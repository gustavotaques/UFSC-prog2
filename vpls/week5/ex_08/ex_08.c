#include <stdio.h>


void recursive(int vetor[], int tam_vetor) {
    if (vetor == NULL || tam_vetor == 0) return;

    printf("%d ", vetor[tam_vetor-1]);
    
    recursive(vetor,tam_vetor-1);
}

int main () {
    int vetor[] = {1,2,3,4,5,6,7,8,9,10,100,1000};
    int vetor_length = (sizeof(vetor) / sizeof(vetor[0]));
    recursive(vetor, vetor_length);

    return 0;
}