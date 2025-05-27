/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_INT = 258,
     TK_FLOAT = 259,
     TK_MAIN = 260,
     TK_NUM = 261,
     TK_ID = 262,
     TK_FLOATNUM = 263,
     TK_PRINT = 264,
     TK_READ = 265,
     TK_STRING = 266,
     TK_CHAR = 267,
     TK_BOOLEAN = 268,
     TK_TRUE = 269,
     TK_FALSE = 270,
     TK_CHARLIT = 271,
     TK_LT = 272,
     TK_LE = 273,
     TK_GT = 274,
     TK_GE = 275,
     TK_EQ = 276,
     TK_NE = 277,
     TK_AND = 278,
     TK_OR = 279,
     TK_NOT = 280,
     TK_IF = 281,
     TK_ELSE = 282,
     TK_WHILE = 283,
     TK_DO = 284,
     TK_FOR = 285,
     TK_SWITCH = 286,
     TK_CASE = 287,
     TK_DEFAULT = 288
   };
#endif
/* Tokens.  */
#define TK_INT 258
#define TK_FLOAT 259
#define TK_MAIN 260
#define TK_NUM 261
#define TK_ID 262
#define TK_FLOATNUM 263
#define TK_PRINT 264
#define TK_READ 265
#define TK_STRING 266
#define TK_CHAR 267
#define TK_BOOLEAN 268
#define TK_TRUE 269
#define TK_FALSE 270
#define TK_CHARLIT 271
#define TK_LT 272
#define TK_LE 273
#define TK_GT 274
#define TK_GE 275
#define TK_EQ 276
#define TK_NE 277
#define TK_AND 278
#define TK_OR 279
#define TK_NOT 280
#define TK_IF 281
#define TK_ELSE 282
#define TK_WHILE 283
#define TK_DO 284
#define TK_FOR 285
#define TK_SWITCH 286
#define TK_CASE 287
#define TK_DEFAULT 288




/* Copy the first part of user declarations.  */
#line 1 "analisador.y"

#include <iostream>
#include <vector>
#include <string>
#include "tipos.h"

int temp_count = 0;
int yydebug = 1;
std::vector<std::string> declaracoes;
std::vector<std::string> variaveis;
std::vector<std::string> temporarios;
std::vector<std::string> tipos;
std::vector<std::string> loop_labels;


int yylex(void);
void yyerror(const char* s) {
    std::cout << "Erro de sintaxe: " << s << std::endl;
    exit(1);
}

std::string get_temp(const std::string& var) {
    for (size_t i = 0; i < variaveis.size(); ++i) {
        if (variaveis[i] == var)
            return temporarios[i];
    }
    std::cerr << "Erro: variável '" << var << "' não declarada.\n";
    exit(1);
}

std::string get_tipo(const std::string& var) {
    for (size_t i = 0; i < variaveis.size(); ++i) {
        if (variaveis[i] == var)
            return tipos[i];
    }
    std::cerr << "Erro: variável '" << var << "' não declarada.\n";
    exit(1);
}

std::string gentemp(std::string tipo) {
    temp_count++;
    std::string nome = "T" + std::to_string(temp_count);
    declaracoes.push_back(tipo + " " + nome + ";");
    return nome;
}

