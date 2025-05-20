all:
	flex analisador.l
	bison -d analisador.y
	g++ -std=c++11 lex.yy.c analisador.tab.c -o faquir

clean:
	rm -f lex.yy.c analisador.tab.c analisador.tab.h faquir
