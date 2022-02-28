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
	void verifyFuncRetType(char* type,struct ClassTable* classTable);

#line 128 "y.tab.c"

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
#line 59 "code.y"

	struct tnode *no;
	struct dnode *dno;
	struct ParamStruct *pt;
	struct ArgStruct *at;
	int number;
	char* string;
	int* seq;
	struct MethodList* methodList;
	

#line 304 "y.tab.c"

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
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   928

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  160
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  367

#define YYUNDEFTOK  2
#define YYMAXUTOK   311


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
      60,    61,     2,     2,    59,     2,    64,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   110,   111,   114,   115,   118,   119,   122,   126,
     132,   139,   140,   141,   144,   145,   148,   151,   152,   155,
     156,   159,   162,   165,   166,   169,   175,   186,   187,   190,
     191,   194,   197,   200,   201,   204,   207,   208,   212,   218,
     221,   222,   225,   226,   227,   228,   229,   232,   235,   238,
     239,   242,   243,   246,   247,   250,   251,   254,   255,   258,
     265,   273,   274,   275,   276,   280,   281,   282,   285,   286,
     289,   295,   298,   303,   304,   305,   308,   309,   312,   315,
     316,   317,   320,   321,   325,   326,   332,   333,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   352,   353,   356,   357,   358,   361,   364,   367,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   403,   404,   407,   408,   409,   412,   413,   414,   417,
     418
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
  "ENDTYPE", "CLASS", "ENDCLASS", "EXTENDS", "READ", "WRITE", "ALLOC",
  "INITIALIZE", "FREE", "NEW", "DELETE", "IF", "THEN", "ELSE", "ENDIF",
  "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL", "BREAK", "CONTINUE",
  "RETURN", "'{'", "'}'", "','", "'('", "')'", "'['", "']'", "'.'",
  "$accept", "program", "GclassBlock", "GclassList", "Gclass", "ClassName",
  "GclassDeclBlockSeg", "GclassDeclBlock", "GclassAttrDeclList",
  "GclassAttrDecl", "GclassIdList", "GclassFuncDeclList", "GclassFuncDecl",
  "GclassFuncName", "GclassFuncDefBlock", "GclassFuncDef", "MName",
  "GtypeBlock", "GtypeList", "Gtype", "GtypeName", "GtypeDeclList",
  "GtypeDecl", "GtypeIdList", "GdeclBlock", "GdeclList", "Type",
  "TupleType", "Gdecl", "GidList", "Gid", "IdentifierDecl", "IdArrDecl",
  "FdefBlock", "Fdef", "FName", "FuncRetType", "ParamList", "Param",
  "MainBlock", "MainHeader", "LdeclBlock", "LdeclList", "Ldecl",
  "LocalType", "LidList", "Lid", "Slist", "Stmt", "IfStmt", "LoopStmt",
  "InputStmt", "OutputStmt", "AssgStmt", "expr", "ArgList", "Identifier",
  "StructId", "IdArr", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   123,   125,    44,
      40,    41,    91,    93,    46
};
# endif

