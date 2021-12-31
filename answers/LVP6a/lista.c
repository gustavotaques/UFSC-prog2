#include "lista_privado.h"

/*
 * Cria uma lista e a inicializa como lista vazia. 
 * "imp" eh um ponteiro para uma funcao de impressao dos dados armazenados dentro da lista. Deve ser usado em "lista_imprime". 
 * o argumento "libera" prove uma maneira de liberar dinamicamente os dados dentro da celula quando "lista_destroi" eh chamada. 
 * Para uma lista onde os dados nao devem ser liberados, libera deve ser NULL 
 * "comparar" eh um ponteiro para funcao de comparacao entre dois dados armazenados na lista. 
 * Deve retornar -1 se o primeiro eh menor que o segundo, 0 se forem iguais, ou 1 se o primeiro for maior que o segundo   
 * Pre: nenhuma
 * Pos: Retorna um ponteiro para uma lista vazia se houver memaria disponivel
 */
lista_t *lista_cria(void (*imp)(const void *), void (*libera)(void *), int (*comparar)(const void *, const void *)){
    
    lista_t* l;
    
    l = (lista_t*) malloc(sizeof(lista_t));
    
    if(l == NULL){
        return NULL;
    }
    
    l->tamanho = 0;
    l->cabeca = NULL;
    l->cauda = NULL;
    
    l->imprime = imp;
    l->destruir = libera;
    l->compara = comparar;
    
    return l;
}

/*
 * Destroi a lista especificada em "l". Nenhuma operacao eh permitida apos a funcao, a nao ser que lista cria seja chamada novamente. 
 * Destroi todos os elementos armazenados na lista se o ponteiro "destruir" for valido
 * Pre: "l" deve ser uma lista valida criada previamente atraves da funcao lista cria
 * Pos: os recursos da lista foram liberados com sucesso e a lista "l" torna-se nula
 */
void lista_destroi(lista_t **l){	 	  	 	      	   	  		 	      	   	 	
    
    if(*l == NULL){
        return;
    }
    
    celula_t *aux, *cabeca = (*l)->cabeca;
    void* elem;
    
    while(cabeca != NULL){
        
        lista_remove((*l), (*l)->cabeca, &elem);
        if((*l)->destruir != NULL){
            (*l)->destruir(elem);
        }
        cabeca = cabeca->prox;
           
    }
    
    free(*l);
    *l = NULL;
}

/*
 * Retorna 1 se a lista estiver vazia, 0 caso contrario
 * Pre: a lista deve existir
 * Pos: retorna 1 caso a lista estiver vazia, 0 se nao estiver. Retorna -1 caso a lista nao existir
 */
int lista_vazia(lista_t *l){
    
    if(l == NULL){
        return -1;
    }
    
    if(l->tamanho == 0){
        return 1;
    }	 	  	 	      	   	  		 	      	   	 	
    
    return 0;
    
}

/*
 * Retorna o tamanho da lista
 * Pre: a lista deve existir
 * Pos: retorna o tamanho da lista. Retorna -1 caso a lista nao existir
 */
int lista_tamanho(lista_t *l){
    
    if(l == NULL){
        return -1;
    }
    
    int tam;
    
    tam = l->tamanho;
    
    return tam;
    
}

/*
 * Retorna a celula cabeca da lista
 * Pre: a lista deve existir
 * Pos: retorna a celula cabeca da lista. Retorna NULL caso a lista estiver vazia ou nao existir
 */
celula_t *lista_cabeca(lista_t *l){
    
    if(l == NULL){
        return NULL;
    }
    
    if(l->tamanho == 0){	 	  	 	      	   	  		 	      	   	 	
        return NULL;
    }
    
    return(l->cabeca);
    
}

/*
 * Retorna a celula cauda da lista
 * Pre: a lista deve existir
 * Pos: retorna a celula cauda da lista. Retorna NULL caso a lista estiver vazia ou nao existir
 */
celula_t *lista_cauda(lista_t *l){
    
    if(l == NULL){
        return NULL;
    }
    
    if(l->tamanho == 0){
        return NULL;
    }
    
    return(l->cauda);
    
}

/*
 * Retorna o dado armazenado dentro da celula "c".
 * Pre: a celula deve existir
 * Pos: retorna o dado armazenado dentro de "c" ou NULL caso "c" for invalido
 */
