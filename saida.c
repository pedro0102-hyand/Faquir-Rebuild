/* Compilador Faquir Rebuild */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int T1;
    int T2;
    int T3;
    int T4;
    int T5;
    int T6;
    int T7;
    int T8;
    int T9;
    int T10;
    int T12;
    int T13;
    T2 = 0;
    T1 = T2;
L1:
    T3 = 1;
    if (!T3) goto L2; // condição falsa
    T4 = 1;
    T5 = T1 + T4;
    T1 = T5;
    T6 = 2;
    T7 = 4;
    T8 = T1 == T7;
    T9 = T6 || T8;
    T10 = T1 == T9;
    if (!T10) goto L11; // if condicional falsa
    goto L1; // continue
L11:
    T12 = 6;
    T13 = T1 == T12;
    if (!T13) goto L14; // if condicional falsa
    goto L2; // break
L14:
    printf("%d\n", T1);
    goto L1; // repetir
L2:
    return 0;
}
