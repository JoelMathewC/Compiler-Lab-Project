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
	#include "functions/symbolTableFunc.h"
	
	#include "functions/dNodeFunc.c"
	#include "functions/tNodeFunc.c"
	#include "functions/paramStructFunc.c"
	#include "functions/labelAddrTableFunc.c"
	#include "functions/loopStackFunc.c"
	#include "functions/symbolTableFunc.c"
	#include "backend/globalVar.c"
	
	#include "backend/code_gen.h"
	#include "backend/code_gen.c"
	
	struct GSymbolTable* gst;
	struct LSymbolTable* lst;
	FILE* startCodeGen(int memLoc);
	void endCodeGen(FILE *fp);
	FILE *fp;

#line 113 "y.tab.c"

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
#line 44 "code.y"

	struct tnode *no;
	struct dnode *dno;
	struct ParamStruct *pt;
	struct ArgStruct *at;
	int number;
	char* string;
	int* seq;
	

#line 257 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   533

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

#define YYUNDEFTOK  2
#define YYMAXUTOK   297


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
      44,    45,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    81,    81,    82,    83,    86,    91,    94,    95,    98,
      99,   102,   105,   106,   109,   110,   113,   114,   117,   118,
     121,   122,   125,   132,   140,   141,   142,   145,   146,   149,
     155,   158,   163,   164,   165,   168,   169,   172,   175,   176,
     180,   181,   187,   188,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   203,   204,   207,   208,   209,   212,
     215,   218,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   244,   245,   248,   249,   250,   253,   254
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "ID", "NUM", "STRING", "STR",
  "INT", "PLUS", "MINUS", "STAR", "DIV", "MOD", "ASSIGN", "GT", "GTE",
  "LT", "LTE", "EQ", "NEQ", "ADDR", "AND", "OR", "START", "END", "ENDSTMT",
  "DECL", "ENDDECL", "READ", "WRITE", "IF", "THEN", "ELSE", "ENDIF",
  "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL", "BREAK", "CONTINUE",
  "RETURN", "','", "'('", "')'", "'['", "']'", "'{'", "'}'", "$accept",
  "program", "GdeclBlock", "GdeclList", "Type", "Gdecl", "GidList", "Gid",
  "IdentifierDecl", "IdArrDecl", "FdefBlock", "Fdef", "FName", "ParamList",
  "Param", "MainBlock", "MainHeader", "LdeclBlock", "LdeclList", "Ldecl",
  "LidList", "Lid", "Slist", "Stmt", "IfStmt", "LoopStmt", "InputStmt",
  "OutputStmt", "AssgStmt", "expr", "ArgList", "Identifier", "IdArr", YY_NULLPTR
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
     295,   296,   297,    44,    40,    41,    91,    93,   123,   125
};
# endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,    32,     6,     9,   118,   -75,   -10,    15,   -75,   -75,
     -75,    29,     0,   -75,   -75,    32,    73,   118,   -75,    67,
     -75,   103,    78,   -75,   -75,    87,    47,    62,   -75,   -75,
      90,    91,   -75,   -75,   103,    53,   113,   -75,   120,   -75,
     -75,   -75,     0,   135,   120,   117,   -75,    96,    89,   -75,
     168,    97,   -37,   -75,   -75,    98,    59,   284,   -75,   142,
      63,   -75,   -75,   -75,   104,    38,   101,   105,   121,   124,
     125,   284,   284,   145,   148,    88,   190,   -75,   -75,   -75,
     -75,   -75,   -75,   156,   127,   -75,   171,   120,   -75,   -75,
     -75,   212,   -75,   -75,    96,    42,   -75,    88,   -75,   -75,
      99,    88,    88,    88,   301,   229,   -75,   -75,   140,   -75,
     -75,   181,    99,    88,   443,   -75,   141,   -75,    88,    88,
     -75,   -75,   143,   -75,   169,   483,    71,   335,   151,   350,
     366,   381,   158,   161,    74,   -75,   -75,   397,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,   -75,   -75,   465,   144,   -75,   -75,    88,   174,   -75,
     185,   186,   175,   177,    88,    88,   -75,    79,   -75,   100,
     100,   -75,   -75,   -75,   513,   513,   513,   513,   513,   513,
     498,   498,   -75,   -75,   483,   -75,   -75,   -75,   284,   284,
     412,   428,   -75,   147,   245,     4,   188,   284,   191,   192,
     -75,   -75,   262,   -75,   -75,   196,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     0,     0,    10,     9,
       6,     0,     0,     8,     1,     9,     0,     0,    21,     0,
       3,    34,     0,     5,     7,    19,     0,     0,    13,    14,
      17,     0,    20,     2,    34,     0,     0,    31,    26,    19,
      16,    11,     0,     0,    26,     0,    33,     0,     0,    36,
       0,     0,     0,    25,    12,     0,     0,     0,    40,     0,
       0,    39,    32,    35,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    43,    47,    48,
      44,    45,    46,     0,    85,    27,     0,     0,    15,    18,
      23,     0,    41,    37,     0,     0,    89,     0,    87,    30,
       0,     0,     0,     0,     0,     0,    49,    50,    89,    76,
      78,     0,     0,     0,     0,    81,     0,    42,     0,     0,
      28,    24,     0,    38,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    29,     0,     0,    22,    51,     0,     0,    86,
       0,     0,     0,     0,     0,     0,    79,     0,    75,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    61,    88,    83,    52,    59,    60,     0,     0,
       0,     0,    80,     0,     0,     0,     0,     0,     0,     0,
      57,    58,     0,    55,    56,     0,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   -75,     8,   213,   -75,   187,   201,   -75,
     -75,   217,   -75,   194,   149,    16,   -75,   205,   -75,   197,
     -75,   150,   -55,   -73,   -75,   -75,   -75,   -75,   -75,   -74,
     112,   -50,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,    11,    51,    13,    27,    28,    29,    30,
      17,    18,    19,    52,    53,     5,     6,    36,    48,    49,
      60,    61,    76,    77,    78,    79,    80,    81,    82,   125,
     126,   115,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,   114,    91,   117,    25,     1,    87,    83,    88,    14,
      12,    26,    16,     8,     9,    98,   104,   105,   117,    12,
      20,    83,    83,   127,     2,    16,    83,   129,   130,   131,
     200,   117,   117,    33,    10,     7,     8,     9,    21,   137,
     189,    83,    96,    47,   153,   154,   108,   109,   110,    65,
     128,    39,   111,    65,    83,    83,    47,    23,    26,    22,
       8,     9,   136,   112,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,    31,   108,   109,
     110,    46,    97,   184,   111,    65,   113,   124,    41,    93,
     190,   191,   108,   109,   110,   112,     8,     9,   111,    65,
      58,    85,    87,    96,    90,    42,    94,    59,    86,   112,
      65,   140,   141,   142,   157,    34,   158,    62,   113,   166,
     117,   117,   157,    37,   192,     8,    15,     8,     9,   117,
      35,    38,   113,   193,   194,    44,    43,    50,    83,    83,
      55,    57,   202,    83,    83,    89,    92,    83,    95,   100,
      99,    64,    83,   138,   139,   140,   141,   142,    65,   143,
     144,   145,   146,   147,   148,   101,   149,   150,   102,   103,
     118,   106,    64,   119,   107,   120,    67,    68,    69,    65,
     197,   198,    70,    71,   134,    72,   135,    73,    74,    75,
     152,   183,   155,    66,    64,   156,   160,    67,    68,    69,
     185,    65,   164,    70,    71,   165,    72,   188,    73,    74,
      75,   186,   187,   189,   201,   116,    64,   203,   204,    67,
      68,    69,   206,    65,    24,    70,    71,    40,    72,    54,
      73,    74,    75,    64,    32,     0,   121,   122,    56,    45,
      65,    67,    68,    69,   123,    63,   167,    70,    71,    64,
      72,     0,    73,    74,    75,     0,    65,     0,    67,    68,
      69,     0,     0,     0,    70,    71,    64,    72,   133,    73,
      74,    75,     0,    65,    67,    68,    69,     0,     0,     0,
      70,    71,   199,    72,     0,    73,    74,    75,    64,     0,
       0,    67,    68,    69,     0,    65,   205,    70,    71,     0,
      72,     0,    73,    74,    75,    64,     0,     0,     0,     0,
       0,     0,    65,    67,    68,    69,     0,     0,     0,    70,
      71,     0,    72,     0,    73,    74,    75,     0,     0,     0,
      67,    68,    69,     0,     0,     0,   132,    71,     0,    72,
       0,    73,    74,    75,   138,   139,   140,   141,   142,     0,
     143,   144,   145,   146,   147,   148,     0,   149,   150,   138,
     139,   140,   141,   142,     0,   143,   144,   145,   146,   147,
     148,     0,   149,   150,     0,   138,   139,   140,   141,   142,
     159,   143,   144,   145,   146,   147,   148,     0,   149,   150,
     138,   139,   140,   141,   142,   161,   143,   144,   145,   146,
     147,   148,     0,   149,   150,     0,   138,   139,   140,   141,
     142,   162,   143,   144,   145,   146,   147,   148,     0,   149,
     150,   138,   139,   140,   141,   142,   163,   143,   144,   145,
     146,   147,   148,     0,   149,   150,     0,   138,   139,   140,
     141,   142,   168,   143,   144,   145,   146,   147,   148,     0,
     149,   150,   138,   139,   140,   141,   142,   195,   143,   144,
     145,   146,   147,   148,     0,   149,   150,     0,     0,   151,
       0,     0,     0,   196,   138,   139,   140,   141,   142,     0,
     143,   144,   145,   146,   147,   148,     0,   149,   150,     0,
       0,   182,   138,   139,   140,   141,   142,     0,   143,   144,
     145,   146,   147,   148,     0,   149,   150,   138,   139,   140,
     141,   142,     0,   143,   144,   145,   146,   147,   148,     0,
      -1,    -1,   138,   139,   140,   141,   142,     0,    -1,    -1,
      -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      50,    75,    57,    76,     4,     8,    43,    57,    45,     0,
       2,    11,     4,     7,     8,    65,    71,    72,    91,    11,
       4,    71,    72,    97,    27,    17,    76,   101,   102,   103,
      26,   104,   105,    17,    28,     3,     7,     8,    48,   113,
      36,    91,     4,    35,   118,   119,     4,     5,     6,    11,
     100,     4,    10,    11,   104,   105,    48,    28,    11,    44,
       7,     8,   112,    21,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,     4,     4,     5,
       6,    28,    44,   157,    10,    11,    44,    45,    26,    26,
     164,   165,     4,     5,     6,    21,     7,     8,    10,    11,
       4,     4,    43,     4,    45,    43,    43,    11,    11,    21,
      11,    11,    12,    13,    43,    48,    45,    28,    44,    45,
     193,   194,    43,    45,    45,     7,     8,     7,     8,   202,
      27,    44,    44,   188,   189,    44,    46,    24,   188,   189,
       5,    24,   197,   193,   194,    47,     4,   197,    44,    44,
      49,     4,   202,     9,    10,    11,    12,    13,    11,    15,
      16,    17,    18,    19,    20,    44,    22,    23,    44,    44,
      14,    26,     4,    46,    26,     4,    29,    30,    31,    11,
      33,    34,    35,    36,    44,    38,     5,    40,    41,    42,
      49,    47,    49,    25,     4,    26,    45,    29,    30,    31,
      26,    11,    44,    35,    36,    44,    38,    32,    40,    41,
      42,    26,    26,    36,    26,    25,     4,    26,    26,    29,
      30,    31,    26,    11,    11,    35,    36,    26,    38,    42,
      40,    41,    42,     4,    17,    -1,    87,    25,    44,    34,
      11,    29,    30,    31,    94,    48,   134,    35,    36,     4,
      38,    -1,    40,    41,    42,    -1,    11,    -1,    29,    30,
      31,    -1,    -1,    -1,    35,    36,     4,    38,    39,    40,
      41,    42,    -1,    11,    29,    30,    31,    -1,    -1,    -1,
      35,    36,    37,    38,    -1,    40,    41,    42,     4,    -1,
      -1,    29,    30,    31,    -1,    11,    34,    35,    36,    -1,
      38,    -1,    40,    41,    42,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    29,    30,    31,    -1,    -1,    -1,    35,
      36,    -1,    38,    -1,    40,    41,    42,    -1,    -1,    -1,
      29,    30,    31,    -1,    -1,    -1,    35,    36,    -1,    38,
      -1,    40,    41,    42,     9,    10,    11,    12,    13,    -1,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,     9,
      10,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    -1,     9,    10,    11,    12,    13,
      45,    15,    16,    17,    18,    19,    20,    -1,    22,    23,
       9,    10,    11,    12,    13,    45,    15,    16,    17,    18,
      19,    20,    -1,    22,    23,    -1,     9,    10,    11,    12,
      13,    45,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,     9,    10,    11,    12,    13,    45,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    -1,     9,    10,    11,
      12,    13,    45,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,     9,    10,    11,    12,    13,    45,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    -1,    -1,    26,
      -1,    -1,    -1,    45,     9,    10,    11,    12,    13,    -1,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    -1,
      -1,    26,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,     9,    10,    11,
      12,    13,    -1,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    19,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    27,    51,    52,    65,    66,     3,     7,     8,
      28,    53,    54,    55,     0,     8,    54,    60,    61,    62,
      65,    48,    44,    28,    55,     4,    11,    56,    57,    58,
      59,     4,    61,    65,    48,    27,    67,    45,    44,     4,
      58,    26,    43,    46,    44,    67,    28,    54,    68,    69,
      24,    54,    63,    64,    57,     5,    63,    24,     4,    11,
      70,    71,    28,    69,     4,    11,    25,    29,    30,    31,
      35,    36,    38,    40,    41,    42,    72,    73,    74,    75,
      76,    77,    78,    81,    82,     4,    11,    43,    45,    47,
      45,    72,     4,    26,    43,    44,     4,    44,    81,    49,
      44,    44,    44,    44,    72,    72,    26,    26,     4,     5,
       6,    10,    21,    44,    79,    81,    25,    73,    14,    46,
       4,    64,    25,    71,    45,    79,    80,    79,    81,    79,
      79,    79,    35,    39,    44,     5,    81,    79,     9,    10,
      11,    12,    13,    15,    16,    17,    18,    19,    20,    22,
      23,    26,    49,    79,    79,    49,    26,    43,    45,    45,
      45,    45,    45,    45,    44,    44,    45,    80,    45,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    26,    47,    79,    26,    26,    26,    32,    36,
      79,    79,    45,    72,    72,    45,    45,    33,    34,    37,
      26,    26,    72,    26,    26,    34,    26
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    62,    63,    63,    63,    64,    64,    65,
      65,    66,    67,    67,    67,    68,    68,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    75,    76,
      77,    78,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    80,    80,    81,    81,    81,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     1,
       1,     3,     3,     1,     1,     4,     2,     1,     4,     1,
       2,     1,     7,     5,     3,     1,     0,     2,     3,     7,
       6,     4,     3,     2,     0,     2,     1,     3,     3,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     4,     5,     3,    10,     8,     8,     7,     7,     5,
       5,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     2,     1,     3,
       4,     1,     2,     3,     1,     1,     4,     2,     4,     1
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
#line 81 "code.y"
                                                {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1632 "y.tab.c"
    break;

  case 3:
#line 82 "code.y"
                                                {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1638 "y.tab.c"
    break;

  case 4:
#line 83 "code.y"
                                                {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1644 "y.tab.c"
    break;

  case 5:
#line 86 "code.y"
                                        {	
						gst = (struct GSymbolTable*)malloc(sizeof(struct GSymbolTable));
						generateGlobalSymbolTable(gst,(yyvsp[-1].dno),noType);
						fp = startCodeGen(memLoc);		
					}
#line 1654 "y.tab.c"
    break;

  case 6:
#line 91 "code.y"
                                        {gst = NULL;}
#line 1660 "y.tab.c"
    break;

  case 7:
#line 94 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1666 "y.tab.c"
    break;

  case 8:
#line 95 "code.y"
                                {(yyval.dno) = (yyvsp[0].dno);}
#line 1672 "y.tab.c"
    break;

  case 9:
#line 98 "code.y"
                                        {(yyval.number) = (yyvsp[0].number);}
#line 1678 "y.tab.c"
    break;

  case 10:
#line 99 "code.y"
                                        {(yyval.number) = (yyvsp[0].number);}
#line 1684 "y.tab.c"
    break;

  case 11:
#line 102 "code.y"
                                        {(yyval.dno) = makeDatatypeNode((yyvsp[-2].number),(yyvsp[-1].dno));}
#line 1690 "y.tab.c"
    break;

  case 12:
#line 105 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 1696 "y.tab.c"
    break;

  case 13:
#line 106 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1702 "y.tab.c"
    break;

  case 14:
#line 109 "code.y"
                                                {(yyval.dno) = (yyvsp[0].dno);}
#line 1708 "y.tab.c"
    break;

  case 15:
#line 110 "code.y"
                                                {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 1714 "y.tab.c"
    break;

  case 16:
#line 113 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].dno) -> varname,(yyvsp[0].dno) -> dim + 1,(yyvsp[0].dno) -> shape);}
#line 1720 "y.tab.c"
    break;

  case 17:
#line 114 "code.y"
                                                {(yyval.dno) = (yyvsp[0].dno);}
#line 1726 "y.tab.c"
    break;

  case 18:
#line 117 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[-3].dno) -> varname,(yyvsp[-3].dno) -> dim,addArrayShape((yyvsp[-3].dno) -> shape,(yyvsp[-1].number)));}
#line 1732 "y.tab.c"
    break;

  case 19:
#line 118 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 1738 "y.tab.c"
    break;

  case 20:
#line 121 "code.y"
                                                        {}
#line 1744 "y.tab.c"
    break;

  case 21:
#line 122 "code.y"
                                                        {}
#line 1750 "y.tab.c"
    break;

  case 22:
#line 125 "code.y"
                                                        {	
									struct Gsymbol* g = GlobalLookup(gst,(yyvsp[-6].string));
									funcCodeGen((yyvsp[-2].no), fp,g -> binding);
									lst = NULL;
								}
#line 1760 "y.tab.c"
    break;

  case 23:
#line 132 "code.y"
                                                        {
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyFuncHead(gst,(yyvsp[-3].string),(yyvsp[-4].number),(yyvsp[-1].pt));
								addParamToLST(lst,(yyvsp[-1].pt));
								(yyval.string) = (yyvsp[-3].string);
							}
#line 1771 "y.tab.c"
    break;

  case 24:
#line 140 "code.y"
                                                {(yyval.pt) = addParameter((yyvsp[-2].pt),(yyvsp[0].pt));}
#line 1777 "y.tab.c"
    break;

  case 25:
#line 141 "code.y"
                                                {(yyval.pt) = (yyvsp[0].pt);}
#line 1783 "y.tab.c"
    break;

  case 26:
#line 142 "code.y"
                                                        {(yyval.pt) = NULL;}
#line 1789 "y.tab.c"
    break;

  case 27:
#line 145 "code.y"
                                                {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-1].number),0);}
#line 1795 "y.tab.c"
    break;

  case 28:
#line 146 "code.y"
                                                        {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-2].number),1);}
