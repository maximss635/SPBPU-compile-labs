%{
#include <stdio.h>

#define LOG_DEBUG( msg ) printf( "[DEBUG] %s\n", msg );

void yyerror( char* s ) ;
int yylex();

extern FILE* yyin;

int numError = 0;
char curLine[ 128 ] = "";
char prevLine[ 128 ] = "";
char someName[ 128 ] = "";
char someFunctionName[ 128 ] = "";

void onFunctionDeclarationDetected()
{

}

void onFunctionDefinitionDetected()
{
    char log[ 64 ];
    snprintf( log, 64, "Function definition detected: %s", someFunctionName );
    LOG_DEBUG( log );
}

%}

%start c_entries

/* TYPES */
%token TYPE_INT TYPE_FLOAT TYPE_DOUBLE TYPE_CHAR TYPE_PREFIX_LONG
%token TYPE_PREFIX_UNSIGNED TYPE_PREFIX_SIGNED TYPE_VOID TYPE_PREFIX_STATIC TYPE_PREFIX_EXTERN TYPE_PREFIX_CONST

/* Special tokens */
%token IF ELSE WHILE DO FOR RETURN

%token NUMBER SOME_NAME COMMON SEMICOLON

%token BINARY_OPERATOR UNARY_OPERATOR BINARY_OPERATOR_ASSIGN

/* Brackets */
%token EBRACE OBRACE OPEN_CIRCLE_BRACKET CLOSE_CITCLE_BRACKET OPEN_SQUARE_BRACKET CLOSE_SQUARE_BRACKET

%%
c_entries:
	c_entry |
	c_entries c_entry;

c_entry:
	c_function_definition;


/* ======= C-FUNCTIONS =========== */

c_function_declaration:
	ret_value SOME_NAME OPEN_CIRCLE_BRACKET function_params CLOSE_CITCLE_BRACKET SEMICOLON
		// int foo() ;
    { onFunctionDeclarationDetected(); };

c_function_definition:
	ret_value		     					                                    // int
	SOME_NAME OPEN_CIRCLE_BRACKET { strcpy( someFunctionName, someName ); }     // foo (
	function_params CLOSE_CITCLE_BRACKET                                        //      ... )
	OBRACE	 							                                        // {
	function_entries							                                //    ....
	EBRACE								                                        // }
	{ onFunctionDefinitionDetected(); };

c_function_call:
	SOME_NAME OPEN_CIRCLE_BRACKET instances_to_stack CLOSE_CITCLE_BRACKET SEMICOLON		// foo( a, b, 2 ) ;

ret_value:
	some_type;

function_params:
	function_param | function_param COMMON function_params;		// int a, double b, char c

function_param:
	some_type SOME_NAME;		// int t;
					// TODO: struct, union, enum, pointers

instances_to_stack:
	instance_to_stack | instance_to_stack COMMON instances_to_stack;	// a, b, 2 + t

instance_to_stack:
	instance_name;

instance_name:
	SOME_NAME;

/* ======== C-TYPES =========== */

some_type:
	some_type_primitive |					        // int / double / char
	TYPE_PREFIX_STATIC some_type_primitive |		// static int / double / char
	TYPE_PREFIX_EXTERN some_type_primitive |		// extern int / double / char
	TYPE_PREFIX_CONST some_type_primitive ;			// const int / double / char

some_type_primitive:
	TYPE_INT | TYPE_DOUBLE | TYPE_FLOAT | TYPE_CHAR |	// int
	TYPE_VOID |						                    // void
	TYPE_PREFIX_UNSIGNED some_type |			        // unsigned int
	TYPE_PREFIX_SIGNED some_type |				        // signed int
	TYPE_PREFIX_LONG some_type ;				        // long int


/* ========= MAIN C-Code ============ */

function_entries:
	function_entrie |
	function_entrie function_entries;

function_entrie:
	cycle_for |			        // for ( ... ) { ... }
	cycle_while | 			    // while ( ... ) { ... }
	c_conditional | 		    // if ( ... ) { ... } else { ... }
	cycle_do_while |		    // do { ... } while ( ... ) ;
	c_function_call |		    // foo();
	c_instance_declaration | 	// int t;
	return_line |			    // return a + b * c;
	c_expr;

return_line:
	RETURN SOME_NAME SEMICOLON;
	// TODO: return expressions. Now work only "return a;"

/* TODO: "struct T t"; , "enum T t;" + pointers: "int * p;"
** TODO: math expr : "int t = a + b * 2;" */
c_instance_declaration:
	some_type c_instances_declarations_in_common SEMICOLON;             // double ... , ... , ... ;

c_instances_declarations_in_common:
    c_decl_var_equal_number COMMON c_instances_declarations_in_common | c_decl_var_equal_number;
        //  a = 1, b = 2, c = 4;

c_decl_var_equal_number:
    var_name BINARY_OPERATOR_ASSIGN assign_right_expr | var_name;

cycle_do_while:
	DO 											                                        // do
	OBRACE											                                    // {
	body_entries									                                    // 	...
	EBRACE											                                    // }
	WHILE OPEN_CIRCLE_BRACKET expression_in_brackets CLOSE_CITCLE_BRACKET SEMICOLON;	// while ( ... )

cycle_while:
	WHILE OPEN_CIRCLE_BRACKET expression_in_brackets CLOSE_CITCLE_BRACKET			// while ( ... )
	OBRACE											                                // {
	body_entries										                            // 	...
	EBRACE;											                                // }

expression_in_brackets:

cycle_for:
	// TODO

c_conditional:
	// TODO

body_entries:
	// TODO

assign_right_expr:
    NUMBER | var_name | c_expr

c_expr:
    left_operand BINARY_OPERATOR right_operand;

left_operand:
    NUMBER | var_name;

right_operand:
    NUMBER | var_name | c_expr;

var_name:
    SOME_NAME;

%%

void yyerror(char *s)
{
    ++numError;

    fprintf( stderr, "[ERROR] %s\n", s );
    fprintf( stderr, "          Line number: %d\n", yylval );
    fprintf( stderr, "          Current line: \"%s\"\n", curLine );
    fprintf( stderr, "          Previous line: \"%s\"\n", prevLine );
}

int yywrap()
{
    if (0 == numError)
        printf("OK\n");
    return 1;
}

int main(int argc, void *argv[])
{
    yylval = 0;

    if (2 != argc) {
        printf("Incorrect arguments\n");
        printf("Usage: ./compile [path]\n");

        return -1;
    }

    char* pathFile = argv[1];
    yyin = fopen(pathFile,"r");
    if (NULL == yyin) {
        printf("No such file: %s\n", pathFile);
	    return -1;
    }

    yyparse();
    fclose(yyin);

    return 0;
}
