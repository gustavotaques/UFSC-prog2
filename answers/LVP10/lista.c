#include "lista_privado.h"


int insere_na_cabeca(lista_t *lista, void *elemento){
	if(lista==NULL||elemento==NULL){
	    return 0;
	}
	celula_t * nova_celula;
	
	nova_celula = (celula_t*) malloc(sizeof(celula_t));
	if(nova_celula==NULL){
		return 0;
	}
	nova_celula->dado = elemento;
	nova_celula->prox = lista->cabeca;
	nova_celula->ant=NULL;
	lista->cabeca = nova_celula;

	if(lista->tamanho!=0){
		nova_celula->prox->ant=nova_celula;
	}else{
		lista->cauda = nova_celula;
	}
	lista->tamanho++;
	return 1;
}

int insere_na_cauda(lista_t *lista, void * elemento){
	if(lista==NULL||elemento==NULL){
	    return 0;
	}
	celula_t * nova_celula;

	nova_celula = (celula_t*) malloc(sizeof(celula_t));
	if(nova_celula==NULL){
		return 0;
	}	 	  	 	    	   	     	    		   	       	 	

	nova_celula->dado = elemento;
	nova_celula->prox=NULL;
	nova_celula->ant=lista->cauda;
	lista->cauda = nova_celula;

	if(lista->tamanho!=0){
		nova_celula->ant->prox=nova_celula;
	}else{
		lista->cabeca = nova_celula;
	}
	lista->tamanho++;
	return 1;
}


lista_t *lista_cria(void (*imp)(const void *), void (*libera)(void *), int (*comparar)(const void *, const void *)){

	lista_t* l;
	l = (lista_t*) malloc(sizeof(lista_t));

	if(l==NULL){
    		return NULL;
	}
		l->tamanho = 0;
		l->cabeca=NULL;
		l->cauda=NULL;
		l->imprime = imp;
		l->destruir=libera;
		l->compara=comparar;

		return l;
}

void lista_destroi(lista_t **l){		 		
		 
    if(*l==NULL){	 	  	 	    	   	     	    		   	       	 	
        return; 
    }		
 		
    celula_t *aux, *cont;
    aux = (*l)->cauda;

    if((*l)->destruir==NULL){
        while(aux!=NULL){	
        cont = aux;
    	free(aux);
    	aux = cont->ant;
        }
    }else{
        while(aux!=NULL){	
        cont = aux;
    	(*l)->destruir(aux->dado);
    	free(aux);
    	aux = cont->ant;
        }        
    }
	free(*l);
	 *l=NULL;		 
}

int lista_vazia(lista_t *l){
	if(l==NULL){
		return -1;
	}
	if(l->tamanho==0){
		return 1;
	}
	return 0;
}

int lista_tamanho(lista_t *l){
	if(l==NULL){	 	  	 	    	   	     	    		   	       	 	
		return -1;
	}

	return(l->tamanho);
}

celula_t *lista_cabeca(lista_t *l){
	if(l==NULL){
		return NULL;
	}

	if(l->tamanho==0){
		return NULL;
	}

	return (l->cabeca);
}

celula_t *lista_cauda(lista_t *l){
	if(l==NULL){
		return NULL;
	}

	if(lista_vazia(l)==1){
		return NULL;
	}

	return (l->cauda);
}

void *lista_dado(celula_t *c){
	if(c==NULL){
		return NULL;
	}
	
	return(c->dado);
}	 	  	 	    	   	     	    		   	       	 	

celula_t *lista_proximo(celula_t *c){
	if(c==NULL){
		return NULL;
	}	
	
	return (c->prox);
}

celula_t *lista_anterior(celula_t *c){
	if(c==NULL){
		return NULL;
	}

	return(c->ant);
}

int lista_eh_cabeca(lista_t *l, celula_t *c){
	if(l==NULL){
		return -1;
	}
	if(c==NULL){
		return -1;
	}
	if(lista_vazia(l)==1){
		return -1;
	}
	if( (l->cabeca->dado==c->dado) && (l->cabeca->prox==c->prox) && (NULL==c->ant) ){
		return 1;
	}
	
	return 0;
}

int lista_eh_cauda(lista_t *l, celula_t *c){
	if(l==NULL){	 	  	 	    	   	     	    		   	       	 	
		return -1;
	}
	if(c==NULL){
		return -1;
	}
	if(lista_vazia(l)==1){
		return -1;
	}
	if( (l->cauda->dado==c->dado) && (c->prox==NULL) && (l->cauda->ant==c->ant) ){
		return 1;
	}
	return 0;
	
}
/*
 * Insere um elemento na lista imeadiamente apos um elemento determinado e recebido como parametro da funcao (celula "c").
 * Caso esse parametro seja invalido, insere o novo elemento na cabeca da lista. 
 * Retorna 1 caso conseguir inserir, 0 caso contrario
 * Pre: A lista e o novo elemento a ser inserido devem ser validos
 * Pos: O elemento recebido como parametro eh inserido logo apos a celula "c" ou na cabeca da lista
 */
