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
    MUL = 265,
    DIV = 266,
    ASSIGN = 267,
    GT = 268,
    GTE = 269,
    LT = 270,
    LTE = 271,
    EQ = 272,
    NEQ = 273,
    START = 274,
    END = 275,
    ENDSTMT = 276,
    DECL = 277,
    ENDDECL = 278,
    READ = 279,
    WRITE = 280,
    IF = 281,
    THEN = 282,
    ELSE = 283,
    ENDIF = 284,
    WHILE = 285,
    DO = 286,
    ENDWHILE = 287,
    REPEAT = 288,
    UNTIL = 289,
    BREAK = 290,
    CONTINUE = 291
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
#define MUL 265
#define DIV 266
#define ASSIGN 267
#define GT 268
#define GTE 269
#define LT 270
#define LTE 271
#define EQ 272
#define NEQ 273
#define START 274
#define END 275
#define ENDSTMT 276
#define DECL 277
#define ENDDECL 278
#define READ 279
#define WRITE 280
#define IF 281
#define THEN 282
#define ELSE 283
#define ENDIF 284
#define WHILE 285
#define DO 286
#define ENDWHILE 287
#define REPEAT 288
#define UNTIL 289
#define BREAK 290
#define CONTINUE 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "code.y"

	struct tnode *no;
	struct dnode *dno;
	int number;
	char* string;
	

#line 137 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
