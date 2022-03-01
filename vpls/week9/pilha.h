#ifndef _pilha_h_
#define _pilha_h_

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha pilha_t;
typedef struct no no_t;

pilha_t*    pilha_cria();

void        pilha_destroi(pilha_t **p);

int         pilha_empilha(pilha_t *p, char elemento, int max_alt);

void         pilha_desempilha(pilha_t *p);

int         info_tamanho(pilha_t *p);

#endif