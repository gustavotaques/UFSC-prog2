#include "abb_privado.h"
#include "abb_privado.c"

abb_t* abb_cria() {
    abb_t *arv = (abb_t*) malloc(sizeof(abb_t));
    if (arv == NULL) return NULL;

    arv->raiz = NULL;

    return arv;
}

int abb_busca (abb_t *arv, elem_t chave) {
    if (arv == NULL) return -1;
    return abb_busca_rec(arv, arv->raiz, chave);
}

int abb_insere (abb_t *arv, elem_t chave) {
    if (arv == NULL) return -1;

    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return -1;
    novo->chave = chave;
    novo->dir = NULL;
    novo->esq = NULL;

    if (arv->raiz == NULL) {
        arv->raiz = novo;
    } else {
        no_t *atual = arv->raiz;
        no_t *aux = NULL;

        while (atual != NULL) {
            aux = atual;

            if (chave == atual->chave) {
                free(novo);
                return 0;
            }
            if (chave < atual->chave) {
                atual = atual->esq;
            } else {
                atual = atual->dir;
            }
        }
        if (chave < aux->chave) {
            aux->esq = novo;
        } else {
            aux->dir = novo;
        }
    }
    return 1;
}

int abb_remove (abb_t *arv, elem_t chave) {
    if (arv == NULL) return -1;
    if (arv->raiz == NULL) return -1;

    no_t *atual = arv->raiz;
    no_t *aux = NULL;

    while (atual != NULL) {
        if (chave == atual->chave) {
            if (atual == arv->raiz) {
                arv->raiz = abb_remove_no(atual);
            } else {
                if (aux->esq == atual) {
                    aux->esq = abb_remove_no(atual);
                } else {
                    aux->dir = abb_remove_no(atual);
                }
            }
            return 1;
        }
        aux = atual;

        if (chave < atual->chave) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
}

void abb_destroi (abb_t **arv) {
    if (arv == NULL) return;
    if (*arv == NULL) return;

    abb_destroi_rec((*arv)->raiz);

    free(*arv);

    arv = NULL;
}

int main () {
    abb_t *arvore = abb_cria();

    abb_insere(arvore, 10);
    abb_insere(arvore, 8);
    abb_insere(arvore, 9);
    abb_insere(arvore, 7);

    printf("%d", abb_busca(NULL, 6));

    abb_destroi(&arvore);

    return 0;
}