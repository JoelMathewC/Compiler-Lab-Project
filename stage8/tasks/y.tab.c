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
	

#line 303 "y.tab.c"

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
#define YYLAST   928

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  365

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
       0,    96,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   108,   109,   112,   113,   116,   117,   120,   124,
     130,   137,   138,   139,   142,   143,   146,   149,   150,   153,
     154,   157,   160,   163,   164,   167,   175,   184,   185,   188,
     189,   192,   195,   196,   199,   202,   203,   207,   213,   216,
     217,   220,   221,   222,   223,   224,   227,   230,   233,   234,
     237,   238,   241,   242,   245,   246,   249,   250,   253,   260,
     268,   269,   270,   271,   275,   276,   277,   280,   281,   284,
     290,   293,   298,   299,   300,   303,   304,   307,   310,   311,
     312,   315,   316,   320,   321,   327,   328,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   347,   348,   351,   352,   353,   356,   359,   362,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     398,   399,   402,   403,   404,   407,   408,   409,   412,   413
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
  "GtypeBlock", "GtypeList", "Gtype", "GtypeDeclList", "GtypeDecl",
  "GtypeIdList", "GdeclBlock", "GdeclList", "Type", "TupleType", "Gdecl",
  "GidList", "Gid", "IdentifierDecl", "IdArrDecl", "FdefBlock", "Fdef",
  "FName", "FuncRetType", "ParamList", "Param", "MainBlock", "MainHeader",
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
     123,    21,   181,     3,    11,    31,   -25,   161,   170,  -234,
     -23,    18,  -234,  -234,  -234,  -234,    71,  -234,   236,    25,
    -234,  -234,    22,  -234,    15,  -234,    44,  -234,    19,  -234,
      36,  -234,   170,   -25,   170,  -234,  -234,  -234,    21,  -234,
     170,  -234,    49,   108,  -234,    89,    74,    83,  -234,  -234,
      84,   110,    14,  -234,  -234,    97,   202,  -234,  -234,   167,
    -234,  -234,   141,   170,  -234,   170,   170,  -234,  -234,  -234,
      89,   117,    99,   166,  -234,   202,   202,  -234,  -234,  -234,
      25,   182,    53,  -234,   177,  -234,   202,    60,  -234,  -234,
     170,  -234,  -234,   187,   202,  -234,  -234,  -234,  -234,   137,
    -234,   115,   446,   153,    38,  -234,   125,  -234,   132,  -234,
    -234,  -234,    37,   419,  -234,   478,  -234,   218,  -234,   130,
    -234,   148,   226,  -234,   635,   159,  -234,  -234,  -234,   232,
      41,  -234,   183,   192,     6,   206,   191,   199,   207,   209,
     635,   635,   240,   258,   400,   474,  -234,  -234,  -234,  -234,
    -234,  -234,   248,   225,   228,  -234,   288,   202,  -234,  -234,
    -234,  -234,   289,  -234,  -234,   560,  -234,  -234,   293,   238,
      46,   269,  -234,  -234,    89,   241,   502,  -234,  -234,  -234,
     115,   122,   296,  -234,   239,   400,  -234,   249,  -234,   109,
     400,   400,   400,   662,   528,  -234,  -234,   242,  -234,  -234,
     250,  -234,   299,   109,   252,   256,   257,   265,   266,   400,
     838,  -234,   263,   270,  -234,   400,   326,   400,  -234,  -234,
    -234,  -234,   238,   202,  -234,   327,  -234,   308,   202,   279,
    -234,   319,   874,   162,   278,   346,   721,   347,   291,   736,
     751,   772,   294,   295,   280,   356,  -234,  -234,   300,   301,
     109,   369,   109,   787,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,  -234,   370,  -234,
     856,   315,   706,   172,  -234,   635,   176,  -234,  -234,   400,
     348,   304,  -234,  -234,  -234,   349,   354,   330,   335,   400,
     400,  -234,   188,   337,  -234,  -234,   325,   338,   339,  -234,
     184,   184,  -234,  -234,  -234,   904,   904,   904,   904,   904,
     904,   889,   889,   342,  -234,   328,  -234,  -234,   556,  -234,
     874,  -234,  -234,   193,  -234,  -234,   635,   635,   802,   823,
    -234,   352,  -234,  -234,  -234,   376,   368,   196,   345,   378,
     417,   582,   -14,   379,  -234,   201,  -234,   204,  -234,   380,
    -234,  -234,   635,   392,   396,  -234,  -234,  -234,  -234,  -234,
     609,  -234,  -234,   403,  -234
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,    54,    52,    51,    53,     0,    48,     0,     0,
      55,    50,     0,    38,     0,    40,    18,    13,     0,    15,
       0,     1,     0,     0,     0,     8,    73,    71,    70,    72,
       0,    67,     0,     0,    10,    84,     0,     0,    47,    49,
      65,     0,     0,    59,    60,    63,     0,    37,    39,     0,
      12,    14,     0,     0,     5,     0,     0,     7,    66,     9,
      84,     0,     0,     0,    81,    76,    76,    65,    62,    57,
       0,     0,     0,    43,     0,    19,     0,     0,    20,     4,
       0,     3,     6,     0,    76,    90,    89,    88,    83,     0,
      86,     0,     0,     0,     0,    75,     0,    58,     0,    41,
      42,    46,     0,     0,    25,     0,    30,     0,    17,     0,
      34,     0,     0,     2,     0,     0,    82,    85,    93,     0,
       0,    92,   159,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,   100,   101,    97,
      98,    99,     0,   154,   157,    77,     0,     0,    56,    61,
      64,    44,     0,    23,    24,     0,    22,    29,     0,    28,
       0,     0,    16,    33,    84,     0,     0,    69,    94,    87,
       0,     0,     0,   159,     0,     0,   153,   154,    80,     0,
       0,     0,     0,     0,     0,   102,   103,   159,   133,   135,
       0,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   139,   154,     0,    95,     0,     0,     0,    78,    74,
      45,    21,     0,    76,    26,     0,    31,     0,    76,     0,
      91,     0,   151,     0,   156,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,     0,    79,
       0,   155,     0,     0,    27,     0,     0,    68,   104,     0,
       0,     0,   156,   152,   155,     0,     0,     0,     0,     0,
       0,   137,     0,   156,   141,   143,     0,     0,     0,   132,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   155,   118,     0,   158,    32,     0,    36,
     150,   105,   108,     0,   116,   117,     0,     0,     0,     0,
     138,     0,   144,   142,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,     0,   146,     0,   106,     0,
      35,   109,     0,     0,     0,   114,   115,   149,   147,   107,
       0,   112,   113,     0,   111
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -234,  -234,   423,  -234,   406,  -234,  -234,  -234,  -234,   322,
    -234,   332,  -106,  -234,  -234,   320,  -234,  -234,  -234,   414,
    -234,   364,  -234,   116,  -234,     2,  -234,   429,  -234,   372,
     397,  -234,   -20,   -10,  -234,  -234,   -68,   292,    20,  -234,
     -65,  -234,   355,  -234,  -234,   277,  -123,  -143,  -234,  -234,
    -234,  -234,  -234,    17,  -233,  -102,   -99,  -234
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    28,    29,    30,    87,    88,   113,   114,
     170,   115,   116,   171,   119,   120,   121,     7,    24,    25,
      82,    83,   112,     8,    18,   103,    20,    21,    52,    53,
      54,    55,    40,    41,    42,    43,   104,   105,     9,    10,
      73,    99,   100,   101,   130,   131,   145,   146,   147,   148,
     149,   150,   151,   232,   233,   211,   212,   154
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     152,   176,   214,   153,    19,    93,     2,    22,   106,   167,
     183,   292,    63,   184,    66,    26,   355,   193,   194,    22,
      19,   134,   152,    26,    11,   153,   125,    35,    44,    50,
      68,    31,   186,   214,    45,   187,   327,    23,   152,   152,
      51,   153,   153,   152,    79,    90,   153,    27,   323,    57,
     214,   214,    64,    68,    67,    60,    68,    12,    84,   167,
      69,    13,    14,    15,    12,    16,   185,   161,    13,    14,
      15,   179,    16,    80,   152,    47,   224,   153,    46,    56,
      68,    59,   337,    89,    84,    91,    92,   238,   117,   122,
     187,   152,   152,    62,   153,   153,   162,   157,   345,   158,
     180,   247,   347,    95,   187,   225,    70,    96,    97,   227,
     123,   109,    71,   183,    77,   117,   184,   168,   118,   128,
      72,   122,    32,    34,   134,    51,   197,   198,   199,   200,
     129,    98,     1,   201,    12,    74,   202,   134,    13,    14,
      15,    95,    16,    75,    76,    96,    97,   203,   296,    65,
     298,   187,   318,   187,     2,   273,     3,   155,     4,    81,
     276,   210,   204,   205,   206,   207,   208,   168,   156,   126,
       1,    85,    86,   152,    36,   214,   153,    94,    37,    38,
      39,   111,   209,   231,   157,    12,   159,   108,   172,    13,
      14,    15,     2,    16,   102,   160,     4,   214,   214,   256,
     257,   258,   236,   340,   341,   174,    12,   239,   240,   241,
      13,    14,    15,    17,    16,   124,   152,   214,   157,   153,
     177,   279,   169,   280,   152,   152,   253,   153,   153,   360,
     175,   157,   270,   317,   272,   157,   178,   319,   152,   152,
      12,   153,   153,   181,    13,    14,    15,   279,    16,   330,
     152,   189,   279,   153,   339,   279,   182,   349,   152,   190,
     279,   153,   357,   279,   188,   358,   215,   191,    48,   192,
     195,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   197,   198,   199,   200,   196,   216,
     217,   201,   218,   220,   202,   134,   320,   222,   223,   226,
     234,   228,   244,   235,   246,   203,   328,   329,   197,   198,
     199,   200,   248,   237,   245,   201,   249,   250,   202,   134,
     204,   205,   206,   207,   208,   251,   252,   268,   269,   203,
     271,   274,   197,   198,   199,   200,   275,   277,   281,   201,
     209,   291,   202,   134,   204,   205,   206,   207,   208,   278,
     282,   284,   285,   203,   289,   290,   197,   198,   199,   200,
     293,   294,   295,   201,   209,   322,   202,   134,   204,   205,
     206,   207,   208,   297,   313,   315,   326,   203,   321,   324,
     197,   198,   199,   200,   325,   327,   332,   201,   209,   336,
     202,   134,   204,   205,   206,   207,   208,   331,   348,   333,
     334,   203,   335,   350,   197,   198,   199,   200,   351,   356,
     359,   201,   209,   344,   202,   134,   204,   205,   206,   207,
     208,   132,   361,    12,   133,   203,   362,    13,    14,    15,
      33,    16,   134,   364,    61,   164,   209,   346,    58,   173,
     204,   205,   206,   207,   208,   165,   110,    49,    78,   219,
     132,   163,   107,   133,   127,   136,   137,   230,     0,     0,
     209,   134,   138,     0,   352,   353,   139,   140,     0,   141,
       0,   142,   143,   144,     0,   135,     0,     0,   132,     0,
       0,   133,    12,     0,   136,   137,    13,    14,    15,   134,
      16,   138,     0,     0,     0,   139,   140,     0,   141,     0,
     142,   143,   144,   213,     0,     0,   132,     0,     0,   133,
     166,     0,   136,   137,     0,     0,     0,   134,     0,   138,
       0,     0,     0,   139,   140,     0,   141,     0,   142,   143,
     144,   229,   132,     0,     0,   133,     0,     0,     0,     0,
     136,   137,     0,   134,     0,     0,     0,   138,     0,     0,
       0,   139,   140,     0,   141,     0,   142,   143,   144,     0,
     132,     0,     0,   133,    12,     0,   136,   137,    13,    14,
      15,   134,    16,   138,     0,     0,     0,   139,   140,     0,
     141,   243,   142,   143,   144,   338,   132,     0,     0,   133,
       0,     0,   221,     0,   136,   137,     0,   134,     0,     0,
       0,   138,     0,     0,     0,   139,   140,     0,   141,     0,
     142,   143,   144,   132,     0,     0,   133,     0,     0,     0,
     136,   137,     0,     0,   134,     0,     0,   138,     0,     0,
       0,   139,   140,   354,   141,     0,   142,   143,   144,   132,
       0,     0,   133,     0,     0,     0,     0,   136,   137,     0,
     134,     0,     0,     0,   138,     0,     0,   363,   139,   140,
       0,   141,     0,   142,   143,   144,   132,     0,     0,   133,
       0,     0,     0,   136,   137,     0,     0,   134,     0,     0,
     138,     0,     0,     0,   139,   140,     0,   141,     0,   142,
     143,   144,     0,     0,     0,     0,     0,     0,     0,     0,
     136,   137,     0,     0,     0,     0,     0,   138,     0,     0,
       0,   242,   140,     0,   141,     0,   142,   143,   144,   254,
     255,   256,   257,   258,     0,   259,   260,   261,   262,   263,
     264,     0,   265,   266,   254,   255,   256,   257,   258,     0,
     259,   260,   261,   262,   263,   264,     0,   265,   266,   254,
     255,   256,   257,   258,     0,   259,   260,   261,   262,   263,
     264,     0,   265,   266,   254,   255,   256,   257,   258,   316,
     259,   260,   261,   262,   263,   264,     0,   265,   266,     0,
       0,     0,   283,     0,     0,   254,   255,   256,   257,   258,
       0,   259,   260,   261,   262,   263,   264,   286,   265,   266,
     254,   255,   256,   257,   258,     0,   259,   260,   261,   262,
     263,   264,   287,   265,   266,   254,   255,   256,   257,   258,
       0,   259,   260,   261,   262,   263,   264,     0,   265,   266,
       0,     0,     0,   288,     0,     0,   254,   255,   256,   257,
     258,     0,   259,   260,   261,   262,   263,   264,   299,   265,
     266,   254,   255,   256,   257,   258,     0,   259,   260,   261,
     262,   263,   264,   342,   265,   266,     0,     0,   267,   254,
     255,   256,   257,   258,     0,   259,   260,   261,   262,   263,
     264,     0,   265,   266,   343,     0,   314,   254,   255,   256,
     257,   258,     0,   259,   260,   261,   262,   263,   264,     0,
     265,   266,   254,   255,   256,   257,   258,     0,   259,   260,
     261,   262,   263,   264,     0,    -1,    -1,   254,   255,   256,
     257,   258,     0,    -1,    -1,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
     102,   124,   145,   102,     2,    70,    31,     4,    76,   115,
       4,   244,    32,     7,    34,     4,    30,   140,   141,     4,
      18,    15,   124,     4,     3,   124,    94,     7,     8,     4,
      40,     0,   134,   176,    57,   134,    50,    34,   140,   141,
      15,   140,   141,   145,    30,    65,   145,    36,   281,    34,
     193,   194,    32,    63,    34,    36,    66,     4,    56,   165,
      40,     8,     9,    10,     4,    12,    60,    30,     8,     9,
      10,    30,    12,    59,   176,     4,    30,   176,    60,    57,
      90,    37,   315,    63,    82,    65,    66,   189,    86,    87,
     189,   193,   194,    57,   193,   194,    59,    59,   331,    61,
      59,   203,   335,     4,   203,    59,    57,     8,     9,   174,
      90,    58,     4,     4,     4,   113,     7,   115,    58,     4,
      31,   119,     6,     7,    15,    15,     4,     5,     6,     7,
      15,    32,     9,    11,     4,    61,    14,    15,     8,     9,
      10,     4,    12,    60,    60,     8,     9,    25,   250,    33,
     252,   250,   275,   252,    31,   223,    33,     4,    35,    62,
     228,   144,    40,    41,    42,    43,    44,   165,    15,    32,
       9,     4,    31,   275,     4,   318,   275,    60,     8,     9,
      10,     4,    60,    61,    59,     4,    61,     5,    58,     8,
       9,    10,    31,    12,    28,    63,    35,   340,   341,    15,
      16,    17,   185,   326,   327,    57,     4,   190,   191,   192,
       8,     9,    10,    32,    12,    28,   318,   360,    59,   318,
      61,    59,     4,    61,   326,   327,   209,   326,   327,   352,
       4,    59,   215,    61,   217,    59,     4,    61,   340,   341,
       4,   340,   341,    60,     8,     9,    10,    59,    12,    61,
     352,    60,    59,   352,    61,    59,    64,    61,   360,    60,
      59,   360,    61,    59,    58,    61,    18,    60,    32,    60,
      30,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,     4,     5,     6,     7,    30,    64,
      62,    11,     4,     4,    14,    15,   279,     4,    60,    30,
       4,    60,    60,    64,     5,    25,   289,   290,     4,     5,
       6,     7,    60,    64,    64,    11,    60,    60,    14,    15,
      40,    41,    42,    43,    44,    60,    60,    64,    58,    25,
       4,     4,     4,     5,     6,     7,    28,    58,    60,    11,
      60,    61,    14,    15,    40,    41,    42,    43,    44,    30,
       4,     4,    61,    25,    60,    60,     4,     5,     6,     7,
       4,    61,    61,    11,    60,    61,    14,    15,    40,    41,
      42,    43,    44,     4,     4,    60,    46,    25,    30,    30,
       4,     5,     6,     7,    30,    50,    61,    11,    60,    61,
      14,    15,    40,    41,    42,    43,    44,    60,    30,    61,
      61,    25,    60,    58,     4,     5,     6,     7,    30,    30,
      30,    11,    60,    61,    14,    15,    40,    41,    42,    43,
      44,     4,    30,     4,     7,    25,    30,     8,     9,    10,
       7,    12,    15,    30,    28,   113,    60,    61,    24,   119,
      40,    41,    42,    43,    44,   113,    82,    18,    51,   157,
       4,    32,    80,     7,    99,    38,    39,   180,    -1,    -1,
      60,    15,    45,    -1,    47,    48,    49,    50,    -1,    52,
      -1,    54,    55,    56,    -1,    29,    -1,    -1,     4,    -1,
      -1,     7,     4,    -1,    38,    39,     8,     9,    10,    15,
      12,    45,    -1,    -1,    -1,    49,    50,    -1,    52,    -1,
      54,    55,    56,    29,    -1,    -1,     4,    -1,    -1,     7,
      32,    -1,    38,    39,    -1,    -1,    -1,    15,    -1,    45,
      -1,    -1,    -1,    49,    50,    -1,    52,    -1,    54,    55,
      56,    29,     4,    -1,    -1,     7,    -1,    -1,    -1,    -1,
      38,    39,    -1,    15,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    49,    50,    -1,    52,    -1,    54,    55,    56,    -1,
       4,    -1,    -1,     7,     4,    -1,    38,    39,     8,     9,
      10,    15,    12,    45,    -1,    -1,    -1,    49,    50,    -1,
      52,    53,    54,    55,    56,    29,     4,    -1,    -1,     7,
      -1,    -1,    32,    -1,    38,    39,    -1,    15,    -1,    -1,
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
       0,     9,    31,    33,    35,    66,    67,    82,    88,   103,
     104,     3,     4,     8,     9,    10,    12,    32,    89,    90,
      91,    92,     4,    34,    83,    84,     4,    36,    68,    69,
      70,     0,    88,    67,    88,   103,     4,     8,     9,    10,
      97,    98,    99,   100,   103,    57,    60,     4,    32,    92,
       4,    15,    93,    94,    95,    96,    57,    34,    84,    37,
      36,    69,    57,    97,   103,    88,    97,   103,    98,   103,
      57,     4,    31,   105,    61,    60,    60,     4,    95,    30,
      59,    62,    85,    86,    90,     4,    31,    71,    72,   103,
      97,   103,   103,   105,    60,     4,     8,     9,    32,   106,
     107,   108,    28,    90,   101,   102,   101,    94,     5,    58,
      86,     4,    87,    73,    74,    76,    77,    90,    58,    79,
      80,    81,    90,   103,    28,   101,    32,   107,     4,    15,
     109,   110,     4,     7,    15,    29,    38,    39,    45,    49,
      50,    52,    54,    55,    56,   111,   112,   113,   114,   115,
     116,   117,   120,   121,   122,     4,    15,    59,    61,    61,
      63,    30,    59,    32,    74,    76,    32,    77,    90,     4,
      75,    78,    58,    80,    57,     4,   111,    61,     4,    30,
      59,    60,    64,     4,     7,    60,   120,   121,    58,    60,
      60,    60,    60,   111,   111,    30,    30,     4,     5,     6,
       7,    11,    14,    25,    40,    41,    42,    43,    44,    60,
     118,   120,   121,    29,   112,    18,    64,    62,     4,   102,
       4,    32,     4,    60,    30,    59,    30,   105,    60,    29,
     110,    61,   118,   119,     4,    64,   118,    64,   120,   118,
     118,   118,    49,    53,    60,    64,     5,   120,    60,    60,
      60,    60,    60,   118,    13,    14,    15,    16,    17,    19,
      20,    21,    22,    23,    24,    26,    27,    30,    64,    58,
     118,     4,   118,   101,     4,    28,   101,    58,    30,    59,
      61,    60,     4,    61,     4,    61,    61,    61,    61,    60,
      60,    61,   119,     4,    61,    61,   120,     4,   120,    61,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,     4,    30,    60,    63,    61,   111,    61,
     118,    30,    61,   119,    30,    30,    46,    50,   118,   118,
      61,    60,    61,    61,    61,    60,    61,   119,    29,    61,
     111,   111,    61,    61,    61,   119,    61,   119,    30,    61,
      58,    30,    47,    48,    51,    30,    30,    61,    61,    30,
     111,    30,    30,    48,    30
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    72,    72,    72,    73,    73,    74,    75,    75,    76,
      76,    77,    78,    79,    79,    80,    81,    82,    82,    83,
      83,    84,    85,    85,    86,    87,    87,    88,    88,    89,
      89,    90,    90,    90,    90,    90,    91,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    98,    99,
     100,   100,   100,   100,   101,   101,   101,   102,   102,   103,
     103,   104,   105,   105,   105,   106,   106,   107,   108,   108,
     108,   109,   109,   110,   110,   111,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   113,   113,   114,   114,   114,   115,   116,   117,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     119,   119,   120,   120,   120,   121,   121,   121,   122,   122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     4,     3,     4,     3,     2,     3,
       2,     1,     3,     2,     2,     1,     5,     4,     1,     3,
       1,     4,     3,     3,     2,     1,     3,     3,     1,     2,
       1,     3,     4,     2,     1,     7,     5,     3,     2,     2,
       1,     4,     2,     1,     3,     3,     1,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     5,     3,     3,     1,
       1,     4,     2,     1,     4,     1,     2,     1,     7,     5,
       1,     1,     1,     1,     3,     1,     0,     2,     3,     7,
       6,     4,     3,     2,     0,     2,     1,     3,     1,     1,
       1,     3,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     2,     2,     4,     5,     6,     7,     5,     7,
       3,    10,     8,     8,     7,     7,     5,     5,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     2,     1,     1,     3,     4,     1,
       2,     3,     4,     3,     4,     4,     5,     6,     5,     6,
       3,     1,     4,     2,     1,     3,     3,     1,     4,     1
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
#line 96 "code.y"
                                                                {}