// Etapa 11: Conversão implícita int → float
std::string gerar_cast(std::string origem, std::string tipo_origem, std::string tipo_destino, std::string& traducao) {
    if (tipo_origem == tipo_destino)
        return origem;

    std::string temp = gentemp(tipo_destino);
    traducao += "    " + temp + " = (" + tipo_destino + ") " + origem + ";\n";
    return temp;
}


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 229 "analisador.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   472

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNRULES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,    43,    36,    34,     2,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    41,
       2,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    11,    14,    18,    23,    27,    32,
      36,    40,    44,    48,    52,    58,    64,    70,    78,    84,
      92,   101,   109,   111,   114,   120,   125,   130,   134,   138,
     142,   146,   150,   154,   158,   162,   166,   170,   174,   178,
     182,   185,   187,   189,   191,   193,   195,   197,   202,   207
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,     3,     5,    38,    47,    39,    -1,    51,
      -1,    47,    51,    -1,    38,    47,    39,    -1,     7,    40,
      53,    41,    -1,     7,    40,    53,    -1,     7,    40,    53,
      41,    -1,     3,     7,    41,    -1,     4,     7,    41,    -1,
      12,     7,    41,    -1,    13,     7,    41,    -1,    11,     7,
      41,    -1,     9,    42,     7,    43,    41,    -1,    10,    42,
       7,    43,    41,    -1,    26,    42,    53,    43,    48,    -1,
      26,    42,    53,    43,    48,    27,    48,    -1,    28,    42,
      53,    43,    48,    -1,    29,    48,    28,    42,    53,    43,
      41,    -1,    30,    42,    49,    53,    41,    50,    43,    48,
      -1,    31,    42,    53,    43,    38,    52,    39,    -1,    48,
      -1,    53,    41,    -1,    52,    32,     6,    44,    47,    -1,
      32,     6,    44,    47,    -1,    52,    33,    44,    47,    -1,
      33,    44,    47,    -1,    53,    34,    53,    -1,    53,    35,
      53,    -1,    53,    36,    53,    -1,    53,    37,    53,    -1,
      53,    17,    53,    -1,    53,    18,    53,    -1,    53,    19,
      53,    -1,    53,    20,    53,    -1,    53,    21,    53,    -1,
      53,    22,    53,    -1,    53,    23,    53,    -1,    53,    24,
      53,    -1,    25,    53,    -1,     6,    -1,     8,    -1,     7,
      -1,    14,    -1,    15,    -1,    16,    -1,    42,     3,    43,
      53,    -1,    42,     4,    43,    53,    -1,    42,    53,    43,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    99,   100,   105,   110,   117,   125,   136,
     149,   162,   175,   189,   202,   215,   231,   239,   252,   271,
     290,   313,   335,   340,   345,   351,   356,   362,   370,   380,
     390,   400,   410,   417,   424,   431,   438,   445,   452,   459,
     466,   473,   479,   485,   491,   496,   501,   506,   518,   531
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_INT", "TK_FLOAT", "TK_MAIN",
  "TK_NUM", "TK_ID", "TK_FLOATNUM", "TK_PRINT", "TK_READ", "TK_STRING",
  "TK_CHAR", "TK_BOOLEAN", "TK_TRUE", "TK_FALSE", "TK_CHARLIT", "TK_LT",
  "TK_LE", "TK_GT", "TK_GE", "TK_EQ", "TK_NE", "TK_AND", "TK_OR", "TK_NOT",
  "TK_IF", "TK_ELSE", "TK_WHILE", "TK_DO", "TK_FOR", "TK_SWITCH",
  "TK_CASE", "TK_DEFAULT", "'+'", "'-'", "'*'", "'/'", "'{'", "'}'", "'='",
  "';'", "'('", "')'", "':'", "$accept", "S", "LISTA_COMANDOS", "BLOCO",
  "INIT", "INCR", "COMANDO", "CASOS", "E", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    43,    45,    42,    47,   123,   125,
      61,    59,    40,    41,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    49,    50,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     1,     2,     3,     4,     3,     4,     3,
       3,     3,     3,     3,     5,     5,     5,     7,     5,     7,
       8,     7,     1,     2,     5,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     4,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,    41,    43,
      42,     0,     0,     0,     0,     0,    44,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,     9,    10,     0,     0,     0,
      13,    11,    12,     0,     0,     0,     0,     0,     0,     5,
       0,     0,    49,    32,    33,    34,    35,    36,    37,    38,
      39,    28,    29,    30,    31,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    48,    14,    15,    16,    18,
       0,     0,     0,     0,     0,     0,     6,     0,     0,     0,
       0,     0,    17,    19,     0,     0,     0,     0,     0,     0,
      21,     7,    20,     0,    27,     0,     0,    25,     0,    26,
      24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    27,    28,    77,   118,    29,   121,    30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -29
