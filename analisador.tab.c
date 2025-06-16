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
     TK_STRLIT = 291,
     TK_ADDEQ = 292,
     TK_SUBEQ = 293,
     TK_MULTEQ = 294,
     TK_DIVEQ = 295,
     TK_INC = 296,
     TK_DEC = 297
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
#define TK_ADDEQ 292
#define TK_SUBEQ 293
#define TK_MULTEQ 294
#define TK_DIVEQ 295
#define TK_INC 296
#define TK_DEC 297




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
#line 350 "analisador.tab.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   853

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNRULES -- Number of states.  */
#define YYNSTATES  232

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      51,    52,    45,    43,     2,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    49,
       2,    50,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,    54,     2,     2,     2,
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    16,    18,    21,    23,    26,    30,
      36,    40,    46,    50,    56,    60,    66,    67,    72,    73,
      78,    82,    86,    90,    94,    98,   101,   104,   109,   114,
     116,   117,   122,   126,   130,   134,   138,   142,   148,   154,
     160,   166,   172,   177,   182,   187,   192,   196,   200,   206,
     212,   218,   224,   230,   238,   241,   249,   255,   264,   267,
     270,   272,   275,   278,   281,   283,   288,   289,   293,   297,
     301,   305,   309,   313,   317,   321,   325,   329,   333,   337,
     341,   344,   347,   350,   353,   355,   357,   359,   361,   363,
     365,   367,   372,   377
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    58,     3,     5,    47,    57,    48,    -1,
       3,     5,    47,    57,    48,    -1,    68,    -1,    57,    68,
      -1,    59,    -1,    58,    59,    -1,     3,     7,    49,    -1,
       3,     7,    50,    73,    49,    -1,     4,     7,    49,    -1,
       4,     7,    50,    73,    49,    -1,    12,     7,    49,    -1,
      12,     7,    50,    73,    49,    -1,    13,     7,    49,    -1,
      13,     7,    50,    73,    49,    -1,    -1,    47,    61,    57,
      48,    -1,    -1,     7,    50,    73,    49,    -1,     7,    50,
      73,    -1,     7,    37,    73,    -1,     7,    38,    73,    -1,
       7,    39,    73,    -1,     7,    40,    73,    -1,     7,    41,
      -1,     7,    42,    -1,    63,    73,    49,    64,    -1,    28,
      51,    73,    52,    -1,    29,    -1,    -1,     7,    50,    73,
      49,    -1,     3,     7,    49,    -1,     4,     7,    49,    -1,
      12,     7,    49,    -1,    13,     7,    49,    -1,    11,     7,
      49,    -1,    11,     7,    50,    73,    49,    -1,     3,     7,
      50,    73,    49,    -1,     4,     7,    50,    73,    49,    -1,
      12,     7,    50,    73,    49,    -1,    13,     7,    50,    73,
      49,    -1,     7,    37,    73,    49,    -1,     7,    38,    73,
      49,    -1,     7,    39,    73,    49,    -1,     7,    40,    73,
      49,    -1,     7,    41,    49,    -1,     7,    42,    49,    -1,
       9,    51,     7,    52,    49,    -1,     9,    51,    36,    52,
      49,    -1,     9,    51,    73,    52,    49,    -1,    10,    51,
       7,    52,    49,    -1,    26,    51,    73,    52,    60,    -1,
      26,    51,    73,    52,    60,    27,    60,    -1,    66,    60,
      -1,    67,    60,    28,    51,    73,    52,    49,    -1,    30,
      51,    65,    52,    60,    -1,    31,    51,    73,    52,    62,
      47,    69,    48,    -1,    34,    49,    -1,    35,    49,    -1,
      60,    -1,    73,    49,    -1,    70,    72,    -1,    70,    71,
      -1,    71,    -1,    32,     6,    53,    60,    -1,    -1,    33,
      53,    60,    -1,    73,    43,    73,    -1,    73,    44,    73,
      -1,    73,    45,    73,    -1,    73,    46,    73,    -1,    73,
      17,    73,    -1,    73,    18,    73,    -1,    73,    19,    73,
      -1,    73,    20,    73,    -1,    73,    21,    73,    -1,    73,
      22,    73,    -1,    73,    23,    73,    -1,    73,    24,    73,
      -1,    25,    73,    -1,    44,    73,    -1,    43,    73,    -1,
      54,    73,    -1,     6,    -1,     8,    -1,     7,    -1,    14,
      -1,    15,    -1,    16,    -1,    36,    -1,    51,     3,    52,
      73,    -1,    51,     4,    52,    73,    -1,    51,    73,    52,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   193,   193,   205,   222,   223,   228,   229,   233,   237,
     244,   248,   255,   259,   266,   270,   280,   280,   288,   295,
     303,   309,   318,   327,   336,   346,   353,   363,   387,   408,
     424,   424,   442,   447,   452,   457,   462,   471,   485,   492,
     499,   506,   513,   523,   533,   543,   553,   561,   572,   587,
     591,   606,   622,   636,   655,   664,   682,   692,   750,   758,
     776,   781,   786,   791,   794,   799,   818,   821,   839,   850,
     861,   872,   883,   891,   899,   907,   915,   923,   931,   939,
     947,   955,   968,   974,   986,   993,  1000,  1007,  1014,  1022,
    1029,  1043,  1052,  1063
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
  "TK_CASE", "TK_DEFAULT", "TK_BREAK", "TK_CONTINUE", "TK_STRLIT",
  "TK_ADDEQ", "TK_SUBEQ", "TK_MULTEQ", "TK_DIVEQ", "TK_INC", "TK_DEC",
  "'+'", "'-'", "'*'", "'/'", "'{'", "'}'", "';'", "'='", "'('", "')'",
  "':'", "'~'", "$accept", "S", "LISTA_COMANDOS", "DECLS", "DECL", "BLOCO",
  "@1", "SWITCH_INIT", "INIT", "INCR", "FOR_INIT", "WHILE_INIT", "DO_INIT",
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    43,    45,    42,    47,   123,   125,    59,
      61,    40,    41,    58,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    61,    60,    62,    63,
      64,    64,    64,    64,    64,    64,    64,    65,    66,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    69,    70,    70,    71,    72,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     1,     2,     1,     2,     3,     5,
       3,     5,     3,     5,     3,     5,     0,     4,     0,     4,
       3,     3,     3,     3,     3,     2,     2,     4,     4,     1,
       0,     4,     3,     3,     3,     3,     3,     5,     5,     5,
       5,     5,     4,     4,     4,     4,     3,     3,     5,     5,
       5,     5,     5,     7,     2,     7,     5,     8,     2,     2,
       1,     2,     2,     2,     1,     4,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     6,     0,     0,
       0,     0,     0,     1,     0,     7,    30,     8,     0,    10,
       0,    12,     0,    14,     0,     0,     0,     0,    84,    86,
      85,     0,     0,     0,     0,     0,    87,    88,    89,     0,
       0,     0,    29,     0,     0,     0,     0,    90,     0,     0,
      16,     0,     0,     0,    60,     0,     0,     4,     0,    86,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,     0,    58,    59,    82,    81,    30,     0,
       0,     0,    83,     3,     5,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
       9,    11,    13,    15,     0,    32,     0,    33,     0,     0,
       0,     0,     0,    46,    47,     0,    86,    90,     0,     0,
      36,     0,    34,     0,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,    72,    73,    74,
      75,    76,    77,    78,    79,    68,    69,    70,    71,     2,
       0,     0,    42,    43,    44,    45,    31,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,     0,    18,
      17,    91,    92,     0,    38,    39,    48,    49,    50,    51,
      37,    40,    41,    52,     0,     0,    56,     0,     0,     0,
      19,     0,    27,     0,     0,    53,     0,     0,     0,     0,
      25,    26,     0,     0,     0,    66,    64,    55,    21,    22,
      23,    24,    20,     0,    57,     0,    63,    62,     0,     0,
      65,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    53,     6,     7,    54,    88,   197,   139,   202,
     140,    55,    56,    57,   214,   215,   216,   227,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -64
