/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "mml_parser.y"

//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!

#line 85 "mml_parser.tab.c"

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

#include "mml_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tIF = 3,                        /* tIF  */
  YYSYMBOL_tBEGIN = 4,                     /* tBEGIN  */
  YYSYMBOL_tEND = 5,                       /* tEND  */
  YYSYMBOL_tFOREIGN = 6,                   /* tFOREIGN  */
  YYSYMBOL_tFORWARD = 7,                   /* tFORWARD  */
  YYSYMBOL_tPUBLIC = 8,                    /* tPUBLIC  */
  YYSYMBOL_tAUTO = 9,                      /* tAUTO  */
  YYSYMBOL_tPRIVATE = 10,                  /* tPRIVATE  */
  YYSYMBOL_tINPUT = 11,                    /* tINPUT  */
  YYSYMBOL_tPRINT = 12,                    /* tPRINT  */
  YYSYMBOL_tPRINTLN = 13,                  /* tPRINTLN  */
  YYSYMBOL_tWHILE = 14,                    /* tWHILE  */
  YYSYMBOL_tSTOP = 15,                     /* tSTOP  */
  YYSYMBOL_tNEXT = 16,                     /* tNEXT  */
  YYSYMBOL_tRETURN = 17,                   /* tRETURN  */
  YYSYMBOL_tSIZEOF = 18,                   /* tSIZEOF  */
  YYSYMBOL_tTYPE_STRING = 19,              /* tTYPE_STRING  */
  YYSYMBOL_tTYPE_INTEGER = 20,             /* tTYPE_INTEGER  */
  YYSYMBOL_tTYPE_DOUBLE = 21,              /* tTYPE_DOUBLE  */
  YYSYMBOL_tTYPE_VOID = 22,                /* tTYPE_VOID  */
  YYSYMBOL_tARROW = 23,                    /* tARROW  */
  YYSYMBOL_tINTEGER = 24,                  /* tINTEGER  */
  YYSYMBOL_tDOUBLE = 25,                   /* tDOUBLE  */
  YYSYMBOL_tSTRING = 26,                   /* tSTRING  */
  YYSYMBOL_tNULLPTR = 27,                  /* tNULLPTR  */
  YYSYMBOL_tIDENTIFIER = 28,               /* tIDENTIFIER  */
  YYSYMBOL_29_ = 29,                       /* '='  */
  YYSYMBOL_tADDRESS = 30,                  /* tADDRESS  */
  YYSYMBOL_tOR = 31,                       /* tOR  */
  YYSYMBOL_tAND = 32,                      /* tAND  */
  YYSYMBOL_tNOT = 33,                      /* tNOT  */
  YYSYMBOL_tEQ = 34,                       /* tEQ  */
  YYSYMBOL_tNE = 35,                       /* tNE  */
  YYSYMBOL_36_ = 36,                       /* '<'  */
  YYSYMBOL_37_ = 37,                       /* '>'  */
  YYSYMBOL_tLE = 38,                       /* tLE  */
  YYSYMBOL_tGE = 39,                       /* tGE  */
  YYSYMBOL_40_ = 40,                       /* '+'  */
  YYSYMBOL_41_ = 41,                       /* '-'  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '/'  */
  YYSYMBOL_44_ = 44,                       /* '%'  */
  YYSYMBOL_45_ = 45,                       /* '@'  */
  YYSYMBOL_tUNARY = 46,                    /* tUNARY  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* '['  */
  YYSYMBOL_tIFX = 49,                      /* tIFX  */
  YYSYMBOL_tELIF = 50,                     /* tELIF  */
  YYSYMBOL_tELSE = 51,                     /* tELSE  */
  YYSYMBOL_52_ = 52,                       /* ';'  */
  YYSYMBOL_53_ = 53,                       /* ']'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* '{'  */
  YYSYMBOL_57_ = 57,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_file = 59,                      /* file  */
  YYSYMBOL_main_program = 60,              /* main_program  */
  YYSYMBOL_declaration = 61,               /* declaration  */
  YYSYMBOL_declarations = 62,              /* declarations  */
  YYSYMBOL_opt_decs = 63,                  /* opt_decs  */
  YYSYMBOL_qualifier = 64,                 /* qualifier  */
  YYSYMBOL_type = 65,                      /* type  */
  YYSYMBOL_auto = 66,                      /* auto  */
  YYSYMBOL_types = 67,                     /* types  */
  YYSYMBOL_opt_init = 68,                  /* opt_init  */
  YYSYMBOL_instruction = 69,               /* instruction  */
  YYSYMBOL_cond_inst = 70,                 /* cond_inst  */
  YYSYMBOL_elif = 71,                      /* elif  */
  YYSYMBOL_iter_inst = 72,                 /* iter_inst  */
  YYSYMBOL_instructions = 73,              /* instructions  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_expressions = 75,               /* expressions  */
  YYSYMBOL_opt_expressions = 76,           /* opt_expressions  */
  YYSYMBOL_lval = 77,                      /* lval  */
  YYSYMBOL_arg = 78,                       /* arg  */
  YYSYMBOL_args = 79,                      /* args  */
  YYSYMBOL_block = 80,                     /* block  */
  YYSYMBOL_func_def = 81,                  /* func_def  */
  YYSYMBOL_string = 82                     /* string  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 81 "mml_parser.y"

//-- The rules below will be included in yyparse, the main parsing function.

#line 205 "mml_parser.tab.c"


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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   867

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    44,     2,     2,
      47,    55,    42,    40,    54,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
      36,    29,    37,     2,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    53,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    30,    31,    32,    33,    34,    35,
      38,    39,    46,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    86,    86,    87,    90,    91,    92,    93,    96,    97,
      98,    99,   100,   103,   104,   107,   108,   111,   112,   113,
     116,   117,   118,   119,   120,   121,   122,   125,   128,   129,
     132,   133,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   149,   150,   152,   153,   154,   157,   160,
     161,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   196,   197,   200,   201,   204,   205,   208,   211,   212,
     213,   216,   217,   218,   219,   222,   223,   226,   227
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tIF", "tBEGIN",
  "tEND", "tFOREIGN", "tFORWARD", "tPUBLIC", "tAUTO", "tPRIVATE", "tINPUT",
  "tPRINT", "tPRINTLN", "tWHILE", "tSTOP", "tNEXT", "tRETURN", "tSIZEOF",
  "tTYPE_STRING", "tTYPE_INTEGER", "tTYPE_DOUBLE", "tTYPE_VOID", "tARROW",
  "tINTEGER", "tDOUBLE", "tSTRING", "tNULLPTR", "tIDENTIFIER", "'='",
  "tADDRESS", "tOR", "tAND", "tNOT", "tEQ", "tNE", "'<'", "'>'", "tLE",
  "tGE", "'+'", "'-'", "'*'", "'/'", "'%'", "'@'", "tUNARY", "'('", "'['",
  "tIFX", "tELIF", "tELSE", "';'", "']'", "','", "')'", "'{'", "'}'",
  "$accept", "file", "main_program", "declaration", "declarations",
  "opt_decs", "qualifier", "type", "auto", "types", "opt_init",
  "instruction", "cond_inst", "elif", "iter_inst", "instructions",
  "expression", "expressions", "opt_expressions", "lval", "arg", "args",
  "block", "func_def", "string", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-69)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,     9,
       4,   -69,     3,    23,   382,    53,     6,    -3,   -69,   -69,
     280,   -69,    16,    64,    24,    36,   130,    57,   -69,    41,
     -69,   -69,    55,     2,    12,   511,    89,   -69,   -69,   -69,
     -69,   -69,   511,   511,   511,    97,   486,   486,    90,   326,
     -69,   -69,   -69,   372,   679,     8,   -27,   -69,   -69,   114,
     511,    36,   116,   511,    96,   -69,   117,    85,   511,   511,
     511,   102,   -69,   105,   -69,   511,   698,   511,   806,    77,
      77,   511,    93,   529,   -69,    73,   639,   -69,   155,   190,
     -69,   418,   -69,   -69,   511,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   -69,
     -69,   -69,   511,   511,   -69,   -69,   717,   107,   511,   774,
     -69,   -69,     9,   736,   551,   573,   -69,   -69,   -69,   595,
     774,   111,   113,   -69,   -69,     9,   164,   -69,   -69,   225,
     -69,   -69,   791,   806,   819,   819,   220,   220,   220,   220,
     142,   142,    77,    77,    77,   136,   659,   774,   774,   -69,
     -69,   755,   117,   -69,   453,   453,   -69,   -69,   -69,    39,
     -69,   -69,   -69,   -69,    82,   -69,    47,   138,   145,   453,
     -69,   -69,   -69,   511,   -69,   617,   453,    82,   -69
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      15,    17,    18,    19,    27,    22,    20,    21,    23,     0,
       0,    13,    16,     2,     0,     0,     0,     0,     1,    14,
       0,     3,     0,     0,     0,    30,     0,     0,    24,     0,
       7,    73,     0,     0,     0,     0,     0,    51,    52,    97,
      54,    85,     0,     0,     0,     0,    88,     0,     0,     0,
      49,    40,    41,     0,    81,     0,    71,    42,    80,    53,
       0,    30,     0,     0,     0,    25,    28,     0,     0,     0,
       0,     0,    35,     0,    37,     0,     0,     0,    57,    55,
      56,    83,     0,     0,    89,     0,     0,    94,     0,     0,
       5,     0,     6,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,    32,
      33,    34,     0,     0,    75,    98,     0,     0,     0,    31,
       8,    26,     0,     0,     0,     0,    36,    38,    39,     0,
      81,    84,     0,    87,    79,     0,     0,    76,    92,     0,
      93,     4,    69,    70,    68,    67,    63,    64,    66,    65,
      58,    59,    60,    61,    62,     0,     0,    82,    72,    12,
      10,     0,    29,     9,     0,     0,    74,    78,    90,     0,
      91,    77,    86,    11,    43,    48,     0,     0,     0,     0,
      44,    95,    96,     0,    45,     0,     0,    46,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -69,   -69,   -69,    -6,    43,   -69,   -69,    -9,   -13,   -69,
     137,   -45,   -69,    10,   -69,     7,   -28,   -68,    92,   -69,
      74,   -69,   -34,   -69,   -69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    21,    11,    12,    13,    14,    15,    16,    67,
      64,    50,    51,   180,    52,    53,    54,    55,   132,    56,
      84,    85,    57,    58,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      17,    24,   113,   114,    18,    23,    19,    76,    93,     1,
       2,     3,     4,   131,    78,    79,    80,    66,    83,    86,
     110,   111,     5,     6,     7,     8,    71,    20,     5,     6,
       7,     8,   116,    26,    27,   119,    73,    82,    17,   131,
     123,   124,   125,    19,    93,    60,    93,    86,     4,   129,
      28,     9,    62,   130,    72,    89,    91,     9,     5,     6,
       7,     8,   112,    49,    74,    63,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   130,
     156,    25,    19,    26,   157,   158,    68,     9,    69,    26,
     161,    88,    61,    29,    93,   139,     1,     2,     3,     4,
      26,    31,    70,    48,    32,    33,    34,    35,    36,     5,
       6,     7,     8,   162,    37,    38,    39,    40,    41,   174,
     175,   133,   121,    42,   107,   108,    82,   135,   136,    26,
      43,    44,   178,   179,   184,    45,    77,    46,    47,   122,
     115,   187,   181,   182,    81,   118,    48,    87,   120,     5,
       6,     7,     8,    26,   126,   185,   177,   127,    29,   160,
     176,     1,     2,     3,     4,   112,    31,    65,   167,    32,
      33,    34,    35,    36,     5,     6,     7,     8,     9,    37,
      38,    39,    40,    41,   104,   105,   106,   169,    42,   107,
     108,   171,   183,    29,    48,    43,    44,   188,   117,   155,
      45,    31,    46,    47,    32,    33,    34,    35,    36,   168,
       0,    48,   138,     0,    37,    38,    39,    40,    41,     0,
       0,     0,     0,    42,     0,     0,     0,     0,    29,     0,
      43,    44,     0,     0,     0,    45,    31,    46,    75,    32,
      33,    34,    35,    36,     0,     0,    48,   140,     0,    37,
      38,    39,    40,    41,     0,     0,     0,     0,    42,     0,
     102,   103,   104,   105,   106,    43,    44,   107,   108,     0,
      45,     0,    46,    75,     0,     0,     0,     0,     0,     0,
       0,    48,   170,    29,     0,    30,     1,     2,     3,     4,
       0,    31,     0,     0,    32,    33,    34,    35,    36,     5,
       6,     7,     8,     0,    37,    38,    39,    40,    41,     0,
       0,     0,     0,    42,     0,     0,     0,     0,     0,     0,
      43,    44,     0,     0,     0,    45,     0,    46,    47,    29,
       0,    90,     1,     2,     3,     4,    48,    31,     0,     0,
      32,    33,    34,    35,    36,     5,     6,     7,     8,     0,
      37,    38,    39,    40,    41,     0,     0,     0,     0,    42,
       0,     0,     0,     0,     0,     0,    43,    44,     0,     0,
       0,    45,     0,    46,    47,    29,     0,    92,     0,     0,
       0,     0,    48,    31,     0,     0,    32,    33,    34,    35,
      36,     4,     0,     0,     0,     0,    37,    38,    39,    40,
      41,     5,     6,     7,     8,    42,     0,     0,     0,     0,
      22,     0,    43,    44,     0,     0,     0,    45,     0,    46,
      75,    29,     0,   141,     0,     0,     0,     0,    48,    31,
       9,     0,    32,    33,    34,    35,    36,     0,     0,     0,
       0,     0,    37,    38,    39,    40,    41,     0,     0,     0,
       0,    42,     0,     0,     0,     0,    29,     0,    43,    44,
       0,     0,     0,    45,    31,    46,    75,    32,    33,    34,
      35,    36,     0,     0,    48,     0,     0,    37,    38,    39,
      40,    41,     0,     0,     0,     0,    42,     0,     0,     0,
       0,     0,     0,    43,    44,     0,     0,    31,    45,     0,
      46,    75,     0,     0,    36,     5,     6,     7,     8,    48,
      37,    38,    39,    40,    41,     0,     0,     0,     0,    42,
       0,     0,    31,     0,     0,     0,    43,    44,     0,    36,
       0,    45,     0,    46,    47,    37,    38,    39,    40,    41,
       0,     0,     0,     0,    42,     0,     0,     0,     0,     0,
       0,    43,    44,     0,     0,     0,    45,     0,    46,    75,
      94,    95,     0,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,   107,   108,     0,     0,
       0,     0,    94,    95,   134,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,     0,   107,   108,
       0,     0,     0,     0,    94,    95,   164,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     0,     0,
     107,   108,     0,     0,     0,     0,    94,    95,   165,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,   107,   108,     0,     0,     0,     0,    94,    95,
     166,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,   107,   108,     0,     0,     0,     0,
      94,    95,   186,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,   107,   108,     0,     0,
      94,    95,   137,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,   107,   108,     0,     0,
      94,    95,   172,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,   107,   108,     0,    94,
      95,   109,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,   107,   108,     0,    94,    95,
     128,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,   107,   108,     0,    94,    95,   159,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,     0,   107,   108,     0,    94,    95,   163,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,   107,   108,     0,    94,    95,   173,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
       0,   107,   108,    95,     0,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,     0,   107,   108,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,     0,   107,   108,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,   107,   108
};

static const yytype_int16 yycheck[] =
{
       9,    14,    29,    30,     0,    14,    12,    35,    53,     6,
       7,     8,     9,    81,    42,    43,    44,    26,    46,    47,
      12,    13,    19,    20,    21,    22,    24,     4,    19,    20,
      21,    22,    60,    36,    28,    63,    24,    46,    47,   107,
      68,    69,    70,    49,    89,    29,    91,    75,     9,    77,
      53,    48,    28,    81,    52,    48,    49,    48,    19,    20,
      21,    22,    54,    20,    52,    29,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    28,    88,    36,   112,   113,    29,    48,    47,    36,
     118,    48,    28,     3,   139,    88,     6,     7,     8,     9,
      36,    11,    47,    56,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   122,    24,    25,    26,    27,    28,   164,
     165,    28,    37,    33,    47,    48,   135,    54,    55,    36,
      40,    41,    50,    51,   179,    45,    47,    47,    48,    54,
      26,   186,   176,   177,    47,    29,    56,    57,    52,    19,
      20,    21,    22,    36,    52,   183,   169,    52,     3,    52,
     169,     6,     7,     8,     9,    54,    11,    37,    55,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    48,    24,
      25,    26,    27,    28,    42,    43,    44,    23,    33,    47,
      48,    55,    47,     3,    56,    40,    41,   187,    61,   107,
      45,    11,    47,    48,    14,    15,    16,    17,    18,   135,
      -1,    56,    57,    -1,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,     3,    -1,
      40,    41,    -1,    -1,    -1,    45,    11,    47,    48,    14,
      15,    16,    17,    18,    -1,    -1,    56,    57,    -1,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    33,    -1,
      40,    41,    42,    43,    44,    40,    41,    47,    48,    -1,
      45,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,     3,    -1,     5,     6,     7,     8,     9,
      -1,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    45,    -1,    47,    48,     3,
      -1,     5,     6,     7,     8,     9,    56,    11,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
      -1,    45,    -1,    47,    48,     3,    -1,     5,    -1,    -1,
      -1,    -1,    56,    11,    -1,    -1,    14,    15,    16,    17,
      18,     9,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      28,    19,    20,    21,    22,    33,    -1,    -1,    -1,    -1,
      28,    -1,    40,    41,    -1,    -1,    -1,    45,    -1,    47,
      48,     3,    -1,     5,    -1,    -1,    -1,    -1,    56,    11,
      48,    -1,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,     3,    -1,    40,    41,
      -1,    -1,    -1,    45,    11,    47,    48,    14,    15,    16,
      17,    18,    -1,    -1,    56,    -1,    -1,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    -1,    -1,    11,    45,    -1,
      47,    48,    -1,    -1,    18,    19,    20,    21,    22,    56,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    11,    -1,    -1,    -1,    40,    41,    -1,    18,
      -1,    45,    -1,    47,    48,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    45,    -1,    47,    48,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    -1,    -1,
      -1,    -1,    31,    32,    55,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    31,    32,    55,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    31,    32,    55,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    31,    32,
      55,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      31,    32,    55,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    -1,    -1,
      31,    32,    53,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    -1,    -1,
      31,    32,    53,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48,    -1,    31,
      32,    52,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    47,    48,    -1,    31,    32,
      52,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    48,    -1,    31,    32,    52,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    -1,    31,    32,    52,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    48,    -1,    31,    32,    52,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    48,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,     9,    19,    20,    21,    22,    48,
      59,    61,    62,    63,    64,    65,    66,    65,     0,    61,
       4,    60,    28,    65,    66,    28,    36,    28,    53,     3,
       5,    11,    14,    15,    16,    17,    18,    24,    25,    26,
      27,    28,    33,    40,    41,    45,    47,    48,    56,    62,
      69,    70,    72,    73,    74,    75,    77,    80,    81,    82,
      29,    28,    28,    29,    68,    37,    65,    67,    29,    47,
      47,    24,    52,    24,    52,    48,    74,    47,    74,    74,
      74,    47,    65,    74,    78,    79,    74,    57,    62,    73,
       5,    73,     5,    69,    31,    32,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    47,    48,    52,
      12,    13,    54,    29,    30,    26,    74,    68,    29,    74,
      52,    37,    54,    74,    74,    74,    52,    52,    52,    74,
      74,    75,    76,    28,    55,    54,    55,    53,    57,    73,
      57,     5,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    76,    74,    74,    74,    52,
      52,    74,    65,    52,    55,    55,    55,    55,    78,    23,
      57,    55,    53,    52,    69,    69,    65,    66,    50,    51,
      71,    80,    80,    47,    69,    74,    55,    69,    71
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    60,    60,    61,    61,
      61,    61,    61,    62,    62,    63,    63,    64,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    71,    71,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    77,    77,    78,    79,    79,
      79,    80,    80,    80,    80,    81,    81,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     4,     3,     3,     2,     4,     5,
       5,     6,     5,     1,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     1,     1,     3,
       0,     2,     2,     2,     2,     2,     3,     2,     3,     3,
       1,     1,     1,     5,     6,     2,     5,     6,     5,     1,
       2,     1,     1,     1,     1,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     4,     2,     3,     4,     4,     3,
       1,     1,     3,     0,     1,     1,     4,     2,     0,     1,
       3,     4,     3,     3,     2,     6,     6,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (compiler, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (compiler);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, compiler);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, std::shared_ptr<cdk::compiler> compiler)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YY_USE (yyvaluep);
  YY_USE (compiler);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (std::shared_ptr<cdk::compiler> compiler)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* file: opt_decs  */
