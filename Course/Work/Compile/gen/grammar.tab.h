/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_MAXIM_IBKS_3_YEAR_6_SEMESTER_COURSE_WORK_COMPILE_GEN_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_HOME_MAXIM_IBKS_3_YEAR_6_SEMESTER_COURSE_WORK_COMPILE_GEN_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TYPE_INT = 258,                /* TYPE_INT  */
    TYPE_FLOAT = 259,              /* TYPE_FLOAT  */
    TYPE_DOUBLE = 260,             /* TYPE_DOUBLE  */
    TYPE_CHAR = 261,               /* TYPE_CHAR  */
    TYPE_PREFIX_LONG = 262,        /* TYPE_PREFIX_LONG  */
    TYPE_PREFIX_UNSIGNED = 263,    /* TYPE_PREFIX_UNSIGNED  */
    TYPE_PREFIX_SIGNED = 264,      /* TYPE_PREFIX_SIGNED  */
    TYPE_VOID = 265,               /* TYPE_VOID  */
    TYPE_PREFIX_STATIC = 266,      /* TYPE_PREFIX_STATIC  */
    TYPE_PREFIX_EXTERN = 267,      /* TYPE_PREFIX_EXTERN  */
    TYPE_PREFIX_CONST = 268,       /* TYPE_PREFIX_CONST  */
    IF = 269,                      /* IF  */
    ELSE = 270,                    /* ELSE  */
    WHILE = 271,                   /* WHILE  */
    DO = 272,                      /* DO  */
    FOR = 273,                     /* FOR  */
    RETURN = 274,                  /* RETURN  */
    INLINE = 275,                  /* INLINE  */
    NUMBER = 276,                  /* NUMBER  */
    SOME_NAME = 277,               /* SOME_NAME  */
    BINARY_OPERATOR = 278,         /* BINARY_OPERATOR  */
    UNARY_OPERATOR = 279           /* UNARY_OPERATOR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_MAXIM_IBKS_3_YEAR_6_SEMESTER_COURSE_WORK_COMPILE_GEN_GRAMMAR_TAB_H_INCLUDED  */
