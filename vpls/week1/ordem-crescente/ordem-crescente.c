#include <stdio.h>

int main () {

    int n;
    scanf("%d", &n);

    int anterior, atual;
    scanf("%d", &anterior);

    int crescente = 1;

    for (int i=0; i<n-1; i++) {
        scanf("%d", &atual);
        if (atual < anterior)
            crescente = 0;
        anterior = atual;
    }

    if (crescente)
        printf("SIM");
    else
        printf("NAO");

    return 0;
}