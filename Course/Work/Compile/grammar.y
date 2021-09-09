%{
#include "logging.h"
#include "context.h"

void yyerror( char* s ) ;
int yylex();

extern FILE* yyin;
extern char *yytext;
extern _Bool g_logging;

struct Context g_context;   // Singleton
int numError;

void saveFuncName()
{
    strcpy( g_context.someFunctionName, g_context.someName );
    //LOG_DEBUG_FMT( "Start parsing function: %s", g_context.someFunctionName );
}

%}

%start c_entries

/* TYPES */
%token TYPE_INT TYPE_FLOAT TYPE_DOUBLE TYPE_CHAR TYPE_SIZE_T TYPE_PREFIX_LONG ARR
%token TYPE_PREFIX_UNSIGNED TYPE_PREFIX_SIGNED TYPE_VOID TYPE_PREFIX_STATIC TYPE_PREFIX_EXTERN TYPE_PREFIX_CONST
%token TYPE_LONG_INT TYPE_LONG_DOUBLE TYPE_SHORT_INT TYPE_LONG TYPE_SHORT

/* Special tokens */
%token IF ELSE WHILE DO FOR RETURN INLINE
%token NUMBER SOME_NAME
%token BINARY_OPERATOR UNARY_OPERATOR

%token BREAK CONTINUE SIZEOF STRING_CONSTANT

%token STRUCT

%%
c_entries:
	c_entry c_entries |
	c_entry ;

c_entry:
	c_function_definition |
	c_function_declaration;

/* ======= C-FUNCTIONS =========== */

c_function_declaration:
	c_function_signature ';'                            // int foo() ;
    { onBlockDetected( FunctionDeclaration ); };

c_function_definition:
    c_function_signature                                                        // int foo()
	'{'	 							                                            // {
	    function_entries							                            //    ....
	'}'								                                            // }
	{ onBlockDetected( FunctionDefinition ); };

c_function_signature:
    ret_value SOME_NAME '('
    { saveFuncName(); }
    function_params ')';

c_function_call:
    SOME_NAME '(' instances_to_stack ')';		// foo( a, b, 2 )

ret_value:
    __ret_value | INLINE __ret_value;

__ret_value:
	c_type '*' | c_type;

function_params:
    TYPE_VOID | __function_params;

__function_params:
	function_param ',' function_params | function_param | /* nothing */;		// int a, double b, char c

function_param:
	c_type SOME_NAME |		        // int t;
	c_type '*' SOME_NAME ;          // int * t
					// TODO: struct, union, enum, pointers

instances_to_stack:
	instance_to_stack ',' instances_to_stack | instance_to_stack | /* nothing */ ;	// a, b, 2 + t

instance_to_stack:
	__instance_to_stack | c_expr;

__instance_to_stack:
    var_or_array | NUMBER | field | STRING_CONSTANT;

instance_name:
	SOME_NAME;

/* ======== C-TYPES =========== */

c_type:
    __c_type |
    __type_prefixes __c_type;

__type_prefixes:
    __type_prefixes __type_prefix | __type_prefix;

__type_prefix:
    __type_prefix_static_extern |
    __type_prefix_signed_unsigned |
    __type_prefix_const;

__c_type:
    TYPE_LONG_INT |
    TYPE_LONG_DOUBLE |
    TYPE_LONG |
    TYPE_SHORT |
    TYPE_SHORT_INT |
   	TYPE_INT |
	TYPE_DOUBLE |
	TYPE_FLOAT |
	TYPE_CHAR |
	TYPE_SIZE_T |
	TYPE_VOID |
	__custom_type;

__custom_type:
    STRUCT SOME_NAME |
    SOME_NAME;

__type_prefix_static_extern:
    TYPE_PREFIX_STATIC | TYPE_PREFIX_EXTERN;

__type_prefix_signed_unsigned:
    TYPE_PREFIX_SIGNED | TYPE_PREFIX_UNSIGNED;

__type_prefix_const:
    TYPE_PREFIX_CONST;

/* ========= MAIN C-Code ============ */

function_entries:
	function_entry function_entries |
	function_entry ;

function_entry:
	cycle_for |			                                // for ( ... ) { ... }
	cycle_while | 			                            // while ( ... ) { ... }
	c_conditional | 		                            // if ( ... ) { ... } else { ... }
	cycle_do_while |		                            // do { ... } while ( ... ) ;
	c_local_instance_declaration ';' | 	                // int t;
	return_line ';' |			                        // return a + b * c;
	BREAK ';' | CONTINUE ';' |
	c_lang_operator ';' |
	c_expr ';' |                                        // ...
    /* empty */ ;

c_lang_operator:
    operator_sizeof;

operator_sizeof:
    SIZEOF '(' c_type ')' |
    SIZEOF '(' SOME_NAME ')' ;

return_line:
	RETURN var_or_number |
	RETURN c_expr |
	RETURN;

var_or_number:
    var_name | NUMBER ;

/* TODO: "struct T t"; , "enum T t;" + pointers: "int * p;" */
c_local_instance_declaration:
    c_type __c_instances_declarations_in_common ;             // double ... , ... , ...

__c_instances_declarations_in_common:
    __c_decl_var_equal_number ',' __c_instances_declarations_in_common | __c_decl_var_equal_number;
        //  a = 1, b = 2, c = 4;

