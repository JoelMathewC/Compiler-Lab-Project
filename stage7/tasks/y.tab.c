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
	
	
	void startCodeGen(FILE* fp, int memLoc, struct GSymbolTable* gst, struct ClassTable* classTable);
	FILE* openFile();
	FILE *fp;
	
	char* currentClass;
	void endCodeGen(FILE *fp);
	void setMemLocationValues(struct GSymbolTable* gst,struct ClassTable* classTable, FILE* fp);

#line 127 "y.tab.c"

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
#line 58 "code.y"

	struct tnode *no;
	struct dnode *dno;
	struct ParamStruct *pt;
	struct ArgStruct *at;
	int number;
	char* string;
	int* seq;
	

#line 294 "y.tab.c"

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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   796

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  335

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
       0,    95,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   107,   108,   111,   112,   115,   116,   119,   125,
     132,   133,   134,   137,   138,   141,   144,   145,   148,   149,
     152,   155,   158,   159,   162,   171,   179,   180,   183,   184,
     187,   190,   191,   194,   197,   198,   202,   208,   211,   212,
     215,   216,   217,   218,   219,   222,   225,   228,   229,   232,
     233,   236,   237,   240,   241,   244,   245,   248,   255,   263,
     264,   265,   266,   269,   270,   271,   274,   275,   278,   284,
     287,   292,   293,   294,   297,   298,   301,   304,   305,   306,
     309,   310,   314,   315,   321,   322,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   339,   340,
     343,   344,   345,   348,   351,   354,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   386,   387,   390,   391,   392,   395,   396,
     399,   400
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
  "GclassList", "Gclass", "ClassName", "GclassDeclBlockSeg",
  "GclassDeclBlock", "GclassAttrDeclList", "GclassAttrDecl",
  "GclassIdList", "GclassFuncDeclList", "GclassFuncDecl", "GclassFuncName",
  "GclassFuncDefBlock", "GclassFuncDef", "MName", "GtypeBlock",
  "GtypeList", "Gtype", "GtypeDeclList", "GtypeDecl", "GtypeIdList",
  "GdeclBlock", "GdeclList", "Type", "TupleType", "Gdecl", "GidList",
  "Gid", "IdentifierDecl", "IdArrDecl", "FdefBlock", "Fdef", "FName",
  "FuncRetType", "ParamList", "Param", "MainBlock", "MainHeader",
  "LdeclBlock", "LdeclList", "Ldecl", "LocalType", "LidList", "Lid",
  "Slist", "Stmt", "IfStmt", "LoopStmt", "InputStmt", "OutputStmt",
  "AssgStmt", "expr", "ArgList", "Identifier", "StructId", "IdArr", YY_NULLPTR
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

