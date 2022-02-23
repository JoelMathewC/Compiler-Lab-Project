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
	#include "functions/symbolTableFunc.h"
	
	#include "functions/dNodeFunc.c"
	#include "functions/tNodeFunc.c"
	#include "functions/paramStructFunc.c"
	#include "functions/labelAddrTableFunc.c"
	#include "functions/loopStackFunc.c"
	#include "functions/typeTableFunc.c"
	#include "functions/symbolTableFunc.c"
	#include "backend/globalVar.c"
	
	#include "backend/code_gen.h"
	#include "backend/code_gen.c"
	
	struct GSymbolTable* gst;
	struct LSymbolTable* lst;
	struct TypeTable* typeTable;
	FILE* startCodeGen(int memLoc, struct GSymbolTable* gst);
	void endCodeGen(FILE *fp);
	void setMemLocationValues(struct GSymbolTable* gst,FILE* fp);
	FILE *fp;

#line 118 "y.tab.c"

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
	

#line 279 "y.tab.c"

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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   587

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  249

#define YYUNDEFTOK  2
#define YYMAXUTOK   304


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
      53,    54,     2,     2,    52,     2,    57,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,    87,    88,    89,    90,    91,    94,    95,
      98,    99,   102,   105,   106,   109,   112,   113,   117,   123,
     126,   127,   130,   131,   132,   133,   136,   139,   140,   143,
     144,   147,   148,   151,   152,   155,   156,   159,   166,   174,
     175,   176,   179,   180,   183,   189,   192,   197,   198,   199,
     202,   203,   206,   209,   210,   214,   215,   221,   222,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   237,
     238,   241,   242,   243,   246,   249,   252,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   282,   283,   286,   287,   288,   289,   292,   293,
     296,   297
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "ID", "NUM", "STRING", "STR",
  "INT", "VOID", "NULL_TYPE", "PLUS", "MINUS", "STAR", "DIV", "MOD",
  "ASSIGN", "GT", "GTE", "LT", "LTE", "EQ", "NEQ", "ADDR", "AND", "OR",
  "START", "END", "ENDSTMT", "DECL", "ENDDECL", "TYPE", "ENDTYPE", "READ",
  "WRITE", "ALLOC", "INITIALIZE", "FREE", "IF", "THEN", "ELSE", "ENDIF",
  "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL", "BREAK", "CONTINUE",
  "RETURN", "'{'", "'}'", "','", "'('", "')'", "'['", "']'", "'.'",
  "$accept", "program", "GtypeBlock", "GtypeList", "Gtype",
  "GtypeDeclList", "GtypeDecl", "GtypeIdList", "GdeclBlock", "GdeclList",
  "Type", "Gdecl", "GidList", "Gid", "IdentifierDecl", "IdArrDecl",
  "FdefBlock", "Fdef", "FName", "ParamList", "Param", "MainBlock",
  "MainHeader", "LdeclBlock", "LdeclList", "Ldecl", "LidList", "Lid",
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
     123,   125,    44,    40,    41,    91,    93,    46
};
# endif

