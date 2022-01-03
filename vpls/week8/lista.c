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

	no_t *node;
	*dado = l->cabeca->info;

	int cont = 0;

}

int main () {
	return 0;
}