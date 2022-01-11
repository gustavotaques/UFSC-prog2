#include "lista.h"

/**
 * arquivo lista.c
 * 
 * Implemente neste arquivo as funções especificadas em lista.h.
 * Não faça modificações nas estruturas de nó e lista fornecidas
 * Você pode implementar funções auxiliares além das fornecidas,
 * para isso, coloque o cabeçário da função no arquivo .h e sua
 * implementação aqui, no arquivo .c. Não altere assinaturas de
 * funções, caso contrário seu código receberá nota 0,0 (zero).
 */

// Estrutura de nó duplamente encadeado
struct no {
	tipo 		 info;		//Informação (dado) armazenada no nó
	struct no	*ant;		//Ponteiro para o nó anterior
	struct no	*prx;		//Ponteiro para o próximo nó
};

//Estrutura de lista duplamente encadeada com nós
struct lista {
	no_t 		*cabeca;	//Ponteiro para a cabeça da lista (primeiro)
	no_t 		*cauda;		//Ponteiro para a cauda da lista (último)
	int 		tamanho;	//Tamanho atual da lista
};

lista_t* lista_cria () {
	lista_t *lista;

	lista = (lista_t*) malloc(sizeof(lista_t));

	if (lista == NULL) return NULL;

	lista->tamanho = 0;
	lista->cabeca = NULL;
	lista->cauda = NULL;

	return lista;
}

void lista_destroi (lista_t **l) {
	if (!l) return;
	if (!(*l)) return;

	if ((*l)->cabeca == NULL) {
		free(*l);
		*l = NULL;

		return;
	}

	tipo d;

	while ((*l)->cabeca != NULL) {
		lista_remove_cabeca(*l, &d);
	}

	free(*l);

	*l = NULL;
}

int lista_inicializada (lista_t *l) {
	return l != NULL;
}

int lista_tamanho (lista_t *l) {
	if (l == NULL) return -1;

	return l->tamanho;
}

int lista_info_cabeca (lista_t *l, int *dado) {
	if (l == NULL) return -1;
	if (dado == NULL) return -1;
	if (l->tamanho == 0) return 0;

	*dado = l->cabeca->info;

	return 1;
}

int lista_info_cauda (lista_t *l, int *dado) {
	if (l == NULL) return -1;
	if (dado == NULL) return -1;
	if (l->tamanho == 0) return 0;

	*dado = l->cauda->info;

	return 1;
}

int lista_info_posicao (lista_t *l, int *dado, int pos) {
	if (l == NULL) return -1;
	if (dado == NULL) return -1;
	if (l->tamanho == 0) return 0;
	if (pos < 0 || pos >= l->tamanho) return 0;

	no_t *n;

	if (pos > l->tamanho / 2) {
		pos = l->tamanho - pos;
		n = l->cauda;
		
		while (--pos) n = n->ant;

	} else {
		n = l->cabeca;

		while (pos--) n = n->prx;
	}

	*dado = n->info;

	return 1;
}

int lista_insere_cabeca (lista_t *l, tipo dado) {
	if (l == NULL) return -1;

	no_t *n;
	n = (no_t*) malloc(sizeof(no_t));

	if (n == NULL) return -1;

	n->info = dado;
	n->ant = NULL;

	if (l->cabeca == NULL) {
		n->prx = NULL;
		l->cauda = n;
	} else {
		n->prx = l->cabeca;
		l->cabeca->ant = n;
	}

	l->cabeca = n;
	l->tamanho++;

	return 1;
}

int lista_insere_cauda (lista_t *l, tipo dado) {
	if (l == NULL) return -1;

	no_t *n;
	n = (no_t*) malloc(sizeof(no_t));

	if (n == NULL) return -1;

	n->info = dado;

	n->prx = NULL;
	n->ant = l->cauda;

	if (l->cabeca == NULL) {
		l->cabeca = n;
	} else {
		l->cauda->prx = n;
	}

	l->cauda = n;
	l->tamanho++;

	return 1;
}

int lista_insere_posicao (lista_t *l, tipo dado, int pos) {
	if (l == NULL) return -1;
	if (pos < 0 || pos > l->tamanho) return 0;

	no_t *n;
	int cont = 0;
	n = (no_t*) malloc(sizeof(no_t));

	if (n == NULL) return -1;

	n->info = dado;

	if (l->cabeca == NULL) {
		n->ant = NULL;
		n->prx = NULL;
		l->cabeca = n;
		l->cauda = n;
	} else {
		if (pos == l->tamanho) {
			n->ant = l->cauda;
			l->cauda->prx = n;
			n->prx = NULL;
			l->cauda = n;
		} else {
			n->prx = l->cabeca;

			if (pos == 0) {
				n->prx->ant = n;
				n->ant = NULL;
				l->cabeca = n;
			} else {
				while (cont++ != pos) {
					n->prx = n->prx->prx;
				}
				n->prx->ant->prx = n;
				n->ant = n->prx->ant;
				n->prx->ant = n;
			}
		}
	}

	l->tamanho++;
	return 1;
}