void *lista_dado(celula_t *c){
    
    if(c == NULL){
        return NULL;
    }	 	  	 	      	   	  		 	      	   	 	
    
    return(c->dado);
}

/*
 * Retorna a celula que esta imediamente apos a celula recebida como parametro.
 * Pre: a celula deve existir
 * Pos: retorna a celula apos "c" ou NULL caso "c" for invalido
 */
celula_t *lista_proximo(celula_t *c){
    
    if(c == NULL){
        return NULL;
    }
    
    return(c->prox);
}

/*
 * Retorna a celula que esta imediamente antes a celula recebida como parametro.
 * Pre: a celula deve existir
 * Pos: retorna a celula que esta antes de "c" ou NULL caso "c" for invalido
 */
celula_t *lista_anterior(celula_t *c){
    
    if(c == NULL){
        return NULL;
    }
    
    return(c->ant);
}

/*
 * Retorna 1 caso a celula recebida como parametro for a celula cabeca da lista "l", 0 caso contrario.
 * Pre: a lista deve existir e a celula recebida como parametro deve ser valida
 * Pos: retorna 1 se "c" for cabeca de "l", 0 caso contrario. Retorna -1 se a lista "l" ou a celula "c" forem invalidas ou se a lista estiver vazia
 */
int lista_eh_cabeca(lista_t *l, celula_t *c){	 	  	 	      	   	  		 	      	   	 	
    
    if(l == NULL){
        return -1;
    }
    
    if(c == NULL){
        return -1;
    }
    
    if(l->tamanho == 0){
        return -1;
    }
    
    if(l->cabeca->dado == c->dado && c->ant == NULL){
        return 1;
    }
    
    return 0;
    
    
}

/*
 * Retorna 1 caso a celula recebida como parametro for a celula cauda da lista "l", 0 caso contrario.
 * Pre: a lista deve existir e a celula recebida como parametro deve ser valida
 * Pos: retorna 1 se "c" for cauda de "l", 0 caso contrario. Retorna -1 se a lista "l" ou a celula "c" forem invalidas ou se a lista estiver vazia
 */
int lista_eh_cauda(lista_t *l, celula_t *c){
    
    if(l == NULL){
        return -1;
    }
    
    if(c == NULL){
        return -1;
    }	 	  	 	      	   	  		 	      	   	 	
    
    if(l->tamanho == 0){
        return -1;
    }
    
    if(l->cauda->dado == c->dado && c->prox == NULL){
        return 1;
    }
    
    return 0;
}

int insere_na_cabeca(lista_t *l, void *elem){
    
    if(l == NULL){
        return 0;
    }
    
    if(elem == NULL){
        return 0;
    }
    
    celula_t *no, *aux;
    
    no = (celula_t*) malloc(sizeof(celula_t));
    
    if(no == NULL){
        return 0;
    }
    
    no->dado = elem;
    no->prox = l->cabeca;
    no->ant = NULL;
    l->cabeca = no;
    
    if(l->tamanho == 0){	 	  	 	      	   	  		 	      	   	 	
        l->cauda = no;
    }else{
        no->prox->ant = no;
    }
    
    l->tamanho++;
    return 1;
    
       
}

int insere_na_cauda(lista_t *l, void * elem){
     
    if(l == NULL){
        return 0;
    }
    
    if(elem == NULL){
        return 0;
    }
    
    celula_t *no, *aux;
    
    no = (celula_t*) malloc(sizeof(celula_t));
    
    if(no == NULL){
        return 0;
    }
    
    no->dado = elem;
    no->prox = NULL;
    no->ant = l->cauda;
    l->cauda = no;
    
    if(l->tamanho == 0){
        l->cabeca = no;
    }else{	 	  	 	      	   	  		 	      	   	 	
        no->ant->prox = no;
    }
    
    l->tamanho++;
    return 1;
    
    
}

/*
 * Insere um elemento na lista imeadiamente apos um elemento determinado e recebido como parametro da funcao (celula "c").
 * Caso esse parametro seja invalido, insere o novo elemento na cabeca da lista. 
 * Retorna 1 caso conseguir inserir, 0 caso contrario
 * Pre: A lista e o novo elemento a ser inserido devem ser validos
 * Pos: O elemento recebido como parametro eh inserido logo apos a celula "c" ou na cabeca da lista
 */