#define YYPACT_NINF (-234)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     156,     4,   114,     2,    11,    14,   -20,    -4,   213,  -234,
     -37,   -32,  -234,  -234,  -234,  -234,    40,  -234,   132,   113,
    -234,  -234,  -234,  -234,     6,  -234,    -3,    21,  -234,    30,
    -234,    48,  -234,   213,   -20,   213,  -234,  -234,  -234,     4,
    -234,   213,  -234,    62,    49,  -234,    81,    18,    69,  -234,
    -234,    94,   123,   -11,  -234,  -234,    70,  -234,  -234,   418,
     121,  -234,  -234,   131,   213,  -234,   213,   213,  -234,  -234,
    -234,    81,   137,   206,   146,  -234,   418,   418,  -234,  -234,
    -234,   113,   195,    52,  -234,   177,  -234,   418,    63,  -234,
    -234,   213,  -234,  -234,   173,   418,  -234,  -234,  -234,  -234,
     293,  -234,   164,   446,   165,    50,  -234,    88,  -234,   142,
    -234,  -234,  -234,    -7,   174,  -234,   237,  -234,   207,  -234,
      72,  -234,   163,   229,  -234,   635,   129,  -234,  -234,  -234,
     232,    38,  -234,   184,   188,     9,   199,   210,   233,   243,
     244,   635,   635,   259,   269,   400,   474,  -234,  -234,  -234,
    -234,  -234,  -234,   249,   248,   251,  -234,   310,   418,  -234,
    -234,  -234,  -234,   312,  -234,  -234,   256,  -234,  -234,   313,
     266,    55,   297,  -234,  -234,    81,   268,   502,  -234,  -234,
    -234,   164,   152,   326,  -234,   267,   400,  -234,   272,  -234,
     130,   400,   400,   400,   662,   528,  -234,  -234,   277,  -234,
    -234,   274,  -234,   344,   130,   290,   291,   292,   294,   295,
     400,   838,  -234,   296,   303,  -234,   400,   358,   400,  -234,
    -234,  -234,  -234,   266,   418,  -234,   369,  -234,   346,   418,
     317,  -234,   348,   874,   170,   316,   375,   721,   380,   324,
     736,   751,   772,   337,   338,   280,   382,  -234,  -234,   339,
     341,   130,   395,   130,   787,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,  -234,   399,
    -234,   856,   349,   706,   176,  -234,   635,   189,  -234,  -234,
     400,   378,   304,  -234,  -234,  -234,   393,   401,   364,   379,
     400,   400,  -234,   194,   373,  -234,  -234,   374,   377,   384,
    -234,   155,   155,  -234,  -234,  -234,   904,   904,   904,   904,
     904,   904,   889,   889,   386,  -234,   328,  -234,  -234,   556,
    -234,   874,  -234,   404,   197,  -234,  -234,   635,   635,   802,
     823,  -234,   352,  -234,  -234,  -234,   376,   409,   202,   389,
    -234,   419,   417,   582,    15,   421,  -234,   231,  -234,   239,
    -234,   422,  -234,  -234,   635,   424,   427,  -234,  -234,  -234,
    -234,  -234,   609,  -234,  -234,   428,  -234
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,    55,    53,    52,    54,     0,    49,     0,     0,
      56,    51,    42,    38,     0,    40,     0,    18,    13,     0,
      15,     0,     1,     0,     0,     0,     8,    74,    72,    71,
      73,     0,    68,     0,     0,    10,    85,     0,     0,    48,
      50,    66,     0,     0,    60,    61,    64,    37,    39,     0,
       0,    12,    14,     0,     0,     5,     0,     0,     7,    67,
       9,    85,     0,     0,     0,    82,    77,    77,    66,    63,
      58,     0,     0,     0,    44,     0,    19,     0,     0,    20,
       4,     0,     3,     6,     0,    77,    91,    90,    89,    84,
       0,    87,     0,     0,     0,     0,    76,     0,    59,     0,
      41,    43,    47,     0,     0,    25,     0,    30,     0,    17,
       0,    34,     0,     0,     2,     0,     0,    83,    86,    94,
       0,     0,    93,   160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,   101,   102,
      98,    99,   100,     0,   155,   158,    78,     0,     0,    57,
      62,    65,    45,     0,    23,    24,     0,    22,    29,     0,
      28,     0,     0,    16,    33,    85,     0,     0,    70,    95,
      88,     0,     0,     0,   160,     0,     0,   154,   155,    81,
       0,     0,     0,     0,     0,     0,   103,   104,   160,   134,
     136,     0,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   155,     0,    96,     0,     0,     0,    79,
      75,    46,    21,     0,    77,    26,     0,    31,     0,    77,
       0,    92,     0,   152,     0,   157,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   111,     0,
      80,     0,   156,     0,     0,    27,     0,     0,    69,   105,
       0,     0,     0,   157,   153,   156,     0,     0,     0,     0,
       0,     0,   138,     0,   157,   142,   144,     0,     0,     0,
     133,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   156,   119,     0,   159,    32,     0,
      36,   151,   106,     0,     0,   117,   118,     0,     0,     0,
       0,   139,     0,   145,   143,   146,     0,     0,     0,     0,
     109,     0,     0,     0,     0,     0,   149,     0,   147,     0,
     107,     0,    35,   110,     0,     0,     0,   115,   116,   150,
     148,   108,     0,   113,   114,     0,   112
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -234,  -234,   441,  -234,   430,  -234,  -234,  -234,  -234,   354,
    -234,   356,  -107,  -234,  -234,   343,  -234,  -234,  -234,   450,
    -234,  -234,   394,  -234,   109,  -234,    19,  -234,   458,  -234,
     398,   431,  -234,    65,    29,  -234,  -234,   -69,   322,    22,
    -234,   -67,  -234,   387,  -234,  -234,   301,  -124,  -144,  -234,
    -234,  -234,  -234,  -234,    16,  -233,  -103,  -100,  -234
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    29,    30,    31,    88,    89,   114,   115,
     171,   116,   117,   172,   120,   121,   122,     7,    24,    25,
      26,    83,    84,   113,     8,    18,   104,    20,    21,    53,
      54,    55,    56,    41,    42,    43,    44,   105,   106,     9,
      10,    74,   100,   101,   102,   131,   132,   146,   147,   148,
     149,   150,   151,   152,   233,   234,   212,   213,   155
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     153,   177,   215,   154,    94,     1,    22,    11,   107,   168,
      22,     2,   293,   184,    32,    27,   185,   194,   195,    80,
      46,    19,   153,   162,   135,   154,   126,     2,    47,    36,
      45,     4,   187,   215,    27,   188,    23,    19,   153,   153,
      57,   154,   154,   153,    48,   357,   154,    28,    81,   324,
     215,   215,   163,    72,    59,    65,    12,    68,    60,   168,
      13,    14,    15,    70,    16,   328,    61,    12,   180,   186,
      69,    13,    14,    15,   153,    16,    12,   154,    85,    75,
      13,    14,    15,   338,    16,   225,    90,   239,    92,    93,
     188,   153,   153,    69,   154,   154,    69,   181,    64,   347,
      67,   248,    85,   349,   188,    63,   118,   123,   228,   158,
     110,   159,    73,   124,   226,    33,    35,    51,    12,    71,
      69,   119,    13,    14,    15,    86,    16,    78,    52,    76,
     173,    91,    82,   118,   184,   169,    12,   185,    52,   123,
      13,    14,    15,    66,    16,   135,    17,   158,   297,   160,
     299,   188,   319,   188,    77,   274,   198,   199,   200,   201,
     277,   211,    87,   202,    49,     1,   203,   135,   129,   156,
     257,   258,   259,   153,   103,   215,   154,   204,    12,   130,
     157,   112,    13,    14,    15,   169,    16,     2,   158,     3,
     178,     4,   205,   206,   207,   208,   209,    95,   215,   215,
     109,   125,   237,   342,   343,   161,   164,   240,   241,   242,
      96,   170,   210,   232,    97,    98,   153,    37,   215,   154,
     175,    38,    39,    40,   153,   153,   254,   154,   154,   280,
     362,   281,   271,   176,   273,   158,   179,   318,    99,   153,
     153,    12,   154,   154,   182,    13,    14,    15,   158,    16,
     320,   153,   183,   280,   154,   331,   280,   189,   341,   153,
      12,   280,   154,   351,    13,    14,    15,   216,    16,   167,
     190,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   198,   199,   200,   201,   222,   196,
     280,   202,   359,   191,   203,   135,   321,    96,   280,   197,
     360,    97,    98,   192,   193,   204,   329,   330,   198,   199,
     200,   201,   217,   218,   219,   202,   221,   223,   203,   135,
     205,   206,   207,   208,   209,   127,   224,   227,   229,   204,
     235,   236,   198,   199,   200,   201,   238,   245,   246,   202,
     210,   292,   203,   135,   205,   206,   207,   208,   209,   247,
     249,   250,   251,   204,   252,   253,   198,   199,   200,   201,
     269,   270,   272,   202,   210,   323,   203,   135,   205,   206,
     207,   208,   209,   275,   276,   278,   282,   204,   279,   283,
     198,   199,   200,   201,   285,   286,   294,   202,   210,   337,
     203,   135,   205,   206,   207,   208,   209,   290,   291,   298,
     295,   204,   296,   314,   198,   199,   200,   201,   322,   316,
     327,   202,   210,   346,   203,   135,   205,   206,   207,   208,
     209,   133,    12,   325,   134,   204,    13,    14,    15,   328,
      16,   326,   135,   332,   340,   333,   210,   348,   334,   350,
     205,   206,   207,   208,   209,   335,   336,   352,    34,   353,
     133,   358,   361,   134,   363,   137,   138,   364,   366,    62,
     210,   135,   139,   174,   354,   355,   140,   141,   165,   142,
     166,   143,   144,   145,    58,   136,    50,   111,   133,   108,
     220,   134,   231,    79,   137,   138,     0,   128,     0,   135,
       0,   139,     0,     0,     0,   140,   141,     0,   142,     0,
     143,   144,   145,   214,     0,     0,   133,     0,     0,   134,
       0,     0,   137,   138,     0,     0,     0,   135,     0,   139,
       0,     0,     0,   140,   141,     0,   142,     0,   143,   144,
     145,   230,   133,     0,     0,   134,     0,     0,     0,     0,
     137,   138,     0,   135,     0,     0,     0,   139,     0,     0,
       0,   140,   141,     0,   142,     0,   143,   144,   145,     0,
     133,     0,     0,   134,     0,     0,   137,   138,     0,     0,
       0,   135,     0,   139,     0,     0,     0,   140,   141,     0,
     142,   244,   143,   144,   145,   339,   133,     0,     0,   134,
       0,     0,     0,     0,   137,   138,     0,   135,     0,     0,
       0,   139,     0,     0,     0,   140,   141,     0,   142,     0,
     143,   144,   145,   133,     0,     0,   134,     0,     0,     0,
     137,   138,     0,     0,   135,     0,     0,   139,     0,     0,
       0,   140,   141,   356,   142,     0,   143,   144,   145,   133,
       0,     0,   134,     0,     0,     0,     0,   137,   138,     0,
     135,     0,     0,     0,   139,     0,     0,   365,   140,   141,
       0,   142,     0,   143,   144,   145,   133,     0,     0,   134,
       0,     0,     0,   137,   138,     0,     0,   135,     0,     0,
     139,     0,     0,     0,   140,   141,     0,   142,     0,   143,
     144,   145,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,     0,     0,     0,     0,     0,   139,     0,     0,
       0,   243,   141,     0,   142,     0,   143,   144,   145,   255,
     256,   257,   258,   259,     0,   260,   261,   262,   263,   264,
     265,     0,   266,   267,   255,   256,   257,   258,   259,     0,
     260,   261,   262,   263,   264,   265,     0,   266,   267,   255,
     256,   257,   258,   259,     0,   260,   261,   262,   263,   264,
     265,     0,   266,   267,   255,   256,   257,   258,   259,   317,
     260,   261,   262,   263,   264,   265,     0,   266,   267,     0,
       0,     0,   284,     0,     0,   255,   256,   257,   258,   259,
       0,   260,   261,   262,   263,   264,   265,   287,   266,   267,
     255,   256,   257,   258,   259,     0,   260,   261,   262,   263,
     264,   265,   288,   266,   267,   255,   256,   257,   258,   259,
       0,   260,   261,   262,   263,   264,   265,     0,   266,   267,
       0,     0,     0,   289,     0,     0,   255,   256,   257,   258,
     259,     0,   260,   261,   262,   263,   264,   265,   300,   266,
     267,   255,   256,   257,   258,   259,     0,   260,   261,   262,
     263,   264,   265,   344,   266,   267,     0,     0,   268,   255,
     256,   257,   258,   259,     0,   260,   261,   262,   263,   264,
     265,     0,   266,   267,   345,     0,   315,   255,   256,   257,
     258,   259,     0,   260,   261,   262,   263,   264,   265,     0,
     266,   267,   255,   256,   257,   258,   259,     0,   260,   261,
     262,   263,   264,   265,     0,    -1,    -1,   255,   256,   257,
     258,   259,     0,    -1,    -1,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
     103,   125,   146,   103,    71,     9,     4,     3,    77,   116,
       4,    31,   245,     4,     0,     4,     7,   141,   142,    30,
      57,     2,   125,    30,    15,   125,    95,    31,    60,     7,
       8,    35,   135,   177,     4,   135,    34,    18,   141,   142,
      34,   141,   142,   146,     4,    30,   146,    36,    59,   282,
     194,   195,    59,     4,    57,    33,     4,    35,    37,   166,
       8,     9,    10,    41,    12,    50,    36,     4,    30,    60,
      41,     8,     9,    10,   177,    12,     4,   177,    59,    61,
       8,     9,    10,   316,    12,    30,    64,   190,    66,    67,
     190,   194,   195,    64,   194,   195,    67,    59,    33,   332,
      35,   204,    83,   336,   204,    57,    87,    88,   175,    59,
      58,    61,    31,    91,    59,     6,     7,     4,     4,    57,
      91,    58,     8,     9,    10,     4,    12,     4,    15,    60,
      58,    66,    62,   114,     4,   116,     4,     7,    15,   120,
       8,     9,    10,    34,    12,    15,    32,    59,   251,    61,
     253,   251,   276,   253,    60,   224,     4,     5,     6,     7,
     229,   145,    31,    11,    32,     9,    14,    15,     4,     4,
      15,    16,    17,   276,    28,   319,   276,    25,     4,    15,
      15,     4,     8,     9,    10,   166,    12,    31,    59,    33,
      61,    35,    40,    41,    42,    43,    44,    60,   342,   343,
       5,    28,   186,   327,   328,    63,    32,   191,   192,   193,
       4,     4,    60,    61,     8,     9,   319,     4,   362,   319,
      57,     8,     9,    10,   327,   328,   210,   327,   328,    59,
     354,    61,   216,     4,   218,    59,     4,    61,    32,   342,
     343,     4,   342,   343,    60,     8,     9,    10,    59,    12,
      61,   354,    64,    59,   354,    61,    59,    58,    61,   362,
       4,    59,   362,    61,     8,     9,    10,    18,    12,    32,
      60,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,     4,     5,     6,     7,    32,    30,
      59,    11,    61,    60,    14,    15,   280,     4,    59,    30,
      61,     8,     9,    60,    60,    25,   290,   291,     4,     5,
       6,     7,    64,    62,     4,    11,     4,     4,    14,    15,
      40,    41,    42,    43,    44,    32,    60,    30,    60,    25,
       4,    64,     4,     5,     6,     7,    64,    60,    64,    11,
      60,    61,    14,    15,    40,    41,    42,    43,    44,     5,
      60,    60,    60,    25,    60,    60,     4,     5,     6,     7,
      64,    58,     4,    11,    60,    61,    14,    15,    40,    41,
      42,    43,    44,     4,    28,    58,    60,    25,    30,     4,
       4,     5,     6,     7,     4,    61,     4,    11,    60,    61,
      14,    15,    40,    41,    42,    43,    44,    60,    60,     4,
      61,    25,    61,     4,     4,     5,     6,     7,    30,    60,
      46,    11,    60,    61,    14,    15,    40,    41,    42,    43,
      44,     4,     4,    30,     7,    25,     8,     9,    10,    50,
      12,    30,    15,    60,    30,    61,    60,    61,    61,    30,
      40,    41,    42,    43,    44,    61,    60,    58,     7,    30,
       4,    30,    30,     7,    30,    38,    39,    30,    30,    29,
      60,    15,    45,   120,    47,    48,    49,    50,   114,    52,
     114,    54,    55,    56,    24,    29,    18,    83,     4,    81,
     158,     7,   181,    52,    38,    39,    -1,   100,    -1,    15,
      -1,    45,    -1,    -1,    -1,    49,    50,    -1,    52,    -1,
      54,    55,    56,    29,    -1,    -1,     4,    -1,    -1,     7,
      -1,    -1,    38,    39,    -1,    -1,    -1,    15,    -1,    45,
      -1,    -1,    -1,    49,    50,    -1,    52,    -1,    54,    55,
      56,    29,     4,    -1,    -1,     7,    -1,    -1,    -1,    -1,
      38,    39,    -1,    15,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    49,    50,    -1,    52,    -1,    54,    55,    56,    -1,
       4,    -1,    -1,     7,    -1,    -1,    38,    39,    -1,    -1,
      -1,    15,    -1,    45,    -1,    -1,    -1,    49,    50,    -1,
      52,    53,    54,    55,    56,    29,     4,    -1,    -1,     7,
      -1,    -1,    -1,    -1,    38,    39,    -1,    15,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    49,    50,    -1,    52,    -1,
      54,    55,    56,     4,    -1,    -1,     7,    -1,    -1,    -1,
      38,    39,    -1,    -1,    15,    -1,    -1,    45,    -1,    -1,
      -1,    49,    50,    51,    52,    -1,    54,    55,    56,     4,
      -1,    -1,     7,    -1,    -1,    -1,    -1,    38,    39,    -1,
      15,    -1,    -1,    -1,    45,    -1,    -1,    48,    49,    50,
      -1,    52,    -1,    54,    55,    56,     4,    -1,    -1,     7,
      -1,    -1,    -1,    38,    39,    -1,    -1,    15,    -1,    -1,
      45,    -1,    -1,    -1,    49,    50,    -1,    52,    -1,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    49,    50,    -1,    52,    -1,    54,    55,    56,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    13,    14,    15,    16,    17,    63,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    -1,
      -1,    -1,    61,    -1,    -1,    13,    14,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    61,    26,    27,
      13,    14,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    24,    61,    26,    27,    13,    14,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    61,    -1,    -1,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    61,    26,
      27,    13,    14,    15,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    61,    26,    27,    -1,    -1,    30,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    61,    -1,    30,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    31,    33,    35,    66,    67,    82,    89,   104,
     105,     3,     4,     8,     9,    10,    12,    32,    90,    91,
      92,    93,     4,    34,    83,    84,    85,     4,    36,    68,
      69,    70,     0,    89,    67,    89,   104,     4,     8,     9,
      10,    98,    99,   100,   101,   104,    57,    60,     4,    32,
      93,     4,    15,    94,    95,    96,    97,    34,    84,    57,
      37,    36,    69,    57,    98,   104,    89,    98,   104,    99,
     104,    57,     4,    31,   106,    61,    60,    60,     4,    96,
      30,    59,    62,    86,    87,    91,     4,    31,    71,    72,
     104,    98,   104,   104,   106,    60,     4,     8,     9,    32,
     107,   108,   109,    28,    91,   102,   103,   102,    95,     5,
      58,    87,     4,    88,    73,    74,    76,    77,    91,    58,
      79,    80,    81,    91,   104,    28,   102,    32,   108,     4,
      15,   110,   111,     4,     7,    15,    29,    38,    39,    45,
      49,    50,    52,    54,    55,    56,   112,   113,   114,   115,
     116,   117,   118,   121,   122,   123,     4,    15,    59,    61,
      61,    63,    30,    59,    32,    74,    76,    32,    77,    91,
       4,    75,    78,    58,    80,    57,     4,   112,    61,     4,
      30,    59,    60,    64,     4,     7,    60,   121,   122,    58,
      60,    60,    60,    60,   112,   112,    30,    30,     4,     5,
       6,     7,    11,    14,    25,    40,    41,    42,    43,    44,
      60,   119,   121,   122,    29,   113,    18,    64,    62,     4,
     103,     4,    32,     4,    60,    30,    59,    30,   106,    60,
      29,   111,    61,   119,   120,     4,    64,   119,    64,   121,
     119,   119,   119,    49,    53,    60,    64,     5,   121,    60,
      60,    60,    60,    60,   119,    13,    14,    15,    16,    17,
      19,    20,    21,    22,    23,    24,    26,    27,    30,    64,
      58,   119,     4,   119,   102,     4,    28,   102,    58,    30,
      59,    61,    60,     4,    61,     4,    61,    61,    61,    61,
      60,    60,    61,   120,     4,    61,    61,   121,     4,   121,
      61,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,     4,    30,    60,    63,    61,   112,
      61,   119,    30,    61,   120,    30,    30,    46,    50,   119,
     119,    61,    60,    61,    61,    61,    60,    61,   120,    29,
      30,    61,   112,   112,    61,    61,    61,   120,    61,   120,
      30,    61,    58,    30,    47,    48,    51,    30,    30,    61,
      61,    30,   112,    30,    30,    48,    30
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    72,    72,    72,    73,    73,    74,    75,    75,    76,
      76,    77,    78,    79,    79,    80,    81,    82,    82,    83,
      83,    84,    85,    86,    86,    87,    88,    88,    89,    89,
      90,    90,    91,    91,    91,    91,    91,    92,    93,    94,
      94,    95,    95,    96,    96,    97,    97,    98,    98,    99,
     100,   101,   101,   101,   101,   102,   102,   102,   103,   103,
     104,   104,   105,   106,   106,   106,   107,   107,   108,   109,
     109,   109,   110,   110,   111,   111,   112,   112,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   115,   115,   115,   116,   117,   118,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   120,   120,   121,   121,   121,   122,   122,   122,   123,
     123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     4,     3,     4,     3,     2,     3,
       2,     1,     3,     2,     2,     1,     5,     4,     1,     3,
       1,     4,     3,     3,     2,     1,     3,     3,     1,     2,
       1,     3,     4,     2,     1,     7,     5,     3,     2,     2,
       1,     4,     1,     2,     1,     3,     3,     1,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     5,     3,     3,
       1,     1,     4,     2,     1,     4,     1,     2,     1,     7,
       5,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       7,     6,     4,     3,     2,     0,     2,     1,     3,     1,
       1,     1,     3,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     2,     2,     4,     5,     6,     7,     6,
       7,     3,    10,     8,     8,     7,     7,     5,     5,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     2,     1,     1,     3,     4,
       1,     2,     3,     4,     3,     4,     4,     5,     6,     5,
       6,     3,     1,     4,     2,     1,     3,     3,     1,     4,
       1
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
#line 98 "code.y"
                                                                {}
