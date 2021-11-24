#include "strlib.h"
#include <stdio.h>


int str_length (const char *str) {
    int cont = 0;

    if (str == NULL) return -1;
    
    for (int i=0; i < *str; i++) {
        if (str[i] != '\n' && str[i] != '\0') cont++;
        else break;
    }
    return cont;
}

char* str_duplicate (const char *str) {
    char *aux;

    if (str == NULL) return aux = NULL;
    

    int text_length;
    text_length = str_length(str);

    aux = (char*) malloc(sizeof(int) * text_length);

    for (int i=0; i<text_length; i++) {
        aux[i] = str[i];
    }
    return aux;
}

int str_compare (const char *stra, const char *strb) {

}


int main () {
    char c[200];
    char c_aux[200];
    //char *c_aux;

    fgets(c, 200, stdin); 

    //c_aux = str_duplicate(c); // <- Ex 2






    //free(c_aux);

    return 0;
}