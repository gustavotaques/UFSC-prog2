#include <stdio.h>


int recursive(int vetor[], int tam_vetor) {
    if (vetor == NULL || tam_vetor == 0) return 0;
    if (tam_vetor == 1) return vetor[0];

    return vetor[tam_vetor-1] + recursive(vetor,tam_vetor-1);
}

int main () {
    int vetor[] = {1,2,3};
    int tam_vetor = (sizeof(vetor) / sizeof(vetor[0]));
    printf("%d\n", recursive(vetor,tam_vetor));
    return 0;
}