#line 1801 "y.tab.c"
    break;

  case 29:
#line 149 "code.y"
                                                                {	
									if(gst == NULL){
										fp = startCodeGen(-1);	
										fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
									}
									funcCodeGen((yyvsp[-2].no), fp,-1);}
#line 1812 "y.tab.c"
    break;

  case 30:
#line 155 "code.y"
                                                                {exit(0);}
#line 1818 "y.tab.c"
    break;

  case 31:
#line 158 "code.y"
                                {lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));}
#line 1824 "y.tab.c"
    break;

  case 32:
#line 163 "code.y"
                                        {localMemLoc = 0; addLocalVarToLST(lst,(yyvsp[-1].dno),noType);}
#line 1830 "y.tab.c"
    break;

  case 33:
#line 164 "code.y"
                                        {(yyval.dno) = NULL;}
#line 1836 "y.tab.c"
    break;

  case 34:
#line 165 "code.y"
                                        {(yyval.dno) = NULL;}
#line 1842 "y.tab.c"
    break;

  case 35:
#line 168 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1848 "y.tab.c"
    break;

  case 36:
#line 169 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1854 "y.tab.c"
    break;

  case 37:
#line 172 "code.y"
                                        {(yyval.dno) = makeDatatypeNode((yyvsp[-2].number),(yyvsp[-1].dno));}
