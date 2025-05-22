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
%}

%token TK_INT TK_FLOAT TK_MAIN TK_NUM TK_ID TK_FLOATNUM
%token TK_CHAR TK_BOOLEAN TK_TRUE TK_FALSE TK_CHARLIT

%left '+' '-'
%left '*' '/'
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

COMANDO : TK_ID '=' E ';' {
    std::string var_temp = get_temp($1.label);
    std::string var_tipo = get_tipo($1.label);

    // Se o valor já é literal direto (ex: 'a', 1) e não teve tradução,
    // não crie temporário extra para o literal
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
    std::string t = gentemp("int"); // boolean representado como int
    variaveis.push_back($2.label);
    temporarios.push_back(t);
    tipos.push_back("boolean");
    $$.traducao = "";
}

| E ';' {
    $$.traducao = $1.traducao;
}
;

E : E '+' E {
    std::string tipo_resultado = ($1.tipo == "float" || $3.tipo == "float") ? "float" : "int";
    std::string t = gentemp(tipo_resultado);
    $$.label = t;
    $$.tipo = tipo_resultado;
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " + " + $3.label + ";\n";
}
| E '-' E {
    std::string tipo_resultado = ($1.tipo == "float" || $3.tipo == "float") ? "float" : "int";
    std::string t = gentemp(tipo_resultado);
    $$.label = t;
    $$.tipo = tipo_resultado;
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " - " + $3.label + ";\n";
}
| E '*' E {
    std::string tipo_resultado = ($1.tipo == "float" || $3.tipo == "float") ? "float" : "int";
    std::string t = gentemp(tipo_resultado);
    $$.label = t;
    $$.tipo = tipo_resultado;
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " * " + $3.label + ";\n";
}
| E '/' E {
    std::string tipo_resultado = ($1.tipo == "float" || $3.tipo == "float") ? "float" : "int";
    std::string t = gentemp(tipo_resultado);
    $$.label = t;
    $$.tipo = tipo_resultado;
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " / " + $3.label + ";\n";
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
    $$.label = $1.label;   // ← já vem como 'a'
    $$.tipo = "char";
    $$.traducao = "";
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