#line 86 "mml_parser.y"
                                      { compiler->ast((yyval.sequence) = (yyvsp[0].sequence)); }
#line 1420 "mml_parser.tab.c"
    break;

  case 3: /* file: opt_decs main_program  */
#line 87 "mml_parser.y"
                                      { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence))); }
#line 1426 "mml_parser.tab.c"
    break;

  case 4: /* main_program: tBEGIN declarations instructions tEND  */
#line 90 "mml_parser.y"
                                                      { (yyval.node) = new mml::function_definition_node(LINE, nullptr, nullptr, new mml::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)), true); }
#line 1432 "mml_parser.tab.c"
    break;

  case 5: /* main_program: tBEGIN declarations tEND  */
#line 91 "mml_parser.y"
                                                      { (yyval.node) = new mml::function_definition_node(LINE, nullptr, nullptr, new mml::block_node(LINE, (yyvsp[-1].sequence), nullptr), true); }
#line 1438 "mml_parser.tab.c"
    break;

  case 6: /* main_program: tBEGIN instructions tEND  */
#line 92 "mml_parser.y"
                                                      { (yyval.node) = new mml::function_definition_node(LINE, nullptr, nullptr, new mml::block_node(LINE, nullptr, (yyvsp[-1].sequence)), true); }
#line 1444 "mml_parser.tab.c"
    break;

  case 7: /* main_program: tBEGIN tEND  */
