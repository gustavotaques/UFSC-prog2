#include <stdio.h>


int recursive (int base, int expoente) {
    if (base == 1 || expoente == 0) return 1;
    if (base == 0) return 0;
    if (expoente == 1) return base;

    return base * recursive(base, expoente-1);
}

int main () {
    printf("%d\n", recursive(2,5));
    return 0;
}