/* Compilador Faquir Rebuild */
#include <stdio.h>
int main(void) {
    int T1;
    int T2;
    int T3;
    int T4;
    int T5;
    int T6;
    T2 = 5;
    T1 = T2;
L1:
    T3 = 0;
    T4 = T1 > T3;
    if (!T4) goto L3; // condição falsa
    printf("%d\n", T1);
L2:
    T5 = 1;
    T6 = T1 - T5;
    T1 = T6;
    goto L1;
L3:
    printf("%s\n", "Fim do Loop");
    return 0;
}
