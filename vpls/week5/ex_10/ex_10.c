#include <stdio.h>

int recursive (int n1, int n2){
    if (n1 == 0 || n2 == 0) return 0;

    return n1 + recursive(n1, n2-1);
}

int main () {
    printf("%d\n", recursive(0,1110));

    return 0;
}