/* Compilador Faquir Rebuild */
#include <stdio.h>
int main(void) {
    int T1;
    int T2;
    int T3;
    int T4;
    int T5;
    int T6;
    int T7;
    int __switch_var10;
    T3 = 0;
    T1 = T3;
    T4 = 1;
    T5 = T1 == T4;
    if (!T5) goto L8; // if condicional falsa
    T6 = 1;
    T2 = T6;
    goto L9; // fim do if
L8:
    T7 = 2;
    T2 = T7;
L9:
    __switch_var10 = T2; // guarda valor do switch
    if (__switch_var10== 1) goto L2;
    if (__switch_var10== 2) goto L3;
L2:
    printf("%d\n", T2);
    goto L1; // break
    goto L1; // break implícito no case
L3:
    printf("%d\n", T2);
    goto L1; // break
    goto L1; // break implícito no case
L1:
    return 0;
}
