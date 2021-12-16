#include <stdio.h>

int recursive(int n1, int n2) {
    if (n1 == n2) return n1;
    if (n1 == 0) return n2;
    if (n2 == 0) return n1;

    if (n1 > n2) return recursive(n1-n2, n2);
    else return recursive(n2, n1);
}

int main () {
    printf("%d\n", recursive(3,4));
    return 0;
}