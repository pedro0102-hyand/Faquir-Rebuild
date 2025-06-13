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
     TK_DEFAULT = 288,
     TK_BREAK = 289,
     TK_CONTINUE = 290,
     TK_STRLIT = 291
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
#define TK_BREAK 289
#define TK_CONTINUE 290
#define TK_STRLIT 291




/* Copy the first part of user declarations.  */
#line 1 "analisador.y"

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include "tipos.h"

int temp_count = 0;
int label_count = 0;
int yydebug = 1;
int escopo_count = 0;
int profundidade_escopo = 0;
std::string escopo_atual = "global";
std::vector<std::string> nome_escopo = {"global"};
std::vector<std::string> declaracoes;
std::string gentemp(std::string tipo);


struct Simbolo {
    std::string nome;
    std::string tipo;
    std::string temp;
    std::string escopo;
    bool constante = false;
    bool usado = false;
    int nivel_escopo;

    Simbolo() = default;

    Simbolo(std::string nome, std::string tipo, std::string temp, std::string escopo, bool constante, bool usado, int nivel_escopo)
        : nome(nome), tipo(tipo), temp(temp), escopo(escopo), constante(constante), usado(usado), nivel_escopo(nivel_escopo) {}
};


std::vector<std::unordered_map<std::string, Simbolo>> tabela_simbolos;


enum TipoControle { LOOP, SWITCH };

struct Controle {
    TipoControle tipo;
    std::string rotulo_break;
    std::string rotulo_continue;  
};

std::vector<Controle> pilha_controle;


int yylex(void);
void yyerror(const char* s) {
    std::cout << "Erro de sintaxe: " << s << std::endl;
    exit(1);
}

void iniciar_escopo(std::string nome_customizado = "") {
    tabela_simbolos.push_back({});
    profundidade_escopo++;
    escopo_count++;

    if (!nome_customizado.empty())
        escopo_atual = nome_customizado;
    else
        escopo_atual = "escopo_" + std::to_string(escopo_count);

    nome_escopo.push_back(escopo_atual);
}

void encerrar_escopo() {
    tabela_simbolos.pop_back();
    nome_escopo.pop_back();
    profundidade_escopo--;
    escopo_atual = profundidade_escopo > 0 ? nome_escopo.back() : "global";
}

void dump_tabela() {
    std::cout << "\n------ TABELA DE SÍMBOLOS ------\n";
    for (size_t i = 0; i < tabela_simbolos.size(); ++i) {
        std::cout << "Escopo " << nome_escopo[i] << " (nível " << i << "):\n";
        for (const auto& par : tabela_simbolos[i]) {
            const Simbolo& s = par.second;
            std::cout << "  " << s.nome << " (" << s.tipo << ") -> " << s.temp;
            if (s.constante) std::cout << " [const]";
            std::cout << "\n";
        }
    }
    std::cout << "--------------------------------\n\n";
}

std::string get_temp(const std::string& var) {
    for (int i = tabela_simbolos.size() - 1; i >= 0; --i)
        if (tabela_simbolos[i].count(var)) return tabela_simbolos[i][var].temp;
    std::cerr << "Erro: variável '" << var << "' não declarada.\n";
    exit(1);
}

std::string get_tipo(const std::string& var) {
    for (int i = tabela_simbolos.size() - 1; i >= 0; --i)
        if (tabela_simbolos[i].count(var)) return tabela_simbolos[i][var].tipo;
    std::cerr << "Erro: variável '" << var << "' não declarada.\n";
    exit(1);
}

Simbolo buscar_simbolo(const std::string& nome) {
    for (int i = tabela_simbolos.size() - 1; i >= 0; --i)
        if (tabela_simbolos[i].count(nome)) return tabela_simbolos[i][nome];
    std::cerr << "Erro: variável '" << nome << "' não declarada.\n";
    exit(1);
}


void declarar(const std::string& nome, const std::string& tipo, bool constante = false) {
    if (tabela_simbolos.back().count(nome)) {
        std::cerr << "Erro: variável '" << nome << "' já declarada neste escopo.\n";
        exit(1);
    }
    std::string t = gentemp(tipo);
    Simbolo s{nome, tipo, t, escopo_atual, constante, false, profundidade_escopo};
    tabela_simbolos.back()[nome] = s;
}


std::string gentemp(std::string tipo) {
    temp_count++;
    std::string nome = "T" + std::to_string(temp_count);

    if (tipo == "string")
        declaracoes.push_back("char* " + nome + ";");
    else if (tipo == "boolean")
        declaracoes.push_back("int " + nome + ";");  // boolean vira int
    else
        declaracoes.push_back(tipo + " " + nome + ";");

    return nome;
}