static const yytype_int16 yypact[] =
{
      15,     0,    13,    16,    19,    29,   107,   -64,   -15,    -9,
      -6,    -3,     4,   -64,    17,   -64,   336,   -64,   370,   -64,
     370,   -64,   370,   -64,   370,   -12,    35,    41,   -64,    66,
     -64,    40,    46,    54,    59,    92,   -64,   -64,   -64,   370,
      58,    61,   -64,    63,    67,    52,    75,   -64,   370,   370,
     -64,   126,   370,   189,   -64,    81,    81,   -64,   516,   -64,
     524,   532,   565,   573,   336,     8,    10,   370,   370,   370,
     370,    88,    89,   370,   386,   132,    26,    28,    73,   442,
     370,   370,   142,   370,   -64,   -64,   807,   807,   336,    98,
     101,    -7,   777,   -64,   -64,   -64,   127,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   -64,
     -64,   -64,   -64,   -64,   238,   -64,   370,   -64,   370,   581,
     614,   622,   630,   -64,   -64,   663,   102,   105,    50,   108,
     -64,   370,   -64,   370,   -64,   370,   424,   434,   109,   370,
     111,   470,   287,   370,   370,   -64,   110,   777,   777,   777,
     777,   777,   777,   154,   190,   807,   807,   442,   442,   -64,
     671,   679,   -64,   -64,   -64,   -64,   -64,   115,   117,   118,
     119,   712,   720,   728,    81,   -64,   370,   761,    81,   -64,
     -64,   777,   777,   370,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   152,   769,   176,   -64,   137,   480,    81,
     -64,   106,   -64,   153,   138,   -64,   370,   370,   370,   370,
     -64,   -64,   370,   180,   158,   103,   -64,   -64,   777,   777,
     777,   777,   777,   160,   -64,   163,   -64,   -64,    81,    81,
     -64,   -64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,   -64,   -63,   -64,   215,   -47,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -50,   -64,   -64,     7,   -64,   -18
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      60,   114,    61,    94,    62,     8,    63,     9,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     1,     2,
      10,    79,    25,    11,     9,   142,    12,     3,     4,    13,
      86,    87,    16,    91,    92,    64,   105,   106,   107,   108,
      17,    18,    65,    19,    20,   145,    21,    22,    66,   119,
     120,   121,   122,    23,    24,   125,   128,   115,   116,   117,
     118,    76,   136,   137,    94,   141,    77,    97,    98,    99,
     100,   101,   102,   103,   104,   130,   131,   132,   133,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    74,    94,   105,   106,   107,   108,    75,   160,    78,
     161,    84,   169,    67,    68,    69,    70,    71,    72,    80,
      14,     2,    81,   171,    82,   172,    73,   173,    83,     3,
       4,   177,   134,   135,    85,   181,   182,   193,    50,    89,
      90,   196,    28,    59,    30,   213,   225,   123,   124,   129,
      36,    37,    38,   206,   207,   208,   209,   210,   211,   138,
     143,    39,   205,   144,   167,   146,   212,   168,   194,   176,
     170,   183,    47,   178,   186,   198,   187,   188,   189,    48,
      49,    97,    98,    99,   100,   101,   102,    51,   104,   199,
      52,   230,   231,   201,   203,   213,   223,   217,   218,   219,
     220,   221,    26,    27,   222,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,   224,    97,    98,    99,
     100,   101,   102,   228,    39,    40,   229,    41,    42,    43,
      44,    15,   226,    45,    46,    47,     0,     0,     0,     0,
       0,     0,    48,    49,     0,     0,    50,    93,     0,     0,
      51,    26,    27,    52,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    40,     0,    41,    42,    43,    44,
       0,     0,    45,    46,    47,     0,     0,     0,     0,     0,
       0,    48,    49,     0,     0,    50,   159,     0,     0,    51,
      26,    27,    52,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,     0,    41,    42,    43,    44,     0,
       0,    45,    46,    47,     0,     0,     0,     0,     0,     0,
      48,    49,     0,     0,    50,   180,     0,     0,    51,    26,
      27,    52,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    40,     0,    41,    42,    43,    44,     0,     0,
      45,    46,    47,     0,     0,     0,    28,    59,    30,    48,
      49,     0,     0,    50,    36,    37,    38,    51,     0,     0,
      52,     0,    28,   126,    30,    39,     0,     0,     0,     0,
      36,    37,    38,     0,     0,     0,    47,     0,     0,     0,
       0,    39,     0,    48,    49,     0,     0,     0,     0,     0,
       0,    51,   127,     0,    52,     0,     0,     0,     0,    48,
      49,     0,     0,     0,     0,     0,     0,    51,     0,     0,
      52,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,    97,    98,    99,   100,   101,   102,   103,   104,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,     0,     0,   174,   105,   106,   107,
     108,     0,     0,     0,     0,     0,   175,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,   105,   106,   107,   108,     0,     0,     0,
       0,     0,   179,   105,   106,   107,   108,     0,     0,     0,
       0,     0,   204,    97,    98,    99,   100,   101,   102,   103,
     104,    97,    98,    99,   100,   101,   102,   103,   104,    97,
      98,    99,   100,   101,   102,   103,   104,     0,     0,   105,
     106,   107,   108,     0,     0,   109,     0,   105,   106,   107,
     108,     0,     0,   110,     0,   105,   106,   107,   108,     0,
       0,   111,    97,    98,    99,   100,   101,   102,   103,   104,
      97,    98,    99,   100,   101,   102,   103,   104,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,   105,   106,
     107,   108,     0,     0,   112,     0,   105,   106,   107,   108,
       0,     0,   113,     0,   105,   106,   107,   108,     0,     0,
     162,    97,    98,    99,   100,   101,   102,   103,   104,    97,
      98,    99,   100,   101,   102,   103,   104,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,   105,   106,   107,
     108,     0,     0,   163,     0,   105,   106,   107,   108,     0,
       0,   164,     0,   105,   106,   107,   108,     0,     0,   165,
      97,    98,    99,   100,   101,   102,   103,   104,    97,    98,
      99,   100,   101,   102,   103,   104,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,   105,   106,   107,   108,
       0,     0,   166,     0,   105,   106,   107,   108,     0,     0,
     184,     0,   105,   106,   107,   108,     0,     0,   185,    97,
      98,    99,   100,   101,   102,   103,   104,    97,    98,    99,
     100,   101,   102,   103,   104,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,   105,   106,   107,   108,     0,
       0,   190,     0,   105,   106,   107,   108,     0,     0,   191,
       0,   105,   106,   107,   108,     0,     0,   192,    97,    98,
      99,   100,   101,   102,   103,   104,    97,    98,    99,   100,
     101,   102,   103,   104,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,   105,   106,   107,   108,     0,     0,
     195,     0,   105,   106,   107,   108,     0,     0,   200,     0,
     105,   106,   107,   108,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   108
};

