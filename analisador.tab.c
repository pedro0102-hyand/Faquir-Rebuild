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
     TK_DEC = 297,
     TK_POW = 298
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
#define TK_POW 298




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
#line 352 "analisador.tab.c"

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
#define YYLAST   954

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  254

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      52,    53,    46,    44,     2,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    50,
       2,    51,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,    55,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    16,    18,    21,    23,    26,    30,
      36,    40,    46,    50,    56,    60,    66,    67,    72,    73,
      78,    84,    90,    96,   102,   106,   110,   114,   118,   122,
     125,   128,   133,   138,   140,   141,   146,   150,   154,   158,
     162,   166,   172,   178,   184,   190,   196,   201,   206,   211,
     216,   220,   224,   230,   236,   242,   248,   254,   262,   265,
     273,   279,   288,   291,   294,   296,   299,   302,   305,   307,
     312,   313,   317,   321,   325,   329,   333,   337,   341,   345,
     349,   353,   357,   361,   365,   369,   372,   375,   378,   381,
     383,   385,   387,   389,   391,   393,   395,   400,   405
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    59,     3,     5,    48,    58,    49,    -1,
       3,     5,    48,    58,    49,    -1,    69,    -1,    58,    69,
      -1,    60,    -1,    59,    60,    -1,     3,     7,    50,    -1,
       3,     7,    51,    74,    50,    -1,     4,     7,    50,    -1,
       4,     7,    51,    74,    50,    -1,    12,     7,    50,    -1,
      12,     7,    51,    74,    50,    -1,    13,     7,    50,    -1,
      13,     7,    51,    74,    50,    -1,    -1,    48,    62,    58,
      49,    -1,    -1,     7,    51,    74,    50,    -1,     3,     7,
      51,    74,    50,    -1,     4,     7,    51,    74,    50,    -1,
      12,     7,    51,    74,    50,    -1,    13,     7,    51,    74,
      50,    -1,     7,    51,    74,    -1,     7,    37,    74,    -1,
       7,    38,    74,    -1,     7,    39,    74,    -1,     7,    40,
      74,    -1,     7,    41,    -1,     7,    42,    -1,    64,    74,
      50,    65,    -1,    28,    52,    74,    53,    -1,    29,    -1,
      -1,     7,    51,    74,    50,    -1,     3,     7,    50,    -1,
       4,     7,    50,    -1,    12,     7,    50,    -1,    13,     7,
      50,    -1,    11,     7,    50,    -1,    11,     7,    51,    74,
      50,    -1,     3,     7,    51,    74,    50,    -1,     4,     7,
      51,    74,    50,    -1,    12,     7,    51,    74,    50,    -1,
      13,     7,    51,    74,    50,    -1,     7,    37,    74,    50,
      -1,     7,    38,    74,    50,    -1,     7,    39,    74,    50,
      -1,     7,    40,    74,    50,    -1,     7,    41,    50,    -1,
       7,    42,    50,    -1,     9,    52,     7,    53,    50,    -1,
       9,    52,    36,    53,    50,    -1,     9,    52,    74,    53,
      50,    -1,    10,    52,     7,    53,    50,    -1,    26,    52,
      74,    53,    61,    -1,    26,    52,    74,    53,    61,    27,
      61,    -1,    67,    61,    -1,    68,    61,    28,    52,    74,
      53,    50,    -1,    30,    52,    66,    53,    61,    -1,    31,
      52,    74,    53,    63,    48,    70,    49,    -1,    34,    50,
      -1,    35,    50,    -1,    61,    -1,    74,    50,    -1,    71,
      73,    -1,    71,    72,    -1,    72,    -1,    32,     6,    54,
      61,    -1,    -1,    33,    54,    61,    -1,    74,    44,    74,
      -1,    74,    45,    74,    -1,    74,    46,    74,    -1,    74,
      47,    74,    -1,    74,    43,    74,    -1,    74,    17,    74,
      -1,    74,    18,    74,    -1,    74,    19,    74,    -1,    74,
      20,    74,    -1,    74,    21,    74,    -1,    74,    22,    74,
      -1,    74,    23,    74,    -1,    74,    24,    74,    -1,    25,
      74,    -1,    45,    74,    -1,    44,    74,    -1,    55,    74,
      -1,     6,    -1,     8,    -1,     7,    -1,    14,    -1,    15,
      -1,    16,    -1,    36,    -1,    52,     3,    53,    74,    -1,
      52,     4,    53,    74,    -1,    52,    74,    53,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   197,   197,   209,   227,   228,   233,   234,   238,   242,
     250,   254,   261,   265,   272,   276,   286,   286,   294,   302,
     308,   314,   320,   326,   336,   342,   351,   360,   369,   379,
     386,   396,   420,   441,   457,   457,   475,   480,   485,   490,
     495,   504,   518,   525,   532,   539,   546,   556,   566,   576,
     586,   594,   605,   620,   624,   639,   655,   669,   688,   697,
     715,   725,   783,   791,   809,   814,   819,   824,   827,   832,
     851,   854,   872,   883,   894,   905,   916,   928,   936,   944,
     952,   960,   968,   976,   984,   992,  1000,  1013,  1019,  1031,
    1038,  1045,  1052,  1059,  1067,  1074,  1088,  1097,  1108
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
  "TK_POW", "'+'", "'-'", "'*'", "'/'", "'{'", "'}'", "';'", "'='", "'('",
  "')'", "':'", "'~'", "$accept", "S", "LISTA_COMANDOS", "DECLS", "DECL",
  "BLOCO", "@1", "SWITCH_INIT", "INIT", "INCR", "FOR_INIT", "WHILE_INIT",
  "DO_INIT", "COMANDO", "CASOS", "LISTA_CASE", "CASE", "DEFAULT_OPCIONAL",
  "E", 0
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
     295,   296,   297,   298,    43,    45,    42,    47,   123,   125,
      59,    61,    40,    41,    58,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    60,    62,    61,    63,    64,
      64,    64,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    66,    67,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    70,    71,    71,    72,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     1,     2,     1,     2,     3,     5,
       3,     5,     3,     5,     3,     5,     0,     4,     0,     4,
       5,     5,     5,     5,     3,     3,     3,     3,     3,     2,
       2,     4,     4,     1,     0,     4,     3,     3,     3,     3,
       3,     5,     5,     5,     5,     5,     4,     4,     4,     4,
       3,     3,     5,     5,     5,     5,     5,     7,     2,     7,
       5,     8,     2,     2,     1,     2,     2,     2,     1,     4,
       0,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     6,     0,     0,
       0,     0,     0,     1,     0,     7,    34,     8,     0,    10,
       0,    12,     0,    14,     0,     0,     0,     0,    89,    91,
      90,     0,     0,     0,     0,     0,    92,    93,    94,     0,
       0,     0,    33,     0,     0,     0,     0,    95,     0,     0,
      16,     0,     0,     0,    64,     0,     0,     4,     0,    91,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,    62,    63,    87,    86,    34,     0,
       0,     0,    88,     3,     5,    58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,     9,    11,    13,    15,     0,    36,     0,    37,     0,
       0,     0,     0,     0,    50,    51,     0,    91,    95,     0,
       0,    40,     0,    38,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      76,    72,    73,    74,    75,     2,     0,     0,    46,    47,
      48,    49,    35,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,     0,     0,    18,
      17,    96,    97,     0,    42,    43,    52,    53,    54,    55,
      41,    44,    45,    56,     0,     0,     0,     0,     0,     0,
      60,     0,     0,     0,     0,     0,    19,     0,     0,     0,
      31,     0,     0,    57,    20,    21,    22,    23,     0,     0,
       0,     0,    29,    30,     0,     0,     0,    70,    68,    59,
      25,    26,    27,    28,    24,     0,    61,     0,    67,    66,
       0,     0,    69,    71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    53,     6,     7,    54,    88,   211,   144,   220,
     145,    55,    56,    57,   236,   237,   238,   249,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -49