#line 1846 "y.tab.c"
    break;

  case 3:
#line 99 "code.y"
                                                                        {}
#line 1852 "y.tab.c"
    break;

  case 4:
#line 100 "code.y"
                                                                        {}
#line 1858 "y.tab.c"
    break;

  case 5:
#line 101 "code.y"
                                                                        {}
#line 1864 "y.tab.c"
    break;

  case 6:
#line 102 "code.y"
                                                                        {}
#line 1870 "y.tab.c"
    break;

  case 7:
#line 103 "code.y"
                                                                        {}
#line 1876 "y.tab.c"
    break;

  case 8:
#line 104 "code.y"
                                                                        {}
#line 1882 "y.tab.c"
    break;

  case 9:
#line 105 "code.y"
                                                                        {}
#line 1888 "y.tab.c"
    break;

  case 10:
#line 106 "code.y"
                                                                        {}
#line 1894 "y.tab.c"
    break;

  case 11:
#line 107 "code.y"
                                                                        {}
#line 1900 "y.tab.c"
    break;

  case 12:
#line 110 "code.y"
                                                        {/*printClassTable(classTable);printf("CLASS DONE\n");*/}
#line 1906 "y.tab.c"
    break;

  case 13:
#line 111 "code.y"
                                                                {}
#line 1912 "y.tab.c"
    break;

  case 14:
#line 114 "code.y"
                                                        {}
#line 1918 "y.tab.c"
    break;

  case 15:
#line 115 "code.y"
                                                                {}
#line 1924 "y.tab.c"
    break;

  case 16:
#line 118 "code.y"
                                                                                {}
#line 1930 "y.tab.c"
    break;

  case 17:
#line 119 "code.y"
                                                                        {}
#line 1936 "y.tab.c"
    break;

  case 18:
#line 122 "code.y"
                                                                                {	
											currentClass = strdup((yyvsp[0].string));
											addToClassTable(classTable,(yyvsp[0].string),NULL);
										}
#line 1945 "y.tab.c"
    break;

  case 19:
#line 126 "code.y"
                                                                        {	
											currentClass = strdup((yyvsp[-2].string));
											addToClassTable(classTable,(yyvsp[-2].string),(yyvsp[0].string));
										}
#line 1954 "y.tab.c"
    break;

  case 20:
#line 132 "code.y"
                                                                                {	
											getMemLoc(8);
											addDeclToClassEntry(classTable, typeTable, (yyvsp[0].dno), currentClass);

										}
#line 1964 "y.tab.c"
    break;

  case 21:
#line 139 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[-1].dno));}
#line 1970 "y.tab.c"
    break;

  case 22:
#line 140 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode(NULL,(yyvsp[-1].dno));}
#line 1976 "y.tab.c"
    break;

  case 23:
#line 141 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),NULL);}
#line 1982 "y.tab.c"
    break;

  case 24:
#line 144 "code.y"
                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1988 "y.tab.c"
    break;

  case 25:
#line 145 "code.y"
                                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1994 "y.tab.c"
    break;

  case 26:
#line 148 "code.y"
                                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno),typeTable,classTable);}
#line 2000 "y.tab.c"
    break;

  case 27:
#line 151 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),declIdNode((yyvsp[-2].string),0,NULL));}
#line 2006 "y.tab.c"
    break;

  case 28:
#line 152 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2012 "y.tab.c"
    break;

  case 29:
#line 155 "code.y"
                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2018 "y.tab.c"
    break;

  case 30:
#line 156 "code.y"
                                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2024 "y.tab.c"
    break;

  case 31:
#line 159 "code.y"
                                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno),typeTable,classTable);}
#line 2030 "y.tab.c"
    break;

  case 32:
#line 162 "code.y"
                                                                {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 2036 "y.tab.c"
    break;

  case 33:
#line 165 "code.y"
                                                                {}
#line 2042 "y.tab.c"
    break;

  case 34:
#line 166 "code.y"
                                                                {}
#line 2048 "y.tab.c"
    break;

  case 35:
#line 169 "code.y"
                                                                        {
										funcCodeGen((yyvsp[-2].no), fp,(yyvsp[-6].methodList) -> flabel);
										lst = NULL;
									}
#line 2057 "y.tab.c"
    break;

  case 36:
#line 175 "code.y"
                                                        {	
								localMemLoc = 0;
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyMethodHead((yyvsp[-3].string),(yyvsp[-1].pt),TLookup(typeTable,(yyvsp[-4].string)),CLookup(classTable,currentClass));
								
								struct ClassTableEntry* entry = CLookup(classTable,currentClass);
								addMethodParamToLST(lst,(yyvsp[-1].pt),entry);
								(yyval.methodList) = MLookupWithParams(entry -> methodList,(yyvsp[-1].pt),(yyvsp[-3].string));
							}
#line 2071 "y.tab.c"
    break;

  case 37:
#line 186 "code.y"
                                                        {/*printf("TYPE DONE\n");*/}
#line 2077 "y.tab.c"
    break;

  case 38:
#line 187 "code.y"
                                                        {}
#line 2083 "y.tab.c"
    break;

  case 39:
#line 190 "code.y"
                                                        {}
#line 2089 "y.tab.c"
    break;

  case 40:
#line 191 "code.y"
                                                {}
#line 2095 "y.tab.c"
    break;

  case 41:
#line 194 "code.y"
                                                {addUserDefToTypeTable(typeTable,(yyvsp[-1].dno),(yyvsp[-3].string));}
#line 2101 "y.tab.c"
    break;

  case 42:
#line 197 "code.y"
                                                {createTypeEntry(typeTable, (yyvsp[0].string));}
#line 2107 "y.tab.c"
    break;

  case 43:
#line 200 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2113 "y.tab.c"
    break;

  case 44:
#line 201 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2119 "y.tab.c"
    break;

  case 45:
#line 204 "code.y"
                                                        {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno),typeTable,classTable);}
