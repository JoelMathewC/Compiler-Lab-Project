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
    NEW = 296,
    IF = 297,
    THEN = 298,
    ELSE = 299,
    ENDIF = 300,
    WHILE = 301,
    DO = 302,
    ENDWHILE = 303,
    REPEAT = 304,
    UNTIL = 305,
    BREAK = 306,
    CONTINUE = 307,
    RETURN = 308
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
#define NEW 296
#define IF 297
#define THEN 298
#define ELSE 299
#define ENDIF 300
#define WHILE 301
#define DO 302
#define ENDWHILE 303
#define REPEAT 304
#define UNTIL 305
#define BREAK 306
#define CONTINUE 307
#define RETURN 308

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
	

#line 296 "y.tab.c"

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
#define YYLAST   761

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  339

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


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
      57,    58,     2,     2,    56,     2,    61,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
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
     330,   331,   332,   333,   334,   335,   336,   337,   340,   341,
     344,   345,   346,   349,   352,   355,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   388,   389,   392,   393,   394,   397,
     398,   401,   402
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
  "NEW", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE",
  "REPEAT", "UNTIL", "BREAK", "CONTINUE", "RETURN", "'{'", "'}'", "','",
  "'('", "')'", "'['", "']'", "'.'", "$accept", "program", "GclassBlock",
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
     305,   306,   307,   308,   123,   125,    44,    40,    41,    91,
      93,    46
};
# endif

