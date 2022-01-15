/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    ID = 258,
    NUM = 259,
    STRING = 260,
    STR = 261,
    INT = 262,
    PLUS = 263,
    MINUS = 264,
    STAR = 265,
    DIV = 266,
    MOD = 267,
    ASSIGN = 268,
    GT = 269,
    GTE = 270,
    LT = 271,
    LTE = 272,
    EQ = 273,
    NEQ = 274,
    ADDR = 275,
    START = 276,
    END = 277,
    ENDSTMT = 278,
    DECL = 279,
    ENDDECL = 280,
    READ = 281,
    WRITE = 282,
    IF = 283,
    THEN = 284,
    ELSE = 285,
    ENDIF = 286,
    WHILE = 287,
    DO = 288,
    ENDWHILE = 289,
    REPEAT = 290,
    UNTIL = 291,
    BREAK = 292,
    CONTINUE = 293
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define STRING 260
#define STR 261
#define INT 262
#define PLUS 263
#define MINUS 264
#define STAR 265
#define DIV 266
#define MOD 267
#define ASSIGN 268
#define GT 269
#define GTE 270
#define LT 271
#define LTE 272
#define EQ 273
#define NEQ 274
#define ADDR 275
#define START 276
#define END 277
#define ENDSTMT 278
#define DECL 279
#define ENDDECL 280
#define READ 281
#define WRITE 282
#define IF 283
#define THEN 284
#define ELSE 285
#define ENDIF 286
#define WHILE 287
#define DO 288
#define ENDWHILE 289
#define REPEAT 290
#define UNTIL 291
#define BREAK 292
#define CONTINUE 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "code.y"

	struct tnode *no;
	struct dnode *dno;
	int number;
	char* string;
	

#line 141 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