#define YYPACT_NINF (-228)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,    12,   346,    13,     8,    23,   -14,     0,   206,  -228,
     -18,   -20,  -228,  -228,  -228,  -228,    56,  -228,   395,    55,
    -228,  -228,    59,  -228,    24,  -228,  -228,  -228,    10,  -228,
      63,  -228,   206,   -14,   206,  -228,  -228,  -228,    12,  -228,
     206,  -228,    76,    68,  -228,    33,    52,    20,  -228,  -228,
      74,   111,    45,  -228,  -228,    96,   187,  -228,  -228,  -228,
    -228,   120,   206,  -228,   206,   206,  -228,  -228,  -228,    33,
     102,   153,   138,  -228,   187,   187,  -228,  -228,  -228,    55,
     163,    57,  -228,   167,   187,    94,  -228,  -228,   206,  -228,
    -228,   147,   187,  -228,  -228,  -228,  -228,   159,  -228,   128,
     344,   141,    22,  -228,    53,  -228,   124,  -228,  -228,  -228,
      58,   424,  -228,   681,  -228,   181,  -228,   127,  -228,   133,
     188,  -228,   489,   125,  -228,  -228,  -228,   193,    85,  -228,
     148,     6,   149,   155,   156,   164,   172,   489,   489,   225,
     228,   307,   372,  -228,  -228,  -228,  -228,  -228,  -228,   244,
     205,   211,  -228,   270,   187,  -228,  -228,  -228,  -228,   272,
    -228,  -228,   687,  -228,  -228,   273,   222,    92,   250,  -228,
    -228,    33,   224,   393,  -228,  -228,  -228,   128,   113,  -228,
     307,  -228,   221,  -228,   142,   307,   307,   307,   506,   411,
    -228,  -228,   227,  -228,  -228,  -228,   282,   142,   232,   233,
     234,   307,   707,  -228,   231,   238,  -228,   307,   289,   307,
    -228,  -228,  -228,  -228,   222,   187,  -228,   290,  -228,   268,
     187,   252,  -228,   275,   743,   170,   562,   303,   253,   577,
     595,   610,   260,   262,   246,  -228,  -228,   265,   266,   142,
     625,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,  -228,   320,  -228,   725,   269,   547,
     174,  -228,   489,   191,  -228,  -228,   307,   297,  -228,  -228,
     299,   300,   288,   286,   307,   307,  -228,   192,  -228,  -228,
     279,  -228,   207,   207,  -228,  -228,  -228,   773,   773,   773,
     773,   773,   773,   758,   758,   283,  -228,   258,  -228,  -228,
     436,  -228,   743,  -228,  -228,  -228,   489,   489,   643,   658,
    -228,  -228,   295,  -228,   198,   284,   323,   454,    25,   311,
    -228,   218,  -228,  -228,   489,   312,   313,  -228,  -228,  -228,
     471,  -228,  -228,   314,  -228
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,    53,    51,    50,    52,     0,    47,     0,     0,
      54,    49,     0,    37,     0,    39,    18,    13,     0,    15,
       0,     1,     0,     0,     0,     8,    72,    70,    69,    71,
       0,    66,     0,     0,    10,    83,     0,     0,    46,    48,
      64,     0,     0,    58,    59,    62,     0,    36,    38,    12,
      14,     0,     0,     5,     0,     0,     7,    65,     9,    83,
       0,     0,     0,    80,    75,    75,    64,    61,    56,     0,
       0,     0,    42,     0,     0,     0,    19,     4,     0,     3,
       6,     0,    75,    89,    88,    87,    82,     0,    85,     0,
       0,     0,     0,    74,     0,    57,     0,    40,    41,    45,
       0,     0,    24,     0,    29,     0,    17,     0,    33,     0,
       0,     2,     0,     0,    81,    84,    92,     0,     0,    91,
     151,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    99,   100,    96,    97,    98,     0,
     147,   149,    76,     0,     0,    55,    60,    63,    43,     0,
      22,    23,     0,    21,    28,     0,    27,     0,     0,    16,
      32,    83,     0,     0,    68,    93,    86,     0,     0,   151,
       0,   146,   147,    79,     0,     0,     0,     0,     0,     0,
     101,   102,   151,   130,   132,   133,     0,     0,     0,     0,
       0,     0,     0,   136,   147,     0,    94,     0,     0,     0,
      77,    73,    44,    20,     0,    75,    25,     0,    30,     0,
      75,     0,    90,     0,   144,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,   137,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,    78,     0,   148,     0,
       0,    26,     0,     0,    67,   103,     0,     0,   145,   148,
       0,     0,     0,     0,     0,     0,   134,     0,   138,   139,
       0,   129,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   148,   115,     0,   150,    31,
       0,    35,   143,   104,   113,   114,     0,     0,     0,     0,
     135,   140,     0,   105,     0,     0,     0,     0,     0,     0,
     141,     0,   106,    34,     0,     0,     0,   111,   112,   142,
       0,   109,   110,     0,   108
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -228,  -228,   337,  -228,   321,  -228,  -228,  -228,  -228,   245,
    -228,   251,  -107,  -228,  -228,   248,  -228,  -228,  -228,   354,
    -228,   280,  -228,    87,  -228,    11,  -228,   352,  -228,   304,
     328,  -228,   -23,    16,  -228,  -228,   -71,   230,    18,  -228,
     -64,  -228,   285,  -228,  -228,   210,  -119,  -141,  -228,  -228,
    -228,  -228,  -228,    -8,  -227,  -100,   -98,  -228
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    28,    29,    30,    85,    86,   111,   112,
     167,   113,   114,   168,   117,   118,   119,     7,    24,    25,
      81,    82,   110,     8,    18,   101,    20,    21,    52,    53,
      54,    55,    40,    41,    42,    43,   102,   103,     9,    10,
      72,    97,    98,    99,   128,   129,   142,   143,   144,   145,
     146,   147,   148,   224,   225,   203,   204,   151
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     149,   206,   150,   173,   104,    91,   164,   277,     1,    62,
     179,    65,    26,    19,    26,    11,     2,    22,   188,   189,
     131,   123,   149,    31,   150,    35,    44,     1,    22,    19,
       2,   181,   206,   182,     4,    45,    46,   149,   149,   150,
     150,    88,   149,    27,   150,    59,    23,   206,   206,     2,
      63,     3,    66,     4,   327,   164,    67,    57,    68,    50,
      47,    12,   180,    71,    13,    14,    15,    83,    16,    51,
     314,   307,    70,   149,    78,   150,    74,   154,    67,   155,
      87,    67,    89,    90,   228,   321,   182,   158,   149,   149,
     150,   150,    83,    32,    34,   115,   120,   236,    12,   182,
      79,    13,    14,    15,    67,    16,   121,   219,   154,    73,
     156,   107,    56,   159,   176,    76,    61,   192,   193,   194,
      64,   216,   115,   195,   165,    51,   196,   131,   120,    69,
      75,    12,   126,   202,    13,    14,    15,   197,    16,   280,
     177,   182,   127,   300,   260,   152,   179,   217,   116,   263,
      84,   198,   199,   200,    80,   153,   131,    93,    92,   206,
      94,    95,   149,    93,   150,   100,    94,    95,   106,   201,
     223,   109,   226,   165,   122,   206,   206,   229,   230,   231,
     154,   169,   174,   157,    96,   166,   171,   316,   317,   206,
     124,    12,   172,   240,    13,    14,    15,   175,    16,   257,
     149,   259,   150,   183,   178,   330,   149,   149,   150,   150,
      36,   184,   185,    37,    38,    39,   149,   149,   150,   150,
     186,   243,   244,   245,   149,   266,   150,   267,   187,   154,
     149,   299,   150,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   154,   266,   301,   310,
     192,   193,   194,   266,   190,   322,   195,   191,   302,   196,
     131,   207,   192,   193,   194,   208,   308,   309,   195,   209,
     197,   196,   131,   266,   210,   329,   212,   214,   215,   218,
     220,   227,   197,   234,   198,   199,   200,   235,   237,   238,
     239,   255,   256,   258,   261,   262,   198,   199,   200,   192,
     193,   194,   201,   276,   265,   195,   264,   269,   196,   131,
     270,   192,   193,   194,   201,   313,   274,   195,   275,   197,
     196,   131,   278,   279,   295,   297,   303,   130,   304,   305,
     306,   197,   307,   198,   199,   200,   311,   131,   323,   312,
     328,   331,   332,   334,    33,   198,   199,   200,   130,    60,
      12,   201,   320,    13,    14,    15,   161,    16,   131,   133,
     134,   108,   162,   201,   135,   170,   324,   325,   136,   137,
      49,   138,   132,   139,   140,   141,   130,    17,    58,    77,
     133,   134,   125,   105,   211,   135,   131,   222,     0,   136,
     137,     0,   138,     0,   139,   140,   141,   130,     0,    12,
     205,     0,    13,    14,    15,     0,    16,   131,   133,   134,
       0,     0,     0,   135,     0,   130,     0,   136,   137,     0,
     138,   221,   139,   140,   141,   131,    48,     0,    12,   133,
     134,    13,    14,    15,   135,    16,     0,     0,   136,   137,
     130,   138,     0,   139,   140,   141,     0,   133,   134,     0,
     131,     0,   135,     0,     0,   160,   136,   137,   130,   138,
     233,   139,   140,   141,   315,     0,     0,     0,   131,     0,
       0,     0,   133,   134,     0,   130,     0,   135,     0,     0,
       0,   136,   137,     0,   138,   131,   139,   140,   141,     0,
     133,   134,     0,   130,     0,   135,     0,     0,     0,   136,
     137,   326,   138,   131,   139,   140,   141,   133,   134,     0,
     130,     0,   135,     0,     0,   333,   136,   137,     0,   138,
     131,   139,   140,   141,     0,   133,   134,     0,     0,     0,
     135,     0,     0,     0,   136,   137,     0,   138,     0,   139,
     140,   141,   133,   134,     0,     0,     0,   135,     0,     0,
       0,   232,   137,     0,   138,     0,   139,   140,   141,   241,
     242,   243,   244,   245,     0,   246,   247,   248,   249,   250,
     251,     0,   252,   253,   241,   242,   243,   244,   245,     0,
     246,   247,   248,   249,   250,   251,     0,   252,   253,   241,
     242,   243,   244,   245,     0,   246,   247,   248,   249,   250,
     251,     0,   252,   253,     0,     0,   298,   241,   242,   243,
     244,   245,     0,   246,   247,   248,   249,   250,   251,   268,
     252,   253,   241,   242,   243,   244,   245,     0,   246,   247,
     248,   249,   250,   251,   271,   252,   253,   241,   242,   243,
     244,   245,     0,   246,   247,   248,   249,   250,   251,     0,
     252,   253,   272,     0,     0,   241,   242,   243,   244,   245,
       0,   246,   247,   248,   249,   250,   251,   273,   252,   253,
     241,   242,   243,   244,   245,     0,   246,   247,   248,   249,
     250,   251,   281,   252,   253,    12,     0,     0,    13,    14,
      15,    12,    16,     0,    13,    14,    15,     0,    16,     0,
     318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,     0,     0,   319,     0,     0,   213,   241,
     242,   243,   244,   245,     0,   246,   247,   248,   249,   250,
     251,     0,   252,   253,     0,     0,   254,   241,   242,   243,
     244,   245,     0,   246,   247,   248,   249,   250,   251,     0,
     252,   253,     0,     0,   296,   241,   242,   243,   244,   245,
       0,   246,   247,   248,   249,   250,   251,     0,   252,   253,
     241,   242,   243,   244,   245,     0,   246,   247,   248,   249,
     250,   251,     0,    -1,    -1,   241,   242,   243,   244,   245,
       0,    -1,    -1,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
     100,   142,   100,   122,    75,    69,   113,   234,     8,    32,
       4,    34,     4,     2,     4,     3,    30,     4,   137,   138,
      14,    92,   122,     0,   122,     7,     8,     8,     4,    18,
      30,   131,   173,   131,    34,    53,    56,   137,   138,   137,
     138,    64,   142,    35,   142,    35,    33,   188,   189,    30,
      32,    32,    34,    34,    29,   162,    40,    33,    40,     4,
       4,     4,    56,    30,     7,     8,     9,    56,    11,    14,
     297,    46,     4,   173,    29,   173,    56,    55,    62,    57,
      62,    65,    64,    65,   184,   312,   184,    29,   188,   189,
     188,   189,    81,     6,     7,    84,    85,   197,     4,   197,
      55,     7,     8,     9,    88,    11,    88,   171,    55,    57,
      57,    54,    53,    55,    29,     4,    53,     4,     5,     6,
      33,    29,   111,    10,   113,    14,    13,    14,   117,    53,
      56,     4,     4,   141,     7,     8,     9,    24,    11,   239,
      55,   239,    14,   262,   215,     4,     4,    55,    54,   220,
      30,    38,    39,    40,    58,    14,    14,     4,    56,   300,
       7,     8,   262,     4,   262,    27,     7,     8,     5,    56,
      57,     4,   180,   162,    27,   316,   317,   185,   186,   187,
      55,    54,    57,    59,    31,     4,    53,   306,   307,   330,
      31,     4,     4,   201,     7,     8,     9,     4,    11,   207,
     300,   209,   300,    54,    56,   324,   306,   307,   306,   307,
       4,    56,    56,     7,     8,     9,   316,   317,   316,   317,
      56,    14,    15,    16,   324,    55,   324,    57,    56,    55,
     330,    57,   330,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    55,    55,    57,    57,
       4,     5,     6,    55,    29,    57,    10,    29,   266,    13,
      14,    17,     4,     5,     6,    60,   274,   275,    10,    58,
      24,    13,    14,    55,     4,    57,     4,     4,    56,    29,
      56,    60,    24,    56,    38,    39,    40,     5,    56,    56,
      56,    60,    54,     4,     4,    27,    38,    39,    40,     4,
       5,     6,    56,    57,    29,    10,    54,     4,    13,    14,
      57,     4,     5,     6,    56,    57,    56,    10,    56,    24,
      13,    14,    57,    57,     4,    56,    29,     4,    29,    29,
      42,    24,    46,    38,    39,    40,    57,    14,    54,    56,
      29,    29,    29,    29,     7,    38,    39,    40,     4,    28,
       4,    56,    57,     7,     8,     9,   111,    11,    14,    36,
      37,    81,   111,    56,    41,   117,    43,    44,    45,    46,
      18,    48,    28,    50,    51,    52,     4,    31,    24,    51,
      36,    37,    97,    79,   154,    41,    14,   177,    -1,    45,
      46,    -1,    48,    -1,    50,    51,    52,     4,    -1,     4,
      28,    -1,     7,     8,     9,    -1,    11,    14,    36,    37,
      -1,    -1,    -1,    41,    -1,     4,    -1,    45,    46,    -1,
      48,    28,    50,    51,    52,    14,    31,    -1,     4,    36,
      37,     7,     8,     9,    41,    11,    -1,    -1,    45,    46,
       4,    48,    -1,    50,    51,    52,    -1,    36,    37,    -1,
      14,    -1,    41,    -1,    -1,    31,    45,    46,     4,    48,
      49,    50,    51,    52,    28,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    36,    37,    -1,     4,    -1,    41,    -1,    -1,
      -1,    45,    46,    -1,    48,    14,    50,    51,    52,    -1,
      36,    37,    -1,     4,    -1,    41,    -1,    -1,    -1,    45,
      46,    47,    48,    14,    50,    51,    52,    36,    37,    -1,
       4,    -1,    41,    -1,    -1,    44,    45,    46,    -1,    48,
      14,    50,    51,    52,    -1,    36,    37,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    45,    46,    -1,    48,    -1,    50,
      51,    52,    36,    37,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    45,    46,    -1,    48,    -1,    50,    51,    52,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    -1,    -1,    59,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    57,
      25,    26,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    23,    57,    25,    26,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    57,    -1,    -1,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    57,    25,    26,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    57,    25,    26,     4,    -1,    -1,     7,     8,
       9,     4,    11,    -1,     7,     8,     9,    -1,    11,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    57,    -1,    -1,    31,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    -1,    -1,    29,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    -1,    -1,    29,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    30,    32,    34,    62,    63,    78,    84,    99,
     100,     3,     4,     7,     8,     9,    11,    31,    85,    86,
      87,    88,     4,    33,    79,    80,     4,    35,    64,    65,
      66,     0,    84,    63,    84,    99,     4,     7,     8,     9,
      93,    94,    95,    96,    99,    53,    56,     4,    31,    88,
       4,    14,    89,    90,    91,    92,    53,    33,    80,    35,
      65,    53,    93,    99,    84,    93,    99,    94,    99,    53,
       4,    30,   101,    57,    56,    56,     4,    91,    29,    55,
      58,    81,    82,    86,    30,    67,    68,    99,    93,    99,
      99,   101,    56,     4,     7,     8,    31,   102,   103,   104,
      27,    86,    97,    98,    97,    90,     5,    54,    82,     4,
      83,    69,    70,    72,    73,    86,    54,    75,    76,    77,
      86,    99,    27,    97,    31,   103,     4,    14,   105,   106,
       4,    14,    28,    36,    37,    41,    45,    46,    48,    50,
      51,    52,   107,   108,   109,   110,   111,   112,   113,   116,
     117,   118,     4,    14,    55,    57,    57,    59,    29,    55,
      31,    70,    72,    31,    73,    86,     4,    71,    74,    54,
      76,    53,     4,   107,    57,     4,    29,    55,    56,     4,
      56,   116,   117,    54,    56,    56,    56,    56,   107,   107,
      29,    29,     4,     5,     6,    10,    13,    24,    38,    39,
      40,    56,   114,   116,   117,    28,   108,    17,    60,    58,
       4,    98,     4,    31,     4,    56,    29,    55,    29,   101,
      56,    28,   106,    57,   114,   115,   114,    60,   116,   114,
     114,   114,    45,    49,    56,     5,   116,    56,    56,    56,
     114,    12,    13,    14,    15,    16,    18,    19,    20,    21,
      22,    23,    25,    26,    29,    60,    54,   114,     4,   114,
      97,     4,    27,    97,    54,    29,    55,    57,    57,     4,
      57,    57,    57,    57,    56,    56,    57,   115,    57,    57,
     116,    57,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,     4,    29,    56,    59,    57,
     107,    57,   114,    29,    29,    29,    42,    46,   114,   114,
      57,    57,    56,    57,   115,    28,   107,   107,    57,    57,
      57,   115,    57,    54,    43,    44,    47,    29,    29,    57,
     107,    29,    29,    44,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    67,
      68,    68,    68,    69,    69,    70,    71,    71,    72,    72,
      73,    74,    75,    75,    76,    77,    78,    78,    79,    79,
      80,    81,    81,    82,    83,    83,    84,    84,    85,    85,
      86,    86,    86,    86,    86,    87,    88,    89,    89,    90,
      90,    91,    91,    92,    92,    93,    93,    94,    95,    96,
      96,    96,    96,    97,    97,    97,    98,    98,    99,    99,
     100,   101,   101,   101,   102,   102,   103,   104,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     110,   110,   110,   111,   112,   113,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   115,   115,   116,   116,   116,   117,   117,
     118,   118
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     4,     3,     4,     3,     2,     3,
       2,     1,     3,     2,     2,     1,     5,     4,     1,     1,
       4,     3,     3,     2,     1,     3,     3,     1,     2,     1,
       3,     4,     2,     1,     7,     5,     3,     2,     2,     1,
       4,     2,     1,     3,     3,     1,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     5,     3,     3,     1,     1,
       4,     2,     1,     4,     1,     2,     1,     7,     5,     1,
       1,     1,     1,     3,     1,     0,     2,     3,     7,     6,
       4,     3,     2,     0,     2,     1,     3,     1,     1,     1,
       3,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     4,     5,     5,     6,     3,    10,     8,
       8,     7,     7,     5,     5,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     2,     1,     1,     3,     4,     1,     2,     3,     3,
       4,     5,     6,     3,     1,     4,     2,     1,     3,     1,
       4,     1
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
#line 95 "code.y"
                                                                {}