#line 93 "mml_parser.y"
                                                      { (yyval.node) = new mml::function_definition_node(LINE, nullptr, nullptr, new mml::block_node(LINE, nullptr, nullptr), true); }
#line 1450 "mml_parser.tab.c"
    break;

  case 8: /* declaration: type tIDENTIFIER opt_init ';'  */
#line 96 "mml_parser.y"
                                                              { (yyval.node) = new mml::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-3].type),      *(yyvsp[-2].s), (yyvsp[-1].expression)); delete (yyvsp[-2].s); }
#line 1456 "mml_parser.tab.c"
    break;

  case 9: /* declaration: auto tIDENTIFIER '=' expression ';'  */
#line 97 "mml_parser.y"
                                                              { (yyval.node) = new mml::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-4].type),      *(yyvsp[-3].s), (yyvsp[-1].expression)); delete (yyvsp[-3].s); }
#line 1462 "mml_parser.tab.c"
    break;

  case 10: /* declaration: qualifier type tIDENTIFIER opt_init ';'  */
#line 98 "mml_parser.y"
                                                              { (yyval.node) = new mml::variable_declaration_node(LINE, (yyvsp[-4].i),       (yyvsp[-3].type),      *(yyvsp[-2].s), (yyvsp[-1].expression)); delete (yyvsp[-2].s); }
