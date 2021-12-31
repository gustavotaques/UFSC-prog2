#include "pesquisa_privado.h"

/*
 * Implementa busca binaria para localizar dado em vetor, que devera estar ordenado. O numero de elementos em vetor eh especificado por tamanho.
 * O tamanho de cada elemento no vetor eh especificado por tamanho_elemento.
 * O ponteiro de funcao "comparar" especifica a funcao de comparacao definida pelo usuario: deve retornar -1 se "a" menor que "b", 0 se
 * forem iguais ou 1 se "a" maior que "b".
 * Pre-condicoes: o vetor e o dado a ser buscado devem ser validos.
 * Pos-condicoes: retorna o indice que possui o dado armazendo ou -1 caso nao encontrar
 */
int pesquisa_binaria(void *vetor, void *dado, int tamanho, int tamanho_elemento, int (*comparar) (const void *a, const void *b)){
    
    if(vetor == NULL || dado == NULL || comparar == NULL){
        return -1;
    }
    
    int i;
    
    for(i=0; i<tamanho; i++){
        
        if(comparar(vetor+(tamanho_elemento*i), dado) == 1){
            return -1;
        }
        if(comparar(vetor+(tamanho_elemento*i), dado) == 0){
            return i;
        }
    
        
    }
    return -1;
    
}	 	  	 	      	   	  		 	      	   	 	
