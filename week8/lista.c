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

// Coloque a partir daqui a implementação das funções