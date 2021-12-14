#include <stdio.h>


int recursive (int n) {
    if (n == 1) return 1;
    if (n < 1) return n + recursive(n+1);
    return n + recursive(n-1);
}


int main () {
    printf("%d\n", recursive(-2));
    return 0;
}