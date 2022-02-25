/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "code.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	
	void yyerror(char const *s);
	int yylex(void);
	extern FILE* yyin;
	
	#include "data_structures/defn.h"
	#include "data_structures/labelAddrTable.h"
	#include "data_structures/loopStack.h"
	#include "data_structures/typeTable.h"
	#include "data_structures/classTable.h"
	#include "data_structures/symbolTable.h"
	#include "data_structures/tNode.h"
	#include "data_structures/dNode.h"
	#include "data_structures/paramStruct.h"
	#include "backend/globalVar.h"
	
	#include "functions/dNodeFunc.h"
	#include "functions/tNodeFunc.h"
	#include "functions/paramStructFunc.h"
	#include "functions/labelAddrTableFunc.h"
	#include "functions/loopStackFunc.h"
	#include "functions/typeTableFunc.h"
	#include "functions/classTableFunc.h"
	#include "functions/symbolTableFunc.h"
	
	#include "functions/dNodeFunc.c"
	#include "functions/tNodeFunc.c"
	#include "functions/paramStructFunc.c"
	#include "functions/labelAddrTableFunc.c"
	#include "functions/loopStackFunc.c"
	#include "functions/typeTableFunc.c"
	#include "functions/classTableFunc.c"
	#include "functions/symbolTableFunc.c"
	#include "backend/globalVar.c"
	
	#include "backend/code_gen.h"
	#include "backend/code_gen.c"
	
	struct GSymbolTable* gst;
	struct LSymbolTable* lst;
	struct TypeTable* typeTable;
	struct ClassTable* classTable;
	FILE* startCodeGen(int memLoc, struct GSymbolTable* gst);
	void endCodeGen(FILE *fp);
	void setMemLocationValues(struct GSymbolTable* gst,FILE* fp);
	FILE *fp;

#line 122 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    CLASS = 289,
    ENDCLASS = 290,
    READ = 291,
    WRITE = 292,
    ALLOC = 293,
    INITIALIZE = 294,
    FREE = 295,
    IF = 296,
    THEN = 297,
    ELSE = 298,
    ENDIF = 299,
    WHILE = 300,
    DO = 301,
    ENDWHILE = 302,
    REPEAT = 303,
    UNTIL = 304,
    BREAK = 305,
    CONTINUE = 306,
    RETURN = 307
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
#define CLASS 289
#define ENDCLASS 290
#define READ 291
#define WRITE 292
#define ALLOC 293
#define INITIALIZE 294
#define FREE 295
#define IF 296
#define THEN 297
#define ELSE 298
#define ENDIF 299
#define WHILE 300
#define DO 301
#define ENDWHILE 302
#define REPEAT 303
#define UNTIL 304
#define BREAK 305
#define CONTINUE 306
#define RETURN 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "code.y"

	struct tnode *no;
	struct dnode *dno;
	struct ParamStruct *pt;
	struct ArgStruct *at;
	int number;
	char* string;
	int* seq;
	

#line 289 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   739

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  310

