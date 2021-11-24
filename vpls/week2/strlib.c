#include "strlib.h"
#include <stdio.h>
#include <string.h>


int str_length (const char *str) {
    int cont = 0;

    if (str[0] == 0 || str[0] == 10) {
        return -1;
    }
    
    for (int i=0; i < *str; i++) {
        if (str[i] != 10 && str[i] != 0) cont++;
        else break;
    }
    return cont;
}


char* str_duplicate (const char *str) {
    if (str[0] == 10 || str[0] == 0) {
        return NULL;
    }

    char *aux;
    int text_length;

    text_length = str_length(str);

    aux = (char*) malloc(sizeof(int) * text_length);

    for (int i=0; i<text_length; i++) {
        aux[i] = str[i];
    }
    return aux;
}


int str_compare (const char *stra, const char *strb) {
    
    while ((*stra != 0 && *stra != 10) && (*strb != 0 && *strb != 10)) {
        if (*stra < *strb) return -1;
        if (*stra > *strb) return 1;

        stra++;
        strb++;

    }
    return 0;
}


int str_reverse (char *str) {
    if (str[0] == 0 || str[0] == 10) return 0;
    
    int n = str_length(str) - 1;
    int i = 0;
    char aux;

    while (i < n) {
        aux = str[i];
        str[i] = str[n];
        str[n] = aux;

        i++;
        n--;
    }
    return 1;
}


int main () {
    char c[200];

    fgets(c, 200, stdin);

    return 0;
}