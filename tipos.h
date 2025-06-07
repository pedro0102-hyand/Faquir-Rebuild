#ifndef TIPOS_H
#define TIPOS_H

#include <string>
using namespace std;

struct atributos {
    string label;
    string traducao;
    string tipo;

    std::string rotulo_break;
    std::string rotulo_continue;
    std::string incr;
};

#define YYSTYPE atributos  // <- VISÍVEL para ambos: .l e .y

#endif


