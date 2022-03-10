#include "abb_privado.h"

int abb_busca_rec (abb_t *arv, no_t *no, elem_t chave) {
    if (no == NULL) return 0;
    if (chave == no->chave) return 1;

    if (chave < no->chave) {
        return abb_busca_rec(arv, no->esq, chave);
    } else {
        return abb_busca_rec(arv, no->dir, chave);
    }
}

no_t* abb_remove_no (no_t *atual) {
    no_t *aux, *aux2;

    if (atual->esq == NULL) {
        aux = atual->dir;
        free(atual);

        return aux;
    }

    aux = atual;
    aux2 = atual->esq;
    while (aux2->dir != NULL) {
        aux = aux2;
        aux2 = aux2->dir;
    }

    if (aux != atual) {
        aux->dir = aux2->esq;
        aux2->esq = atual->esq;
    }

    aux2->dir = atual->dir;
    free(atual);

    return aux2;
}

void abb_destroi_rec (no_t *n) {
    if (n == NULL) return;

    abb_destroi_rec(n->esq);
    abb_destroi_rec(n->dir);
    free(n);
    n = NULL;
}