static const yytype_int16 yycheck[] =
{
      18,    64,    20,    53,    22,     5,    24,     7,    55,    56,
      17,    18,    19,    20,    21,    22,    23,    24,     3,     4,
       7,    39,     5,     7,     7,    88,     7,    12,    13,     0,
      48,    49,    47,    51,    52,    47,    43,    44,    45,    46,
      49,    50,     7,    49,    50,    52,    49,    50,     7,    67,
      68,    69,    70,    49,    50,    73,    74,    49,    50,    49,
      50,     7,    80,    81,   114,    83,     7,    17,    18,    19,
      20,    21,    22,    23,    24,    49,    50,    49,    50,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    51,   142,    43,    44,    45,    46,    51,   116,     7,
     118,    49,    52,    37,    38,    39,    40,    41,    42,    51,
       3,     4,    51,   131,    51,   133,    50,   135,    51,    12,
      13,   139,    49,    50,    49,   143,   144,   174,    47,     3,
       4,   178,     6,     7,     8,    32,    33,    49,    49,     7,
      14,    15,    16,    37,    38,    39,    40,    41,    42,     7,
      52,    25,   199,    52,    52,    28,    50,    52,   176,    50,
      52,    51,    36,    52,    49,   183,    49,    49,    49,    43,
      44,    17,    18,    19,    20,    21,    22,    51,    24,    27,
      54,   228,   229,     7,    47,    32,     6,    49,   206,   207,
     208,   209,     3,     4,   212,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    48,    17,    18,    19,
      20,    21,    22,    53,    25,    26,    53,    28,    29,    30,
      31,     6,   215,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    47,    48,    -1,    -1,
      51,     3,     4,    54,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      -1,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    47,    48,    -1,    -1,    51,
       3,     4,    54,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    -1,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    47,    48,    -1,    -1,    51,     3,
       4,    54,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    -1,    -1,
      34,    35,    36,    -1,    -1,    -1,     6,     7,     8,    43,
      44,    -1,    -1,    47,    14,    15,    16,    51,    -1,    -1,
      54,    -1,     6,     7,     8,    25,    -1,    -1,    -1,    -1,
      14,    15,    16,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    25,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    36,    -1,    54,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      54,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    17,
      18,    19,    20,    21,    22,    23,    24,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    17,    18,    19,    20,    21,    22,    23,
      24,    17,    18,    19,    20,    21,    22,    23,    24,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    17,    18,    19,    20,    21,    22,    23,    24,
      17,    18,    19,    20,    21,    22,    23,    24,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    17,    18,    19,    20,    21,    22,    23,    24,    17,
      18,    19,    20,    21,    22,    23,    24,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      17,    18,    19,    20,    21,    22,    23,    24,    17,    18,
      19,    20,    21,    22,    23,    24,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    -1,    43,    44,    45,    46,    -1,    -1,    49,    17,
      18,    19,    20,    21,    22,    23,    24,    17,    18,    19,
      20,    21,    22,    23,    24,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    17,    18,
      19,    20,    21,    22,    23,    24,    17,    18,    19,    20,
      21,    22,    23,    24,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    -1,    43,    44,    45,    46,    -1,    -1,    49,    -1,
      43,    44,    45,    46,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    12,    13,    56,    58,    59,     5,     7,
       7,     7,     7,     0,     3,    59,    47,    49,    50,    49,
      50,    49,    50,    49,    50,     5,     3,     4,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    25,
      26,    28,    29,    30,    31,    34,    35,    36,    43,    44,
      47,    51,    54,    57,    60,    66,    67,    68,    73,     7,
      73,    73,    73,    73,    47,     7,     7,    37,    38,    39,
      40,    41,    42,    50,    51,    51,     7,     7,     7,    73,
      51,    51,    51,    51,    49,    49,    73,    73,    61,     3,
       4,    73,    73,    48,    68,    60,    60,    17,    18,    19,
      20,    21,    22,    23,    24,    43,    44,    45,    46,    49,
      49,    49,    49,    49,    57,    49,    50,    49,    50,    73,
      73,    73,    73,    49,    49,    73,     7,    36,    73,     7,
      49,    50,    49,    50,    49,    50,    73,    73,     7,    63,
      65,    73,    57,    52,    52,    52,    28,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    48,
      73,    73,    49,    49,    49,    49,    49,    52,    52,    52,
      52,    73,    73,    73,    52,    52,    50,    73,    52,    52,
      48,    73,    73,    51,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    60,    73,    49,    60,    62,    73,    27,
      49,     7,    64,    47,    52,    60,    37,    38,    39,    40,
      41,    42,    50,    32,    69,    70,    71,    49,    73,    73,
      73,    73,    73,     6,    48,    33,    71,    72,    53,    53,
      60,    60
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
#line 193 "analisador.y"
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
#line 205 "analisador.y"
    {
    std::cout << "/* Compilador Faquir Rebuild */\n";
    std::cout << "#include <stdio.h>\n";
    std::cout << "#include <stdlib.h>\n";
    std::cout << "#include <string.h>\n";
    std::cout << "int main(void) {\n";

    for (const std::string& decl : declaracoes)
        std::cout << "    " << decl << "\n";

    std::cout << (yyvsp[(4) - (5)]).traducao;
    std::cout << "    return 0;\n";
    std::cout << "}\n";
;}
    break;

  case 5:
#line 223 "analisador.y"
    {
                   (yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;
               ;}
    break;

  case 8:
#line 233 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "int");
    (yyval).traducao = "";
;}
    break;

  case 9:
#line 237 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "int");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "int", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 10:
#line 244 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "float");
    (yyval).traducao = "";
;}
    break;

  case 11:
#line 248 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "float");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "float", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 12:
#line 255 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "char");
    (yyval).traducao = "";
;}
    break;

  case 13:
#line 259 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "char");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "char", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 14:
#line 266 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "boolean");
    (yyval).traducao = "";
;}
    break;

  case 15:
#line 270 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "boolean");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "boolean", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 16:
#line 280 "analisador.y"
    {
    tabela_simbolos.push_back({});  
;}
    break;

  case 17:
#line 282 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(3) - (4)]).traducao;
    tabela_simbolos.pop_back();     
;}
    break;

  case 18:
#line 288 "analisador.y"
    {
    std::string l_fim_switch = genlabel();
    pilha_controle.push_back({SWITCH, l_fim_switch, ""});
    (yyval).label = l_fim_switch;
;}
    break;

  case 19:
#line 295 "analisador.y"
    {
    std::string var_temp = get_temp((yyvsp[(1) - (4)]).label);
    std::string var_tipo = get_tipo((yyvsp[(1) - (4)]).label);
    std::string t = (yyvsp[(3) - (4)]).traducao + "    " + var_temp + " = " + (yyvsp[(3) - (4)]).label + ";\n";
    (yyval).traducao = t;
;}
    break;

  case 20:
#line 303 "analisador.y"
    {
    std::string var_temp = get_temp((yyvsp[(1) - (3)]).label);
    std::string var_tipo = get_tipo((yyvsp[(1) - (3)]).label);
    std::string t = (yyvsp[(3) - (3)]).traducao + "    " + var_temp + " = " + (yyvsp[(3) - (3)]).label + ";\n";
    (yyval).traducao = t;
;}
    break;

  case 21:
#line 309 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (3)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (3)]).label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast((yyvsp[(3) - (3)]).label, (yyvsp[(3) - (3)]).tipo, tipo, (yyvsp[(3) - (3)]).traducao);
    (yyval).traducao = (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + temp + " = " + var + " + " + cast + ";\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 22:
#line 318 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (3)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (3)]).label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast((yyvsp[(3) - (3)]).label, (yyvsp[(3) - (3)]).tipo, tipo, (yyvsp[(3) - (3)]).traducao);
    (yyval).traducao = (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + temp + " = " + var + " - " + cast + ";\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 23:
#line 327 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (3)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (3)]).label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast((yyvsp[(3) - (3)]).label, (yyvsp[(3) - (3)]).tipo, tipo, (yyvsp[(3) - (3)]).traducao);
    (yyval).traducao = (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + temp + " = " + var + " * " + cast + ";\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 24:
#line 336 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (3)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (3)]).label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast((yyvsp[(3) - (3)]).label, (yyvsp[(3) - (3)]).tipo, tipo, (yyvsp[(3) - (3)]).traducao);
    (yyval).traducao = (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + temp + " = " + var + " / " + cast + ";\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 25:
#line 346 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (2)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (2)]).label);
    std::string temp = gentemp(tipo);
    (yyval).traducao = "    " + temp + " = " + var + " + 1;\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 26:
#line 353 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (2)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (2)]).label);
    std::string temp = gentemp(tipo);
    (yyval).traducao = "    " + temp + " = " + var + " - 1;\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 27:
#line 363 "analisador.y"
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

  case 28:
#line 387 "analisador.y"
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

  case 29:
#line 408 "analisador.y"
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

  case 31:
#line 424 "analisador.y"
    {
    std::string var_temp = get_temp((yyvsp[(1) - (4)]).label);
    std::string var_tipo = get_tipo((yyvsp[(1) - (4)]).label);
    std::ostringstream ss;

    ss << (yyvsp[(3) - (4)]).traducao;

    if (var_tipo == "string") {
        ss << "    " << var_temp << " = (char*) malloc(strlen(" << (yyvsp[(3) - (4)]).label << ") + 1);\n";
        ss << "    strcpy(" << var_temp << ", " << (yyvsp[(3) - (4)]).label << ");\n";
    } else {
        ss << "    " << var_temp << " = " << (yyvsp[(3) - (4)]).label << ";\n";
    }

    (yyval).traducao = ss.str();
;}
    break;

  case 32:
#line 442 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "int");
    (yyval).traducao = "";
;}
    break;

  case 33:
#line 447 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "float");
    (yyval).traducao = "";
;}
    break;

  case 34:
#line 452 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "char");
    (yyval).traducao = "";
;}
    break;

  case 35:
#line 457 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "boolean");
    (yyval).traducao = "";
;}
    break;

  case 36:
#line 462 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "string");
    std::ostringstream ss;
    ss << "    " << get_temp((yyvsp[(2) - (3)]).label) << " = (char*) malloc(100);\n";
    (yyval).traducao = ss.str();
;}
    break;

  case 37:
#line 471 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "string");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::ostringstream ss;

    ss << (yyvsp[(4) - (5)]).traducao;

    ss << "    " << temp << " = (char*) malloc(strlen(" << (yyvsp[(4) - (5)]).label << ") + 1);\n";
    ss << "    strcpy(" << temp << ", " << (yyvsp[(4) - (5)]).label << ");\n";

    (yyval).traducao = ss.str();
;}
    break;

  case 38:
#line 485 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "int");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "int", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 39:
#line 492 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "float");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "float", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 40:
#line 499 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "char");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "char", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 41:
#line 506 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "boolean");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "boolean", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 42:
#line 513 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (4)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (4)]).label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast((yyvsp[(3) - (4)]).label, (yyvsp[(3) - (4)]).tipo, tipo, (yyvsp[(3) - (4)]).traducao);
    (yyval).traducao = (yyvsp[(3) - (4)]).traducao;
    (yyval).traducao += "    " + temp + " = " + var + " + " + cast + ";\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 43:
#line 523 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (4)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (4)]).label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast((yyvsp[(3) - (4)]).label, (yyvsp[(3) - (4)]).tipo, tipo, (yyvsp[(3) - (4)]).traducao);
    (yyval).traducao = (yyvsp[(3) - (4)]).traducao;
    (yyval).traducao += "    " + temp + " = " + var + " - " + cast + ";\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 44:
#line 533 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (4)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (4)]).label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast((yyvsp[(3) - (4)]).label, (yyvsp[(3) - (4)]).tipo, tipo, (yyvsp[(3) - (4)]).traducao);
    (yyval).traducao = (yyvsp[(3) - (4)]).traducao;
    (yyval).traducao += "    " + temp + " = " + var + " * " + cast + ";\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 45:
#line 543 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (4)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (4)]).label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast((yyvsp[(3) - (4)]).label, (yyvsp[(3) - (4)]).tipo, tipo, (yyvsp[(3) - (4)]).traducao);
    (yyval).traducao = (yyvsp[(3) - (4)]).traducao;
    (yyval).traducao += "    " + temp + " = " + var + " / " + cast + ";\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 46:
#line 553 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (3)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (3)]).label);
    std::string temp = gentemp(tipo);
    (yyval).traducao = "    " + temp + " = " + var + " + 1;\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 47:
#line 561 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (3)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (3)]).label);
    std::string temp = gentemp(tipo);
    (yyval).traducao = "    " + temp + " = " + var + " - 1;\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 48:
#line 572 "analisador.y"
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

  case 49:
#line 587 "analisador.y"
    {
    (yyval).traducao = "    printf(\"%s\\n\", \"" + (yyvsp[(3) - (5)]).label + "\");\n";
;}
    break;

  case 50:
#line 591 "analisador.y"
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

  case 51:
#line 606 "analisador.y"
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

  case 52:
#line 622 "analisador.y"
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

  case 53:
#line 636 "analisador.y"
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

  case 54:
#line 655 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (2)]).traducao;
    (yyval).traducao += (yyvsp[(2) - (2)]).traducao;
    (yyval).traducao += "    goto " + (yyvsp[(1) - (2)]).label + "; // repetir\n";
    (yyval).traducao += (yyvsp[(1) - (2)]).rotulo_break + ":\n";

    pilha_controle.pop_back();
;}
    break;

  case 55:
#line 664 "analisador.y"
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

  case 56:
#line 682 "analisador.y"
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

  case 57:
#line 692 "analisador.y"
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

  case 58:
#line 750 "analisador.y"
    {
    if (pilha_controle.empty()) {
        std::cerr << "Erro: 'break' fora de estrutura de controle.\n";
        exit(1);
    }
    (yyval).traducao = "    goto " + pilha_controle.back().rotulo_break + "; // break\n";
;}
    break;

  case 59:
#line 758 "analisador.y"
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

  case 60:
#line 776 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (1)]).traducao;
;}
    break;

  case 61:
#line 781 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (2)]).traducao;
;}
    break;

  case 62:
#line 786 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;
;}
    break;

  case 63:
#line 791 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;
;}
    break;

  case 64:
#line 794 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (1)]).traducao;
;}
    break;

  case 65:
#line 799 "analisador.y"
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

  case 66:
#line 818 "analisador.y"
    {
    (yyval).traducao = "";
;}
    break;

  case 67:
#line 821 "analisador.y"
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

  case 68:
#line 839 "analisador.y"
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

  case 69:
#line 850 "analisador.y"
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

  case 70:
#line 861 "analisador.y"
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

  case 71:
#line 872 "analisador.y"
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

  case 72:
#line 883 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " < " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 73:
#line 891 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " <= " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 74:
#line 899 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " > " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 75:
#line 907 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " >= " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 76:
#line 915 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " == " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 77:
#line 923 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " != " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 78:
#line 931 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " && " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 79:
#line 939 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " || " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 80:
#line 947 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(2) - (2)]).traducao;
    (yyval).traducao += "    " + t + " = !" + (yyvsp[(2) - (2)]).label + ";\n";
;}
    break;

  case 81:
#line 955 "analisador.y"
    {
    std::string tipo = (yyvsp[(2) - (2)]).tipo;
    if (tipo != "int" && tipo != "float") {
        std::cerr << "Erro: operador unário '-' só pode ser aplicado a int ou float (não a '" << tipo << "')\n";
        exit(1);
    }
    std::string temp = gentemp(tipo);
    (yyval).label = temp;
    (yyval).tipo = tipo;
    (yyval).traducao = (yyvsp[(2) - (2)]).traducao;
    (yyval).traducao += "    " + temp + " = -" + (yyvsp[(2) - (2)]).label + ";\n";
;}
    break;

  case 82:
#line 968 "analisador.y"
    {
    (yyval).label = (yyvsp[(2) - (2)]).label;
    (yyval).tipo = (yyvsp[(2) - (2)]).tipo;
    (yyval).traducao = (yyvsp[(2) - (2)]).traducao; // não altera o valor
;}
    break;

  case 83:
#line 974 "analisador.y"
    {
    if ((yyvsp[(2) - (2)]).tipo != "int") {
        std::cerr << "Erro: operador '~' só pode ser aplicado a inteiros.\n";
        exit(1);
    }
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "int";
    (yyval).traducao = (yyvsp[(2) - (2)]).traducao + "    " + t + " = ~" + (yyvsp[(2) - (2)]).label + ";\n";
;}
    break;

  case 84:
#line 986 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "int";
    (yyval).traducao = "    " + t + " = " + (yyvsp[(1) - (1)]).label + ";\n";
;}
    break;

  case 85:
#line 993 "analisador.y"
    {
    std::string t = gentemp("float");
    (yyval).label = t;
    (yyval).tipo = "float";
    (yyval).traducao = "    " + t + " = " + (yyvsp[(1) - (1)]).label + ";\n";
;}
    break;

  case 86:
#line 1000 "analisador.y"
    {
    std::string t = get_temp((yyvsp[(1) - (1)]).label);
    (yyval).label = t;
    (yyval).tipo = get_tipo((yyvsp[(1) - (1)]).label);
    (yyval).traducao = "";
;}
    break;

  case 87:
#line 1007 "analisador.y"
    {
    std::string t = gentemp("boolean");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = "    " + t + " = 1;\n";
;}
    break;

  case 88:
#line 1014 "analisador.y"
    {
    std::string t = gentemp("boolean");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = "    " + t + " = 0;\n";
;}
    break;

  case 89:
#line 1022 "analisador.y"
    {
    std::string t = gentemp("char");
    (yyval).label = t;
    (yyval).tipo = "char";
    (yyval).traducao = "    " + t + " = " + (yyvsp[(1) - (1)]).label + ";\n";
;}
    break;

  case 90:
#line 1029 "analisador.y"
    {
    std::string t = gentemp("string");
    std::ostringstream ss;
    ss << "    " << t << " = (char*) malloc(strlen(\"" << (yyvsp[(1) - (1)]).label << "\") + 1);\n";
    ss << "    strcpy(" << t << ", \"" << (yyvsp[(1) - (1)]).label << "\");\n";
    (yyval).label = t;
    (yyval).tipo = "string";
    (yyval).traducao = ss.str();
;}
    break;

  case 91:
#line 1043 "analisador.y"
    {
    std::string cast = gentemp("int");

    (yyval).traducao = (yyvsp[(4) - (4)]).traducao;
    (yyval).traducao += "    " + cast + " = (int) " + (yyvsp[(4) - (4)]).label + ";\n";
    (yyval).label = cast;
    (yyval).tipo = "int";
;}
    break;

  case 92:
#line 1052 "analisador.y"
    {
    std::string cast = gentemp("float");

    (yyval).traducao = (yyvsp[(4) - (4)]).traducao;
    (yyval).traducao += "    " + cast + " = (float) " + (yyvsp[(4) - (4)]).label + ";\n";
    (yyval).label = cast;
    (yyval).tipo = "float";
;}
    break;

  case 93:
#line 1063 "analisador.y"
    {
    (yyval).label = (yyvsp[(2) - (3)]).label;
    (yyval).tipo = (yyvsp[(2) - (3)]).tipo;
    (yyval).traducao = (yyvsp[(2) - (3)]).traducao;
;}
    break;


/* Line 1267 of yacc.c.  */
#line 2958 "analisador.tab.c"
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


#line 1070 "analisador.y"


int main() {
    yydebug = 1;
    tabela_simbolos.push_back({});
    yyparse();
    return 0;
}















