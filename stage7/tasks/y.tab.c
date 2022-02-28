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
    READ = 292,
    WRITE = 293,
    ALLOC = 294,
    INITIALIZE = 295,
    FREE = 296,
    NEW = 297,
    DELETE = 298,
    IF = 299,
    THEN = 300,
    ELSE = 301,
    ENDIF = 302,
    WHILE = 303,
    DO = 304,
    ENDWHILE = 305,
    REPEAT = 306,
    UNTIL = 307,
    BREAK = 308,
    CONTINUE = 309,
    RETURN = 310
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
#define READ 292
#define WRITE 293
#define ALLOC 294
#define INITIALIZE 295
#define FREE 296
#define NEW 297
#define DELETE 298
#define IF 299
#define THEN 300
#define ELSE 301
#define ENDIF 302
#define WHILE 303
#define DO 304
#define ENDWHILE 305
#define REPEAT 306
#define UNTIL 307
#define BREAK 308
#define CONTINUE 309
#define RETURN 310

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
	

#line 300 "y.tab.c"

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
#define YYLAST   852

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  361

#define YYUNDEFTOK  2
#define YYMAXUTOK   310


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
      59,    60,     2,     2,    58,     2,    63,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    95,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   107,   108,   111,   112,   115,   116,   119,   125,
     132,   133,   134,   137,   138,   141,   144,   145,   148,   149,
     152,   155,   158,   159,   162,   171,   180,   181,   184,   185,
     188,   191,   192,   195,   198,   199,   203,   209,   212,   213,
     216,   217,   218,   219,   220,   223,   226,   229,   230,   233,
     234,   237,   238,   241,   242,   245,   246,   249,   256,   264,
     265,   266,   267,   270,   271,   272,   275,   276,   279,   285,
     288,   293,   294,   295,   298,   299,   302,   305,   306,   307,
     310,   311,   315,   316,   322,   323,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   341,
     342,   345,   346,   347,   350,   353,   356,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   391,   392,   395,
     396,   397,   400,   401,   402,   405,   406
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "ID", "NUM", "STRING", "SELF",
  "STR", "INT", "VOID", "NULL_TYPE", "TUPLE", "PLUS", "MINUS", "STAR",
  "DIV", "MOD", "ASSIGN", "GT", "GTE", "LT", "LTE", "EQ", "NEQ", "ADDR",
  "AND", "OR", "START", "END", "ENDSTMT", "DECL", "ENDDECL", "TYPE",
  "ENDTYPE", "CLASS", "ENDCLASS", "READ", "WRITE", "ALLOC", "INITIALIZE",
  "FREE", "NEW", "DELETE", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "REPEAT", "UNTIL", "BREAK", "CONTINUE", "RETURN", "'{'",
  "'}'", "','", "'('", "')'", "'['", "']'", "'.'", "$accept", "program",
  "GclassBlock", "GclassList", "Gclass", "ClassName", "GclassDeclBlockSeg",
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
     305,   306,   307,   308,   309,   310,   123,   125,    44,    40,
      41,    91,    93,    46
};
# endif