#line 1841 "y.tab.c"
    break;

  case 3:
#line 97 "code.y"
                                                                        {}
#line 1847 "y.tab.c"
    break;

  case 4:
#line 98 "code.y"
                                                                        {}
#line 1853 "y.tab.c"
    break;

  case 5:
#line 99 "code.y"
                                                                        {}
#line 1859 "y.tab.c"
    break;

  case 6:
#line 100 "code.y"
                                                                        {}
#line 1865 "y.tab.c"
    break;

  case 7:
#line 101 "code.y"
                                                                        {}
#line 1871 "y.tab.c"
    break;

  case 8:
#line 102 "code.y"
                                                                        {}
#line 1877 "y.tab.c"
    break;

  case 9:
#line 103 "code.y"
                                                                        {}
#line 1883 "y.tab.c"
    break;

  case 10:
#line 104 "code.y"
                                                                        {}
#line 1889 "y.tab.c"
    break;

  case 11:
#line 105 "code.y"
                                                                        {}
#line 1895 "y.tab.c"
    break;

  case 12:
#line 108 "code.y"
                                                        {/*printClassTable(classTable);printf("CLASS DONE\n");*/}
#line 1901 "y.tab.c"
    break;

  case 13:
#line 109 "code.y"
                                                                {}
#line 1907 "y.tab.c"
    break;

  case 14:
#line 112 "code.y"
                                                        {}
#line 1913 "y.tab.c"
    break;

  case 15:
#line 113 "code.y"
                                                                {}
#line 1919 "y.tab.c"
    break;

  case 16:
#line 116 "code.y"
                                                                                {}
#line 1925 "y.tab.c"
    break;

  case 17:
#line 117 "code.y"
                                                                        {}
#line 1931 "y.tab.c"
    break;

  case 18:
#line 120 "code.y"
                                                                                {	
											currentClass = strdup((yyvsp[0].string));
											addToClassTable(classTable,(yyvsp[0].string),NULL);
										}
#line 1940 "y.tab.c"
    break;

  case 19:
#line 124 "code.y"
                                                                        {	
											currentClass = strdup((yyvsp[-2].string));
											addToClassTable(classTable,(yyvsp[-2].string),(yyvsp[0].string));
										}
#line 1949 "y.tab.c"
    break;

  case 20:
#line 130 "code.y"
                                                                                {	
											getMemLoc(8);
											addDeclToClassEntry(classTable, typeTable, (yyvsp[0].dno), currentClass);

										}
#line 1959 "y.tab.c"
    break;

  case 21:
#line 137 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[-1].dno));}
#line 1965 "y.tab.c"
    break;

  case 22:
#line 138 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode(NULL,(yyvsp[-1].dno));}
#line 1971 "y.tab.c"
    break;

  case 23:
#line 139 "code.y"
                                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),NULL);}
#line 1977 "y.tab.c"
    break;

  case 24:
#line 142 "code.y"
                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 1983 "y.tab.c"
    break;

  case 25:
#line 143 "code.y"
                                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 1989 "y.tab.c"
    break;

  case 26:
#line 146 "code.y"
                                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 1995 "y.tab.c"
    break;

  case 27:
#line 149 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),declIdNode((yyvsp[-2].string),0,NULL));}
#line 2001 "y.tab.c"
    break;

  case 28:
#line 150 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2007 "y.tab.c"
    break;

  case 29:
#line 153 "code.y"
                                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2013 "y.tab.c"
    break;

  case 30:
#line 154 "code.y"
                                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2019 "y.tab.c"
    break;

  case 31:
#line 157 "code.y"
                                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2025 "y.tab.c"
    break;

  case 32:
#line 160 "code.y"
                                                                {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 2031 "y.tab.c"
    break;

  case 33:
#line 163 "code.y"
                                                                {}
#line 2037 "y.tab.c"
    break;

  case 34:
#line 164 "code.y"
                                                                {}
#line 2043 "y.tab.c"
    break;

  case 35:
#line 167 "code.y"
                                                                        {	
										struct ClassTableEntry* entry = CLookup(classTable,currentClass);
										struct MethodList* method = MLookup(entry -> methodList,(yyvsp[-6].string));
										funcCodeGen((yyvsp[-2].no), fp,method -> flabel);
										lst = NULL;
									}
#line 2054 "y.tab.c"
    break;

  case 36:
#line 175 "code.y"
                                                        {	
								localMemLoc = 0;
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyMethodHead((yyvsp[-3].string),(yyvsp[-1].pt),TLookup(typeTable,(yyvsp[-4].string)),CLookup(classTable,currentClass));
								addMethodParamToLST(lst,(yyvsp[-1].pt),CLookup(classTable,currentClass));
								(yyval.string) = (yyvsp[-3].string);
							}
#line 2066 "y.tab.c"
    break;

  case 37:
#line 184 "code.y"
                                                        {/*printf("TYPE DONE\n");*/}
#line 2072 "y.tab.c"
    break;

  case 38:
#line 185 "code.y"
                                                        {}
#line 2078 "y.tab.c"
    break;

  case 39:
#line 188 "code.y"
                                                        {}
#line 2084 "y.tab.c"
    break;

  case 40:
#line 189 "code.y"
                                                {}
#line 2090 "y.tab.c"
    break;

  case 41:
#line 192 "code.y"
                                                        {addUserDefToTypeTable(typeTable,(yyvsp[-1].dno),(yyvsp[-3].string));}
#line 2096 "y.tab.c"
    break;

  case 42:
#line 195 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2102 "y.tab.c"
    break;

  case 43:
#line 196 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2108 "y.tab.c"
    break;

  case 44:
#line 199 "code.y"
                                                        {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2114 "y.tab.c"
    break;

  case 45:
#line 202 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),declIdNode((yyvsp[-2].string),0,NULL));}
#line 2120 "y.tab.c"
    break;

  case 46:
#line 203 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2126 "y.tab.c"
    break;

  case 47:
#line 207 "code.y"
                                        {	
						gst = (struct GSymbolTable*)malloc(sizeof(struct GSymbolTable));
						generateGlobalSymbolTable(gst,(yyvsp[-1].dno),NULL,NULL,typeTable,classTable);
						startCodeGen(fp,memLoc,gst,classTable);
						//printGlobalSymbolTable(gst);
					}
#line 2137 "y.tab.c"
    break;

  case 48:
#line 213 "code.y"
                                        {gst = NULL;}
#line 2143 "y.tab.c"
    break;

  case 49:
#line 216 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2149 "y.tab.c"
    break;

  case 50:
#line 217 "code.y"
                                {(yyval.dno) = (yyvsp[0].dno);}
#line 2155 "y.tab.c"
    break;

  case 51:
#line 220 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2161 "y.tab.c"
    break;

  case 52:
#line 221 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2167 "y.tab.c"
    break;

  case 53:
#line 222 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2173 "y.tab.c"
    break;

  case 54:
#line 223 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2179 "y.tab.c"
    break;

  case 55:
#line 224 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2185 "y.tab.c"
    break;

  case 56:
#line 227 "code.y"
                                        {addTupleToTypeTable(typeTable,(yyvsp[-1].pt),(yyvsp[-3].string));(yyval.string) = (yyvsp[-3].string);}
#line 2191 "y.tab.c"
    break;

  case 57:
#line 230 "code.y"
                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2197 "y.tab.c"
    break;

  case 58:
#line 233 "code.y"
                                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 2203 "y.tab.c"
    break;

  case 59:
#line 234 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2209 "y.tab.c"
    break;

  case 60:
#line 237 "code.y"
                                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2215 "y.tab.c"
    break;

  case 61:
#line 238 "code.y"
                                                        {(yyval.dno) = declFuncNode((yyvsp[-3].string),(yyvsp[-1].pt));}
#line 2221 "y.tab.c"
    break;

  case 62:
#line 241 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].dno) -> varname,(yyvsp[0].dno) -> dim + 1,(yyvsp[0].dno) -> shape);}
#line 2227 "y.tab.c"
    break;

  case 63:
#line 242 "code.y"
                                                {(yyval.dno) = (yyvsp[0].dno);}
#line 2233 "y.tab.c"
    break;

  case 64:
#line 245 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[-3].dno) -> varname,(yyvsp[-3].dno) -> dim + 1,addArrayShape((yyvsp[-3].dno) -> shape,(yyvsp[-1].number)));}
#line 2239 "y.tab.c"
    break;

  case 65:
#line 246 "code.y"
                                                {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2245 "y.tab.c"
    break;

  case 66:
#line 249 "code.y"
                                                        {}
#line 2251 "y.tab.c"
    break;

  case 67:
#line 250 "code.y"
                                                        {}
#line 2257 "y.tab.c"
    break;

  case 68:
#line 253 "code.y"
                                                        {	
									struct Gsymbol* g = GlobalLookup(gst,(yyvsp[-6].string));
									funcCodeGen((yyvsp[-2].no), fp,g -> flabel);
									lst = NULL;
								}
#line 2267 "y.tab.c"
    break;

  case 69:
#line 260 "code.y"
                                                                {
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyFuncHead(gst,(yyvsp[-3].string),TLookup(typeTable,(yyvsp[-4].string)),CLookup(classTable,(yyvsp[-4].string)),(yyvsp[-1].pt));
								addParamToLST(lst,(yyvsp[-1].pt));
								(yyval.string) = (yyvsp[-3].string);
							}
#line 2278 "y.tab.c"
    break;

  case 70:
#line 268 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2284 "y.tab.c"
    break;

  case 71:
#line 269 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2290 "y.tab.c"
    break;

  case 72:
#line 270 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2296 "y.tab.c"
    break;

  case 73:
#line 271 "code.y"
                                        {verifyFuncRetType((yyvsp[0].string),classTable);
					(yyval.string) = (yyvsp[0].string);}
#line 2303 "y.tab.c"
    break;

  case 74:
#line 275 "code.y"
                                                {(yyval.pt) = addParameter((yyvsp[-2].pt),(yyvsp[0].pt));}
#line 2309 "y.tab.c"
    break;

  case 75:
#line 276 "code.y"
                                                {(yyval.pt) = (yyvsp[0].pt);}
#line 2315 "y.tab.c"
    break;

  case 76:
#line 277 "code.y"
                                                        {(yyval.pt) = NULL;}
#line 2321 "y.tab.c"
    break;

  case 77:
#line 280 "code.y"
                                                {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-1].string),0,typeTable,classTable);}
