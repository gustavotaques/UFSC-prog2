#include <stdio.h>
#include <string.h>

// 1: É recursivo | 0: Não é recursivo
int recursive (char *arr, int tam){
    if (tam <= 1) return 1;

    if(arr[0] != arr[tam-1]) return 0;

    recursive(arr+1, tam-2);
}

int main (){
    char array[] = "tenet";
    int size = strlen(array);
    printf("%d\n", recursive(array, size));
    return 0;
}