int lista_insere_proximo(lista_t *l, celula_t *c, const void *elem){

	if(l==NULL||elem==NULL){
		return 0;
	}
	if(c==NULL||l->tamanho==0){
		return (insere_na_cabeca(l,(void*)elem));
	}

	if(c->prox==NULL){//ultimo elemento
		return (insere_na_cauda(l,(void*)elem));
	}

	celula_t * nova_celula;
	nova_celula = (celula_t*) malloc(sizeof(celula_t));

	if(nova_celula==NULL){	 	  	 	    	   	     	    		   	       	 	
		return 0;
	}

	nova_celula->dado = (void*)elem;
	nova_celula->prox=c->prox;
	c->prox->ant=nova_celula;
	nova_celula->ant=c;
	c->prox=nova_celula;
	l->tamanho++;

	return 1;
}

/*
 * Insere um elemento na lista imeadiamente antes a um elemento determinado e recebido como parametro da funcao (celula "c").
 * Caso esse parametro seja invalido, insere o novo elemento na cabeca da lista. 
 * Retorna 1 caso conseguir inserir, 0 caso contrario
 * Pre: A lista e o novo elemento a ser inserido devem ser validos
 * Pos: O elemento recebido como parametro eh inserido antes da celula "c" ou na cabeca da lista
 */
int lista_insere_anterior(lista_t *l, celula_t *c, const void *elem){

	if(l==NULL||elem==NULL){
		return 0;
	}
	if((c==NULL)||(l->tamanho==0)){
		return (insere_na_cabeca(l,(void*)elem));
	}
	if(c->ant==NULL){
		return(insere_na_cabeca(l,(void*)elem));
	}

	celula_t * nova_celula;
	nova_celula = (celula_t*) malloc(sizeof(celula_t));

	if(nova_celula == NULL){	 	  	 	    	   	     	    		   	       	 	
		return 0;
	}

	nova_celula->dado = (void*)elem;
	nova_celula->ant=c->ant;

    if(c->ant!=NULL){
    	c->ant->prox=nova_celula;
    }
	
	
	nova_celula->prox=c;
	c->ant=nova_celula;
	l->tamanho++;
	return 1;
}

int lista_insere_posicao(lista_t *l, const unsigned int posicao, const void *elem){
	
	if(l==NULL||elem==NULL){
		return 0;
	}
	
	if(l->tamanho<=posicao){
		return (insere_na_cauda(l,(void*)elem));
	}
	int i;
	int j=0;
	celula_t * aux;
	aux=l->cabeca;	
	for(i=0;i<posicao;i++){//aux sera o a celula proxima aonde vc quer inserir
		aux= aux->prox;
		j=1;
	}

	if(j==0){	 	  	 	    	   	     	    		   	       	 	
		return (insere_na_cabeca(l,(void*)elem));
	}

	celula_t * nova_celula;
	nova_celula = (celula_t*) malloc(sizeof(celula_t));

	if(nova_celula == NULL){
		return 0;
	}
	
	nova_celula->dado=(void*)elem;
	nova_celula->ant=aux->ant;
	aux->ant->prox=nova_celula;
	nova_celula->prox=aux;
	aux->ant=nova_celula;
	l->tamanho++;
	return 1;
}


/* 
 * Remove o elemento conhecido e recebido como parametro. Retorna o conteudo do elemento removido em uma variavel recebida como parametro. 
 * Retorna 1 caso conseguir remover, 0 caso contrario.
 * Pre: a lista deve existir e nao deve estar vazia, a celula a ser removida e a variavel recebida para armazenar o conteudo removido devem ser validas
 * Pos: a lista tera um elemento a menos e seu conteudo sera retornado dentro de uma variavel recebida como parametro
 * Retorna 1 caso conseguir remover, 0 caso contrario
 */

int lista_remove(lista_t *l, celula_t *c, void **elem){

	if(l==NULL||c==NULL||elem==NULL||l->tamanho==0){
		return 0;
	}

	*elem = c->dado;
	l->tamanho--;

	if(lista_eh_cabeca(l,c)==1){	 	  	 	    	   	     	    		   	       	 	
		c->prox->ant=NULL;
		l->cabeca=c->prox;
		l->destruir(c->dado);
		free(c);
		return 1;

	}
	if(lista_eh_cauda(l,c)==1){
		c->ant->prox=NULL;
		l->cauda=c->ant;
		free(c);
		return 1;
	}

	c->ant->prox = c->prox;
	c->prox->ant = c->ant;
	free(c);

	return 1;
}

