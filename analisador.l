%{
#include "tipos.h"
#include "analisador.tab.h"
using namespace std;
%}

DIGITO      [0-9]+
ESPACO      [ \t\r\n]+

%%

"int"       { return TK_INT; }
"float"     { return TK_FLOAT; }         // ← adiciona suporte à palavra-chave float
"main"      { return TK_MAIN; }

"{"         { return '{'; }
"}"         { return '}'; }
"("         { return '('; }
")"         { return ')'; }
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
"="         { return '='; }
"char"      { return TK_CHAR; }
"boolean"   { return TK_BOOLEAN; }
"true"      { yylval.label = "1"; return TK_TRUE; }
"false"     { yylval.label = "0"; return TK_FALSE; }
\'[a-zA-Z0-9]\' {
    std::string s = yytext;
    yylval.label = s;  // mantém como 'a', '1', etc.
    return TK_CHARLIT;
}


[0-9]+\.[0-9]+   { yylval.label = yytext; return TK_FLOATNUM; }  // ← para literais float
{DIGITO}         { yylval.label = yytext; return TK_NUM; }

[A-Za-z_][A-Za-z0-9_]* { yylval.label = string(yytext); return TK_ID; }

{ESPACO}    { /* ignora */ }

.           { return *yytext; }

%%
int yywrap() { return 1; }








