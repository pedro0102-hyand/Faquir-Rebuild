#ifndef TIPOS_H
#define TIPOS_H

#include <string>
using namespace std;

struct atributos {
    string label;
    string traducao;
};

#define YYSTYPE atributos  // <- VISÍVEL para ambos: .l e .y

#endif


