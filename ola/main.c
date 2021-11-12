#include <stdio.h>
#include <string.h>

int main () {

    char entrada[50];
    int cont = 0;

    fgets(entrada, 50, stdin);

    while ((strcmp(entrada, "#\n") != 0) && (strcmp(entrada, "#") != 0)) {
        
        if (strcmp(entrada, "HALLO\n") == 0) {
            cont++;
            printf("Caso %i: ALEMAO\n", cont);

        }else if (strcmp(entrada, "HOLA\n") == 0) {
            cont++;
            printf("Caso %i: ESPANHOL\n", cont);
        
        }else if (strcmp(entrada, "HELLO\n") == 0) {
            cont++;
            printf("Caso %i: INGLES\n", cont);

        }else if (strcmp(entrada, "BONJOUR\n") == 0){
            cont++;
            printf("Caso %i: FRANCES\n", cont);

        }else if (strcmp(entrada, "CIAO\n") == 0){
            cont++;
            printf("Caso %i: ITALIANO\n", cont);

        }else if (strcmp(entrada, "ZDRAVSTVUJTE\n") == 0){
            cont++;
            printf("Caso %i: RUSSO\n", cont);
        
        }else{
            cont++;
            printf("Caso %i: DESCONHECIDO\n", cont);

        }

        fgets(entrada, 50, stdin);

    }

    return 0;
}