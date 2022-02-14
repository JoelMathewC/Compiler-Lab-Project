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
    AND = 277,
    OR = 278,
    START = 279,
    END = 280,
    ENDSTMT = 281,
    DECL = 282,
    ENDDECL = 283,
    READ = 284,
    WRITE = 285,
    IF = 286,
    THEN = 287,
    ELSE = 288,
    ENDIF = 289,
    WHILE = 290,
    DO = 291,
    ENDWHILE = 292,
    REPEAT = 293,
    UNTIL = 294,
    BREAK = 295,
    CONTINUE = 296,
    RETURN = 297
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
#define AND 277
#define OR 278
#define START 279
#define END 280
#define ENDSTMT 281
#define DECL 282
#define ENDDECL 283
#define READ 284
#define WRITE 285
#define IF 286
#define THEN 287
#define ELSE 288
#define ENDIF 289
#define WHILE 290
#define DO 291
#define ENDWHILE 292
#define REPEAT 293
#define UNTIL 294
#define BREAK 295
#define CONTINUE 296
#define RETURN 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "parser_temp.y"

	struct tnode *no;
	struct dnode *dno;
	struct ParamStruct *pt;
	struct ArgStruct *at;
	int number;
	char* string;

#line 150 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
