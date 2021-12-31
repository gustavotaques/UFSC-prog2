#include "pilha_interface.h"



pilha_t *pilha_cria(int cap, int tam_elemento, void (*imp)(const void *)){

	if(cap <= 0||tam_elemento <= 0){
		return NULL;
	}

	pilha_t *pilha;
	pilha = (pilha_t*) malloc(sizeof(pilha_t));

	if(pilha==NULL){
		return NULL;
	}
	
	pilha->elementos = (void *)malloc(tam_elemento*cap);
	if(pilha->elementos==NULL){
		free(pilha);
		return NULL;
	}
	pilha->imprime = imp;
	pilha->tamanho_elemento = tam_elemento;
	pilha->capacidade = cap;
	pilha->topo = 0;
	
	return pilha;
}

void pilha_destroi(pilha_t **p){

	if(p==NULL){
		return;
	}
	if(*p==NULL){
		return;
	}	 	  	 	    	   	     	    		   	       	 	

	free((*p)->elementos);
	free(*p);
	*p = NULL;
}

int pilha_vazia(pilha_t *p){

	if(p==NULL){
		return -1;
	}

	if(p->topo==0){
		return 1;
	}

	return 0;
}

int pilha_cheia(pilha_t *p){

	if(p==NULL){
		return -1;
	}

	if(p->topo==p->capacidade){
		return 1;
	}

	return 0;
}

int pilha_tamanho(pilha_t *p){

	if(p==NULL){
		return -1;
	}	 	  	 	    	   	     	    		   	       	 	

	return (p->topo);
}

/*
 * Empilha um novo elemento na pilha. O conteudo de "elem" eh copiado para dentro da pilha. Retorna 1 caso conseguir empilhar, 0 caso contrario
 * Pre: a pilha deve existir, nao deve estar cheia e "elem" deve ser valido
 * Pos: o elemento recebido pela operacao eh armazenado no topo da pilha
 */

int pilha_empilha(pilha_t *p, void *elem){
	
	if(p==NULL||elem==NULL){
		return 0;
	}

	if(p->topo==p->capacidade){
		return 0;
	}
	char *aux = (char *)p->elementos;
	
	memcpy(&aux[p->tamanho_elemento * p->topo], elem, p->tamanho_elemento);

	p->topo++;

	return 1; 
}

int pilha_desempilha(pilha_t *p, void *elem){

	if(p==NULL||elem==NULL){
		return 0;
	}

	if(p->topo==0){
		return 0;
	}	 	  	 	    	   	     	    		   	       	 	
	char *aux = (char *)p->elementos;
	memcpy(elem, &aux[p->tamanho_elemento * (p->topo-1)], p->tamanho_elemento);

	p->topo--;

	return 1;
}

int pilha_topo(pilha_t *p, void *elem){

	if(p==NULL||elem==NULL){
		return 0;
	}

	if(p->topo==0){
		return 0;
	}
	char *aux = (char *)p->elementos;
	memcpy(elem, &aux[p->tamanho_elemento *( p->topo-1)], p->tamanho_elemento);

	return 1;
}

void pilha_imprime(pilha_t *p){

	if(p==NULL){
		return;
	}
	
	if(p->imprime==NULL){
		return;
	}
	
	pilha_t *p1= pilha_cria(p->capacidade, p->tamanho_elemento,p->imprime);
	
	if(p1==NULL){	 	  	 	    	   	     	    		   	       	 	
	    return;
	}
	
    int num = p->topo;
    
    
    void * aux = (void*)malloc(p->tamanho_elemento) ;
    
    
	for(int i=0;i<num;i++){
	    
	    pilha_desempilha(p, aux);
	    
		pilha_empilha(p1, aux);
		
	}
	
	for(int i=0;i<num;i++){
	    
	    pilha_desempilha(p1, (void *)aux);
	    p->imprime(aux);
		pilha_empilha(p, (void*)aux);
		
	}
	
	pilha_destroi(&p1);
	free(aux);	
}	 	  	 	    	   	     	    		   	       	 	
