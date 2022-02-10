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
	FILE* startCodeGen();
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
    START = 277,
    END = 278,
    ENDSTMT = 279,
    DECL = 280,
    ENDDECL = 281,
    READ = 282,
    WRITE = 283,
    IF = 284,
    THEN = 285,
    ELSE = 286,
    ENDIF = 287,
    WHILE = 288,
    DO = 289,
    ENDWHILE = 290,
    REPEAT = 291,
    UNTIL = 292,
    BREAK = 293,
    CONTINUE = 294,
    RETURN = 295
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
#define START 277
#define END 278
#define ENDSTMT 279
#define DECL 280
#define ENDDECL 281
#define READ 282
#define WRITE 283
#define IF 284
#define THEN 285
#define ELSE 286
#define ENDIF 287
#define WHILE 288
#define DO 289
#define ENDWHILE 290
#define REPEAT 291
#define UNTIL 292
#define BREAK 293
#define CONTINUE 294
#define RETURN 295

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
	

#line 255 "y.tab.c"

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   486

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


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
      44,    45,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    80,    81,    84,    90,    93,    94,    97,
      98,   101,   104,   105,   108,   109,   110,   111,   112,   115,
     116,   119,   126,   134,   135,   136,   139,   142,   148,   151,
     156,   157,   158,   161,   162,   165,   168,   169,   173,   179,
     180,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   195,   196,   199,   200,   201,   204,   207,   210,   211,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   233,   234,   237,
     238,   239,   240
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "ID", "NUM", "STRING", "STR",
  "INT", "PLUS", "MINUS", "STAR", "DIV", "MOD", "ASSIGN", "GT", "GTE",
  "LT", "LTE", "EQ", "NEQ", "ADDR", "START", "END", "ENDSTMT", "DECL",
  "ENDDECL", "READ", "WRITE", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "REPEAT", "UNTIL", "BREAK", "CONTINUE", "RETURN", "','",
  "'['", "']'", "'('", "')'", "'{'", "'}'", "$accept", "program",
  "GdeclBlock", "GdeclList", "Type", "Gdecl", "GidList", "Gid",
  "FdefBlock", "Fdef", "FName", "ParamList", "Param", "MainBlock",
  "MainHeader", "LdeclBlock", "LdeclList", "Ldecl", "LidList", "Lid",
  "Slist", "Stmt", "IfStmt", "LoopStmt", "InputStmt", "OutputStmt",
  "AssgStmt", "expr", "ArgList", "Identifier", YY_NULLPTR
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
     295,    44,    91,    93,    40,    41,   123,   125
};
# endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -6,     5,    -2,    34,    15,   -69,     2,    35,   -69,   -69,
     -69,    32,    52,   -69,   -69,     5,    55,    15,   -69,    42,
     -69,    70,    58,   -69,   -69,    89,   112,   -14,   -69,    77,
     -69,   -69,    70,    36,    96,   -69,   122,   105,   -69,   -69,
      52,   105,   104,   -69,   126,    91,   -69,   135,    94,   134,
      16,   -69,   -69,    59,   345,   -69,     6,   -69,   -69,   -69,
      99,   143,   109,   107,   123,   132,   133,   345,   345,   142,
     146,    31,   161,   -69,   -69,   -69,   -69,   -69,   -69,   164,
     138,   -69,   105,   -69,   -69,   175,   -69,   126,    31,     7,
     -69,   -69,    73,    31,    31,    31,   359,   201,   -69,   -69,
     100,   -69,   -69,    31,   420,   -69,   136,   -69,    76,   176,
     -69,   140,   -69,   391,   158,   454,    60,   149,   147,   207,
     238,   250,   141,   152,    49,   262,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,   -69,   -69,    73,
     438,   150,   -69,   165,   -69,    31,   182,   186,   197,   202,
     199,    31,    31,   -69,    61,   -69,    98,    98,   -69,   -69,
     -69,   466,   466,   466,   466,   466,   466,   212,   -69,   -69,
      31,   454,   -69,   -69,   -69,   345,   345,   281,   293,   -69,
     -69,   403,   121,   312,    62,   218,   -69,   345,   219,   220,
     -69,   -69,   326,   -69,   -69,   221,   -69
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     0,     0,    10,     9,
       6,     0,     0,     8,     1,     9,     0,     0,    20,     0,
       3,    32,     0,     5,     7,    14,     0,     0,    13,     0,
      19,     2,    32,     0,     0,    29,     0,    25,    17,    11,
       0,    25,     0,    31,     0,     0,    34,     0,     0,     0,
       0,    24,    12,     0,     0,    38,     0,    37,    30,    33,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,    44,    45,    41,    42,    43,     0,
      15,    26,     0,    18,    22,     0,    35,     0,     0,     0,
      82,    28,     0,     0,     0,     0,     0,     0,    46,    47,
      79,    72,    73,     0,     0,    76,     0,    39,     0,     0,
      23,     0,    36,     0,     0,    78,     0,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    27,     0,
       0,     0,    21,    80,    48,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,    71,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    58,    16,
       0,    77,    49,    56,    57,     0,     0,     0,     0,    75,
      59,     0,     0,     0,     0,     0,    81,     0,     0,     0,
      54,    55,     0,    52,    53,     0,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   -69,   -69,    74,   235,   -69,   191,   -69,   247,
     -69,   243,   194,    -1,   -69,   253,   -69,   241,   -69,   200,
     -53,   -68,   -69,   -69,   -69,   -69,   -69,   -62,   190,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,    11,    49,    13,    27,    28,    17,    18,
      19,    50,    51,     5,     6,    34,    45,    46,    56,    57,
      72,    73,    74,    75,    76,    77,    78,   115,   116,   105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,    85,     1,    20,   107,     8,     9,    79,     7,   104,
      39,   100,   101,   102,    96,    97,    31,   107,    61,     2,
      79,    79,     8,    15,    10,    79,   113,    40,   107,   107,
      86,   119,   120,   121,    14,   100,   101,   102,    79,     8,
       9,   125,    61,     8,     9,   118,   140,    87,    21,    79,
      79,   103,   114,   100,   101,   102,    25,    82,    23,    29,
      61,    83,    43,    26,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   103,    12,   117,    16,    22,
     100,   101,   102,   171,    61,    12,   190,    61,    32,   177,
     178,    16,   167,   103,   153,    33,   176,   139,     8,     9,
      82,   145,   145,    35,    84,   146,   179,    44,   181,   128,
     129,   130,     8,     9,   107,   107,    38,    58,    47,    44,
     103,    41,   182,   183,   107,    60,    54,    48,    79,    79,
      55,    36,    61,    37,   192,    79,    79,    80,    81,    60,
      79,    88,    88,    89,   124,    79,    61,    90,    63,    64,
      65,    92,   187,   188,    66,    67,    91,    68,    62,    69,
      70,    71,    63,    64,    65,    60,    98,    93,    66,    67,
      99,    68,    61,    69,    70,    71,    94,    95,   108,    60,
     109,   141,   144,   138,   106,   151,    61,   142,    63,    64,
      65,    88,   147,   169,    66,    67,   152,    68,   111,    69,
      70,    71,    63,    64,    65,    60,   172,   170,    66,    67,
     173,    68,    61,    69,    70,    71,   126,   127,   128,   129,
     130,   174,   131,   132,   133,   134,   135,   136,    63,    64,
      65,    52,   175,   176,    66,    67,   180,    68,   123,    69,
      70,    71,   191,   193,   194,   196,    24,   126,   127,   128,
     129,   130,   148,   131,   132,   133,   134,   135,   136,   126,
     127,   128,   129,   130,    30,   131,   132,   133,   134,   135,
     136,   126,   127,   128,   129,   130,   110,   131,   132,   133,
     134,   135,   136,   149,    53,    42,    59,   112,     0,     0,
     126,   127,   128,   129,   130,   150,   131,   132,   133,   134,
     135,   136,   126,   127,   128,   129,   130,   155,   131,   132,
     133,   134,   135,   136,   154,     0,    60,     0,     0,     0,
       0,     0,     0,    61,     0,     0,   184,     0,     0,     0,
      60,     0,     0,     0,     0,     0,     0,    61,   185,    63,
      64,    65,     0,     0,     0,    66,    67,   189,    68,    60,
      69,    70,    71,    63,    64,    65,    61,     0,   195,    66,
      67,     0,    68,    60,    69,    70,    71,     0,     0,     0,
      61,     0,    63,    64,    65,     0,     0,     0,    66,    67,
       0,    68,     0,    69,    70,    71,    63,    64,    65,     0,
       0,     0,   122,    67,     0,    68,     0,    69,    70,    71,
     126,   127,   128,   129,   130,     0,   131,   132,   133,   134,
     135,   136,   126,   127,   128,   129,   130,     0,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,   126,
     127,   128,   129,   130,   143,   131,   132,   133,   134,   135,
     136,     0,     0,     0,   137,     0,   186,   126,   127,   128,
     129,   130,     0,   131,   132,   133,   134,   135,   136,     0,
       0,     0,   168,   126,   127,   128,   129,   130,     0,   131,
     132,   133,   134,   135,   136,   126,   127,   128,   129,   130,
       0,    -1,    -1,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      47,    54,     8,     4,    72,     7,     8,    54,     3,    71,
      24,     4,     5,     6,    67,    68,    17,    85,    11,    25,
      67,    68,     7,     8,    26,    72,    88,    41,    96,    97,
      24,    93,    94,    95,     0,     4,     5,     6,    85,     7,
       8,   103,    11,     7,     8,    92,   108,    41,    46,    96,
      97,    44,    45,     4,     5,     6,     4,    41,    26,     4,
      11,    45,    26,    11,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,    44,     2,     4,     4,    44,
       4,     5,     6,   145,    11,    11,    24,    11,    46,   151,
     152,    17,   139,    44,    45,    25,    34,    21,     7,     8,
      41,    41,    41,    45,    45,    45,    45,    33,   170,    11,
      12,    13,     7,     8,   182,   183,     4,    26,    22,    45,
      44,    44,   175,   176,   192,     4,    22,     5,   175,   176,
       4,    42,    11,    44,   187,   182,   183,    43,     4,     4,
     187,    42,    42,    44,    44,   192,    11,     4,    27,    28,
      29,    44,    31,    32,    33,    34,    47,    36,    23,    38,
      39,    40,    27,    28,    29,     4,    24,    44,    33,    34,
      24,    36,    11,    38,    39,    40,    44,    44,    14,     4,
      42,     5,    24,    47,    23,    44,    11,    47,    27,    28,
      29,    42,    45,    43,    33,    34,    44,    36,    23,    38,
      39,    40,    27,    28,    29,     4,    24,    42,    33,    34,
      24,    36,    11,    38,    39,    40,     9,    10,    11,    12,
      13,    24,    15,    16,    17,    18,    19,    20,    27,    28,
      29,    40,    30,    34,    33,    34,    24,    36,    37,    38,
      39,    40,    24,    24,    24,    24,    11,     9,    10,    11,
      12,    13,    45,    15,    16,    17,    18,    19,    20,     9,
      10,    11,    12,    13,    17,    15,    16,    17,    18,    19,
      20,     9,    10,    11,    12,    13,    82,    15,    16,    17,
      18,    19,    20,    45,    41,    32,    45,    87,    -1,    -1,
       9,    10,    11,    12,    13,    45,    15,    16,    17,    18,
      19,    20,     9,    10,    11,    12,    13,    45,    15,    16,
      17,    18,    19,    20,   124,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    45,    -1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    11,    45,    27,
      28,    29,    -1,    -1,    -1,    33,    34,    35,    36,     4,
      38,    39,    40,    27,    28,    29,    11,    -1,    32,    33,
      34,    -1,    36,     4,    38,    39,    40,    -1,    -1,    -1,
      11,    -1,    27,    28,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    -1,    38,    39,    40,    27,    28,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    -1,    38,    39,    40,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    20,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    12,    13,    43,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    24,    -1,    43,     9,    10,    11,
      12,    13,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    24,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    19,    20,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    19,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    25,    49,    50,    61,    62,     3,     7,     8,
      26,    51,    52,    53,     0,     8,    52,    56,    57,    58,
      61,    46,    44,    26,    53,     4,    11,    54,    55,     4,
      57,    61,    46,    25,    63,    45,    42,    44,     4,    24,
      41,    44,    63,    26,    52,    64,    65,    22,     5,    52,
      59,    60,    55,    59,    22,     4,    66,    67,    26,    65,
       4,    11,    23,    27,    28,    29,    33,    34,    36,    38,
      39,    40,    68,    69,    70,    71,    72,    73,    74,    77,
      43,     4,    41,    45,    45,    68,    24,    41,    42,    44,
       4,    47,    44,    44,    44,    44,    68,    68,    24,    24,
       4,     5,     6,    44,    75,    77,    23,    69,    14,    42,
      60,    23,    67,    75,    45,    75,    76,     4,    77,    75,
      75,    75,    33,    37,    44,    75,     9,    10,    11,    12,
      13,    15,    16,    17,    18,    19,    20,    24,    47,    21,
      75,     5,    47,    43,    24,    41,    45,    45,    45,    45,
      45,    44,    44,    45,    76,    45,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    77,    24,    43,
      42,    75,    24,    24,    24,    30,    34,    75,    75,    45,
      24,    75,    68,    68,    45,    45,    43,    31,    32,    35,
      24,    24,    68,    24,    24,    32,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    51,    51,    52,
      52,    53,    54,    54,    55,    55,    55,    55,    55,    56,
      56,    57,    58,    59,    59,    59,    60,    61,    61,    62,
      63,    63,    63,    64,    64,    65,    66,    66,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    71,    71,    71,    72,    73,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    77,
      77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     1,
       1,     3,     3,     1,     1,     4,     7,     2,     4,     2,
       1,     7,     5,     3,     1,     0,     2,     7,     6,     4,
       3,     2,     0,     2,     1,     3,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     4,     5,
       3,    10,     8,     8,     7,     7,     5,     5,     4,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     3,     4,     1,     3,     1,     1,
       4,     7,     2
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
#line 79 "code.y"
                                                {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1615 "y.tab.c"
    break;

  case 3:
#line 80 "code.y"
                                                {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1621 "y.tab.c"
    break;

  case 4:
#line 81 "code.y"
                                                {fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
#line 1627 "y.tab.c"
    break;

  case 5:
#line 84 "code.y"
                                        {
						gst = (struct GSymbolTable*)malloc(sizeof(struct GSymbolTable));
						generateGlobalSymbolTable(gst,(yyvsp[-1].dno),noType);
						fp = startCodeGen();	
						fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space	
					}
#line 1638 "y.tab.c"
    break;

  case 6:
#line 90 "code.y"
                                        {gst = NULL;}
#line 1644 "y.tab.c"
    break;

  case 7:
#line 93 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1650 "y.tab.c"
    break;

  case 8:
#line 94 "code.y"
                                {(yyval.dno) = (yyvsp[0].dno);}
#line 1656 "y.tab.c"
    break;

  case 9:
#line 97 "code.y"
                                        {(yyval.number) = (yyvsp[0].number);}
#line 1662 "y.tab.c"
    break;

  case 10:
#line 98 "code.y"
                                        {(yyval.number) = (yyvsp[0].number);}
#line 1668 "y.tab.c"
    break;

  case 11:
#line 101 "code.y"
                                        {(yyval.dno) = makeDatatypeNode((yyvsp[-2].number),(yyvsp[-1].dno));}
#line 1674 "y.tab.c"
    break;

  case 12:
#line 104 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 1680 "y.tab.c"
    break;

  case 13:
#line 105 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1686 "y.tab.c"
    break;

  case 14:
#line 108 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,0,0);}
#line 1692 "y.tab.c"
    break;

  case 15:
#line 109 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[-3].string),(yyvsp[-1].number),0,1);}
#line 1698 "y.tab.c"
    break;

  case 16:
#line 110 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[-6].string),(yyvsp[-4].number),(yyvsp[-1].number),2);}
#line 1704 "y.tab.c"
    break;

  case 17:
#line 111 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,0,-1);}
#line 1710 "y.tab.c"
    break;

  case 18:
#line 112 "code.y"
                                                        {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 1716 "y.tab.c"
    break;

  case 19:
#line 115 "code.y"
                                                        {}
#line 1722 "y.tab.c"
    break;

  case 20:
#line 116 "code.y"
                                                        {}
#line 1728 "y.tab.c"
    break;

  case 21:
#line 119 "code.y"
                                                        {
									struct Gsymbol* g = GlobalLookup(gst,(yyvsp[-6].string));
									funcCodeGen((yyvsp[-2].no), fp,g -> binding);
									lst = NULL;
								}
#line 1738 "y.tab.c"
    break;

  case 22:
#line 126 "code.y"
                                                        {
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyFuncHead(gst,(yyvsp[-3].string),(yyvsp[-4].number),(yyvsp[-1].pt));
								addParamToLST(lst,(yyvsp[-1].pt));
								(yyval.string) = (yyvsp[-3].string);
							}
#line 1749 "y.tab.c"
    break;

  case 23:
#line 134 "code.y"
                                                {(yyval.pt) = addParameter((yyvsp[-2].pt),(yyvsp[0].pt));}
#line 1755 "y.tab.c"
    break;

  case 24:
#line 135 "code.y"
                                                {(yyval.pt) = (yyvsp[0].pt);}
#line 1761 "y.tab.c"
    break;

  case 25:
#line 136 "code.y"
                                                        {(yyval.pt) = NULL;}
#line 1767 "y.tab.c"
    break;

  case 26:
#line 139 "code.y"
                                                {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-1].number));}
#line 1773 "y.tab.c"
    break;

  case 27:
#line 142 "code.y"
                                                                {
									if(gst == NULL){
										fp = startCodeGen();	
										fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
									}
									funcCodeGen((yyvsp[-2].no), fp,-1);}
#line 1784 "y.tab.c"
    break;

  case 28:
#line 148 "code.y"
                                                                {exit(0);}
#line 1790 "y.tab.c"
    break;

  case 29:
#line 151 "code.y"
                                {lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));}
