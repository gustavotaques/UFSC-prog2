#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int        dado;
    struct no   *ant;
    struct no   *prx;
} no_t;

typedef struct pilha {
    int tamanho;
	no_t    *base;
	no_t    *topo;
} pilha_t;


pilha_t** pilha_cria(int tam) {
    pilha_t **p = (pilha_t**) malloc(sizeof(pilha_t*) * tam);
    if (p == NULL) return NULL;

    for (int i=0; i<tam; i++) {
        p[i] = (pilha_t*) malloc(sizeof(pilha_t));

        if (i == tam-1) {
            p[i]->base = NULL;
            p[i]->topo = NULL;
            p[i]->tamanho = 0;

            continue;
        }
        
        no_t *aux = (no_t*) malloc(sizeof(no_t));
        aux->dado = i;

        p[i]->base = aux;
        p[i]->topo = aux;
        p[i]->tamanho = 1;
        aux->ant = NULL;
        aux->prx = NULL;
    }

    return p;
}

void empilha(pilha_t *p, no_t *valor) {
    if (p == NULL) return;
    if (valor == NULL) return;

    if (p->tamanho == 0) {
        p->topo = p->base = valor;
        p->tamanho++;
    } else {
        p->topo->prx = valor;
        valor->ant = p->topo;
        p->topo = valor;
        valor->prx = NULL;
        p->tamanho++;
    }
}

no_t* desempilha(pilha_t *p, int valor) {
    if (p->tamanho == 0) return NULL;

    no_t *aux;
    aux = p->topo;

    if (p->tamanho == 1) {
        p->topo = p->base = NULL;
        p->tamanho--;
    } else {
        p->topo = aux->ant;
        aux->ant->prx = NULL;
        p->tamanho--;
    }    

    return aux;
}

void pilha_destroi(pilha_t **m, int tam) {
    if (!m) return;
    if (!(*m)) return;

    for (int i=0; i<tam; i++) {
        while (m[i]->topo != NULL) {
            no_t *aux = desempilha(m[i], m[i]->topo->dado);
            free(aux);
        }
        free(m[i]);
    }

    free(m);
}

int procura_container(pilha_t **p, int tam, int container) {
    for (int i=0; i<tam; i++) {
        no_t *aux;
        aux = p[i]->base;

        while (aux != NULL) {
            if (aux->dado == container) return i;

            aux = aux->prx;
        }
    }

    return -1;
}

int main () {
    pilha_t **m;
    int a, b, n;
    char x[7], y[5];
    
    scanf("%d", &n);
    n++;

    scanf("%s", x);
    if (x[0] == 's') return 0;

    m = pilha_cria(n);

    scanf("%d", &a);
    scanf("%s", y);
    scanf("%d", &b);

    while (x[0] != 's') {
        int cont_a = procura_container(m, n, a);
        int cont_b = procura_container(m, n, b);

        if (a != b && cont_a != cont_b) {

            if (x[1] == 'o' && y[0] == 's') {

                while (m[cont_a]->topo->dado != a) {
                    no_t *container = desempilha(m[cont_a], m[cont_a]->topo->dado);
                    empilha(m[container->dado], container);
                }

                while (m[cont_b]->topo->dado != b) {
                    no_t *container = desempilha(m[cont_b], m[cont_b]->topo->dado);
                    empilha(m[container->dado], container);
                }

                no_t *aux = desempilha(m[cont_a], a);
                empilha(m[cont_b], aux);

            } else if (x[0] == 'm' && y[0] == 't') {
                
                while (m[cont_a]->topo->dado != a) {
                    no_t *container = desempilha(m[cont_a], m[cont_a]->topo->dado);
                    empilha(m[container->dado], container);
                }

                no_t *aux = desempilha(m[cont_a], a);
                empilha(m[cont_b], aux);
                
            } else if (x[1] == 'm' && y[0] == 's') {
                
                while (m[cont_b]->topo->dado != b) {
                    no_t *container = desempilha(m[cont_b], m[cont_b]->topo->dado);
                    empilha(m[container->dado], container);
                }

                while (m[cont_a]->topo->dado != a) {
                    no_t *container = desempilha(m[cont_a], m[cont_a]->topo->dado);
                    empilha(m[n-1], container);
                }

                no_t *aux = desempilha(m[cont_a], a);
                empilha(m[cont_b], aux);

                while (m[n-1]->topo != NULL) {
                    no_t *container = desempilha(m[n-1], m[n-1]->topo->dado);
                    empilha(m[cont_b], container);
                }
            
            } else {

                while (m[cont_a]->topo->dado != a) {
                    no_t *container = desempilha(m[cont_a], m[cont_a]->topo->dado);
                    empilha(m[n-1], container);
                }

                no_t *aux = desempilha(m[cont_a], a);
                empilha(m[cont_b], aux);

                while (m[n-1]->topo != NULL) {
                    no_t *container = desempilha(m[n-1], m[n-1]->topo->dado);
                    empilha(m[cont_b], container);
                }
            }
        }

        scanf("%s", x);
        if (x[0] == 's') break;

        scanf("%d", &a);
        scanf("%s", y);
        scanf("%d", &b);
    }

    for (int i=0; i<n-1; i++) {
        no_t *aux;
        aux = m[i]->base;
        int cont = 0;

        printf("%d:", i);

        while (m[i]->tamanho != cont) {
            printf(" %d", aux->dado);

            aux = aux->prx;
            cont++;
        }

        printf("\n");
    }

    pilha_destroi(m, n);

    return 0;
}