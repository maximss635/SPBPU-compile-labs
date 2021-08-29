/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/grammar.y"

#include "logging.h"
#include "context.h"

void yyerror( char* s ) ;
int yylex();

extern FILE* yyin;
extern char *yytext;

struct Context g_context;   // Singleton
int numError;

void saveFuncName()
{
    strcpy( g_context.someFunctionName, g_context.someName );
    LOG_DEBUG_FMT( "Start parsing function: %s", g_context.someFunctionName );
}


#line 92 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/gen/grammar.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "grammar.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TYPE_INT = 3,                   /* TYPE_INT  */
  YYSYMBOL_TYPE_FLOAT = 4,                 /* TYPE_FLOAT  */
  YYSYMBOL_TYPE_DOUBLE = 5,                /* TYPE_DOUBLE  */
  YYSYMBOL_TYPE_CHAR = 6,                  /* TYPE_CHAR  */
  YYSYMBOL_TYPE_PREFIX_LONG = 7,           /* TYPE_PREFIX_LONG  */
  YYSYMBOL_TYPE_PREFIX_UNSIGNED = 8,       /* TYPE_PREFIX_UNSIGNED  */
  YYSYMBOL_TYPE_PREFIX_SIGNED = 9,         /* TYPE_PREFIX_SIGNED  */
  YYSYMBOL_TYPE_VOID = 10,                 /* TYPE_VOID  */
  YYSYMBOL_TYPE_PREFIX_STATIC = 11,        /* TYPE_PREFIX_STATIC  */
  YYSYMBOL_TYPE_PREFIX_EXTERN = 12,        /* TYPE_PREFIX_EXTERN  */
  YYSYMBOL_TYPE_PREFIX_CONST = 13,         /* TYPE_PREFIX_CONST  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_DO = 17,                        /* DO  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_RETURN = 19,                    /* RETURN  */
  YYSYMBOL_INLINE = 20,                    /* INLINE  */
  YYSYMBOL_NUMBER = 21,                    /* NUMBER  */
  YYSYMBOL_SOME_NAME = 22,                 /* SOME_NAME  */
  YYSYMBOL_BINARY_OPERATOR = 23,           /* BINARY_OPERATOR  */
  YYSYMBOL_UNARY_OPERATOR = 24,            /* UNARY_OPERATOR  */
  YYSYMBOL_25_ = 25,                       /* '('  */
  YYSYMBOL_26_ = 26,                       /* ')'  */
  YYSYMBOL_27_ = 27,                       /* ';'  */
  YYSYMBOL_28_ = 28,                       /* '{'  */
  YYSYMBOL_29_ = 29,                       /* '}'  */
  YYSYMBOL_30_ = 30,                       /* ','  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_32_ = 32,                       /* '['  */
  YYSYMBOL_33_ = 33,                       /* ']'  */
  YYSYMBOL_34_ = 34,                       /* '?'  */
  YYSYMBOL_35_ = 35,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_c_entries = 37,                 /* c_entries  */
  YYSYMBOL_c_entry = 38,                   /* c_entry  */
  YYSYMBOL_c_function_definition = 39,     /* c_function_definition  */
  YYSYMBOL_40_2 = 40,                      /* $@2  */
  YYSYMBOL_c_function_call = 41,           /* c_function_call  */
  YYSYMBOL_ret_value = 42,                 /* ret_value  */
  YYSYMBOL_function_params = 43,           /* function_params  */
  YYSYMBOL_function_param = 44,            /* function_param  */
  YYSYMBOL_instances_to_stack = 45,        /* instances_to_stack  */
  YYSYMBOL_instance_to_stack = 46,         /* instance_to_stack  */
  YYSYMBOL_instance_name = 47,             /* instance_name  */
  YYSYMBOL_some_type = 48,                 /* some_type  */
  YYSYMBOL_some_type_primitive = 49,       /* some_type_primitive  */
  YYSYMBOL_function_entries = 50,          /* function_entries  */
  YYSYMBOL_function_entrie = 51,           /* function_entrie  */
  YYSYMBOL_return_line = 52,               /* return_line  */
  YYSYMBOL_var_or_number = 53,             /* var_or_number  */
  YYSYMBOL_c_local_instance_declaration = 54, /* c_local_instance_declaration  */
  YYSYMBOL_c_instances_declarations_in_common = 55, /* c_instances_declarations_in_common  */
  YYSYMBOL_c_decl_var_equal_number = 56,   /* c_decl_var_equal_number  */
  YYSYMBOL_var_or_array = 57,              /* var_or_array  */
  YYSYMBOL_cycle_do_while = 58,            /* cycle_do_while  */
  YYSYMBOL_cycle_while = 59,               /* cycle_while  */
  YYSYMBOL_cond_in_brackets = 60,          /* cond_in_brackets  */
  YYSYMBOL_cond_in_brackets_for = 61,      /* cond_in_brackets_for  */
  YYSYMBOL_body = 62,                      /* body  */
  YYSYMBOL_cycle_for = 63,                 /* cycle_for  */
  YYSYMBOL_c_conditional = 64,             /* c_conditional  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_67_5 = 67,                      /* $@5  */
  YYSYMBOL_68_6 = 68,                      /* $@6  */
  YYSYMBOL_else_cases = 69,                /* else_cases  */
  YYSYMBOL_70_7 = 70,                      /* $@7  */
  YYSYMBOL_71_8 = 71,                      /* $@8  */
  YYSYMBOL_body_entries = 72,              /* body_entries  */
  YYSYMBOL_assign_right_expr = 73,         /* assign_right_expr  */
  YYSYMBOL_c_expr = 74,                    /* c_expr  */
  YYSYMBOL_tern_operator = 75,             /* tern_operator  */
  YYSYMBOL_operand1 = 76,                  /* operand1  */
  YYSYMBOL_operand2 = 77,                  /* operand2  */
  YYSYMBOL_operand3 = 78,                  /* operand3  */
  YYSYMBOL_left_operand = 79,              /* left_operand  */
  YYSYMBOL_right_operand = 80,             /* right_operand  */
  YYSYMBOL_binary_operator = 81,           /* binary_operator  */
  YYSYMBOL_c_expr_in_brackets = 82,        /* c_expr_in_brackets  */
  YYSYMBOL_array_item = 83,                /* array_item  */
  YYSYMBOL_var_name = 84                   /* var_name  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   279

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   279


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      25,    26,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    27,
       2,    31,     2,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    33,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,    29,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    35,    35,    36,    39,    50,    50,    58,    61,    61,
      64,    64,    64,    67,    71,    71,    71,    74,    74,    74,
      77,    82,    83,    84,    85,    88,    88,    88,    88,    89,
      90,    91,    92,    98,    99,   102,   103,   104,   105,   106,
     107,   108,   108,   112,   113,   116,   116,   120,   123,   123,
     127,   128,   131,   131,   131,   134,   139,   142,   146,   146,
     146,   149,   150,   153,   158,   161,   166,   168,   165,   171,
     173,   170,   178,   177,   181,   180,   184,   187,   190,   190,
     190,   193,   193,   194,   194,   195,   196,   197,   198,   201,
     204,   204,   204,   207,   207,   207,   210,   210,   210,   213,
     213,   213,   216,   216,   216,   219,   219,   222,   225,   225,
     228
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TYPE_INT",
  "TYPE_FLOAT", "TYPE_DOUBLE", "TYPE_CHAR", "TYPE_PREFIX_LONG",
  "TYPE_PREFIX_UNSIGNED", "TYPE_PREFIX_SIGNED", "TYPE_VOID",
  "TYPE_PREFIX_STATIC", "TYPE_PREFIX_EXTERN", "TYPE_PREFIX_CONST", "IF",
  "ELSE", "WHILE", "DO", "FOR", "RETURN", "INLINE", "NUMBER", "SOME_NAME",
  "BINARY_OPERATOR", "UNARY_OPERATOR", "'('", "')'", "';'", "'{'", "'}'",
  "','", "'='", "'['", "']'", "'?'", "':'", "$accept", "c_entries",
  "c_entry", "c_function_definition", "$@2", "c_function_call",
  "ret_value", "function_params", "function_param", "instances_to_stack",
  "instance_to_stack", "instance_name", "some_type", "some_type_primitive",
  "function_entries", "function_entrie", "return_line", "var_or_number",
  "c_local_instance_declaration", "c_instances_declarations_in_common",
  "c_decl_var_equal_number", "var_or_array", "cycle_do_while",
  "cycle_while", "cond_in_brackets", "cond_in_brackets_for", "body",
  "cycle_for", "c_conditional", "$@3", "$@4", "$@5", "$@6", "else_cases",
  "$@7", "$@8", "body_entries", "assign_right_expr", "c_expr",
  "tern_operator", "operand1", "operand2", "operand3", "left_operand",
  "right_operand", "binary_operator", "c_expr_in_brackets", "array_item",
  "var_name", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    40,    41,    59,   123,   125,
      44,    61,    91,    93,    63,    58
};
#endif

#define YYPACT_NINF (-118)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-102)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      98,  -118,  -118,  -118,  -118,   174,   174,   174,  -118,   222,
     222,   222,   174,    16,    98,  -118,    -1,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,    14,  -118,
     174,    15,    30,    49,    56,   174,  -118,   145,  -118,    68,
      71,    86,    74,   218,  -118,    91,   218,   218,  -118,   112,
     110,   145,   115,    11,   133,  -118,  -118,  -118,  -118,   164,
    -118,   134,   -11,  -118,   140,   163,   223,   223,   145,   181,
      70,   165,   166,   228,   177,   191,    63,  -118,  -118,   192,
     189,   202,  -118,  -118,  -118,  -118,  -118,  -118,  -118,   218,
    -118,  -118,   218,    -3,   195,    87,  -118,   197,   170,   209,
    -118,   208,   216,   219,   225,   178,    89,   230,   229,  -118,
      13,  -118,   112,   233,    33,    28,   141,   226,   111,    19,
      13,  -118,    -9,   227,   231,   234,   119,  -118,   223,   218,
     119,   218,  -118,   228,  -118,    42,  -118,    13,   206,   232,
     235,   218,  -118,  -118,    86,   145,  -118,  -118,   237,   179,
    -118,  -118,   183,  -118,  -118,  -118,    11,   184,  -118,   140,
    -118,  -118,   239,   218,   218,   252,   252,  -118,   185,   190,
     241,  -118,  -118,    86,   145,  -118,  -118
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    25,    27,    26,    28,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     3,     4,     0,     8,    21,    32,
      30,    31,    22,    23,    24,     9,     1,     2,     0,     5,
      12,     0,    11,     0,     0,    12,    13,    42,    10,     0,
       0,     0,     0,     0,    46,   110,     0,     0,    87,     0,
       0,    34,     0,   100,     0,    38,    36,    35,    37,   101,
      88,     0,     0,    86,    99,    45,     0,     0,    42,     0,
       0,   100,   101,    16,    81,    82,   101,   110,    47,    49,
      51,    54,     6,    33,    40,    83,    39,    84,    41,     0,
     105,   106,     0,     0,    46,   110,    59,     0,   101,     0,
      77,     0,     0,     0,     0,   101,    46,     0,    15,    17,
      19,   107,     0,     0,     0,   100,   101,     0,    99,   103,
     104,    85,   102,     0,     0,    69,    42,    63,     0,     0,
      42,     0,     7,    16,    48,    46,    50,    80,    45,     0,
       0,     0,   109,   108,     0,    42,    57,    56,     0,   101,
      65,    64,   101,    14,    52,    53,    97,    98,    89,    96,
      67,    70,     0,     0,     0,    76,    76,    55,   101,   101,
      74,    68,    71,     0,    42,    73,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,   256,  -118,  -118,  -118,  -118,  -118,   236,  -118,   139,
    -118,   -65,    26,   162,   -34,  -117,  -118,   -41,   203,   167,
    -118,  -118,  -118,  -118,   -61,  -118,  -115,  -118,  -118,  -118,
    -118,  -118,  -118,   108,  -118,  -118,  -118,  -118,   -43,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,   -82,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    13,    14,    15,    30,    48,    16,    31,    32,   107,
     108,    96,    49,    18,    50,    51,    52,    53,    54,    78,
      79,    80,    55,    56,    97,   104,    69,    57,    58,   144,
     165,   145,   166,   171,   173,   174,   101,   136,    59,    60,
      61,   117,   158,    62,   121,    92,    63,    64,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      72,    81,    71,    75,    76,    74,    99,   118,   109,   146,
     122,   147,    90,   150,   -99,   151,    26,    83,   123,   124,
      91,    28,   -99,    98,    98,   -90,    17,   105,   161,   160,
     110,    19,    20,    21,   100,    85,  -101,    87,    25,    29,
      17,    34,  -100,    85,  -101,   -91,   116,   -92,   115,   120,
    -100,   119,    85,   -91,   139,    77,    33,   176,   175,   159,
      35,    33,   -91,   -94,    81,   138,   140,   148,   109,   -78,
     137,    36,   -78,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    37,    98,   149,    87,   152,   111,
     110,    44,    45,    66,    46,    47,    67,   -92,   157,    70,
     156,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    73,   -20,    68,   -18,    73,   -20,    12,   -18,
     168,   169,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    39,    77,    40,    41,    42,    43,    82,
      44,    45,    84,    46,    47,   -90,   -93,    68,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    39,
      86,    40,    41,    42,    43,    87,    44,    45,    89,    46,
      47,    22,    23,    24,   -90,   -92,   -95,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    87,    85,
      87,    88,   -43,   -44,    87,    93,   -60,   102,   -92,   -91,
     -92,    85,    87,    87,   -92,   131,   163,    87,    87,    87,
     164,   -62,   -92,   -92,    87,    87,   -61,   -92,   -92,   -92,
     113,   -58,   112,   125,   -92,     1,     2,     3,     4,     5,
       6,     7,     8,   -79,   114,   126,   -79,   127,    93,    44,
      45,   128,    46,    47,    94,    95,   129,    46,    47,   106,
      95,   130,    46,    47,   135,    45,   132,    46,    47,   133,
     142,   141,   -66,   162,   143,   154,   167,   170,   155,   -72,
      27,    38,   153,   103,   172,     0,     0,     0,     0,   134
};

static const yytype_int16 yycheck[] =
{
      43,    49,    43,    46,    47,    46,    67,    89,    73,   126,
      92,   126,    23,   130,    23,   130,     0,    51,    21,    22,
      31,    22,    31,    66,    67,    34,     0,    70,   145,   144,
      73,     5,     6,     7,    68,    24,    23,    24,    12,    25,
      14,    26,    23,    24,    31,    34,    89,    34,    89,    92,
      31,    92,    24,    34,    21,    22,    30,   174,   173,   141,
      30,    35,    34,    35,   112,   113,   114,   128,   133,    27,
     113,    22,    30,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    28,   128,   129,    24,   131,    26,
     133,    21,    22,    25,    24,    25,    25,    34,   141,    25,
     141,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    25,    26,    28,    26,    25,    30,    20,    30,
     163,   164,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    22,    16,    17,    18,    19,    29,
      21,    22,    27,    24,    25,    34,    35,    28,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      27,    16,    17,    18,    19,    24,    21,    22,    34,    24,
      25,     9,    10,    11,    34,    34,    35,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    24,    24,
      24,    27,    27,    27,    24,    32,    26,    16,    34,    34,
      34,    24,    24,    24,    34,    27,    27,    24,    24,    24,
      27,    26,    34,    34,    24,    24,    26,    34,    34,    34,
      31,    26,    30,    26,    34,     3,     4,     5,     6,     7,
       8,     9,    10,    27,    32,    26,    30,    29,    32,    21,
      22,    25,    24,    25,    21,    22,    27,    24,    25,    21,
      22,    26,    24,    25,    21,    22,    26,    24,    25,    30,
      33,    35,    28,    26,    33,    33,    27,    15,    33,    28,
      14,    35,   133,    70,   166,    -1,    -1,    -1,    -1,   112
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    20,    37,    38,    39,    42,    48,    49,    48,
      48,    48,    49,    49,    49,    48,     0,    37,    22,    25,
      40,    43,    44,    48,    26,    30,    22,    28,    43,    14,
      16,    17,    18,    19,    21,    22,    24,    25,    41,    48,
      50,    51,    52,    53,    54,    58,    59,    63,    64,    74,
      75,    76,    79,    82,    83,    84,    25,    25,    28,    62,
      25,    53,    74,    25,    53,    74,    74,    22,    55,    56,
      57,    84,    29,    50,    27,    24,    27,    24,    27,    34,
      23,    31,    81,    32,    21,    22,    47,    60,    74,    60,
      50,    72,    16,    54,    61,    74,    21,    45,    46,    47,
      74,    26,    30,    31,    32,    53,    74,    77,    83,    53,
      74,    80,    83,    21,    22,    26,    26,    29,    25,    27,
      26,    27,    26,    30,    55,    21,    73,    74,    84,    21,
      84,    35,    33,    33,    65,    67,    51,    62,    60,    74,
      51,    62,    74,    45,    33,    33,    53,    74,    78,    83,
      62,    51,    26,    27,    27,    66,    68,    27,    74,    74,
      15,    69,    69,    70,    71,    62,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    38,    40,    39,    41,    42,    42,
      43,    43,    43,    44,    45,    45,    45,    46,    46,    46,
      47,    48,    48,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    51,    52,    52,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    59,    59,    60,    60,
      60,    61,    61,    62,    63,    63,    65,    66,    64,    67,
      68,    64,    70,    69,    71,    69,    69,    72,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      76,    76,    76,    77,    77,    77,    78,    78,    78,    79,
      79,    79,    80,    80,    80,    81,    81,    82,    83,    83,
      84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     0,     9,     4,     1,     2,
       3,     1,     0,     2,     3,     1,     0,     1,     1,     1,
       1,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     2,
       2,     2,     0,     2,     2,     1,     1,     2,     3,     1,
       3,     1,     4,     4,     1,     7,     5,     5,     1,     1,
       1,     5,     5,     3,     5,     5,     0,     0,     8,     0,
       0,     8,     0,     3,     0,     3,     0,     1,     1,     1,
       1,     2,     2,     2,     2,     3,     1,     1,     1,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     4,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* $@2: %empty  */