int lista_insere_proximo(lista_t *l, celula_t *c, const void *elem){
    
    if(l == NULL){
        return 0;
    }
    
    if(elem == NULL){
        return 0;
    }
    
    if(c == NULL || l->tamanho == 0){
        return(insere_na_cabeca(l, (void*)elem));
    }
    
    if(c->prox == NULL){
        return(insere_na_cauda(l, (void*)elem));
    }
    
    celula_t *no;
    
    no = (celula_t*) malloc(sizeof(celula_t));
    
    if(no == NULL){	 	  	 	      	   	  		 	      	   	 	
        return 0;
    }
    
    no->dado = (void*)elem;
    no->prox = c->prox;
    c->prox->ant = no;
    no->ant = c;
    c->prox = no;
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
    
    if(l == NULL || elem == NULL){
        return 0;
    }
    
    if((c == NULL) || (l->tamanho == 0)){
        return (insere_na_cabeca(l, (void*)elem));
    }
    
    
    
    celula_t *no;
    
    no = (celula_t*) malloc(sizeof(celula_t));
    
    if(no == NULL){	 	  	 	      	   	  		 	      	   	 	
        return 0;
    }
    
    if(c->ant == NULL){
        free(no);
        return(insere_na_cabeca(l, (void*)elem));
    }
    
    no->dado = (void*)elem;
    no->ant = c->ant;
    
    if(c->ant!=NULL){
    	c->ant->prox = no;
    }
    
    no->prox = c;
    c->ant = no;
    
    l->tamanho++;
    
    return 1;
    
}

/*
 * Insere um elemento na lista na posicao especificada por "posicao". Caso "posicao" seja maior que o tamanho da lista, insere o elemento na cauda da lista.
 * A ordem das posicoes da lista segue a mesma utilizada em vetores (0 eh equivalente a primeira posicao na lista, 1 a segunda e assim por diante)
 * Retorna 1 caso conseguir inserir, 0 caso contrario
 * Pre: A lista e o novo elemento a ser inserido devem ser validos
 * Pos: O elemento recebido como parametro eh inserido logo apos a celula "c" ou na cabeca da lista. Retorna 1 caso conseguir inserir, 0 caso contrario
 */
int lista_insere_posicao(lista_t *l, const unsigned int posicao, const void *elem){
    
    if(l == NULL || elem == NULL){
        return 0;
    }	 	  	 	      	   	  		 	      	   	 	
    
    if(posicao >= l->tamanho){
        return(insere_na_cauda(l, (void*)elem));
    }
    
    celula_t *no, *aux;
    
    no = (celula_t*) malloc(sizeof(celula_t));
    
    if(no == NULL){
        return 0;
    }
    
    int vazio = 0;
    aux = l->cabeca;
    
    for(int i=0; i<posicao; i++){
        aux = aux->prox;
        vazio = 1;
    }
    
    if(vazio == 0){
        free(no);
        return(insere_na_cabeca(l, (void*)elem));
    }
    no->dado = (void*)elem;
    
    no->ant = aux->ant;
    aux->ant->prox = no;
    no->prox = aux;
    aux->ant = no;
    
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
    
    if(l == NULL || lista_vazia(l) == 1){
        return 0;
    }
    
    if(c == NULL || *elem == NULL){
        return 0;
    }
    
    if(l->tamanho == 1){
        l->cauda = NULL;
        l->cabeca = NULL;
        *elem = (void*)c->dado;
        free(c);
        l->tamanho = 0;
        return 1;
    }
    
    if(lista_eh_cauda(l, c) == 1){
        *elem = (void*)c->dado;
        l->cauda = c->ant;
        c->ant->prox = NULL;
        free(c);
        l->tamanho--;
        return 1;
    }
    
    if(lista_eh_cabeca(l, c) == 1){	 	  	 	      	   	  		 	      	   	 	
        *elem = (void*)c->dado;
        l->cabeca = c->prox;
        c->prox->ant = NULL;
        free(c);
        l->tamanho--;
        return 1;
        
    }
    
    *elem = (void*)c->dado;
    c->ant->prox = c->prox;
    c->prox->ant = c->ant;
    l->tamanho--;
    free(c);
    
    return 1;
    
    
    
}

