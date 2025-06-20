/* Compilador Faquir Rebuild */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
    T1 = 0;
    T2 = T1;
L1:
    T3 = 10;
    T4 = T2 < T3;
    if (!T4) goto L2; // condição falsa
    T5 = 0;
    T6 = T5;
L3:
    T7 = 5;
    T8 = T6 < T7;
    if (!T8) goto L4; // condição falsa
    goto L2; // break all
    T9 = T6 + 1;
    T6 = T9;
    goto L3; // repetir
L4:
    T10 = T2 + 1;
    T2 = T10;
    goto L1; // repetir
L2:
    return 0;
}
