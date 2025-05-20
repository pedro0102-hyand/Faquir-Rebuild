%{
#include "tipos.h"
#include "analisador.tab.h"
using namespace std;
%}

DIGITO      [0-9]+
ESPACO      [ \t\r\n]+

%%

"int"       { return TK_INT; }
"main"      { return TK_MAIN; }

"{"         { return '{'; }
"}"         { return '}'; }
"("         { return '('; }
")"         { return ')'; }
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }

{DIGITO}    { yylval.label = yytext; return TK_NUM; }

{ESPACO}    { /* ignora */ }

.           { return *yytext; }

%%
int yywrap() { return 1; }







