/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOKEN_BEGIN = 258,
    COMMA = 259,
    RESERVE_WORDS = 260,
    JNS = 261,
    LOAD = 262,
    STORE = 263,
    ADD = 264,
    SUBT = 265,
    INPUT = 266,
    OUTPUT = 267,
    HALT = 268,
    SKIPCOND = 269,
    JUMP = 270,
    CLEAR = 271,
    ADDI = 272,
    JUMPI = 273,
    LOADI = 274,
    STOREI = 275,
    DEC = 276,
    HEX = 277,
    ORG = 278,
    REGULAR_EXPRESSIONS = 279,
    IDENTIFIER = 280,
    HEXLIT = 281,
    TOKEN_END = 282
  };
#endif
/* Tokens.  */
#define TOKEN_BEGIN 258
#define COMMA 259
#define RESERVE_WORDS 260
#define JNS 261
#define LOAD 262
#define STORE 263
#define ADD 264
#define SUBT 265
#define INPUT 266
#define OUTPUT 267
#define HALT 268
#define SKIPCOND 269
#define JUMP 270
#define CLEAR 271
#define ADDI 272
#define JUMPI 273
#define LOADI 274
#define STOREI 275
#define DEC 276
#define HEX 277
#define ORG 278
#define REGULAR_EXPRESSIONS 279
#define IDENTIFIER 280
#define HEXLIT 281
#define TOKEN_END 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 51 "maspar.y" /* yacc.c:1909  */

  string* token;
  unsigned short integer;

#line 113 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
