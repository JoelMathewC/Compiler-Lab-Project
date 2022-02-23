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
    PLUS = 266,
    MINUS = 267,
    STAR = 268,
    DIV = 269,
    MOD = 270,
    ASSIGN = 271,
    GT = 272,
    GTE = 273,
    LT = 274,
    LTE = 275,
    EQ = 276,
    NEQ = 277,
    ADDR = 278,
    AND = 279,
    OR = 280,
    START = 281,
    END = 282,
    ENDSTMT = 283,
    DECL = 284,
    ENDDECL = 285,
    TYPE = 286,
    ENDTYPE = 287,
    READ = 288,
    WRITE = 289,
    ALLOC = 290,
    INITIALIZE = 291,
    FREE = 292,
    IF = 293,
    THEN = 294,
    ELSE = 295,
    ENDIF = 296,
    WHILE = 297,
    DO = 298,
    ENDWHILE = 299,
    REPEAT = 300,
    UNTIL = 301,
    BREAK = 302,
    CONTINUE = 303,
    RETURN = 304
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
#define PLUS 266
#define MINUS 267
#define STAR 268
#define DIV 269
#define MOD 270
#define ASSIGN 271
#define GT 272
#define GTE 273
#define LT 274
#define LTE 275
#define EQ 276
#define NEQ 277
#define ADDR 278
#define AND 279
#define OR 280
#define START 281
#define END 282
#define ENDSTMT 283
#define DECL 284
#define ENDDECL 285
#define TYPE 286
#define ENDTYPE 287
#define READ 288
#define WRITE 289
#define ALLOC 290
#define INITIALIZE 291
#define FREE 292
#define IF 293
#define THEN 294
#define ELSE 295
#define ENDIF 296
#define WHILE 297
#define DO 298
#define ENDWHILE 299
#define REPEAT 300
#define UNTIL 301
#define BREAK 302
#define CONTINUE 303
#define RETURN 304

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
	

#line 166 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
