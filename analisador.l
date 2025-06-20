%{
#include "tipos.h"
#include "analisador.tab.h"
using namespace std;
%}

DIGITO      [0-9]+
ESPACO      [ \t\r\n]+

%%

"int"       { return TK_INT; }
"float"     { return TK_FLOAT; }
"main"      { return TK_MAIN; }

"var"   { return TK_VAR; }

"if"        { return TK_IF; }
"else"      { return TK_ELSE; }

break[ \t]+all   { return TK_BREAKALL; }
"break"     { return TK_BREAK; }
"continue"  { return TK_CONTINUE; }


"while"     { return TK_WHILE; }

"do"        { return TK_DO; }

"for"       { return TK_FOR; }

"switch"    { return TK_SWITCH; }
"case"      { return TK_CASE; }
"default"   { return TK_DEFAULT; }




"{"         { return '{'; }
"}"         { return '}'; }
"("         { return '('; }
")"         { return ')'; }
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
"**"        { return TK_POW; }

"//"    { return TK_INTDIV; }    
"%"     { return '%'; }
"<<"    { return TK_LSHIFT; }
">>"    { return TK_RSHIFT; }



"=="        { return TK_EQ; }
"!="        { return TK_NE; }
"<="        { return TK_LE; }
">="        { return TK_GE; }
"<"         { return TK_LT; }
">"         { return TK_GT; }

"&&"        { return TK_AND; }
"||"        { return TK_OR; }
"!"         { return TK_NOT; }

"+="        { return TK_ADDEQ; }
"-="        { return TK_SUBEQ; }
"*="        { return TK_MULTEQ; }
"/="        { return TK_DIVEQ; }

"++"    { return TK_INC; }
"--"    { return TK_DEC; }



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

[0-9]+\.[0-9]+   { yylval.label = yytext; return TK_FLOATNUM; }
{DIGITO}         { yylval.label = yytext; return TK_NUM; }

"print"     { return TK_PRINT; }
"read"      { return TK_READ; }
"string"    { return TK_STRING; }
"exit"      { return TK_EXIT; }


\"[^\"]*\" {
    std::string str(yytext);
    yylval.label = str.substr(1, str.size() - 2); // remove as aspas
    return TK_STRLIT;
}





[A-Za-z_][A-Za-z0-9_]* {
    yylval.label = string(yytext);
    return TK_ID;
}

{ESPACO}         { /* ignora */ }

.                { return *yytext; }

%%

int yywrap() { return 1; }