#line 50 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/grammar.y"
                                { saveFuncName(); }
#line 1324 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/gen/grammar.tab.c"
    break;

  case 6: /* c_function_definition: ret_value SOME_NAME '(' $@2 function_params ')' '{' function_entries '}'  */
#line 55 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/grammar.y"
        { onBlockDetected( FunctionDefinition ); }
#line 1330 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/gen/grammar.tab.c"
    break;

  case 50: /* c_decl_var_equal_number: var_or_array '=' assign_right_expr  */
#line 127 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/grammar.y"
                                       { onBlockDetected( LocalInstanceDeclaration ); }
#line 1336 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/gen/grammar.tab.c"
    break;

  case 51: /* c_decl_var_equal_number: var_or_array  */
#line 128 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/grammar.y"
                   { onBlockDetected( LocalInstanceDeclaration ); }
#line 1342 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/gen/grammar.tab.c"
    break;

  case 66: /* $@3: %empty  */
#line 166 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/grammar.y"
    { onBlockDetected( IfCond ); }
#line 1348 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/gen/grammar.tab.c"
    break;

  case 67: /* $@4: %empty  */
#line 168 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/grammar.y"
        { onBlockDetected( IfBody ); }
#line 1354 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/gen/grammar.tab.c"
    break;

  case 69: /* $@5: %empty  */