#line 1468 "mml_parser.tab.c"
    break;

  case 11: /* declaration: qualifier auto tIDENTIFIER '=' expression ';'  */
#line 99 "mml_parser.y"
                                                              { (yyval.node) = new mml::variable_declaration_node(LINE, (yyvsp[-5].i),       (yyvsp[-4].type), *(yyvsp[-3].s), (yyvsp[-1].expression)); delete (yyvsp[-3].s); }
#line 1474 "mml_parser.tab.c"
    break;

  case 12: /* declaration: qualifier tIDENTIFIER '=' expression ';'  */
#line 100 "mml_parser.y"
                                                              { (yyval.node) = new mml::variable_declaration_node(LINE, (yyvsp[-4].i),       cdk::primitive_type::create(0, cdk::TYPE_UNSPEC), *(yyvsp[-3].s), (yyvsp[-1].expression)); delete (yyvsp[-3].s); }
#line 1480 "mml_parser.tab.c"
    break;

  case 13: /* declarations: declaration  */
#line 103 "mml_parser.y"
                                         { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1486 "mml_parser.tab.c"
    break;

  case 14: /* declarations: declarations declaration  */
#line 104 "mml_parser.y"
                                         { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1492 "mml_parser.tab.c"
    break;

  case 15: /* opt_decs: %empty  */
#line 107 "mml_parser.y"
                             { (yyval.sequence) = NULL; }
#line 1498 "mml_parser.tab.c"
    break;

  case 16: /* opt_decs: declarations  */
#line 108 "mml_parser.y"
                             { (yyval.sequence) = (yyvsp[0].sequence);   }
#line 1504 "mml_parser.tab.c"
    break;

  case 17: /* qualifier: tFOREIGN  */
#line 111 "mml_parser.y"
                         { (yyval.i) = tFOREIGN; }
#line 1510 "mml_parser.tab.c"
    break;

  case 18: /* qualifier: tFORWARD  */
#line 112 "mml_parser.y"
                         { (yyval.i) = tFORWARD; }
#line 1516 "mml_parser.tab.c"
    break;

  case 19: /* qualifier: tPUBLIC  */
#line 113 "mml_parser.y"
                         { (yyval.i) = tPUBLIC;  }
#line 1522 "mml_parser.tab.c"
    break;

  case 20: /* type: tTYPE_INTEGER  */
#line 116 "mml_parser.y"
                              { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT); }
#line 1528 "mml_parser.tab.c"
    break;

  case 21: /* type: tTYPE_DOUBLE  */
#line 117 "mml_parser.y"
                              { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE); }
