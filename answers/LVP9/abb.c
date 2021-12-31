#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb_privado.h"


abb_t*      abb_criar       (void (*imprimir)(const void *data),
                             void (*destruir)(void **data),
                             int (*compara)(const void *key1, const void* key2)){

    if(compara == NULL){
        return NULL;
    }
    
    abb_t *arv;
    arv = (abb_t*) malloc(sizeof(abb_t));
    
    if(arv == NULL){
        return NULL;
    }
    
    arv->tamanho = 0;
    arv->raiz = NULL;
    arv->destroi = destruir;
    arv->compara = compara;
    arv->imprime = imprimir;

    return arv;                                 
}                            


abb_t*      abb_criar_de_vetor (void* vetor, int tamanho_vetor, int tamanho_elemento,
                             void (*imprimir)(const void *data),
                             void (*destruir)(void **data),
                             int (*compara)(const void *key1, const void* key2)){
                                 
        abb_t *a;
        int i;
        
        a = abb_criar(imprimir, destruir, compara);
        
        if(a == NULL){	 	  	 	      	   	  		 	      	   	 	
            return NULL;
        }
        
        for(i=0; i<tamanho_vetor; i++){
            abb_insere(a, vetor+(tamanho_elemento * i));
        }
        
        return a;
        
}


codigo_erro abb_destroi    (abb_t** arv){
    
    if(arv == NULL || (*arv)==NULL){
        return INVALIDO;
    }
    
    destrui_rec((*arv)->raiz, (*arv));
    free(*arv);
    *arv = NULL;
    return SUCESSO;
    
}


bool        abb_vazia       (const abb_t* arv){
    
    if(arv == NULL){
        return true;
    }
    
    if(arv->tamanho == 0){
        return true;
    }
    
    return false;
}	 	  	 	      	   	  		 	      	   	 	

long        abb_tamanho     (const abb_t* arv){
    
    if(arv == NULL){
        return -1;
    }
    
    return(arv->tamanho);
}

codigo_erro abb_insere      (abb_t* arv, void* data){
    
    if(arv == NULL || data == NULL){
        return INVALIDO;
    }
    
    if(arv->compara == NULL){
        return ESTADO_INVALIDO;
    }
    
    if(arv->tamanho == 0){
        
        node_t *no;
        no = (node_t*) malloc(sizeof(node_t));
        
        if(no == NULL){
            return INVALIDO;
        }
        
        no->info = data;
        no->direita = NULL;
        no->esquerda = NULL;
        arv->raiz = no;
        arv->tamanho++;
        
        return SUCESSO;
    }	 	  	 	      	   	  		 	      	   	 	
    
    int correto;
    
    node_t *no_test;
    
    no_test = acha_no_inserir(arv->raiz, data, arv, &correto);
    
    if(no_test == NULL && correto == 1){
        return DUPLICADO;
    }
    
    node_t *no;
    no = (node_t*) malloc(sizeof(node_t));
    
    if(no == NULL){
        return INVALIDO;
    }
    
    no->info = data;
    no->direita = NULL;
    no->esquerda = NULL;
    
    if(arv->compara(data, no_test->info) == -1){
        no_test->esquerda = no;
    }
    
    if(arv->compara(data, no_test->info) == 1){
        no_test->direita = no;
    }
    
    arv->tamanho++;
    
    return SUCESSO;
    
}

codigo_erro abb_remove(abb_t* arv, const void* data){	 	  	 	      	   	  		 	      	   	 	

	if(arv == NULL || arv->tamanho == 0){
		return UNDER_FLOW;
	}

	if(data == NULL){
		return VALOR_INVALIDO;
	}

	if(arv->compara == NULL){
		return INVALIDO;
	}


	node_t *no = NULL;
	node_t *aux = arv->raiz;

	while(aux != NULL){
	
		if(arv->compara(data, aux->info) == -1){
			no = aux;
			aux = aux->esquerda;

		}else if(arv->compara(data, aux->info) == 1){
			no = aux;
			aux = aux->direita;

		}else if(arv->compara(data, aux->info) == 0){
			if(aux == arv->raiz){
				arv->raiz = retira_no(arv, aux);
			}else if(no->direita == aux){
				no->direita = retira_no(arv, aux);
			}else{
				no->esquerda = retira_no(arv,aux);
			}
        
        arv->tamanho--;
		return SUCESSO;
		}	 	  	 	      	   	  		 	      	   	 	
		
	}

	return VALOR_INVALIDO;
	

}





bool        abb_busca_bin   (const abb_t* arv, void* info){
    
    if(arv == NULL || info == NULL){
        return false;
    }
    
    return busca_valor_na_arvore(arv->raiz, info, arv);
    
}

const node_t*     abb_raiz(const abb_t* arv){
    
    if(arv == NULL || arv->tamanho == 0){
        return NULL;
    }
    
    return arv->raiz;
    
}

const node_t*     abb_esq(const node_t* raiz){
    
    if(raiz == NULL || raiz->esquerda == NULL){
        return NULL;
    }	 	  	 	      	   	  		 	      	   	 	
    
    return raiz->esquerda;
    
}

const node_t*     abb_dir(const node_t* raiz){
    
    if(raiz == NULL || raiz->direita == NULL){
        return NULL;
    }
    
    return raiz->direita;
    
}

const void* 	  abb_info(const node_t* node){
    
    if(node == NULL){
        return NULL;
    }
    
    return node->info;
}

bool        abb_node_ehfolha(const node_t* node){
    
    if(node == NULL){
        return true;
    }
    
    if(node->esquerda == NULL && node->direita == NULL){
        return true;
    }
    
    return false;
    
    
}	 	  	 	      	   	  		 	      	   	 	

codigo_erro abb_altura(abb_t* arv, unsigned long *altura){
    
    if(altura == NULL){
        return INVALIDO;
    }
    
    if(arv == NULL){
        *altura = 0;
        return INVALIDO;
    }
    
    if(arv->tamanho == 0){
        *altura = 0;
        return INVALIDO;
    }
    
    *altura = altura_da_arvore(arv->raiz);
    
    return SUCESSO;
    

    
}
	 	  	 	      	   	  		 	      	   	 	