int lista_remove_cabeca (lista_t *l, tipo *dado) {
	if (l == NULL) return -1;
	if (dado == NULL) return -1;
	if (l->tamanho == 0) return 0;

	no_t *rem = l->cabeca;

	if (--l->tamanho) {
		l->cabeca = rem->prx;
		l->cabeca->ant = NULL;
	} else {
		l->cabeca = NULL;
		l->cauda = NULL;
	}

	rem->ant = NULL;
	rem->prx = NULL;

	*dado = rem->info;

	free(rem);

	return 1;
}

int lista_remove_cauda (lista_t *l, tipo *dado) {
	if (l == NULL) return -1;
	if (dado == NULL) return -1;
	if (l->tamanho == 0) return 0;

	no_t *rem = l->cauda;

	if (--l->tamanho) {
		l->cauda = rem->ant;
		l->cauda->prx = NULL;
	} else {
		l->cabeca = NULL;
		l->cauda = NULL;
	}

	rem->ant = NULL;
	rem->prx = NULL;

	*dado = rem->info;

	free(rem);

	return 1;
}

int lista_remove_posicao (lista_t *l, tipo *dado, int pos) {
	if (l == NULL) return -1;
	if (dado == NULL) return -1;
	if (l->tamanho == 0) return 0;
	if (pos < 0 || pos >= l->tamanho) return 0;

	no_t *rem;
	int cont = 0;

	if (pos >= l->tamanho / 2) {
		pos = l->tamanho - pos;
		cont = pos;

		rem = l->cauda;

		while (--cont) rem = rem->ant;

		if (pos == 1) {
			l->cauda = rem->ant;
			l->cauda->prx = NULL;
			rem->ant = NULL;
		} else {
			rem->ant->prx = rem->prx;
			rem->prx->ant = rem->ant;
			rem->ant = NULL;
			rem->prx = NULL;
		}
	} else {
		rem = l->cabeca;
		cont = pos;

		while (cont--) rem = rem->prx;

		if (pos == 0) {
			l->cabeca = l->cabeca->prx;
			rem->prx->ant = NULL;
			rem->prx = NULL;
		} else {
			rem->ant->prx = rem->prx;
			rem->prx->ant = rem->ant;
			rem->ant = NULL;
			rem->prx = NULL;
		}
	}

	*dado = rem->info;
	l->tamanho--;

	free(rem);

	return 1;
}

int lista_remove_primeira (lista_t *l, tipo dado) {
	if (l == NULL) return -1;
	if (l->cabeca == NULL) return -2;

	int cont = 0;
	no_t *aux;
	aux = l->cabeca;

	while (aux->info != dado) {
		if (aux->prx == NULL) return -2;

		aux = aux->prx;
		cont++;
	}

	if(cont == 0) {
		l->cabeca = l->cabeca->prx;

		if(l->cabeca == NULL) {
			l->cauda = NULL;
		} else {
			l->cabeca->ant = NULL;
		}
	} else if (cont == l->tamanho -1) {
		l->cauda = aux->ant;
		aux->ant->prx = NULL;
		aux->ant = NULL;
	} else {
		aux->ant->prx = aux->prx;
		aux->prx->ant = aux->ant;
		aux->ant = NULL;
		aux->prx = NULL;
	}

	free(aux);
	l->tamanho--;
	
	return cont;
}

int lista_remove_todas (lista_t *l, tipo dado) {
	if (l == NULL) return -1;

	int cont = 0;
	no_t *aux, *rem;
	aux = l->cabeca;

	while (aux != NULL) {
		if (aux->info == dado) {
			if (aux->ant == NULL && aux->prx == NULL) {
				l->cabeca = NULL;
				l->cauda = NULL;

				free(aux);
				cont++;
				l->tamanho--;

				break;
			}
			if (aux->ant == NULL) {
				aux = aux->prx;
				rem = aux->ant;
				l->cabeca = aux;
				rem->prx = NULL;
				aux->ant = NULL;

				free(rem);
				cont++;
				l->tamanho--;

				continue;
			}

			if (aux->prx == NULL) {
				aux = aux->ant;
				rem = aux->prx;
				l->cauda = aux;
				rem->ant = NULL;
				aux->prx = NULL;

				free(rem);
				cont++;
				l->tamanho--;

				break;
			}

			aux = aux->prx;
			rem = aux->ant;
			rem->ant->prx = aux;
			aux->ant = rem->ant;
			rem->ant = NULL;
			rem->prx = NULL;

			free(rem);
			cont++;
			l->tamanho--;

		} else {
			aux = aux->prx;
		}
	}

	return cont;
}