static const yytype_int16 yypact[] =
{
      -1,     4,    10,   -25,   -29,   188,     7,     9,   -29,   -23,
     -29,   -24,   -21,    13,    15,    18,   -29,   -29,   -29,   217,
     -16,     5,     8,     6,    19,   188,    50,   114,   -29,   -29,
     361,    14,    26,   217,    42,    43,    27,    36,    37,   -29,
      76,   217,   217,    23,    45,   217,   151,    17,    38,   226,
     -29,   -29,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   -29,   -29,   -29,   369,    41,    44,
     -29,   -29,   -29,   253,   280,    48,    39,   217,   307,   -29,
     217,   217,   -29,   427,   427,   427,   427,   427,   427,    52,
      11,   435,   435,    76,    76,   -29,    60,    61,     8,     8,
     217,   217,   394,    47,   427,   427,   -29,   -29,    53,   -29,
     334,   402,    79,   -26,     8,    62,   -29,    51,    65,   103,
      75,   -28,   -29,   -29,   217,     8,    87,   188,   126,    89,
     -29,   427,   -29,   188,   188,    90,   188,   188,   188,   188,
     188
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,   -22,   -10,   -29,   -29,   -27,   -29,   -18
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      51,    40,     1,    46,   128,   129,   119,   120,    49,     3,
       4,   130,    43,     5,    31,    67,    32,    33,    34,    51,
      36,    35,    37,    73,    74,    38,    41,    78,    52,    53,
      54,    55,    56,    57,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    25,    42,    44,    68,
      69,    75,    76,    47,    48,    65,     8,    39,    10,   102,
      80,    45,   104,   105,    16,    17,    18,    66,    70,    52,
      53,    54,    55,    56,    57,    19,    59,    71,    72,   101,
     114,    81,   110,   111,    96,   113,   117,    97,   108,   109,
     100,   124,    26,    52,    53,    54,    55,    56,    57,    58,
      59,   106,   107,   123,   122,   134,   131,    51,   125,   126,
      51,   137,    51,    51,   139,   132,   140,     6,     7,   127,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,   133,   135,   136,   138,     0,     0,     0,     0,    19,
      20,     0,    21,    22,    23,    24,     0,     0,     0,     0,
       0,     0,    25,    50,     6,     7,    26,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    20,     0,    21,
      22,    23,    24,     0,     0,     0,     0,     0,     0,    25,
      79,     6,     7,    26,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    20,     0,    21,    22,    23,    24,
       0,     0,     0,     8,    39,    10,    25,     0,     0,     0,
      26,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,     0,     0,     0,     0,     0,     0,    26,
      60,    61,    62,    63,     0,     0,     0,     0,     0,    82,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,     0,     0,     0,     0,     0,    98,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,     0,     0,
       0,     0,     0,    99,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    61,    62,    63,     0,     0,     0,     0,     0,
     103,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,     0,     0,     0,     0,     0,   115,    52,    53,
      54,    55,    56,    57,    58,    59,    52,    53,    54,    55,
      56,    57,    58,    59,     0,    60,    61,    62,    63,     0,
       0,     0,    64,    60,    61,    62,    63,     0,     0,     0,
      95,    52,    53,    54,    55,    56,    57,    58,    59,    52,
      53,    54,    55,    56,    57,    58,    59,     0,    60,    61,
      62,    63,     0,     0,     0,   112,    60,    61,    62,    63,
       0,     0,     0,   116,    52,    53,    54,    55,    56,    57,
      58,    59,    52,    53,    54,    55,    56,    57,    58,    59,
       0,    60,    61,    62,    63,     0,     0,     0,     0,     0,
       0,    62,    63
};