#define YYPACT_NINF (-230)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     261,    12,   107,    32,    17,     9,    30,   151,   335,  -230,
     -20,   -16,  -230,  -230,  -230,  -230,    65,  -230,   126,    39,
    -230,  -230,    22,  -230,    44,  -230,  -230,  -230,    21,  -230,
      27,  -230,   335,    30,   335,  -230,  -230,  -230,    12,  -230,
     335,  -230,    52,   117,  -230,   106,    94,   123,  -230,  -230,
     127,   113,    26,  -230,  -230,   104,   300,  -230,  -230,  -230,
    -230,   160,   335,  -230,   335,   335,  -230,  -230,  -230,   106,
     130,   101,   168,  -230,   300,   300,  -230,  -230,  -230,    39,
     194,     3,  -230,   202,   300,    19,  -230,  -230,   335,  -230,
    -230,   171,   300,  -230,  -230,  -230,  -230,   239,  -230,   115,
     343,   164,    83,  -230,    92,  -230,   158,  -230,  -230,  -230,
      56,   163,  -230,   193,  -230,   213,  -230,    55,  -230,   172,
     228,  -230,   483,   157,  -230,  -230,  -230,   229,    69,  -230,
     162,     4,   182,   184,   187,   188,   191,   483,   483,   235,
     248,   362,   369,  -230,  -230,  -230,  -230,  -230,  -230,   264,
     224,   230,  -230,   293,   300,  -230,  -230,  -230,  -230,   295,
    -230,  -230,   231,  -230,  -230,   301,   249,    75,   281,  -230,
    -230,   106,   266,   395,  -230,  -230,  -230,   115,   262,  -230,
     362,  -230,   260,  -230,   165,   362,   362,   362,   501,   403,
    -230,  -230,   267,  -230,  -230,  -230,   322,   165,   276,   278,
     283,   284,   362,   671,  -230,   285,   290,  -230,   362,   345,
     362,  -230,  -230,  -230,  -230,   249,   300,  -230,   350,  -230,
     328,   300,   303,  -230,   327,   708,   169,   558,   355,   302,
     573,   592,   607,   304,   317,   274,  -230,  -230,   319,   320,
     165,   380,   622,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,  -230,   383,  -230,   690,
     331,   543,   173,  -230,   483,   207,  -230,  -230,   362,   364,
    -230,  -230,   375,   379,   348,   351,   362,   362,  -230,   215,
    -230,  -230,   352,   354,  -230,   161,   161,  -230,  -230,  -230,
     738,   738,   738,   738,   738,   738,   723,   723,   356,  -230,
     312,  -230,  -230,   429,  -230,   708,  -230,  -230,  -230,   483,
     483,   641,   656,  -230,  -230,  -230,   324,  -230,   234,   359,
     109,   447,    54,   396,  -230,   238,  -230,  -230,   483,   397,
     398,  -230,  -230,  -230,   465,  -230,  -230,   399,  -230
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
     152,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    99,   100,    96,    97,    98,     0,
     148,   150,    76,     0,     0,    55,    60,    63,    43,     0,
      22,    23,     0,    21,    28,     0,    27,     0,     0,    16,
      32,    83,     0,     0,    68,    93,    86,     0,     0,   152,
       0,   147,   148,    79,     0,     0,     0,     0,     0,     0,
     101,   102,   152,   130,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,   136,   148,     0,    94,     0,     0,
       0,    77,    73,    44,    20,     0,    75,    25,     0,    30,
       0,    75,     0,    90,     0,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,    78,     0,
     149,     0,     0,    26,     0,     0,    67,   103,     0,     0,
     146,   149,     0,     0,     0,     0,     0,     0,   134,     0,
     138,   140,     0,     0,   129,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   149,   115,
       0,   151,    31,     0,    35,   144,   104,   113,   114,     0,
       0,     0,     0,   135,   141,   139,     0,   105,     0,     0,
       0,     0,     0,     0,   142,     0,   106,    34,     0,     0,
       0,   111,   112,   143,     0,   109,   110,     0,   108
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -230,  -230,   417,  -230,   401,  -230,  -230,  -230,  -230,   323,
    -230,   325,   -94,  -230,  -230,   313,  -230,  -230,  -230,   411,
    -230,   357,  -230,    87,  -230,    11,  -230,   440,  -230,   381,
     408,  -230,    15,    -8,  -230,  -230,   -72,   308,    38,  -230,
     -64,  -230,   366,  -230,  -230,   287,  -121,  -138,  -230,  -230,
    -230,  -230,  -230,     6,  -229,  -100,   -98,  -230
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    28,    29,    30,    85,    86,   111,   112,
     167,   113,   114,   168,   117,   118,   119,     7,    24,    25,
      81,    82,   110,     8,    18,   101,    20,    21,    52,    53,
      54,    55,    40,    41,    42,    43,   102,   103,     9,    10,
      72,    97,    98,    99,   128,   129,   142,   143,   144,   145,
     146,   147,   148,   225,   226,   204,   205,   151
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     149,   173,   150,   104,   207,    91,   279,    12,   179,    31,
      13,    14,    15,    19,    16,    11,   188,   189,   131,   164,
     123,    26,   149,    12,   150,    26,    13,    14,    15,    19,
      16,   181,    67,   182,    45,   207,    22,   149,   149,   150,
     150,    46,   149,    50,   150,    35,    44,    62,    22,    65,
     207,   207,    27,    51,    67,    78,    59,    67,   107,    12,
       2,   180,    13,    14,    15,    23,    16,    83,   164,    47,
      63,   318,    66,   149,   116,   150,    56,    57,    68,    88,
      67,    61,    79,   331,   229,   158,   182,   325,   149,   149,
     150,   150,    83,    32,    34,   115,   120,   237,   176,   182,
      87,   310,    89,    90,   217,    93,    69,   220,    94,    95,
     169,    12,   159,   130,    13,    14,    15,    76,    16,   126,
      64,    70,   115,   131,   165,   177,   121,    51,   120,   127,
      12,   218,    96,    13,    14,    15,    71,    16,    17,   154,
     282,   155,   182,   303,   262,   133,   134,   203,   154,   265,
     156,   135,    73,   328,   329,   136,   137,    48,   138,     1,
     139,   140,   141,    80,   149,   207,   150,    12,   152,   179,
      13,    14,    15,   165,    16,   245,   246,   247,   153,   131,
      74,     2,   207,   207,    75,     4,   227,    92,   320,   321,
      84,   230,   231,   232,   160,   100,   207,    12,   122,   106,
      13,    14,    15,   149,    16,   150,   109,   334,   242,   149,
     149,   150,   150,   154,   259,   174,   261,   166,   157,   178,
     149,   149,   150,   150,   163,   268,   171,   269,   149,   154,
     150,   302,   172,   175,   149,    12,   150,   183,    13,    14,
      15,   184,    16,    93,   185,   186,    94,    95,   187,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   214,   154,   190,   304,   192,   193,   194,     1,
     124,   268,   195,   313,   305,   196,   131,   191,   192,   193,
     194,   208,   311,   312,   195,   209,   197,   196,   131,   210,
     268,     2,   326,     3,   268,     4,   333,   211,   197,   213,
     198,   199,   200,   201,    12,   215,   216,    13,    14,    15,
     219,    16,   198,   199,   200,   201,   192,   193,   194,   202,
     224,   228,   195,   221,   235,   196,   131,   236,   192,   193,
     194,   202,   278,   238,   195,   239,   197,   196,   131,    36,
     240,   241,    37,    38,    39,   258,   257,   130,   197,   260,
     198,   199,   200,   201,   263,   264,   267,   131,   266,   271,
     272,   276,   198,   199,   200,   201,   192,   193,   194,   202,
     317,   132,   195,   130,   277,   196,   131,   280,   281,   133,
     134,   202,   324,   131,   283,   135,   197,   298,   300,   136,
     137,   309,   138,   306,   139,   140,   141,   206,   310,   130,
     198,   199,   200,   201,   307,   133,   134,   130,   308,   131,
     314,   135,   315,   316,   327,   136,   137,   131,   138,   202,
     139,   140,   141,   222,    33,   332,   335,   336,   338,    60,
     170,   133,   134,   130,   161,    58,   162,   135,   108,   133,
     134,   136,   137,   131,   138,   135,   139,   140,   141,   136,
     137,   130,   138,   234,   139,   140,   141,   319,    49,    77,
     105,   131,   212,   125,   223,   133,   134,     0,     0,   130,
       0,   135,     0,     0,     0,   136,   137,     0,   138,   131,
     139,   140,   141,   133,   134,     0,     0,   130,     0,   135,
       0,     0,     0,   136,   137,   330,   138,   131,   139,   140,
     141,   133,   134,     0,     0,   130,     0,   135,     0,     0,
     337,   136,   137,     0,   138,   131,   139,   140,   141,   133,
     134,     0,     0,     0,     0,   135,     0,     0,     0,   136,
     137,     0,   138,     0,   139,   140,   141,   133,   134,     0,
       0,     0,     0,   135,     0,     0,     0,   233,   137,     0,
     138,     0,   139,   140,   141,   243,   244,   245,   246,   247,
       0,   248,   249,   250,   251,   252,   253,     0,   254,   255,
     243,   244,   245,   246,   247,     0,   248,   249,   250,   251,
     252,   253,     0,   254,   255,   243,   244,   245,   246,   247,
       0,   248,   249,   250,   251,   252,   253,     0,   254,   255,
       0,     0,     0,   301,   243,   244,   245,   246,   247,     0,
     248,   249,   250,   251,   252,   253,   270,   254,   255,   243,
     244,   245,   246,   247,     0,   248,   249,   250,   251,   252,
     253,   273,   254,   255,   243,   244,   245,   246,   247,     0,
     248,   249,   250,   251,   252,   253,     0,   254,   255,     0,
     274,     0,     0,   243,   244,   245,   246,   247,     0,   248,
     249,   250,   251,   252,   253,   275,   254,   255,   243,   244,
     245,   246,   247,     0,   248,   249,   250,   251,   252,   253,
     284,   254,   255,   243,   244,   245,   246,   247,     0,   248,
     249,   250,   251,   252,   253,     0,   254,   255,     0,   322,
     256,     0,   243,   244,   245,   246,   247,     0,   248,   249,
     250,   251,   252,   253,   323,   254,   255,     0,     0,   299,
     243,   244,   245,   246,   247,     0,   248,   249,   250,   251,
     252,   253,     0,   254,   255,   243,   244,   245,   246,   247,
       0,   248,   249,   250,   251,   252,   253,     0,    -1,    -1,
     243,   244,   245,   246,   247,     0,    -1,    -1,    -1,    -1,
      -1,    -1
};

