#include <stdio.h>
#include <string.h>

#ifndef funcao_h
#define funcao_h

//Declare funcoes adicionais aqui


/* Ordena
 *		Implementa um algoritmo de ordenacao qualquer (voce escolhe).
 *			Retorna 1, caso seja possivel ordenar o vetor
 *			Retorna 0, caso o vetor (v == NULL) ou tamanho seja invalido (t == 0)
 *		Ao final o vetor v, de tamanho t, estara ordenado.
 */
int ordena(int *v, unsigned int t);

int quicksort(int *v, unsigned int min, unsigned int max);

int partition(int *v, unsigned int start, unsigned int end);

#endif
