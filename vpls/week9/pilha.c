#include "pilha.h"

struct no {
    char        dado;
    int         capacidade;
    struct no   *prx;
};

struct pilha {
    int     tam;
	no_t    *topo;
};

pilha_t*    pilha_cria() {
    pilha_t *p = (pilha_t*) malloc(sizeof(pilha_t));
    if (p == NULL) return NULL;

    p->tam = 0;
    p->topo = NULL;

    return p;
}

void        pilha_destroi(pilha_t **p) {
    if (!p) return;
    if (!(*p)) return;

    if ((*p)->topo == NULL) {
		free(*p);
		*p = NULL;

		return;
	}

    while ((*p)->topo != NULL) {
        pilha_desempilha(*p);
    }

    free(*p);

    p = NULL;
}

int         pilha_empilha(pilha_t *p, char elemento, int max_alt) {
    if (p == NULL) return 0;

    if (p->topo == NULL) {
        no_t *no = (no_t*) malloc(sizeof(no_t));
        if (no == NULL) return 0;

        no->dado = elemento;
        no->capacidade = 1;

        no->prx = NULL;
        p->topo = no;
        p->tam++;
    } else {
        no_t *aux;
        int cont = 0;
        aux = p->topo;

        while (aux != NULL) {
            if (elemento <= aux->dado && aux->capacidade < max_alt) {
                aux->dado = elemento;
                aux->capacidade++;
                cont++;
                break;
            }
            aux = aux->prx;
        }

        if (cont == 0) {
            no_t *no = (no_t*) malloc(sizeof(no_t));
            if (no == NULL) return 0;

            no_t *aux;
            aux = p->topo;

            while (aux->prx != NULL) {
                aux = aux->prx;
            }

            no->dado = elemento;
            no->capacidade = 1;

            aux->prx = no;
            no->prx = NULL;
            p->tam++;
        }
    }
    return 1;
}

void pilha_desempilha(pilha_t *p) {
    if (p == NULL) return;
    if (p->tam == 0) return;

    no_t *no = p->topo;
    p->topo = p->topo->prx;
    free(no);
    p->tam--;
}

int info_tamanho(pilha_t *p) {
    if (p == NULL) return -1;

    return p->tam;
}