std::string genlabel() {
    return "L" + std::to_string(++label_count);
}

bool dentro_de(TipoControle tipo) {
    for (int i = pilha_controle.size() - 1; i >= 0; --i) {
        if (pilha_controle[i].tipo == tipo)
            return true;
    }
    return false;
}


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
#line 338 "analisador.tab.c"

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   518

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    46,    39,    37,     2,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    43,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    16,    18,    21,    23,    26,    30,
      34,    38,    42,    46,    47,    52,    53,    58,    62,    67,
      72,    74,    75,    80,    84,    88,    92,    96,   100,   106,
     112,   118,   124,   130,   138,   141,   149,   155,   164,   167,
     170,   172,   175,   178,   181,   183,   188,   189,   193,   197,
     201,   205,   209,   213,   217,   221,   225,   229,   233,   237,
     241,   244,   246,   248,   250,   252,   254,   256,   258,   263,
     268
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    51,     3,     5,    41,    50,    42,    -1,
       3,     5,    41,    50,    42,    -1,    61,    -1,    50,    61,
      -1,    52,    -1,    51,    52,    -1,     3,     7,    43,    -1,
       4,     7,    43,    -1,    12,     7,    43,    -1,    13,     7,
      43,    -1,    11,     7,    43,    -1,    -1,    41,    54,    50,
      42,    -1,    -1,     7,    44,    66,    43,    -1,     7,    44,
      66,    -1,    56,    66,    43,    57,    -1,    28,    45,    66,
      46,    -1,    29,    -1,    -1,     7,    44,    66,    43,    -1,
       3,     7,    43,    -1,     4,     7,    43,    -1,    12,     7,
      43,    -1,    13,     7,    43,    -1,    11,     7,    43,    -1,
       9,    45,     7,    46,    43,    -1,     9,    45,    36,    46,
      43,    -1,     9,    45,    66,    46,    43,    -1,    10,    45,
       7,    46,    43,    -1,    26,    45,    66,    46,    53,    -1,
      26,    45,    66,    46,    53,    27,    53,    -1,    59,    53,
      -1,    60,    53,    28,    45,    66,    46,    43,    -1,    30,
      45,    58,    46,    53,    -1,    31,    45,    66,    46,    55,
      41,    62,    42,    -1,    34,    43,    -1,    35,    43,    -1,
      53,    -1,    66,    43,    -1,    63,    65,    -1,    63,    64,
      -1,    64,    -1,    32,     6,    47,    53,    -1,    -1,    33,
      47,    53,    -1,    66,    37,    66,    -1,    66,    38,    66,
      -1,    66,    39,    66,    -1,    66,    40,    66,    -1,    66,
      17,    66,    -1,    66,    18,    66,    -1,    66,    19,    66,
      -1,    66,    20,    66,    -1,    66,    21,    66,    -1,    66,
      22,    66,    -1,    66,    23,    66,    -1,    66,    24,    66,
      -1,    25,    66,    -1,     6,    -1,     8,    -1,     7,    -1,
      14,    -1,    15,    -1,    16,    -1,    36,    -1,    45,     3,
      46,    66,    -1,    45,     4,    46,    66,    -1,    45,    66,
      46,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   190,   190,   202,   217,   218,   223,   224,   227,   231,
     235,   239,   243,   250,   250,   258,   265,   272,   279,   303,
     324,   340,   340,   352,   357,   362,   367,   373,   378,   393,
     397,   412,   428,   442,   461,   470,   488,   498,   556,   564,
     582,   587,   592,   597,   600,   605,   624,   627,   645,   656,
     667,   678,   689,   697,   705,   713,   721,   729,   737,   745,
     753,   761,   768,   775,   782,   789,   797,   804,   814,   823,
     834
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
  "TK_CASE", "TK_DEFAULT", "TK_BREAK", "TK_CONTINUE", "TK_STRLIT", "'+'",
  "'-'", "'*'", "'/'", "'{'", "'}'", "';'", "'='", "'('", "')'", "':'",
  "$accept", "S", "LISTA_COMANDOS", "DECLS", "DECL", "BLOCO", "@1",
  "SWITCH_INIT", "INIT", "INCR", "FOR_INIT", "WHILE_INIT", "DO_INIT",
  "COMANDO", "CASOS", "LISTA_CASE", "CASE", "DEFAULT_OPCIONAL", "E", 0
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
     285,   286,   287,   288,   289,   290,   291,    43,    45,    42,
      47,   123,   125,    59,    61,    40,    41,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    51,    51,    52,    52,
      52,    52,    52,    54,    53,    55,    56,    57,    58,    59,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    63,    63,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     1,     2,     1,     2,     3,     3,
       3,     3,     3,     0,     4,     0,     4,     3,     4,     4,
       1,     0,     4,     3,     3,     3,     3,     3,     5,     5,
       5,     5,     5,     7,     2,     7,     5,     8,     2,     2,
       1,     2,     2,     2,     1,     4,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     1,     0,     7,    21,     8,
       9,    12,    10,    11,     0,     0,     0,    61,    63,    62,
       0,     0,     0,     0,     0,    64,    65,    66,     0,     0,
       0,    20,     0,     0,     0,     0,    67,    13,     0,     0,
      40,     0,     0,     4,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    60,     0,     0,     0,     0,
      38,    39,    21,     0,     0,     0,     3,     5,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,    23,    24,     0,    63,    67,     0,
       0,    27,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,    52,    53,    54,    55,    56,
      57,    58,    59,    48,    49,    50,    51,     2,    22,     0,
       0,     0,     0,     0,    19,     0,     0,     0,    15,    14,
      68,    69,     0,    28,    29,    30,    31,    32,     0,     0,
      36,     0,     0,     0,    16,     0,    18,     0,     0,    33,
       0,     0,     0,    46,    44,    35,    17,     0,    37,     0,
      43,    42,     0,     0,    45,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    49,     7,     8,    50,    72,   151,   107,   156,
     108,    51,    52,    53,   162,   163,   164,   171,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -55