static const yytype_int16 yypact[] =
{
      41,    -4,    -2,    25,    28,    47,    56,   -49,    16,   -31,
      22,    24,    26,   -49,    36,   -49,   361,   -49,   127,   -49,
     127,   -49,   127,   -49,   127,    30,    63,    85,   -49,   154,
     -49,    50,    52,   106,   108,   110,   -49,   -49,   -49,   127,
      86,    87,   -49,    92,    93,    79,    97,   -49,   127,   127,
     -49,   396,   127,   211,   -49,   100,   100,   -49,   557,   -49,
     591,   599,   607,   641,   361,    55,    57,   127,   127,   127,
     127,    99,   101,   127,   411,   143,    59,    61,    77,     5,
     127,   127,    54,   127,   -49,   -49,   137,   137,   361,   109,
     111,    -7,   907,   -49,   -49,   -49,   125,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     -49,   -49,   -49,   -49,   -49,   261,   -49,   127,   -49,   127,
     649,   657,   691,   699,   -49,   -49,   707,   114,   115,   450,
     116,   -49,   127,   -49,   127,   -49,   127,   461,   498,   163,
     166,   123,   169,   170,   127,   128,   509,   311,   127,   127,
     -49,   126,   907,   907,   907,   907,   907,   907,    76,   103,
     103,   137,   137,     5,     5,   -49,   741,   749,   -49,   -49,
     -49,   -49,   -49,   135,   138,   147,   148,   757,   791,   799,
     100,   -49,   149,   150,   127,   153,   155,   807,   100,   -49,
     -49,   907,   907,   127,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   172,   127,   127,   841,   127,   127,   200,
     -49,   160,   546,   100,   849,   857,   -49,   891,   899,   192,
     -49,   177,   178,   -49,   -49,   -49,   -49,   -49,   127,   127,
     127,   127,   -49,   -49,   127,   229,   189,   104,   -49,   -49,
     907,   907,   907,   907,   907,   190,   -49,   194,   -49,   -49,
     100,   100,   -49,   -49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -49,   -49,   -46,   -49,   243,   -48,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   -44,   -49,   -49,    13,   -49,   -18
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      60,     8,    61,     9,    62,    10,    63,    95,    96,    94,
      97,    98,    99,   100,   101,   102,   103,   104,   115,    17,
      18,    79,    97,    98,    99,   100,   101,   102,   103,   104,
      86,    87,    11,    91,    92,    12,   105,   106,   107,   108,
     109,    25,   147,     9,     1,     2,   150,    13,   105,   120,
     121,   122,   123,     3,     4,   126,   129,   139,   140,    14,
       2,   141,   137,   138,    16,   146,   142,   143,     3,     4,
      65,    94,    19,    20,    21,    22,    23,    24,    64,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,    66,    97,    98,    99,   100,   101,   102,   166,
     104,   167,    74,    94,    75,   116,   117,   118,   119,   131,
     132,   133,   134,    76,   177,    77,   178,    78,   179,   105,
      97,    98,    99,   100,   101,   102,   187,   135,   136,    84,
     191,   192,   203,    28,    59,    30,   235,   247,    80,    81,
     210,    36,    37,    38,    82,    83,   105,    85,    50,   124,
     130,   125,    39,   151,    97,    98,    99,   100,   101,   102,
     103,   104,   148,    47,   149,   223,   206,   173,   174,   176,
     182,    48,    49,   183,   184,   212,   185,   186,   193,    51,
     105,   188,    52,   108,   109,   196,   214,   215,   197,   217,
     218,    67,    68,    69,    70,    71,    72,   198,   199,   213,
     204,   205,   252,   253,   207,    73,   208,   219,   221,   235,
     240,   241,   242,   243,    26,    27,   244,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,   239,   228,
     229,   230,   231,   232,   233,   245,    39,    40,   246,    41,
      42,    43,    44,   234,   250,    45,    46,    47,   251,    15,
     248,     0,     0,     0,     0,    48,    49,     0,     0,    50,
      93,     0,     0,    51,    26,    27,    52,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    40,     0,    41,
      42,    43,    44,     0,     0,    45,    46,    47,     0,     0,
       0,     0,     0,     0,     0,    48,    49,     0,     0,    50,
     165,     0,     0,    51,    26,    27,    52,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    40,     0,    41,
      42,    43,    44,     0,     0,    45,    46,    47,     0,     0,
       0,     0,     0,     0,     0,    48,    49,     0,     0,    50,
     190,     0,     0,    51,    26,    27,    52,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    40,     0,    41,
      42,    43,    44,     0,     0,    45,    46,    47,     0,    89,
      90,     0,    28,    59,    30,    48,    49,     0,     0,    50,
      36,    37,    38,    51,     0,     0,    52,    28,   127,    30,
       0,    39,     0,     0,     0,    36,    37,    38,     0,     0,
       0,     0,    47,     0,     0,     0,    39,     0,     0,     0,
      48,    49,     0,     0,     0,     0,     0,   128,    51,     0,
       0,    52,     0,     0,     0,    48,    49,     0,     0,     0,
       0,     0,     0,    51,     0,     0,    52,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,     0,     0,
       0,     0,     0,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,   175,   105,   106,   107,   108,   109,     0,
       0,     0,     0,     0,   180,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,   181,   105,   106,   107,   108,   109,     0,     0,     0,
       0,     0,   189,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,   105,
     106,   107,   108,   109,     0,     0,     0,     0,     0,   222,
     105,   106,   107,   108,   109,     0,     0,   110,    97,    98,
      99,   100,   101,   102,   103,   104,    97,    98,    99,   100,
     101,   102,   103,   104,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,   105,   106,   107,   108,   109,     0,
       0,   111,   105,   106,   107,   108,   109,     0,     0,   112,
     105,   106,   107,   108,   109,     0,     0,   113,    97,    98,
      99,   100,   101,   102,   103,   104,    97,    98,    99,   100,
     101,   102,   103,   104,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,   105,   106,   107,   108,   109,     0,
       0,   114,   105,   106,   107,   108,   109,     0,     0,   168,
     105,   106,   107,   108,   109,     0,     0,   169,    97,    98,
      99,   100,   101,   102,   103,   104,    97,    98,    99,   100,
     101,   102,   103,   104,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,   105,   106,   107,   108,   109,     0,
       0,   170,   105,   106,   107,   108,   109,     0,     0,   171,
     105,   106,   107,   108,   109,     0,     0,   172,    97,    98,
      99,   100,   101,   102,   103,   104,    97,    98,    99,   100,
     101,   102,   103,   104,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,   105,   106,   107,   108,   109,     0,
       0,   194,   105,   106,   107,   108,   109,     0,     0,   195,
     105,   106,   107,   108,   109,     0,     0,   200,    97,    98,
      99,   100,   101,   102,   103,   104,    97,    98,    99,   100,
     101,   102,   103,   104,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,   105,   106,   107,   108,   109,     0,
       0,   201,   105,   106,   107,   108,   109,     0,     0,   202,
     105,   106,   107,   108,   109,     0,     0,   209,    97,    98,
      99,   100,   101,   102,   103,   104,    97,    98,    99,   100,
     101,   102,   103,   104,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,   105,   106,   107,   108,   109,     0,
       0,   216,   105,   106,   107,   108,   109,     0,     0,   224,
     105,   106,   107,   108,   109,     0,     0,   225,    97,    98,
      99,   100,   101,   102,   103,   104,    97,    98,    99,   100,
     101,   102,   103,   104,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,   105,   106,   107,   108,   109,     0,
       0,   226,   105,   106,   107,   108,   109,     0,     0,   227,
     105,   106,   107,   108,   109
};