static const yytype_int16 yycheck[] =
{
      27,    19,     3,    25,    32,    33,    32,    33,    26,     5,
       0,    39,    22,    38,     7,    33,     7,    40,    42,    46,
       7,    42,     7,    41,    42,     7,    42,    45,    17,    18,
      19,    20,    21,    22,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    38,    42,    42,     7,
       7,    28,     7,     3,     4,    41,     6,     7,     8,    77,
      43,    42,    80,    81,    14,    15,    16,    41,    41,    17,
      18,    19,    20,    21,    22,    25,    24,    41,    41,    40,
      27,    43,   100,   101,    43,    38,     7,    43,    98,    99,
      42,    40,    42,    17,    18,    19,    20,    21,    22,    23,
      24,    41,    41,    41,   114,   127,   124,   134,    43,     6,
     137,   133,   139,   140,   136,   125,   138,     3,     4,    44,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    44,     6,    44,    44,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,     3,     4,    42,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,     3,     4,    42,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      -1,    -1,    -1,     6,     7,     8,    38,    -1,    -1,    -1,
      42,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    43,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      43,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    17,    18,
      19,    20,    21,    22,    23,    24,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    34,    35,    36,    37,    -1,
      -1,    -1,    41,    34,    35,    36,    37,    -1,    -1,    -1,
      41,    17,    18,    19,    20,    21,    22,    23,    24,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    34,    35,
      36,    37,    -1,    -1,    -1,    41,    34,    35,    36,    37,
      -1,    -1,    -1,    41,    17,    18,    19,    20,    21,    22,
      23,    24,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    46,     5,     0,    38,     3,     4,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    25,
      26,    28,    29,    30,    31,    38,    42,    47,    48,    51,
      53,     7,     7,    40,    42,    42,     7,     7,     7,     7,
      53,    42,    42,    48,    42,    42,    47,     3,     4,    53,
      39,    51,    17,    18,    19,    20,    21,    22,    23,    24,
      34,    35,    36,    37,    41,    41,    41,    53,     7,     7,
      41,    41,    41,    53,    53,    28,     7,    49,    53,    39,
      43,    43,    43,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    41,    43,    43,    43,    43,
      42,    40,    53,    43,    53,    53,    41,    41,    48,    48,
      53,    53,    41,    38,    27,    43,    41,     7,    50,    32,
      33,    52,    48,    41,    40,    43,     6,    44,    32,    33,
      39,    53,    48,    44,    47,     6,    44,    47,    44,    47,
      47
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
#line 85 "analisador.y"
    {
    std::cout << "/* Compilador Faquir Rebuild */\n";
    std::cout << "#include <stdio.h>\n";
    std::cout << "int main(void) {\n";

    for (const std::string& decl : declaracoes)
        std::cout << "    " << decl << "\n";

    std::cout << (yyvsp[(4) - (5)]).traducao;
    std::cout << "    return 0;\n";
    std::cout << "}\n";
;}
    break;

  case 4:
#line 100 "analisador.y"
    {
                   (yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;
               ;}
    break;

  case 5:
#line 105 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(2) - (3)]).traducao;
;}
    break;

  case 6:
#line 110 "analisador.y"
    {
    std::string var_temp = get_temp((yyvsp[(1) - (4)]).label);
    std::string var_tipo = get_tipo((yyvsp[(1) - (4)]).label);
    std::string t = (yyvsp[(3) - (4)]).traducao + "    " + var_temp + " = " + (yyvsp[(3) - (4)]).label + ";\n";
    (yyval).traducao = t;
;}
    break;

  case 7:
#line 117 "analisador.y"
    {
    std::string var_temp = get_temp((yyvsp[(1) - (3)]).label);
    std::string var_tipo = get_tipo((yyvsp[(1) - (3)]).label);
    std::string t = (yyvsp[(3) - (3)]).traducao + "    " + var_temp + " = " + (yyvsp[(3) - (3)]).label + ";\n";
    (yyval).traducao = t;
;}
    break;

  case 8:
#line 125 "analisador.y"
    {
    std::string var_temp = get_temp((yyvsp[(1) - (4)]).label);
    std::string var_tipo = get_tipo((yyvsp[(1) - (4)]).label);

    if ((yyvsp[(3) - (4)]).traducao == "") {
        (yyval).traducao = "    " + var_temp + " = " + (yyvsp[(3) - (4)]).label + ";\n";
    } else {
        (yyval).traducao = (yyvsp[(3) - (4)]).traducao;
        (yyval).traducao += "    " + var_temp + " = " + (yyvsp[(3) - (4)]).label + ";\n";
    }
;}
    break;

  case 9:
#line 136 "analisador.y"
    {
    for (const std::string& v : variaveis) {
        if (v == (yyvsp[(2) - (3)]).label) {
            std::cerr << "Erro: variável '" << (yyvsp[(2) - (3)]).label << "' já declarada.\n";
            exit(1);
        }
    }
    std::string t = gentemp("int");
    variaveis.push_back((yyvsp[(2) - (3)]).label);
    temporarios.push_back(t);
    tipos.push_back("int");
    (yyval).traducao = "";
;}
    break;

  case 10:
#line 149 "analisador.y"
    {
    for (const std::string& v : variaveis) {
        if (v == (yyvsp[(2) - (3)]).label) {
            std::cerr << "Erro: variável '" << (yyvsp[(2) - (3)]).label << "' já declarada.\n";
            exit(1);
        }
    }
    std::string t = gentemp("float");
    variaveis.push_back((yyvsp[(2) - (3)]).label);
    temporarios.push_back(t);
    tipos.push_back("float");
    (yyval).traducao = "";
;}
    break;

  case 11:
#line 162 "analisador.y"
    {
    for (const std::string& v : variaveis) {
        if (v == (yyvsp[(2) - (3)]).label) {
            std::cerr << "Erro: variável '" << (yyvsp[(2) - (3)]).label << "' já declarada.\n";
            exit(1);
        }
    }
    std::string t = gentemp("char");
    variaveis.push_back((yyvsp[(2) - (3)]).label);
    temporarios.push_back(t);
    tipos.push_back("char");
    (yyval).traducao = "";
;}
    break;

  case 12:
#line 175 "analisador.y"
    {
    for (const std::string& v : variaveis) {
        if (v == (yyvsp[(2) - (3)]).label) {
            std::cerr << "Erro: variável '" << (yyvsp[(2) - (3)]).label << "' já declarada.\n";
            exit(1);
        }
    }
    std::string t = gentemp("int");
    variaveis.push_back((yyvsp[(2) - (3)]).label);
    temporarios.push_back(t);
    tipos.push_back("boolean");
    (yyval).traducao = "";
;}
    break;

  case 13:
#line 189 "analisador.y"
    {
    for (const std::string& v : variaveis) {
        if (v == (yyvsp[(2) - (3)]).label) {
            std::cerr << "Erro: variável '" << (yyvsp[(2) - (3)]).label << "' já declarada.\n";
            exit(1);
        }
    }
    std::string t = gentemp("char*");
    variaveis.push_back((yyvsp[(2) - (3)]).label);
    temporarios.push_back(t);
    tipos.push_back("string");
    (yyval).traducao = "";
;}
    break;

  case 14:
#line 202 "analisador.y"
    {
    std::string temp = get_temp((yyvsp[(3) - (5)]).label);
    std::string tipo = get_tipo((yyvsp[(3) - (5)]).label);
    std::string fmt;

    if (tipo == "int") fmt = "%d";
    else if (tipo == "float") fmt = "%f";
    else if (tipo == "char") fmt = "%c";
    else if (tipo == "string") fmt = "%s";
    else fmt = "??";

    (yyval).traducao = "    printf(\"" + fmt + "\\n\", " + temp + ");\n";
;}
    break;

  case 15:
#line 215 "analisador.y"
    {
    std::string temp = get_temp((yyvsp[(3) - (5)]).label);
    std::string tipo = get_tipo((yyvsp[(3) - (5)]).label);
    std::string fmt;

    if (tipo == "int") fmt = "%d";
    else if (tipo == "float") fmt = "%f";
    else if (tipo == "char") fmt = " %c";
    else if (tipo == "string") fmt = "%s";
    else fmt = "??";

    std::string ref = (tipo == "string") ? temp : "&" + temp;

    (yyval).traducao = "    scanf(\"" + fmt + "\", " + ref + ");\n";
;}
    break;

  case 16:
#line 231 "analisador.y"
    {
    std::string l_fim = "L" + std::to_string(++temp_count);

    (yyval).traducao = (yyvsp[(3) - (5)]).traducao;
    (yyval).traducao += "    if (!" + (yyvsp[(3) - (5)]).label + ") goto " + l_fim + ";\n";
    (yyval).traducao += (yyvsp[(5) - (5)]).traducao;
    (yyval).traducao += l_fim + ":\n";
;}
    break;

  case 17:
#line 239 "analisador.y"
    {
    std::string l_else = "L" + std::to_string(++temp_count);
    std::string l_fim  = "L" + std::to_string(++temp_count);

    (yyval).traducao = (yyvsp[(3) - (7)]).traducao;
    (yyval).traducao += "    if (!" + (yyvsp[(3) - (7)]).label + ") goto " + l_else + ";\n";
    (yyval).traducao += (yyvsp[(5) - (7)]).traducao;
    (yyval).traducao += "    goto " + l_fim + ";\n";
    (yyval).traducao += l_else + ":\n";
    (yyval).traducao += (yyvsp[(7) - (7)]).traducao;
    (yyval).traducao += l_fim + ":\n";
;}
    break;

  case 18:
#line 252 "analisador.y"
    {
    std::string l_inicio = "L" + std::to_string(++temp_count);
    std::string l_fim = "L" + std::to_string(++temp_count);

    // ✅ empilha antes de $5 ser processado
    loop_labels.push_back(l_fim);

    std::string bloco = (yyvsp[(5) - (5)]).traducao;

    (yyval).traducao = l_inicio + ":\n";
    (yyval).traducao += (yyvsp[(3) - (5)]).traducao;
    (yyval).traducao += "    if (!" + (yyvsp[(3) - (5)]).label + ") goto " + l_fim + ";\n";
    (yyval).traducao += bloco;
    (yyval).traducao += "    goto " + l_inicio + ";\n";
    (yyval).traducao += l_fim + ":\n";

    loop_labels.pop_back(); // ✅ depois que já usamos $5
;}
    break;

  case 19:
#line 271 "analisador.y"
    {
    std::string l_inicio = "L" + std::to_string(++temp_count);
    std::string l_cond = "L" + std::to_string(++temp_count);
    std::string l_fim = "L" + std::to_string(++temp_count);

    loop_labels.push_back(l_cond); // destino do continue

    std::string bloco = (yyvsp[(2) - (7)]).traducao;

    loop_labels.pop_back(); // remove após bloco

    (yyval).traducao = l_inicio + ":\n";
    (yyval).traducao += bloco;
    (yyval).traducao += l_cond + ":\n";
    (yyval).traducao += (yyvsp[(5) - (7)]).traducao;
    (yyval).traducao += "    if (" + (yyvsp[(5) - (7)]).label + ") goto " + l_inicio + ";\n";
    (yyval).traducao += l_fim + ":\n";
;}
    break;

  case 20:
#line 290 "analisador.y"
    {
    std::string l_inicio = "L" + std::to_string(++temp_count);
    std::string l_cond = "L" + std::to_string(++temp_count);
    std::string l_fim = "L" + std::to_string(++temp_count);

    // empilha o destino de break e continue
    loop_labels.push_back(l_fim);  // break vai pra cá
    loop_labels.push_back(l_cond); // continue vai pra cá

    (yyval).traducao = (yyvsp[(3) - (8)]).traducao;  // INIT
    (yyval).traducao += l_inicio + ":\n";
    (yyval).traducao += (yyvsp[(4) - (8)]).traducao;  // condição
    (yyval).traducao += "    if (!" + (yyvsp[(4) - (8)]).label + ") goto " + l_fim + ";\n";
    (yyval).traducao += (yyvsp[(8) - (8)]).traducao;  // bloco
    (yyval).traducao += l_cond + ":\n";
    (yyval).traducao += (yyvsp[(6) - (8)]).traducao;  // incremento
    (yyval).traducao += "    goto " + l_inicio + ";\n";
    (yyval).traducao += l_fim + ":\n";

    loop_labels.pop_back(); // pop continue
    loop_labels.pop_back(); // pop break
;}
    break;

  case 21:
#line 313 "analisador.y"
    {
    std::string switch_var = "__switch_var" + std::to_string(++temp_count);
    declaracoes.push_back("int " + switch_var + ";");

    // Armazena valor da expressão em uma variável auxiliar
    std::string codigo = (yyvsp[(3) - (7)]).traducao;
    codigo += "    " + switch_var + " = " + (yyvsp[(3) - (7)]).label + ";\n";

    // Substitui __switch_var por switch_var com proteção contra loop
    std::string casos_traducao = (yyvsp[(6) - (7)]).traducao;
    std::string from = "__switch_var";
    size_t pos = 0;
    while ((pos = casos_traducao.find(from, pos)) != std::string::npos) {
        casos_traducao.replace(pos, from.length(), switch_var);
        pos += switch_var.length();  // avança para evitar loop infinito
    }

    (yyval).traducao = codigo + casos_traducao;
;}
    break;

  case 22:
#line 335 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (1)]).traducao;
;}
    break;

  case 23:
#line 340 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (2)]).traducao;
;}
    break;

  case 24:
#line 345 "analisador.y"
    {
    std::string l_case = "L" + std::to_string(++temp_count);
    (yyval).traducao = (yyvsp[(1) - (5)]).traducao;
    (yyval).traducao += "    if (__switch_var == " + (yyvsp[(3) - (5)]).label + ") goto " + l_case + ";\n";
    (yyval).traducao += l_case + ":\n" + (yyvsp[(5) - (5)]).traducao;
;}
    break;

  case 25:
#line 351 "analisador.y"
    {
    std::string l_case = "L" + std::to_string(++temp_count);
    (yyval).traducao = "    if (__switch_var == " + (yyvsp[(2) - (4)]).label + ") goto " + l_case + ";\n";
    (yyval).traducao += l_case + ":\n" + (yyvsp[(4) - (4)]).traducao;
;}
    break;

  case 26:
#line 356 "analisador.y"
    {
    std::string l_default = "L" + std::to_string(++temp_count);
    (yyval).traducao = (yyvsp[(1) - (4)]).traducao;
    (yyval).traducao += "    goto " + l_default + ";\n";
    (yyval).traducao += l_default + ":\n" + (yyvsp[(4) - (4)]).traducao;
;}
    break;

  case 27:
#line 362 "analisador.y"
    {
    std::string l_default = "L" + std::to_string(++temp_count);
    (yyval).traducao = "    goto " + l_default + ";\n";
    (yyval).traducao += l_default + ":\n" + (yyvsp[(3) - (3)]).traducao;
;}
    break;

  case 28:
#line 370 "analisador.y"
    {
    std::string tipo_resultado = ((yyvsp[(1) - (3)]).tipo == "float" || (yyvsp[(3) - (3)]).tipo == "float") ? "float" : "int";
    std::string t = gentemp(tipo_resultado);
    std::string traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    std::string a1 = gerar_cast((yyvsp[(1) - (3)]).label, (yyvsp[(1) - (3)]).tipo, tipo_resultado, traducao);
    std::string a2 = gerar_cast((yyvsp[(3) - (3)]).label, (yyvsp[(3) - (3)]).tipo, tipo_resultado, traducao);
    (yyval).label = t;
    (yyval).tipo = tipo_resultado;
    (yyval).traducao = traducao + "    " + t + " = " + a1 + " + " + a2 + ";\n";
;}
    break;

  case 29:
#line 380 "analisador.y"
    {
    std::string tipo_resultado = ((yyvsp[(1) - (3)]).tipo == "float" || (yyvsp[(3) - (3)]).tipo == "float") ? "float" : "int";
    std::string t = gentemp(tipo_resultado);
    std::string traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    std::string a1 = gerar_cast((yyvsp[(1) - (3)]).label, (yyvsp[(1) - (3)]).tipo, tipo_resultado, traducao);
    std::string a2 = gerar_cast((yyvsp[(3) - (3)]).label, (yyvsp[(3) - (3)]).tipo, tipo_resultado, traducao);
    (yyval).label = t;
    (yyval).tipo = tipo_resultado;
    (yyval).traducao = traducao + "    " + t + " = " + a1 + " - " + a2 + ";\n";
;}
    break;

  case 30:
#line 390 "analisador.y"
    {
    std::string tipo_resultado = ((yyvsp[(1) - (3)]).tipo == "float" || (yyvsp[(3) - (3)]).tipo == "float") ? "float" : "int";
    std::string t = gentemp(tipo_resultado);
    std::string traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    std::string a1 = gerar_cast((yyvsp[(1) - (3)]).label, (yyvsp[(1) - (3)]).tipo, tipo_resultado, traducao);
    std::string a2 = gerar_cast((yyvsp[(3) - (3)]).label, (yyvsp[(3) - (3)]).tipo, tipo_resultado, traducao);
    (yyval).label = t;
    (yyval).tipo = tipo_resultado;
    (yyval).traducao = traducao + "    " + t + " = " + a1 + " * " + a2 + ";\n";
;}
    break;

  case 31:
#line 400 "analisador.y"
    {
    std::string tipo_resultado = ((yyvsp[(1) - (3)]).tipo == "float" || (yyvsp[(3) - (3)]).tipo == "float") ? "float" : "int";
    std::string t = gentemp(tipo_resultado);
    std::string traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    std::string a1 = gerar_cast((yyvsp[(1) - (3)]).label, (yyvsp[(1) - (3)]).tipo, tipo_resultado, traducao);
    std::string a2 = gerar_cast((yyvsp[(3) - (3)]).label, (yyvsp[(3) - (3)]).tipo, tipo_resultado, traducao);
    (yyval).label = t;
    (yyval).tipo = tipo_resultado;
    (yyval).traducao = traducao + "    " + t + " = " + a1 + " / " + a2 + ";\n";
;}
    break;

  case 32:
#line 410 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " < " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 33:
#line 417 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " <= " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 34:
#line 424 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " > " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 35:
#line 431 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " >= " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 36:
#line 438 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " == " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 37:
#line 445 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " != " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 38:
#line 452 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " && " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 39:
#line 459 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " || " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 40:
#line 466 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(2) - (2)]).traducao;
    (yyval).traducao += "    " + t + " = !" + (yyvsp[(2) - (2)]).label + ";\n";
;}
    break;

  case 41:
#line 473 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "int";
    (yyval).traducao = "    " + t + " = " + (yyvsp[(1) - (1)]).label + ";\n";
;}
    break;

  case 42:
#line 479 "analisador.y"
    {
    std::string t = gentemp("float");
    (yyval).label = t;
    (yyval).tipo = "float";
    (yyval).traducao = "    " + t + " = " + (yyvsp[(1) - (1)]).label + ";\n";
;}
    break;

  case 43:
#line 485 "analisador.y"
    {
    std::string t = get_temp((yyvsp[(1) - (1)]).label);
    (yyval).label = t;
    (yyval).tipo = get_tipo((yyvsp[(1) - (1)]).label);
    (yyval).traducao = "";
;}
    break;

  case 44:
#line 491 "analisador.y"
    {
    (yyval).label = "1";
    (yyval).tipo = "boolean";
    (yyval).traducao = "";
;}
    break;

  case 45:
#line 496 "analisador.y"
    {
    (yyval).label = "0";
    (yyval).tipo = "boolean";
    (yyval).traducao = "";
;}
    break;

  case 46:
#line 501 "analisador.y"
    {
    (yyval).label = (yyvsp[(1) - (1)]).label;
    (yyval).tipo = "char";
    (yyval).traducao = "";
;}
    break;

  case 47:
#line 506 "analisador.y"
    {
    std::string copia = gentemp((yyvsp[(4) - (4)]).tipo); // tipo original
    std::string cast = gentemp("int");

    (yyval).label = cast;
    (yyval).tipo = "int";

    (yyval).traducao = (yyvsp[(4) - (4)]).traducao;
    (yyval).traducao += "    " + copia + " = " + (yyvsp[(4) - (4)]).label + ";\n";
    (yyval).traducao += "    " + cast + " = (int) " + copia + ";\n";
;}
    break;

  case 48:
#line 518 "analisador.y"
    {
    std::string copia = gentemp((yyvsp[(4) - (4)]).tipo); // tipo original
    std::string cast = gentemp("float");

    (yyval).label = cast;
    (yyval).tipo = "float";

    (yyval).traducao = (yyvsp[(4) - (4)]).traducao;
    (yyval).traducao += "    " + copia + " = " + (yyvsp[(4) - (4)]).label + ";\n";
    (yyval).traducao += "    " + cast + " = (float) " + copia + ";\n";
;}
    break;

  case 49:
#line 531 "analisador.y"
    {
    (yyval).label = (yyvsp[(2) - (3)]).label;
    (yyval).tipo = (yyvsp[(2) - (3)]).tipo;
    (yyval).traducao = (yyvsp[(2) - (3)]).traducao;
;}
    break;


/* Line 1267 of yacc.c.  */
#line 2204 "analisador.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 538 "analisador.y"


int main() {
    yydebug = 1;
    yyparse();
    return 0;
}