static const yytype_int16 yypact[] =
{
       4,     6,    -5,     2,    12,    26,    61,    75,   -55,   -29,
      22,    23,    24,    33,    34,   -55,    25,   -55,   223,   -55,
     -55,   -55,   -55,   -55,    27,    73,    76,   -55,    38,   -55,
      39,    45,    84,    86,    87,   -55,   -55,   -55,   255,    50,
      51,   -55,    53,    54,    57,    59,   -55,   -55,    56,   103,
     -55,    62,    62,   -55,   408,   223,    65,    77,   255,   259,
     114,    80,    83,    92,   -55,   486,   255,   255,   120,   255,
     -55,   -55,   223,    90,    94,   288,   -55,   -55,   -55,   102,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   -55,   143,   -55,   -55,   416,    95,    96,   298,
      97,   -55,   -55,   -55,   328,   338,   116,   255,   115,   368,
     183,   255,   255,   -55,   117,    17,    17,    17,    17,    17,
      17,   268,     5,   478,   478,   486,   486,   -55,   -55,   121,
     122,   123,   124,    62,   -55,   255,   443,    62,   -55,   -55,
      17,    17,   255,   -55,   -55,   -55,   -55,   136,   451,   163,
     -55,   134,   378,    62,   -55,   132,   -55,   148,   138,   -55,
     255,   176,   141,   -27,   -55,   -55,    17,   153,   -55,   154,
     -55,   -55,    62,    62,   -55,   -55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -55,   -55,   -54,   -55,   195,   -48,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -35,   -55,   -55,    40,   -55,   -38
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      65,    93,    11,    78,    79,   161,   169,     1,     2,    12,
      75,     9,    18,    10,    77,     3,     4,     5,   110,    13,
      96,    99,    80,    81,    82,    83,    84,    85,   104,   105,
      24,   109,    10,    14,    80,    81,    82,    83,    84,    85,
      86,    87,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    88,    89,    90,    91,    77,    73,
      74,    15,    27,    64,    29,    19,    20,    21,    55,   136,
      35,    36,    37,   140,   141,    77,    22,    23,    16,     2,
      56,    38,    58,    57,    59,   147,     3,     4,     5,   150,
      60,    61,    46,    62,    63,    66,    67,   148,    68,    69,
      70,    48,    71,    47,   152,   159,    25,    26,    94,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      95,   100,   166,   101,   174,   175,   102,   106,    38,    39,
     114,    40,    41,    42,    43,   103,   111,    44,    45,    46,
     112,   129,   130,   132,    47,    76,    25,    26,    48,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
     135,   137,   142,   153,   143,   144,   145,   146,    38,    39,
     155,    40,    41,    42,    43,   157,   160,    44,    45,    46,
     161,   165,   167,   168,    47,   127,    25,    26,    48,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
     172,   173,    17,   170,     0,     0,     0,     0,    38,    39,
       0,    40,    41,    42,    43,     0,     0,    44,    45,    46,
       0,     0,     0,     0,    47,   139,    25,    26,    48,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
       0,    40,    41,    42,    43,     0,     0,    44,    45,    46,
       0,    27,    64,    29,    47,    27,    97,    29,    48,    35,
      36,    37,     0,    35,    36,    37,     0,     0,     0,     0,
      38,     0,     0,     0,    38,    80,    81,    82,    83,    84,
      85,    46,    87,     0,     0,    98,     0,     0,     0,     0,
      48,     0,     0,     0,    48,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,    89,    90,    91,     0,
       0,     0,     0,     0,   113,    88,    89,    90,    91,     0,
       0,     0,     0,     0,   131,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,    89,    90,    91,     0,
       0,     0,     0,     0,   133,    88,    89,    90,    91,     0,
       0,     0,     0,     0,   134,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88,    89,    90,    91,     0,
       0,     0,     0,     0,   138,    88,    89,    90,    91,     0,
       0,     0,     0,     0,   158,    80,    81,    82,    83,    84,
      85,    86,    87,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,     0,    88,    89,    90,    91,     0,
       0,    92,     0,    88,    89,    90,    91,     0,     0,   128,
      80,    81,    82,    83,    84,    85,    86,    87,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
      88,    89,    90,    91,     0,     0,   149,     0,    88,    89,
      90,    91,     0,     0,   154,    80,    81,    82,    83,    84,
      85,    86,    87,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,     0,     0,     0,    90,    91
};