#define YYUNDEFTOK  2
#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      56,    57,     2,     2,    55,     2,    60,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    90,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   102,   103,   106,   107,   110,   114,   117,   118,
     119,   122,   123,   126,   129,   130,   133,   134,   137,   140,
     143,   144,   147,   153,   154,   157,   158,   161,   164,   165,
     168,   171,   172,   176,   182,   185,   186,   189,   190,   191,
     192,   193,   196,   199,   202,   203,   206,   207,   210,   211,
     214,   215,   218,   219,   222,   229,   237,   238,   239,   242,
     243,   246,   252,   255,   260,   261,   262,   265,   266,   269,
     272,   273,   277,   278,   284,   285,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   300,   301,   304,   305,
     306,   309,   312,   315,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   345,
     346,   349,   350,   351,   352,   355,   356,   359,   360
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "ID", "NUM", "STRING", "STR",
  "INT", "VOID", "NULL_TYPE", "TUPLE", "PLUS", "MINUS", "STAR", "DIV",
  "MOD", "ASSIGN", "GT", "GTE", "LT", "LTE", "EQ", "NEQ", "ADDR", "AND",
  "OR", "START", "END", "ENDSTMT", "DECL", "ENDDECL", "TYPE", "ENDTYPE",
  "CLASS", "ENDCLASS", "READ", "WRITE", "ALLOC", "INITIALIZE", "FREE",
  "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT",
  "UNTIL", "BREAK", "CONTINUE", "RETURN", "'{'", "'}'", "','", "'('",
  "')'", "'['", "']'", "'.'", "$accept", "program", "GclassBlock",
  "GclassList", "Gclass", "GclassDeclBlock", "GclassAttrDeclList",
  "GclassAttrDecl", "GclassIdList", "GclassFuncDeclList", "GclassFuncDecl",
  "GclassFuncName", "GclassFuncDefBlock", "GclassFuncDef", "GtypeBlock",
  "GtypeList", "Gtype", "GtypeDeclList", "GtypeDecl", "GtypeIdList",
  "GdeclBlock", "GdeclList", "Type", "TupleType", "Gdecl", "GidList",
  "Gid", "IdentifierDecl", "IdArrDecl", "FdefBlock", "Fdef", "FName",
  "ParamList", "Param", "MainBlock", "MainHeader", "LdeclBlock",
  "LdeclList", "Ldecl", "LidList", "Lid", "Slist", "Stmt", "IfStmt",
  "LoopStmt", "InputStmt", "OutputStmt", "AssgStmt", "expr", "ArgList",
  "Identifier", "StructId", "IdArr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   123,   125,    44,    40,    41,    91,    93,
      46
};
# endif

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      58,    14,   119,    23,     7,    20,    -6,   109,   173,  -132,
     -24,   -18,  -132,  -132,  -132,  -132,    54,  -132,   207,   117,
    -132,  -132,    29,  -132,    24,  -132,    34,  -132,     8,  -132,
    -132,    32,   173,   173,  -132,    14,    87,   173,  -132,    43,
    -132,    77,    59,    68,  -132,  -132,    90,   118,   -15,  -132,
    -132,   100,   191,  -132,  -132,   136,  -132,  -132,   173,   173,
    -132,   173,  -132,   116,  -132,  -132,    77,   269,   151,  -132,
     191,   191,  -132,  -132,  -132,   117,   174,    41,  -132,   181,
     191,    60,   173,  -132,  -132,  -132,   191,   159,  -132,   137,
     365,  -132,   284,   145,    21,  -132,    78,  -132,   130,  -132,
    -132,  -132,   -11,   622,  -132,   628,  -132,   188,  -132,    93,
    -132,   140,  -132,    85,   430,  -132,   190,    -4,  -132,  -132,
    -132,   149,     9,   147,   150,   153,   164,   185,   430,   430,
     213,   217,   251,   309,  -132,  -132,  -132,  -132,  -132,  -132,
     231,   187,   113,  -132,   245,   191,  -132,  -132,  -132,  -132,
     246,  -132,  -132,   636,  -132,  -132,   247,   202,    50,   234,
    -132,  -132,    77,  -132,   334,  -132,  -132,   137,   105,  -132,
     251,  -132,  -132,   156,   251,   251,   251,   447,   352,  -132,
    -132,   203,  -132,  -132,  -132,   255,   156,   210,   211,   215,
     251,   650,  -132,   220,  -132,   251,   275,   251,   277,  -132,
    -132,  -132,  -132,   202,   191,  -132,   278,  -132,   256,   238,
    -132,   264,   686,   155,   503,   227,   518,   536,   551,   229,
     240,   230,  -132,  -132,   248,   254,   156,   566,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,  -132,  -132,   668,  -132,   488,  -132,   162,  -132,   430,
    -132,  -132,   251,   268,  -132,   285,   286,   274,   271,   251,
     251,  -132,   182,  -132,  -132,   261,  -132,   139,   139,  -132,
    -132,  -132,   716,   716,   716,   716,   716,   716,   701,   701,
    -132,  -132,  -132,   377,   686,  -132,  -132,  -132,   430,   430,
     584,   599,  -132,  -132,   265,   258,   395,    74,   293,  -132,
     430,   295,   297,  -132,  -132,   412,  -132,  -132,   298,  -132
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,    50,    48,    47,    49,     0,    44,     0,     0,
      51,    46,     0,    34,     0,    36,     0,    13,     0,    15,
       1,     0,     0,     0,     8,    47,     0,     0,    63,     0,
      10,    76,     0,     0,    43,    45,    61,     0,     0,    55,
      56,    59,     0,    33,    35,     0,    12,    14,     0,     0,
       5,     0,     7,     0,    62,     9,    76,     0,     0,    73,
      68,    68,    61,    58,    53,     0,     0,     0,    39,     0,
       0,     0,     0,     3,     4,     6,    68,     0,    75,     0,
       0,    78,     0,     0,     0,    67,     0,    54,     0,    37,
      38,    42,     0,     0,    22,     0,    27,     0,    17,     0,
      31,     0,     2,     0,     0,    82,     0,     0,    81,    74,
      77,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    89,    90,    86,    87,    88,
       0,   134,   131,    69,     0,     0,    52,    57,    60,    40,
       0,    20,    21,     0,    19,    26,     0,    25,     0,     0,
      16,    30,    76,    65,     0,    83,    79,     0,     0,   138,
       0,   133,    72,     0,     0,     0,     0,     0,     0,    91,
      92,   138,   118,   120,   121,     0,     0,     0,     0,     0,
       0,     0,   124,     0,    84,     0,     0,     0,     0,    70,
      66,    41,    18,     0,    68,    23,     0,    28,     0,     0,
      80,     0,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    71,     0,   135,     0,   136,     0,    24,     0,
      64,    93,     0,     0,   132,     0,     0,     0,     0,     0,
       0,   122,     0,   126,   127,     0,   117,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     103,   137,    29,     0,   129,    94,   101,   102,     0,     0,
       0,     0,   123,   128,     0,     0,     0,     0,     0,    32,
       0,     0,     0,    99,   100,     0,    97,    98,     0,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,  -132,   300,  -132,  -132,   228,  -132,   236,
     -99,  -132,  -132,   224,   335,  -132,   316,  -132,   266,  -132,
       1,  -132,     3,  -132,   324,  -132,   272,   302,  -132,    80,
      16,   -50,   -67,   199,     2,  -132,   -63,  -132,   262,  -132,
     184,  -113,  -131,  -132,  -132,  -132,  -132,  -132,    -7,   132,
     -92,  -132,  -132
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    28,    29,    81,   103,   104,   158,   105,
     106,   159,   109,   110,     7,    24,    25,    77,    78,   102,
       8,    18,    36,    20,    21,    48,    49,    50,    51,    37,
      38,    39,    94,    95,     9,    10,    68,    90,    91,   117,
     118,   133,   134,   135,   136,   137,   138,   139,   212,   213,
     192,   141,   142
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     140,   164,   194,    87,    96,    19,   155,    32,    33,    34,
      40,    26,    26,   169,    74,   177,   178,    11,   149,   113,
      30,    19,   140,   122,     2,   166,     3,    22,    22,    41,
     171,   111,    58,   194,    60,    62,   140,   140,    42,    65,
      75,   140,    27,    56,   150,    12,   194,   194,    13,    14,
      15,   167,    16,    64,   155,    79,    23,    53,    43,   111,
      83,    84,     2,    85,    12,   170,     1,    13,    14,    15,
      89,    16,   140,    93,    93,    64,   145,    64,   146,   205,
      79,   215,    52,   107,   112,   140,   140,    55,     2,    93,
       3,    63,     4,    89,   223,    99,    66,    12,    64,   208,
      13,    14,    15,   303,    16,   206,   107,    67,   156,   181,
     182,   183,    59,    61,   108,   184,    69,     1,   185,   122,
     289,    46,    72,    12,    70,   191,    13,    14,    15,   186,
      16,    47,    47,   145,   265,   147,   283,   247,    82,     2,
     145,   115,   163,   187,   188,   189,    71,   160,    93,   143,
      17,   116,   194,   230,   231,   232,   156,   140,    76,   144,
     169,   190,   211,   214,   194,   194,    80,   216,   217,   218,
     122,   197,    86,   198,   194,   295,   296,    12,    92,    98,
      13,    35,    15,   227,    16,   101,   114,   305,   243,   148,
     245,   140,   157,   162,   165,    12,   140,   140,    13,    14,
      15,   172,    16,   140,   140,   168,   173,    93,   140,   174,
     252,    12,   253,   140,    13,    14,    15,   145,    16,   282,
     175,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   181,   182,   183,   252,    44,   292,
     184,   176,   179,   185,   122,   284,   180,   196,   195,   199,
     201,   203,   290,   291,   186,   181,   182,   183,   204,   221,
     222,   184,   121,   207,   185,   122,   224,   225,   187,   188,
     189,   226,   122,    12,   242,   186,    13,    14,    15,   244,
      16,   246,   248,   249,   255,   259,   190,   261,   121,   187,
     188,   189,   250,   251,   124,   125,   260,   285,   122,   126,
      88,   300,   301,   127,   128,   263,   129,   190,   130,   131,
     132,   264,   123,   121,   286,   287,   288,   289,   293,   299,
     124,   125,   304,   122,   306,   126,   307,   309,    57,   127,
     128,   152,   129,   161,   130,   131,   132,   193,   121,   153,
      54,    31,    45,   100,   200,   124,   125,    97,   122,    73,
     126,   210,   120,   262,   127,   128,   121,   129,     0,   130,
     131,   132,   209,     0,     0,     0,   122,     0,     0,    12,
     124,   125,    13,    14,    15,   126,    16,     0,     0,   127,
     128,   121,   129,     0,   130,   131,   132,     0,   124,   125,
       0,   122,     0,   126,     0,     0,   119,   127,   128,   121,
     129,   220,   130,   131,   132,   294,     0,     0,     0,   122,
       0,     0,     0,   124,   125,     0,   121,     0,   126,     0,
       0,     0,   127,   128,     0,   129,   122,   130,   131,   132,
       0,   124,   125,     0,   121,     0,   126,     0,     0,     0,
     127,   128,   302,   129,   122,   130,   131,   132,   124,   125,
       0,   121,     0,   126,     0,     0,   308,   127,   128,     0,
     129,   122,   130,   131,   132,     0,   124,   125,     0,     0,
       0,   126,     0,     0,     0,   127,   128,     0,   129,     0,
     130,   131,   132,   124,   125,     0,     0,     0,   126,     0,
       0,     0,   219,   128,     0,   129,     0,   130,   131,   132,
     228,   229,   230,   231,   232,     0,   233,   234,   235,   236,
     237,   238,     0,   239,   240,   228,   229,   230,   231,   232,
       0,   233,   234,   235,   236,   237,   238,     0,   239,   240,
     228,   229,   230,   231,   232,     0,   233,   234,   235,   236,
     237,   238,     0,   239,   240,     0,     0,   281,   228,   229,
     230,   231,   232,     0,   233,   234,   235,   236,   237,   238,
     254,   239,   240,   228,   229,   230,   231,   232,     0,   233,
     234,   235,   236,   237,   238,   256,   239,   240,   228,   229,
     230,   231,   232,     0,   233,   234,   235,   236,   237,   238,
       0,   239,   240,   257,     0,     0,   228,   229,   230,   231,
     232,     0,   233,   234,   235,   236,   237,   238,   258,   239,
     240,   228,   229,   230,   231,   232,     0,   233,   234,   235,
     236,   237,   238,   266,   239,   240,    12,     0,     0,    13,
      14,    15,    12,    16,     0,    13,    14,    15,     0,    16,
      12,   297,     0,    13,    14,    15,     0,    16,     0,     0,
       0,     0,     0,   151,     0,     0,   298,     0,     0,   154,
       0,     0,   228,   229,   230,   231,   232,   202,   233,   234,
     235,   236,   237,   238,     0,   239,   240,     0,     0,   241,
     228,   229,   230,   231,   232,     0,   233,   234,   235,   236,
     237,   238,     0,   239,   240,     0,     0,   280,   228,   229,
     230,   231,   232,     0,   233,   234,   235,   236,   237,   238,
       0,   239,   240,   228,   229,   230,   231,   232,     0,   233,
     234,   235,   236,   237,   238,     0,    -1,    -1,   228,   229,
     230,   231,   232,     0,    -1,    -1,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      92,   114,   133,    66,    71,     2,   105,     6,     7,     7,
       8,     4,     4,     4,    29,   128,   129,     3,    29,    86,
       0,    18,   114,    14,    30,    29,    32,     4,     4,    53,
     122,    81,    31,   164,    32,    33,   128,   129,    56,    37,
      55,   133,    35,    35,    55,     4,   177,   178,     7,     8,
       9,    55,    11,    37,   153,    52,    33,    33,     4,   109,
      58,    59,    30,    61,     4,    56,     8,     7,     8,     9,
      67,    11,   164,    70,    71,    59,    55,    61,    57,    29,
      77,   173,    53,    80,    82,   177,   178,    53,    30,    86,
      32,     4,    34,    90,   186,    54,    53,     4,    82,   162,
       7,     8,     9,    29,    11,    55,   103,    30,   105,     4,
       5,     6,    32,    33,    54,    10,    57,     8,    13,    14,
      46,     4,     4,     4,    56,   132,     7,     8,     9,    24,
      11,    14,    14,    55,   226,    57,   249,   204,    58,    30,
      55,     4,    57,    38,    39,    40,    56,    54,   145,     4,
      31,    14,   283,    14,    15,    16,   153,   249,    58,    14,
       4,    56,    57,   170,   295,   296,    30,   174,   175,   176,
      14,    58,    56,    60,   305,   288,   289,     4,    27,     5,
       7,     8,     9,   190,    11,     4,    27,   300,   195,    59,
     197,   283,     4,    53,     4,     4,   288,   289,     7,     8,
       9,    54,    11,   295,   296,    56,    56,   204,   300,    56,
      55,     4,    57,   305,     7,     8,     9,    55,    11,    57,
      56,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     4,     5,     6,    55,    31,    57,
      10,    56,    29,    13,    14,   252,    29,    60,    17,     4,
       4,     4,   259,   260,    24,     4,     5,     6,    56,    56,
       5,    10,     4,    29,    13,    14,    56,    56,    38,    39,
      40,    56,    14,     4,    54,    24,     7,     8,     9,     4,
      11,     4,     4,    27,    57,    56,    56,    57,     4,    38,
      39,    40,    54,    29,    36,    37,    56,    29,    14,    41,
      31,    43,    44,    45,    46,    57,    48,    56,    50,    51,
      52,    57,    28,     4,    29,    29,    42,    46,    57,    54,
      36,    37,    29,    14,    29,    41,    29,    29,    28,    45,
      46,   103,    48,   109,    50,    51,    52,    28,     4,   103,
      24,     6,    18,    77,   145,    36,    37,    75,    14,    47,
      41,   167,    90,   221,    45,    46,     4,    48,    -1,    50,
      51,    52,    28,    -1,    -1,    -1,    14,    -1,    -1,     4,
      36,    37,     7,     8,     9,    41,    11,    -1,    -1,    45,
      46,     4,    48,    -1,    50,    51,    52,    -1,    36,    37,
      -1,    14,    -1,    41,    -1,    -1,    31,    45,    46,     4,
      48,    49,    50,    51,    52,    28,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    36,    37,    -1,     4,    -1,    41,    -1,
      -1,    -1,    45,    46,    -1,    48,    14,    50,    51,    52,
      -1,    36,    37,    -1,     4,    -1,    41,    -1,    -1,    -1,
      45,    46,    47,    48,    14,    50,    51,    52,    36,    37,
      -1,     4,    -1,    41,    -1,    -1,    44,    45,    46,    -1,
      48,    14,    50,    51,    52,    -1,    36,    37,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    45,    46,    -1,    48,    -1,
      50,    51,    52,    36,    37,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    45,    46,    -1,    48,    -1,    50,    51,    52,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    -1,    -1,    59,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      57,    25,    26,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    57,    25,    26,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    57,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    23,    57,    25,
      26,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    57,    25,    26,     4,    -1,    -1,     7,
       8,     9,     4,    11,    -1,     7,     8,     9,    -1,    11,
       4,    57,    -1,     7,     8,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    57,    -1,    -1,    31,
      -1,    -1,    12,    13,    14,    15,    16,    31,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    -1,    29,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    -1,    -1,    29,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    30,    32,    34,    62,    63,    75,    81,    95,
      96,     3,     4,     7,     8,     9,    11,    31,    82,    83,
      84,    85,     4,    33,    76,    77,     4,    35,    64,    65,
       0,    75,    81,    81,    95,     8,    83,    90,    91,    92,
      95,    53,    56,     4,    31,    85,     4,    14,    86,    87,
      88,    89,    53,    33,    77,    53,    35,    65,    81,    90,
      95,    90,    95,     4,    91,    95,    53,    30,    97,    57,
      56,    56,     4,    88,    29,    55,    58,    78,    79,    83,
      30,    66,    90,    95,    95,    95,    56,    97,    31,    83,
      98,    99,    27,    83,    93,    94,    93,    87,     5,    54,
      79,     4,    80,    67,    68,    70,    71,    83,    54,    73,
      74,    92,    95,    93,    27,     4,    14,   100,   101,    31,
      99,     4,    14,    28,    36,    37,    41,    45,    46,    48,
      50,    51,    52,   102,   103,   104,   105,   106,   107,   108,
     111,   112,   113,     4,    14,    55,    57,    57,    59,    29,
      55,    31,    68,    70,    31,    71,    83,     4,    69,    72,
      54,    74,    53,    57,   102,     4,    29,    55,    56,     4,
      56,   111,    54,    56,    56,    56,    56,   102,   102,    29,
      29,     4,     5,     6,    10,    13,    24,    38,    39,    40,
      56,   109,   111,    28,   103,    17,    60,    58,    60,     4,
      94,     4,    31,     4,    56,    29,    55,    29,    97,    28,
     101,    57,   109,   110,   109,   111,   109,   109,   109,    45,
      49,    56,     5,   111,    56,    56,    56,   109,    12,    13,
      14,    15,    16,    18,    19,    20,    21,    22,    23,    25,
      26,    29,    54,   109,     4,   109,     4,    93,     4,    27,
      54,    29,    55,    57,    57,    57,    57,    57,    57,    56,
      56,    57,   110,    57,    57,   111,    57,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
      29,    59,    57,   102,   109,    29,    29,    29,    42,    46,
     109,   109,    57,    57,    28,   102,   102,    57,    57,    54,
      43,    44,    47,    29,    29,   102,    29,    29,    44,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      66,    67,    67,    68,    69,    69,    70,    70,    71,    72,
      73,    73,    74,    75,    75,    76,    76,    77,    78,    78,
      79,    80,    80,    81,    81,    82,    82,    83,    83,    83,
      83,    83,    84,    85,    86,    86,    87,    87,    88,    88,
      89,    89,    90,    90,    91,    92,    93,    93,    93,    94,
      94,    95,    95,    96,    97,    97,    97,    98,    98,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   104,   104,   105,   105,
     105,   106,   107,   108,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   110,
     110,   111,   111,   111,   111,   112,   112,   113,   113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     4,     3,     4,     3,     2,     3,
       2,     1,     3,     2,     2,     1,     5,     4,     4,     3,
       3,     2,     1,     3,     3,     1,     2,     1,     3,     4,
       2,     1,     7,     3,     2,     2,     1,     4,     2,     1,
       3,     3,     1,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     5,     3,     3,     1,     1,     4,     2,     1,
       4,     1,     2,     1,     7,     5,     3,     1,     0,     2,
       3,     7,     6,     4,     3,     2,     0,     2,     1,     3,
       3,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     4,     5,     3,    10,     8,     8,     7,
       7,     5,     5,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     2,
       1,     1,     3,     4,     1,     2,     3,     3,     4,     3,
       1,     1,     4,     2,     1,     3,     3,     4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 90 "code.y"
                                                                {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1763 "y.tab.c"
    break;

  case 3:
#line 91 "code.y"
                                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1769 "y.tab.c"
    break;

  case 4:
#line 92 "code.y"
                                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1775 "y.tab.c"
    break;

  case 5:
#line 93 "code.y"
                                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1781 "y.tab.c"
    break;

  case 6:
#line 94 "code.y"
                                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1787 "y.tab.c"
    break;

  case 7:
#line 95 "code.y"
                                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1793 "y.tab.c"
    break;

  case 8:
#line 96 "code.y"
                                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1799 "y.tab.c"
    break;

  case 9:
#line 97 "code.y"
                                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1805 "y.tab.c"
    break;

  case 10:
#line 98 "code.y"
                                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1811 "y.tab.c"
    break;

  case 11:
#line 99 "code.y"
                                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1817 "y.tab.c"
    break;

  case 12:
#line 102 "code.y"
                                                        {printClassTable(classTable);}
#line 1823 "y.tab.c"
    break;

  case 13:
#line 103 "code.y"
                                                                {}
#line 1829 "y.tab.c"
    break;

  case 14:
#line 106 "code.y"
                                                        {}
#line 1835 "y.tab.c"
    break;

  case 15:
#line 107 "code.y"
                                                                {}
#line 1841 "y.tab.c"
    break;

  case 16:
#line 110 "code.y"
                                                                        {
											addToClassTable(classTable, typeTable, (yyvsp[-2].dno), (yyvsp[-4].string));
											
										}
#line 1850 "y.tab.c"
    break;

  case 17:
#line 114 "code.y"
                                                                                {addToClassTable(classTable, typeTable, (yyvsp[-1].dno), (yyvsp[-3].string));}
#line 1856 "y.tab.c"
    break;

  case 18:
#line 117 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[-1].dno));}
#line 1862 "y.tab.c"
    break;

  case 19:
#line 118 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode(NULL,(yyvsp[-1].dno));}
#line 1868 "y.tab.c"
    break;

  case 20:
#line 119 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),NULL);}
#line 1874 "y.tab.c"
    break;

  case 21:
#line 122 "code.y"
                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1880 "y.tab.c"
    break;

  case 22:
#line 123 "code.y"
                                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1886 "y.tab.c"
    break;

  case 23:
#line 126 "code.y"
                                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 1892 "y.tab.c"
    break;

  case 24:
#line 129 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),declIdNode((yyvsp[-2].string),0,NULL));}
#line 1898 "y.tab.c"
    break;

  case 25:
#line 130 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 1904 "y.tab.c"
    break;

  case 26:
#line 133 "code.y"
                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1910 "y.tab.c"
    break;

  case 27:
#line 134 "code.y"
                                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1916 "y.tab.c"
    break;

  case 28:
#line 137 "code.y"
                                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 1922 "y.tab.c"
    break;

  case 29:
#line 140 "code.y"
                                                                {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 1928 "y.tab.c"
    break;

  case 30:
#line 143 "code.y"
                                                                {}
#line 1934 "y.tab.c"
    break;

  case 31:
#line 144 "code.y"
                                                                {}
#line 1940 "y.tab.c"
    break;

  case 32:
#line 147 "code.y"
                                                                        {	
										//TODO: CODE GEN and adding self to lst
										lst = NULL;
									}
#line 1949 "y.tab.c"
    break;

  case 33:
#line 153 "code.y"
                                                        {}
#line 1955 "y.tab.c"
    break;

  case 34:
#line 154 "code.y"
                                                        {}
#line 1961 "y.tab.c"
    break;

  case 35:
#line 157 "code.y"
                                                        {}
#line 1967 "y.tab.c"
    break;

  case 36:
#line 158 "code.y"
                                                {}
#line 1973 "y.tab.c"
    break;

  case 37:
#line 161 "code.y"
                                                        {addUserDefToTypeTable(typeTable,(yyvsp[-1].dno),(yyvsp[-3].string));}
#line 1979 "y.tab.c"
    break;

  case 38:
#line 164 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1985 "y.tab.c"
    break;

  case 39:
#line 165 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1991 "y.tab.c"
    break;

  case 40:
#line 168 "code.y"
                                                        {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 1997 "y.tab.c"
    break;

  case 41:
#line 171 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),declIdNode((yyvsp[-2].string),0,NULL));}
#line 2003 "y.tab.c"
    break;

  case 42:
#line 172 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2009 "y.tab.c"
    break;

  case 43:
#line 176 "code.y"
                                        {	
						gst = (struct GSymbolTable*)malloc(sizeof(struct GSymbolTable));
						generateGlobalSymbolTable(gst,(yyvsp[-1].dno),NULL,NULL,typeTable,classTable);
						fp = startCodeGen(memLoc,gst);
						//printGlobalSymbolTable(gst);
					}
#line 2020 "y.tab.c"
    break;

  case 44:
#line 182 "code.y"
                                        {gst = NULL;}
#line 2026 "y.tab.c"
    break;

  case 45:
#line 185 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2032 "y.tab.c"
    break;

  case 46:
#line 186 "code.y"
                                {(yyval.dno) = (yyvsp[0].dno);}
#line 2038 "y.tab.c"
    break;

  case 47:
#line 189 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2044 "y.tab.c"
    break;

  case 48:
#line 190 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2050 "y.tab.c"
    break;

  case 49:
#line 191 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2056 "y.tab.c"
    break;

  case 50:
#line 192 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2062 "y.tab.c"
    break;

  case 51:
#line 193 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2068 "y.tab.c"
    break;

  case 52:
#line 196 "code.y"
                                        {addTupleToTypeTable(typeTable,(yyvsp[-1].pt),(yyvsp[-3].string));(yyval.string) = (yyvsp[-3].string);}
#line 2074 "y.tab.c"
    break;

  case 53:
#line 199 "code.y"
                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2080 "y.tab.c"
    break;

  case 54:
#line 202 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 2086 "y.tab.c"
    break;

  case 55:
#line 203 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2092 "y.tab.c"
    break;

  case 56:
#line 206 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2098 "y.tab.c"
    break;

  case 57:
#line 207 "code.y"
                                                        {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 2104 "y.tab.c"
    break;

  case 58:
#line 210 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].dno) -> varname,(yyvsp[0].dno) -> dim + 1,(yyvsp[0].dno) -> shape);}
#line 2110 "y.tab.c"
    break;

  case 59:
#line 211 "code.y"
                                                {(yyval.dno) = (yyvsp[0].dno);}
#line 2116 "y.tab.c"
    break;

  case 60:
#line 214 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[-3].dno) -> varname,(yyvsp[-3].dno) -> dim + 1,addArrayShape((yyvsp[-3].dno) -> shape,(yyvsp[-1].number)));}
#line 2122 "y.tab.c"
    break;

  case 61:
#line 215 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2128 "y.tab.c"
    break;

  case 62:
#line 218 "code.y"
                                                        {}
#line 2134 "y.tab.c"
    break;

  case 63:
#line 219 "code.y"
                                                        {}
#line 2140 "y.tab.c"
    break;

  case 64:
#line 222 "code.y"
                                                        {	
									struct Gsymbol* g = GlobalLookup(gst,(yyvsp[-6].string));
									funcCodeGen((yyvsp[-2].no), fp,g -> flabel);
									lst = NULL;
								}
#line 2150 "y.tab.c"
    break;

  case 65:
#line 229 "code.y"
                                                        {
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyFuncHead(gst,(yyvsp[-3].string),TLookup(typeTable,(yyvsp[-4].string)),CLookup(classTable,(yyvsp[-4].string)),(yyvsp[-1].pt));
								addParamToLST(lst,(yyvsp[-1].pt));
								(yyval.string) = (yyvsp[-3].string);
							}
#line 2161 "y.tab.c"
    break;

  case 66:
#line 237 "code.y"
                                                {(yyval.pt) = addParameter((yyvsp[-2].pt),(yyvsp[0].pt));}
#line 2167 "y.tab.c"
    break;

  case 67:
#line 238 "code.y"
                                                {(yyval.pt) = (yyvsp[0].pt);}
#line 2173 "y.tab.c"
    break;

  case 68:
#line 239 "code.y"
                                                        {(yyval.pt) = NULL;}
#line 2179 "y.tab.c"
    break;

  case 69:
#line 242 "code.y"
                                                {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-1].string),0,typeTable,classTable);}
#line 2185 "y.tab.c"
    break;

  case 70:
#line 243 "code.y"
                                                        {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-2].string),1,typeTable,classTable);}
