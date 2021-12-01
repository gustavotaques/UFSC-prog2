#include "lab.h"
#include <stdlib.h>
#include <math.h>

FILE *abre_arquivo(const char *arquivo) {
    FILE *arq = fopen(arquivo, "r");
    
    return arq;
}


int fecha_arquivo(FILE *arq) {
    if (!arq) {
        return -1;
    }

    return fclose(arq);
}


double *le_valores(const char *arquivo, unsigned int *qtd_numeros) {

    if (!qtd_numeros) {
        return NULL;
    }

    FILE *arq = abre_arquivo(arquivo);

    if (!arq) {
        *qtd_numeros = 0;
        return NULL;
    }
    
    int cont = 0;
    double n;

    while (!feof(arq)) {
        fscanf(arq, "%lf", &n);
        cont++;
    }
    
    double *v = (double*) malloc(sizeof(double) * cont);
    rewind(arq);

    int i = 0;

    while (!feof(arq)) {
        fscanf(arq, "%lf", &n);
        v[i] = n;
        i++;
    }

    *qtd_numeros = cont-1;

    fecha_arquivo(arq);

    return v;
}


double maior(double* valores, unsigned int qtd_numeros) {
    if (!valores) return HUGE_VAL;

    double aux = 0.00;

    for (int i=0; i<qtd_numeros; i++) {
        if (i == 0) aux = valores[i];
        else if (valores[i] > aux) aux = valores[i];
    }
    return aux;
}


double menor(double* valores, unsigned int qtd_numeros) {
    if (!valores) return HUGE_VAL;

    double aux = 0.00;

    for (int i=0; i<qtd_numeros; i++) {
        if (i == 0) aux = valores[i];
        else if (valores[i] < aux) aux = valores[i];
    }
    return aux;
}


double media(double* valores, unsigned int qtd_numeros) {
    if (!valores) return HUGE_VAL;

    double aux = 0.00;

    for (int i=0; i<qtd_numeros; i++) aux += valores[i];

    return aux / qtd_numeros;
}


double desvio(double* valores, unsigned int qtd_numeros) {
    if (!valores) return HUGE_VAL;

    double med = media(valores, qtd_numeros);

    double aux = 0.00;

    for (int i=0; i<qtd_numeros; i++) aux += pow(valores[i] - med,2);
    
    aux = sqrt(aux/(qtd_numeros-1));

    return aux;
}


double amplitude(double* valores, unsigned int qtd_numeros) {
    if (!valores) return HUGE_VAL;

    double m = maior(valores, qtd_numeros);
    double n = menor(valores, qtd_numeros);

    return m - n;
}


double valor(double* valores, unsigned int qtd_numeros, unsigned int posicao) {
    if (!valores) return HUGE_VAL;
    if (posicao > qtd_numeros) return HUGE_VAL;

    return valores[posicao];
}


double repetido(double* valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao) {
    if (!valores) {
        *qtd_repeticao = 0;
        return HUGE_VAL;
    }

    int cont, cont_repeticao = 0, indice_maior_freq = 0;

    for (int i = 0; i <= qtd_numeros; i++) {
        cont = 0;
        for (int j = i + 1; j <= qtd_numeros; j++) {
            if (valores[i] == valores[j]) {
                cont++;
            }
        }
        if (cont > cont_repeticao) {
            indice_maior_freq = i;
            cont_repeticao = cont;
        }
    }
    *qtd_repeticao = cont_repeticao;
    return valores[indice_maior_freq];

}


int main () {
    char name[] = "example.txt";
    unsigned int cont;
    unsigned int pos = 19;

    double *aux = le_valores(name, &cont);
    
    printf("%d\n", cont);
    // printf("%.2f\n", valor(aux, cont, pos));

    return 0;
}