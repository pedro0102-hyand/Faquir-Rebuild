/* Compilador Faquir Rebuild */
#include <stdio.h>
int main(void) {
    int T1;
    int T2;
    int __switch_var3;
    T2 = 2;
    T1 = T2;
    __switch_var3 = T1; // guarda valor do switch
    if (__switch_var3== 0) goto L2;
    if (__switch_var3== 1) goto L3;
    if (__switch_var3== 2) goto L4;
    goto Ldefault;
L2:
    printf("%s\n", "Vermelho");
    goto L1; // break
    goto L1; // break implícito no case
L3:
    printf("%s\n", "Verde");
    goto L1; // break
    goto L1; // break implícito no case
L4:
    printf("%s\n", "Azul");
    goto L1; // break
    goto L1; // break implícito no case
Ldefault:
    printf("%s\n", "Cor desconhecida");
    goto L1; // break após default
L1:
    return 0;
}
