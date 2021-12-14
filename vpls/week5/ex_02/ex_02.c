#include <stdio.h>

int recursive (int n1, int n2) {
    if (n1 == n2) return printf("%d", n2);
    printf("%d ", n1);
    if (n1 > n2) {
        return recursive(n1-1,n2);
    }
    return recursive(n1+1,n2);
}

int main () {
    recursive(1,40);
    return 0;
}