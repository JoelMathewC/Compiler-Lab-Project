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
    MAIN = 258,
    ID = 259,
    NUM = 260,
    STRING = 261,
    STR = 262,
    INT = 263,
    PLUS = 264,
    MINUS = 265,
    STAR = 266,
    DIV = 267,
    MOD = 268,
    ASSIGN = 269,
    GT = 270,
    GTE = 271,
    LT = 272,
    LTE = 273,
    EQ = 274,
    NEQ = 275,
    ADDR = 276,
    START = 277,
    END = 278,
    ENDSTMT = 279,
    DECL = 280,
    ENDDECL = 281,
    READ = 282,
    WRITE = 283,
    IF = 284,
    THEN = 285,
    ELSE = 286,
    ENDIF = 287,
    WHILE = 288,
    DO = 289,
    ENDWHILE = 290,
    REPEAT = 291,
    UNTIL = 292,
    BREAK = 293,
    CONTINUE = 294
  };
#endif
/* Tokens.  */
#define MAIN 258
#define ID 259
#define NUM 260
#define STRING 261
#define STR 262
#define INT 263
#define PLUS 264
#define MINUS 265
#define STAR 266
#define DIV 267
#define MOD 268
#define ASSIGN 269
#define GT 270
#define GTE 271
#define LT 272
#define LTE 273
#define EQ 274
#define NEQ 275
#define ADDR 276
#define START 277
#define END 278
#define ENDSTMT 279
#define DECL 280
#define ENDDECL 281
#define READ 282
#define WRITE 283
#define IF 284
#define THEN 285
#define ELSE 286
#define ENDIF 287
#define WHILE 288
#define DO 289
#define ENDWHILE 290
#define REPEAT 291
#define UNTIL 292
#define BREAK 293
#define CONTINUE 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "code.y"

	struct tnode *no;
	struct dnode *dno;
	int number;
	char* string;
	

#line 143 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