#line 1534 "mml_parser.tab.c"
    break;

  case 22: /* type: tTYPE_STRING  */
#line 118 "mml_parser.y"
                              { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING); }
#line 1540 "mml_parser.tab.c"
    break;

  case 23: /* type: tTYPE_VOID  */
#line 119 "mml_parser.y"
                              { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_VOID); }
#line 1546 "mml_parser.tab.c"
    break;

  case 24: /* type: '[' type ']'  */
#line 120 "mml_parser.y"
                                   { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 1552 "mml_parser.tab.c"
    break;

  case 25: /* type: type '<' '>'  */
#line 121 "mml_parser.y"
                                   { (yyval.type) = cdk::functional_type::create((yyvsp[-2].type)); }
#line 1558 "mml_parser.tab.c"
    break;

  case 26: /* type: type '<' types '>'  */
#line 122 "mml_parser.y"
                                   { (yyval.type) = cdk::functional_type::create(*(yyvsp[-1].type_vec), (yyvsp[-3].type)); delete (yyvsp[-1].type_vec); }
#line 1564 "mml_parser.tab.c"
    break;

  case 27: /* auto: tAUTO  */
#line 125 "mml_parser.y"
                      { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_UNSPEC); }
#line 1570 "mml_parser.tab.c"
    break;

  case 28: /* types: type  */
