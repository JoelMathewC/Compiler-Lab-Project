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
    SELF = 262,
    STR = 263,
    INT = 264,
    VOID = 265,
    NULL_TYPE = 266,
    TUPLE = 267,
    PLUS = 268,
    MINUS = 269,
    STAR = 270,
    DIV = 271,
    MOD = 272,
    ASSIGN = 273,
    GT = 274,
    GTE = 275,
    LT = 276,
    LTE = 277,
    EQ = 278,
    NEQ = 279,
    ADDR = 280,
    AND = 281,
    OR = 282,
    START = 283,
    END = 284,
    ENDSTMT = 285,
    DECL = 286,
    ENDDECL = 287,
    TYPE = 288,
    ENDTYPE = 289,
    CLASS = 290,
    ENDCLASS = 291,
    EXTENDS = 292,
    READ = 293,
    WRITE = 294,
    ALLOC = 295,
    INITIALIZE = 296,
    FREE = 297,
    NEW = 298,
    DELETE = 299,
    IF = 300,
    THEN = 301,
    ELSE = 302,
    ENDIF = 303,
    WHILE = 304,
    DO = 305,
    ENDWHILE = 306,
    REPEAT = 307,
    UNTIL = 308,
    BREAK = 309,
    CONTINUE = 310,
    RETURN = 311
  };
#endif
/* Tokens.  */
#define MAIN 258
#define ID 259
#define NUM 260
#define STRING 261
#define SELF 262
#define STR 263
#define INT 264
#define VOID 265
#define NULL_TYPE 266
#define TUPLE 267
#define PLUS 268
#define MINUS 269
#define STAR 270
#define DIV 271
#define MOD 272
#define ASSIGN 273
#define GT 274
#define GTE 275
#define LT 276
#define LTE 277
#define EQ 278
#define NEQ 279
#define ADDR 280
#define AND 281
#define OR 282
#define START 283
#define END 284
#define ENDSTMT 285
#define DECL 286
#define ENDDECL 287
#define TYPE 288
#define ENDTYPE 289
#define CLASS 290
#define ENDCLASS 291
#define EXTENDS 292
#define READ 293
#define WRITE 294
#define ALLOC 295
#define INITIALIZE 296
#define FREE 297
#define NEW 298
#define DELETE 299
#define IF 300
#define THEN 301
#define ELSE 302
#define ENDIF 303
#define WHILE 304
#define DO 305
#define ENDWHILE 306
#define REPEAT 307
#define UNTIL 308
#define BREAK 309
#define CONTINUE 310
#define RETURN 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 58 "code.y"

	struct tnode *no;
	struct dnode *dno;
	struct ParamStruct *pt;
	struct ArgStruct *at;
	int number;
	char* string;
	int* seq;
	

#line 180 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
