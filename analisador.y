%{
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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
%token TK_BREAK TK_CONTINUE TK_STRLIT





%left '+' '-'
%left '*' '/'
%right TK_NOT
%left TK_AND
%left TK_OR



%start S

%%

S : TK_INT TK_MAIN '{' LISTA_COMANDOS '}' {
    std::cout << "/* Compilador Faquir Rebuild */\n";
    std::cout << "#include <stdio.h>\n";
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


INIT : TK_ID '=' E ';' {
    std::string var_temp = get_temp($1.label);
    std::string var_tipo = get_tipo($1.label);
    std::string t = $3.traducao + "    " + var_temp + " = " + $3.label + ";\n";
    $$.traducao = t;
};

INCR : TK_ID '=' E {
    std::string var_temp = get_temp($1.label);
    std::string var_tipo = get_tipo($1.label);
    std::string t = $3.traducao + "    " + var_temp + " = " + $3.label + ";\n";
    $$.traducao = t;
};

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
    std::string var_temp = get_temp($1.label);
    std::string var_tipo = get_tipo($1.label);

    if ($3.traducao == "") {
        $$.traducao = "    " + var_temp + " = " + $3.label + ";\n";
    } else {
        $$.traducao = $3.traducao;
        $$.traducao += "    " + var_temp + " = " + $3.label + ";\n";
    }
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
    $$.traducao = "";
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

    // Variável temporária para armazenar o valor da expressão do switch
    std::string switch_var = "__switch_var" + std::to_string(++temp_count);
    declaracoes.push_back("int " + switch_var + ";");

    // Código da avaliação da expressão do switch
    std::string codigo = $3.traducao;
    codigo += "    " + switch_var + " = " + $3.label + "; // guarda valor do switch\n";

    // Recupera o corpo dos casos
    std::string casos_traducao = $7.traducao;  // <-- importante: $7 é CASOS

    // Substitui "__switch_var" pelo nome real
    std::string from = "__switch_var";
    size_t pos = 0;
    while ((pos = casos_traducao.find(from, pos)) != std::string::npos) {
        casos_traducao.replace(pos, from.length(), switch_var);
        pos += switch_var.length();
    }

    // Se existir um label default, insere goto para ele
    std::string l_default;
    size_t pos_default = casos_traducao.find("Ldefault:");
    if (pos_default != std::string::npos) {
        l_default = "Ldefault";
        codigo += "    goto " + l_default + ";\n";
    }

    // Fecha o bloco do switch
    std::string l_fim_switch = $5.label;
    pilha_controle.pop_back();

    $$.traducao = codigo + casos_traducao + l_fim_switch + ":\n";
}




| TK_BREAK ';' {
    if (pilha_controle.empty()) {
        std::cerr << "Erro: 'break' fora de estrutura de controle.\n";
        exit(1);
    }
    $$.traducao = "    goto " + pilha_controle.back().rotulo_break + "; // break\n";
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
    std::string tipo_resultado = ($1.tipo == "float" || $3.tipo == "float") ? "float" : "int";
    std::string t = gentemp(tipo_resultado);
    std::string traducao = $1.traducao + $3.traducao;
    std::string a1 = gerar_cast($1.label, $1.tipo, tipo_resultado, traducao);
    std::string a2 = gerar_cast($3.label, $3.tipo, tipo_resultado, traducao);
    $$.label = t;
    $$.tipo = tipo_resultado;
    $$.traducao = traducao + "    " + t + " = " + a1 + " + " + a2 + ";\n";
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
    std::string t = get_temp($1.label);
    $$.label = t;
    $$.tipo = get_tipo($1.label);
    $$.traducao = "";
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
    $$.label = t;
    $$.tipo = "string";
    $$.traducao = "    " + t + " = \"" + $1.label + "\";\n";
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