__c_decl_var_equal_number:
    '*' ___c_decl_var_equal_number |            // pointers declare
    ___c_decl_var_equal_number;

___c_decl_var_equal_number:
    var_or_array '=' assign_right_expr { onBlockDetected( LocalInstanceDeclaration ); } |
    var_or_array { onBlockDetected( LocalInstanceDeclaration ); };

var_or_array:
    array_item |
    var_name;

cycle_do_while:
	DO 											                                        // do
	body                                                                                //     ...
	WHILE '(' cond_in_brackets ')' ';' ;	                                            // while ( ... ) ;

cycle_while:
	WHILE '(' cond_in_brackets ')'			                                        // while ( ... )
	body                                                                            //     { ... }
    |
	WHILE '(' cond_in_brackets ')'			                                        // while ( ... )
	function_entry;                                                                //     ...

cond_in_brackets:
    NUMBER |
    instance_name |
    field |
    array_item |
    c_expr;

cond_in_brackets_for:
    cond_in_brackets_for_enrty ';'
    cond_in_brackets_for_enrty ';'
    cond_in_brackets_for_enrty |              // ( ... ; ... ; ... )
    c_local_instance_declaration ';'
    cond_in_brackets_for_enrty ';'
    cond_in_brackets_for_enrty ;      // ( double ... ; ... ; ... )

cond_in_brackets_for_enrty:
    c_expr | /* noth */ ;

body:
	'{'											                                    // {
	body_entries									                                // 	...
	'}'											                                    // }

cycle_for:
	FOR '(' cond_in_brackets_for ')'			                                    // for ( ... ; ... ; ... )
	body                                                                            //     { ... }
	|
	FOR '(' cond_in_brackets_for ')'			                                    // for ( ... ; ... ; ... )
	function_entry;                                                                //     ...

c_conditional:
	IF '(' cond_in_brackets ')'                                             // if ( ... )
    { onBlockDetected( IfCond ); }
	body                                                                    //     {...}
	{ onBlockDetected( IfBody ); }
    else_cases |
	IF '(' cond_in_brackets ')'                                             // if ( ... )
    { onBlockDetected( IfCond ); }
    function_entry										                    // 	    ...
    { onBlockDetected( IfBody ); }
    else_cases;

else_cases:
    ELSE                                                                    // else
	{ onBlockDetected( ElseCond ); }
	body                                                                    //     {...}
	| ELSE                                                                  // else
    { onBlockDetected( ElseCond ); }                                        //  ...
    function_entry
    { onBlockDetected( ElseBody ); }
    | /* nothing */ ;

body_entries:
    function_entries;

assign_right_expr:
    c_expr |
    var_or_number |
    array_item |
    field |
    c_lang_operator;

c_expr:
    __left_operand binary_operator __right_operand |
    unary_operator __operand1 |
    __operand1 UNARY_OPERATOR |
    tern_operator |
    __c_expr;

__c_expr:
    __c_expr_in_brackets |
        c_function_call ;

tern_operator:
    __operand1 '?' __operand2 ':' __operand3 ;

__operand1:
    array_item | var_or_number | field | c_expr| c_lang_operator;

__operand2:
    array_item | var_or_number | field | c_expr| c_lang_operator;

__operand3:
    array_item | var_or_number | field | c_expr| c_lang_operator;

__left_operand:
    array_item | var_or_number | field | __c_expr;

__right_operand:
    array_item | var_or_number | field | c_expr | c_lang_operator;

field:
    SOME_NAME __field;

__field:
    '.' SOME_NAME __field | '.' SOME_NAME |
    ARR SOME_NAME __field | ARR SOME_NAME ;

unary_operator:
    UNARY_OPERATOR | '*' | '&' | cast;

binary_operator:
    BINARY_OPERATOR | '=' | '*' | '&';

cast:
    '(' c_type ')' ;

__c_expr_in_brackets:
    '(' c_expr ')';

array_item:
    var_name '[' array_index ']' |
    field '[' array_index ']' ;

array_index:
    NUMBER | var_or_array | field;

var_name:
    SOME_NAME;

%%

void yyerror( char* s )
{
    ++numError;

    fprintf( stdout, "[ERROR] %s\n", s );
    fprintf( stdout, "          Line number: %d\n", yylval + 1 );
    fprintf( stdout, "          Current line: \"%s\"\n", g_context.curLine );
    fprintf( stdout, "          Previous line: \"%s\"\n", g_context.prevLine );
}

int yywrap()
{
    if ( 0 == numError )
        printf("OK\n");
    return 1;
}

int main( int argc, void *argv[] )
{
    yylval = 0;

    if ( argc < 2 ) {
        printf( "Incorrect arguments\n" );
        printf( "Usage: ./compile [path]\n");

        return -1;
    }

    for ( int i = 0; i < argc; ++i )
    {
        if ( !strcmp( "--nologging", argv[ i ] ) )
        {
            g_logging = 0;
            break;
        }
    }

    char* pathFile = argv[ 1 ];
    yyin = fopen( pathFile, "r" );
    if ( NULL == yyin ) {
        printf( "No such file: %s\n", pathFile );
	    return -1;
    }

    yyparse();
    fclose( yyin );

    return 0;
}