#line 1796 "y.tab.c"
    break;

  case 3:
#line 96 "code.y"
                                                                        {}
#line 1802 "y.tab.c"
    break;

  case 4:
#line 97 "code.y"
                                                                        {}
#line 1808 "y.tab.c"
    break;

  case 5:
#line 98 "code.y"
                                                                        {}
#line 1814 "y.tab.c"
    break;

  case 6:
#line 99 "code.y"
                                                                        {}
#line 1820 "y.tab.c"
    break;

  case 7:
#line 100 "code.y"
                                                                        {}
#line 1826 "y.tab.c"
    break;

  case 8:
#line 101 "code.y"
                                                                        {}
#line 1832 "y.tab.c"
    break;

  case 9:
#line 102 "code.y"
                                                                        {}
#line 1838 "y.tab.c"
    break;

  case 10:
#line 103 "code.y"
                                                                        {}
#line 1844 "y.tab.c"
    break;

  case 11:
#line 104 "code.y"
                                                                        {}
#line 1850 "y.tab.c"
    break;

  case 12:
#line 107 "code.y"
                                                        {/*printClassTable(classTable);*/printf("CLASS DONE\n");}
#line 1856 "y.tab.c"
    break;

  case 13:
#line 108 "code.y"
                                                                {}
#line 1862 "y.tab.c"
    break;

  case 14:
#line 111 "code.y"
                                                        {}
#line 1868 "y.tab.c"
    break;

  case 15:
#line 112 "code.y"
                                                                {}
#line 1874 "y.tab.c"
    break;

  case 16:
#line 115 "code.y"
                                                                                {}
#line 1880 "y.tab.c"
    break;

  case 17:
#line 116 "code.y"
                                                                        {}
#line 1886 "y.tab.c"
    break;

  case 18:
#line 119 "code.y"
                                                                                {
											currentClass = strdup((yyvsp[0].string));
											(yyval.string) = (yyvsp[0].string);
										}
#line 1895 "y.tab.c"
    break;

  case 19:
#line 125 "code.y"
                                                                                {	
											getMemLoc(8);
											addToClassTable(classTable, typeTable, (yyvsp[0].dno), currentClass);

										}
#line 1905 "y.tab.c"
    break;

  case 20:
#line 132 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[-1].dno));}
#line 1911 "y.tab.c"
    break;

  case 21:
#line 133 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode(NULL,(yyvsp[-1].dno));}
#line 1917 "y.tab.c"
    break;

  case 22:
#line 134 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),NULL);}
#line 1923 "y.tab.c"
    break;

  case 23:
#line 137 "code.y"
                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1929 "y.tab.c"
    break;

  case 24:
#line 138 "code.y"
                                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1935 "y.tab.c"
    break;

  case 25:
#line 141 "code.y"
                                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 1941 "y.tab.c"
    break;

  case 26:
#line 144 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),declIdNode((yyvsp[-2].string),0,NULL));}
#line 1947 "y.tab.c"
    break;

  case 27:
#line 145 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 1953 "y.tab.c"
    break;

  case 28:
#line 148 "code.y"
                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1959 "y.tab.c"
    break;

  case 29:
#line 149 "code.y"
                                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1965 "y.tab.c"
    break;

  case 30:
#line 152 "code.y"
                                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 1971 "y.tab.c"
    break;

  case 31:
#line 155 "code.y"
                                                                {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 1977 "y.tab.c"
    break;

  case 32:
#line 158 "code.y"
                                                                {}
#line 1983 "y.tab.c"
    break;

  case 33:
#line 159 "code.y"
                                                                {}
#line 1989 "y.tab.c"
    break;

  case 34:
#line 162 "code.y"
                                                                        {	
										
										struct ClassTableEntry* entry = CLookup(classTable,currentClass);
										struct MethodList* method = MLookup(entry -> methodList,(yyvsp[-6].string));
										funcCodeGen((yyvsp[-2].no), fp,method -> flabel);
										lst = NULL;
									}
#line 2001 "y.tab.c"
    break;

  case 35:
#line 171 "code.y"
                                                        {	
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyMethodHead((yyvsp[-3].string),(yyvsp[-1].pt),TLookup(typeTable,(yyvsp[-4].string)),CLookup(classTable,currentClass));
								addMethodParamToLST(lst,(yyvsp[-1].pt),CLookup(classTable,currentClass));
								(yyval.string) = (yyvsp[-3].string);
							}
#line 2012 "y.tab.c"
    break;

  case 36:
#line 179 "code.y"
                                                        {printf("TYPE DONE\n");}
#line 2018 "y.tab.c"
    break;

  case 37:
#line 180 "code.y"
                                                        {}
#line 2024 "y.tab.c"
    break;

  case 38:
#line 183 "code.y"
                                                        {}
#line 2030 "y.tab.c"
    break;

  case 39:
#line 184 "code.y"
                                                {}
#line 2036 "y.tab.c"
    break;

  case 40:
#line 187 "code.y"
                                                        {addUserDefToTypeTable(typeTable,(yyvsp[-1].dno),(yyvsp[-3].string));}
#line 2042 "y.tab.c"
    break;

  case 41:
#line 190 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2048 "y.tab.c"
    break;

  case 42:
#line 191 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2054 "y.tab.c"
    break;

  case 43:
#line 194 "code.y"
                                                        {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2060 "y.tab.c"
    break;

  case 44:
#line 197 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),declIdNode((yyvsp[-2].string),0,NULL));}
#line 2066 "y.tab.c"
    break;

  case 45:
#line 198 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2072 "y.tab.c"
    break;

  case 46:
#line 202 "code.y"
                                        {	
						gst = (struct GSymbolTable*)malloc(sizeof(struct GSymbolTable));
						generateGlobalSymbolTable(gst,(yyvsp[-1].dno),NULL,NULL,typeTable,classTable);
						startCodeGen(fp,memLoc,gst,classTable);
						//printGlobalSymbolTable(gst);
					}
#line 2083 "y.tab.c"
    break;

  case 47:
#line 208 "code.y"
                                        {gst = NULL;}
#line 2089 "y.tab.c"
    break;

  case 48:
#line 211 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2095 "y.tab.c"
    break;

  case 49:
#line 212 "code.y"
                                {(yyval.dno) = (yyvsp[0].dno);}
#line 2101 "y.tab.c"
    break;

  case 50:
#line 215 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2107 "y.tab.c"
    break;

  case 51:
#line 216 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2113 "y.tab.c"
    break;

  case 52:
#line 217 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2119 "y.tab.c"
    break;

  case 53:
#line 218 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2125 "y.tab.c"
    break;

  case 54:
#line 219 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2131 "y.tab.c"
    break;

  case 55:
#line 222 "code.y"
                                        {addTupleToTypeTable(typeTable,(yyvsp[-1].pt),(yyvsp[-3].string));(yyval.string) = (yyvsp[-3].string);}
#line 2137 "y.tab.c"
    break;

  case 56:
#line 225 "code.y"
                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2143 "y.tab.c"
    break;

  case 57:
#line 228 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 2149 "y.tab.c"
    break;

  case 58:
#line 229 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2155 "y.tab.c"
    break;

  case 59:
#line 232 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2161 "y.tab.c"
    break;

  case 60:
#line 233 "code.y"
                                                        {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 2167 "y.tab.c"
    break;

  case 61:
#line 236 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].dno) -> varname,(yyvsp[0].dno) -> dim + 1,(yyvsp[0].dno) -> shape);}
#line 2173 "y.tab.c"
    break;

  case 62:
#line 237 "code.y"
                                                {(yyval.dno) = (yyvsp[0].dno);}
#line 2179 "y.tab.c"
    break;

  case 63:
#line 240 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[-3].dno) -> varname,(yyvsp[-3].dno) -> dim + 1,addArrayShape((yyvsp[-3].dno) -> shape,(yyvsp[-1].number)));}
#line 2185 "y.tab.c"
    break;

  case 64:
#line 241 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2191 "y.tab.c"
    break;

  case 65:
#line 244 "code.y"
                                                        {}
#line 2197 "y.tab.c"
    break;

  case 66:
#line 245 "code.y"
                                                        {}
#line 2203 "y.tab.c"
    break;

  case 67:
#line 248 "code.y"
                                                        {	
									struct Gsymbol* g = GlobalLookup(gst,(yyvsp[-6].string));
									funcCodeGen((yyvsp[-2].no), fp,g -> flabel);
									lst = NULL;
								}
#line 2213 "y.tab.c"
    break;

  case 68:
#line 255 "code.y"
                                                                {
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyFuncHead(gst,(yyvsp[-3].string),TLookup(typeTable,(yyvsp[-4].string)),CLookup(classTable,(yyvsp[-4].string)),(yyvsp[-1].pt));
								addParamToLST(lst,(yyvsp[-1].pt));
								(yyval.string) = (yyvsp[-3].string);
							}
#line 2224 "y.tab.c"
    break;

  case 69:
#line 263 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2230 "y.tab.c"
    break;

  case 70:
#line 264 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2236 "y.tab.c"
    break;

  case 71:
#line 265 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2242 "y.tab.c"
    break;

  case 72:
#line 266 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2248 "y.tab.c"
    break;

  case 73:
#line 269 "code.y"
                                                {(yyval.pt) = addParameter((yyvsp[-2].pt),(yyvsp[0].pt));}
#line 2254 "y.tab.c"
    break;

  case 74:
#line 270 "code.y"
                                                {(yyval.pt) = (yyvsp[0].pt);}
#line 2260 "y.tab.c"
    break;

  case 75:
#line 271 "code.y"
                                                        {(yyval.pt) = NULL;}
#line 2266 "y.tab.c"
    break;

  case 76:
#line 274 "code.y"
                                                {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-1].string),0,typeTable,classTable);}
