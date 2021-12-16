#include <stdio.h>

int recursive (int n) {
    if (n == 0 || n == 1) return n;

    return recursive(n-1) + recursive(n-2);
}

int main () {
    printf("%d\n", recursive(20));
    return 0;
}