#define YYPACT_NINF (-98)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     150,    19,    75,    -3,     9,    31,   179,   -98,   -36,   -13,
     -98,   -98,   -98,   -98,   -98,   105,    74,   -98,   -18,   -98,
      12,   -98,   -98,   179,   -98,    19,    47,   179,   -98,     2,
     -98,    26,     4,   -98,   -98,    15,    77,   -21,   -98,   -98,
      25,   224,   -98,   -98,   179,   -98,    35,   -98,   -98,    26,
     192,    69,   -98,   224,   -98,   -98,   -98,    74,   110,    34,
     -98,   112,   -98,   224,   111,   -98,   107,   278,   -98,   202,
     132,    67,   -98,   -98,    88,   -98,   -98,   -98,    58,   102,
     324,   -98,   153,    66,   -98,   -98,   -98,   115,    11,   118,
     121,   127,   141,   144,   324,   324,   170,   174,   172,   226,
     -98,   -98,   -98,   -98,   -98,   -98,   187,   147,   108,   -98,
     201,   224,   -98,   -98,   -98,   222,   -98,   250,   -98,   -98,
     107,     0,   -98,   172,   -98,   -98,   151,   172,   172,   172,
     347,   268,   -98,   -98,   181,   -98,   -98,   -98,   232,   151,
     185,   203,   204,   172,   494,   -98,   176,   -98,   172,   238,
     172,   248,   -98,   -98,   -98,   207,   -98,   233,   535,   189,
     386,   208,   401,   417,   432,   212,   213,   136,   -98,   -98,
     216,   225,   151,   448,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   -98,   -98,   517,
     -98,   199,   -98,   -98,   -98,   172,   239,   -98,   252,   261,
     237,   235,   172,   172,   -98,   194,   -98,   -98,   236,   -98,
     178,   178,   -98,   -98,   -98,   565,   565,   565,   565,   565,
     565,   550,   550,   -98,   -98,   535,   -98,   -98,   -98,   324,
     324,   463,   479,   -98,   -98,    59,   287,    46,   266,   324,
     275,   276,   -98,   -98,   305,   -98,   -98,   277,   -98
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     7,     0,     0,
      25,    23,    22,    24,    19,     0,     0,    21,     0,     9,
       0,    11,     1,     0,     4,    22,     0,     0,    36,     0,
       6,    49,     0,    18,    20,    34,     0,     0,    28,    29,
      32,     0,     8,    10,     0,     3,     0,    35,     5,    49,
       0,     0,    46,    41,    34,    31,    26,     0,     0,     0,
      14,     0,     2,    41,     0,    48,     0,     0,    51,     0,
       0,     0,    40,    27,     0,    12,    13,    17,     0,     0,
       0,    55,     0,     0,    54,    47,    50,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    62,    63,    59,    60,    61,     0,   107,   104,    42,
       0,     0,    30,    33,    15,     0,    38,     0,    56,    52,
       0,     0,   111,     0,   106,    45,     0,     0,     0,     0,
       0,     0,    64,    65,   111,    91,    93,    94,     0,     0,
       0,     0,     0,     0,     0,    97,     0,    57,     0,     0,
       0,     0,    43,    39,    16,     0,    53,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,    44,     0,
     108,     0,   109,    37,    66,     0,     0,   105,     0,     0,
       0,     0,     0,     0,    95,     0,    99,   100,     0,    90,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    76,   110,   102,    67,    74,    75,     0,
       0,     0,     0,    96,   101,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,    70,    71,     0,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,   -98,   -98,   292,   -98,   260,   -98,   291,   -98,
       6,   307,   -98,   267,   271,   -98,   300,    23,   -98,   263,
     229,    22,   -98,   284,   -98,   274,   -98,   241,   -77,   -97,
     -98,   -98,   -98,   -98,   -98,   -52,   160,   -69,   -98,   -98
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    20,    21,    59,    60,    78,     6,    15,
      26,    17,    37,    38,    39,    40,    27,    28,    29,    71,
      72,     7,     8,    51,    67,    68,    83,    84,    99,   100,
     101,   102,   103,   104,   105,   158,   159,   145,   107,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     106,    18,   147,   117,   134,   135,   136,    56,    16,    22,
     137,   106,   138,    88,    31,   122,    18,   130,   131,   124,
     147,    16,     9,   139,    88,   106,   106,    24,    30,    19,
     106,    57,    41,   147,   147,   140,   141,   142,    10,     1,
      32,    11,    12,    13,    42,    45,   144,    61,   106,    48,
      47,    46,    49,   143,   157,    50,    66,   161,    52,    70,
       2,   106,   106,    87,   123,    61,    62,    47,    53,    70,
     169,   160,    88,    66,   242,   162,   163,   164,    35,    10,
      58,    54,    11,    12,    13,    75,   114,    36,    63,   230,
      36,   173,    90,    91,   119,    69,   189,    92,   191,   239,
     240,    93,    94,   208,    95,    14,    96,    97,    98,    10,
     115,    81,    11,    12,    13,    74,    77,    70,   120,   111,
      82,   112,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    33,   109,    80,   147,   147,
     134,   135,   136,   225,   113,   110,   137,   147,   138,    88,
     231,   232,   235,   236,   111,   122,   116,   118,     1,   139,
     106,   106,   244,   150,    88,   151,   106,   106,   121,   125,
     106,   140,   141,   142,   126,   106,   134,   135,   136,     2,
     127,     3,   137,    10,   138,    88,    11,    25,    13,   143,
     204,   176,   177,   178,   128,   139,    10,   129,   132,    11,
      12,    13,   133,   148,   149,   152,    87,   140,   141,   142,
     174,   175,   176,   177,   178,    88,   179,   180,   181,   182,
     183,   184,    65,   185,   186,   143,   154,   188,    10,    89,
      87,    11,    12,    13,   167,    90,    91,   168,   170,    88,
      92,   195,   190,   196,    93,    94,   195,    95,   233,    96,
      97,    98,   192,   146,    87,   224,   171,   172,   193,    90,
      91,   194,   198,    88,    92,   202,   203,   226,    93,    94,
     206,    95,    87,    96,    97,    98,   229,   155,   230,   207,
     227,    88,    10,    90,    91,    11,    12,    13,    92,   228,
     234,    87,    93,    94,   243,    95,    23,    96,    97,    98,
      88,    90,    91,   245,   246,   248,    92,    55,    85,    87,
      93,    94,    43,    95,   166,    96,    97,    98,    88,    76,
      90,    91,    34,    44,    73,    92,    79,   205,    87,    93,
      94,   241,    95,    64,    96,    97,    98,    88,    90,    91,
     153,    86,     0,    92,     0,     0,   247,    93,    94,     0,
      95,    87,    96,    97,    98,     0,     0,    90,    91,     0,
      88,   156,    92,     0,     0,     0,    93,    94,     0,    95,
       0,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      90,    91,     0,     0,     0,    92,     0,     0,     0,   165,
      94,     0,    95,     0,    96,    97,    98,   174,   175,   176,
     177,   178,     0,   179,   180,   181,   182,   183,   184,     0,
     185,   186,   174,   175,   176,   177,   178,     0,   179,   180,
     181,   182,   183,   184,     0,   185,   186,     0,   174,   175,
     176,   177,   178,     0,   179,   180,   181,   182,   183,   184,
     197,   185,   186,   174,   175,   176,   177,   178,     0,   179,
     180,   181,   182,   183,   184,   199,   185,   186,     0,   174,
     175,   176,   177,   178,     0,   179,   180,   181,   182,   183,
     184,   200,   185,   186,   174,   175,   176,   177,   178,     0,
     179,   180,   181,   182,   183,   184,   201,   185,   186,     0,
     174,   175,   176,   177,   178,     0,   179,   180,   181,   182,
     183,   184,   209,   185,   186,   174,   175,   176,   177,   178,
       0,   179,   180,   181,   182,   183,   184,   237,   185,   186,
       0,     0,   187,     0,     0,     0,     0,     0,   174,   175,
     176,   177,   178,   238,   179,   180,   181,   182,   183,   184,
       0,   185,   186,     0,     0,   223,   174,   175,   176,   177,
     178,     0,   179,   180,   181,   182,   183,   184,     0,   185,
     186,   174,   175,   176,   177,   178,     0,   179,   180,   181,
     182,   183,   184,     0,    -1,    -1,   174,   175,   176,   177,
     178,     0,    -1,    -1,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      69,     4,    99,    80,     4,     5,     6,    28,     2,     0,
      10,    80,    12,    13,    50,     4,     4,    94,    95,    88,
     117,    15,     3,    23,    13,    94,    95,     5,     6,    32,
      99,    52,    50,   130,   131,    35,    36,    37,     4,     8,
      53,     7,     8,     9,    32,    23,    98,    41,   117,    27,
      27,     4,    50,    53,    54,    29,    50,   126,    54,    53,
      29,   130,   131,     4,    53,    59,    44,    44,    53,    63,
     139,   123,    13,    67,    28,   127,   128,   129,     4,     4,
      55,     4,     7,     8,     9,    51,    28,    13,    53,    43,
      13,   143,    33,    34,    28,    26,   148,    38,   150,    40,
      41,    42,    43,   172,    45,    30,    47,    48,    49,     4,
      52,     4,     7,     8,     9,     5,     4,   111,    52,    52,
      13,    54,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    30,     4,    26,   235,   236,
       4,     5,     6,   195,    56,    13,    10,   244,    12,    13,
     202,   203,   229,   230,    52,     4,    54,     4,     8,    23,
     229,   230,   239,    55,    13,    57,   235,   236,    53,    51,
     239,    35,    36,    37,    53,   244,     4,     5,     6,    29,
      53,    31,    10,     4,    12,    13,     7,     8,     9,    53,
      54,    13,    14,    15,    53,    23,     4,    53,    28,     7,
       8,     9,    28,    16,    57,     4,     4,    35,    36,    37,
      11,    12,    13,    14,    15,    13,    17,    18,    19,    20,
      21,    22,    30,    24,    25,    53,     4,    51,     4,    27,
       4,     7,     8,     9,    53,    33,    34,     5,    53,    13,
      38,    52,     4,    54,    42,    43,    52,    45,    54,    47,
      48,    49,     4,    27,     4,    56,    53,    53,    51,    33,
      34,    28,    54,    13,    38,    53,    53,    28,    42,    43,
      54,    45,     4,    47,    48,    49,    39,    27,    43,    54,
      28,    13,     4,    33,    34,     7,     8,     9,    38,    28,
      54,     4,    42,    43,    28,    45,     5,    47,    48,    49,
      13,    33,    34,    28,    28,    28,    38,    36,    30,     4,
      42,    43,    20,    45,    46,    47,    48,    49,    13,    59,
      33,    34,    15,    23,    57,    38,    63,   167,     4,    42,
      43,    44,    45,    49,    47,    48,    49,    13,    33,    34,
     111,    67,    -1,    38,    -1,    -1,    41,    42,    43,    -1,
      45,     4,    47,    48,    49,    -1,    -1,    33,    34,    -1,
      13,   120,    38,    -1,    -1,    -1,    42,    43,    -1,    45,
      -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,
      43,    -1,    45,    -1,    47,    48,    49,    11,    12,    13,
      14,    15,    -1,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    21,    22,    -1,    24,    25,    -1,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    21,    22,
      54,    24,    25,    11,    12,    13,    14,    15,    -1,    17,
      18,    19,    20,    21,    22,    54,    24,    25,    -1,    11,
      12,    13,    14,    15,    -1,    17,    18,    19,    20,    21,
      22,    54,    24,    25,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    21,    22,    54,    24,    25,    -1,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      21,    22,    54,    24,    25,    11,    12,    13,    14,    15,
      -1,    17,    18,    19,    20,    21,    22,    54,    24,    25,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    54,    17,    18,    19,    20,    21,    22,
      -1,    24,    25,    -1,    -1,    28,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    21,    22,    -1,    24,
      25,    11,    12,    13,    14,    15,    -1,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    21,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    29,    31,    59,    60,    66,    79,    80,     3,
       4,     7,     8,     9,    30,    67,    68,    69,     4,    32,
      61,    62,     0,    66,    79,     8,    68,    74,    75,    76,
      79,    50,    53,    30,    69,     4,    13,    70,    71,    72,
      73,    50,    32,    62,    74,    79,     4,    75,    79,    50,
      29,    81,    54,    53,     4,    72,    28,    52,    55,    63,
      64,    68,    79,    53,    81,    30,    68,    82,    83,    26,
      68,    77,    78,    71,     5,    51,    64,     4,    65,    77,
      26,     4,    13,    84,    85,    30,    83,     4,    13,    27,
      33,    34,    38,    42,    43,    45,    47,    48,    49,    86,
      87,    88,    89,    90,    91,    92,    95,    96,    97,     4,
      13,    52,    54,    56,    28,    52,    54,    86,     4,    28,
      52,    53,     4,    53,    95,    51,    53,    53,    53,    53,
      86,    86,    28,    28,     4,     5,     6,    10,    12,    23,
      35,    36,    37,    53,    93,    95,    27,    87,    16,    57,
      55,    57,     4,    78,     4,    27,    85,    54,    93,    94,
      93,    95,    93,    93,    93,    42,    46,    53,     5,    95,
      53,    53,    53,    93,    11,    12,    13,    14,    15,    17,
      18,    19,    20,    21,    22,    24,    25,    28,    51,    93,
       4,    93,     4,    51,    28,    52,    54,    54,    54,    54,
      54,    54,    53,    53,    54,    94,    54,    54,    95,    54,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    28,    56,    93,    28,    28,    28,    39,
      43,    93,    93,    54,    54,    86,    86,    54,    54,    40,
      41,    44,    28,    28,    86,    28,    28,    41,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    62,    63,    63,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    68,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    74,    74,    75,    76,    77,
      77,    77,    78,    78,    79,    79,    80,    81,    81,    81,
      82,    82,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    88,
      88,    89,    89,    89,    90,    91,    92,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    94,    94,    95,    95,    95,    95,    96,    96,
      97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     1,     3,     2,
       2,     1,     4,     2,     1,     3,     3,     1,     3,     2,
       2,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       4,     2,     1,     4,     1,     2,     1,     7,     5,     3,
       1,     0,     2,     3,     7,     6,     4,     3,     2,     0,
       2,     1,     3,     3,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     4,     5,     3,    10,
       8,     8,     7,     7,     5,     5,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     1,     1,     3,     4,     1,     2,     3,
       3,     4,     3,     1,     1,     4,     2,     1,     3,     3,
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
#line 86 "code.y"
                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1690 "y.tab.c"
    break;

  case 3:
#line 87 "code.y"
                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1696 "y.tab.c"
    break;

  case 4:
#line 88 "code.y"
                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1702 "y.tab.c"
    break;

  case 5:
#line 89 "code.y"
                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1708 "y.tab.c"
    break;

  case 6:
#line 90 "code.y"
                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1714 "y.tab.c"
    break;

  case 7:
#line 91 "code.y"
                                                        {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1720 "y.tab.c"
    break;

  case 8:
#line 94 "code.y"
                                                        {/*printTypeTable(typeTable);*/}
#line 1726 "y.tab.c"
    break;

  case 9:
#line 95 "code.y"
                                                        {}
#line 1732 "y.tab.c"
    break;

  case 10:
#line 98 "code.y"
                                                        {}
#line 1738 "y.tab.c"
    break;

  case 11:
#line 99 "code.y"
                                                {}
#line 1744 "y.tab.c"
    break;

  case 12:
#line 102 "code.y"
                                                        {addToTypeTable(typeTable,(yyvsp[-1].dno),(yyvsp[-3].string));}
#line 1750 "y.tab.c"
    break;

  case 13:
#line 105 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1756 "y.tab.c"
    break;

  case 14:
#line 106 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1762 "y.tab.c"
    break;

  case 15:
#line 109 "code.y"
                                                        {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 1768 "y.tab.c"
    break;

  case 16:
#line 112 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),declIdNode((yyvsp[-2].string),0,NULL));}
#line 1774 "y.tab.c"
    break;

  case 17:
#line 113 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 1780 "y.tab.c"
    break;

  case 18:
#line 117 "code.y"
                                        {	
						gst = (struct GSymbolTable*)malloc(sizeof(struct GSymbolTable));
						generateGlobalSymbolTable(gst,(yyvsp[-1].dno),NULL,typeTable);
						fp = startCodeGen(memLoc,gst);
						//printGlobalSymbolTable(gst);
					}
#line 1791 "y.tab.c"
    break;

  case 19:
#line 123 "code.y"
                                        {gst = NULL;}
#line 1797 "y.tab.c"
    break;

  case 20:
#line 126 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1803 "y.tab.c"
    break;

  case 21:
#line 127 "code.y"
                                {(yyval.dno) = (yyvsp[0].dno);}
#line 1809 "y.tab.c"
    break;

  case 22:
#line 130 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 1815 "y.tab.c"
    break;

  case 23:
#line 131 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 1821 "y.tab.c"
    break;

  case 24:
#line 132 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 1827 "y.tab.c"
    break;

  case 25:
#line 133 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 1833 "y.tab.c"
    break;

  case 26:
#line 136 "code.y"
                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 1839 "y.tab.c"
    break;

  case 27:
#line 139 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 1845 "y.tab.c"
    break;

  case 28:
#line 140 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1851 "y.tab.c"
    break;

  case 29:
#line 143 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1857 "y.tab.c"
    break;

  case 30:
#line 144 "code.y"
                                                        {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 1863 "y.tab.c"
    break;

  case 31:
#line 147 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].dno) -> varname,(yyvsp[0].dno) -> dim + 1,(yyvsp[0].dno) -> shape);}
#line 1869 "y.tab.c"
    break;

  case 32:
#line 148 "code.y"
                                                {(yyval.dno) = (yyvsp[0].dno);}
#line 1875 "y.tab.c"
    break;

  case 33:
#line 151 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[-3].dno) -> varname,(yyvsp[-3].dno) -> dim + 1,addArrayShape((yyvsp[-3].dno) -> shape,(yyvsp[-1].number)));}
#line 1881 "y.tab.c"
    break;

  case 34:
#line 152 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 1887 "y.tab.c"
    break;

  case 35:
#line 155 "code.y"
                                                        {}
#line 1893 "y.tab.c"
    break;

  case 36:
#line 156 "code.y"
                                                        {}
#line 1899 "y.tab.c"
    break;

  case 37:
#line 159 "code.y"
                                                        {	
									struct Gsymbol* g = GlobalLookup(gst,(yyvsp[-6].string));
									funcCodeGen((yyvsp[-2].no), fp,g -> flabel);
									lst = NULL;
								}
#line 1909 "y.tab.c"
    break;

  case 38:
#line 166 "code.y"
                                                        {
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyFuncHead(gst,(yyvsp[-3].string),TLookup(typeTable,(yyvsp[-4].string)),(yyvsp[-1].pt));
								addParamToLST(lst,(yyvsp[-1].pt));
								(yyval.string) = (yyvsp[-3].string);
							}
#line 1920 "y.tab.c"
    break;

  case 39:
#line 174 "code.y"
                                                {(yyval.pt) = addParameter((yyvsp[-2].pt),(yyvsp[0].pt));}
#line 1926 "y.tab.c"
    break;

  case 40:
#line 175 "code.y"
                                                {(yyval.pt) = (yyvsp[0].pt);}
#line 1932 "y.tab.c"
    break;

  case 41:
#line 176 "code.y"
                                                        {(yyval.pt) = NULL;}
#line 1938 "y.tab.c"
    break;

  case 42:
#line 179 "code.y"
                                                {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-1].string),0,typeTable);}