#line 2327 "y.tab.c"
    break;

  case 78:
#line 281 "code.y"
                                                        {(yyval.pt) = makeParamStruct((yyvsp[0].string),(yyvsp[-2].string),1,typeTable,classTable);}
#line 2333 "y.tab.c"
    break;

  case 79:
#line 284 "code.y"
                                                                {	
									if(gst == NULL){
										startCodeGen(fp,-1,gst,classTable);	
										fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
									}
									funcCodeGen((yyvsp[-2].no), fp,-1);}
#line 2344 "y.tab.c"
    break;

  case 80:
#line 290 "code.y"
                                                                {exit(0);}
#line 2350 "y.tab.c"
    break;

  case 81:
#line 293 "code.y"
                                {lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));}
#line 2356 "y.tab.c"
    break;

  case 82:
#line 298 "code.y"
                                        {localMemLoc = 0; addLocalVarToLST(lst,(yyvsp[-1].dno),NULL,NULL,typeTable,classTable);}
#line 2362 "y.tab.c"
    break;

  case 83:
#line 299 "code.y"
                                        {(yyval.dno) = NULL;}
#line 2368 "y.tab.c"
    break;

  case 84:
#line 300 "code.y"
                                        {(yyval.dno) = NULL;}
#line 2374 "y.tab.c"
    break;

  case 85:
#line 303 "code.y"
                                                {(yyval.dno) = makeDConnectorNode((yyvsp[-1].dno),(yyvsp[0].dno));}
#line 2380 "y.tab.c"
    break;

  case 86:
#line 304 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2386 "y.tab.c"
    break;

  case 87:
#line 307 "code.y"
                                                {(yyval.dno) = makeDatatypeNode((yyvsp[-2].string),(yyvsp[-1].dno));}
#line 2392 "y.tab.c"
    break;

  case 88:
#line 310 "code.y"
                                        {(yyval.string) = (yyvsp[0].string);}
#line 2398 "y.tab.c"
    break;

  case 89:
#line 311 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2404 "y.tab.c"
    break;

  case 90:
#line 312 "code.y"
                                                {(yyval.string) = (yyvsp[0].string);}
#line 2410 "y.tab.c"
    break;

  case 91:
#line 315 "code.y"
                                        {(yyval.dno) = makeDConnectorNode((yyvsp[-2].dno),(yyvsp[0].dno));}
#line 2416 "y.tab.c"
    break;

  case 92:
#line 316 "code.y"
                                        {(yyval.dno) = (yyvsp[0].dno);}
#line 2422 "y.tab.c"
    break;

  case 93:
#line 320 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),0,NULL);}
#line 2428 "y.tab.c"
    break;

  case 94:
#line 321 "code.y"
                                                        {(yyval.dno) = declIdNode((yyvsp[0].string),1,NULL);}
#line 2434 "y.tab.c"
    break;

  case 95:
#line 327 "code.y"
                                                                        {(yyval.no) = makeConnectorNode((yyvsp[-1].no),(yyvsp[0].no));}
#line 2440 "y.tab.c"
    break;

  case 96:
#line 328 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2446 "y.tab.c"
    break;

  case 97:
#line 331 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2452 "y.tab.c"
    break;

  case 98:
#line 332 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2458 "y.tab.c"
    break;

  case 99:
#line 333 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2464 "y.tab.c"
    break;

  case 100:
#line 334 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2470 "y.tab.c"
    break;

  case 101:
#line 335 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2476 "y.tab.c"
    break;

  case 102:
#line 336 "code.y"
                                                                {(yyval.no) = makeJumpNode(break_node);}
#line 2482 "y.tab.c"
    break;

  case 103:
#line 337 "code.y"
                                                                        {(yyval.no) = makeJumpNode(continue_node);}
#line 2488 "y.tab.c"
    break;

  case 104:
#line 338 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,NULL);}
#line 2494 "y.tab.c"
    break;

  case 105:
#line 339 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-4].string),gst,(yyvsp[-2].at));}
#line 2500 "y.tab.c"
    break;

  case 106:
#line 340 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-5].no),(yyvsp[-3].string),NULL,typeTable);}
#line 2506 "y.tab.c"
    break;

  case 107:
#line 341 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-6].no),(yyvsp[-4].string),(yyvsp[-2].at),typeTable);}
#line 2512 "y.tab.c"
    break;

  case 108:
#line 342 "code.y"
                                                                        {(yyval.no) = makeMethodNode(makeIdNode((yyvsp[-4].string),gst,lst,NULL,typeTable,classTable),(yyvsp[-2].string),NULL,typeTable);}
#line 2518 "y.tab.c"
    break;

  case 109:
#line 343 "code.y"
                                                                        {(yyval.no) = makeMethodNode(makeIdNode((yyvsp[-6].string),gst,lst,NULL,typeTable,classTable),(yyvsp[-4].string),(yyvsp[-2].at),typeTable);}
#line 2524 "y.tab.c"
    break;

  case 110:
#line 344 "code.y"
                                                                        {(yyval.no) = makeReturnNode((yyvsp[-1].no));}
#line 2530 "y.tab.c"
    break;

  case 111:
#line 347 "code.y"
                                                                {(yyval.no) = makeIfElseBlock((yyvsp[-7].no),(yyvsp[-4].no),(yyvsp[-2].no));}
#line 2536 "y.tab.c"
    break;

  case 112:
#line 348 "code.y"
                                                                        {(yyval.no) = makeIfElseBlock((yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 2542 "y.tab.c"
    break;

  case 113:
#line 351 "code.y"
                                                                {(yyval.no) = makeWhileBlock((yyvsp[-5].no),(yyvsp[-2].no));}
#line 2548 "y.tab.c"
    break;

  case 114:
#line 352 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 2554 "y.tab.c"
    break;

  case 115:
#line 353 "code.y"
                                                                        {(yyval.no) = makeDoWhileBlock((yyvsp[-2].no),(yyvsp[-5].no));}
#line 2560 "y.tab.c"
    break;

  case 116:
#line 356 "code.y"
                                                                        {(yyval.no) = makeReadNode((yyvsp[-2].no));}
#line 2566 "y.tab.c"
    break;

  case 117:
#line 359 "code.y"
                                                                {(yyval.no) = makeWriteNode((yyvsp[-2].no));}
#line 2572 "y.tab.c"
    break;

  case 118:
#line 362 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(assign,(yyvsp[-3].no),(yyvsp[-1].no),typeTable);}
#line 2578 "y.tab.c"
    break;

  case 119:
#line 365 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(add,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2584 "y.tab.c"
    break;

  case 120:
#line 366 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(sub,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2590 "y.tab.c"
    break;

  case 121:
#line 367 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(mul,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2596 "y.tab.c"
    break;

  case 122:
#line 368 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(div,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2602 "y.tab.c"
    break;

  case 123:
#line 369 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(mod,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2608 "y.tab.c"
    break;

  case 124:
#line 370 "code.y"
                                                                {(yyval.no) = makeOperatorNode(gt,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2614 "y.tab.c"
    break;

  case 125:
#line 371 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(gte,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2620 "y.tab.c"
    break;

  case 126:
#line 372 "code.y"
                                                                {(yyval.no) = makeOperatorNode(lt,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2626 "y.tab.c"
    break;

  case 127:
#line 373 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(lte,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2632 "y.tab.c"
    break;

  case 128:
#line 374 "code.y"
                                                                {(yyval.no) = makeOperatorNode(eq,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2638 "y.tab.c"
    break;

  case 129:
#line 375 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(neq,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2644 "y.tab.c"
    break;

  case 130:
#line 376 "code.y"
                                                                        {(yyval.no) = makeOperatorNode(and,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2650 "y.tab.c"
    break;

  case 131:
#line 377 "code.y"
                                                                {(yyval.no) = makeOperatorNode(or,(yyvsp[-2].no),(yyvsp[0].no),typeTable);}
#line 2656 "y.tab.c"
    break;

  case 132:
#line 378 "code.y"
                                                                {(yyval.no) = (yyvsp[-1].no);}
#line 2662 "y.tab.c"
    break;

  case 133:
#line 379 "code.y"
                                                                        {(yyval.no) = makeNumNode((yyvsp[0].number),0,typeTable);}
#line 2668 "y.tab.c"
    break;

  case 134:
#line 380 "code.y"
                                                                        {(yyval.no) = makeNumNode(-1 * (yyvsp[0].number),0,typeTable);}
#line 2674 "y.tab.c"
    break;

  case 135:
#line 381 "code.y"
                                                                        {(yyval.no) = makeStringNode((yyvsp[0].string),typeTable);}
#line 2680 "y.tab.c"
    break;

  case 136:
#line 382 "code.y"
                                                                        {(yyval.no) = makeNullNode(typeTable);}
#line 2686 "y.tab.c"
    break;

  case 137:
#line 383 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-2].string),gst,NULL);}
#line 2692 "y.tab.c"
    break;

  case 138:
#line 384 "code.y"
                                                                        {(yyval.no) = makeFuncNode((yyvsp[-3].string),gst,(yyvsp[-1].at));}
#line 2698 "y.tab.c"
    break;

  case 139:
#line 385 "code.y"
                                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2704 "y.tab.c"
    break;

  case 140:
#line 386 "code.y"
                                                                        {(yyval.no) = makeAddrNode((yyvsp[0].no),gst,lst,typeTable);}
#line 2710 "y.tab.c"
    break;

  case 141:
#line 387 "code.y"
                                                                        {(yyval.no) = makeTypeAllocNode();}
#line 2716 "y.tab.c"
    break;

  case 142:
#line 388 "code.y"
                                                                        {(yyval.no) = makeClassAllocNode((yyvsp[-1].string),classTable);}
#line 2722 "y.tab.c"
    break;

  case 143:
#line 389 "code.y"
                                                                        {(yyval.no) = makeMemInitNode(typeTable);}
#line 2728 "y.tab.c"
    break;

  case 144:
#line 390 "code.y"
                                                                        {(yyval.no) = makeFreeNode((yyvsp[-1].no),typeTable);}
#line 2734 "y.tab.c"
    break;

  case 145:
#line 391 "code.y"
                                                                        {(yyval.no) = makeDeleteNode((yyvsp[-1].no),typeTable);}
#line 2740 "y.tab.c"
    break;

  case 146:
#line 392 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-4].no),(yyvsp[-2].string),NULL,typeTable);}
#line 2746 "y.tab.c"
    break;

  case 147:
#line 393 "code.y"
                                                                        {(yyval.no) = makeMethodNode((yyvsp[-5].no),(yyvsp[-3].string),(yyvsp[-1].at),typeTable);}
#line 2752 "y.tab.c"
    break;

  case 148:
#line 394 "code.y"
                                                                        {(yyval.no) = makeMethodNode(makeIdNode((yyvsp[-4].string),gst,lst,NULL,typeTable,classTable),(yyvsp[-2].string),NULL,typeTable);}
#line 2758 "y.tab.c"
    break;

  case 149:
#line 395 "code.y"
                                                                {(yyval.no) = makeMethodNode(makeIdNode((yyvsp[-5].string),gst,lst,NULL,typeTable,classTable),(yyvsp[-3].string),(yyvsp[-1].at),typeTable);}
#line 2764 "y.tab.c"
    break;

  case 150:
#line 398 "code.y"
                                        {(yyval.at) = addArguments((yyvsp[-2].at),makeArgStruct((yyvsp[0].no)),typeTable);}
#line 2770 "y.tab.c"
    break;

  case 151:
#line 399 "code.y"
                                        {(yyval.at) = makeArgStruct((yyvsp[0].no));}
#line 2776 "y.tab.c"
    break;

  case 152:
#line 402 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[-1].no),typeTable);}
#line 2782 "y.tab.c"
    break;

  case 153:
#line 403 "code.y"
                                        {(yyval.no) = makePtrNode((yyvsp[0].no),typeTable);}
#line 2788 "y.tab.c"
    break;

  case 154:
#line 404 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2794 "y.tab.c"
    break;

  case 155:
#line 407 "code.y"
                                                {(yyval.no) = extendTypeNode((yyvsp[-2].no),(yyvsp[0].string),typeTable);}
#line 2800 "y.tab.c"
    break;

  case 156:
#line 408 "code.y"
                                                {(yyval.no) = extendClassNode(makeIdNode((yyvsp[-2].string),gst,lst,NULL,typeTable,classTable),(yyvsp[0].string),classTable);}
#line 2806 "y.tab.c"
    break;

  case 157:
#line 409 "code.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2812 "y.tab.c"
    break;

  case 158:
#line 412 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[-3].no) -> varname,gst,lst,addArrayDim((yyvsp[-3].no) -> indices,(yyvsp[-1].no)),typeTable,classTable);}
#line 2818 "y.tab.c"
    break;

  case 159:
#line 413 "code.y"
                                                {(yyval.no) = makeIdNode((yyvsp[0].string),gst,lst,NULL,typeTable,classTable);}
#line 2824 "y.tab.c"
    break;


#line 2828 "y.tab.c"

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
#line 416 "code.y"


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