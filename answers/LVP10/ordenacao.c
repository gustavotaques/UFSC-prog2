#include "ordenacao_privado.h"



/*
 * Implementa o algoritmo de ordenacao quicksort. Ordena o vetor de elementos em "vetor" de forma crescente. 
 * tamanho especifica o numero de elementos do vetor. tamanho_elemento especifica o tamanho de cada elemento.
 * Os argumentos inicio e fim definem a parte que esta sendo classificada (ordenada) no momeneto e inicialmente devem ser 0 e tamanho - 1.
 * O ponteiro de funcao "comparar" especifica a funcao de comparacao definida pelo usuario: deve retornar -1 se "a" menor que "b", 0 se
 * forem iguais ou 1 se "a" maior que "b".
 * Pre-condicoes: vetor a ser ordenado deve existir. A funcao de comparacao deve ser valida.
 * Pos-condicoes: o vetor estara ordenado de forma crescente apos a execucao da funcao. Retorna 1 caso conseguir ordenar, 0 caso contrario.
 */
int quicksort(void *vetor, unsigned int tamanho, unsigned int tamanho_elemento, unsigned int inicio, unsigned int fim, int (*comparar)(const void *a, const void *b)){

    if(vetor == NULL || comparar == NULL){
        return 0;
    }
    int p;
    
    if(inicio  == 0 && fim == -1){
        return -1;
    }
    
    if(fim>inicio){
        p = particiona(vetor, tamanho, tamanho_elemento, inicio, fim, comparar);
        quicksort(vetor, tamanho, tamanho_elemento, inicio, p-1, comparar);
        quicksort(vetor, tamanho, tamanho_elemento, p+1, fim, comparar);
    }
}
/*
 * Ordena de forma crescente a lista especificada em "l" usando o metodo de ordenacao bolha.
 * O ponteiro de funcao "comparar" especifica a funcao de comparacao definida pelo usuario que compara dois elementos armazenados na lista. 
 * Deve retornar -1 se "a" menor que "b", 0 se forem iguais ou 1 se "a" maior que "b".
 * Pre-condicoes: a lista deve existir e nao deve estar vazia
 * Pos-condicoes: a lista "l" estara ordenada apos a execucao da funcao. Retorna 1 caso conseguir ordenar, 0 caso contrario
 */
 
 
int particiona(void *vetor, unsigned int tamanho, unsigned int tamanho_elemento, unsigned int inicio, unsigned int fim, int (*comparar)(const void *a, const void *b)){

    void * pivo = malloc(tamanho_elemento);
    if(pivo==NULL){
        return -1;
    }
    memcpy(pivo,vetor+(tamanho_elemento*fim), tamanho_elemento);
    int i = inicio-1,j;
    void * aux = malloc(tamanho_elemento);
    if(aux==NULL){
        free(pivo);
        return-1;
    }
    for(j=inicio;j<fim;j++){
        if(comparar(vetor+(tamanho_elemento*j),pivo)==-1){
            i++;
            memcpy(aux,  vetor+(tamanho_elemento*j), tamanho_elemento);
            memcpy(vetor+(tamanho_elemento*j),  vetor+(tamanho_elemento*i), tamanho_elemento);
            memcpy(vetor+(tamanho_elemento*i), aux, tamanho_elemento);
        }	 	  	 	    	   	     	    		   	       	 	
    }
    
    if(comparar(vetor+(tamanho_elemento*fim),vetor+(tamanho_elemento*(i+1)))==-1){
        memcpy(aux,  vetor+(tamanho_elemento*fim), tamanho_elemento);
        memcpy(vetor+(tamanho_elemento*fim),  vetor+(tamanho_elemento*(i+1)), tamanho_elemento);
        memcpy(vetor+(tamanho_elemento*(i+1)), aux, tamanho_elemento);
    }
    free(pivo);
    free(aux);
    return i+1;
}



int bolha_lista(lista_t *l, int (*comparar)(const void *a, const void *b)){
    
    if(l == NULL || lista_tamanho(l) == 0 || comparar == NULL){
        return 0;
    } 
    
    if(lista_tamanho(l) == 1){
        return 1;
    }
    
    int teste = 1;
    celula_t *no1, *no2;

    while(teste != 0){
        teste = 0;
        no1 = lista_cabeca(l);
        no2 = lista_proximo(no1);
        
        while(no2 != NULL){
            if(comparar(lista_dado(no2), lista_dado(no1)) == -1){
                troca_no(l, no1, no2);
                no2 = lista_proximo(no1);
                teste = 1;
            }else{
                no1 = no2;
                no2 = lista_proximo(no1);
            }
            
            
        }
        
    }

}
//coloque a implementacao de quicksort e bolha aqui