#line 1944 "y.tab.c"
    break;

  case 43:
#line 180 "code.y"
                                                        {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-2].string),1,typeTable);}
#line 1950 "y.tab.c"
    break;

  case 44:
#line 183 "code.y"
                                                                {	
									if(gst == NULL){
										fp = startCodeGen(-1,gst);	
										fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
									}
									funcCodeGen((yyvsp[-2].no), fp,-1);}
#line 1961 "y.tab.c"
    break;

  case 45:
#line 189 "code.y"
                                                                {exit(0);}
#line 1967 "y.tab.c"
    break;

  case 46:
#line 192 "code.y"
                                {lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));}
#line 1973 "y.tab.c"
    break;

  case 47:
#line 197 "code.y"
                                        {localMemLoc = 0; addLocalVarToLST(lst,(yyvsp[-1].dno),NULL,typeTable);}
#line 1979 "y.tab.c"
    break;

  case 48:
#line 198 "code.y"
                                        {(yyval.dno) = NULL;}
#line 1985 "y.tab.c"
    break;

  case 49:
#line 199 "code.y"
                                        {(yyval.dno) = NULL;}
#line 1991 "y.tab.c"
    break;

  case 50:
#line 202 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1997 "y.tab.c"
    break;

  case 51:
#line 203 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2003 "y.tab.c"
    break;

  case 52:
#line 206 "code.y"
                                        {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2009 "y.tab.c"
    break;

  case 53:
#line 209 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 2015 "y.tab.c"
    break;

  case 54:
#line 210 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2021 "y.tab.c"
    break;

  case 55:
#line 214 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2027 "y.tab.c"
    break;

  case 56:
#line 215 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),1,NULL);}
#line 2033 "y.tab.c"
    break;

  case 57:
#line 221 "code.y"
                                                                        {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 2039 "y.tab.c"
    break;

  case 58:
#line 222 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2045 "y.tab.c"
    break;

  case 59:
#line 225 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2051 "y.tab.c"
    break;

  case 60:
#line 226 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2057 "y.tab.c"
    break;

  case 61:
#line 227 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2063 "y.tab.c"
    break;

  case 62:
#line 228 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2069 "y.tab.c"
    break;

  case 63:
#line 229 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2075 "y.tab.c"
    break;

  case 64:
#line 230 "code.y"
                                                                {(yyval.no) = makeJumpNode(break_node);}
#line 2081 "y.tab.c"
    break;

  case 65:
#line 231 "code.y"
                                                                        {(yyval.no) = makeJumpNode(continue_node);}
#line 2087 "y.tab.c"
    break;

  case 66:
#line 232 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,NULL);}
#line 2093 "y.tab.c"
    break;

  case 67:
#line 233 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-4].string),gst,(yyvsp[-2].at));}
#line 2099 "y.tab.c"
    break;

  case 68:
#line 234 "code.y"
                                                                        {(yyval.no) = makeReturnNode((yyvsp[-1].no));}
#line 2105 "y.tab.c"
    break;

  case 69:
#line 237 "code.y"
                                                                {(yyval.no) = makeIfElseBlock((yyvsp[-7].no),(yyvsp[-4].no),(yyvsp[-2].no));}
#line 2111 "y.tab.c"
    break;

  case 70:
#line 238 "code.y"
                                                                        {(yyval.no) = makeIfElseBlock((yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 2117 "y.tab.c"
    break;

  case 71:
#line 241 "code.y"
                                                                {(yyval.no) = makeWhileBlock((yyvsp[-5].no),(yyvsp[-2].no));}
#line 2123 "y.tab.c"
    break;

  case 72:
#line 242 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 2129 "y.tab.c"
    break;

  case 73:
#line 243 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 2135 "y.tab.c"
    break;

  case 74:
#line 246 "code.y"
                                                                        {(yyval.no) = makeReadNode((yyvsp[-2].no));}
#line 2141 "y.tab.c"
    break;

  case 75:
#line 249 "code.y"
                                                                {(yyval.no) = makeWriteNode((yyvsp[-2].no));}
#line 2147 "y.tab.c"
    break;

  case 76:
#line 252 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(assign,(yyvsp[-3].no),(yyvsp[-1].no),typeTable);}
#line 2153 "y.tab.c"
    break;

  case 77:
#line 255 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(add,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2159 "y.tab.c"
    break;

  case 78:
#line 256 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(sub,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2165 "y.tab.c"
    break;

  case 79:
#line 257 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(mul,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2171 "y.tab.c"
    break;

  case 80:
#line 258 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(div,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2177 "y.tab.c"
    break;

  case 81:
#line 259 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(mod,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2183 "y.tab.c"
    break;

  case 82:
#line 260 "code.y"
                                                                {(yyval.no) = makeOperatorNode(gt,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2189 "y.tab.c"
    break;

  case 83:
#line 261 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(gte,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2195 "y.tab.c"
    break;

  case 84:
#line 262 "code.y"
                                                                {(yyval.no) = makeOperatorNode(lt,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2201 "y.tab.c"
    break;

  case 85:
#line 263 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(lte,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2207 "y.tab.c"
    break;

  case 86:
#line 264 "code.y"
                                                                {(yyval.no) = makeOperatorNode(eq,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2213 "y.tab.c"
    break;

  case 87:
#line 265 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(neq,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2219 "y.tab.c"
    break;

  case 88:
#line 266 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(and,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2225 "y.tab.c"
    break;

  case 89:
#line 267 "code.y"
                                                                {(yyval.no) = makeOperatorNode(or,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2231 "y.tab.c"
    break;

  case 90:
#line 268 "code.y"
                                                                {(yyval.no) = (yyvsp[-1].no);}
#line 2237 "y.tab.c"
    break;

  case 91:
#line 269 "code.y"
                                                                        {(yyval.no) = makeNumNode((yyvsp[0].number),0,typeTable);}
#line 2243 "y.tab.c"
    break;

  case 92:
#line 270 "code.y"
                                                                        {(yyval.no) = makeNumNode(-1 * (yyvsp[0].number),0,typeTable);}
#line 2249 "y.tab.c"
    break;

  case 93:
#line 271 "code.y"
                                                                        {(yyval.no) = makeStringNode((yyvsp[0].string),typeTable);}
#line 2255 "y.tab.c"
    break;

  case 94:
#line 272 "code.y"
                                                                        {(yyval.no) = makeNullNode(typeTable);}
#line 2261 "y.tab.c"
    break;

  case 95:
#line 273 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-2].string),gst,NULL);}
#line 2267 "y.tab.c"
    break;

  case 96:
#line 274 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,(yyvsp[-1].at));}
#line 2273 "y.tab.c"
    break;

  case 97:
#line 275 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2279 "y.tab.c"
    break;

  case 98:
#line 276 "code.y"
                                                                        {(yyval.no) = makeAddrNode((yyvsp[0].no),gst,lst,typeTable);}
#line 2285 "y.tab.c"
    break;

  case 99:
#line 277 "code.y"
                                                                        {(yyval.no) = makeAllocNode();}
#line 2291 "y.tab.c"
    break;

  case 100:
#line 278 "code.y"
                                                                        {(yyval.no) = makeMemInitNode(typeTable);}
#line 2297 "y.tab.c"
    break;

  case 101:
#line 279 "code.y"
                                                                        {(yyval.no) = makeFreeNode((yyvsp[-1].no),typeTable);}
#line 2303 "y.tab.c"
    break;

  case 102:
#line 282 "code.y"
                                        {(yyval.at) = addArguments((yyvsp[-2].at),makeArgStruct((yyvsp[0].no)));}
#line 2309 "y.tab.c"
    break;

  case 103:
#line 283 "code.y"
                                        {(yyval.at) = makeArgStruct((yyvsp[0].no));}
#line 2315 "y.tab.c"
    break;

  case 104:
#line 286 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2321 "y.tab.c"
    break;

  case 105:
#line 287 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[-1].no),typeTable);}
#line 2327 "y.tab.c"
    break;

  case 106:
#line 288 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[0].no),typeTable);}
#line 2333 "y.tab.c"
    break;

  case 107:
#line 289 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2339 "y.tab.c"
    break;

  case 108:
#line 292 "code.y"
                                                {(yyval.no) = extendTypeNode((yyvsp[-2].no),(yyvsp[0].string),typeTable);}
#line 2345 "y.tab.c"
    break;

  case 109:
#line 293 "code.y"
                                                {(yyval.no) = extendTypeNode((yyvsp[-2].no),(yyvsp[0].string),typeTable);}
#line 2351 "y.tab.c"
    break;

  case 110:
#line 296 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[-3].no) -> varname,gst,lst,addArrayDim((yyvsp[-3].no) -> indices,(yyvsp[-1].no)),typeTable);}
#line 2357 "y.tab.c"
    break;

  case 111:
#line 297 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[0].string),gst,lst,NULL,typeTable);}
#line 2363 "y.tab.c"
    break;


#line 2367 "y.tab.c"

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
#line 300 "code.y"


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
		if(shape != NULL){
			
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
