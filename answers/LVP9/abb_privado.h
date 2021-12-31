#ifndef _ABB_PRIV_H
#define _ABB_PRIV_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb_interface.h"

struct nodearv{
    void* info;

    node_t* esquerda;
    node_t* direita;
};

struct arvorebb{
    long tamanho;
    node_t* raiz;
    void (*destroi)(void **data);
    void (*imprime)(const void *data);
    int (*compara)(const void *key1, const void* key2); //Deve retornar -1 se o primeiro eh menor que o segundo, 0 se forem iguais, ou 1 se o primeiro for maior que o segundo
};


void destrui_rec(node_t * no, abb_t * a){

	if(no==NULL){
		return;
	}
	destrui_rec(no->esquerda, a);
	destrui_rec(no->direita, a);

	if(a->destroi!=NULL){
		a->destroi(&(no->info));
	}

	free(no);
	return; 
}	 	  	 	    	   	     	    		   	       	 	

node_t * acha_no_inserir(node_t * no, void *data, abb_t * a, int *confirma){

	if(no==NULL || data == NULL){
		return a->raiz; 
	}

	if(a->compara(data,no->info)==-1 && no->esquerda == NULL){
		return no;
	}

	if(a->compara(data,no->info)==1 && no->direita == NULL){
		return no;
	}

	if(a->compara(data,no->info)==-1){
		return acha_no_inserir(no->esquerda,data,a, confirma);
	}

	if(a->compara(data,no->info)==1){
		return acha_no_inserir(no->direita,data,a,confirma);
	}

	if(a->compara(data,no->info)==0){
		*confirma = 1;
		return NULL;
	}
	return NULL;

}

node_t * acha_no(node_t * no,const void * data, abb_t * a){

	if(data == NULL){
		return NULL; 
	}	 	  	 	    	   	     	    		   	       	 	

	if(no==NULL){
		return NULL; 
	}

	
	if(a->compara(data,no->info)==-1){
		return acha_no(no->esquerda,data,a);
	}

	if(a->compara(data,no->info)==1){
		return acha_no(no->direita,data,a);
	}
	
	if(a->compara(data,no->info)==0){
		return no;
	}
	return NULL;
}

bool busca_valor_na_arvore(node_t * no,void *dado, const abb_t* a){

	if(no==NULL || dado==NULL){
		return false;
	}
	
	if(a->compara(dado,no->info)==-1){
		return busca_valor_na_arvore(no->esquerda,dado,a);
	}

	if(a->compara(dado,no->info)==1){
		return busca_valor_na_arvore(no->direita,dado,a);
	}
	
	if(a->compara(dado,no->info)==0){
		return true;
	}	 	  	 	    	   	     	    		   	       	 	
	
	return false;

}

int altura_da_arvore(node_t * no){

	int esquerda,direita;
	if(no==NULL){
		return -1;	
	}

	
	esquerda = altura_da_arvore(no->esquerda);
	direita = altura_da_arvore(no->direita);

    	if (esquerda > direita){
    		return esquerda+1;
    	}else{
    		return direita+1;
    	}
   	
   	return 0;

}

node_t * acha_pai(node_t * raiz ,node_t * no, abb_t * a){

	if(raiz == NULL){
		return NULL; 
	}

	if(no==NULL){
		return NULL; 
	}
    int achou=0;
    node_t* pai=NULL;
    
    if (no == raiz) 
        return NULL;
    
    while (!achou) {	 	  	 	    	   	     	    		   	       	 	
        if(a->compara(raiz->info,no->info)==-1){
            if(raiz->direita==no){
                achou=1;
                pai = raiz;
            }else{
                raiz = raiz->direita;
            }
            
        }else if(a->compara(raiz->info, no->info)==1){
            
            if(raiz->esquerda==no){
                achou=1;
                pai = raiz;
            }else{
                raiz = raiz->esquerda;
            }
            
        }
    }
    
    return pai;
}

node_t * acha_ant(node_t * no, abb_t * a){
    
    if(no==NULL || a==NULL){
        return NULL;
    }
    
    node_t * ant = no->esquerda;
    if(ant==NULL){
        return NULL;
    }
    while(!ant->direita){
        ant=ant->direita;
    }	 	  	 	    	   	     	    		   	       	 	
    return ant;
}

node_t *retira_no(abb_t *arv, node_t *no){
    
    if(arv == NULL || no == NULL){
        return NULL;
    }
    
    node_t *no_aux1;
    node_t *no_aux2;
    
    if(no->esquerda == NULL){
        no_aux2 = no->direita;
        if(arv->destroi != NULL){
            arv->destroi(&no->info);
        }
        free(no);
        
        return no_aux2;
    }
    
    no_aux1 = no;
    no_aux2 = no->esquerda;
    
    while(no_aux2->direita != NULL){
        no_aux1 = no_aux2;
        no_aux2 = no_aux2->direita;
    }
    
    if(no_aux1 != no){
        no_aux1->direita = no_aux2->esquerda;
        no_aux2->esquerda = no->esquerda;
    }
    
    no_aux2->direita = no->direita;
    
    free(no);
    return no_aux2;
    
}



#endif


