#define YYPACT_NINF (-236)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     125,    25,   159,     6,    11,    29,    21,   130,   225,  -236,
       1,     5,  -236,  -236,  -236,  -236,    75,  -236,   284,    61,
    -236,  -236,    30,  -236,    22,  -236,  -236,  -236,    27,  -236,
      33,  -236,   225,    21,   225,  -236,  -236,  -236,    25,  -236,
     225,  -236,    43,    81,  -236,    71,    58,    60,  -236,  -236,
      68,    67,   -21,  -236,  -236,    98,   245,  -236,  -236,  -236,
    -236,    97,   225,  -236,   225,   225,  -236,  -236,  -236,    71,
     141,   122,   164,  -236,   245,   245,  -236,  -236,  -236,    61,
     199,    50,  -236,   207,   245,   113,  -236,  -236,   225,  -236,
    -236,   193,   245,  -236,  -236,  -236,  -236,   190,  -236,   105,
     376,   131,   -46,  -236,    89,  -236,   158,  -236,  -236,  -236,
      40,   407,  -236,   434,  -236,   221,  -236,   133,  -236,   175,
     228,  -236,   561,   106,  -236,  -236,  -236,   232,    42,  -236,
     180,   184,     9,   204,   213,   214,   236,   239,   561,   561,
     251,   254,   331,   403,  -236,  -236,  -236,  -236,  -236,  -236,
     287,   227,   247,  -236,   303,   245,  -236,  -236,  -236,  -236,
     305,  -236,  -236,   487,  -236,  -236,   306,   258,    66,   288,
    -236,  -236,    71,   262,   430,  -236,  -236,  -236,   105,   203,
     318,  -236,   264,   331,  -236,   265,  -236,   129,   331,   331,
     331,   587,   456,  -236,  -236,   270,  -236,  -236,   276,  -236,
     335,   129,   282,   289,   290,   291,   292,   331,   761,  -236,
     280,   296,  -236,   331,   343,   331,  -236,  -236,  -236,  -236,
     258,   245,  -236,   350,  -236,   329,   245,   307,  -236,   336,
     798,   114,   308,   361,   645,   364,   309,   660,   680,   695,
     316,   317,   260,   373,  -236,  -236,   321,   322,   129,   380,
     129,   710,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,  -236,   383,  -236,   780,   330,
     630,   135,  -236,   561,   143,  -236,  -236,   331,   358,   331,
    -236,  -236,  -236,   363,   368,   355,   357,   331,   331,  -236,
     192,   345,  -236,  -236,   349,   352,   362,  -236,   253,   253,
    -236,  -236,  -236,   828,   828,   828,   828,   828,   828,   813,
     813,   367,  -236,   272,  -236,  -236,   483,  -236,   798,  -236,
     200,  -236,  -236,   561,   561,   730,   745,  -236,   331,  -236,
    -236,  -236,   319,   378,   222,   366,   391,   348,   509,    39,
     398,   231,  -236,   246,  -236,   405,  -236,  -236,   561,   406,
     418,  -236,  -236,  -236,  -236,  -236,   535,  -236,  -236,   419,
    -236
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
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    99,   100,    96,    97,    98,
       0,   151,   154,    76,     0,     0,    55,    60,    63,    43,
       0,    22,    23,     0,    21,    28,     0,    27,     0,     0,
      16,    32,    83,     0,     0,    68,    93,    86,     0,     0,
       0,   156,     0,     0,   150,   151,    79,     0,     0,     0,
       0,     0,     0,   101,   102,   156,   131,   133,     0,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
     151,     0,    94,     0,     0,     0,    77,    73,    44,    20,
       0,    75,    25,     0,    30,     0,    75,     0,    90,     0,
     148,     0,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,    78,     0,   152,
       0,     0,    26,     0,     0,    67,   103,     0,     0,     0,
     153,   149,   152,     0,     0,     0,     0,     0,     0,   135,
       0,   153,   139,   141,     0,     0,     0,   130,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   152,   116,     0,   155,    31,     0,    35,   147,   104,
       0,   114,   115,     0,     0,     0,     0,   136,     0,   142,
     140,   143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   144,     0,   105,     0,    34,   107,     0,     0,
       0,   112,   113,   146,   145,   106,     0,   110,   111,     0,
     109
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -236,  -236,   426,  -236,   422,  -236,  -236,  -236,  -236,   342,
    -236,   344,  -102,  -236,  -236,   347,  -236,  -236,  -236,   437,
    -236,   381,  -236,    12,  -236,    -1,  -236,   447,  -236,   390,
     421,  -236,     2,   -35,  -236,  -236,   -69,   315,    41,  -236,
     -61,  -236,   379,  -236,  -236,   295,  -118,  -141,  -236,  -236,
    -236,  -236,  -236,   -75,  -235,  -100,   -97,  -236
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    28,    29,    30,    85,    86,   111,   112,
     168,   113,   114,   169,   117,   118,   119,     7,    24,    25,
      81,    82,   110,     8,    18,   101,    20,    21,    52,    53,
      54,    55,    40,    41,    42,    43,   102,   103,     9,    10,
      72,    97,    98,    99,   128,   129,   143,   144,   145,   146,
     147,   148,   149,   230,   231,   209,   210,   152
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     150,    19,   212,   151,   174,    67,   104,   290,    91,    78,
      22,   165,   155,   181,   156,    26,   182,    19,    32,    34,
     191,   192,   150,   123,   132,   151,    22,    67,    11,    31,
      67,    26,   184,   212,    62,   185,    65,    79,   150,   150,
      23,   151,   151,   150,   320,    64,   151,    27,    35,    44,
     212,   212,     2,    67,    12,    83,    57,    45,    13,    14,
      15,   165,    16,    59,    46,    50,    88,   208,   183,   351,
     159,    76,   177,    63,   150,    66,    51,   151,   334,    47,
      83,    68,    51,   115,   120,    70,    56,   236,   324,    61,
     185,   150,   150,   341,   151,   151,   222,   343,   160,    69,
     178,   245,    71,    87,   185,    89,    90,   107,   234,   126,
     115,   225,   166,   237,   238,   239,   120,    12,    73,    74,
     127,    13,    14,    15,   223,    16,    93,    75,    84,   121,
      94,    95,   251,   181,     1,   153,   182,    12,   268,     1,
     270,    13,    14,    15,   132,    16,   154,   155,   294,   157,
     296,   185,   271,   185,    96,   316,     2,   274,     3,    80,
       4,     2,   166,    12,   155,     4,   175,    13,    14,    15,
     116,    16,   277,   150,   278,   212,   151,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     170,    17,   100,   155,    93,   315,   212,   212,    94,    95,
      92,   155,   318,   317,   106,   337,   338,   195,   196,   197,
     198,   109,   325,   326,   199,   212,   150,   200,   132,   151,
     158,   122,   124,   150,   150,   167,   151,   151,   201,    36,
     356,   172,   173,    37,    38,    39,   176,   150,   150,   179,
     151,   151,   202,   203,   204,   205,   206,   180,   150,    12,
     277,   151,   327,    13,    14,    15,   150,    16,   277,   151,
     336,   186,   207,   229,   195,   196,   197,   198,   254,   255,
     256,   199,   187,   188,   200,   132,   195,   196,   197,   198,
     277,   193,   345,   199,   194,   201,   200,   132,    12,   277,
     214,   353,    13,    14,    15,   189,    16,   201,   190,   202,
     203,   204,   205,   206,   277,   213,   354,   216,   215,   218,
     220,   202,   203,   204,   205,   206,    48,   221,   224,   207,
     289,   226,   232,   195,   196,   197,   198,   233,   235,   242,
     199,   207,   333,   200,   132,   195,   196,   197,   198,   243,
     244,   246,   199,   266,   201,   200,   132,   269,   247,   248,
     249,   250,   130,   267,   272,   131,   201,   273,   202,   203,
     204,   205,   206,   132,   275,   280,   276,   279,   282,   283,
     202,   203,   204,   205,   206,   287,   288,   291,   207,   342,
     130,   292,   293,   131,   295,   134,   135,   311,   319,   313,
     207,   132,   136,   321,   348,   349,   137,   138,   322,   139,
     323,   140,   141,   142,   328,   133,   324,   130,   344,   329,
     131,    12,   330,   134,   135,    13,    14,    15,   132,    16,
     136,   347,   331,   346,   137,   138,   332,   139,   352,   140,
     141,   142,   211,    33,   130,   355,   357,   131,    12,   161,
     134,   135,    13,    14,    15,   132,    16,   136,   358,   360,
      60,   137,   138,   162,   139,   163,   140,   141,   142,   227,
     130,    58,   108,   131,   171,    49,   164,   134,   135,   105,
     217,   132,    77,   228,   136,     0,   125,     0,   137,   138,
       0,   139,     0,   140,   141,   142,     0,   130,     0,     0,
     131,    12,     0,   134,   135,    13,    14,    15,   132,    16,
     136,     0,     0,     0,   137,   138,     0,   139,   241,   140,
     141,   142,   335,   130,     0,     0,   131,     0,     0,   219,
     134,   135,     0,     0,   132,     0,     0,   136,     0,     0,
       0,   137,   138,     0,   139,     0,   140,   141,   142,   130,
       0,     0,   131,     0,     0,     0,   134,   135,     0,     0,
     132,     0,     0,   136,     0,     0,     0,   137,   138,   350,
     139,     0,   140,   141,   142,   130,     0,     0,   131,     0,
       0,     0,   134,   135,     0,     0,   132,     0,     0,   136,
       0,     0,   359,   137,   138,     0,   139,     0,   140,   141,
     142,   130,     0,     0,   131,     0,     0,     0,   134,   135,
       0,     0,   132,     0,     0,   136,     0,     0,     0,   137,
     138,     0,   139,     0,   140,   141,   142,     0,     0,     0,
       0,     0,     0,     0,   134,   135,     0,     0,     0,     0,
       0,   136,     0,     0,     0,   240,   138,     0,   139,     0,
     140,   141,   142,   252,   253,   254,   255,   256,     0,   257,
     258,   259,   260,   261,   262,     0,   263,   264,   252,   253,
     254,   255,   256,     0,   257,   258,   259,   260,   261,   262,
       0,   263,   264,   252,   253,   254,   255,   256,     0,   257,
     258,   259,   260,   261,   262,     0,   263,   264,     0,     0,
       0,     0,   314,   252,   253,   254,   255,   256,     0,   257,
     258,   259,   260,   261,   262,   281,   263,   264,   252,   253,
     254,   255,   256,     0,   257,   258,   259,   260,   261,   262,
     284,   263,   264,   252,   253,   254,   255,   256,     0,   257,
     258,   259,   260,   261,   262,     0,   263,   264,     0,     0,
     285,     0,     0,   252,   253,   254,   255,   256,     0,   257,
     258,   259,   260,   261,   262,   286,   263,   264,   252,   253,
     254,   255,   256,     0,   257,   258,   259,   260,   261,   262,
     297,   263,   264,     0,   252,   253,   254,   255,   256,     0,
     257,   258,   259,   260,   261,   262,     0,   263,   264,     0,
     339,   265,     0,   252,   253,   254,   255,   256,     0,   257,
     258,   259,   260,   261,   262,   340,   263,   264,     0,     0,
     312,   252,   253,   254,   255,   256,     0,   257,   258,   259,
     260,   261,   262,     0,   263,   264,   252,   253,   254,   255,
     256,     0,   257,   258,   259,   260,   261,   262,     0,    -1,
      -1,   252,   253,   254,   255,   256,     0,    -1,    -1,    -1,
      -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
     100,     2,   143,   100,   122,    40,    75,   242,    69,    30,
       4,   113,    58,     4,    60,     4,     7,    18,     6,     7,
     138,   139,   122,    92,    15,   122,     4,    62,     3,     0,
      65,     4,   132,   174,    32,   132,    34,    58,   138,   139,
      34,   138,   139,   143,   279,    33,   143,    36,     7,     8,
     191,   192,    31,    88,     4,    56,    34,    56,     8,     9,
      10,   163,    12,    36,    59,     4,    64,   142,    59,    30,
      30,     4,    30,    32,   174,    34,    15,   174,   313,     4,
      81,    40,    15,    84,    85,     4,    56,   187,    49,    56,
     187,   191,   192,   328,   191,   192,    30,   332,    58,    56,
      58,   201,    31,    62,   201,    64,    65,    57,   183,     4,
     111,   172,   113,   188,   189,   190,   117,     4,    60,    59,
      15,     8,     9,    10,    58,    12,     4,    59,    31,    88,
       8,     9,   207,     4,     9,     4,     7,     4,   213,     9,
     215,     8,     9,    10,    15,    12,    15,    58,   248,    60,
     250,   248,   221,   250,    32,   273,    31,   226,    33,    61,
      35,    31,   163,     4,    58,    35,    60,     8,     9,    10,
      57,    12,    58,   273,    60,   316,   273,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      57,    32,    28,    58,     4,    60,   337,   338,     8,     9,
      59,    58,   277,    60,     5,   323,   324,     4,     5,     6,
       7,     4,   287,   288,    11,   356,   316,    14,    15,   316,
      62,    28,    32,   323,   324,     4,   323,   324,    25,     4,
     348,    56,     4,     8,     9,    10,     4,   337,   338,    59,
     337,   338,    39,    40,    41,    42,    43,    63,   348,     4,
      58,   348,    60,     8,     9,    10,   356,    12,    58,   356,
      60,    57,    59,    60,     4,     5,     6,     7,    15,    16,
      17,    11,    59,    59,    14,    15,     4,     5,     6,     7,
      58,    30,    60,    11,    30,    25,    14,    15,     4,    58,
      63,    60,     8,     9,    10,    59,    12,    25,    59,    39,
      40,    41,    42,    43,    58,    18,    60,     4,    61,     4,
       4,    39,    40,    41,    42,    43,    32,    59,    30,    59,
      60,    59,     4,     4,     5,     6,     7,    63,    63,    59,
      11,    59,    60,    14,    15,     4,     5,     6,     7,    63,
       5,    59,    11,    63,    25,    14,    15,     4,    59,    59,
      59,    59,     4,    57,     4,     7,    25,    28,    39,    40,
      41,    42,    43,    15,    57,     4,    30,    59,     4,    60,
      39,    40,    41,    42,    43,    59,    59,     4,    59,    60,
       4,    60,    60,     7,     4,    37,    38,     4,    30,    59,
      59,    15,    44,    30,    46,    47,    48,    49,    30,    51,
      45,    53,    54,    55,    59,    29,    49,     4,    30,    60,
       7,     4,    60,    37,    38,     8,     9,    10,    15,    12,
      44,    30,    60,    57,    48,    49,    59,    51,    30,    53,
      54,    55,    29,     7,     4,    30,    30,     7,     4,    32,
      37,    38,     8,     9,    10,    15,    12,    44,    30,    30,
      28,    48,    49,   111,    51,   111,    53,    54,    55,    29,
       4,    24,    81,     7,   117,    18,    32,    37,    38,    79,
     155,    15,    51,   178,    44,    -1,    97,    -1,    48,    49,
      -1,    51,    -1,    53,    54,    55,    -1,     4,    -1,    -1,
       7,     4,    -1,    37,    38,     8,     9,    10,    15,    12,
      44,    -1,    -1,    -1,    48,    49,    -1,    51,    52,    53,
      54,    55,    29,     4,    -1,    -1,     7,    -1,    -1,    32,
      37,    38,    -1,    -1,    15,    -1,    -1,    44,    -1,    -1,
      -1,    48,    49,    -1,    51,    -1,    53,    54,    55,     4,
      -1,    -1,     7,    -1,    -1,    -1,    37,    38,    -1,    -1,
      15,    -1,    -1,    44,    -1,    -1,    -1,    48,    49,    50,
      51,    -1,    53,    54,    55,     4,    -1,    -1,     7,    -1,
      -1,    -1,    37,    38,    -1,    -1,    15,    -1,    -1,    44,
      -1,    -1,    47,    48,    49,    -1,    51,    -1,    53,    54,
      55,     4,    -1,    -1,     7,    -1,    -1,    -1,    37,    38,
      -1,    -1,    15,    -1,    -1,    44,    -1,    -1,    -1,    48,
      49,    -1,    51,    -1,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,
      53,    54,    55,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      -1,    -1,    62,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    60,    26,    27,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      60,    26,    27,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    -1,    -1,
      60,    -1,    -1,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    60,    26,    27,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    24,
      60,    26,    27,    -1,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    -1,
      60,    30,    -1,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    60,    26,    27,    -1,    -1,
      30,    13,    14,    15,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    13,    14,    15,    16,    17,    -1,    19,    20,    21,
      22,    23,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    31,    33,    35,    65,    66,    81,    87,   102,
     103,     3,     4,     8,     9,    10,    12,    32,    88,    89,
      90,    91,     4,    34,    82,    83,     4,    36,    67,    68,
      69,     0,    87,    66,    87,   102,     4,     8,     9,    10,
      96,    97,    98,    99,   102,    56,    59,     4,    32,    91,
       4,    15,    92,    93,    94,    95,    56,    34,    83,    36,
      68,    56,    96,   102,    87,    96,   102,    97,   102,    56,
       4,    31,   104,    60,    59,    59,     4,    94,    30,    58,
      61,    84,    85,    89,    31,    70,    71,   102,    96,   102,
     102,   104,    59,     4,     8,     9,    32,   105,   106,   107,
      28,    89,   100,   101,   100,    93,     5,    57,    85,     4,
      86,    72,    73,    75,    76,    89,    57,    78,    79,    80,
      89,   102,    28,   100,    32,   106,     4,    15,   108,   109,
       4,     7,    15,    29,    37,    38,    44,    48,    49,    51,
      53,    54,    55,   110,   111,   112,   113,   114,   115,   116,
     119,   120,   121,     4,    15,    58,    60,    60,    62,    30,
      58,    32,    73,    75,    32,    76,    89,     4,    74,    77,
      57,    79,    56,     4,   110,    60,     4,    30,    58,    59,
      63,     4,     7,    59,   119,   120,    57,    59,    59,    59,
      59,   110,   110,    30,    30,     4,     5,     6,     7,    11,
      14,    25,    39,    40,    41,    42,    43,    59,   117,   119,
     120,    29,   111,    18,    63,    61,     4,   101,     4,    32,
       4,    59,    30,    58,    30,   104,    59,    29,   109,    60,
     117,   118,     4,    63,   117,    63,   119,   117,   117,   117,
      48,    52,    59,    63,     5,   119,    59,    59,    59,    59,
      59,   117,    13,    14,    15,    16,    17,    19,    20,    21,
      22,    23,    24,    26,    27,    30,    63,    57,   117,     4,
     117,   100,     4,    28,   100,    57,    30,    58,    60,    59,
       4,    60,     4,    60,    60,    60,    60,    59,    59,    60,
     118,     4,    60,    60,   119,     4,   119,    60,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,     4,    30,    59,    62,    60,   110,    60,   117,    30,
     118,    30,    30,    45,    49,   117,   117,    60,    59,    60,
      60,    60,    59,    60,   118,    29,    60,   110,   110,    60,
      60,   118,    60,   118,    30,    60,    57,    30,    46,    47,
      50,    30,    30,    60,    60,    30,   110,    30,    30,    47,
      30
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    70,
      71,    71,    71,    72,    72,    73,    74,    74,    75,    75,
      76,    77,    78,    78,    79,    80,    81,    81,    82,    82,
      83,    84,    84,    85,    86,    86,    87,    87,    88,    88,
      89,    89,    89,    89,    89,    90,    91,    92,    92,    93,
      93,    94,    94,    95,    95,    96,    96,    97,    98,    99,
      99,    99,    99,   100,   100,   100,   101,   101,   102,   102,
     103,   104,   104,   104,   105,   105,   106,   107,   107,   107,
     108,   108,   109,   109,   110,   110,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   112,
     112,   113,   113,   113,   114,   115,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   118,   118,   119,
     119,   119,   120,   120,   120,   121,   121
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
       1,     2,     2,     4,     5,     6,     7,     7,     3,    10,
       8,     8,     7,     7,     5,     5,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     1,     1,     3,     4,     1,     2,     3,
       4,     3,     4,     4,     5,     6,     6,     3,     1,     4,
       2,     1,     3,     3,     1,     4,     1
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
#line 1824 "y.tab.c"
    break;

  case 3:
#line 96 "code.y"
                                                                        {}
#line 1830 "y.tab.c"
    break;

  case 4:
#line 97 "code.y"
                                                                        {}
#line 1836 "y.tab.c"
    break;

  case 5:
#line 98 "code.y"
                                                                        {}
#line 1842 "y.tab.c"
    break;

  case 6:
#line 99 "code.y"
                                                                        {}
#line 1848 "y.tab.c"
    break;

  case 7:
#line 100 "code.y"
                                                                        {}
#line 1854 "y.tab.c"
    break;

  case 8:
#line 101 "code.y"
                                                                        {}
#line 1860 "y.tab.c"
    break;

  case 9:
#line 102 "code.y"
                                                                        {}
#line 1866 "y.tab.c"
    break;

  case 10:
#line 103 "code.y"
                                                                        {}
#line 1872 "y.tab.c"
    break;

  case 11:
#line 104 "code.y"
                                                                        {}
#line 1878 "y.tab.c"
    break;

  case 12:
#line 107 "code.y"
                                                        {/*printClassTable(classTable);printf("CLASS DONE\n");*/}
#line 1884 "y.tab.c"
    break;

  case 13:
#line 108 "code.y"
                                                                {}
#line 1890 "y.tab.c"
    break;

  case 14:
#line 111 "code.y"
                                                        {}
