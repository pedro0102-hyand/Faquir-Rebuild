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
    T4 = 1;
    T1 = T4;
    T5 = 0;
    T2 = T5;
    T6 = !T2;
    T7 = T1 && T6;
    T3 = T7;
    printf("%d\n", T1);
    printf("%d\n", T2);
    printf("%d\n", T3);
    return 0;
}