static const yytype_int16 yycheck[] =
{
     100,   122,   100,    75,   142,    69,   235,     4,     4,     0,
       7,     8,     9,     2,    11,     3,   137,   138,    14,   113,
      92,     4,   122,     4,   122,     4,     7,     8,     9,    18,
      11,   131,    40,   131,    54,   173,     4,   137,   138,   137,
     138,    57,   142,     4,   142,     7,     8,    32,     4,    34,
     188,   189,    35,    14,    62,    29,    35,    65,    55,     4,
      30,    57,     7,     8,     9,    33,    11,    56,   162,     4,
      32,   300,    34,   173,    55,   173,    54,    33,    40,    64,
      88,    54,    56,    29,   184,    29,   184,   316,   188,   189,
     188,   189,    81,     6,     7,    84,    85,   197,    29,   197,
      62,    47,    64,    65,    29,     4,    54,   171,     7,     8,
      55,     4,    56,     4,     7,     8,     9,     4,    11,     4,
      33,     4,   111,    14,   113,    56,    88,    14,   117,    14,
       4,    56,    31,     7,     8,     9,    30,    11,    31,    56,
     240,    58,   240,   264,   216,    36,    37,   141,    56,   221,
      58,    42,    58,    44,    45,    46,    47,    31,    49,     8,
      51,    52,    53,    59,   264,   303,   264,     4,     4,     4,
       7,     8,     9,   162,    11,    14,    15,    16,    14,    14,
      57,    30,   320,   321,    57,    34,   180,    57,   309,   310,
      30,   185,   186,   187,    31,    27,   334,     4,    27,     5,
       7,     8,     9,   303,    11,   303,     4,   328,   202,   309,
     310,   309,   310,    56,   208,    58,   210,     4,    60,    57,
     320,   321,   320,   321,    31,    56,    54,    58,   328,    56,
     328,    58,     4,     4,   334,     4,   334,    55,     7,     8,
       9,    57,    11,     4,    57,    57,     7,     8,    57,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    31,    56,    29,    58,     4,     5,     6,     8,
      31,    56,    10,    58,   268,    13,    14,    29,     4,     5,
       6,    17,   276,   277,    10,    61,    24,    13,    14,    59,
      56,    30,    58,    32,    56,    34,    58,     4,    24,     4,
      38,    39,    40,    41,     4,     4,    57,     7,     8,     9,
      29,    11,    38,    39,    40,    41,     4,     5,     6,    57,
      58,    61,    10,    57,    57,    13,    14,     5,     4,     5,
       6,    57,    58,    57,    10,    57,    24,    13,    14,     4,
      57,    57,     7,     8,     9,    55,    61,     4,    24,     4,
      38,    39,    40,    41,     4,    27,    29,    14,    55,     4,
      58,    57,    38,    39,    40,    41,     4,     5,     6,    57,
      58,    28,    10,     4,    57,    13,    14,    58,    58,    36,
      37,    57,    58,    14,     4,    42,    24,     4,    57,    46,
      47,    43,    49,    29,    51,    52,    53,    28,    47,     4,
      38,    39,    40,    41,    29,    36,    37,     4,    29,    14,
      58,    42,    58,    57,    55,    46,    47,    14,    49,    57,
      51,    52,    53,    28,     7,    29,    29,    29,    29,    28,
     117,    36,    37,     4,   111,    24,   111,    42,    81,    36,
      37,    46,    47,    14,    49,    42,    51,    52,    53,    46,
      47,     4,    49,    50,    51,    52,    53,    28,    18,    51,
      79,    14,   154,    97,   177,    36,    37,    -1,    -1,     4,
      -1,    42,    -1,    -1,    -1,    46,    47,    -1,    49,    14,
      51,    52,    53,    36,    37,    -1,    -1,     4,    -1,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    14,    51,    52,
      53,    36,    37,    -1,    -1,     4,    -1,    42,    -1,    -1,
      45,    46,    47,    -1,    49,    14,    51,    52,    53,    36,
      37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      47,    -1,    49,    -1,    51,    52,    53,    36,    37,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    47,    -1,
      49,    -1,    51,    52,    53,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    60,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23,    58,    25,    26,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    58,    25,    26,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    -1,
      58,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    58,    25,    26,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    23,
      58,    25,    26,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    -1,    58,
      29,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    23,    58,    25,    26,    -1,    -1,    29,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    30,    32,    34,    63,    64,    79,    85,   100,
     101,     3,     4,     7,     8,     9,    11,    31,    86,    87,
      88,    89,     4,    33,    80,    81,     4,    35,    65,    66,
      67,     0,    85,    64,    85,   100,     4,     7,     8,     9,
      94,    95,    96,    97,   100,    54,    57,     4,    31,    89,
       4,    14,    90,    91,    92,    93,    54,    33,    81,    35,
      66,    54,    94,   100,    85,    94,   100,    95,   100,    54,
       4,    30,   102,    58,    57,    57,     4,    92,    29,    56,
      59,    82,    83,    87,    30,    68,    69,   100,    94,   100,
     100,   102,    57,     4,     7,     8,    31,   103,   104,   105,
      27,    87,    98,    99,    98,    91,     5,    55,    83,     4,
      84,    70,    71,    73,    74,    87,    55,    76,    77,    78,
      87,   100,    27,    98,    31,   104,     4,    14,   106,   107,
       4,    14,    28,    36,    37,    42,    46,    47,    49,    51,
      52,    53,   108,   109,   110,   111,   112,   113,   114,   117,
     118,   119,     4,    14,    56,    58,    58,    60,    29,    56,
      31,    71,    73,    31,    74,    87,     4,    72,    75,    55,
      77,    54,     4,   108,    58,     4,    29,    56,    57,     4,
      57,   117,   118,    55,    57,    57,    57,    57,   108,   108,
      29,    29,     4,     5,     6,    10,    13,    24,    38,    39,
      40,    41,    57,   115,   117,   118,    28,   109,    17,    61,
      59,     4,    99,     4,    31,     4,    57,    29,    56,    29,
     102,    57,    28,   107,    58,   115,   116,   115,    61,   117,
     115,   115,   115,    46,    50,    57,     5,   117,    57,    57,
      57,    57,   115,    12,    13,    14,    15,    16,    18,    19,
      20,    21,    22,    23,    25,    26,    29,    61,    55,   115,
       4,   115,    98,     4,    27,    98,    55,    29,    56,    58,
      58,     4,    58,    58,    58,    58,    57,    57,    58,   116,
      58,    58,   117,     4,    58,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,     4,    29,
      57,    60,    58,   108,    58,   115,    29,    29,    29,    43,
      47,   115,   115,    58,    58,    58,    57,    58,   116,    28,
     108,   108,    58,    58,    58,   116,    58,    55,    44,    45,
      48,    29,    29,    58,   108,    29,    29,    45,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    65,    65,    66,    66,    67,    68,
      69,    69,    69,    70,    70,    71,    72,    72,    73,    73,
      74,    75,    76,    76,    77,    78,    79,    79,    80,    80,
      81,    82,    82,    83,    84,    84,    85,    85,    86,    86,
      87,    87,    87,    87,    87,    88,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    96,    97,
      97,    97,    97,    98,    98,    98,    99,    99,   100,   100,
     101,   102,   102,   102,   103,   103,   104,   105,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   110,   110,
     111,   111,   111,   112,   113,   114,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   116,   117,   117,   117,   118,
     118,   119,   119
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
       1,     2,     1,     1,     3,     4,     1,     2,     3,     4,
       3,     4,     5,     6,     3,     1,     4,     2,     1,     3,
       1,     4,     1
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
#line 1792 "y.tab.c"
    break;

  case 3:
#line 96 "code.y"
                                                                        {}
#line 1798 "y.tab.c"
    break;

  case 4:
#line 97 "code.y"
                                                                        {}
#line 1804 "y.tab.c"
    break;

  case 5:
#line 98 "code.y"
                                                                        {}
#line 1810 "y.tab.c"
    break;

  case 6:
#line 99 "code.y"
                                                                        {}
#line 1816 "y.tab.c"
    break;

  case 7:
#line 100 "code.y"
                                                                        {}
#line 1822 "y.tab.c"
    break;

  case 8:
#line 101 "code.y"
                                                                        {}
#line 1828 "y.tab.c"
    break;

  case 9:
#line 102 "code.y"
                                                                        {}
#line 1834 "y.tab.c"
    break;

  case 10:
#line 103 "code.y"
                                                                        {}
#line 1840 "y.tab.c"
    break;

  case 11:
#line 104 "code.y"
                                                                        {}
#line 1846 "y.tab.c"
    break;

  case 12:
#line 107 "code.y"
                                                        {/*printClassTable(classTable);printf("CLASS DONE\n");*/}
#line 1852 "y.tab.c"
    break;

  case 13:
#line 108 "code.y"
                                                                {}
#line 1858 "y.tab.c"
    break;

  case 14:
#line 111 "code.y"
                                                        {}
#line 1864 "y.tab.c"
    break;

  case 15:
#line 112 "code.y"
                                                                {}
#line 1870 "y.tab.c"
    break;

  case 16:
#line 115 "code.y"
                                                                                {}
#line 1876 "y.tab.c"
    break;

  case 17:
#line 116 "code.y"
                                                                        {}
#line 1882 "y.tab.c"
    break;

  case 18:
#line 119 "code.y"
                                                                                {
											currentClass = strdup((yyvsp[0].string));
											(yyval.string) = (yyvsp[0].string);
										}
#line 1891 "y.tab.c"
    break;

  case 19:
#line 125 "code.y"
                                                                                {	
											getMemLoc(8);
											addToClassTable(classTable, typeTable, (yyvsp[0].dno), currentClass);

										}
#line 1901 "y.tab.c"
    break;

  case 20:
#line 132 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[-1].dno));}
#line 1907 "y.tab.c"
    break;

  case 21:
#line 133 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode(NULL,(yyvsp[-1].dno));}
#line 1913 "y.tab.c"
    break;

  case 22:
#line 134 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),NULL);}
#line 1919 "y.tab.c"
    break;

  case 23:
#line 137 "code.y"
                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1925 "y.tab.c"
    break;

  case 24:
#line 138 "code.y"
                                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1931 "y.tab.c"
    break;

  case 25:
#line 141 "code.y"
                                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 1937 "y.tab.c"
    break;

  case 26:
#line 144 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),declIdNode((yyvsp[-2].string),0,NULL));}
#line 1943 "y.tab.c"
    break;

  case 27:
#line 145 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 1949 "y.tab.c"
    break;

  case 28:
#line 148 "code.y"
                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1955 "y.tab.c"
    break;

  case 29:
#line 149 "code.y"
                                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1961 "y.tab.c"
    break;

  case 30:
#line 152 "code.y"
                                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 1967 "y.tab.c"
    break;

  case 31:
#line 155 "code.y"
                                                                {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 1973 "y.tab.c"
    break;

  case 32:
#line 158 "code.y"
                                                                {}
#line 1979 "y.tab.c"
    break;

  case 33:
#line 159 "code.y"
                                                                {}
#line 1985 "y.tab.c"
    break;

  case 34:
#line 162 "code.y"
                                                                        {	
										
										struct ClassTableEntry* entry = CLookup(classTable,currentClass);
										struct MethodList* method = MLookup(entry -> methodList,(yyvsp[-6].string));
										funcCodeGen((yyvsp[-2].no), fp,method -> flabel);
										lst = NULL;
									}
#line 1997 "y.tab.c"
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
#line 2009 "y.tab.c"
    break;

  case 36:
#line 180 "code.y"
                                                        {/*printf("TYPE DONE\n");*/}
#line 2015 "y.tab.c"
    break;

  case 37:
#line 181 "code.y"
                                                        {}
#line 2021 "y.tab.c"
    break;

  case 38:
#line 184 "code.y"
                                                        {}
#line 2027 "y.tab.c"
    break;

  case 39:
#line 185 "code.y"
                                                {}
#line 2033 "y.tab.c"
    break;

  case 40:
#line 188 "code.y"
                                                        {addUserDefToTypeTable(typeTable,(yyvsp[-1].dno),(yyvsp[-3].string));}
#line 2039 "y.tab.c"
    break;

  case 41:
#line 191 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2045 "y.tab.c"
    break;

  case 42:
#line 192 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2051 "y.tab.c"
    break;

  case 43:
#line 195 "code.y"
                                                        {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2057 "y.tab.c"
    break;

  case 44:
#line 198 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),declIdNode((yyvsp[-2].string),0,NULL));}
#line 2063 "y.tab.c"
    break;

  case 45:
#line 199 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2069 "y.tab.c"
    break;

  case 46:
#line 203 "code.y"
                                        {	
						gst = (struct GSymbolTable*)malloc(sizeof(struct GSymbolTable));
						generateGlobalSymbolTable(gst,(yyvsp[-1].dno),NULL,NULL,typeTable,classTable);
						startCodeGen(fp,memLoc,gst,classTable);
						//printGlobalSymbolTable(gst);
					}
#line 2080 "y.tab.c"
    break;

  case 47:
#line 209 "code.y"
                                        {gst = NULL;}
#line 2086 "y.tab.c"
    break;

  case 48:
#line 212 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2092 "y.tab.c"
    break;

  case 49:
#line 213 "code.y"
                                {(yyval.dno) = (yyvsp[0].dno);}
#line 2098 "y.tab.c"
    break;

  case 50:
#line 216 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2104 "y.tab.c"
    break;

  case 51:
#line 217 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2110 "y.tab.c"
    break;

  case 52:
#line 218 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2116 "y.tab.c"
    break;

  case 53:
#line 219 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2122 "y.tab.c"
    break;

  case 54:
#line 220 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2128 "y.tab.c"
    break;

  case 55:
#line 223 "code.y"
                                        {addTupleToTypeTable(typeTable,(yyvsp[-1].pt),(yyvsp[-3].string));(yyval.string) = (yyvsp[-3].string);}
#line 2134 "y.tab.c"
    break;

  case 56:
#line 226 "code.y"
                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2140 "y.tab.c"
    break;

  case 57:
#line 229 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 2146 "y.tab.c"
    break;

  case 58:
#line 230 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2152 "y.tab.c"
    break;

  case 59:
#line 233 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2158 "y.tab.c"
    break;

  case 60:
#line 234 "code.y"
                                                        {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 2164 "y.tab.c"
    break;

  case 61:
#line 237 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].dno) -> varname,(yyvsp[0].dno) -> dim + 1,(yyvsp[0].dno) -> shape);}
#line 2170 "y.tab.c"
    break;

  case 62:
#line 238 "code.y"
                                                {(yyval.dno) = (yyvsp[0].dno);}
#line 2176 "y.tab.c"
    break;

  case 63:
#line 241 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[-3].dno) -> varname,(yyvsp[-3].dno) -> dim + 1,addArrayShape((yyvsp[-3].dno) -> shape,(yyvsp[-1].number)));}
#line 2182 "y.tab.c"
    break;

  case 64:
#line 242 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2188 "y.tab.c"
    break;

  case 65:
#line 245 "code.y"
                                                        {}
#line 2194 "y.tab.c"
    break;

  case 66:
#line 246 "code.y"
                                                        {}
#line 2200 "y.tab.c"
    break;

  case 67:
#line 249 "code.y"
                                                        {	
									struct Gsymbol* g = GlobalLookup(gst,(yyvsp[-6].string));
									funcCodeGen((yyvsp[-2].no), fp,g -> flabel);
									lst = NULL;
								}
#line 2210 "y.tab.c"
    break;

  case 68:
#line 256 "code.y"
                                                                {
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyFuncHead(gst,(yyvsp[-3].string),TLookup(typeTable,(yyvsp[-4].string)),CLookup(classTable,(yyvsp[-4].string)),(yyvsp[-1].pt));
								addParamToLST(lst,(yyvsp[-1].pt));
								(yyval.string) = (yyvsp[-3].string);
							}
#line 2221 "y.tab.c"
    break;

  case 69:
#line 264 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2227 "y.tab.c"
    break;

  case 70:
#line 265 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2233 "y.tab.c"
    break;

  case 71:
#line 266 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2239 "y.tab.c"
    break;

  case 72:
#line 267 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2245 "y.tab.c"
    break;

  case 73:
#line 270 "code.y"
                                                {(yyval.pt) = addParameter((yyvsp[-2].pt),(yyvsp[0].pt));}
#line 2251 "y.tab.c"
    break;

  case 74:
#line 271 "code.y"
                                                {(yyval.pt) = (yyvsp[0].pt);}
#line 2257 "y.tab.c"
    break;

  case 75:
#line 272 "code.y"
                                                        {(yyval.pt) = NULL;}
#line 2263 "y.tab.c"
    break;

  case 76:
#line 275 "code.y"
                                                {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-1].string),0,typeTable,classTable);}
#line 2269 "y.tab.c"
    break;

  case 77:
#line 276 "code.y"
                                                        {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-2].string),1,typeTable,classTable);}
