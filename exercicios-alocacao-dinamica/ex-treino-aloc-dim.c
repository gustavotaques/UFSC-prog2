#include <stdio.h>
#include <stdlib.h>


int** aloca_matriz_quadratica (int n) {
    int **m;

    m = (int**) malloc(sizeof(int*) * n);

    for (int i=0; i<n; i++) {
        m[i] = (int*) malloc(sizeof(int) * (i+1));
    }

    return m;
}

void preenche_matriz (int **m, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            scanf("%d", &m[i][j]);
        }
    }
}

void imprime_matriz (int **m, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void desaloca_matriz (int ***m, int n) {
    for (int i=0; i<n; i++) {
        free((*m)[i]);
    }

    free(*m);
    *m = NULL;
}

int main () {
    int **mat;
    
    mat = aloca_matriz_quadratica(4);
    preenche_matriz(mat, 4);
    imprime_matriz(mat, 4);
    desaloca_matriz(&mat, 4);

    return 0;
}