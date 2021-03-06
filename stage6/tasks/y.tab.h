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
    VOID = 264,
    NULL_TYPE = 265,
    TUPLE = 266,
    PLUS = 267,
    MINUS = 268,
    STAR = 269,
    DIV = 270,
    MOD = 271,
    ASSIGN = 272,
    GT = 273,
    GTE = 274,
    LT = 275,
    LTE = 276,
    EQ = 277,
    NEQ = 278,
    ADDR = 279,
    AND = 280,
    OR = 281,
    START = 282,
    END = 283,
    ENDSTMT = 284,
    DECL = 285,
    ENDDECL = 286,
    TYPE = 287,
    ENDTYPE = 288,
    READ = 289,
    WRITE = 290,
    ALLOC = 291,
    INITIALIZE = 292,
    FREE = 293,
    IF = 294,
    THEN = 295,
    ELSE = 296,
    ENDIF = 297,
    WHILE = 298,
    DO = 299,
    ENDWHILE = 300,
    REPEAT = 301,
    UNTIL = 302,
    BREAK = 303,
    CONTINUE = 304,
    RETURN = 305
  };
#endif
/* Tokens.  */
#define MAIN 258
#define ID 259
#define NUM 260
#define STRING 261
#define STR 262
#define INT 263
#define VOID 264
#define NULL_TYPE 265
#define TUPLE 266
#define PLUS 267
#define MINUS 268
#define STAR 269
#define DIV 270
#define MOD 271
#define ASSIGN 272
#define GT 273
#define GTE 274
#define LT 275
#define LTE 276
#define EQ 277
#define NEQ 278
#define ADDR 279
#define AND 280
#define OR 281
#define START 282
#define END 283
#define ENDSTMT 284
#define DECL 285
#define ENDDECL 286
#define TYPE 287
#define ENDTYPE 288
#define READ 289
#define WRITE 290
#define ALLOC 291
#define INITIALIZE 292
#define FREE 293
#define IF 294
#define THEN 295
#define ELSE 296
#define ENDIF 297
#define WHILE 298
#define DO 299
#define ENDWHILE 300
#define REPEAT 301
#define UNTIL 302
#define BREAK 303
#define CONTINUE 304
#define RETURN 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "code.y"

	struct tnode *no;
	struct dnode *dno;
	struct ParamStruct *pt;
	struct ArgStruct *at;
	int number;
	char* string;
	int* seq;
	

#line 168 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
