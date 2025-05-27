%{
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

BLOCO : '{' LISTA_COMANDOS '}' {
    $$.traducao = $2.traducao;
}
;

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


COMANDO : TK_ID '=' E ';' {
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
    for (const std::string& v : variaveis) {
        if (v == $2.label) {
            std::cerr << "Erro: variável '" << $2.label << "' já declarada.\n";
            exit(1);
        }
    }
    std::string t = gentemp("int");
    variaveis.push_back($2.label);
    temporarios.push_back(t);
    tipos.push_back("int");
    $$.traducao = "";
}
| TK_FLOAT TK_ID ';' {
    for (const std::string& v : variaveis) {
        if (v == $2.label) {
            std::cerr << "Erro: variável '" << $2.label << "' já declarada.\n";
            exit(1);
        }
    }
    std::string t = gentemp("float");
    variaveis.push_back($2.label);
    temporarios.push_back(t);
    tipos.push_back("float");
    $$.traducao = "";
}
| TK_CHAR TK_ID ';' {
    for (const std::string& v : variaveis) {
        if (v == $2.label) {
            std::cerr << "Erro: variável '" << $2.label << "' já declarada.\n";
            exit(1);
        }
    }
    std::string t = gentemp("char");
    variaveis.push_back($2.label);
    temporarios.push_back(t);
    tipos.push_back("char");
    $$.traducao = "";
}
| TK_BOOLEAN TK_ID ';' {
    for (const std::string& v : variaveis) {
        if (v == $2.label) {
            std::cerr << "Erro: variável '" << $2.label << "' já declarada.\n";
            exit(1);
        }
    }
    std::string t = gentemp("int");
    variaveis.push_back($2.label);
    temporarios.push_back(t);
    tipos.push_back("boolean");
    $$.traducao = "";
}

| TK_STRING TK_ID ';' {
    for (const std::string& v : variaveis) {
        if (v == $2.label) {
            std::cerr << "Erro: variável '" << $2.label << "' já declarada.\n";
            exit(1);
        }
    }
    std::string t = gentemp("char*");
    variaveis.push_back($2.label);
    temporarios.push_back(t);
    tipos.push_back("string");
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
    else fmt = "??";

    $$.traducao = "    printf(\"" + fmt + "\\n\", " + temp + ");\n";
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
    std::string l_fim = "L" + std::to_string(++temp_count);

    $$.traducao = $3.traducao;
    $$.traducao += "    if (!" + $3.label + ") goto " + l_fim + ";\n";
    $$.traducao += $5.traducao;
    $$.traducao += l_fim + ":\n";
}
| TK_IF '(' E ')' BLOCO TK_ELSE BLOCO {
    std::string l_else = "L" + std::to_string(++temp_count);
    std::string l_fim  = "L" + std::to_string(++temp_count);

    $$.traducao = $3.traducao;
    $$.traducao += "    if (!" + $3.label + ") goto " + l_else + ";\n";
    $$.traducao += $5.traducao;
    $$.traducao += "    goto " + l_fim + ";\n";
    $$.traducao += l_else + ":\n";
    $$.traducao += $7.traducao;
    $$.traducao += l_fim + ":\n";
}

| TK_WHILE '(' E ')' BLOCO {
    std::string l_inicio = "L" + std::to_string(++temp_count);
    std::string l_fim = "L" + std::to_string(++temp_count);

    // ✅ empilha antes de $5 ser processado
    loop_labels.push_back(l_fim);

    std::string bloco = $5.traducao;

    $$.traducao = l_inicio + ":\n";
    $$.traducao += $3.traducao;
    $$.traducao += "    if (!" + $3.label + ") goto " + l_fim + ";\n";
    $$.traducao += bloco;
    $$.traducao += "    goto " + l_inicio + ";\n";
    $$.traducao += l_fim + ":\n";

    loop_labels.pop_back(); // ✅ depois que já usamos $5
}

| TK_DO BLOCO TK_WHILE '(' E ')' ';' {
    std::string l_inicio = "L" + std::to_string(++temp_count);
    std::string l_cond = "L" + std::to_string(++temp_count);
    std::string l_fim = "L" + std::to_string(++temp_count);

    loop_labels.push_back(l_cond); // destino do continue

    std::string bloco = $2.traducao;

    loop_labels.pop_back(); // remove após bloco

    $$.traducao = l_inicio + ":\n";
    $$.traducao += bloco;
    $$.traducao += l_cond + ":\n";
    $$.traducao += $5.traducao;
    $$.traducao += "    if (" + $5.label + ") goto " + l_inicio + ";\n";
    $$.traducao += l_fim + ":\n";
}

| TK_FOR '(' INIT E ';' INCR ')' BLOCO {
    std::string l_inicio = "L" + std::to_string(++temp_count);
    std::string l_cond = "L" + std::to_string(++temp_count);
    std::string l_fim = "L" + std::to_string(++temp_count);

    // empilha o destino de break e continue
    loop_labels.push_back(l_fim);  // break vai pra cá
    loop_labels.push_back(l_cond); // continue vai pra cá

    $$.traducao = $3.traducao;  // INIT
    $$.traducao += l_inicio + ":\n";
    $$.traducao += $4.traducao;  // condição
    $$.traducao += "    if (!" + $4.label + ") goto " + l_fim + ";\n";
    $$.traducao += $8.traducao;  // bloco
    $$.traducao += l_cond + ":\n";
    $$.traducao += $6.traducao;  // incremento
    $$.traducao += "    goto " + l_inicio + ";\n";
    $$.traducao += l_fim + ":\n";

    loop_labels.pop_back(); // pop continue
    loop_labels.pop_back(); // pop break
}

| TK_SWITCH '(' E ')' '{' CASOS '}' {
    std::string switch_var = "__switch_var" + std::to_string(++temp_count);
    declaracoes.push_back("int " + switch_var + ";");

    // Armazena valor da expressão em uma variável auxiliar
    std::string codigo = $3.traducao;
    codigo += "    " + switch_var + " = " + $3.label + ";\n";

    // Substitui __switch_var por switch_var com proteção contra loop
    std::string casos_traducao = $6.traducao;
    std::string from = "__switch_var";
    size_t pos = 0;
    while ((pos = casos_traducao.find(from, pos)) != std::string::npos) {
        casos_traducao.replace(pos, from.length(), switch_var);
        pos += switch_var.length();  // avança para evitar loop infinito
    }

    $$.traducao = codigo + casos_traducao;
}



| BLOCO {
    $$.traducao = $1.traducao;
}


| E ';' {
    $$.traducao = $1.traducao;
}
;

CASOS : CASOS TK_CASE TK_NUM ':' LISTA_COMANDOS {
    std::string l_case = "L" + std::to_string(++temp_count);
    $$.traducao = $1.traducao;
    $$.traducao += "    if (__switch_var == " + $3.label + ") goto " + l_case + ";\n";
    $$.traducao += l_case + ":\n" + $5.traducao;
}
| TK_CASE TK_NUM ':' LISTA_COMANDOS {
    std::string l_case = "L" + std::to_string(++temp_count);
    $$.traducao = "    if (__switch_var == " + $2.label + ") goto " + l_case + ";\n";
    $$.traducao += l_case + ":\n" + $4.traducao;
}
| CASOS TK_DEFAULT ':' LISTA_COMANDOS {
    std::string l_default = "L" + std::to_string(++temp_count);
    $$.traducao = $1.traducao;
    $$.traducao += "    goto " + l_default + ";\n";
    $$.traducao += l_default + ":\n" + $4.traducao;
}
| TK_DEFAULT ':' LISTA_COMANDOS {
    std::string l_default = "L" + std::to_string(++temp_count);
    $$.traducao = "    goto " + l_default + ";\n";
    $$.traducao += l_default + ":\n" + $3.traducao;
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
    $$.label = "1";
    $$.tipo = "boolean";
    $$.traducao = "";
}
| TK_FALSE {
    $$.label = "0";
    $$.tipo = "boolean";
    $$.traducao = "";
}
| TK_CHARLIT {
    $$.label = $1.label;
    $$.tipo = "char";
    $$.traducao = "";
}
| '(' TK_INT ')' E {
    std::string copia = gentemp($4.tipo); // tipo original
    std::string cast = gentemp("int");

    $$.label = cast;
    $$.tipo = "int";

    $$.traducao = $4.traducao;
    $$.traducao += "    " + copia + " = " + $4.label + ";\n";
    $$.traducao += "    " + cast + " = (int) " + copia + ";\n";
}

| '(' TK_FLOAT ')' E {
    std::string copia = gentemp($4.tipo); // tipo original
    std::string cast = gentemp("float");

    $$.label = cast;
    $$.tipo = "float";

    $$.traducao = $4.traducao;
    $$.traducao += "    " + copia + " = " + $4.label + ";\n";
    $$.traducao += "    " + cast + " = (float) " + copia + ";\n";
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
    yyparse();
    return 0;
}