static const yytype_int16 yycheck[] =
{
      38,    55,     7,    51,    52,    32,    33,     3,     4,     7,
      48,     5,    41,     7,    49,    11,    12,    13,    72,     7,
      58,    59,    17,    18,    19,    20,    21,    22,    66,    67,
       5,    69,     7,     7,    17,    18,    19,    20,    21,    22,
      23,    24,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    37,    38,    39,    40,    93,     3,
       4,     0,     6,     7,     8,    43,    43,    43,    41,   107,
      14,    15,    16,   111,   112,   110,    43,    43,     3,     4,
       7,    25,    44,     7,    45,   133,    11,    12,    13,   137,
      45,     7,    36,     7,     7,    45,    45,   135,    45,    45,
      43,    45,    43,    41,   142,   153,     3,     4,    43,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      43,     7,   160,    43,   172,   173,    43,     7,    25,    26,
      28,    28,    29,    30,    31,    43,    46,    34,    35,    36,
      46,    46,    46,    46,    41,    42,     3,     4,    45,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      44,    46,    45,    27,    43,    43,    43,    43,    25,    26,
       7,    28,    29,    30,    31,    41,    44,    34,    35,    36,
      32,    43,     6,    42,    41,    42,     3,     4,    45,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      47,    47,     7,   163,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    -1,    -1,    34,    35,    36,
      -1,    -1,    -1,    -1,    41,    42,     3,     4,    45,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    -1,    -1,    34,    35,    36,
      -1,     6,     7,     8,    41,     6,     7,     8,    45,    14,
      15,    16,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    25,    17,    18,    19,    20,    21,
      22,    36,    24,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    45,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    17,    18,    19,    20,    21,
      22,    23,    24,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,
      -1,    43,    -1,    37,    38,    39,    40,    -1,    -1,    43,
      17,    18,    19,    20,    21,    22,    23,    24,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    -1,    -1,    43,    -1,    37,    38,
      39,    40,    -1,    -1,    43,    17,    18,    19,    20,    21,
      22,    23,    24,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    11,    12,    13,    49,    51,    52,     5,
       7,     7,     7,     7,     7,     0,     3,    52,    41,    43,
      43,    43,    43,    43,     5,     3,     4,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    25,    26,
      28,    29,    30,    31,    34,    35,    36,    41,    45,    50,
      53,    59,    60,    61,    66,    41,     7,     7,    44,    45,
      45,     7,     7,     7,     7,    66,    45,    45,    45,    45,
      43,    43,    54,     3,     4,    66,    42,    61,    53,    53,
      17,    18,    19,    20,    21,    22,    23,    24,    37,    38,
      39,    40,    43,    50,    43,    43,    66,     7,    36,    66,
       7,    43,    43,    43,    66,    66,     7,    56,    58,    66,
      50,    46,    46,    46,    28,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    42,    43,    46,
      46,    46,    46,    46,    46,    44,    66,    46,    46,    42,
      66,    66,    45,    43,    43,    43,    43,    53,    66,    43,
      53,    55,    66,    27,    43,     7,    57,    41,    46,    53,
      44,    32,    62,    63,    64,    43,    66,     6,    42,    33,
      64,    65,    47,    47,    53,    53
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
#line 190 "analisador.y"
    {
    std::cout << "/* Compilador Faquir Rebuild */\n";
    std::cout << "#include <stdio.h>\n";
    std::cout << "int main(void) {\n";

    for (const std::string& decl : declaracoes)
        std::cout << "    " << decl << "\n";

    std::cout << (yyvsp[(5) - (6)]).traducao;
    std::cout << "    return 0;\n";
    std::cout << "}\n";
;}
    break;

  case 3:
#line 202 "analisador.y"
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

  case 5:
#line 218 "analisador.y"
    {
                   (yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;
               ;}
    break;

  case 8:
#line 227 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "int");
    (yyval).traducao = "";
;}
    break;

  case 9:
#line 231 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "float");
    (yyval).traducao = "";
;}
    break;

  case 10:
#line 235 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "char");
    (yyval).traducao = "";
;}
    break;

  case 11:
#line 239 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "boolean");
    (yyval).traducao = "";
;}
    break;

  case 12:
#line 243 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "string");
    (yyval).traducao = "";
;}
    break;

  case 13:
#line 250 "analisador.y"
    {
    tabela_simbolos.push_back({});  
;}
    break;

  case 14:
#line 252 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(3) - (4)]).traducao;
    tabela_simbolos.pop_back();     
;}
    break;

  case 15:
#line 258 "analisador.y"
    {
    std::string l_fim_switch = genlabel();
    pilha_controle.push_back({SWITCH, l_fim_switch, ""});
    (yyval).label = l_fim_switch;
;}
    break;

  case 16:
#line 265 "analisador.y"
    {
    std::string var_temp = get_temp((yyvsp[(1) - (4)]).label);
    std::string var_tipo = get_tipo((yyvsp[(1) - (4)]).label);
    std::string t = (yyvsp[(3) - (4)]).traducao + "    " + var_temp + " = " + (yyvsp[(3) - (4)]).label + ";\n";
    (yyval).traducao = t;
;}
    break;

  case 17:
#line 272 "analisador.y"
    {
    std::string var_temp = get_temp((yyvsp[(1) - (3)]).label);
    std::string var_tipo = get_tipo((yyvsp[(1) - (3)]).label);
    std::string t = (yyvsp[(3) - (3)]).traducao + "    " + var_temp + " = " + (yyvsp[(3) - (3)]).label + ";\n";
    (yyval).traducao = t;
;}
    break;

  case 18:
#line 279 "analisador.y"
    {
    if ((yyvsp[(2) - (4)]).tipo != "boolean") {
        std::cerr << "Erro: condição do 'for' deve ser booleana, mas é '" << (yyvsp[(2) - (4)]).tipo << "'\n";
        exit(1);
    }

    std::string l_inicio = genlabel();       // Início do laço
    std::string l_continue = genlabel();     // Rótulo de continue (vai para incremento)
    std::string l_fim = genlabel();          // Saída do laço

    pilha_controle.push_back({LOOP, l_fim, l_continue});

    (yyval).traducao = (yyvsp[(1) - (4)]).traducao;  // INIT
    (yyval).traducao += l_inicio + ":\n";
    (yyval).traducao += (yyvsp[(2) - (4)]).traducao;
    (yyval).traducao += "    if (!" + (yyvsp[(2) - (4)]).label + ") goto " + l_fim + "; // condição falsa\n";

    // salvar rótulos para a regra principal
    (yyval).label = l_inicio;
    (yyval).rotulo_break = l_fim;
    (yyval).rotulo_continue = l_continue;
    (yyval).incr = (yyvsp[(4) - (4)]).traducao;
;}
    break;

  case 19:
#line 303 "analisador.y"
    {
    if ((yyvsp[(3) - (4)]).tipo != "boolean") {
        std::cerr << "Erro: condição do 'while' deve ser booleana, mas é '" << (yyvsp[(3) - (4)]).tipo << "'\n";
        exit(1);
    }

    std::string l_inicio = genlabel();     // início do loop
    std::string l_fim = genlabel();        // saída do loop

    // Empilha antes do corpo ser processado
    pilha_controle.push_back({LOOP, l_fim, l_inicio});

    (yyval).label = l_inicio;
    (yyval).rotulo_break = l_fim;
    (yyval).rotulo_continue = l_inicio;  // no while, continue volta pro teste

    (yyval).traducao = l_inicio + ":\n";
    (yyval).traducao += (yyvsp[(3) - (4)]).traducao;
    (yyval).traducao += "    if (!" + (yyvsp[(3) - (4)]).label + ") goto " + l_fim + "; // condição falsa\n";
;}
    break;

  case 20:
#line 324 "analisador.y"
    {
    std::string l_inicio = genlabel();  // início do bloco
    std::string l_cond = genlabel();    // ponto da condição
    std::string l_fim = genlabel();     // saída do laço

    pilha_controle.push_back({LOOP, l_fim, l_cond});

    (yyval).label = l_inicio;
    (yyval).rotulo_continue = l_cond;
    (yyval).rotulo_break = l_fim;

    (yyval).traducao = l_inicio + ":\n";  // começa o corpo aqui
;}
    break;

  case 22:
#line 340 "analisador.y"
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

  case 23:
#line 352 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "int");
    (yyval).traducao = "";
;}
    break;

  case 24:
#line 357 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "float");
    (yyval).traducao = "";
;}
    break;

  case 25:
#line 362 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "char");
    (yyval).traducao = "";
;}
    break;

  case 26:
#line 367 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "boolean");
    (yyval).traducao = "";
;}
    break;

  case 27:
#line 373 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "string");
    (yyval).traducao = "";
;}
    break;

  case 28:
#line 378 "analisador.y"
    {
    std::string temp = get_temp((yyvsp[(3) - (5)]).label);
    std::string tipo = get_tipo((yyvsp[(3) - (5)]).label);
    std::string fmt;

    if (tipo == "int") fmt = "%d";
    else if (tipo == "float") fmt = "%f";
    else if (tipo == "char") fmt = "%c";
    else if (tipo == "string") fmt = "%s";
    else if (tipo == "boolean") fmt = "%d"; 
    else fmt = "??";

    (yyval).traducao = "    printf(\"" + fmt + "\\n\", " + temp + ");\n";
;}
    break;

  case 29:
#line 393 "analisador.y"
    {
    (yyval).traducao = "    printf(\"%s\\n\", \"" + (yyvsp[(3) - (5)]).label + "\");\n";
;}
    break;

  case 30:
#line 397 "analisador.y"
    {
    std::string fmt;
    if ((yyvsp[(3) - (5)]).tipo == "int") fmt = "%d";
    else if ((yyvsp[(3) - (5)]).tipo == "float") fmt = "%f";
    else if ((yyvsp[(3) - (5)]).tipo == "char") fmt = "%c";
    else if ((yyvsp[(3) - (5)]).tipo == "boolean") fmt = "%d";
    else if ((yyvsp[(3) - (5)]).tipo == "string") fmt = "%s";
    else fmt = "??";

    (yyval).traducao = (yyvsp[(3) - (5)]).traducao;
    (yyval).traducao += "    printf(\"" + fmt + "\\n\", " + (yyvsp[(3) - (5)]).label + ");\n";
;}
    break;

  case 31:
#line 412 "analisador.y"
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

  case 32:
#line 428 "analisador.y"
    {
    if ((yyvsp[(3) - (5)]).tipo != "boolean") {
        std::cerr << "Erro: condição do 'if' deve ser booleana, mas é '" << (yyvsp[(3) - (5)]).tipo << "'\n";
        exit(1);
    }

    std::string l_fim = "L" + std::to_string(++temp_count);

    (yyval).traducao = (yyvsp[(3) - (5)]).traducao;
    (yyval).traducao += "    if (!" + (yyvsp[(3) - (5)]).label + ") goto " + l_fim + "; // if condicional falsa\n";
    (yyval).traducao += (yyvsp[(5) - (5)]).traducao;
    (yyval).traducao += l_fim + ":\n";
;}
    break;

  case 33:
#line 442 "analisador.y"
    {
    if ((yyvsp[(3) - (7)]).tipo != "boolean") {
        std::cerr << "Erro: condição do 'if' deve ser booleana, mas é '" << (yyvsp[(3) - (7)]).tipo << "'\n";
        exit(1);
    }

    std::string l_else = "L" + std::to_string(++temp_count);
    std::string l_fim  = "L" + std::to_string(++temp_count);

    (yyval).traducao = (yyvsp[(3) - (7)]).traducao;
    (yyval).traducao += "    if (!" + (yyvsp[(3) - (7)]).label + ") goto " + l_else + "; // if condicional falsa\n";
    (yyval).traducao += (yyvsp[(5) - (7)]).traducao;
    (yyval).traducao += "    goto " + l_fim + "; // fim do if\n";
    (yyval).traducao += l_else + ":\n";
    (yyval).traducao += (yyvsp[(7) - (7)]).traducao;
    (yyval).traducao += l_fim + ":\n";
;}
    break;

  case 34:
#line 461 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (2)]).traducao;
    (yyval).traducao += (yyvsp[(2) - (2)]).traducao;
    (yyval).traducao += "    goto " + (yyvsp[(1) - (2)]).label + "; // repetir\n";
    (yyval).traducao += (yyvsp[(1) - (2)]).rotulo_break + ":\n";

    pilha_controle.pop_back();
;}
    break;

  case 35:
#line 470 "analisador.y"
    {
    if ((yyvsp[(5) - (7)]).tipo != "boolean") {
        std::cerr << "Erro: condição do 'do-while' deve ser booleana, mas é '" << (yyvsp[(5) - (7)]).tipo << "'\n";
        exit(1);
    }

    (yyval).traducao = (yyvsp[(1) - (7)]).traducao;          // label início
    (yyval).traducao += (yyvsp[(2) - (7)]).traducao;         // corpo do do
    (yyval).traducao += (yyvsp[(1) - (7)]).rotulo_continue + ":\n";  // ponto de continue
    (yyval).traducao += (yyvsp[(5) - (7)]).traducao;
    (yyval).traducao += "    if (" + (yyvsp[(5) - (7)]).label + ") goto " + (yyvsp[(1) - (7)]).label + "; // repetir\n";
    (yyval).traducao += (yyvsp[(1) - (7)]).rotulo_break + ":\n";  // fim do laço

    pilha_controle.pop_back();  // saiu do laço
;}
    break;

  case 36:
#line 488 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(3) - (5)]).traducao;
    (yyval).traducao += (yyvsp[(5) - (5)]).traducao;                  // corpo do laço
    (yyval).traducao += (yyvsp[(3) - (5)]).rotulo_continue + ":\n";   // continue salta para cá
    (yyval).traducao += (yyvsp[(3) - (5)]).incr;                      // incremento
    (yyval).traducao += "    goto " + (yyvsp[(3) - (5)]).label + ";\n"; // volta pro início
    (yyval).traducao += (yyvsp[(3) - (5)]).rotulo_break + ":\n";      // fim do laço
    pilha_controle.pop_back();
;}
    break;

  case 37:
#line 498 "analisador.y"
    {
    if ((yyvsp[(3) - (8)]).tipo != "int") {
        std::cerr << "Erro: expressão do 'switch' deve ser do tipo int, mas é '" << (yyvsp[(3) - (8)]).tipo << "'\n";
        exit(1);
    }

    // Nome único da variável temporária do switch
    std::string switch_var = "__switch_var" + std::to_string(++temp_count);
    declaracoes.push_back("int " + switch_var + ";");

    // Começa com a tradução da expressão
    std::string codigo = (yyvsp[(3) - (8)]).traducao;
    codigo += "    " + switch_var + " = " + (yyvsp[(3) - (8)]).label + "; // guarda valor do switch\n";

    // Divide a tradução dos casos entre ifs e blocos
    std::string casos_if;
    std::string blocos_label;

    std::stringstream ss((yyvsp[(7) - (8)]).traducao);
    std::string linha;
    while (getline(ss, linha)) {
        if (linha.find("if (__switch_var") != std::string::npos) {
            casos_if += linha + "\n";
        } else {
            blocos_label += linha + "\n";
        }
    }

    // Substitui "__switch_var" pelo nome real gerado (ex: __switch_var3)
    size_t pos = 0;
    while ((pos = casos_if.find("__switch_var", pos)) != std::string::npos) {
        casos_if.replace(pos, 13, switch_var);
        pos += switch_var.length();
    }

    pos = 0;
    while ((pos = blocos_label.find("__switch_var", pos)) != std::string::npos) {
        blocos_label.replace(pos, 13, switch_var);
        pos += switch_var.length();
    }

    // Se houver bloco default, insere um goto para ele ao fim dos ifs
    if (blocos_label.find("Ldefault:") != std::string::npos) {
        casos_if += "    goto Ldefault;\n";
    }

    // Fecha o bloco switch com o label final
    std::string l_fim_switch = (yyvsp[(5) - (8)]).label;
    pilha_controle.pop_back();

    (yyval).traducao = codigo + casos_if + blocos_label + l_fim_switch + ":\n";
;}
    break;

  case 38:
#line 556 "analisador.y"
    {
    if (pilha_controle.empty()) {
        std::cerr << "Erro: 'break' fora de estrutura de controle.\n";
        exit(1);
    }
    (yyval).traducao = "    goto " + pilha_controle.back().rotulo_break + "; // break\n";
;}
    break;

  case 39:
#line 564 "analisador.y"
    {
    bool encontrou = false;
    for (int i = pilha_controle.size() - 1; i >= 0; --i) {
        if (pilha_controle[i].tipo == LOOP) {
            (yyval).traducao = "    goto " + pilha_controle[i].rotulo_continue + "; // continue\n";
            encontrou = true;
            break;
        }
    }
    if (!encontrou) {
        std::cerr << "Erro: 'continue' fora de laço.\n";
        exit(1);
    }
;}
    break;

  case 40:
#line 582 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (1)]).traducao;
;}
    break;

  case 41:
#line 587 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (2)]).traducao;
;}
    break;

  case 42:
#line 592 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;
;}
    break;

  case 43:
#line 597 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;
;}
    break;

  case 44:
#line 600 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (1)]).traducao;
;}
    break;

  case 45:
#line 605 "analisador.y"
    {
    std::string l_case = genlabel();
    std::string l_fim;

    if (!pilha_controle.empty() && pilha_controle.back().tipo == SWITCH)
        l_fim = pilha_controle.back().rotulo_break;
    else {
        std::cerr << "Erro interno: 'case' fora de contexto de switch.\n";
        exit(1);
    }

    (yyval).traducao = "    if (__switch_var == " + (yyvsp[(2) - (4)]).label + ") goto " + l_case + ";\n";
    (yyval).traducao += l_case + ":\n" + (yyvsp[(4) - (4)]).traducao;
    (yyval).traducao += "    goto " + l_fim + "; // break implícito no case\n";
;}
    break;

  case 46:
#line 624 "analisador.y"
    {
    (yyval).traducao = "";
;}
    break;

  case 47:
#line 627 "analisador.y"
    {
    std::string l_fim;

    if (!pilha_controle.empty() && pilha_controle.back().tipo == SWITCH)
        l_fim = pilha_controle.back().rotulo_break;
    else {
        std::cerr << "Erro interno: 'default' fora de contexto de switch.\n";
        exit(1);
    }

    (yyval).traducao = "Ldefault:\n" + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    goto " + l_fim + "; // break após default\n";
;}
    break;

  case 48:
#line 645 "analisador.y"
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

  case 49:
#line 656 "analisador.y"
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

  case 50:
#line 667 "analisador.y"
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

  case 51:
#line 678 "analisador.y"
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

  case 52:
#line 689 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " < " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 53:
#line 697 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " <= " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 54:
#line 705 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " > " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 55:
#line 713 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " >= " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 56:
#line 721 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " == " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 57:
#line 729 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " != " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 58:
#line 737 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " && " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 59:
#line 745 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " || " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 60:
#line 753 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(2) - (2)]).traducao;
    (yyval).traducao += "    " + t + " = !" + (yyvsp[(2) - (2)]).label + ";\n";
;}
    break;

  case 61:
#line 761 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "int";
    (yyval).traducao = "    " + t + " = " + (yyvsp[(1) - (1)]).label + ";\n";
;}
    break;

  case 62:
#line 768 "analisador.y"
    {
    std::string t = gentemp("float");
    (yyval).label = t;
    (yyval).tipo = "float";
    (yyval).traducao = "    " + t + " = " + (yyvsp[(1) - (1)]).label + ";\n";
;}
    break;

  case 63:
#line 775 "analisador.y"
    {
    std::string t = get_temp((yyvsp[(1) - (1)]).label);
    (yyval).label = t;
    (yyval).tipo = get_tipo((yyvsp[(1) - (1)]).label);
    (yyval).traducao = "";
;}
    break;

  case 64:
#line 782 "analisador.y"
    {
    std::string t = gentemp("boolean");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = "    " + t + " = 1;\n";
;}
    break;

  case 65:
#line 789 "analisador.y"
    {
    std::string t = gentemp("boolean");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = "    " + t + " = 0;\n";
;}
    break;

  case 66:
#line 797 "analisador.y"
    {
    std::string t = gentemp("char");
    (yyval).label = t;
    (yyval).tipo = "char";
    (yyval).traducao = "    " + t + " = " + (yyvsp[(1) - (1)]).label + ";\n";
;}
    break;

  case 67:
#line 804 "analisador.y"
    {
    std::string t = gentemp("string");
    (yyval).label = t;
    (yyval).tipo = "string";
    (yyval).traducao = "    " + t + " = \"" + (yyvsp[(1) - (1)]).label + "\";\n";
;}
    break;

  case 68:
#line 814 "analisador.y"
    {
    std::string cast = gentemp("int");

    (yyval).traducao = (yyvsp[(4) - (4)]).traducao;
    (yyval).traducao += "    " + cast + " = (int) " + (yyvsp[(4) - (4)]).label + ";\n";
    (yyval).label = cast;
    (yyval).tipo = "int";
;}
    break;

  case 69:
#line 823 "analisador.y"
    {
    std::string cast = gentemp("float");

    (yyval).traducao = (yyvsp[(4) - (4)]).traducao;
    (yyval).traducao += "    " + cast + " = (float) " + (yyvsp[(4) - (4)]).label + ";\n";
    (yyval).label = cast;
    (yyval).tipo = "float";
;}
    break;

  case 70:
#line 834 "analisador.y"
    {
    (yyval).label = (yyvsp[(2) - (3)]).label;
    (yyval).tipo = (yyvsp[(2) - (3)]).tipo;
    (yyval).traducao = (yyvsp[(2) - (3)]).traducao;
;}
    break;


/* Line 1267 of yacc.c.  */
#line 2552 "analisador.tab.c"
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


#line 841 "analisador.y"


int main() {
    yydebug = 1;
    tabela_simbolos.push_back({});
    yyparse();
    return 0;
}