#line 2125 "y.tab.c"
    break;

  case 46:
#line 207 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),declIdNode((yyvsp[-2].string),0,NULL));}
#line 2131 "y.tab.c"
    break;

  case 47:
#line 208 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2137 "y.tab.c"
    break;

  case 48:
#line 212 "code.y"
                                        {	
						gst = (struct GSymbolTable*)malloc(sizeof(struct GSymbolTable));
						generateGlobalSymbolTable(gst,(yyvsp[-1].dno),NULL,NULL,typeTable,classTable);
						startCodeGen(fp,memLoc,gst,classTable);
						//printGlobalSymbolTable(gst);
					}
#line 2148 "y.tab.c"
    break;

  case 49:
#line 218 "code.y"
                                        {gst = NULL;}
#line 2154 "y.tab.c"
    break;

  case 50:
#line 221 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2160 "y.tab.c"
    break;

  case 51:
#line 222 "code.y"
                                {(yyval.dno) = (yyvsp[0].dno);}
#line 2166 "y.tab.c"
    break;

  case 52:
#line 225 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2172 "y.tab.c"
    break;

  case 53:
#line 226 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2178 "y.tab.c"
    break;

  case 54:
#line 227 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2184 "y.tab.c"
    break;

  case 55:
#line 228 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2190 "y.tab.c"
    break;

  case 56:
#line 229 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2196 "y.tab.c"
    break;

  case 57:
#line 232 "code.y"
                                        {addTupleToTypeTable(typeTable,(yyvsp[-1].pt),(yyvsp[-3].string));(yyval.string) = (yyvsp[-3].string);}
#line 2202 "y.tab.c"
    break;

  case 58:
#line 235 "code.y"
                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno),typeTable,classTable);}
#line 2208 "y.tab.c"
    break;

  case 59:
#line 238 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 2214 "y.tab.c"
    break;

  case 60:
#line 239 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2220 "y.tab.c"
    break;

  case 61:
#line 242 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2226 "y.tab.c"
    break;

  case 62:
#line 243 "code.y"
                                                        {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 2232 "y.tab.c"
    break;

  case 63:
#line 246 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].dno) -> varname,(yyvsp[0].dno) -> dim + 1,(yyvsp[0].dno) -> shape);}
#line 2238 "y.tab.c"
    break;

  case 64:
#line 247 "code.y"
                                                {(yyval.dno) = (yyvsp[0].dno);}
#line 2244 "y.tab.c"
    break;

  case 65:
#line 250 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[-3].dno) -> varname,(yyvsp[-3].dno) -> dim + 1,addArrayShape((yyvsp[-3].dno) -> shape,(yyvsp[-1].number)));}
#line 2250 "y.tab.c"
    break;

  case 66:
#line 251 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2256 "y.tab.c"
    break;

  case 67:
#line 254 "code.y"
                                                        {}
#line 2262 "y.tab.c"
    break;

  case 68:
#line 255 "code.y"
                                                        {}
#line 2268 "y.tab.c"
    break;

  case 69:
#line 258 "code.y"
                                                        {	
									struct Gsymbol* g = GlobalLookup(gst,(yyvsp[-6].string));
									funcCodeGen((yyvsp[-2].no), fp,g -> flabel);
									lst = NULL;
								}
#line 2278 "y.tab.c"
    break;

  case 70:
#line 265 "code.y"
                                                                {
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyFuncHead(gst,(yyvsp[-3].string),TLookup(typeTable,(yyvsp[-4].string)),CLookup(classTable,(yyvsp[-4].string)),(yyvsp[-1].pt));
								addParamToLST(lst,(yyvsp[-1].pt));
								(yyval.string) = (yyvsp[-3].string);
							}
#line 2289 "y.tab.c"
    break;

  case 71:
#line 273 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2295 "y.tab.c"
    break;

  case 72:
#line 274 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2301 "y.tab.c"
    break;

  case 73:
#line 275 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2307 "y.tab.c"
    break;

  case 74:
#line 276 "code.y"
                                        {verifyFuncRetType((yyvsp[0].string),classTable);
					(yyval.string) = (yyvsp[0].string);}
#line 2314 "y.tab.c"
    break;

  case 75:
#line 280 "code.y"
                                                {(yyval.pt) = addParameter((yyvsp[-2].pt),(yyvsp[0].pt));}
#line 2320 "y.tab.c"
    break;

  case 76:
#line 281 "code.y"
                                                {(yyval.pt) = (yyvsp[0].pt);}
#line 2326 "y.tab.c"
    break;

  case 77:
#line 282 "code.y"
                                                        {(yyval.pt) = NULL;}
#line 2332 "y.tab.c"
    break;

  case 78:
#line 285 "code.y"
                                                {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-1].string),0,typeTable,classTable);}
