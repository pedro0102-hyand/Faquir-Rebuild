%{
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
std::unordered_map<std::string, std::unordered_map<std::string, int>> enums;
std::unordered_map<std::string, std::string> constantes_enum;

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

void declarar(const std::string& nome, const std::string& tipo, bool constante = false) {
    if (tabela_simbolos.back().count(nome)) {
        std::cerr << "Erro: variável '" << nome << "' já declarada neste escopo.\n";
        exit(1);
    }
    std::string t = gentemp(tipo);
    Simbolo s{nome, tipo, t, escopo_atual, constante, false, profundidade_escopo};
    tabela_simbolos.back()[nome] = s;
}

std::string get_temp(const std::string& var) {
    for (int i = tabela_simbolos.size() - 1; i >= 0; --i)
        if (tabela_simbolos[i].count(var))
            return tabela_simbolos[i][var].temp;

    // Declaração implícita: assume int
    std::cerr << "Aviso: variável '" << var << "' não declarada. Será assumida como 'int'.\n";
    declarar(var, "int");
    return tabela_simbolos.back()[var].temp;
}

std::string get_tipo(const std::string& var) {
    for (int i = tabela_simbolos.size() - 1; i >= 0; --i)
        if (tabela_simbolos[i].count(var))
            return tabela_simbolos[i][var].tipo;

    // Declaração implícita: assume int
    std::cerr << "Aviso: variável '" << var << "' não declarada. Será assumida como 'int'.\n";
    declarar(var, "int");
    return "int";
}


Simbolo buscar_simbolo(const std::string& nome) {
    for (int i = tabela_simbolos.size() - 1; i >= 0; --i)
        if (tabela_simbolos[i].count(nome)) return tabela_simbolos[i][nome];
    std::cerr << "Erro: variável '" << nome << "' não declarada.\n";
    exit(1);
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
%}


%token TK_INT TK_FLOAT TK_MAIN TK_NUM TK_ID TK_FLOATNUM
%token TK_PRINT TK_READ TK_STRING
%token TK_CHAR TK_BOOLEAN TK_TRUE TK_FALSE TK_CHARLIT
%token TK_LT TK_LE TK_GT TK_GE TK_EQ TK_NE
%token TK_AND TK_OR TK_NOT
%token TK_IF TK_ELSE
%token TK_WHILE 
%token TK_DO
%token TK_FOR
%token TK_SWITCH TK_CASE TK_DEFAULT
%token TK_BREAK TK_CONTINUE TK_STRLIT TK_BREAKALL
%token TK_ADDEQ TK_SUBEQ TK_MULTEQ TK_DIVEQ
%token TK_INC TK_DEC
%token TK_POW
%token TK_VAR
%token TK_INTDIV TK_LSHIFT TK_RSHIFT
%token TK_EXIT
%token TK_CONST
%token TK_ENUM



%left '+' '-'
%left '*' '/'
%right TK_NOT
%left TK_AND
%left TK_OR
%right TK_POW
%left TK_LSHIFT TK_RSHIFT
%left TK_INTDIV '%'


%start S

%%

S : DECLS TK_INT TK_MAIN '{' LISTA_COMANDOS '}' {
    std::cout << "/* Compilador Faquir Rebuild */\n";
    std::cout << "#include <stdio.h>\n";
    std::cout << "int main(void) {\n";

    for (const std::string& decl : declaracoes)
        std::cout << "    " << decl << "\n";

    std::cout << $5.traducao;
    std::cout << "    return 0;\n";
    std::cout << "}\n";
}
| TK_INT TK_MAIN '{' LISTA_COMANDOS '}' {
    std::cout << "/* Compilador Faquir Rebuild */\n";
    std::cout << "#include <stdio.h>\n";
    std::cout << "#include <stdlib.h>\n";
    std::cout << "#include <string.h>\n";
    std::cout << "#include <math.h>\n";
    std::cout << "int main(void) {\n";

    for (const std::string& decl : declaracoes)
        std::cout << "    " << decl << "\n";

    std::cout << $4.traducao;
    std::cout << "    return 0;\n";
    std::cout << "}\n";
}
;


LISTA_COMANDOS : COMANDO
               | LISTA_COMANDOS COMANDO {
                   $$.traducao = $1.traducao + $2.traducao;
               }
;

DECLS : DECL
      | DECLS DECL
;

DECL:
      TK_INT TK_ID '=' E ';' {
        declarar($2.label, "int");
        std::string temp = get_temp($2.label);
        std::string cast = gerar_cast($4.label, $4.tipo, "int", $4.traducao);
        $$.traducao = $4.traducao + "    " + temp + " = " + cast + ";\n";
      }
    | TK_FLOAT TK_ID '=' E ';' {
        declarar($2.label, "float");
        std::string temp = get_temp($2.label);
        std::string cast = gerar_cast($4.label, $4.tipo, "float", $4.traducao);
        $$.traducao = $4.traducao + "    " + temp + " = " + cast + ";\n";
      }
    | TK_CHAR TK_ID '=' E ';' {
        declarar($2.label, "char");
        std::string temp = get_temp($2.label);
        std::string cast = gerar_cast($4.label, $4.tipo, "char", $4.traducao);
        $$.traducao = $4.traducao + "    " + temp + " = " + cast + ";\n";
      }
    | TK_BOOLEAN TK_ID '=' E ';' {
        declarar($2.label, "boolean");
        std::string temp = get_temp($2.label);
        std::string cast = gerar_cast($4.label, $4.tipo, "boolean", $4.traducao);
        $$.traducao = $4.traducao + "    " + temp + " = " + cast + ";\n";
      }

 
    | TK_CONST TK_INT TK_ID '=' E ';' {
        declarar($3.label, "int", true);
        std::string temp = get_temp($3.label);
        std::string cast = gerar_cast($5.label, $5.tipo, "int", $5.traducao);
        $$.traducao = $5.traducao + "    " + temp + " = " + cast + ";\n";
      }
    | TK_CONST TK_FLOAT TK_ID '=' E ';' {
        declarar($3.label, "float", true);
        std::string temp = get_temp($3.label);
        std::string cast = gerar_cast($5.label, $5.tipo, "float", $5.traducao);
        $$.traducao = $5.traducao + "    " + temp + " = " + cast + ";\n";
      }
    | TK_CONST TK_CHAR TK_ID '=' E ';' {
        declarar($3.label, "char", true);
        std::string temp = get_temp($3.label);
        std::string cast = gerar_cast($5.label, $5.tipo, "char", $5.traducao);
        $$.traducao = $5.traducao + "    " + temp + " = " + cast + ";\n";
      }
    | TK_CONST TK_BOOLEAN TK_ID '=' E ';' {
        declarar($3.label, "boolean", true);
        std::string temp = get_temp($3.label);
        std::string cast = gerar_cast($5.label, $5.tipo, "boolean", $5.traducao);
        $$.traducao = $5.traducao + "    " + temp + " = " + cast + ";\n";
      }
    | TK_ENUM TK_ID '{' LISTA_ENUM '}' ';' {
    // Apenas registramos os enums internamente, não geramos código
}

;

LISTA_ENUM
    : TK_ID {
        enums[$0.label][$1.label] = 0;
        constantes_enum[$1.label] = $0.label;
        $$.label = $0.label;
    }
    | LISTA_ENUM ',' TK_ID {
        std::string enum_nome = $1.label;
        int valor = enums[enum_nome].size();
        enums[enum_nome][$3.label] = valor;
        constantes_enum[$3.label] = enum_nome;
        $$.label = enum_nome;
    }
;


BLOCO : '{' {
    tabela_simbolos.push_back({});  
} LISTA_COMANDOS '}' {
    $$.traducao = $3.traducao;
    tabela_simbolos.pop_back();     
}
;

SWITCH_INIT : {
    std::string l_fim_switch = genlabel();
    pilha_controle.push_back({SWITCH, l_fim_switch, ""});
    $$.label = l_fim_switch;
};


INIT
: TK_ID '=' E ';' {
    std::string var_temp = get_temp($1.label);
    std::string var_tipo = get_tipo($1.label);
    std::string t = $3.traducao + "    " + var_temp + " = " + $3.label + ";\n";
    $$.traducao = t;
}
| TK_INT TK_ID '=' E ';' {
    declarar($2.label, "int");
    std::string temp = get_temp($2.label);
    std::string cast = gerar_cast($4.label, $4.tipo, "int", $4.traducao);
    $$.traducao = $4.traducao + "    " + temp + " = " + cast + ";\n";
}
| TK_FLOAT TK_ID '=' E ';' {
    declarar($2.label, "float");
    std::string temp = get_temp($2.label);
    std::string cast = gerar_cast($4.label, $4.tipo, "float", $4.traducao);
    $$.traducao = $4.traducao + "    " + temp + " = " + cast + ";\n";
}
| TK_CHAR TK_ID '=' E ';' {
    declarar($2.label, "char");
    std::string temp = get_temp($2.label);
    std::string cast = gerar_cast($4.label, $4.tipo, "char", $4.traducao);
    $$.traducao = $4.traducao + "    " + temp + " = " + cast + ";\n";
}
| TK_BOOLEAN TK_ID '=' E ';' {
    declarar($2.label, "boolean");
    std::string temp = get_temp($2.label);
    std::string cast = gerar_cast($4.label, $4.tipo, "boolean", $4.traducao);
    $$.traducao = $4.traducao + "    " + temp + " = " + cast + ";\n";
}
;


INCR 
: TK_ID '=' E {
    std::string var_temp = get_temp($1.label);
    std::string var_tipo = get_tipo($1.label);
    std::string t = $3.traducao + "    " + var_temp + " = " + $3.label + ";\n";
    $$.traducao = t;
}
| TK_ID TK_ADDEQ E {
    std::string var = get_temp($1.label);
    std::string tipo = get_tipo($1.label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast($3.label, $3.tipo, tipo, $3.traducao);
    $$.traducao = $3.traducao;
    $$.traducao += "    " + temp + " = " + var + " + " + cast + ";\n";
    $$.traducao += "    " + var + " = " + temp + ";\n";
}
| TK_ID TK_SUBEQ E {
    std::string var = get_temp($1.label);
    std::string tipo = get_tipo($1.label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast($3.label, $3.tipo, tipo, $3.traducao);
    $$.traducao = $3.traducao;
    $$.traducao += "    " + temp + " = " + var + " - " + cast + ";\n";
    $$.traducao += "    " + var + " = " + temp + ";\n";
}
| TK_ID TK_MULTEQ E {
    std::string var = get_temp($1.label);
    std::string tipo = get_tipo($1.label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast($3.label, $3.tipo, tipo, $3.traducao);
    $$.traducao = $3.traducao;
    $$.traducao += "    " + temp + " = " + var + " * " + cast + ";\n";
    $$.traducao += "    " + var + " = " + temp + ";\n";
}
| TK_ID TK_DIVEQ E {
    std::string var = get_temp($1.label);
    std::string tipo = get_tipo($1.label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast($3.label, $3.tipo, tipo, $3.traducao);
    $$.traducao = $3.traducao;
    $$.traducao += "    " + temp + " = " + var + " / " + cast + ";\n";
    $$.traducao += "    " + var + " = " + temp + ";\n";
}

| TK_ID TK_INC {
    std::string var = get_temp($1.label);
    std::string tipo = get_tipo($1.label);
    std::string temp = gentemp(tipo);
    $$.traducao = "    " + temp + " = " + var + " + 1;\n";
    $$.traducao += "    " + var + " = " + temp + ";\n";
}
| TK_ID TK_DEC {
    std::string var = get_temp($1.label);
    std::string tipo = get_tipo($1.label);
    std::string temp = gentemp(tipo);
    $$.traducao = "    " + temp + " = " + var + " - 1;\n";
    $$.traducao += "    " + var + " = " + temp + ";\n";
}



FOR_INIT : INIT E ';' INCR {
    if ($2.tipo != "boolean") {
        std::cerr << "Erro: condição do 'for' deve ser booleana, mas é '" << $2.tipo << "'\n";
        exit(1);
    }

    std::string l_inicio = genlabel();       // Início do laço
    std::string l_continue = genlabel();     // Rótulo de continue (vai para incremento)
    std::string l_fim = genlabel();          // Saída do laço

    pilha_controle.push_back({LOOP, l_fim, l_continue});

    $$.traducao = $1.traducao;  // INIT
    $$.traducao += l_inicio + ":\n";
    $$.traducao += $2.traducao;
    $$.traducao += "    if (!" + $2.label + ") goto " + l_fim + "; // condição falsa\n";

    // salvar rótulos para a regra principal
    $$.label = l_inicio;
    $$.rotulo_break = l_fim;
    $$.rotulo_continue = l_continue;
    $$.incr = $4.traducao;
}

WHILE_INIT : TK_WHILE '(' E ')' {
    if ($3.tipo != "boolean") {
        std::cerr << "Erro: condição do 'while' deve ser booleana, mas é '" << $3.tipo << "'\n";
        exit(1);
    }

    std::string l_inicio = genlabel();     // início do loop
    std::string l_fim = genlabel();        // saída do loop

    // Empilha antes do corpo ser processado
    pilha_controle.push_back({LOOP, l_fim, l_inicio});

    $$.label = l_inicio;
    $$.rotulo_break = l_fim;
    $$.rotulo_continue = l_inicio;  // no while, continue volta pro teste

    $$.traducao = l_inicio + ":\n";
    $$.traducao += $3.traducao;
    $$.traducao += "    if (!" + $3.label + ") goto " + l_fim + "; // condição falsa\n";
}

DO_INIT : TK_DO {
    std::string l_inicio = genlabel();  // início do bloco
    std::string l_cond = genlabel();    // ponto da condição
    std::string l_fim = genlabel();     // saída do laço

    pilha_controle.push_back({LOOP, l_fim, l_cond});

    $$.label = l_inicio;
    $$.rotulo_continue = l_cond;
    $$.rotulo_break = l_fim;

    $$.traducao = l_inicio + ":\n";  // começa o corpo aqui
}



COMANDO : | TK_ID '=' E ';' {
    Simbolo s = buscar_simbolo($1.label);
    if (s.constante) {
        std::cerr << "Erro: tentativa de atribuir valor à constante '" << $1.label << "'.\n";
        exit(1);
    }

    std::string var_temp = get_temp($1.label);
    std::string var_tipo = get_tipo($1.label);
    std::ostringstream ss;

    ss << $3.traducao;

    if (var_tipo == "string") {
        ss << "    " << var_temp << " = (char*) malloc(strlen(" << $3.label << ") + 1);\n";
        ss << "    strcpy(" << var_temp << ", " << $3.label << ");\n";
    } else {
        ss << "    " << var_temp << " = " << $3.label << ";\n";
    }

    $$.traducao = ss.str();
}



| TK_INT TK_ID ';' {
    declarar($2.label, "int");
    $$.traducao = "";
}

| TK_FLOAT TK_ID ';' {
    declarar($2.label, "float");
    $$.traducao = "";
}

| TK_CHAR TK_ID ';' {
    declarar($2.label, "char");
    $$.traducao = "";
}

| TK_BOOLEAN TK_ID ';' {
    declarar($2.label, "boolean");
    $$.traducao = "";
}

| TK_STRING TK_ID ';' {
    declarar($2.label, "string");
    std::ostringstream ss;
    ss << "    " << get_temp($2.label) << " = (char*) malloc(100);\n";
    $$.traducao = ss.str();
}

| TK_ID TK_ID ';' {
    if (!enums.count($1.label)) {
        std::cerr << "Erro: tipo enum '" << $1.label << "' não declarado.\n";
        exit(1);
    }
    declarar($2.label, "int");  // enums são armazenados como inteiros
    $$.traducao = "";
}


| TK_STRING TK_ID '=' E ';' {
    declarar($2.label, "string");
    std::string temp = get_temp($2.label);
    std::ostringstream ss;

    ss << $4.traducao;

    ss << "    " << temp << " = (char*) malloc(strlen(" << $4.label << ") + 1);\n";
    ss << "    strcpy(" << temp << ", " << $4.label << ");\n";

    $$.traducao = ss.str();
}


| TK_INT TK_ID '=' E ';' {
    declarar($2.label, "int");
    std::string temp = get_temp($2.label);
    std::string cast = gerar_cast($4.label, $4.tipo, "int", $4.traducao);
    $$.traducao = $4.traducao + "    " + temp + " = " + cast + ";\n";
}

| TK_FLOAT TK_ID '=' E ';' {
    declarar($2.label, "float");
    std::string temp = get_temp($2.label);
    std::string cast = gerar_cast($4.label, $4.tipo, "float", $4.traducao);
    $$.traducao = $4.traducao + "    " + temp + " = " + cast + ";\n";
}

| TK_CHAR TK_ID '=' E ';' {
    declarar($2.label, "char");
    std::string temp = get_temp($2.label);
    std::string cast = gerar_cast($4.label, $4.tipo, "char", $4.traducao);
    $$.traducao = $4.traducao + "    " + temp + " = " + cast + ";\n";
}

| TK_BOOLEAN TK_ID '=' E ';' {
    declarar($2.label, "boolean");
    std::string temp = get_temp($2.label);
    std::string cast = gerar_cast($4.label, $4.tipo, "boolean", $4.traducao);
    $$.traducao = $4.traducao + "    " + temp + " = " + cast + ";\n";
}

  | TK_CONST TK_INT TK_ID '=' E ';' {
      declarar($3.label, "int", true);
      std::string temp = get_temp($3.label);
      std::string cast = gerar_cast($5.label, $5.tipo, "int", $5.traducao);
      $$.traducao = $5.traducao + "    " + temp + " = " + cast + ";\n";
  }
  | TK_CONST TK_FLOAT TK_ID '=' E ';' {
      declarar($3.label, "float", true);
      std::string temp = get_temp($3.label);
      std::string cast = gerar_cast($5.label, $5.tipo, "float", $5.traducao);
      $$.traducao = $5.traducao + "    " + temp + " = " + cast + ";\n";
  }
  | TK_CONST TK_CHAR TK_ID '=' E ';' {
      declarar($3.label, "char", true);
      std::string temp = get_temp($3.label);
      std::string cast = gerar_cast($5.label, $5.tipo, "char", $5.traducao);
      $$.traducao = $5.traducao + "    " + temp + " = " + cast + ";\n";
  }
  | TK_CONST TK_BOOLEAN TK_ID '=' E ';' {
      declarar($3.label, "boolean", true);
      std::string temp = get_temp($3.label);
      std::string cast = gerar_cast($5.label, $5.tipo, "boolean", $5.traducao);
      $$.traducao = $5.traducao + "    " + temp + " = " + cast + ";\n";
  }


| TK_ID TK_ADDEQ E ';' {
    std::string var = get_temp($1.label);
    std::string tipo = get_tipo($1.label);

    if (tipo == "string" && $3.tipo == "string") {
        $$.traducao = $3.traducao;
        $$.traducao += "    " + var + " = (char*) realloc(" + var + ", strlen(" + var + ") + strlen(" + $3.label + ") + 1);\n";
        $$.traducao += "    strcat(" + var + ", " + $3.label + ");\n";
    } else {
        std::string temp = gentemp(tipo);
        std::string cast = gerar_cast($3.label, $3.tipo, tipo, $3.traducao);
        $$.traducao = $3.traducao;
        $$.traducao += "    " + temp + " = " + var + " + " + cast + ";\n";
        $$.traducao += "    " + var + " = " + temp + ";\n";
    }
}


| TK_ID TK_SUBEQ E ';' {
    std::string var = get_temp($1.label);
    std::string tipo = get_tipo($1.label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast($3.label, $3.tipo, tipo, $3.traducao);
    $$.traducao = $3.traducao;
    $$.traducao += "    " + temp + " = " + var + " - " + cast + ";\n";
    $$.traducao += "    " + var + " = " + temp + ";\n";
}

| TK_ID TK_MULTEQ E ';' {
    std::string var = get_temp($1.label);
    std::string tipo = get_tipo($1.label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast($3.label, $3.tipo, tipo, $3.traducao);
    $$.traducao = $3.traducao;
    $$.traducao += "    " + temp + " = " + var + " * " + cast + ";\n";
    $$.traducao += "    " + var + " = " + temp + ";\n";
}

| TK_ID TK_DIVEQ E ';' {
    std::string var = get_temp($1.label);
    std::string tipo = get_tipo($1.label);
    std::string temp = gentemp(tipo);
    std::string cast = gerar_cast($3.label, $3.tipo, tipo, $3.traducao);
    $$.traducao = $3.traducao;
    $$.traducao += "    " + temp + " = " + var + " / " + cast + ";\n";
    $$.traducao += "    " + var + " = " + temp + ";\n";
}

| TK_ID TK_INC ';' {
    std::string var = get_temp($1.label);
    std::string tipo = get_tipo($1.label);
    std::string temp = gentemp(tipo);
    $$.traducao = "    " + temp + " = " + var + " + 1;\n";
    $$.traducao += "    " + var + " = " + temp + ";\n";
}

| TK_ID TK_DEC ';' {
    std::string var = get_temp($1.label);
    std::string tipo = get_tipo($1.label);
    std::string temp = gentemp(tipo);
    $$.traducao = "    " + temp + " = " + var + " - 1;\n";
    $$.traducao += "    " + var + " = " + temp + ";\n";
}

| TK_PRINT '(' TK_ID ')' ';' {
    std::string temp = get_temp($3.label);
    std::string tipo = get_tipo($3.label);
    std::string fmt;

    if (tipo == "int") fmt = "%d";
    else if (tipo == "float") fmt = "%f";
    else if (tipo == "char") fmt = "%c";
    else if (tipo == "string") fmt = "%s";
    else if (tipo == "boolean") fmt = "%d"; 
    else fmt = "??";

    $$.traducao = "    printf(\"" + fmt + "\\n\", " + temp + ");\n";
}

| TK_PRINT '(' TK_STRLIT ')' ';' {
    $$.traducao = "    printf(\"%s\\n\", \"" + $3.label + "\");\n";
}

| TK_PRINT '(' E ')' ';' {
    std::string fmt;
    if ($3.tipo == "int") fmt = "%d";
    else if ($3.tipo == "float") fmt = "%f";
    else if ($3.tipo == "char") fmt = "%c";
    else if ($3.tipo == "boolean") fmt = "%d";
    else if ($3.tipo == "string") fmt = "%s";
    else fmt = "??";

    $$.traducao = $3.traducao;
    $$.traducao += "    printf(\"" + fmt + "\\n\", " + $3.label + ");\n";
}



| TK_READ '(' TK_ID ')' ';' {
    std::string temp = get_temp($3.label);
    std::string tipo = get_tipo($3.label);
    std::string fmt;

    if (tipo == "int") fmt = "%d";
    else if (tipo == "float") fmt = "%f";
    else if (tipo == "char") fmt = " %c";
    else if (tipo == "string") fmt = "%s";
    else fmt = "??";

    std::string ref = (tipo == "string") ? temp : "&" + temp;

    $$.traducao = "    scanf(\"" + fmt + "\", " + ref + ");\n";
}

| TK_IF '(' E ')' BLOCO {
    if ($3.tipo != "boolean") {
        std::cerr << "Erro: condição do 'if' deve ser booleana, mas é '" << $3.tipo << "'\n";
        exit(1);
    }

    std::string l_fim = "L" + std::to_string(++temp_count);

    $$.traducao = $3.traducao;
    $$.traducao += "    if (!" + $3.label + ") goto " + l_fim + "; // if condicional falsa\n";
    $$.traducao += $5.traducao;
    $$.traducao += l_fim + ":\n";
}

| TK_IF '(' E ')' BLOCO TK_ELSE BLOCO {
    if ($3.tipo != "boolean") {
        std::cerr << "Erro: condição do 'if' deve ser booleana, mas é '" << $3.tipo << "'\n";
        exit(1);
    }

    std::string l_else = "L" + std::to_string(++temp_count);
    std::string l_fim  = "L" + std::to_string(++temp_count);

    $$.traducao = $3.traducao;
    $$.traducao += "    if (!" + $3.label + ") goto " + l_else + "; // if condicional falsa\n";
    $$.traducao += $5.traducao;
    $$.traducao += "    goto " + l_fim + "; // fim do if\n";
    $$.traducao += l_else + ":\n";
    $$.traducao += $7.traducao;
    $$.traducao += l_fim + ":\n";
}


| WHILE_INIT BLOCO {
    $$.traducao = $1.traducao;
    $$.traducao += $2.traducao;
    $$.traducao += "    goto " + $1.label + "; // repetir\n";
    $$.traducao += $1.rotulo_break + ":\n";

    pilha_controle.pop_back();
}

| DO_INIT BLOCO TK_WHILE '(' E ')' ';' {
    if ($5.tipo != "boolean") {
        std::cerr << "Erro: condição do 'do-while' deve ser booleana, mas é '" << $5.tipo << "'\n";
        exit(1);
    }

    $$.traducao = $1.traducao;          // label início
    $$.traducao += $2.traducao;         // corpo do do
    $$.traducao += $1.rotulo_continue + ":\n";  // ponto de continue
    $$.traducao += $5.traducao;
    $$.traducao += "    if (" + $5.label + ") goto " + $1.label + "; // repetir\n";
    $$.traducao += $1.rotulo_break + ":\n";  // fim do laço

    pilha_controle.pop_back();  // saiu do laço
}


| TK_FOR '(' FOR_INIT ')' BLOCO {
    $$.traducao = $3.traducao;
    $$.traducao += $5.traducao;                  // corpo do laço
    $$.traducao += $3.rotulo_continue + ":\n";   // continue salta para cá
    $$.traducao += $3.incr;                      // incremento
    $$.traducao += "    goto " + $3.label + ";\n"; // volta pro início
    $$.traducao += $3.rotulo_break + ":\n";      // fim do laço
    pilha_controle.pop_back();
}

| TK_SWITCH '(' E ')' SWITCH_INIT '{' CASOS '}' {
    if ($3.tipo != "int") {
        std::cerr << "Erro: expressão do 'switch' deve ser do tipo int, mas é '" << $3.tipo << "'\n";
        exit(1);
    }

    // Nome único da variável temporária do switch
    std::string switch_var = "__switch_var" + std::to_string(++temp_count);
    declaracoes.push_back("int " + switch_var + ";");

    // Começa com a tradução da expressão
    std::string codigo = $3.traducao;
    codigo += "    " + switch_var + " = " + $3.label + "; // guarda valor do switch\n";

    // Divide a tradução dos casos entre ifs e blocos
    std::string casos_if;
    std::string blocos_label;

    std::stringstream ss($7.traducao);
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
    std::string l_fim_switch = $5.label;
    pilha_controle.pop_back();

    $$.traducao = codigo + casos_if + blocos_label + l_fim_switch + ":\n";
}


| TK_BREAK ';' {
    if (pilha_controle.empty()) {
        std::cerr << "Erro: 'break' fora de estrutura de controle.\n";
        exit(1);
    }
    $$.traducao = "    goto " + pilha_controle.back().rotulo_break + "; // break\n";
}

| TK_BREAKALL ';' {
    if (pilha_controle.empty()) {
        std::cerr << "Erro: 'break all' fora de laço.\n";
        exit(1);
    }

    std::string rotulo_externo = "";

    for (int i = 0; i < pilha_controle.size(); ++i) {
        if (pilha_controle[i].tipo == LOOP) {
            rotulo_externo = pilha_controle[i].rotulo_break;
            break;
        }
    }

    if (rotulo_externo == "") {
        std::cerr << "Erro: nenhum laço externo encontrado para 'break all'.\n";
        exit(1);
    }

    $$.traducao = "    goto " + rotulo_externo + "; // break all\n";
}


| TK_CONTINUE ';' {
    bool encontrou = false;
    for (int i = pilha_controle.size() - 1; i >= 0; --i) {
        if (pilha_controle[i].tipo == LOOP) {
            $$.traducao = "    goto " + pilha_controle[i].rotulo_continue + "; // continue\n";
            encontrou = true;
            break;
        }
    }
    if (!encontrou) {
        std::cerr << "Erro: 'continue' fora de laço.\n";
        exit(1);
    }
}

| TK_VAR TK_ID '=' E ';' {
    // Inferir tipo a partir da expressão
    std::string tipo_inferido = $4.tipo;
    declarar($2.label, tipo_inferido);  // declara a variável com o tipo deduzido
    std::string temp = get_temp($2.label);
    std::string cast = gerar_cast($4.label, $4.tipo, tipo_inferido, $4.traducao);
    $$.traducao = $4.traducao + "    " + temp + " = " + cast + ";\n";
}

| TK_EXIT ';' {
    $$.traducao = "    exit(0);\n";
}


| BLOCO {
    $$.traducao = $1.traducao;
}


| E ';' {
    $$.traducao = $1.traducao;
}
;

CASOS : LISTA_CASE DEFAULT_OPCIONAL {
    $$.traducao = $1.traducao + $2.traducao;
}
;

LISTA_CASE : LISTA_CASE CASE {
    $$.traducao = $1.traducao + $2.traducao;
}
| CASE {
    $$.traducao = $1.traducao;
}
;

CASE : TK_CASE TK_NUM ':' BLOCO {
    std::string l_case = genlabel();
    std::string l_fim;

    if (!pilha_controle.empty() && pilha_controle.back().tipo == SWITCH)
        l_fim = pilha_controle.back().rotulo_break;
    else {
        std::cerr << "Erro interno: 'case' fora de contexto de switch.\n";
        exit(1);
    }

    $$.traducao = "    if (__switch_var == " + $2.label + ") goto " + l_case + ";\n";
    $$.traducao += l_case + ":\n" + $4.traducao;
    $$.traducao += "    goto " + l_fim + "; // break implícito no case\n";
}


;

DEFAULT_OPCIONAL : /* vazio */ {
    $$.traducao = "";
}
| TK_DEFAULT ':' BLOCO {
    std::string l_fim;

    if (!pilha_controle.empty() && pilha_controle.back().tipo == SWITCH)
        l_fim = pilha_controle.back().rotulo_break;
    else {
        std::cerr << "Erro interno: 'default' fora de contexto de switch.\n";
        exit(1);
    }

    $$.traducao = "Ldefault:\n" + $3.traducao;
    $$.traducao += "    goto " + l_fim + "; // break após default\n";
}


;


E : E '+' E {
    if ($1.tipo == "string" && $3.tipo == "string") {
        std::string temp = gentemp("string");
        $$.label = temp;
        $$.tipo = "string";

        $$.traducao = $1.traducao + $3.traducao;
        $$.traducao += "    " + temp + " = (char*) malloc(strlen(" + $1.label + ") + strlen(" + $3.label + ") + 1);\n";
        $$.traducao += "    strcpy(" + temp + ", " + $1.label + ");\n";
        $$.traducao += "    strcat(" + temp + ", " + $3.label + ");\n";
    } else {
        std::string tipo_resultado = ($1.tipo == "float" || $3.tipo == "float") ? "float" : "int";
        std::string t = gentemp(tipo_resultado);
        std::string traducao = $1.traducao + $3.traducao;
        std::string a1 = gerar_cast($1.label, $1.tipo, tipo_resultado, traducao);
        std::string a2 = gerar_cast($3.label, $3.tipo, tipo_resultado, traducao);
        $$.label = t;
        $$.tipo = tipo_resultado;
        $$.traducao = traducao + "    " + t + " = " + a1 + " + " + a2 + ";\n";
    }
}


| E '-' E {
    std::string tipo_resultado = ($1.tipo == "float" || $3.tipo == "float") ? "float" : "int";
    std::string t = gentemp(tipo_resultado);
    std::string traducao = $1.traducao + $3.traducao;
    std::string a1 = gerar_cast($1.label, $1.tipo, tipo_resultado, traducao);
    std::string a2 = gerar_cast($3.label, $3.tipo, tipo_resultado, traducao);
    $$.label = t;
    $$.tipo = tipo_resultado;
    $$.traducao = traducao + "    " + t + " = " + a1 + " - " + a2 + ";\n";
}

| E '*' E {
    std::string tipo_resultado = ($1.tipo == "float" || $3.tipo == "float") ? "float" : "int";
    std::string t = gentemp(tipo_resultado);
    std::string traducao = $1.traducao + $3.traducao;
    std::string a1 = gerar_cast($1.label, $1.tipo, tipo_resultado, traducao);
    std::string a2 = gerar_cast($3.label, $3.tipo, tipo_resultado, traducao);
    $$.label = t;
    $$.tipo = tipo_resultado;
    $$.traducao = traducao + "    " + t + " = " + a1 + " * " + a2 + ";\n";
}

| E '/' E {
    std::string tipo_resultado = ($1.tipo == "float" || $3.tipo == "float") ? "float" : "int";
    std::string t = gentemp(tipo_resultado);
    std::string traducao = $1.traducao + $3.traducao;
    std::string a1 = gerar_cast($1.label, $1.tipo, tipo_resultado, traducao);
    std::string a2 = gerar_cast($3.label, $3.tipo, tipo_resultado, traducao);
    $$.label = t;
    $$.tipo = tipo_resultado;
    $$.traducao = traducao + "    " + t + " = " + a1 + " / " + a2 + ";\n";
}

| E TK_POW E {
    std::string tipo_resultado = ($1.tipo == "float" || $3.tipo == "float") ? "float" : "int";
    std::string temp = gentemp(tipo_resultado);
    std::string traducao = $1.traducao + $3.traducao;
    std::string a1 = gerar_cast($1.label, $1.tipo, "float", traducao);
    std::string a2 = gerar_cast($3.label, $3.tipo, "float", traducao);
    $$.label = temp;
    $$.tipo = tipo_resultado;
    $$.traducao = traducao + "    " + temp + " = pow(" + a1 + ", " + a2 + ");\n";
}


| E TK_LT E {
    std::string t = gentemp("int");
    $$.label = t;
    $$.tipo = "boolean";
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " < " + $3.label + ";\n";
}

| E TK_LE E {
    std::string t = gentemp("int");
    $$.label = t;
    $$.tipo = "boolean";
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " <= " + $3.label + ";\n";
}

| E TK_GT E {
    std::string t = gentemp("int");
    $$.label = t;
    $$.tipo = "boolean";
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " > " + $3.label + ";\n";
}

| E TK_GE E {
    std::string t = gentemp("int");
    $$.label = t;
    $$.tipo = "boolean";
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " >= " + $3.label + ";\n";
}

| E TK_EQ E {
    std::string t = gentemp("int");
    $$.label = t;
    $$.tipo = "boolean";
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " == " + $3.label + ";\n";
}

| E TK_NE E {
    std::string t = gentemp("int");
    $$.label = t;
    $$.tipo = "boolean";
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " != " + $3.label + ";\n";
}

| E TK_AND E {
    std::string t = gentemp("int");
    $$.label = t;
    $$.tipo = "boolean";
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " && " + $3.label + ";\n";
}

| E TK_OR E {
    std::string t = gentemp("int");
    $$.label = t;
    $$.tipo = "boolean";
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " || " + $3.label + ";\n";
}

| TK_NOT E {
    std::string t = gentemp("int");
    $$.label = t;
    $$.tipo = "boolean";
    $$.traducao = $2.traducao;
    $$.traducao += "    " + t + " = !" + $2.label + ";\n";
}

| '-' E {
    std::string tipo = $2.tipo;
    if (tipo != "int" && tipo != "float") {
        std::cerr << "Erro: operador unário '-' só pode ser aplicado a int ou float (não a '" << tipo << "')\n";
        exit(1);
    }
    std::string temp = gentemp(tipo);
    $$.label = temp;
    $$.tipo = tipo;
    $$.traducao = $2.traducao;
    $$.traducao += "    " + temp + " = -" + $2.label + ";\n";
}

| '+' E {
    $$.label = $2.label;
    $$.tipo = $2.tipo;
    $$.traducao = $2.traducao; // não altera o valor
}

| '~' E {
    if ($2.tipo != "int") {
        std::cerr << "Erro: operador '~' só pode ser aplicado a inteiros.\n";
        exit(1);
    }
    std::string t = gentemp("int");
    $$.label = t;
    $$.tipo = "int";
    $$.traducao = $2.traducao + "    " + t + " = ~" + $2.label + ";\n";
}

| E '%' E {
    if ($1.tipo != "int" || $3.tipo != "int") {
        std::cerr << "Erro: '%' só funciona com int\n"; exit(1);
    }
    std::string t = gentemp("int");
    $$.label = t; $$.tipo = "int";
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " % " + $3.label + ";\n";
}

| E TK_INTDIV E {
    if ($1.tipo != "int" || $3.tipo != "int") {
        std::cerr << "Erro: '//' só funciona com int\n"; exit(1);
    }
    std::string t = gentemp("int");
    $$.label = t; $$.tipo = "int";
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " / " + $3.label + ";\n";
}

| TK_ID '(' E ')' {
    std::string func = $1.label;
    std::string temp;

    if (func == "sqrt" || func == "log" || func == "sin") {
        if ($3.tipo != "float" && $3.tipo != "int") {
            std::cerr << "Erro: função '" << func << "' espera float\n"; exit(1);
        }

        temp = gentemp("float");
        std::string arg = gerar_cast($3.label, $3.tipo, "float", $3.traducao);
        $$.traducao = $3.traducao;
        $$.traducao += "    " + temp + " = " + func + "(" + arg + ");\n";
        $$.label = temp;
        $$.tipo = "float";
    } else {
        std::cerr << "Erro: função desconhecida '" << func << "'\n"; exit(1);
    }
}

| TK_ID '(' E ',' E ')' {
    std::string func = $1.label;

    if (($3.tipo != $5.tipo) || ($3.tipo != "int" && $3.tipo != "float")) {
        std::cerr << "Erro: 'min' e 'max' precisam de dois args do mesmo tipo numérico\n"; exit(1);
    }

    std::string t = gentemp($3.tipo);
    std::string a = $3.label;
    std::string b = $5.label;

    $$.traducao = $3.traducao + $5.traducao;

    if (func == "min") {
        $$.traducao += "    if (" + a + " < " + b + ") " + t + " = " + a + "; else " + t + " = " + b + ";\n";
    } else if (func == "max") {
        $$.traducao += "    if (" + a + " > " + b + ") " + t + " = " + a + "; else " + t + " = " + b + ";\n";
    } else {
        std::cerr << "Erro: função '" << func << "' não suportada\n"; exit(1);
    }

    $$.label = t;
    $$.tipo = $3.tipo;
}

| E TK_LSHIFT E {
    if ($1.tipo != "int" || $3.tipo != "int") {
        std::cerr << "Erro: '<<' espera inteiros\n"; exit(1);
    }
    std::string t = gentemp("int");
    $$.label = t; $$.tipo = "int";
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " << " + $3.label + ";\n";
}

| E TK_RSHIFT E {
    if ($1.tipo != "int" || $3.tipo != "int") {
        std::cerr << "Erro: '>>' espera inteiros\n"; exit(1);
    }
    std::string t = gentemp("int");
    $$.label = t; $$.tipo = "int";
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " >> " + $3.label + ";\n";
}


| TK_NUM {
    std::string t = gentemp("int");
    $$.label = t;
    $$.tipo = "int";
    $$.traducao = "    " + t + " = " + $1.label + ";\n";
}

| TK_FLOATNUM {
    std::string t = gentemp("float");
    $$.label = t;
    $$.tipo = "float";
    $$.traducao = "    " + t + " = " + $1.label + ";\n";
}

| TK_ID {
    if (constantes_enum.count($1.label)) {
        std::string nome_enum = constantes_enum[$1.label];
        int valor = enums[nome_enum][$1.label];

        std::string t = gentemp("int");
        $$.label = t;
        $$.tipo = "int";
        $$.traducao = "    " + t + " = " + std::to_string(valor) + ";\n";
    } else {
        std::string t = get_temp($1.label);
        $$.label = t;
        $$.tipo = get_tipo($1.label);
        $$.traducao = "";
    }
}


| TK_TRUE {
    std::string t = gentemp("boolean");
    $$.label = t;
    $$.tipo = "boolean";
    $$.traducao = "    " + t + " = 1;\n";
}

| TK_FALSE {
    std::string t = gentemp("boolean");
    $$.label = t;
    $$.tipo = "boolean";
    $$.traducao = "    " + t + " = 0;\n";
}


| TK_CHARLIT {
    std::string t = gentemp("char");
    $$.label = t;
    $$.tipo = "char";
    $$.traducao = "    " + t + " = " + $1.label + ";\n";
}

| TK_STRLIT {
    std::string t = gentemp("string");
    std::ostringstream ss;
    ss << "    " << t << " = (char*) malloc(strlen(\"" << $1.label << "\") + 1);\n";
    ss << "    strcpy(" << t << ", \"" << $1.label << "\");\n";
    $$.label = t;
    $$.tipo = "string";
    $$.traducao = ss.str();
}





| '(' TK_INT ')' E {
    std::string cast = gentemp("int");

    $$.traducao = $4.traducao;
    $$.traducao += "    " + cast + " = (int) " + $4.label + ";\n";
    $$.label = cast;
    $$.tipo = "int";
}

| '(' TK_FLOAT ')' E {
    std::string cast = gentemp("float");

    $$.traducao = $4.traducao;
    $$.traducao += "    " + cast + " = (float) " + $4.label + ";\n";
    $$.label = cast;
    $$.tipo = "float";
}



| '(' E ')' {
    $$.label = $2.label;
    $$.tipo = $2.tipo;
    $$.traducao = $2.traducao;
}
;

%%

int main() {
    yydebug = 1;
    tabela_simbolos.push_back({});
    yyparse();
    return 0;
}