#line 1796 "y.tab.c"
    break;

  case 30:
#line 156 "code.y"
                                        {localMemLoc = 0; addLocalVarToLST(lst,(yyvsp[-1].dno),noType);}
#line 1802 "y.tab.c"
    break;

  case 31:
#line 157 "code.y"
                                        {(yyval.dno) = NULL;}
#line 1808 "y.tab.c"
    break;

  case 32:
#line 158 "code.y"
                                        {(yyval.dno) = NULL;}
#line 1814 "y.tab.c"
    break;

  case 33:
#line 161 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1820 "y.tab.c"
    break;

  case 34:
#line 162 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1826 "y.tab.c"
    break;

  case 35:
#line 165 "code.y"
                                        {(yyval.dno) = makeDatatypeNode((yyvsp[-2].number),(yyvsp[-1].dno));}
#line 1832 "y.tab.c"
    break;

  case 36:
#line 168 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 1838 "y.tab.c"
    break;

  case 37:
#line 169 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1844 "y.tab.c"
    break;

  case 38:
#line 173 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,0,0);}
#line 1850 "y.tab.c"
    break;

  case 39:
#line 179 "code.y"
                                                                        {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 1856 "y.tab.c"
    break;

  case 40:
#line 180 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1862 "y.tab.c"
    break;

  case 41:
#line 183 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1868 "y.tab.c"
    break;

  case 42:
#line 184 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1874 "y.tab.c"
    break;

  case 43:
#line 185 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1880 "y.tab.c"
    break;

  case 44:
#line 186 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1886 "y.tab.c"
    break;

  case 45:
#line 187 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 1892 "y.tab.c"
    break;

  case 46:
#line 188 "code.y"
                                                                {(yyval.no) = makeJumpNode(break_node);}
#line 1898 "y.tab.c"
    break;

  case 47:
#line 189 "code.y"
                                                                        {(yyval.no) = makeJumpNode(continue_node);}
#line 1904 "y.tab.c"
    break;

  case 48:
#line 190 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,NULL);}
#line 1910 "y.tab.c"
    break;

  case 49:
#line 191 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-4].string),gst,(yyvsp[-2].at));}
#line 1916 "y.tab.c"
    break;

  case 50:
#line 192 "code.y"
                                                                        {(yyval.no) = makeReturnNode((yyvsp[-1].no));}
#line 1922 "y.tab.c"
    break;

  case 51:
#line 195 "code.y"
                                                                {(yyval.no) = makeIfElseBlock((yyvsp[-7].no),(yyvsp[-4].no),(yyvsp[-2].no));}
#line 1928 "y.tab.c"
    break;

  case 52:
#line 196 "code.y"
                                                                        {(yyval.no) = makeIfElseBlock((yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 1934 "y.tab.c"
    break;

  case 53:
#line 199 "code.y"
                                                                {(yyval.no) = makeWhileBlock((yyvsp[-5].no),(yyvsp[-2].no));}
#line 1940 "y.tab.c"
    break;

  case 54:
#line 200 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 1946 "y.tab.c"
    break;

  case 55:
#line 201 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 1952 "y.tab.c"
    break;

  case 56:
#line 204 "code.y"
                                                                        {(yyval.no) = makeReadNode((yyvsp[-2].no));}
#line 1958 "y.tab.c"
    break;

  case 57:
#line 207 "code.y"
                                                                {(yyval.no) = makeWriteNode((yyvsp[-2].no));}
#line 1964 "y.tab.c"
    break;

  case 58:
#line 210 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(assign,(yyvsp[-3].no),(yyvsp[-1].no));}
#line 1970 "y.tab.c"
    break;

  case 59:
#line 211 "code.y"
                                                                        {(yyval.no) = makePtrIdNode((yyvsp[-4].no), gst, (yyvsp[-1].no));}
#line 1976 "y.tab.c"
    break;

  case 60:
#line 214 "code.y"
                                {(yyval.no) = makeOperatorNode(add,(yyvsp[-2].no),(yyvsp[0].no));}
#line 1982 "y.tab.c"
    break;

  case 61:
#line 215 "code.y"
                                {(yyval.no) = makeOperatorNode(sub,(yyvsp[-2].no),(yyvsp[0].no));}
#line 1988 "y.tab.c"
    break;

  case 62:
#line 216 "code.y"
                                {(yyval.no) = makeOperatorNode(mul,(yyvsp[-2].no),(yyvsp[0].no));}
#line 1994 "y.tab.c"
    break;

  case 63:
#line 217 "code.y"
                                {(yyval.no) = makeOperatorNode(div,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2000 "y.tab.c"
    break;

  case 64:
#line 218 "code.y"
                                {(yyval.no) = makeOperatorNode(mod,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2006 "y.tab.c"
    break;

  case 65:
#line 219 "code.y"
                        {(yyval.no) = makeOperatorNode(gt,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2012 "y.tab.c"
    break;

  case 66:
#line 220 "code.y"
                                {(yyval.no) = makeOperatorNode(gte,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2018 "y.tab.c"
    break;

  case 67:
#line 221 "code.y"
                        {(yyval.no) = makeOperatorNode(lt,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2024 "y.tab.c"
    break;

  case 68:
#line 222 "code.y"
                                {(yyval.no) = makeOperatorNode(lte,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2030 "y.tab.c"
    break;

  case 69:
#line 223 "code.y"
                        {(yyval.no) = makeOperatorNode(eq,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2036 "y.tab.c"
    break;

  case 70:
#line 224 "code.y"
                                {(yyval.no) = makeOperatorNode(neq,(yyvsp[-2].no),(yyvsp[0].no));}
#line 2042 "y.tab.c"
    break;

  case 71:
#line 225 "code.y"
                        {(yyval.no) = (yyvsp[-1].no);}
#line 2048 "y.tab.c"
    break;

  case 72:
#line 226 "code.y"
                                {(yyval.no) = makeNumNode((yyvsp[0].number));}
#line 2054 "y.tab.c"
    break;

  case 73:
#line 227 "code.y"
                                {(yyval.no) = makeStringNode((yyvsp[0].string));}
#line 2060 "y.tab.c"
    break;

  case 74:
#line 228 "code.y"
                                {(yyval.no) = makeFuncNode((yyvsp[-2].string),gst,NULL);}
#line 2066 "y.tab.c"
    break;

  case 75:
#line 229 "code.y"
                                {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,(yyvsp[-1].at));}
#line 2072 "y.tab.c"
    break;

  case 76:
#line 230 "code.y"
                                {(yyval.no) = (yyvsp[0].no);}
#line 2078 "y.tab.c"
    break;

  case 77:
#line 233 "code.y"
                                        {(yyval.at) = addArguments((yyvsp[-2].at),makeArgStruct((yyvsp[0].no)));}
#line 2084 "y.tab.c"
    break;

  case 78:
#line 234 "code.y"
                                        {(yyval.at) = makeArgStruct((yyvsp[0].no));}
#line 2090 "y.tab.c"
    break;

  case 79:
#line 237 "code.y"
                                        {(yyval.no) = makeIdNode((yyvsp[0].string),gst,lst,NULL,NULL);}
#line 2096 "y.tab.c"
    break;

  case 80:
#line 238 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[-3].string),gst,lst,(yyvsp[-1].no),NULL);}
#line 2102 "y.tab.c"
    break;

  case 81:
#line 239 "code.y"
                                        {(yyval.no) = makeIdNode((yyvsp[-6].string),gst,lst,(yyvsp[-4].no),(yyvsp[-1].no));}
#line 2108 "y.tab.c"
    break;

  case 82:
#line 240 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[0].string),gst,lst,makeNumNode(0),NULL);}
#line 2114 "y.tab.c"
    break;


#line 2118 "y.tab.c"

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
#line 243 "code.y"


void yyerror(char const *s)
{
    printf("yyerror: %s",s);
    exit(0);
}

FILE* startCodeGen(){
	FILE *fp = fopen("output/output.out","w");
	fprintf(fp,"0\n2056\n0\n0\n0\n0\n0\n0\n");
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