#line 2191 "y.tab.c"
    break;

  case 71:
#line 246 "code.y"
                                                                {	
									if(gst == NULL){
										fp = startCodeGen(-1,gst);	
										fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
									}
									funcCodeGen((yyvsp[-2].no), fp,-1);}
#line 2202 "y.tab.c"
    break;

  case 72:
#line 252 "code.y"
                                                                {exit(0);}
#line 2208 "y.tab.c"
    break;

  case 73:
#line 255 "code.y"
                                {lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));}
#line 2214 "y.tab.c"
    break;

  case 74:
#line 260 "code.y"
                                        {localMemLoc = 0; addLocalVarToLST(lst,(yyvsp[-1].dno),NULL,NULL,typeTable,classTable);}
#line 2220 "y.tab.c"
    break;

  case 75:
#line 261 "code.y"
                                        {(yyval.dno) = NULL;}
#line 2226 "y.tab.c"
    break;

  case 76:
#line 262 "code.y"
                                        {(yyval.dno) = NULL;}
#line 2232 "y.tab.c"
    break;

  case 77:
#line 265 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2238 "y.tab.c"
    break;

  case 78:
#line 266 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2244 "y.tab.c"
    break;

  case 79:
#line 269 "code.y"
                                        {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2250 "y.tab.c"
    break;

  case 80:
#line 272 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 2256 "y.tab.c"
    break;

  case 81:
#line 273 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2262 "y.tab.c"
    break;

  case 82:
#line 277 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2268 "y.tab.c"
    break;

  case 83:
#line 278 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),1,NULL);}
#line 2274 "y.tab.c"
    break;

  case 84:
#line 284 "code.y"
                                                                        {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 2280 "y.tab.c"
    break;

  case 85:
#line 285 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2286 "y.tab.c"
    break;

  case 86:
#line 288 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2292 "y.tab.c"
    break;

  case 87:
#line 289 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2298 "y.tab.c"
    break;

  case 88:
#line 290 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2304 "y.tab.c"
    break;

  case 89:
#line 291 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2310 "y.tab.c"
    break;

  case 90:
#line 292 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2316 "y.tab.c"
    break;

  case 91:
#line 293 "code.y"
                                                                {(yyval.no) = makeJumpNode(break_node);}
#line 2322 "y.tab.c"
    break;

  case 92:
#line 294 "code.y"
                                                                        {(yyval.no) = makeJumpNode(continue_node);}
#line 2328 "y.tab.c"
    break;

  case 93:
#line 295 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,NULL);}
#line 2334 "y.tab.c"
    break;

  case 94:
#line 296 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-4].string),gst,(yyvsp[-2].at));}
#line 2340 "y.tab.c"
    break;

  case 95:
#line 297 "code.y"
                                                                        {(yyval.no) = makeReturnNode((yyvsp[-1].no));}
#line 2346 "y.tab.c"
    break;

  case 96:
#line 300 "code.y"
                                                                {(yyval.no) = makeIfElseBlock((yyvsp[-7].no),(yyvsp[-4].no),(yyvsp[-2].no));}
#line 2352 "y.tab.c"
    break;

  case 97:
#line 301 "code.y"
                                                                        {(yyval.no) = makeIfElseBlock((yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 2358 "y.tab.c"
    break;

  case 98:
#line 304 "code.y"
                                                                {(yyval.no) = makeWhileBlock((yyvsp[-5].no),(yyvsp[-2].no));}
#line 2364 "y.tab.c"
    break;

  case 99:
#line 305 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 2370 "y.tab.c"
    break;

  case 100:
#line 306 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 2376 "y.tab.c"
    break;

  case 101:
#line 309 "code.y"
                                                                        {(yyval.no) = makeReadNode((yyvsp[-2].no));}
#line 2382 "y.tab.c"
    break;

  case 102:
#line 312 "code.y"
                                                                {(yyval.no) = makeWriteNode((yyvsp[-2].no));}
#line 2388 "y.tab.c"
    break;

  case 103:
#line 315 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(assign,(yyvsp[-3].no),(yyvsp[-1].no),typeTable);}
#line 2394 "y.tab.c"
    break;

  case 104:
#line 318 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(add,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2400 "y.tab.c"
    break;

  case 105:
#line 319 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(sub,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2406 "y.tab.c"
    break;

  case 106:
#line 320 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(mul,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2412 "y.tab.c"
    break;

  case 107:
#line 321 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(div,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2418 "y.tab.c"
    break;

  case 108:
#line 322 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(mod,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2424 "y.tab.c"
    break;

  case 109:
#line 323 "code.y"
                                                                {(yyval.no) = makeOperatorNode(gt,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2430 "y.tab.c"
    break;

  case 110:
#line 324 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(gte,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2436 "y.tab.c"
    break;

  case 111:
#line 325 "code.y"
                                                                {(yyval.no) = makeOperatorNode(lt,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2442 "y.tab.c"
    break;

  case 112:
#line 326 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(lte,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2448 "y.tab.c"
    break;

  case 113:
#line 327 "code.y"
                                                                {(yyval.no) = makeOperatorNode(eq,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2454 "y.tab.c"
    break;

  case 114:
#line 328 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(neq,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2460 "y.tab.c"
    break;

  case 115:
#line 329 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(and,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2466 "y.tab.c"
    break;

  case 116:
#line 330 "code.y"
                                                                {(yyval.no) = makeOperatorNode(or,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2472 "y.tab.c"
    break;

  case 117:
#line 331 "code.y"
                                                                {(yyval.no) = (yyvsp[-1].no);}
#line 2478 "y.tab.c"
    break;

  case 118:
#line 332 "code.y"
                                                                        {(yyval.no) = makeNumNode((yyvsp[0].number),0,typeTable);}
#line 2484 "y.tab.c"
    break;

  case 119:
#line 333 "code.y"
                                                                        {(yyval.no) = makeNumNode(-1 * (yyvsp[0].number),0,typeTable);}
#line 2490 "y.tab.c"
    break;

  case 120:
#line 334 "code.y"
                                                                        {(yyval.no) = makeStringNode((yyvsp[0].string),typeTable);}
#line 2496 "y.tab.c"
    break;

  case 121:
#line 335 "code.y"
                                                                        {(yyval.no) = makeNullNode(typeTable);}
#line 2502 "y.tab.c"
    break;

  case 122:
#line 336 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-2].string),gst,NULL);}
#line 2508 "y.tab.c"
    break;

  case 123:
#line 337 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,(yyvsp[-1].at));}
#line 2514 "y.tab.c"
    break;

  case 124:
#line 338 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2520 "y.tab.c"
    break;

  case 125:
#line 339 "code.y"
                                                                        {(yyval.no) = makeAddrNode((yyvsp[0].no),gst,lst,typeTable);}
#line 2526 "y.tab.c"
    break;

  case 126:
#line 340 "code.y"
                                                                        {(yyval.no) = makeAllocNode();}
#line 2532 "y.tab.c"
    break;

  case 127:
#line 341 "code.y"
                                                                        {(yyval.no) = makeMemInitNode(typeTable);}
#line 2538 "y.tab.c"
    break;

  case 128:
#line 342 "code.y"
                                                                        {(yyval.no) = makeFreeNode((yyvsp[-1].no),typeTable);}
#line 2544 "y.tab.c"
    break;

  case 129:
#line 345 "code.y"
                                        {(yyval.at) = addArguments((yyvsp[-2].at),makeArgStruct((yyvsp[0].no)));}
#line 2550 "y.tab.c"
    break;

  case 130:
#line 346 "code.y"
                                        {(yyval.at) = makeArgStruct((yyvsp[0].no));}
#line 2556 "y.tab.c"
    break;

  case 131:
#line 349 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2562 "y.tab.c"
    break;

  case 132:
#line 350 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[-1].no),typeTable);}
#line 2568 "y.tab.c"
    break;

  case 133:
#line 351 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[0].no),typeTable);}
#line 2574 "y.tab.c"
    break;

  case 134:
#line 352 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2580 "y.tab.c"
    break;

  case 135:
#line 355 "code.y"
                                                {(yyval.no) = extendTypeNode((yyvsp[-2].no),(yyvsp[0].string),typeTable,classTable);}
#line 2586 "y.tab.c"
    break;

  case 136:
#line 356 "code.y"
                                                {(yyval.no) = extendTypeNode((yyvsp[-2].no),(yyvsp[0].string),typeTable,classTable);}
#line 2592 "y.tab.c"
    break;

  case 137:
#line 359 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[-3].no) -> varname,gst,lst,addArrayDim((yyvsp[-3].no) -> indices,(yyvsp[-1].no)),typeTable,classTable);}
#line 2598 "y.tab.c"
    break;

  case 138:
#line 360 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[0].string),gst,lst,NULL,typeTable,classTable);}
#line 2604 "y.tab.c"
    break;


#line 2608 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 363 "code.y"


void yyerror(char const *s)
{
    printf("yyerror: %s",s);
    exit(0);
}

FILE* startCodeGen(int memLoc, struct GSymbolTable* gst){
	int label1 = getLabel();
	
	FILE *fp = fopen("output/output.out","w");
	fprintf(fp,"0\n2056\n0\n0\n0\n0\n0\n0\n");
	
	//to shift the SP and fill it with 0
	fprintf(fp,"MOV R2, SP\n");
	if(memLoc > 0){
		fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
		fprintf(fp,"L%d:\n",label1);
		fprintf(fp,"ADD R2, 1\n");
		fprintf(fp,"MOV R1, R2\n");
		fprintf(fp,"MOV [R1], 0\n");
		fprintf(fp,"EQ R1, SP\n");
		fprintf(fp,"JZ R1, L%d\n",label1);
	}
	
	fprintf(fp,"ADD SP, 1\n"); //allocate space for return from main
	
	if(gst != NULL)
		setMemLocationValues(gst,fp);
	fprintf(fp, "CALL MAIN\n");
	fprintf(fp,"CALL EXIT\n");
	return fp;
}

void endCodeGen(FILE *fp){
	lib_code_gen(end,0,fp);
	fclose(fp);
}

void setMemLocationValues(struct GSymbolTable* gst,FILE* fp){
	reg_index reg1;
	int curr_mem = 0;
	struct Gsymbol* node = gst -> head;
	struct ArrayShape *shape;
	int index1,index2,temp,endFrame;
	
	
	while(node != NULL){ // loop through global symbol table
		shape = node -> shape;
		
		if(node -> dtype -> nodetype == tupleType){
			fprintf(fp,"MOV R1, %d\n",node -> binding);
			fprintf(fp,"MOV [R1], %d\n", node -> binding + 1);
		}
		else if(shape != NULL){
			
			curr_mem = node -> binding;
			index1 = 1;
			
			while(shape != NULL){
			
				index2 = shape -> index;
				endFrame = curr_mem + index1;
				for(int i = 0; i<index1; ++i){
					temp = endFrame + (i * index2);
					fprintf(fp,"MOV R1, %d\n",curr_mem);
					fprintf(fp,"MOV [R1], %d\n", temp);
					curr_mem += 1;
				}
				
				index1 = index1 * index2;
				curr_mem = endFrame;
				shape = shape -> next;

			}
		}
		node = node -> next;
	}
}

int main(int argc, char* argv[]) {
	
	FILE *input_fp;

	if(argc > 1){
		input_fp = fopen(argv[1],"r");
		fflush(input_fp);
	
		if(input_fp)
			yyin = input_fp;
	}
	
	typeTable = TypeTableCreate();
	yyparse();
	
	if(input_fp)
		fclose(input_fp);
	return 0;
}
