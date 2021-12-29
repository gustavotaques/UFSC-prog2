#include "conjunto_privado.h"
#include <stdio.h>
#include <stdlib.h>

conjunto_t *conjunto_cria(void) {
    conjunto_t *p = NULL;
    
    p = (conjunto_t*) malloc(sizeof(conjunto_t));

    if (p == NULL) return NULL;

    p->vetor = (elem_t*) malloc(sizeof(elem_t) * ELEMENTOS);

    if (p->vetor == NULL) {
        free(p);
        return NULL;
    }

    p->numero = 0;
    p->capacidade = ELEMENTOS;

    return p;
}

void conjunto_destroi(conjunto_t **a) {
    if (!a) return;
    if (!(*a)) return;

    if ((*a)->vetor != NULL) free((*a)->vetor);

    free(*a);
    *a = NULL;
}

int conjunto_numero_elementos(conjunto_t *a) {
    if (a == NULL) return -1;

    return a->numero;
}

void conjunto_inicializa_vazio(conjunto_t *a) {
    if (a == NULL) return;

    a->numero = 0;
}

int conjunto_insere_elemento(elem_t x, conjunto_t *a) {
    if (a == NULL) return 0;

    if (a->numero == a->capacidade){
        a->vetor = (elem_t*) realloc(a->vetor, sizeof(elem_t) * a->capacidade * 2);
        if (a->vetor == NULL) return 0;
        a->capacidade *= 2;
    }
    a->vetor[a->numero] = x;
    a->numero++;

    return 1;
}

void conjunto_uniao(conjunto_t *a, conjunto_t *b, conjunto_t *c) {
    if (a == NULL || b == NULL || c == NULL) return;

    conjunto_inicializa_vazio(c);

    for (int i=0; i<a->numero; i++) {
        if (!(conjunto_membro(a->vetor[i], c))) {
            conjunto_insere_elemento(a->vetor[i], c);
        }
    }

    for (int i=0; i<b->numero; i++) {
        if (!(conjunto_membro(b->vetor[i], c))) {
            conjunto_insere_elemento(b->vetor[i], c);
        }
    }
}

void conjunto_interseccao(conjunto_t *a, conjunto_t *b, conjunto_t *c) {
    if (a == NULL || b == NULL || c == NULL) return;

    conjunto_inicializa_vazio(c);

    for (int i=0; i<a->numero; i++) {
        if (conjunto_membro(a->vetor[i], b)) {
            conjunto_insere_elemento(a->vetor[i], c);
        }
    }
}

void conjunto_diferenca(conjunto_t *a, conjunto_t *b, conjunto_t *c) {
    if (a == NULL || b == NULL || c == NULL) return;

    conjunto_inicializa_vazio(c);

    for (int i=0; i<a->numero; i++) {
        if (!(conjunto_membro(a->vetor[i], b))) {
            conjunto_insere_elemento(a->vetor[i], c);
        }
    }
    // for (int i=0; i<b->numero; i++) {
    //     if (!(conjunto_membro(b->vetor[i], a))) {
    //         conjunto_insere_elemento(b->vetor[i], c);
    //     }
    // }
}

int conjunto_membro(elem_t x, conjunto_t *a) {
    if (a == NULL) return 0;
    if (a->numero == 0) return 0;

    for (int i=0; i<a->numero; i++) {
        if (a->vetor[i] == x) return 1;
    }
    return 0;
}

void conjunto_remove_elemento(elem_t x, conjunto_t *a) {
    if (a == NULL) return;
    if (!(conjunto_membro(x, a))) return;

    for (int i=0; i<a->numero; i++) {
        if (a->vetor[i] == x) {
            for (int j=i+1; j<a->numero; j++) {
                a->vetor[j-1] = a->vetor[j];
            }
        }
    }
    a->numero--;
}

void conjunto_atribui(conjunto_t *a, conjunto_t *b) {
    if (a == NULL || b == NULL) return;

    conjunto_inicializa_vazio(b);

    for (int i=0; i<a->numero; i++) {
        conjunto_insere_elemento(a->vetor[i], b);
    }
}

int conjunto_igual(conjunto_t *a, conjunto_t *b) {
    if (a == NULL || b == NULL) return 0;
    if (a->numero != b->numero) return 0;
    if (a->capacidade != b->capacidade) return 0;


    for (int i=0; i<a->numero; i++) {
        if (!(conjunto_membro(a->vetor[i], b))) return 0;
    }
    return 1;
}

elem_t conjunto_minimo(conjunto_t *a) {
    if (a == NULL) return ELEM_MAX;
    if (a->numero == 0) return ELEM_MAX;

    if (a->numero == 1) return a->vetor[0];

    elem_t aux = a->vetor[0];

    for (int i=1; i<a->numero; i++) {
        if (a->vetor[i] < aux) aux = a->vetor[i];
    }    
    return aux;
}

elem_t conjunto_maximo(conjunto_t *a) {
    if (a == NULL) return ELEM_MIN;
    if (a->numero == 0) return ELEM_MIN;

    if (a->numero == 1) return a->vetor[0];

    elem_t aux = a->vetor[0];

    for (int i=1; i<a->numero; i++) {
        if (a->vetor[i] > aux) aux = a->vetor[i];
    }    
    return aux;
}

void conjunto_imprime(conjunto_t *a) {
    if (a == NULL) return;

    for (int i=0; i<(a->numero - 1); i++) printf("%d ", a->vetor[i]);

    printf("%d\n", a->vetor[a->numero - 1]);
}

int main () {
    conjunto_t *a;

    a = conjunto_cria();

    conjunto_insere_elemento(1, a);
    conjunto_insere_elemento(2, a);
    conjunto_insere_elemento(3, a);
    conjunto_insere_elemento(4, a);
    conjunto_insere_elemento(5, a);
    conjunto_insere_elemento(6, a);
    conjunto_insere_elemento(7, a);
    conjunto_insere_elemento(8, a);
    conjunto_insere_elemento(9, a);
    conjunto_insere_elemento(10, a);

    conjunto_remove_elemento(10, a);

    conjunto_imprime(a);

    conjunto_destroi(&a);

    return 0;
}