#line 171 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/grammar.y"
    { onBlockDetected( IfCond ); }
#line 1360 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/gen/grammar.tab.c"
    break;

  case 70: /* $@6: %empty  */
#line 173 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/grammar.y"
    { onBlockDetected( IfBody ); }
#line 1366 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/gen/grammar.tab.c"
    break;

  case 72: /* $@7: %empty  */
#line 178 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/grammar.y"
        { onBlockDetected( ElseCond ); }
#line 1372 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/gen/grammar.tab.c"
    break;

  case 74: /* $@8: %empty  */
#line 181 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/grammar.y"
    { onBlockDetected( ElseCond ); }
#line 1378 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/gen/grammar.tab.c"
    break;

  case 75: /* else_cases: ELSE $@8 function_entrie  */
#line 183 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/grammar.y"
    { onBlockDetected( ElseBody ); }
#line 1384 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/gen/grammar.tab.c"
    break;


#line 1388 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/gen/grammar.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 230 "/home/maxim/IBKS/3 year/6 semester/ФГиТК/Course/Work/Compile/grammar.y"


void yyerror( char* s )
{
    ++numError;

    fprintf( stderr, "[ERROR] %s\n", s );
    fprintf( stderr, "          Line number: %d\n", yylval + 1 );
    fprintf( stderr, "          Current line: \"%s\"\n", g_context.curLine );
    fprintf( stderr, "          Previous line: \"%s\"\n", g_context.prevLine );
}

int yywrap()
{
    if ( 0 == numError )
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