#line 1896 "y.tab.c"
    break;

  case 15:
#line 112 "code.y"
                                                                {}
#line 1902 "y.tab.c"
    break;

  case 16:
#line 115 "code.y"
                                                                                {}
#line 1908 "y.tab.c"
    break;

  case 17:
#line 116 "code.y"
                                                                        {}
#line 1914 "y.tab.c"
    break;

  case 18:
#line 119 "code.y"
                                                                                {
											currentClass = strdup((yyvsp[0].string));
											(yyval.string) = (yyvsp[0].string);
										}
#line 1923 "y.tab.c"
    break;

  case 19:
#line 125 "code.y"
                                                                                {	
											getMemLoc(8);
											addToClassTable(classTable, typeTable, (yyvsp[0].dno), currentClass);

										}
#line 1933 "y.tab.c"
    break;

  case 20:
#line 132 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[-1].dno));}
#line 1939 "y.tab.c"
    break;

  case 21:
#line 133 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode(NULL,(yyvsp[-1].dno));}
#line 1945 "y.tab.c"
    break;

  case 22:
#line 134 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),NULL);}
#line 1951 "y.tab.c"
    break;

  case 23:
#line 137 "code.y"
                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1957 "y.tab.c"
    break;

  case 24:
#line 138 "code.y"
                                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1963 "y.tab.c"
    break;

  case 25:
#line 141 "code.y"
                                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 1969 "y.tab.c"
    break;

  case 26:
#line 144 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),declIdNode((yyvsp[-2].string),0,NULL));}
#line 1975 "y.tab.c"
    break;

  case 27:
#line 145 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 1981 "y.tab.c"
    break;

  case 28:
#line 148 "code.y"
                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1987 "y.tab.c"
    break;

  case 29:
#line 149 "code.y"
                                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1993 "y.tab.c"
    break;

  case 30:
#line 152 "code.y"
                                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 1999 "y.tab.c"
    break;

  case 31:
#line 155 "code.y"
                                                                {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 2005 "y.tab.c"
    break;

  case 32:
#line 158 "code.y"
                                                                {}
#line 2011 "y.tab.c"
    break;

  case 33:
#line 159 "code.y"
                                                                {}
#line 2017 "y.tab.c"
    break;

  case 34:
#line 162 "code.y"
                                                                        {	
										
										struct ClassTableEntry* entry = CLookup(classTable,currentClass);
										struct MethodList* method = MLookup(entry -> methodList,(yyvsp[-6].string));
										funcCodeGen((yyvsp[-2].no), fp,method -> flabel);
										lst = NULL;
									}
#line 2029 "y.tab.c"
    break;

  case 35:
#line 171 "code.y"
                                                        {	
								localMemLoc = 0;
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyMethodHead((yyvsp[-3].string),(yyvsp[-1].pt),TLookup(typeTable,(yyvsp[-4].string)),CLookup(classTable,currentClass));
								addMethodParamToLST(lst,(yyvsp[-1].pt),CLookup(classTable,currentClass));
								(yyval.string) = (yyvsp[-3].string);
							}
#line 2041 "y.tab.c"
    break;

  case 36:
#line 180 "code.y"
                                                        {/*printf("TYPE DONE\n");*/}
#line 2047 "y.tab.c"
    break;

  case 37:
#line 181 "code.y"
                                                        {}
#line 2053 "y.tab.c"
    break;

  case 38:
#line 184 "code.y"
                                                        {}
#line 2059 "y.tab.c"
    break;

  case 39:
#line 185 "code.y"
                                                {}
#line 2065 "y.tab.c"
    break;

  case 40:
#line 188 "code.y"
                                                        {addUserDefToTypeTable(typeTable,(yyvsp[-1].dno),(yyvsp[-3].string));}
#line 2071 "y.tab.c"
    break;

  case 41:
#line 191 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2077 "y.tab.c"
    break;

  case 42:
#line 192 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2083 "y.tab.c"
    break;

  case 43:
#line 195 "code.y"
                                                        {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2089 "y.tab.c"
    break;

  case 44:
#line 198 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),declIdNode((yyvsp[-2].string),0,NULL));}
#line 2095 "y.tab.c"
    break;

  case 45:
#line 199 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2101 "y.tab.c"
    break;

  case 46:
#line 203 "code.y"
                                        {	
						gst = (struct GSymbolTable*)malloc(sizeof(struct GSymbolTable));
						generateGlobalSymbolTable(gst,(yyvsp[-1].dno),NULL,NULL,typeTable,classTable);
						startCodeGen(fp,memLoc,gst,classTable);
						//printGlobalSymbolTable(gst);
					}
#line 2112 "y.tab.c"
    break;

  case 47:
#line 209 "code.y"
                                        {gst = NULL;}
#line 2118 "y.tab.c"
    break;

  case 48:
#line 212 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2124 "y.tab.c"
    break;

  case 49:
#line 213 "code.y"
                                {(yyval.dno) = (yyvsp[0].dno);}
#line 2130 "y.tab.c"
    break;

  case 50:
#line 216 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2136 "y.tab.c"
    break;

  case 51:
#line 217 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2142 "y.tab.c"
    break;

  case 52:
#line 218 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2148 "y.tab.c"
    break;

  case 53:
#line 219 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2154 "y.tab.c"
    break;

  case 54:
#line 220 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2160 "y.tab.c"
    break;

  case 55:
#line 223 "code.y"
                                        {addTupleToTypeTable(typeTable,(yyvsp[-1].pt),(yyvsp[-3].string));(yyval.string) = (yyvsp[-3].string);}
#line 2166 "y.tab.c"
    break;

  case 56:
#line 226 "code.y"
                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2172 "y.tab.c"
    break;

  case 57:
#line 229 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 2178 "y.tab.c"
    break;

  case 58:
#line 230 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2184 "y.tab.c"
    break;

  case 59:
#line 233 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2190 "y.tab.c"
    break;

  case 60:
#line 234 "code.y"
                                                        {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 2196 "y.tab.c"
    break;

  case 61:
#line 237 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].dno) -> varname,(yyvsp[0].dno) -> dim + 1,(yyvsp[0].dno) -> shape);}
#line 2202 "y.tab.c"
    break;

  case 62:
#line 238 "code.y"
                                                {(yyval.dno) = (yyvsp[0].dno);}
#line 2208 "y.tab.c"
    break;

  case 63:
#line 241 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[-3].dno) -> varname,(yyvsp[-3].dno) -> dim + 1,addArrayShape((yyvsp[-3].dno) -> shape,(yyvsp[-1].number)));}
#line 2214 "y.tab.c"
    break;

  case 64:
#line 242 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2220 "y.tab.c"
    break;

  case 65:
#line 245 "code.y"
                                                        {}
#line 2226 "y.tab.c"
    break;

  case 66:
#line 246 "code.y"
                                                        {}
#line 2232 "y.tab.c"
    break;

  case 67:
#line 249 "code.y"
                                                        {	
									struct Gsymbol* g = GlobalLookup(gst,(yyvsp[-6].string));
									funcCodeGen((yyvsp[-2].no), fp,g -> flabel);
									lst = NULL;
								}
#line 2242 "y.tab.c"
    break;

  case 68:
#line 256 "code.y"
                                                                {
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyFuncHead(gst,(yyvsp[-3].string),TLookup(typeTable,(yyvsp[-4].string)),CLookup(classTable,(yyvsp[-4].string)),(yyvsp[-1].pt));
								addParamToLST(lst,(yyvsp[-1].pt));
								(yyval.string) = (yyvsp[-3].string);
							}
#line 2253 "y.tab.c"
    break;

  case 69:
#line 264 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2259 "y.tab.c"
    break;

  case 70:
#line 265 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2265 "y.tab.c"
    break;

  case 71:
#line 266 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2271 "y.tab.c"
    break;

  case 72:
#line 267 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2277 "y.tab.c"
    break;

  case 73:
#line 270 "code.y"
                                                {(yyval.pt) = addParameter((yyvsp[-2].pt),(yyvsp[0].pt));}
#line 2283 "y.tab.c"
    break;

  case 74:
#line 271 "code.y"
                                                {(yyval.pt) = (yyvsp[0].pt);}
#line 2289 "y.tab.c"
    break;

  case 75:
#line 272 "code.y"
                                                        {(yyval.pt) = NULL;}
#line 2295 "y.tab.c"
    break;

  case 76:
#line 275 "code.y"
                                                {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-1].string),0,typeTable,classTable);}