#line 128 "mml_parser.y"
                               { (yyval.type_vec) = new std::vector<std::shared_ptr<cdk::basic_type>>(); (yyval.type_vec)->push_back((yyvsp[0].type)); }
#line 1576 "mml_parser.tab.c"
    break;

  case 29: /* types: types ',' type  */
#line 129 "mml_parser.y"
                               { (yyval.type_vec) = (yyvsp[-2].type_vec); (yyval.type_vec)->push_back((yyvsp[0].type)); }
#line 1582 "mml_parser.tab.c"
    break;

  case 30: /* opt_init: %empty  */
#line 132 "mml_parser.y"
                                    { (yyval.expression) = nullptr; }
#line 1588 "mml_parser.tab.c"
    break;

  case 31: /* opt_init: '=' expression  */
#line 133 "mml_parser.y"
                                    { (yyval.expression) = (yyvsp[0].expression); }
#line 1594 "mml_parser.tab.c"
    break;

  case 32: /* instruction: expression ';'  */
#line 136 "mml_parser.y"
                                       { (yyval.node) = new mml::evaluation_node(LINE, (yyvsp[-1].expression));      }
#line 1600 "mml_parser.tab.c"
    break;

  case 33: /* instruction: expressions tPRINT  */
#line 137 "mml_parser.y"
                                       { (yyval.node) = new mml::print_node(LINE, (yyvsp[-1].sequence));           }
#line 1606 "mml_parser.tab.c"
    break;

  case 34: /* instruction: expressions tPRINTLN  */
#line 138 "mml_parser.y"
                                       { (yyval.node) = new mml::print_node(LINE, (yyvsp[-1].sequence), true);     }
#line 1612 "mml_parser.tab.c"
    break;

  case 35: /* instruction: tSTOP ';'  */
#line 139 "mml_parser.y"
                                       { (yyval.node) = new mml::stop_node(LINE);                }
#line 1618 "mml_parser.tab.c"
    break;

  case 36: /* instruction: tSTOP tINTEGER ';'  */
#line 140 "mml_parser.y"
                                       { (yyval.node) = new mml::stop_node(LINE, (yyvsp[-1].i));            }
#line 1624 "mml_parser.tab.c"
    break;

  case 37: /* instruction: tNEXT ';'  */
#line 141 "mml_parser.y"
                                       { (yyval.node) = new mml::next_node(LINE);                }
#line 1630 "mml_parser.tab.c"
    break;

  case 38: /* instruction: tNEXT tINTEGER ';'  */
#line 142 "mml_parser.y"
                                       { (yyval.node) = new mml::next_node(LINE, (yyvsp[-1].i));            }
#line 1636 "mml_parser.tab.c"
    break;

  case 39: /* instruction: tRETURN expression ';'  */
#line 143 "mml_parser.y"
                                       { (yyval.node) = new mml::return_node(LINE, (yyvsp[-1].expression));          }
#line 1642 "mml_parser.tab.c"
    break;

  case 40: /* instruction: cond_inst  */
#line 144 "mml_parser.y"
                                       { (yyval.node) = (yyvsp[0].node);                                      }
#line 1648 "mml_parser.tab.c"
    break;

  case 41: /* instruction: iter_inst  */
#line 145 "mml_parser.y"
                                       { (yyval.node) = (yyvsp[0].node);                                      }
#line 1654 "mml_parser.tab.c"
    break;

  case 42: /* instruction: block  */
#line 146 "mml_parser.y"
                                       { (yyval.node) = (yyvsp[0].block);                                      }
#line 1660 "mml_parser.tab.c"
    break;

  case 43: /* cond_inst: tIF '(' expression ')' instruction  */
#line 149 "mml_parser.y"
                                                                  { (yyval.node) = new mml::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node));          }
#line 1666 "mml_parser.tab.c"
    break;

  case 44: /* cond_inst: tIF '(' expression ')' instruction elif  */
