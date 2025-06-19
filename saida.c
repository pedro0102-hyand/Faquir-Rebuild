/* Compilador Faquir Rebuild */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(void) {
    char* T1;
    char* T2;
    T1 = (char*) malloc(strlen("Pedro") + 1);
    strcpy(T1, "Pedro");
    T2 = (char*) malloc(strlen(T1) + 1);
    strcpy(T2, T1);
    printf("%s\n", T2);
    return 0;
}
