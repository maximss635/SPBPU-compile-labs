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
    NUMBER = 258,                  /* NUMBER  */
    VAR = 259,                     /* VAR  */
    ASSIGN = 260,                  /* ASSIGN  */
    SEMICOLON = 261,               /* SEMICOLON  */
    IF = 262,                      /* IF  */
    OPEN = 263,                    /* OPEN  */
    CLOSE = 264,                   /* CLOSE  */
    OBRACE = 265,                  /* OBRACE  */
    EBRACE = 266,                  /* EBRACE  */
    COMPARE = 267,                 /* COMPARE  */
    ELSE_IF = 268,                 /* ELSE_IF  */
    ELSE = 269,                    /* ELSE  */
    PRINT = 270,                   /* PRINT  */
    ADD = 271,                     /* ADD  */
    SUB = 272,                     /* SUB  */
    MUL = 273,                     /* MUL  */
    DIV = 274,                     /* DIV  */
    WHILE = 275,                   /* WHILE  */
    RETURN = 276,                  /* RETURN  */
    CHANGE = 277,                  /* CHANGE  */
    DEC = 278,                     /* DEC  */
    INC = 279,                     /* INC  */
    AND = 280,                     /* AND  */
    OR = 281,                      /* OR  */
    BIT_AND = 282,                 /* BIT_AND  */
    BIT_OR = 283,                  /* BIT_OR  */
    BIT_XOR = 284,                 /* BIT_XOR  */
    BIT_LEFT_SHIFT = 285,          /* BIT_LEFT_SHIFT  */
    BIT_RIGHT_SHIFT = 286,         /* BIT_RIGHT_SHIFT  */
    MOD = 287                      /* MOD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUMBER 258
#define VAR 259
#define ASSIGN 260
#define SEMICOLON 261
#define IF 262
#define OPEN 263
#define CLOSE 264
#define OBRACE 265
#define EBRACE 266
#define COMPARE 267
#define ELSE_IF 268
#define ELSE 269
#define PRINT 270
#define ADD 271
#define SUB 272
#define MUL 273
#define DIV 274
#define WHILE 275
#define RETURN 276
#define CHANGE 277
#define DEC 278
#define INC 279
#define AND 280
#define OR 281
#define BIT_AND 282
#define BIT_OR 283
#define BIT_XOR 284
#define BIT_LEFT_SHIFT 285
#define BIT_RIGHT_SHIFT 286
#define MOD 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
