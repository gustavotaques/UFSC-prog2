#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char        dado;
    int         capacidade;
    struct no   *prx;
} no_t;

typedef struct pilha {
    int     tam;
	no_t    *topo;
} pilha_t;

int is_str_valid(char *p) {
    if (p == NULL) return 0;

    while (*p != 0) {
        if (!(isalpha(*p))) return 0;

        p++;
    }

    return 1;
}

int str_upper(char *p) {
    if (p == NULL) return 0;

    while (*p != 0) {
        if (islower(*p)) {
            *p = toupper(*p);
        }

        p++;
    }

    return 1;
}

pilha_t*    pilha_cria() {
    pilha_t *p = (pilha_t*) malloc(sizeof(pilha_t));
    if (p == NULL) return NULL;

    p->tam = 0;
    p->topo = NULL;

    return p;
}

void pilha_desempilha(pilha_t *p) {
    if (p == NULL) return;
    if (p->tam == 0) return;

    no_t *no = p->topo;
    p->topo = p->topo->prx;
    free(no);
    p->tam--;
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

int info_tamanho(pilha_t *p) {
    if (p == NULL) return -1;

    return p->tam;
}

int main () {
    int altura_max;
    int cont = 0;
    char str[100];
    int arr[100];

    pilha_t *terminal;

    scanf("%d", &altura_max);

    while (altura_max != 0) {
        scanf("%s", str);

        if (!(is_str_valid(str))) {
            scanf("%d", &altura_max);
            continue;
        }

        str_upper(str);

        terminal = pilha_cria();

        if (terminal == NULL) {
            scanf("%d", &altura_max);
            continue;
        }    

        for (int i=0; i<strlen(str); i++) {
            pilha_empilha(terminal, str[i], altura_max);
        }

        arr[cont++] = info_tamanho(terminal);

        pilha_destroi(&terminal);

        //---------------------
        scanf("%d", &altura_max);
    }

    for (int i=0; i<cont; i++) {
        if (i == cont - 1) {
            printf("%d", arr[i]);
        } else {
            printf("%d\n", arr[i]);
        }
    }

    return 0;
}