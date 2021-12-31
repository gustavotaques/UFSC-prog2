//coloque aqui a implementacao do programa principale funcoes auxiliares

#include <stdio.h>
#include <stdlib.h>
#include "pilha_interface.h"
#include "lista_interface.h"

void imprime(const void *e) {
    printf(" %d", *(int *)e);
}

void lib(void *e) {
    if (e != NULL){
        pilha_t *p = (pilha_t *)e;
        pilha_destroi(&p);
        }
}

pilha_t * retorna_pilha_do_numero(int num, lista_t * l){
    
    pilha_t * pilha_importa, *paux, *p;
    
    paux=pilha_cria(l->tamanho, sizeof(int), NULL);
    if(paux==NULL){
        return NULL;
    }
    int achou=0, i, tam, elem;
    celula_t *c;
    c=lista_cabeca(l);
   while(achou==0 && c!=NULL){
        p = c->dado;
        tam = p->topo; 
        for(i=0;i<tam;i++){
            
            pilha_desempilha(p,&elem);
            
            if(elem==num){
                achou=1;
                pilha_importa=c->dado;
            }	 	  	 	    	   	     	    		   	       	 	
            
            pilha_empilha(paux, &elem);
            
        }
        
        for(i=0;i<tam;i++){
            pilha_desempilha(paux,&elem);
           
            pilha_empilha(p, &elem);
        }
            
        c=c->prox;
    }
    
    pilha_destroi(&paux);

 return pilha_importa; 
    
}

pilha_t * encontra_origem_do_numero(int num, lista_t *l){//DESTROIR NA FUNCAO QUE FOR CHAMADO
    
    pilha_t *p;
    int i, tam_lista;
    celula_t * c;
    
    
    tam_lista = lista_tamanho(l);
    
    if(num==(tam_lista-1)){
        c=lista_cauda(l);
        p=c->dado;
        return p;
    }
    
    c=lista_cabeca(l);
    
    for(i=0;i<num;i++){	 	  	 	    	   	     	    		   	       	 	
        c=c->prox;
    }
    
    p=c->dado;
    return p;  
}


int verifica_igualdade(pilha_t * a, int b){

	pilha_t * p=pilha_cria(a->topo,sizeof(int), NULL);
	
	int num=a->topo, i, elem, achou=0;
	
	for(i=0;i<num;i++){
	
		pilha_desempilha(a,&elem);
		if(elem==b){
			achou=1;
		}
		pilha_empilha(p,&elem);
	}
	
	for(i=0;i<num;i++){
	
		pilha_desempilha(p,&elem);
		pilha_empilha(a,&elem);
	}
	
	pilha_destroi(&p);
	if(achou==0){
		return 0;//diferenters
	}
	return 1;
}

void empilha_topo(int a,int b, lista_t *l){	 	  	 	    	   	     	    		   	       	 	

    pilha_t * pilha_a, *pilha_b, *paux;
    
    pilha_a = retorna_pilha_do_numero(a, l);
    pilha_b = retorna_pilha_do_numero(b, l);
    
    if(verifica_igualdade(pilha_a,b)==1){
        return;
    }
    paux = pilha_cria(l->tamanho, sizeof(int), NULL);
    int i=0, tam_a, elem, achou=0;
    tam_a = pilha_a->topo;
    
    while(achou==0){
        i++;
        pilha_desempilha(pilha_a,&elem);
        if(elem==a){
            achou = 1;
        }
        
        pilha_empilha(paux,&elem);
    }
    
    for(achou=0;achou<i;achou++){
        pilha_desempilha(paux,&elem);
        pilha_empilha(pilha_b,&elem);
        
    }
    
    pilha_destroi(&paux);

}

void empilha_sobre(int a,int b,lista_t *l){
    
    pilha_t * pilha_a, *pilha_b, *paux, *paux_b, *pilha_encontra;
    
    pilha_a = retorna_pilha_do_numero(a, l);
    pilha_b = retorna_pilha_do_numero(b, l);
    if(verifica_igualdade(pilha_a, b)==1){	 	  	 	    	   	     	    		   	       	 	
        return ;
    }
    paux = pilha_cria(l->tamanho, sizeof(int), NULL);
    paux_b = pilha_cria(l->tamanho, sizeof(int), NULL);
    
    int i=0, tam_a, elem, achou=0, j=0;
    tam_a = pilha_a->topo;
    
    while(achou==0){
        i++;
        pilha_desempilha(pilha_a,&elem);
        if(elem==a){
            achou = 1;
        }
        
        pilha_empilha(paux,&elem);
    }

    achou=0;
    while(achou==0){
        j++;
        pilha_desempilha(pilha_b,&elem);
        if(elem==b){
            achou = 1;
        }
        
        pilha_empilha(paux_b,&elem);
    }   
    
    pilha_desempilha(paux_b,&elem);
    pilha_empilha(pilha_b,&elem);
    
    for(achou=0;achou<j-1;achou++){
        
        pilha_desempilha(paux_b,&elem);
        pilha_encontra =  encontra_origem_do_numero(elem, l);
        pilha_empilha(pilha_encontra,&elem);
        
    }	 	  	 	    	   	     	    		   	       	 	
    
    for(achou=0;achou<i;achou++){
        
        pilha_desempilha(paux,&elem);
        pilha_empilha(pilha_b,&elem);
        
    }
    pilha_destroi(&paux);
    pilha_destroi(&paux_b);
}

