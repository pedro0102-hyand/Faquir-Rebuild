%{
#include <iostream>
#include <vector>
#include <string>
#include "tipos.h"

int temp_count = 0;
int yydebug = 1;
std::vector<std::string> declaracoes;

int yylex(void);
void yyerror(const char* s) {
    std::cout << "Erro de sintaxe: " << s << std::endl;
    exit(1);
}

std::string gentemp();
%}

%token TK_INT TK_MAIN TK_NUM
%left '+' '-'
%left '*' '/'
%start S

%%

S : TK_INT TK_MAIN '{' E '}' {
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

E : E '+' E {
    std::string t = gentemp();
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " + " + $3.label + ";\n";
    $$.label = t;
}
| E '-' E {
    std::string t = gentemp();
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " - " + $3.label + ";\n";
    $$.label = t;
}
| E '*' E {
    std::string t = gentemp();
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " * " + $3.label + ";\n";
    $$.label = t;
}
| E '/' E {
    std::string t = gentemp();
    $$.traducao = $1.traducao + $3.traducao;
    $$.traducao += "    " + t + " = " + $1.label + " / " + $3.label + ";\n";
    $$.label = t;
}
| TK_NUM {
    std::string t = gentemp();
    $$.label = t;
    $$.traducao = "    " + t + " = " + $1.label + ";\n";
}
| '(' E ')' {
    $$.label = $2.label;
    $$.traducao = $2.traducao;
}

;

%%

std::string gentemp() {
    temp_count++;
    std::string nome = "T" + std::to_string(temp_count);
    declaracoes.push_back("int " + nome + ";");
    return nome;
}

int main() {
    yydebug = 1;
    yyparse();
    return 0;
}