/*
 * Imprime os elementos da lista atraves do ponteiro de funcao "imprime", comecando pela cabeca da lista
 * Pre: a lista deve existir e o ponteiro "imprime" deve ser valido
 * Pos: Os elementos sao impressos usando o ponteiro "imprime"
 */
void lista_imprime(lista_t *l){
    
    if(l == NULL || l->imprime == NULL){
        return;
    }
    
    celula_t *no;
    
    no = l->cabeca;
    
    while(no != NULL){	 	  	 	      	   	  		 	      	   	 	
        l->imprime(no->dado);
        no = no->prox;
    }
    
    
}

/*
 * Insere um novo elemento na lista de forma ordenada (crescente). Caso o ponteiro "elem" tenha um valor igual a um elemento que estiver na lista, a insercao de "elem" deve ser feita logo apos.
 * Eh responsabilidade de quem chama o gerenciamento da memoria de "elem", onde ela devera permanecer valida enquanto estiver dentro da lista.
 * Caso o ponteiro de funcao "compara" for NULL, a insercao de "elem" deve ser feita na cauda da lista.
 * Retorna 1 caso conseguir inserir, 0 caso contrario
 * Pre: a lista deve existir e "elem" deve ser valido
 * Pos: o elemento recebido pela operacao eh inserido de forma ordenada (crescente)
 * OBS: considere que a lista ja esta ordenada, ou seja, nao precisa ordenar antes de usar a funcao
 */
int lista_insere_ordenado(lista_t *l, const void *elem){
    
    if(l == NULL || elem == NULL){
        return 0;
    }
    
    if(l->compara == NULL){
        return(insere_na_cauda(l,(void*)elem));
    }
    
    if(l->cabeca == NULL){
        return(insere_na_cabeca(l,(void*)elem));
    }
    
    celula_t *no, *aux;
    no = l->cabeca;
    
    while(l->compara(elem, no->dado) == 1){
        
        if(no == l->cauda){	 	  	 	      	   	  		 	      	   	 	
            return(insere_na_cauda(l,(void*)elem));
        }
        
        no = no->prox;
    }
    
    
    return(lista_insere_anterior(l, no, elem));
    
}

/*
 * Funcao recursiva que retorna a celula da lista que contem o elemento recebido como parametro. A comparacao deve ser feita usando ponteiros, e nao a funcao de comparacao internda da lista.
 * A celula "c" recebida deve ser usada para finalizar a recursao.
 * Pre: a lista, o elemento e a celula recebidas devem ser validas. A lista nao pode estar vazia
 * Pos: Retorna a celula que contem o elemento ou NULL caso o elemento nao estiver na lista recebida
 */
celula_t *lista_busca_recursiva(lista_t *l, const void *elem, celula_t *c){
    
    if(l == NULL || elem == NULL){
        return NULL;
    }
    
    if(c != NULL){
        if(l->compara(c->dado, elem) == 0){
            return c;
        }else{
         return(lista_busca_recursiva(l, elem, c->prox));  
        }
        
    
    }else{
        return NULL;
    }
    
}	 	  	 	      	   	  		 	      	   	 	

/*
 * Separa a lista recebida como parametro em duas, de tal forma que a segunda lista comece na primeira celula logo apos a celula que contem o elemento recebido como parametro.
 * A funcao deve retornar um ponteiro para a segunda sub-divisao da lista original, enquanto l deve continuar apontando para o primeiro elemento da primeira sub-divisao da lista.
 * Se o elemento recebido como parametro for NULL ou nao estiver na lista "l", a funcao nao faz nada e retorna NULL. 
 * A nova lista deve ter os mesmos ponteiros internos (imprime, compara e destruir) da lista "l"
 * Pre: lista deve existir e o elemento recebido como parametro deve ser valido
 * Pos: retorna um ponteiro para a nova lista que inicia logo apos a celula que contem "elem". Esta celula torna-se a cauda da lista "l". Retorna NULL caso nao conseguir separar a lista
 */