#line 2301 "y.tab.c"
    break;

  case 77:
#line 276 "code.y"
                                                        {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-2].string),1,typeTable,classTable);}
#line 2307 "y.tab.c"
    break;

  case 78:
#line 279 "code.y"
                                                                {	
									if(gst == NULL){
										startCodeGen(fp,-1,gst,classTable);	
										fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
									}
									funcCodeGen((yyvsp[-2].no), fp,-1);}
#line 2318 "y.tab.c"
    break;

  case 79:
#line 285 "code.y"
                                                                {exit(0);}
#line 2324 "y.tab.c"
    break;

  case 80:
#line 288 "code.y"
                                {lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));}
#line 2330 "y.tab.c"
    break;

  case 81:
#line 293 "code.y"
                                        {localMemLoc = 0; addLocalVarToLST(lst,(yyvsp[-1].dno),NULL,NULL,typeTable,classTable);}
#line 2336 "y.tab.c"
    break;

  case 82:
#line 294 "code.y"
                                        {(yyval.dno) = NULL;}
#line 2342 "y.tab.c"
    break;

  case 83:
#line 295 "code.y"
                                        {(yyval.dno) = NULL;}
#line 2348 "y.tab.c"
    break;

  case 84:
#line 298 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2354 "y.tab.c"
    break;

  case 85:
#line 299 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2360 "y.tab.c"
    break;

  case 86:
#line 302 "code.y"
                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2366 "y.tab.c"
    break;

  case 87:
#line 305 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2372 "y.tab.c"
    break;

  case 88:
#line 306 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2378 "y.tab.c"
    break;

  case 89:
#line 307 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2384 "y.tab.c"
    break;

  case 90:
#line 310 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 2390 "y.tab.c"
    break;

  case 91:
#line 311 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2396 "y.tab.c"
    break;

  case 92:
#line 315 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2402 "y.tab.c"
    break;

  case 93:
#line 316 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),1,NULL);}
#line 2408 "y.tab.c"
    break;

  case 94:
#line 322 "code.y"
                                                                        {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 2414 "y.tab.c"
    break;

  case 95:
#line 323 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2420 "y.tab.c"
    break;

  case 96:
#line 326 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2426 "y.tab.c"
    break;

  case 97:
#line 327 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2432 "y.tab.c"
    break;

  case 98:
#line 328 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2438 "y.tab.c"
    break;

  case 99:
#line 329 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2444 "y.tab.c"
    break;

  case 100:
#line 330 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2450 "y.tab.c"
    break;

  case 101:
#line 331 "code.y"
                                                                {(yyval.no) = makeJumpNode(break_node);}
#line 2456 "y.tab.c"
    break;

  case 102:
#line 332 "code.y"
                                                                        {(yyval.no) = makeJumpNode(continue_node);}
#line 2462 "y.tab.c"
    break;

  case 103:
#line 333 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,NULL);}
#line 2468 "y.tab.c"
    break;

  case 104:
#line 334 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-4].string),gst,(yyvsp[-2].at));}
#line 2474 "y.tab.c"
    break;

  case 105:
#line 335 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-5].no),(yyvsp[-3].string),NULL,typeTable);}
#line 2480 "y.tab.c"
    break;

  case 106:
#line 336 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-6].no),(yyvsp[-4].string),(yyvsp[-2].at),typeTable);}
#line 2486 "y.tab.c"
    break;

  case 107:
#line 337 "code.y"
                                                                        {(yyval.no) = makeMethodNode(makeIdNode((yyvsp[-6].string),gst,lst,NULL,typeTable,classTable),(yyvsp[-4].string),(yyvsp[-2].at),typeTable);}
#line 2492 "y.tab.c"
    break;

  case 108:
#line 338 "code.y"
                                                                        {(yyval.no) = makeReturnNode((yyvsp[-1].no));}
#line 2498 "y.tab.c"
    break;

  case 109:
#line 341 "code.y"
                                                                {(yyval.no) = makeIfElseBlock((yyvsp[-7].no),(yyvsp[-4].no),(yyvsp[-2].no));}
#line 2504 "y.tab.c"
    break;

  case 110:
#line 342 "code.y"
                                                                        {(yyval.no) = makeIfElseBlock((yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 2510 "y.tab.c"
    break;

  case 111:
#line 345 "code.y"
                                                                {(yyval.no) = makeWhileBlock((yyvsp[-5].no),(yyvsp[-2].no));}
#line 2516 "y.tab.c"
    break;

  case 112:
#line 346 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 2522 "y.tab.c"
    break;

  case 113:
#line 347 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 2528 "y.tab.c"
    break;

  case 114:
#line 350 "code.y"
                                                                        {(yyval.no) = makeReadNode((yyvsp[-2].no));}
#line 2534 "y.tab.c"
    break;

  case 115:
#line 353 "code.y"
                                                                {(yyval.no) = makeWriteNode((yyvsp[-2].no));}
#line 2540 "y.tab.c"
    break;

  case 116:
#line 356 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(assign,(yyvsp[-3].no),(yyvsp[-1].no),typeTable);}
#line 2546 "y.tab.c"
    break;

  case 117:
#line 359 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(add,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2552 "y.tab.c"
    break;

  case 118:
#line 360 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(sub,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2558 "y.tab.c"
    break;

  case 119:
#line 361 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(mul,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2564 "y.tab.c"
    break;

  case 120:
#line 362 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(div,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2570 "y.tab.c"
    break;

  case 121:
#line 363 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(mod,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2576 "y.tab.c"
    break;

  case 122:
#line 364 "code.y"
                                                                {(yyval.no) = makeOperatorNode(gt,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2582 "y.tab.c"
    break;

  case 123:
#line 365 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(gte,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2588 "y.tab.c"
    break;

  case 124:
#line 366 "code.y"
                                                                {(yyval.no) = makeOperatorNode(lt,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2594 "y.tab.c"
    break;

  case 125:
#line 367 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(lte,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2600 "y.tab.c"
    break;

  case 126:
#line 368 "code.y"
                                                                {(yyval.no) = makeOperatorNode(eq,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2606 "y.tab.c"
    break;

  case 127:
#line 369 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(neq,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2612 "y.tab.c"
    break;

  case 128:
#line 370 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(and,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2618 "y.tab.c"
    break;

  case 129:
#line 371 "code.y"
                                                                {(yyval.no) = makeOperatorNode(or,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2624 "y.tab.c"
    break;

  case 130:
#line 372 "code.y"
                                                                {(yyval.no) = (yyvsp[-1].no);}
#line 2630 "y.tab.c"
    break;

  case 131:
#line 373 "code.y"
                                                                        {(yyval.no) = makeNumNode((yyvsp[0].number),0,typeTable);}
#line 2636 "y.tab.c"
    break;

  case 132:
#line 374 "code.y"
                                                                        {(yyval.no) = makeNumNode(-1 * (yyvsp[0].number),0,typeTable);}
#line 2642 "y.tab.c"
    break;

  case 133:
#line 375 "code.y"
                                                                        {(yyval.no) = makeStringNode((yyvsp[0].string),typeTable);}
#line 2648 "y.tab.c"
    break;

  case 134:
#line 376 "code.y"
                                                                        {(yyval.no) = makeNullNode(typeTable);}
#line 2654 "y.tab.c"
    break;

  case 135:
#line 377 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-2].string),gst,NULL);}
#line 2660 "y.tab.c"
    break;

  case 136:
#line 378 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,(yyvsp[-1].at));}
#line 2666 "y.tab.c"
    break;

  case 137:
#line 379 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2672 "y.tab.c"
    break;

  case 138:
#line 380 "code.y"
                                                                        {(yyval.no) = makeAddrNode((yyvsp[0].no),gst,lst,typeTable);}
#line 2678 "y.tab.c"
    break;

  case 139:
#line 381 "code.y"
                                                                        {(yyval.no) = makeTypeAllocNode();}
#line 2684 "y.tab.c"
    break;

  case 140:
#line 382 "code.y"
                                                                        {(yyval.no) = makeClassAllocNode((yyvsp[-1].string),classTable);}
#line 2690 "y.tab.c"
    break;

  case 141:
#line 383 "code.y"
                                                                        {(yyval.no) = makeMemInitNode(typeTable);}
#line 2696 "y.tab.c"
    break;

  case 142:
#line 384 "code.y"
                                                                        {(yyval.no) = makeFreeNode((yyvsp[-1].no),typeTable);}
#line 2702 "y.tab.c"
    break;

  case 143:
#line 385 "code.y"
                                                                        {(yyval.no) = makeDeleteNode((yyvsp[-1].no),typeTable);}
#line 2708 "y.tab.c"
    break;

  case 144:
#line 386 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-4].no),(yyvsp[-2].string),NULL,typeTable);}
#line 2714 "y.tab.c"
    break;

  case 145:
#line 387 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-5].no),(yyvsp[-3].string),(yyvsp[-1].at),typeTable);}
#line 2720 "y.tab.c"
    break;

  case 146:
#line 388 "code.y"
                                                                {(yyval.no) = makeMethodNode(makeIdNode((yyvsp[-5].string),gst,lst,NULL,typeTable,classTable),(yyvsp[-3].string),(yyvsp[-1].at),typeTable);}
#line 2726 "y.tab.c"
    break;

  case 147:
#line 391 "code.y"
                                        {(yyval.at) = addArguments((yyvsp[-2].at),makeArgStruct((yyvsp[0].no)),typeTable);}
#line 2732 "y.tab.c"
    break;

  case 148:
#line 392 "code.y"
                                        {(yyval.at) = makeArgStruct((yyvsp[0].no));}
#line 2738 "y.tab.c"
    break;

  case 149:
#line 395 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[-1].no),typeTable);}
#line 2744 "y.tab.c"
    break;

  case 150:
#line 396 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[0].no),typeTable);}
#line 2750 "y.tab.c"
    break;

  case 151:
#line 397 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2756 "y.tab.c"
    break;

  case 152:
#line 400 "code.y"
                                                {(yyval.no) = extendTypeNode((yyvsp[-2].no),(yyvsp[0].string),typeTable);}
#line 2762 "y.tab.c"
    break;

  case 153:
#line 401 "code.y"
                                                {(yyval.no) = extendClassNode(makeIdNode((yyvsp[-2].string),gst,lst,NULL,typeTable,classTable),(yyvsp[0].string),classTable);}
#line 2768 "y.tab.c"
    break;

  case 154:
#line 402 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2774 "y.tab.c"
    break;

  case 155:
#line 405 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[-3].no) -> varname,gst,lst,addArrayDim((yyvsp[-3].no) -> indices,(yyvsp[-1].no)),typeTable,classTable);}
#line 2780 "y.tab.c"
    break;

  case 156:
#line 406 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[0].string),gst,lst,NULL,typeTable,classTable);}
#line 2786 "y.tab.c"
    break;


#line 2790 "y.tab.c"

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
#line 409 "code.y"


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
				fprintf(fp,"MOV R1, %d\n",4096 + (classEntry -> classIndex * 8) +func_num);
				fprintf(fp,"MOV [R1], F%d\n",method -> flabel);
				method = method -> next;
				++func_num;
			}
			while(func_num == 0 || func_num % 8 != 0){
				fprintf(fp,"MOV R1, %d\n",4096+ (classEntry -> classIndex * 8) + func_num);
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
		}
/*		else if(node -> ctype != NULL){
			fprintf(fp,"MOV R1, %d\n",node -> binding + 1); //address of func ptr
			fprintf(fp,"MOV [R1], %d\n", 4096 + (node -> ctype -> classIndex * 8));
		} */
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