#line 2275 "y.tab.c"
    break;

  case 78:
#line 279 "code.y"
                                                                {	
									if(gst == NULL){
										startCodeGen(fp,-1,gst,classTable);	
										fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
									}
									funcCodeGen((yyvsp[-2].no), fp,-1);}
#line 2286 "y.tab.c"
    break;

  case 79:
#line 285 "code.y"
                                                                {exit(0);}
#line 2292 "y.tab.c"
    break;

  case 80:
#line 288 "code.y"
                                {lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));}
#line 2298 "y.tab.c"
    break;

  case 81:
#line 293 "code.y"
                                        {localMemLoc = 0; addLocalVarToLST(lst,(yyvsp[-1].dno),NULL,NULL,typeTable,classTable);}
#line 2304 "y.tab.c"
    break;

  case 82:
#line 294 "code.y"
                                        {(yyval.dno) = NULL;}
#line 2310 "y.tab.c"
    break;

  case 83:
#line 295 "code.y"
                                        {(yyval.dno) = NULL;}
#line 2316 "y.tab.c"
    break;

  case 84:
#line 298 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2322 "y.tab.c"
    break;

  case 85:
#line 299 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2328 "y.tab.c"
    break;

  case 86:
#line 302 "code.y"
                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2334 "y.tab.c"
    break;

  case 87:
#line 305 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2340 "y.tab.c"
    break;

  case 88:
#line 306 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2346 "y.tab.c"
    break;

  case 89:
#line 307 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2352 "y.tab.c"
    break;

  case 90:
#line 310 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 2358 "y.tab.c"
    break;

  case 91:
#line 311 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2364 "y.tab.c"
    break;

  case 92:
#line 315 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2370 "y.tab.c"
    break;

  case 93:
#line 316 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),1,NULL);}
#line 2376 "y.tab.c"
    break;

  case 94:
#line 322 "code.y"
                                                                        {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 2382 "y.tab.c"
    break;

  case 95:
#line 323 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2388 "y.tab.c"
    break;

  case 96:
#line 326 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2394 "y.tab.c"
    break;

  case 97:
#line 327 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2400 "y.tab.c"
    break;

  case 98:
#line 328 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2406 "y.tab.c"
    break;

  case 99:
#line 329 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2412 "y.tab.c"
    break;

  case 100:
#line 330 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2418 "y.tab.c"
    break;

  case 101:
#line 331 "code.y"
                                                                {(yyval.no) = makeJumpNode(break_node);}
#line 2424 "y.tab.c"
    break;

  case 102:
#line 332 "code.y"
                                                                        {(yyval.no) = makeJumpNode(continue_node);}
#line 2430 "y.tab.c"
    break;

  case 103:
#line 333 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,NULL);}
#line 2436 "y.tab.c"
    break;

  case 104:
#line 334 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-4].string),gst,(yyvsp[-2].at));}
#line 2442 "y.tab.c"
    break;

  case 105:
#line 335 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-4].no),(yyvsp[-2].string),NULL,typeTable);}
#line 2448 "y.tab.c"
    break;

  case 106:
#line 336 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-5].no),(yyvsp[-3].string),(yyvsp[-1].at),typeTable);}
#line 2454 "y.tab.c"
    break;

  case 107:
#line 337 "code.y"
                                                                        {(yyval.no) = makeReturnNode((yyvsp[-1].no));}
#line 2460 "y.tab.c"
    break;

  case 108:
#line 340 "code.y"
                                                                {(yyval.no) = makeIfElseBlock((yyvsp[-7].no),(yyvsp[-4].no),(yyvsp[-2].no));}
#line 2466 "y.tab.c"
    break;

  case 109:
#line 341 "code.y"
                                                                        {(yyval.no) = makeIfElseBlock((yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 2472 "y.tab.c"
    break;

  case 110:
#line 344 "code.y"
                                                                {(yyval.no) = makeWhileBlock((yyvsp[-5].no),(yyvsp[-2].no));}
#line 2478 "y.tab.c"
    break;

  case 111:
#line 345 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 2484 "y.tab.c"
    break;

  case 112:
#line 346 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 2490 "y.tab.c"
    break;

  case 113:
#line 349 "code.y"
                                                                        {(yyval.no) = makeReadNode((yyvsp[-2].no));}
#line 2496 "y.tab.c"
    break;

  case 114:
#line 352 "code.y"
                                                                {(yyval.no) = makeWriteNode((yyvsp[-2].no));}
#line 2502 "y.tab.c"
    break;

  case 115:
#line 355 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(assign,(yyvsp[-3].no),(yyvsp[-1].no),typeTable);}
#line 2508 "y.tab.c"
    break;

  case 116:
#line 358 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(add,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2514 "y.tab.c"
    break;

  case 117:
#line 359 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(sub,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2520 "y.tab.c"
    break;

  case 118:
#line 360 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(mul,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2526 "y.tab.c"
    break;

  case 119:
#line 361 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(div,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2532 "y.tab.c"
    break;

  case 120:
#line 362 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(mod,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2538 "y.tab.c"
    break;

  case 121:
#line 363 "code.y"
                                                                {(yyval.no) = makeOperatorNode(gt,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2544 "y.tab.c"
    break;

  case 122:
#line 364 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(gte,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2550 "y.tab.c"
    break;

  case 123:
#line 365 "code.y"
                                                                {(yyval.no) = makeOperatorNode(lt,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2556 "y.tab.c"
    break;

  case 124:
#line 366 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(lte,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2562 "y.tab.c"
    break;

  case 125:
#line 367 "code.y"
                                                                {(yyval.no) = makeOperatorNode(eq,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2568 "y.tab.c"
    break;

  case 126:
#line 368 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(neq,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2574 "y.tab.c"
    break;

  case 127:
#line 369 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(and,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2580 "y.tab.c"
    break;

  case 128:
#line 370 "code.y"
                                                                {(yyval.no) = makeOperatorNode(or,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2586 "y.tab.c"
    break;

  case 129:
#line 371 "code.y"
                                                                {(yyval.no) = (yyvsp[-1].no);}
#line 2592 "y.tab.c"
    break;

  case 130:
#line 372 "code.y"
                                                                        {(yyval.no) = makeNumNode((yyvsp[0].number),0,typeTable);}
#line 2598 "y.tab.c"
    break;

  case 131:
#line 373 "code.y"
                                                                        {(yyval.no) = makeNumNode(-1 * (yyvsp[0].number),0,typeTable);}
#line 2604 "y.tab.c"
    break;

  case 132:
#line 374 "code.y"
                                                                        {(yyval.no) = makeStringNode((yyvsp[0].string),typeTable);}
#line 2610 "y.tab.c"
    break;

  case 133:
#line 375 "code.y"
                                                                        {(yyval.no) = makeNullNode(typeTable);}
#line 2616 "y.tab.c"
    break;

  case 134:
#line 376 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-2].string),gst,NULL);}
#line 2622 "y.tab.c"
    break;

  case 135:
#line 377 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,(yyvsp[-1].at));}
#line 2628 "y.tab.c"
    break;

  case 136:
#line 378 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2634 "y.tab.c"
    break;

  case 137:
#line 379 "code.y"
                                                                        {(yyval.no) = makeAddrNode((yyvsp[0].no),gst,lst,typeTable);}
#line 2640 "y.tab.c"
    break;

  case 138:
#line 380 "code.y"
                                                                        {(yyval.no) = makeTypeAllocNode();}
#line 2646 "y.tab.c"
    break;

  case 139:
#line 381 "code.y"
                                                                        {(yyval.no) = makeClassAllocNode((yyvsp[-1].string),classTable);}
#line 2652 "y.tab.c"
    break;

  case 140:
#line 382 "code.y"
                                                                        {(yyval.no) = makeMemInitNode(typeTable);}
#line 2658 "y.tab.c"
    break;

  case 141:
#line 383 "code.y"
                                                                        {(yyval.no) = makeFreeNode((yyvsp[-1].no),typeTable);}
#line 2664 "y.tab.c"
    break;

  case 142:
#line 384 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-4].no),(yyvsp[-2].string),NULL,typeTable);}
#line 2670 "y.tab.c"
    break;

  case 143:
#line 385 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-5].no),(yyvsp[-3].string),(yyvsp[-1].at),typeTable);}
#line 2676 "y.tab.c"
    break;

  case 144:
#line 388 "code.y"
                                        {(yyval.at) = addArguments((yyvsp[-2].at),makeArgStruct((yyvsp[0].no)),typeTable);}
#line 2682 "y.tab.c"
    break;

  case 145:
#line 389 "code.y"
                                        {(yyval.at) = makeArgStruct((yyvsp[0].no));}
#line 2688 "y.tab.c"
    break;

  case 146:
#line 392 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[-1].no),typeTable);}
#line 2694 "y.tab.c"
    break;

  case 147:
#line 393 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[0].no),typeTable);}
#line 2700 "y.tab.c"
    break;

  case 148:
#line 394 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2706 "y.tab.c"
    break;

  case 149:
#line 397 "code.y"
                                                {(yyval.no) = extendTypeNode((yyvsp[-2].no),(yyvsp[0].string),typeTable,classTable);}
#line 2712 "y.tab.c"
    break;

  case 150:
#line 398 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2718 "y.tab.c"
    break;

  case 151:
#line 401 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[-3].no) -> varname,gst,lst,addArrayDim((yyvsp[-3].no) -> indices,(yyvsp[-1].no)),typeTable,classTable);}
#line 2724 "y.tab.c"
    break;

  case 152:
#line 402 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[0].string),gst,lst,NULL,typeTable,classTable);}
#line 2730 "y.tab.c"
    break;


#line 2734 "y.tab.c"

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
#line 405 "code.y"


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