int lista_busca_info (lista_t *l, tipo dado) {
	if (l == NULL) return -1;
	if (l->cabeca == NULL) return -1;
	if (l->tamanho == 0) return -1;

	no_t *node = l->cabeca;
	int cont = 0;

	for (; node!=NULL; node=node->prx) {
		if (node->info == dado) return cont;
		cont++;
	}

	return -1;
}

int lista_frequencia_info (lista_t *l, tipo dado) {
	if (l == NULL) return -1;
	if (l->cabeca == NULL) return 0;

	no_t *node = l->cabeca;
	int cont = 0;

	for (; node!=NULL; node=node->prx){
		if (node->info == dado) cont++;
	}

	return cont;
}

int lista_ordenada (lista_t *l) {
	if (l == NULL) return -1;
	if (l->cabeca == NULL) return 1;

	no_t *node = l->cabeca;

	for (; node->prx!=NULL; node=node->prx){
		if (node->info > node->prx->info) return 0;
	}

	return 1;
}

int lista_insere_ordenado (lista_t *l, tipo dado) {
	if (l == NULL) return -1;

	no_t *node, *aux;
	node = (no_t*) malloc(sizeof(no_t));

	if (node == NULL) return -1;

	node->info = dado;

	if (l->cabeca == NULL) {
		l->cabeca = node;
		l->cauda = node;
		node->ant = NULL;
		node->prx = NULL;
	} else if (node->info <= l->cabeca->info) {
		node->prx = l->cabeca;
		l->cabeca->ant = node;
		node->ant = NULL;
		l->cabeca = node;
	} else if (node->info >= l->cauda->info){
		l->cauda->prx = node;
		node->prx = NULL;
		node->ant = l->cauda;
		l->cauda = node;
	} else {
		aux = l->cabeca;

		while (aux->prx && node->info >= aux->prx->info) {
			aux = aux->prx;
		}

		node->prx = aux->prx;
		aux->prx = node;
		node->ant = aux;
		node->prx->ant = node;
	}

	l->tamanho++;

	return 1;
}

int lista_compara(lista_t *l1, lista_t *l2) {
	if (l1 == NULL && l2 == NULL) return 1;
	if (l1 == NULL || l2 == NULL) return 0;
	if (l1->tamanho != l2->tamanho) return 0;
	if (l1->tamanho == l2->tamanho && l1->tamanho == 0) return 1;
	if (l1->cabeca->info == l2->cabeca->info && l1->tamanho == 1) return 1;

	no_t *aux1;
	no_t *aux2;
	aux1 = l1->cabeca;
	aux2 = l2->cabeca;

	while (aux1 != NULL) {
		if (aux1->info != aux2->info) return 0;
		aux1 = aux1->prx;
		aux2 = aux2->prx;
	}
	return 1;
}

int lista_reverte(lista_t *l) {
	if (l == NULL) return -1;
	if (l->cabeca == NULL) return 1;

	tipo aux;
	int start = 0, end = l->tamanho-1;
	no_t *ncab = l->cabeca;
	no_t *ncau = l->cauda;

	while (start < end) {
		aux = ncab->info;
		ncab->info = ncau->info;
		ncau->info = aux;

		start++;
		end--;

		ncab = ncab->prx;
		ncau = ncau->ant;
	}

	return 1;
}

lista_t* lista_cria_copia(lista_t *l) {
	if (l == NULL) return NULL;

	lista_t *copy_list;
	copy_list = lista_cria();

	if (copy_list == NULL) return NULL;

	no_t *aux;
	aux = l->cabeca;

	while (aux != NULL) {
		lista_insere_cauda(copy_list, aux->info);
		aux = aux->prx;
	}

	return copy_list;
}

int main () {
	lista_t *list;

	list = lista_cria();

	lista_insere_cauda(list, 1);
	lista_insere_cauda(list, 3);
	lista_insere_cauda(list, 5);
	// lista_insere_cauda(list, 7);

	printf("%d\n", lista_insere_ordenado(list, 10));

	lista_destroi(&list);

	return 0;
}