lista_t *lista_separa(lista_t *l, const void *elem){
    
    if(l == NULL || elem == NULL){
        return NULL;
    }
    
    if(l->tamanho == 1 || l->tamanho == 0){
        return NULL;
    }
    
    celula_t *aux, *nova;
    lista_t *new_l;
    int i;
    
    new_l = lista_cria(l->imprime,l->destruir,l->compara);
    
    aux = l->cabeca;
    
    int posicao = 0;
    
    for(i=0; i<l->tamanho; i++){
        
        if(aux->dado == elem){
            nova = aux;
            posicao = i + 1;
        }
        if(i != l->tamanho){	 	  	 	      	   	  		 	      	   	 	
            aux = aux->prox;
        }
    }
    
    
    new_l->cauda = l->cauda;
    new_l->cabeca = nova->prox;
    new_l->cabeca->ant = NULL;
    l->cauda = nova;
    l->cauda->prox = NULL;
    
    new_l->tamanho = l->tamanho - posicao;
    l->tamanho = posicao;
    return(new_l);
    
}

/*
 * Concatena duas listas recebidas como parametro e retorna a lista resultante da concatenacao.
 * Depois da funcao ser chamada, as listas "l1" e "l2" nao sao mais validas (serao destruidas) e suas celulas estarao dentro da lista retornada.
 * A nova lista deve ter os mesmos ponteiros internos (imprime, compara e destruir) da lista "l1" ou da lista "l2" se a "l1" for vazia
 * Pre: "l1" e "l2" devem ser listas validas (observe que elas podem ser vazias).
 * Pos: retorna uma nova lista contendo a concatenacao das duas listas recebidas como parametro. Retorna NULL caso nao conseguir concatenar as duas listas. 
 * Retorna NULL se ambas forem vazias (sem destrui-las). 
 * Apos a execucao, l1 e l2 nao sao mais listas validas e foram destruidas.
 */
lista_t *lista_concatena_e_destroi(lista_t **l1, lista_t **l2){
    
    if(l1 == NULL || l2 == NULL){
        return NULL;
    }
    
     if(*l1 == NULL || *l2 == NULL){
        return NULL;
    }
    
    if(lista_vazia(*l1) == 1 && lista_vazia(*l2)==1){	 	  	 	      	   	  		 	      	   	 	
		return NULL;
	}
    
    lista_t *l3;
    int i;
    
    if((*l1)->tamanho == 0 && (*l2)->tamanho != 0){
        
        l3 = lista_cria((*l2)->imprime,(*l2)->destruir,(*l2)->compara);
        l3->tamanho = (*l2)->tamanho;
        
        l3->cabeca = (*l2)->cabeca;
        l3->cauda = (*l2)->cauda;
        
        (*l2)->cabeca = NULL;
        (*l2)->cauda = NULL;
        
        lista_destroi(l1);
        
        free(*l1);
        free(*l2);
        
        *l1 = NULL;
        *l2 = NULL;
        
        return(l3);
        
    }
    
    if((*l2)->tamanho == 0 && (*l1)->tamanho != 0){
        
        l3 = lista_cria((*l1)->imprime,(*l1)->destruir,(*l1)->compara);
        l3->tamanho = (*l1)->tamanho;
        
        l3->cabeca = (*l1)->cabeca;
        l3->cauda = (*l1)->cauda;
        
        (*l1)->cabeca = NULL;
        (*l1)->cauda = NULL;
        
        lista_destroi(l2);
        
        free(*l1);
        free(*l2);
        
        *l1 = NULL;
        *l2 = NULL;
        
        return(l3);
        
    }	 	  	 	      	   	  		 	      	   	 	
    
    l3 = lista_cria((*l1)->imprime,(*l1)->destruir,(*l1)->compara);
    
    l3->tamanho = (*l1)->tamanho + (*l2)->tamanho;
    l3->cabeca = (*l1)->cabeca;
    l3->cauda = (*l2)->cauda;
    (*l1)->cauda->prox = (*l2)->cabeca;
    (*l2)->cabeca->ant = (*l1)->cauda;
    
    (*l1)->cabeca = NULL;
    (*l1)->cauda = NULL;
    (*l2)->cabeca = NULL;
    (*l2)->cauda = NULL;
    
    free(*l1);
    free(*l2);
        
    *l1 = NULL;
    *l2 = NULL;
    
    return(l3);
   
    
    
    
    
    
    
    
    
}
	 	  	 	      	   	  		 	      	   	 	
