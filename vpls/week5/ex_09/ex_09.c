#include <stdio.h>

void recursive (int vetor[], int tam){
    if (vetor == NULL || tam == 0) return;
    int temp = 0;
    
    if(tam-1 > 0) {
        temp = vetor[0];
        vetor[0] = vetor[tam-1];
        vetor[tam-1] = temp;

        recursive(vetor+1, tam-2);
    }

}

int main () {
    int vet[] = {1,2,3,4,5};
    int tam = sizeof(vet)/sizeof(vet[0]);

    recursive(vet, tam);

    for (int i=0; i<tam; i++) printf("%d ", vet[i]);

    return 0;
}