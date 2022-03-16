#include "funcao.h"
#include <ctype.h>
#include <stdlib.h>

int quicksort(int *v, unsigned int start, unsigned int end) {
    if (start < end) {
        int p = partition(v, start, end);
        quicksort(v, start, end - 1);
        quicksort(v, p + 1, end);
    }

    return 1;
}

int partition(int *v, unsigned int start, unsigned int end) {
    int esq, dir, pivo, aux;
    esq = start - 1;
    dir = end;
    pivo = v[start];

    while (esq < dir) {
        while (v[esq] <= pivo) esq++;
        while (v[dir] > pivo) dir--;

        if (esq < dir) {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[start] = v[dir];
    v[dir] = pivo;

    return dir;
}

int ordena(int *v, unsigned int t) {
    if (v == NULL || t == 0) return 0;

    return quicksort(v, 0, t);
}