static const yytype_int16 yycheck[] =
{
      18,     5,    20,     7,    22,     7,    24,    55,    56,    53,
      17,    18,    19,    20,    21,    22,    23,    24,    64,    50,
      51,    39,    17,    18,    19,    20,    21,    22,    23,    24,
      48,    49,     7,    51,    52,     7,    43,    44,    45,    46,
      47,     5,    88,     7,     3,     4,    53,     0,    43,    67,
      68,    69,    70,    12,    13,    73,    74,     3,     4,     3,
       4,     7,    80,    81,    48,    83,    12,    13,    12,    13,
       7,   115,    50,    51,    50,    51,    50,    51,    48,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     7,    17,    18,    19,    20,    21,    22,   117,
      24,   119,    52,   147,    52,    50,    51,    50,    51,    50,
      51,    50,    51,     7,   132,     7,   134,     7,   136,    43,
      17,    18,    19,    20,    21,    22,   144,    50,    51,    50,
     148,   149,   180,     6,     7,     8,    32,    33,    52,    52,
     188,    14,    15,    16,    52,    52,    43,    50,    48,    50,
       7,    50,    25,    28,    17,    18,    19,    20,    21,    22,
      23,    24,    53,    36,    53,   213,   184,    53,    53,    53,
       7,    44,    45,     7,    51,   193,     7,     7,    52,    52,
      43,    53,    55,    46,    47,    50,   204,   205,    50,   207,
     208,    37,    38,    39,    40,    41,    42,    50,    50,    27,
      51,    51,   250,   251,    51,    51,    51,     7,    48,    32,
     228,   229,   230,   231,     3,     4,   234,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    50,    37,
      38,    39,    40,    41,    42,     6,    25,    26,    49,    28,
      29,    30,    31,    51,    54,    34,    35,    36,    54,     6,
     237,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    48,
      49,    -1,    -1,    52,     3,     4,    55,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    -1,    -1,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    48,
      49,    -1,    -1,    52,     3,     4,    55,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    -1,    -1,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    48,
      49,    -1,    -1,    52,     3,     4,    55,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    -1,    -1,    34,    35,    36,    -1,     3,
       4,    -1,     6,     7,     8,    44,    45,    -1,    -1,    48,
      14,    15,    16,    52,    -1,    -1,    55,     6,     7,     8,
      -1,    25,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    -1,    36,    52,    -1,
      -1,    55,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    53,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    53,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    53,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    53,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,
      43,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    20,    21,    22,    23,    24,    17,    18,    19,    20,
      21,    22,    23,    24,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      -1,    50,    43,    44,    45,    46,    47,    -1,    -1,    50,
      43,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    20,    21,    22,    23,    24,    17,    18,    19,    20,
      21,    22,    23,    24,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      -1,    50,    43,    44,    45,    46,    47,    -1,    -1,    50,
      43,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    20,    21,    22,    23,    24,    17,    18,    19,    20,
      21,    22,    23,    24,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      -1,    50,    43,    44,    45,    46,    47,    -1,    -1,    50,
      43,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    20,    21,    22,    23,    24,    17,    18,    19,    20,
      21,    22,    23,    24,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      -1,    50,    43,    44,    45,    46,    47,    -1,    -1,    50,
      43,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    20,    21,    22,    23,    24,    17,    18,    19,    20,
      21,    22,    23,    24,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      -1,    50,    43,    44,    45,    46,    47,    -1,    -1,    50,
      43,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    20,    21,    22,    23,    24,    17,    18,    19,    20,
      21,    22,    23,    24,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      -1,    50,    43,    44,    45,    46,    47,    -1,    -1,    50,
      43,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    20,    21,    22,    23,    24,    17,    18,    19,    20,
      21,    22,    23,    24,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      -1,    50,    43,    44,    45,    46,    47,    -1,    -1,    50,
      43,    44,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    12,    13,    57,    59,    60,     5,     7,
       7,     7,     7,     0,     3,    60,    48,    50,    51,    50,
      51,    50,    51,    50,    51,     5,     3,     4,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    25,
      26,    28,    29,    30,    31,    34,    35,    36,    44,    45,
      48,    52,    55,    58,    61,    67,    68,    69,    74,     7,
      74,    74,    74,    74,    48,     7,     7,    37,    38,    39,
      40,    41,    42,    51,    52,    52,     7,     7,     7,    74,
      52,    52,    52,    52,    50,    50,    74,    74,    62,     3,
       4,    74,    74,    49,    69,    61,    61,    17,    18,    19,
      20,    21,    22,    23,    24,    43,    44,    45,    46,    47,
      50,    50,    50,    50,    50,    58,    50,    51,    50,    51,
      74,    74,    74,    74,    50,    50,    74,     7,    36,    74,
       7,    50,    51,    50,    51,    50,    51,    74,    74,     3,
       4,     7,    12,    13,    64,    66,    74,    58,    53,    53,
      53,    28,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    49,    74,    74,    50,    50,
      50,    50,    50,    53,    53,    53,    53,    74,    74,    74,
      53,    53,     7,     7,    51,     7,     7,    74,    53,    53,
      49,    74,    74,    52,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    61,    51,    51,    74,    51,    51,    50,
      61,    63,    74,    27,    74,    74,    50,    74,    74,     7,
      65,    48,    53,    61,    50,    50,    50,    50,    37,    38,
      39,    40,    41,    42,    51,    32,    70,    71,    72,    50,
      74,    74,    74,    74,    74,     6,    49,    33,    72,    73,
      54,    54,    61,    61
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
#line 197 "analisador.y"
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
#line 209 "analisador.y"
    {
    std::cout << "/* Compilador Faquir Rebuild */\n";
    std::cout << "#include <stdio.h>\n";
    std::cout << "#include <stdlib.h>\n";
    std::cout << "#include <string.h>\n";
    std::cout << "#include <math.h>\n";
    std::cout << "int main(void) {\n";

    for (const std::string& decl : declaracoes)
        std::cout << "    " << decl << "\n";

    std::cout << (yyvsp[(4) - (5)]).traducao;
    std::cout << "    return 0;\n";
    std::cout << "}\n";
;}
    break;

  case 5:
#line 228 "analisador.y"
    {
                   (yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;
               ;}
    break;

  case 8:
#line 238 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "int");
    (yyval).traducao = "";
;}
    break;

  case 9:
#line 242 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "int");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "int", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 10:
#line 250 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "float");
    (yyval).traducao = "";
;}
    break;

  case 11:
#line 254 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "float");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "float", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 12:
#line 261 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "char");
    (yyval).traducao = "";
;}
    break;

  case 13:
#line 265 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "char");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "char", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 14:
#line 272 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "boolean");
    (yyval).traducao = "";
;}
    break;

  case 15:
#line 276 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "boolean");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "boolean", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 16:
#line 286 "analisador.y"
    {
    tabela_simbolos.push_back({});  
;}
    break;

  case 17:
#line 288 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(3) - (4)]).traducao;
    tabela_simbolos.pop_back();     
;}
    break;

  case 18:
#line 294 "analisador.y"
    {
    std::string l_fim_switch = genlabel();
    pilha_controle.push_back({SWITCH, l_fim_switch, ""});
    (yyval).label = l_fim_switch;
;}
    break;

  case 19:
#line 302 "analisador.y"
    {
    std::string var_temp = get_temp((yyvsp[(1) - (4)]).label);
    std::string var_tipo = get_tipo((yyvsp[(1) - (4)]).label);
    std::string t = (yyvsp[(3) - (4)]).traducao + "    " + var_temp + " = " + (yyvsp[(3) - (4)]).label + ";\n";
    (yyval).traducao = t;
;}
    break;

  case 20:
#line 308 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "int");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "int", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 21:
#line 314 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "float");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "float", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 22:
#line 320 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "char");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "char", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 23:
#line 326 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "boolean");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "boolean", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 24:
#line 336 "analisador.y"
    {
    std::string var_temp = get_temp((yyvsp[(1) - (3)]).label);
    std::string var_tipo = get_tipo((yyvsp[(1) - (3)]).label);
    std::string t = (yyvsp[(3) - (3)]).traducao + "    " + var_temp + " = " + (yyvsp[(3) - (3)]).label + ";\n";
    (yyval).traducao = t;
;}
    break;

  case 25:
#line 342 "analisador.y"
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

  case 26:
#line 351 "analisador.y"
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

  case 27:
#line 360 "analisador.y"
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

  case 28:
#line 369 "analisador.y"
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

  case 29:
#line 379 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (2)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (2)]).label);
    std::string temp = gentemp(tipo);
    (yyval).traducao = "    " + temp + " = " + var + " + 1;\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 30:
#line 386 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (2)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (2)]).label);
    std::string temp = gentemp(tipo);
    (yyval).traducao = "    " + temp + " = " + var + " - 1;\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 31:
#line 396 "analisador.y"
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

  case 32:
#line 420 "analisador.y"
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

  case 33:
#line 441 "analisador.y"
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

  case 35:
#line 457 "analisador.y"
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

  case 36:
#line 475 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "int");
    (yyval).traducao = "";
;}
    break;

  case 37:
#line 480 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "float");
    (yyval).traducao = "";
;}
    break;

  case 38:
#line 485 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "char");
    (yyval).traducao = "";
;}
    break;

  case 39:
#line 490 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "boolean");
    (yyval).traducao = "";
;}
    break;

  case 40:
#line 495 "analisador.y"
    {
    declarar((yyvsp[(2) - (3)]).label, "string");
    std::ostringstream ss;
    ss << "    " << get_temp((yyvsp[(2) - (3)]).label) << " = (char*) malloc(100);\n";
    (yyval).traducao = ss.str();
;}
    break;

  case 41:
#line 504 "analisador.y"
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

  case 42:
#line 518 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "int");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "int", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 43:
#line 525 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "float");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "float", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 44:
#line 532 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "char");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "char", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 45:
#line 539 "analisador.y"
    {
    declarar((yyvsp[(2) - (5)]).label, "boolean");
    std::string temp = get_temp((yyvsp[(2) - (5)]).label);
    std::string cast = gerar_cast((yyvsp[(4) - (5)]).label, (yyvsp[(4) - (5)]).tipo, "boolean", (yyvsp[(4) - (5)]).traducao);
    (yyval).traducao = (yyvsp[(4) - (5)]).traducao + "    " + temp + " = " + cast + ";\n";
;}
    break;

  case 46:
#line 546 "analisador.y"
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

  case 47:
#line 556 "analisador.y"
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

  case 48:
#line 566 "analisador.y"
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

  case 49:
#line 576 "analisador.y"
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

  case 50:
#line 586 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (3)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (3)]).label);
    std::string temp = gentemp(tipo);
    (yyval).traducao = "    " + temp + " = " + var + " + 1;\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 51:
#line 594 "analisador.y"
    {
    std::string var = get_temp((yyvsp[(1) - (3)]).label);
    std::string tipo = get_tipo((yyvsp[(1) - (3)]).label);
    std::string temp = gentemp(tipo);
    (yyval).traducao = "    " + temp + " = " + var + " - 1;\n";
    (yyval).traducao += "    " + var + " = " + temp + ";\n";
;}
    break;

  case 52:
#line 605 "analisador.y"
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

  case 53:
#line 620 "analisador.y"
    {
    (yyval).traducao = "    printf(\"%s\\n\", \"" + (yyvsp[(3) - (5)]).label + "\");\n";
;}
    break;

  case 54:
#line 624 "analisador.y"
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

  case 55:
#line 639 "analisador.y"
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

  case 56:
#line 655 "analisador.y"
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

  case 57:
#line 669 "analisador.y"
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

  case 58:
#line 688 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (2)]).traducao;
    (yyval).traducao += (yyvsp[(2) - (2)]).traducao;
    (yyval).traducao += "    goto " + (yyvsp[(1) - (2)]).label + "; // repetir\n";
    (yyval).traducao += (yyvsp[(1) - (2)]).rotulo_break + ":\n";

    pilha_controle.pop_back();
;}
    break;

  case 59:
#line 697 "analisador.y"
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

  case 60:
#line 715 "analisador.y"
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

  case 61:
#line 725 "analisador.y"
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

  case 62:
#line 783 "analisador.y"
    {
    if (pilha_controle.empty()) {
        std::cerr << "Erro: 'break' fora de estrutura de controle.\n";
        exit(1);
    }
    (yyval).traducao = "    goto " + pilha_controle.back().rotulo_break + "; // break\n";
;}
    break;

  case 63:
#line 791 "analisador.y"
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

  case 64:
#line 809 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (1)]).traducao;
;}
    break;

  case 65:
#line 814 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (2)]).traducao;
;}
    break;

  case 66:
#line 819 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;
;}
    break;

  case 67:
#line 824 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (2)]).traducao + (yyvsp[(2) - (2)]).traducao;
;}
    break;

  case 68:
#line 827 "analisador.y"
    {
    (yyval).traducao = (yyvsp[(1) - (1)]).traducao;
;}
    break;

  case 69:
#line 832 "analisador.y"
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

  case 70:
#line 851 "analisador.y"
    {
    (yyval).traducao = "";
;}
    break;

  case 71:
#line 854 "analisador.y"
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

  case 72:
#line 872 "analisador.y"
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

  case 73:
#line 883 "analisador.y"
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

  case 74:
#line 894 "analisador.y"
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

  case 75:
#line 905 "analisador.y"
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

  case 76:
#line 916 "analisador.y"
    {
    std::string tipo_resultado = ((yyvsp[(1) - (3)]).tipo == "float" || (yyvsp[(3) - (3)]).tipo == "float") ? "float" : "int";
    std::string temp = gentemp(tipo_resultado);
    std::string traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    std::string a1 = gerar_cast((yyvsp[(1) - (3)]).label, (yyvsp[(1) - (3)]).tipo, "float", traducao);
    std::string a2 = gerar_cast((yyvsp[(3) - (3)]).label, (yyvsp[(3) - (3)]).tipo, "float", traducao);
    (yyval).label = temp;
    (yyval).tipo = tipo_resultado;
    (yyval).traducao = traducao + "    " + temp + " = pow(" + a1 + ", " + a2 + ");\n";
;}
    break;

  case 77:
#line 928 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " < " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 78:
#line 936 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " <= " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 79:
#line 944 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " > " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 80:
#line 952 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " >= " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 81:
#line 960 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " == " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 82:
#line 968 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " != " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 83:
#line 976 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " && " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 84:
#line 984 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(1) - (3)]).traducao + (yyvsp[(3) - (3)]).traducao;
    (yyval).traducao += "    " + t + " = " + (yyvsp[(1) - (3)]).label + " || " + (yyvsp[(3) - (3)]).label + ";\n";
;}
    break;

  case 85:
#line 992 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = (yyvsp[(2) - (2)]).traducao;
    (yyval).traducao += "    " + t + " = !" + (yyvsp[(2) - (2)]).label + ";\n";
;}
    break;

  case 86:
#line 1000 "analisador.y"
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

  case 87:
#line 1013 "analisador.y"
    {
    (yyval).label = (yyvsp[(2) - (2)]).label;
    (yyval).tipo = (yyvsp[(2) - (2)]).tipo;
    (yyval).traducao = (yyvsp[(2) - (2)]).traducao; // não altera o valor
;}
    break;

  case 88:
#line 1019 "analisador.y"
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

  case 89:
#line 1031 "analisador.y"
    {
    std::string t = gentemp("int");
    (yyval).label = t;
    (yyval).tipo = "int";
    (yyval).traducao = "    " + t + " = " + (yyvsp[(1) - (1)]).label + ";\n";
;}
    break;

  case 90:
#line 1038 "analisador.y"
    {
    std::string t = gentemp("float");
    (yyval).label = t;
    (yyval).tipo = "float";
    (yyval).traducao = "    " + t + " = " + (yyvsp[(1) - (1)]).label + ";\n";
;}
    break;

  case 91:
#line 1045 "analisador.y"
    {
    std::string t = get_temp((yyvsp[(1) - (1)]).label);
    (yyval).label = t;
    (yyval).tipo = get_tipo((yyvsp[(1) - (1)]).label);
    (yyval).traducao = "";
;}
    break;

  case 92:
#line 1052 "analisador.y"
    {
    std::string t = gentemp("boolean");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = "    " + t + " = 1;\n";
;}
    break;

  case 93:
#line 1059 "analisador.y"
    {
    std::string t = gentemp("boolean");
    (yyval).label = t;
    (yyval).tipo = "boolean";
    (yyval).traducao = "    " + t + " = 0;\n";
;}
    break;

  case 94:
#line 1067 "analisador.y"
    {
    std::string t = gentemp("char");
    (yyval).label = t;
    (yyval).tipo = "char";
    (yyval).traducao = "    " + t + " = " + (yyvsp[(1) - (1)]).label + ";\n";
;}
    break;

  case 95:
#line 1074 "analisador.y"
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

  case 96:
#line 1088 "analisador.y"
    {
    std::string cast = gentemp("int");

    (yyval).traducao = (yyvsp[(4) - (4)]).traducao;
    (yyval).traducao += "    " + cast + " = (int) " + (yyvsp[(4) - (4)]).label + ";\n";
    (yyval).label = cast;
    (yyval).tipo = "int";
;}
    break;

  case 97:
#line 1097 "analisador.y"
    {
    std::string cast = gentemp("float");

    (yyval).traducao = (yyvsp[(4) - (4)]).traducao;
    (yyval).traducao += "    " + cast + " = (float) " + (yyvsp[(4) - (4)]).label + ";\n";
    (yyval).label = cast;
    (yyval).tipo = "float";
;}
    break;

  case 98:
#line 1108 "analisador.y"
    {
    (yyval).label = (yyvsp[(2) - (3)]).label;
    (yyval).tipo = (yyvsp[(2) - (3)]).tipo;
    (yyval).traducao = (yyvsp[(2) - (3)]).traducao;
;}
    break;


/* Line 1267 of yacc.c.  */
#line 3044 "analisador.tab.c"
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


#line 1115 "analisador.y"


int main() {
    yydebug = 1;
    tabela_simbolos.push_back({});
    yyparse();
    return 0;
}