void lista_imprime(lista_t *l){

	if(l==NULL||l->imprime==NULL){
		return;
	}
	celula_t *aux;
	aux = l->cabeca;
	while(aux!=NULL){
		l->imprime(aux->dado);
		aux=aux->prox;
	}

}

int lista_insere_ordenado(lista_t *l, const void *elem){	 	  	 	    	   	     	    		   	       	 	
    
	if(l==NULL||elem==NULL){
		return 0;
	}
	if(l->compara==NULL){
		return insere_na_cauda(l,(void*)elem);
	}
	if(l->cabeca == NULL){
	    return(insere_na_cabeca(l,(void*)elem));
	}
	
	celula_t *aux, *celula_ins;
	aux = l->cabeca;
	while(l->compara(elem,aux->dado)==1){
	    
		if(aux==l->cauda){
		    return (insere_na_cauda(l,(void*)elem));
		}
		aux = aux->prox;
	}

    return (lista_insere_anterior(l,aux,elem));
}

celula_t *lista_busca_recursiva(lista_t *l, const void *elem, celula_t *c){

	if(!l){
		return NULL;
	}
	if(c!=NULL){
		if(0==l->compara(c->dado,elem)){
			return c;
		}else{
			lista_busca_recursiva(l,elem,c->prox);
		}
	}else{	 	  	 	    	   	     	    		   	       	 	
		return NULL;
	}
}


lista_t *lista_separa(lista_t *l, const void *elem){

	if(l==NULL||elem==NULL){
		return NULL;
	}

	if(l->tamanho==1||l->tamanho==1){
		return NULL;
	}
	int i,h;
	celula_t *aux, *separa;
	aux=l->cabeca;
	for(i=0;i<l->tamanho;i++){
		if(elem==aux->dado){
			separa = aux;
			h = i+1;	
		}
		if(i!=l->tamanho){
			aux=aux->prox;
		}
		
	}

	lista_t *nova_lista;

	nova_lista = lista_cria(l->imprime,l->destruir,l->compara);

	nova_lista->cauda = l->cauda;
	nova_lista->cabeca = separa->prox;
	nova_lista->cabeca->ant = NULL;
	l->cauda = separa;
	l->cauda->prox = NULL;

	

	nova_lista->tamanho = l->tamanho-h;
	l->tamanho=h;
	
	return(nova_lista);
}	 	  	 	    	   	     	    		   	       	 	


lista_t *lista_concatena_e_destroi(lista_t **l1, lista_t **l2){

	if(!l1||!l2){
	    return NULL;	
	}

	if(!(*l1) ||!(*l2)){
		return NULL;	
	}
	
	if(lista_vazia(*l1) == 1 && lista_vazia(*l2)==1){
		return NULL;
	}
	
	lista_t *nova_lista;
	
	if(lista_vazia(*l1)==1 && lista_vazia(*l2)!=1){
	
		nova_lista = lista_cria( (*l2)->imprime, (*l2)->destruir, (*l2)->compara);
		
		nova_lista->cabeca=(*l2)->cabeca;
		nova_lista->cauda = (*l2)->cauda;
		nova_lista->tamanho = (*l2)->tamanho;
		
		lista_destroi(l2);
		lista_destroi(l1);
		
		*l1=NULL;
		*l2=NULL;
		
		return nova_lista;
	}
	
	if(lista_vazia(*l2)==1 && lista_vazia(*l1)!=1){	 	  	 	    	   	     	    		   	       	 	
	
		nova_lista = lista_cria( (*l1)->imprime, (*l1)->destruir, (*l1)->compara);
		
		nova_lista->cabeca=(*l1)->cabeca;
		nova_lista->cauda = (*l1)->cauda;
		nova_lista->tamanho = (*l1)->tamanho;
		
		lista_destroi(l2);
		lista_destroi(l1);
		
		*l1=NULL;
		*l2=NULL;
		
		return nova_lista;
	}
	nova_lista = lista_cria( (*l1)->imprime, (*l1)->destruir, (*l1)->compara);
	nova_lista->tamanho = (*l1)->tamanho + (*l2)->tamanho;
	nova_lista->cabeca = (*l1)->cabeca;
	nova_lista->cauda = (*l2)->cauda;
	
	(*l1)->cauda->prox = (*l2)->cabeca;
	(*l2)->cabeca->ant = (*l1)->cauda;
	
	
	free(*l2);
	free(*l1);
		
	*l1=NULL;
	*l2=NULL;
		
	return nova_lista;
    
}

void troca_no(lista_t *l, celula_t * p, celula_t * s){
    
    if(l==NULL || p==NULL || s==NULL){	 	  	 	    	   	     	    		   	       	 	
        return;
    }
    
    void * aux;
    
    aux = p->dado;
    p->dado = s->dado;
    s->dado = aux;
    
}


















	 	  	 	    	   	     	    		   	       	 	
