#include <stdio.h>


void recursive(int vetor[], int i, int tam_vetor) {
    if (vetor == NULL || i >= tam_vetor) return;

    printf("%d ", vetor[i]);
    
    recursive(vetor,i+1,tam_vetor);
}

int main () {
    int vetor[] = {1,2,3};
    int idx = 0;
    int vetor_length = (sizeof(vetor) / sizeof(vetor[0]));
    recursive(vetor, idx, vetor_length);

    return 0;
}