void mova_sobre(int a,int b,lista_t *l){
    
    pilha_t * pilha_a,*pilha_b;
    pilha_a = retorna_pilha_do_numero(a, l);
    pilha_b = retorna_pilha_do_numero(b, l);
    
    if(verifica_igualdade(pilha_a,b)==1){
        return ;
    }
    
    pilha_t *paux, *pilha_encontra;
    paux = pilha_cria(l->tamanho,sizeof(int), NULL);
    
    int achou = 0, elem,i=0;
    while(achou==0){
        i++;
        pilha_desempilha(pilha_a,&elem);
        if(a==elem){
            achou=1;
        }
        pilha_empilha(paux,&elem);
    }
    
    pilha_desempilha(paux,&elem);
    pilha_empilha(pilha_a,&elem);
        
    int num = paux->topo;
    
    for(achou=0;achou<i-1;achou++){	 	  	 	    	   	     	    		   	       	 	
        pilha_desempilha(paux,&elem);
        pilha_encontra =  encontra_origem_do_numero(elem, l);
        pilha_empilha(pilha_encontra,&elem);
        
        
    }
    pilha_destroi(&paux);
    paux = pilha_cria(l->tamanho,sizeof(int), NULL);
    
    achou = 0;
    i=0;
    while(achou==0){
        i++;
        pilha_desempilha(pilha_b,&elem);
        if(b==elem){
            achou=1;
        }
        pilha_empilha(paux,&elem);
    }
    
    pilha_desempilha(paux,&elem);
    pilha_empilha(pilha_b,&elem);
        
    num = paux->topo;
    
    for(achou=0;achou<i-1;achou++){
        pilha_desempilha(paux,&elem);
        pilha_encontra =  encontra_origem_do_numero(elem, l);
        pilha_empilha(pilha_encontra,&elem);
        
        
    }
    pilha_destroi(&paux);
    
    pilha_desempilha(pilha_a,&elem);
    pilha_empilha(pilha_b,&elem);
    
    
}	 	  	 	    	   	     	    		   	       	 	

void mova_topo(int a,int b,lista_t *l) {
    
  pilha_t * pilha_a,*pilha_b;
  
    pilha_a = retorna_pilha_do_numero(a, l);
    pilha_b = retorna_pilha_do_numero(b, l);
    
    if(verifica_igualdade(pilha_a, b)!=1){
        pilha_t  *paux, *p_origem;
    
        paux = pilha_cria(l->tamanho, sizeof(int), NULL);
        
        
        int achou=0, elem;
        while(achou==0){
            pilha_desempilha(pilha_a,&elem);
            
            if(elem==a){
                achou=1;
            }
                pilha_empilha(paux,&elem);
        }
        
        pilha_desempilha(paux,&elem);
        pilha_empilha(pilha_b,&elem);
        
        int num = paux->topo;
        for(achou=0;achou<num;achou++){
            
            pilha_desempilha(paux,&elem);
           p_origem = encontra_origem_do_numero(elem, l);
           pilha_empilha(p_origem,&elem);
            
        }
        pilha_destroi(&paux);
        
        
    }	 	  	 	    	   	     	    		   	       	 	
    
}

int main(){

	int qtd_cont;
	scanf("%d", &qtd_cont);
	
	lista_t * plataforma = lista_cria((void*)pilha_imprime, lib, NULL);
	
	if(plataforma==NULL){
		return 0;
	}
	
	
	for(int i=0;i<qtd_cont;i++){
	
		pilha_t * pilha = pilha_cria(qtd_cont, sizeof(int), imprime);
		if(pilha==NULL){
			return 0;
		}
		
		insere_na_cauda(plataforma, (void *) pilha);
		pilha_empilha(pilha, (void*)&i);	
	}
	
	char comando1[9], comando2[9];
	int cont1, cont2;
	
	scanf("%s", comando1);
	
	while(comando1[0]!='s'){//while(strcmp(comando1,"sair")!=0){
		scanf("%d", &cont1);
		scanf("%s", comando2);
		scanf("%d", &cont2);
		
		if(cont1!=cont2){	 	  	 	    	   	     	    		   	       	 	
    				//printf("comando 1:%s  comando 2:%s\n", comando1,comando2);
	    		if(strcmp(comando1,"mova")==0 && strcmp(comando2,"sobre")==0){
	    			mova_sobre(cont1,cont2,plataforma);
	    
	    		}
	    	
	    		if(strcmp(comando1,"mova")==0 && strcmp(comando2,"topo")==0){
	    			mova_topo(cont1,cont2,plataforma);
	    		}
	    	
	    		if(strcmp(comando1,"empilhe")==0 && strcmp(comando2,"sobre")==0){
	    	
	    			empilha_sobre(cont1,cont2,plataforma);
	    		}
	    	
	    		if(strcmp(comando1,"empilhe")==0 && strcmp(comando2,"topo")==0){
	    			empilha_topo(cont1,cont2,plataforma);
	    		}
		
		}
		scanf("%s", comando1);
	
	}
	
	celula_t * cel = lista_cabeca(plataforma);
	pilha_t * p;
	for(int i=0;i<qtd_cont;i++){
	
		p = cel->dado;
		printf("%d:", i);
		pilha_imprime(p);
			
		cel = cel->prox;
		
		printf("\n");
				
	}	 	  	 	    	   	     	    		   	       	 	
	
	lista_destroi(&plataforma);
}
