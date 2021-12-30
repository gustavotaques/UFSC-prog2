#include "lista.h"

/**
 * arquivo lista.c
 * 
 * Implemente neste arquivo as funções especificadas em lista.h.
 * Não faça modificações nas estruturas fornecidas. Você pode 
 * implementar funções auxiliares além das fornecidas, para isso,
 * coloque o cabeçário da função no arquivo .h e sua implementação 
 * aqui, no arquivo .c. Não altere assinaturas de funções, caso 
 * contrário seu código receberá nota 0,0 (zero).
 */

//Estrutura de lista
struct lista {
	tipo 		*dados;		//Vetor que armazena os dados
	int 		capacidade; //Capacidade de armazenamento da lista
 	int 		tamanho;	//Tamanho atual da lista
};

lista_t* lista_cria (int capacidade) {
	lista_t *list = NULL;

	list = (lista_t*) malloc(sizeof(lista_t));

	if (list == NULL) return NULL;

	list->dados = (tipo*) malloc(sizeof(tipo) * capacidade);

	if (list->dados == NULL) {
		free(list);
		return NULL;
	}

	list->capacidade = capacidade;
	list->tamanho = 0;

	return list;
}

void lista_destroi (lista_t **l) {
	if (!l) return;
    if (!(*l)) return;

	if ((*l)->dados != NULL) free((*l)->dados);

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

int lista_capacidade (lista_t *l) {
	if (l == NULL) return -1;

	return l->capacidade;
}

int lista_cheia (lista_t *l) {
	if (l == NULL) return -1;
	if (l->tamanho == l->capacidade) return 1;

	return 0;
}

int lista_info_cabeca (lista_t *l, int *dado) {
	if (l == NULL) return -1;
	if (dado == NULL) return -1;
	if (l->tamanho == 0) return 0;

	*dado = l->dados[0];

	return 1;
}

int lista_info_cauda (lista_t *l, int *dado) {
	if (l == NULL) return -1;
	if (dado == NULL) return -1;
	if (l->tamanho == 0) return 0;

	*dado = l->dados[l->tamanho - 1];

	return 1;
}

int lista_info_posicao (lista_t *l, int *dado, int pos) {
	if (l == NULL) return -1;
	if (dado == NULL) return -1;
	if (l->tamanho == 0) return 0;

	if (!(pos >= 0 && pos < l->tamanho)) return 0;

	*dado = l->dados[pos];

	return 1;
}

int lista_insere_cabeca (lista_t *l, tipo dado) {
	if (l == NULL) return -1;
	if (l->tamanho == l->capacidade) return -1;

	for (int i=l->tamanho; i>0; i--) {
		l->dados[i] = l->dados[i-1];
	}

	l->dados[0] = dado;
	l->tamanho++;
	
	return 1;
}

int lista_insere_cauda (lista_t *l, tipo dado) {
	if (l == NULL) return -1;
	if (l->tamanho == l->capacidade) return -1;

	l->dados[l->tamanho] = dado;
	l->tamanho++;

	return 1;
}

int lista_insere_posicao (lista_t *l, tipo dado, int pos) {
	if (l == NULL) return -1;
	if (l->tamanho == l->capacidade) return -1;
	if (!(pos >= 0 && pos <= l->tamanho)) return 0;

	for (int i=l->tamanho; i>pos; i--) {
		l->dados[i] = l->dados[i-1];
	}

	l->dados[pos] = dado;
	l->tamanho++;
	
	return 1;
}

int lista_remove_cabeca (lista_t *l, tipo *dado) {
	if (l == NULL) return -1;
	if (dado == NULL) return -1;
	if (l->tamanho == 0) return 0;

	*dado = l->dados[0];

	if (l->tamanho == 1) {
		l->tamanho--;

		return 1;
	}

	for (int i=1; i<l->tamanho; i++) {
		l->dados[i-1] = l->dados[i];
	}

	l->tamanho--;

	return 1;
}

int lista_remove_cauda (lista_t *l, tipo *dado) {
	if (l == NULL) return -1;
	if (dado == NULL) return -1;
	if (l->tamanho == 0) return 0;

	*dado = l->dados[l->tamanho - 1];

	l->tamanho--;

	return 1;
}

int lista_remove_posicao (lista_t *l, tipo *dado, int pos) {
	if (l == NULL) return -1;
	if (dado == NULL) return -1;
	if (l->tamanho == 0) return 0;
	if (!(pos >= 0 && pos < l->tamanho)) return 0;

	*dado = l->dados[pos];

	for (int i=pos; i<l->tamanho-1; i++) {
		l->dados[i] = l->dados[i+1];
	}

	l->tamanho--;

	return 1;
}

int lista_remove_primeira (lista_t *l, tipo dado) {
	if (l == NULL) return -1;

	for (int i=0; i<l->tamanho; i++) {
		if (l->dados[i] == dado) {

			for (int j=i+1; j<l->tamanho; j++) {
				l->dados[j-1] = l->dados[j];
			}

			l->tamanho--;
			return i;
		}
	}
	return -2;
}

int lista_remove_todas (lista_t *l, tipo dado) {
	if (l == NULL) return -1;

	int cont = 0, i = 0;

	while (i < l->tamanho) {
		if (l->dados[i] == dado) {
			for (int j=i+1; j<l->tamanho; j++) {
				l->dados[j-1] = l->dados[j];
			}

			l->tamanho--;
			cont++;
			continue;
		}
		i++;
	}

	return cont;
}

int lista_busca_info (lista_t *l, tipo dado) {
	if (l == NULL) return -1;
	if (l->tamanho == 0) return -1;

	for (int i=0; i<l->tamanho; i++) {
		if (l->dados[i] == dado) return i;
	}

	return -1;
}

int lista_frequencia_info (lista_t *l, tipo dado) {
	if (l == NULL) return -1;

	int cont = 0;

	for (int i=0; i<l->tamanho; i++) {
		if (l->dados[i] == dado) cont++;
	}

	return cont;
}

int lista_ordenada (lista_t *l) {
	if (l == NULL) return -1;

	for (int i=1; i<l->tamanho; i++) {
		if (l->dados[i-1] > l->dados[i]) return 0;
	}

	return 1;
}

int lista_insere_ordenado (lista_t *l, tipo dado) {
	if (l == NULL) return -1;
	if (l->tamanho == l->capacidade) return -1;

	for (int i=0; i<l->tamanho; i++) {
		if (dado <= l->dados[i]) {
			lista_insere_posicao(l, dado, i);
			return 1;
		}
	}
	lista_insere_cauda(l, dado);
	
	return 1;
}

int lista_compara (lista_t *l1, lista_t *l2) {
	if (l1 == NULL && l2 == NULL) return 1;
	if (l1 == NULL || l2 == NULL) return 0;
	if (l1->dados == NULL || l2->dados == NULL) return 0;
	if (l1->tamanho != l2->tamanho) return 0;


	for (int i=0; i<l1->tamanho; i++) {
		if (l1->dados[i] != l2->dados[i]) {
			return 0;
		}
	}
	return 1;
}

int lista_reverte(lista_t *l) {
	if (l == NULL) return -1;

	int j = l->tamanho - 1;
	tipo aux;

	for (int i=0; i<l->tamanho; i++) {
		if (i < j) {
			aux = l->dados[i];
			l->dados[i] = l->dados[j];
			l->dados[j] = aux;

			j--;
			continue;
		}
		break;
	}

	return 1;
}

lista_t* lista_cria_copia(lista_t *l) {
	if (l == NULL) return NULL;

	lista_t *copia = lista_cria(l->capacidade);

	if (copia == NULL) return NULL;

	copia->tamanho = l->tamanho;

	for (int i=0; i<l->tamanho; i++) {
		copia->dados[i] = l->dados[i];
	}

	return copia;
}

int main () {
	return 0;
}