#line 150 "mml_parser.y"
                                                                  { (yyval.node) = new mml::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1672 "mml_parser.tab.c"
    break;

  case 45: /* elif: tELSE instruction  */
#line 152 "mml_parser.y"
                                                                  { (yyval.node) = (yyvsp[0].node); }
#line 1678 "mml_parser.tab.c"
    break;

  case 46: /* elif: tELIF '(' expression ')' instruction  */
#line 153 "mml_parser.y"
                                                                  { (yyval.node) = new mml::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1684 "mml_parser.tab.c"
    break;

  case 47: /* elif: tELIF '(' expression ')' instruction elif  */
#line 154 "mml_parser.y"
                                                                  { (yyval.node) = new mml::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1690 "mml_parser.tab.c"
    break;

  case 48: /* iter_inst: tWHILE '(' expression ')' instruction  */
#line 157 "mml_parser.y"
                                                                     { (yyval.node) = new mml::while_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node));       }
#line 1696 "mml_parser.tab.c"
    break;

  case 49: /* instructions: instruction  */
#line 160 "mml_parser.y"
                                         { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1702 "mml_parser.tab.c"
    break;

  case 50: /* instructions: instructions instruction  */
#line 161 "mml_parser.y"
                                         { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1708 "mml_parser.tab.c"
    break;

  case 51: /* expression: tINTEGER  */
#line 164 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i));                        }
#line 1714 "mml_parser.tab.c"
    break;

  case 52: /* expression: tDOUBLE  */
#line 165 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d));                         }
#line 1720 "mml_parser.tab.c"
    break;

  case 53: /* expression: string  */
#line 166 "mml_parser.y"
                                                           { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s));                         }
#line 1726 "mml_parser.tab.c"
    break;

  case 54: /* expression: tNULLPTR  */
#line 167 "mml_parser.y"
                                                     { (yyval.expression) = new mml::nullptr_node(LINE);                            }
#line 1732 "mml_parser.tab.c"
    break;

  case 55: /* expression: '+' expression  */
#line 168 "mml_parser.y"
                                                     { (yyval.expression) = new mml::identity_node(LINE, (yyvsp[0].expression));                       }
#line 1738 "mml_parser.tab.c"
    break;

  case 56: /* expression: '-' expression  */
#line 169 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::neg_node(LINE, (yyvsp[0].expression));                            }
#line 1744 "mml_parser.tab.c"
    break;

  case 57: /* expression: tNOT expression  */
#line 170 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[0].expression));                            }
#line 1750 "mml_parser.tab.c"
    break;

  case 58: /* expression: expression '+' expression  */
#line 171 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression));                        }
#line 1756 "mml_parser.tab.c"
    break;

  case 59: /* expression: expression '-' expression  */
#line 172 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression));                        }
#line 1762 "mml_parser.tab.c"
    break;

  case 60: /* expression: expression '*' expression  */
#line 173 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression));                        }
#line 1768 "mml_parser.tab.c"
    break;

  case 61: /* expression: expression '/' expression  */
#line 174 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression));                        }
#line 1774 "mml_parser.tab.c"
    break;

  case 62: /* expression: expression '%' expression  */
#line 175 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression));                        }
#line 1780 "mml_parser.tab.c"
    break;

  case 63: /* expression: expression '<' expression  */
#line 176 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression));                         }
#line 1786 "mml_parser.tab.c"
    break;

  case 64: /* expression: expression '>' expression  */
#line 177 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression));                         }
#line 1792 "mml_parser.tab.c"
    break;

  case 65: /* expression: expression tGE expression  */
#line 178 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression));                         }
#line 1798 "mml_parser.tab.c"
    break;

  case 66: /* expression: expression tLE expression  */
#line 179 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression));                         }
#line 1804 "mml_parser.tab.c"
    break;

  case 67: /* expression: expression tNE expression  */
#line 180 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression));                         }
#line 1810 "mml_parser.tab.c"
    break;

  case 68: /* expression: expression tEQ expression  */
#line 181 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression));                         }
#line 1816 "mml_parser.tab.c"
    break;

  case 69: /* expression: expression tOR expression  */
#line 182 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::or_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression));                         }
#line 1822 "mml_parser.tab.c"
    break;

  case 70: /* expression: expression tAND expression  */
#line 183 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::and_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression));                        }
#line 1828 "mml_parser.tab.c"
    break;

  case 71: /* expression: lval  */
#line 184 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lvalue));                         }
#line 1834 "mml_parser.tab.c"
    break;

  case 72: /* expression: lval '=' expression  */
#line 185 "mml_parser.y"
                                                     { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lvalue), (yyvsp[0].expression));                 }
#line 1840 "mml_parser.tab.c"
    break;

  case 73: /* expression: tINPUT  */
#line 186 "mml_parser.y"
                                                     { (yyval.expression) = new mml::input_node(LINE);                              }
#line 1846 "mml_parser.tab.c"
    break;

  case 74: /* expression: tSIZEOF '(' expression ')'  */
#line 187 "mml_parser.y"
                                                     { (yyval.expression) = new mml::sizeof_node(LINE, (yyvsp[-1].expression));                         }
#line 1852 "mml_parser.tab.c"
    break;

  case 75: /* expression: lval tADDRESS  */
#line 188 "mml_parser.y"
                                                     { (yyval.expression) = new mml::address_of_node(LINE, (yyvsp[-1].lvalue));                     }