#line 2272 "y.tab.c"
    break;

  case 77:
#line 275 "code.y"
                                                        {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-2].string),1,typeTable,classTable);}
#line 2278 "y.tab.c"
    break;

  case 78:
#line 278 "code.y"
                                                                {	
									if(gst == NULL){
										startCodeGen(fp,-1,gst,classTable);	
										fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
									}
									funcCodeGen((yyvsp[-2].no), fp,-1);}
#line 2289 "y.tab.c"
    break;

  case 79:
#line 284 "code.y"
                                                                {exit(0);}
#line 2295 "y.tab.c"
    break;

  case 80:
#line 287 "code.y"
                                {lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));}
#line 2301 "y.tab.c"
    break;

  case 81:
#line 292 "code.y"
                                        {localMemLoc = 0; addLocalVarToLST(lst,(yyvsp[-1].dno),NULL,NULL,typeTable,classTable);}
#line 2307 "y.tab.c"
    break;

  case 82:
#line 293 "code.y"
                                        {(yyval.dno) = NULL;}
#line 2313 "y.tab.c"
    break;

  case 83:
#line 294 "code.y"
                                        {(yyval.dno) = NULL;}
#line 2319 "y.tab.c"
    break;

  case 84:
#line 297 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2325 "y.tab.c"
    break;

  case 85:
#line 298 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2331 "y.tab.c"
    break;

  case 86:
#line 301 "code.y"
                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2337 "y.tab.c"
    break;

  case 87:
#line 304 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2343 "y.tab.c"
    break;

  case 88:
#line 305 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2349 "y.tab.c"
    break;

  case 89:
#line 306 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2355 "y.tab.c"
    break;

  case 90:
#line 309 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 2361 "y.tab.c"
    break;

  case 91:
#line 310 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2367 "y.tab.c"
    break;

  case 92:
#line 314 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2373 "y.tab.c"
    break;

  case 93:
#line 315 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),1,NULL);}
#line 2379 "y.tab.c"
    break;

  case 94:
#line 321 "code.y"
                                                                        {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 2385 "y.tab.c"
    break;

  case 95:
#line 322 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2391 "y.tab.c"
    break;

  case 96:
#line 325 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2397 "y.tab.c"
    break;

  case 97:
#line 326 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2403 "y.tab.c"
    break;

  case 98:
#line 327 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2409 "y.tab.c"
    break;

  case 99:
#line 328 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2415 "y.tab.c"
    break;

  case 100:
#line 329 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2421 "y.tab.c"
    break;

  case 101:
#line 330 "code.y"
                                                                {(yyval.no) = makeJumpNode(break_node);}
#line 2427 "y.tab.c"
    break;

  case 102:
#line 331 "code.y"
                                                                        {(yyval.no) = makeJumpNode(continue_node);}
#line 2433 "y.tab.c"
    break;

  case 103:
#line 332 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,NULL);}
#line 2439 "y.tab.c"
    break;

  case 104:
#line 333 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-4].string),gst,(yyvsp[-2].at));}
#line 2445 "y.tab.c"
    break;

  case 105:
#line 334 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-4].no),(yyvsp[-2].string),NULL,typeTable);}
#line 2451 "y.tab.c"
    break;

  case 106:
#line 335 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-5].no),(yyvsp[-3].string),(yyvsp[-1].at),typeTable);}
#line 2457 "y.tab.c"
    break;

  case 107:
#line 336 "code.y"
                                                                        {(yyval.no) = makeReturnNode((yyvsp[-1].no));}
#line 2463 "y.tab.c"
    break;

  case 108:
#line 339 "code.y"
                                                                {(yyval.no) = makeIfElseBlock((yyvsp[-7].no),(yyvsp[-4].no),(yyvsp[-2].no));}
#line 2469 "y.tab.c"
    break;

  case 109:
#line 340 "code.y"
                                                                        {(yyval.no) = makeIfElseBlock((yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 2475 "y.tab.c"
    break;

  case 110:
#line 343 "code.y"
                                                                {(yyval.no) = makeWhileBlock((yyvsp[-5].no),(yyvsp[-2].no));}
#line 2481 "y.tab.c"
    break;

  case 111:
#line 344 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 2487 "y.tab.c"
    break;

  case 112:
#line 345 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 2493 "y.tab.c"
    break;

  case 113:
#line 348 "code.y"
                                                                        {(yyval.no) = makeReadNode((yyvsp[-2].no));}
#line 2499 "y.tab.c"
    break;

  case 114:
#line 351 "code.y"
                                                                {(yyval.no) = makeWriteNode((yyvsp[-2].no));}
#line 2505 "y.tab.c"
    break;

  case 115:
#line 354 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(assign,(yyvsp[-3].no),(yyvsp[-1].no),typeTable);}
#line 2511 "y.tab.c"
    break;

  case 116:
#line 357 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(add,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2517 "y.tab.c"
    break;

  case 117:
#line 358 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(sub,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2523 "y.tab.c"
    break;

  case 118:
#line 359 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(mul,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2529 "y.tab.c"
    break;

  case 119:
#line 360 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(div,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2535 "y.tab.c"
    break;

  case 120:
#line 361 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(mod,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2541 "y.tab.c"
    break;

  case 121:
#line 362 "code.y"
                                                                {(yyval.no) = makeOperatorNode(gt,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2547 "y.tab.c"
    break;

  case 122:
#line 363 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(gte,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2553 "y.tab.c"
    break;

  case 123:
#line 364 "code.y"
                                                                {(yyval.no) = makeOperatorNode(lt,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2559 "y.tab.c"
    break;

  case 124:
#line 365 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(lte,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2565 "y.tab.c"
    break;

  case 125:
#line 366 "code.y"
                                                                {(yyval.no) = makeOperatorNode(eq,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2571 "y.tab.c"
    break;

  case 126:
#line 367 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(neq,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2577 "y.tab.c"
    break;

  case 127:
#line 368 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(and,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2583 "y.tab.c"
    break;

  case 128:
#line 369 "code.y"
                                                                {(yyval.no) = makeOperatorNode(or,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2589 "y.tab.c"
    break;

  case 129:
#line 370 "code.y"
                                                                {(yyval.no) = (yyvsp[-1].no);}
#line 2595 "y.tab.c"
    break;

  case 130:
#line 371 "code.y"
                                                                        {(yyval.no) = makeNumNode((yyvsp[0].number),0,typeTable);}
#line 2601 "y.tab.c"
    break;

  case 131:
#line 372 "code.y"
                                                                        {(yyval.no) = makeNumNode(-1 * (yyvsp[0].number),0,typeTable);}
#line 2607 "y.tab.c"
    break;

  case 132:
#line 373 "code.y"
                                                                        {(yyval.no) = makeStringNode((yyvsp[0].string),typeTable);}
#line 2613 "y.tab.c"
    break;

  case 133:
#line 374 "code.y"
                                                                        {(yyval.no) = makeNullNode(typeTable);}
#line 2619 "y.tab.c"
    break;

  case 134:
#line 375 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-2].string),gst,NULL);}
#line 2625 "y.tab.c"
    break;

  case 135:
#line 376 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,(yyvsp[-1].at));}
#line 2631 "y.tab.c"
    break;

  case 136:
#line 377 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2637 "y.tab.c"
    break;

  case 137:
#line 378 "code.y"
                                                                        {(yyval.no) = makeAddrNode((yyvsp[0].no),gst,lst,typeTable);}
#line 2643 "y.tab.c"
    break;

  case 138:
#line 379 "code.y"
                                                                        {(yyval.no) = makeAllocNode();}
#line 2649 "y.tab.c"
    break;

  case 139:
#line 380 "code.y"
                                                                        {(yyval.no) = makeMemInitNode(typeTable);}
#line 2655 "y.tab.c"
    break;

  case 140:
#line 381 "code.y"
                                                                        {(yyval.no) = makeFreeNode((yyvsp[-1].no),typeTable);}
#line 2661 "y.tab.c"
    break;

  case 141:
#line 382 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-4].no),(yyvsp[-2].string),NULL,typeTable);}
#line 2667 "y.tab.c"
    break;

  case 142:
#line 383 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-5].no),(yyvsp[-3].string),(yyvsp[-1].at),typeTable);}
#line 2673 "y.tab.c"
    break;

  case 143:
#line 386 "code.y"
                                        {(yyval.at) = addArguments((yyvsp[-2].at),makeArgStruct((yyvsp[0].no)),typeTable);}
#line 2679 "y.tab.c"
    break;

  case 144:
#line 387 "code.y"
                                        {(yyval.at) = makeArgStruct((yyvsp[0].no));}
#line 2685 "y.tab.c"
    break;

  case 145:
#line 390 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[-1].no),typeTable);}
#line 2691 "y.tab.c"
    break;

  case 146:
#line 391 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[0].no),typeTable);}
#line 2697 "y.tab.c"
    break;

  case 147:
#line 392 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2703 "y.tab.c"
    break;

  case 148:
#line 395 "code.y"
                                                {(yyval.no) = extendTypeNode((yyvsp[-2].no),(yyvsp[0].string),typeTable,classTable);}
#line 2709 "y.tab.c"
    break;

  case 149:
#line 396 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2715 "y.tab.c"
    break;

  case 150:
#line 399 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[-3].no) -> varname,gst,lst,addArrayDim((yyvsp[-3].no) -> indices,(yyvsp[-1].no)),typeTable,classTable);}
#line 2721 "y.tab.c"
    break;

  case 151:
#line 400 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[0].string),gst,lst,NULL,typeTable,classTable);}
#line 2727 "y.tab.c"
    break;


#line 2731 "y.tab.c"

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
#line 403 "code.y"


void yyerror(char const *s)
{
    printf("yyerror: %s",s);
    exit(0);
}

FILE* openFile(){
	FILE *fp = fopen("output/output.out","w");
	fprintf(fp,"0\nGEN\n0\n0\n0\n0\n0\n0\n");
	return fp;
}

void startCodeGen(FILE* fp, int memLoc, struct GSymbolTable* gst, struct ClassTable* classTable){
	int label1 = getLabel();
	
	fprintf(fp,"GEN:\n");
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
		setMemLocationValues(gst,classTable,fp);
	fprintf(fp, "CALL MAIN\n");
	fprintf(fp,"CALL EXIT\n");

}

void endCodeGen(FILE *fp){
	fprintf(fp,"EXIT:\n");
	lib_code_gen(end,0,fp);
	fclose(fp);
}

void setMemLocationValues(struct GSymbolTable* gst,struct ClassTable* classTable, FILE* fp){
	reg_index reg1;
	int curr_mem = 0;
	struct Gsymbol* node = gst -> head;
	struct ArrayShape *shape;
	int index1,index2,temp,endFrame;
	
	struct ClassTableEntry* classEntry;
	struct MethodList* method;
	int func_num = 0;
	
	if(classTable != NULL){
		classEntry = classTable -> head;
		while(classEntry != NULL){
			method = classEntry -> methodList;
			func_num = 0;
			
			while(method != NULL){
				fprintf(fp,"MOV R1, %d\n",4096+func_num);
				fprintf(fp,"MOV [R1], F%d\n",method -> flabel);
				method = method -> next;
				++func_num;
			}
			while(func_num == 0 || func_num % 8 != 0){
				fprintf(fp,"MOV R1, %d\n",4096+func_num);
				fprintf(fp,"MOV [R1], -1\n");
				++func_num;
			}
			
			classEntry = classEntry -> next;
		}
	}
	
	while(node != NULL){ // loop through global symbol table
		shape = node -> shape;
		
		if(node -> dtype != NULL && node -> dtype -> nodetype == tupleType){
			fprintf(fp,"MOV R1, %d\n",node -> binding);
			fprintf(fp,"MOV [R1], %d\n", node -> binding + 1);
		}
		else if(node -> dtype != NULL && shape != NULL){
			
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
		}else if(node -> ctype != NULL){
			fprintf(fp,"MOV R1, %d\n",node -> binding + 1); //address of func ptr
			fprintf(fp,"MOV [R1], %d\n", 4096 + (node -> ctype -> classIndex * 8));
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
	classTable = ClassTableCreate();
	fp = openFile();
	yyparse();
	endCodeGen(fp);
	
	if(input_fp)
		fclose(input_fp);
	return 0;
}