#line 1860 "y.tab.c"
    break;

  case 38:
#line 175 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 1866 "y.tab.c"
    break;

  case 39:
#line 176 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1872 "y.tab.c"
    break;

  case 40:
#line 180 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 1878 "y.tab.c"
    break;

  case 41:
#line 181 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),1,NULL);}
#line 1884 "y.tab.c"
    break;

  case 42:
#line 187 "code.y"
                                                                        {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 1890 "y.tab.c"
    break;

  case 43:
#line 188 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1896 "y.tab.c"
    break;

  case 44:
#line 191 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1902 "y.tab.c"
    break;

  case 45:
#line 192 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1908 "y.tab.c"
    break;

  case 46:
#line 193 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1914 "y.tab.c"
    break;

  case 47:
#line 194 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1920 "y.tab.c"
    break;

  case 48:
#line 195 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1926 "y.tab.c"
    break;

  case 49:
#line 196 "code.y"
                                                                {(yyval.no) = makeJumpNode(break_node);}
#line 1932 "y.tab.c"
    break;

  case 50:
#line 197 "code.y"
                                                                        {(yyval.no) = makeJumpNode(continue_node);}
#line 1938 "y.tab.c"
    break;

  case 51:
#line 198 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,NULL);}
#line 1944 "y.tab.c"
    break;

  case 52:
#line 199 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-4].string),gst,(yyvsp[-2].at));}
#line 1950 "y.tab.c"
    break;

  case 53:
#line 200 "code.y"
                                                                        {(yyval.no) = makeReturnNode((yyvsp[-1].no));}
#line 1956 "y.tab.c"
    break;

  case 54:
#line 203 "code.y"
                                                                {(yyval.no) = makeIfElseBlock((yyvsp[-7].no),(yyvsp[-4].no),(yyvsp[-2].no));}
#line 1962 "y.tab.c"
    break;

  case 55:
#line 204 "code.y"
                                                                        {(yyval.no) = makeIfElseBlock((yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 1968 "y.tab.c"
    break;

  case 56:
#line 207 "code.y"
                                                                {(yyval.no) = makeWhileBlock((yyvsp[-5].no),(yyvsp[-2].no));}
#line 1974 "y.tab.c"
    break;

  case 57:
#line 208 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 1980 "y.tab.c"
    break;

  case 58:
#line 209 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 1986 "y.tab.c"
    break;

  case 59:
#line 212 "code.y"
                                                                        {(yyval.no) = makeReadNode((yyvsp[-2].no));}
#line 1992 "y.tab.c"
    break;

  case 60:
#line 215 "code.y"
                                                                {(yyval.no) = makeWriteNode((yyvsp[-2].no));}
#line 1998 "y.tab.c"
    break;

  case 61:
#line 218 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(assign,(yyvsp[-3].no),(yyvsp[-1].no));}
#line 2004 "y.tab.c"
    break;

  case 62:
#line 221 "code.y"
                                {(yyval.no) = makeOperatorNode(add,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2010 "y.tab.c"
    break;

  case 63:
#line 222 "code.y"
                                {(yyval.no) = makeOperatorNode(sub,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2016 "y.tab.c"
    break;

  case 64:
#line 223 "code.y"
                                {(yyval.no) = makeOperatorNode(mul,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2022 "y.tab.c"
    break;

  case 65:
#line 224 "code.y"
                                {(yyval.no) = makeOperatorNode(div,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2028 "y.tab.c"
    break;

  case 66:
#line 225 "code.y"
                                {(yyval.no) = makeOperatorNode(mod,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2034 "y.tab.c"
    break;

  case 67:
#line 226 "code.y"
                        {(yyval.no) = makeOperatorNode(gt,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2040 "y.tab.c"
    break;

  case 68:
#line 227 "code.y"
                                {(yyval.no) = makeOperatorNode(gte,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2046 "y.tab.c"
    break;

  case 69:
#line 228 "code.y"
                        {(yyval.no) = makeOperatorNode(lt,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2052 "y.tab.c"
    break;

  case 70:
#line 229 "code.y"
                                {(yyval.no) = makeOperatorNode(lte,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2058 "y.tab.c"
    break;

  case 71:
#line 230 "code.y"
                        {(yyval.no) = makeOperatorNode(eq,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2064 "y.tab.c"
    break;

  case 72:
#line 231 "code.y"
                                {(yyval.no) = makeOperatorNode(neq,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2070 "y.tab.c"
    break;

  case 73:
#line 232 "code.y"
                                {(yyval.no) = makeOperatorNode(and,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2076 "y.tab.c"
    break;

  case 74:
#line 233 "code.y"
                        {(yyval.no) = makeOperatorNode(or,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2082 "y.tab.c"
    break;

  case 75:
#line 234 "code.y"
                        {(yyval.no) = (yyvsp[-1].no);}
#line 2088 "y.tab.c"
    break;

  case 76:
#line 235 "code.y"
                                {(yyval.no) = makeNumNode((yyvsp[0].number),0);}
#line 2094 "y.tab.c"
    break;

  case 77:
#line 236 "code.y"
                                {(yyval.no) = makeNumNode(-1 * (yyvsp[0].number),0);}
#line 2100 "y.tab.c"
    break;

  case 78:
#line 237 "code.y"
                                {(yyval.no) = makeStringNode((yyvsp[0].string));}
#line 2106 "y.tab.c"
    break;

  case 79:
#line 238 "code.y"
                                {(yyval.no) = makeFuncNode((yyvsp[-2].string),gst,NULL);}
#line 2112 "y.tab.c"
    break;

  case 80:
#line 239 "code.y"
                                {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,(yyvsp[-1].at));}
#line 2118 "y.tab.c"
    break;

  case 81:
#line 240 "code.y"
                                {(yyval.no) = (yyvsp[0].no);}
#line 2124 "y.tab.c"
    break;

  case 82:
#line 241 "code.y"
                                {(yyval.no) = makeAddrNode((yyvsp[0].no),gst,lst);}
#line 2130 "y.tab.c"
    break;

  case 83:
#line 244 "code.y"
                                        {(yyval.at) = addArguments((yyvsp[-2].at),makeArgStruct((yyvsp[0].no)));}
#line 2136 "y.tab.c"
    break;

  case 84:
#line 245 "code.y"
                                        {(yyval.at) = makeArgStruct((yyvsp[0].no));}
#line 2142 "y.tab.c"
    break;

  case 85:
#line 248 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2148 "y.tab.c"
    break;

  case 86:
#line 249 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[-1].no));}
#line 2154 "y.tab.c"
    break;

  case 87:
#line 250 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[0].no));}
#line 2160 "y.tab.c"
    break;

  case 88:
#line 253 "code.y"
                                        {(yyval.no) = makeIdNode((yyvsp[-3].no) -> varname,gst,lst,addArrayDim((yyvsp[-3].no) -> indices,(yyvsp[-1].no)));}
#line 2166 "y.tab.c"
    break;

  case 89:
#line 254 "code.y"
                                        {(yyval.no) = makeIdNode((yyvsp[0].string),gst,lst,NULL);}
#line 2172 "y.tab.c"
    break;


#line 2176 "y.tab.c"

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
#line 257 "code.y"


void yyerror(char const *s)
{
    printf("yyerror: %s",s);
    exit(0);
}

FILE* startCodeGen(int memLoc){
	FILE *fp = fopen("output/output.out","w");
	fprintf(fp,"0\n2056\n0\n0\n0\n0\n0\n0\n");
	if(memLoc > 0)
		fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
	fprintf(fp,"ADD SP, 1\n"); //allocate space for return from main
	fprintf(fp, "CALL MAIN\n");
	fprintf(fp,"CALL EXIT\n");
	return fp;
}

void endCodeGen(FILE *fp){
	lib_code_gen(end,0,fp);
	fclose(fp);
}

int main(int argc, char* argv[]) {
	
	FILE *input_fp;

	if(argc > 1){
		input_fp = fopen(argv[1],"r");
		fflush(input_fp);
	
		if(input_fp)
			yyin = input_fp;
	}
	yyparse();
	
	if(input_fp)
		fclose(input_fp);
	return 0;
}