#line 2338 "y.tab.c"
    break;

  case 79:
#line 286 "code.y"
                                                        {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-2].string),1,typeTable,classTable);}
#line 2344 "y.tab.c"
    break;

  case 80:
#line 289 "code.y"
                                                                {	
									if(gst == NULL){
										startCodeGen(fp,-1,gst,classTable);	
										fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
									}
									funcCodeGen((yyvsp[-2].no), fp,-1);}
#line 2355 "y.tab.c"
    break;

  case 81:
#line 295 "code.y"
                                                                {exit(0);}
#line 2361 "y.tab.c"
    break;

  case 82:
#line 298 "code.y"
                                {lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));}
#line 2367 "y.tab.c"
    break;

  case 83:
#line 303 "code.y"
                                        {localMemLoc = 0; addLocalVarToLST(lst,(yyvsp[-1].dno),NULL,NULL,typeTable,classTable);}
#line 2373 "y.tab.c"
    break;

  case 84:
#line 304 "code.y"
                                        {(yyval.dno) = NULL;}
#line 2379 "y.tab.c"
    break;

  case 85:
#line 305 "code.y"
                                        {(yyval.dno) = NULL;}
#line 2385 "y.tab.c"
    break;

  case 86:
#line 308 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2391 "y.tab.c"
    break;

  case 87:
#line 309 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2397 "y.tab.c"
    break;

  case 88:
#line 312 "code.y"
                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno),typeTable,classTable);}
#line 2403 "y.tab.c"
    break;

  case 89:
#line 315 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2409 "y.tab.c"
    break;

  case 90:
#line 316 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2415 "y.tab.c"
    break;

  case 91:
#line 317 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2421 "y.tab.c"
    break;

  case 92:
#line 320 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 2427 "y.tab.c"
    break;

  case 93:
#line 321 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2433 "y.tab.c"
    break;

  case 94:
#line 325 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2439 "y.tab.c"
    break;

  case 95:
#line 326 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),1,NULL);}
#line 2445 "y.tab.c"
    break;

  case 96:
#line 332 "code.y"
                                                                        {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 2451 "y.tab.c"
    break;

  case 97:
#line 333 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2457 "y.tab.c"
    break;

  case 98:
#line 336 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2463 "y.tab.c"
    break;

  case 99:
#line 337 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2469 "y.tab.c"
    break;

  case 100:
#line 338 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2475 "y.tab.c"
    break;

  case 101:
#line 339 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2481 "y.tab.c"
    break;

  case 102:
#line 340 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2487 "y.tab.c"
    break;

  case 103:
#line 341 "code.y"
                                                                {(yyval.no) = makeJumpNode(break_node);}
#line 2493 "y.tab.c"
    break;

  case 104:
#line 342 "code.y"
                                                                        {(yyval.no) = makeJumpNode(continue_node);}
#line 2499 "y.tab.c"
    break;

  case 105:
#line 343 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,NULL);}
#line 2505 "y.tab.c"
    break;

  case 106:
#line 344 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-4].string),gst,(yyvsp[-2].at));}
#line 2511 "y.tab.c"
    break;

  case 107:
#line 345 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-5].no),(yyvsp[-3].string),NULL,typeTable);}
#line 2517 "y.tab.c"
    break;

  case 108:
#line 346 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-6].no),(yyvsp[-4].string),(yyvsp[-2].at),typeTable);}
#line 2523 "y.tab.c"
    break;

  case 109:
#line 347 "code.y"
                                                                        {(yyval.no) = makeMethodNode(makeIdNode((yyvsp[-5].string),gst,lst,NULL,typeTable,classTable),(yyvsp[-3].string),NULL,typeTable);}
#line 2529 "y.tab.c"
    break;

  case 110:
#line 348 "code.y"
                                                                        {(yyval.no) = makeMethodNode(makeIdNode((yyvsp[-6].string),gst,lst,NULL,typeTable,classTable),(yyvsp[-4].string),(yyvsp[-2].at),typeTable);}
#line 2535 "y.tab.c"
    break;

  case 111:
#line 349 "code.y"
                                                                        {(yyval.no) = makeReturnNode((yyvsp[-1].no));}
#line 2541 "y.tab.c"
    break;

  case 112:
#line 352 "code.y"
                                                                {(yyval.no) = makeIfElseBlock((yyvsp[-7].no),(yyvsp[-4].no),(yyvsp[-2].no));}
#line 2547 "y.tab.c"
    break;

  case 113:
#line 353 "code.y"
                                                                        {(yyval.no) = makeIfElseBlock((yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 2553 "y.tab.c"
    break;

  case 114:
#line 356 "code.y"
                                                                {(yyval.no) = makeWhileBlock((yyvsp[-5].no),(yyvsp[-2].no));}
#line 2559 "y.tab.c"
    break;

  case 115:
#line 357 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 2565 "y.tab.c"
    break;

  case 116:
#line 358 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 2571 "y.tab.c"
    break;

  case 117:
#line 361 "code.y"
                                                                        {(yyval.no) = makeReadNode((yyvsp[-2].no));}
#line 2577 "y.tab.c"
    break;

  case 118:
#line 364 "code.y"
                                                                {(yyval.no) = makeWriteNode((yyvsp[-2].no));}
#line 2583 "y.tab.c"
    break;

  case 119:
#line 367 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(assign,(yyvsp[-3].no),(yyvsp[-1].no),typeTable);}
#line 2589 "y.tab.c"
    break;

  case 120:
#line 370 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(add,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2595 "y.tab.c"
    break;

  case 121:
#line 371 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(sub,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2601 "y.tab.c"
    break;

  case 122:
#line 372 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(mul,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2607 "y.tab.c"
    break;

  case 123:
#line 373 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(div,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2613 "y.tab.c"
    break;

  case 124:
#line 374 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(mod,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2619 "y.tab.c"
    break;

  case 125:
#line 375 "code.y"
                                                                {(yyval.no) = makeOperatorNode(gt,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2625 "y.tab.c"
    break;

  case 126:
#line 376 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(gte,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2631 "y.tab.c"
    break;

  case 127:
#line 377 "code.y"
                                                                {(yyval.no) = makeOperatorNode(lt,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2637 "y.tab.c"
    break;

  case 128:
#line 378 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(lte,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2643 "y.tab.c"
    break;

  case 129:
#line 379 "code.y"
                                                                {(yyval.no) = makeOperatorNode(eq,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2649 "y.tab.c"
    break;

  case 130:
#line 380 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(neq,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2655 "y.tab.c"
    break;

  case 131:
#line 381 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(and,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2661 "y.tab.c"
    break;

  case 132:
#line 382 "code.y"
                                                                {(yyval.no) = makeOperatorNode(or,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2667 "y.tab.c"
    break;

  case 133:
#line 383 "code.y"
                                                                {(yyval.no) = (yyvsp[-1].no);}
#line 2673 "y.tab.c"
    break;

  case 134:
#line 384 "code.y"
                                                                        {(yyval.no) = makeNumNode((yyvsp[0].number),0,typeTable);}
#line 2679 "y.tab.c"
    break;

  case 135:
#line 385 "code.y"
                                                                        {(yyval.no) = makeNumNode(-1 * (yyvsp[0].number),0,typeTable);}
#line 2685 "y.tab.c"
    break;

  case 136:
#line 386 "code.y"
                                                                        {(yyval.no) = makeStringNode((yyvsp[0].string),typeTable);}
#line 2691 "y.tab.c"
    break;

  case 137:
#line 387 "code.y"
                                                                        {(yyval.no) = makeNullNode(typeTable);}
#line 2697 "y.tab.c"
    break;

  case 138:
#line 388 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-2].string),gst,NULL);}
#line 2703 "y.tab.c"
    break;

  case 139:
#line 389 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,(yyvsp[-1].at));}
#line 2709 "y.tab.c"
    break;

  case 140:
#line 390 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2715 "y.tab.c"
    break;

  case 141:
#line 391 "code.y"
                                                                        {(yyval.no) = makeAddrNode((yyvsp[0].no),gst,lst,typeTable);}
#line 2721 "y.tab.c"
    break;

  case 142:
#line 392 "code.y"
                                                                        {(yyval.no) = makeTypeAllocNode();}
#line 2727 "y.tab.c"
    break;

  case 143:
#line 393 "code.y"
                                                                        {(yyval.no) = makeClassAllocNode((yyvsp[-1].string),classTable);}
#line 2733 "y.tab.c"
    break;

  case 144:
#line 394 "code.y"
                                                                        {(yyval.no) = makeMemInitNode(typeTable);}
#line 2739 "y.tab.c"
    break;

  case 145:
#line 395 "code.y"
                                                                        {(yyval.no) = makeFreeNode((yyvsp[-1].no),typeTable);}
#line 2745 "y.tab.c"
    break;

  case 146:
#line 396 "code.y"
                                                                        {(yyval.no) = makeDeleteNode((yyvsp[-1].no),typeTable);}
#line 2751 "y.tab.c"
    break;

  case 147:
#line 397 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-4].no),(yyvsp[-2].string),NULL,typeTable);}
#line 2757 "y.tab.c"
    break;

  case 148:
#line 398 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-5].no),(yyvsp[-3].string),(yyvsp[-1].at),typeTable);}
#line 2763 "y.tab.c"
    break;

  case 149:
#line 399 "code.y"
                                                                        {(yyval.no) = makeMethodNode(makeIdNode((yyvsp[-4].string),gst,lst,NULL,typeTable,classTable),(yyvsp[-2].string),NULL,typeTable);}
#line 2769 "y.tab.c"
    break;

  case 150:
#line 400 "code.y"
                                                                {(yyval.no) = makeMethodNode(makeIdNode((yyvsp[-5].string),gst,lst,NULL,typeTable,classTable),(yyvsp[-3].string),(yyvsp[-1].at),typeTable);}
#line 2775 "y.tab.c"
    break;

  case 151:
#line 403 "code.y"
                                        {(yyval.at) = addArguments((yyvsp[-2].at),makeArgStruct((yyvsp[0].no)),typeTable);}
#line 2781 "y.tab.c"
    break;

  case 152:
#line 404 "code.y"
                                        {(yyval.at) = makeArgStruct((yyvsp[0].no));}
#line 2787 "y.tab.c"
    break;

  case 153:
#line 407 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[-1].no),typeTable);}
#line 2793 "y.tab.c"
    break;

  case 154:
#line 408 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[0].no),typeTable);}
#line 2799 "y.tab.c"
    break;

  case 155:
#line 409 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2805 "y.tab.c"
    break;

  case 156:
#line 412 "code.y"
                                                {(yyval.no) = extendTypeNode((yyvsp[-2].no),(yyvsp[0].string),typeTable);}
#line 2811 "y.tab.c"
    break;

  case 157:
#line 413 "code.y"
                                                {(yyval.no) = extendClassNode(makeIdNode((yyvsp[-2].string),gst,lst,NULL,typeTable,classTable),(yyvsp[0].string),classTable);}
#line 2817 "y.tab.c"
    break;

  case 158:
#line 414 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2823 "y.tab.c"
    break;

  case 159:
#line 417 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[-3].no) -> varname,gst,lst,addArrayDim((yyvsp[-3].no) -> indices,(yyvsp[-1].no)),typeTable,classTable);}
#line 2829 "y.tab.c"
    break;

  case 160:
#line 418 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[0].string),gst,lst,NULL,typeTable,classTable);}
#line 2835 "y.tab.c"
    break;


#line 2839 "y.tab.c"

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
#line 421 "code.y"


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

void verifyFuncRetType(char* type,struct ClassTable* classTable){
	struct ClassTableEntry* entry = CLookup(classTable,type);
	if(entry != NULL){
		printf("Error: Return Type cannot be a class");
		exit(0);
	}
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
			while(func_num <= 8){
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