#line 1858 "mml_parser.tab.c"
    break;

  case 76: /* expression: '[' expression ']'  */
#line 189 "mml_parser.y"
                                                     { (yyval.expression) = new mml::stack_alloc_node(LINE, (yyvsp[-1].expression));                    }
#line 1864 "mml_parser.tab.c"
    break;

  case 77: /* expression: expression '(' opt_expressions ')'  */
#line 190 "mml_parser.y"
                                                     { (yyval.expression) = new mml::function_call_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].sequence));              }
#line 1870 "mml_parser.tab.c"
    break;

  case 78: /* expression: '@' '(' opt_expressions ')'  */
#line 191 "mml_parser.y"
                                                     { (yyval.expression) = new mml::function_call_node(LINE, nullptr, (yyvsp[-1].sequence), true);   }
#line 1876 "mml_parser.tab.c"
    break;

  case 79: /* expression: '(' expression ')'  */
#line 192 "mml_parser.y"
                                                     { (yyval.expression) = (yyvsp[-1].expression);                                                     }
#line 1882 "mml_parser.tab.c"
    break;

  case 80: /* expression: func_def  */
#line 193 "mml_parser.y"
                                                     { (yyval.expression) = (yyvsp[0].expression);                                                     }
#line 1888 "mml_parser.tab.c"
    break;

  case 81: /* expressions: expression  */
#line 196 "mml_parser.y"
                                           { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression));     }
#line 1894 "mml_parser.tab.c"
    break;

  case 82: /* expressions: expressions ',' expression  */
#line 197 "mml_parser.y"
                                           { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 1900 "mml_parser.tab.c"
    break;

  case 83: /* opt_expressions: %empty  */
#line 200 "mml_parser.y"
                                      { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1906 "mml_parser.tab.c"
    break;

  case 84: /* opt_expressions: expressions  */
#line 201 "mml_parser.y"
                                      { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1912 "mml_parser.tab.c"
    break;

  case 85: /* lval: tIDENTIFIER  */
#line 204 "mml_parser.y"
                            { (yyval.lvalue) = new cdk::variable_node(LINE, (yyvsp[0].s)); }
#line 1918 "mml_parser.tab.c"
    break;

  case 86: /* lval: expression '[' expression ']'  */
#line 205 "mml_parser.y"
                                              {(yyval.lvalue) = new mml::pointer_to_index_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1924 "mml_parser.tab.c"
    break;

  case 87: /* arg: type tIDENTIFIER  */
#line 208 "mml_parser.y"
                                 { (yyval.vardec) = new mml::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1930 "mml_parser.tab.c"
    break;

  case 88: /* args: %empty  */
#line 211 "mml_parser.y"
                                     { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1936 "mml_parser.tab.c"
    break;

  case 89: /* args: arg  */
#line 212 "mml_parser.y"
                             { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].vardec));     }
#line 1942 "mml_parser.tab.c"
    break;

  case 90: /* args: args ',' arg  */
#line 213 "mml_parser.y"
                             { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].vardec), (yyvsp[-2].sequence)); }
#line 1948 "mml_parser.tab.c"
    break;

  case 91: /* block: '{' declarations instructions '}'  */
#line 216 "mml_parser.y"
                                                  { (yyval.block) = new mml::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)); }
#line 1954 "mml_parser.tab.c"
    break;

  case 92: /* block: '{' declarations '}'  */
#line 217 "mml_parser.y"
                                                  { (yyval.block) = new mml::block_node(LINE, (yyvsp[-1].sequence), nullptr); }
#line 1960 "mml_parser.tab.c"
    break;

  case 93: /* block: '{' instructions '}'  */
#line 218 "mml_parser.y"
                                                  { (yyval.block) = new mml::block_node(LINE, nullptr, (yyvsp[-1].sequence)); }
#line 1966 "mml_parser.tab.c"
    break;

  case 94: /* block: '{' '}'  */
#line 219 "mml_parser.y"
                                                  { (yyval.block) = new mml::block_node(LINE, nullptr, nullptr); }
#line 1972 "mml_parser.tab.c"
    break;

  case 95: /* func_def: '(' args ')' tARROW type block  */
#line 222 "mml_parser.y"
                                               { (yyval.expression) = new mml::function_definition_node(LINE, (yyvsp[-4].sequence), (yyvsp[-1].type), (yyvsp[0].block)); }
#line 1978 "mml_parser.tab.c"
    break;

  case 96: /* func_def: '(' args ')' tARROW auto block  */
#line 223 "mml_parser.y"
                                               { (yyval.expression) = new mml::function_definition_node(LINE, (yyvsp[-4].sequence), (yyvsp[-1].type), (yyvsp[0].block)); }
#line 1984 "mml_parser.tab.c"
    break;

  case 97: /* string: tSTRING  */
#line 226 "mml_parser.y"
                               { (yyval.s) = (yyvsp[0].s); }
#line 1990 "mml_parser.tab.c"
    break;

  case 98: /* string: string tSTRING  */
#line 227 "mml_parser.y"
                               { (yyval.s) = (yyvsp[-1].s); (yyval.s)->append(*(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 1996 "mml_parser.tab.c"
    break;


#line 2000 "mml_parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (compiler, YY_("syntax error"));
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
                      yytoken, &yylval, compiler);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, compiler);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (compiler, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, compiler);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 230 "mml_parser.y"

