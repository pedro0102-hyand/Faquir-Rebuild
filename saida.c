/* Compilador Faquir Rebuild */
#include <stdio.h>
int main(void) {
    int T1;
    int T2;
    int T3;
    int T4;
    int T5;
    int T6;
    int T8;
    int T9;
    T2 = 0;
    T1 = T2;
L1:
    T3 = 1;
    T4 = T1 + T3;
    T1 = T4;
    T5 = 2;
    T6 = T1 == T5;
    if (!T6) goto L7; // if condicional falsa
    goto L2; // continue
L7:
    printf("%d\n", T1);
L2:
    T8 = 3;
    T9 = T1 < T8;
    if (T9) goto L1; // repetir
L3:
    return 0;
}
