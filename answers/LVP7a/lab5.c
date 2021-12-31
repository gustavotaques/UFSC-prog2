#include "lab5.h"

// void retira(pilha_t *p, carro_t c, void (*saida)(carro_t *)){

//     int i=0;    
//     carro_t c1, aux;
//     pilha_t *p1 = pilha_cria(10, sizeof(carro_t),NULL);

//     pilha_topo(p, (void *)&c1);
    
//     if(p1==NULL){
//         return;
//     }
    
//     while(strcmp(c.placa,c1.placa) != 0 && (strlen(c.placa) != strlen(c1.placa))){
        
//         if(pilha_vazia(p))
//             break;
            
//         pilha_desempilha(p,&c1);
//         c1.manobras+=1;
        
//         if(strcmp(c.placa,c1.placa) != 0){
//             pilha_empilha(p1,&c1);
//             pilha_topo(p,&c1);
//         }
        
//         i=1;
//     }
//      printf("%s  c=%s\n", c1.placa, c.placa);
     
//     if(i==1){
//         //c1.manobras--;
//         pilha_desempilha(p, &aux);
//         printf("Saida: %s\n\n", aux.placa);
//         saida(&aux);
  
//         while(pilha_vazia(p1)!=1){	 	  	 	    	   	     	    		   	       	 	
//             pilha_desempilha(p1, &aux);
//             pilha_empilha(p,&aux);
//         }
        
//     }else{
//         //c1.manobras--;
//         pilha_desempilha(p,&aux);
//         saida(&aux);
//     }
    
    
//     free(p1);
    
// }

void retira(pilha_t *p, carro_t c, void (*saida)(carro_t *)){

    carro_t aux;
    pilha_t *p1 = pilha_cria(10, sizeof(carro_t),NULL);
    
    if(p1==NULL){
        return;
    }
    
    pilha_desempilha(p, (void*)&aux);
    
    
    while(pilha_vazia(p)==0){
        
        if(strcmp(aux.placa, c.placa)==0){
           saida(&aux);
           break;
        }
       
        pilha_empilha(p1, &aux);
        aux.manobras++;
        pilha_desempilha(p, &aux);
        
    }	 	  	 	    	   	     	    		   	       	 	
    while(pilha_vazia(p1)==0){
        pilha_desempilha(p1, &aux);    
        pilha_empilha(p, &aux);
    }

    pilha_destroi(&p1);
}


void estacionamento(const char *arquivo, void (*entrada)(carro_t *), void (*saida)(carro_t *)){
    
	if(arquivo==NULL||entrada==NULL||saida==NULL){
        return;
    }

    pilha_t * p = pilha_cria(10,sizeof(carro_t), NULL);
    
   if(p==NULL){
       return;
    }

    FILE * arq = fopen(arquivo,"r");
    if(!arq) return;

    carro_t carro1;
    carro_t carro2;
    char aux[2] = "\0";

    fscanf(arq,"%s",aux);
    
    while(aux[0]!='F'){
        
        if(aux[0] == 'E' && pilha_cheia(p)==1){
    		carro1.manobras = 0;
    		fscanf(arq,"%s",carro1.placa);

    		entrada(&carro1);
    		saida(&carro1);
    	}	 	  	 	    	   	     	    		   	       	 	

    	else if(aux[0] == 'E' && pilha_cheia(p)==0){
    		carro1.manobras = 0;
    		fscanf(arq,"%s",carro1.placa);
    		entrada(&carro1);
    		pilha_empilha(p, (void*)&carro1);
    	}

    	else if(aux[0] == 'S'){
    	   	fscanf(arq,"%s",carro1.placa);
    		retira(p,carro1,saida);
    	}
    	
    	fscanf(arq,"%s",aux);
    }
    


    fclose(arq);printf("fim");
    pilha_destroi(&p);
}
