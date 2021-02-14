/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    OPEN = 258,                    /* OPEN  */
    CLOSE = 259,                   /* CLOSE  */
    OBRACE = 260,                  /* OBRACE  */
    EBRACE = 261,                  /* EBRACE  */
    NUMBER = 262,                  /* NUMBER  */
    VAR = 263,                     /* VAR  */
    SEMICOLON = 264,               /* SEMICOLON  */
    IF = 265,                      /* IF  */
    ELSE_IF = 266,                 /* ELSE_IF  */
    ELSE = 267,                    /* ELSE  */
    WHILE = 268,                   /* WHILE  */
    PRINT = 269,                   /* PRINT  */
    RETURN = 270,                  /* RETURN  */
    ADD = 271,                     /* ADD  */
    SUB = 272,                     /* SUB  */
    MUL = 273,                     /* MUL  */
    DIV = 274,                     /* DIV  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    DEC = 277,                     /* DEC  */
    INC = 278,                     /* INC  */
    BIT_AND = 279,                 /* BIT_AND  */
    BIT_OR = 280,                  /* BIT_OR  */
    BIT_XOR = 281,                 /* BIT_XOR  */
    BIT_LEFT_SHIFT = 282,          /* BIT_LEFT_SHIFT  */
    BIT_RIGHT_SHIFT = 283,         /* BIT_RIGHT_SHIFT  */
    MOD = 284,                     /* MOD  */
    ASSIGN = 285,                  /* ASSIGN  */
    IS_EQUAL = 286,                /* IS_EQUAL  */
    IS_NOT_EQUAL = 287,            /* IS_NOT_EQUAL  */
    IS_LESS = 288,                 /* IS_LESS  */
    IS_MORE = 289,                 /* IS_MORE  */
    IS_LEQUAL = 290,               /* IS_LEQUAL  */
    IS_MEQUAL = 291,               /* IS_MEQUAL  */
    AASS = 292,                    /* AASS  */
    SASS = 293,                    /* SASS  */
    MASS = 294,                    /* MASS  */
    DASS = 295                     /* DASS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define OPEN 258
#define CLOSE 259
#define OBRACE 260
#define EBRACE 261
#define NUMBER 262
#define VAR 263
#define SEMICOLON 264
#define IF 265
#define ELSE_IF 266
#define ELSE 267
#define WHILE 268
#define PRINT 269
#define RETURN 270
#define ADD 271
#define SUB 272
#define MUL 273
#define DIV 274
#define AND 275
#define OR 276
#define DEC 277
#define INC 278
#define BIT_AND 279
#define BIT_OR 280
#define BIT_XOR 281
#define BIT_LEFT_SHIFT 282
#define BIT_RIGHT_SHIFT 283
#define MOD 284
#define ASSIGN 285
#define IS_EQUAL 286
#define IS_NOT_EQUAL 287
#define IS_LESS 288
#define IS_MORE 289
#define IS_LEQUAL 290
#define IS_MEQUAL 291
#define AASS 292
#define SASS 293
#define MASS 294
#define DASS 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
