//Seu programa para resolver o problema (incluindo uma main).

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int recurcao(char tabuleiro[10][11], int i, int j, int local){
		
	if(i < 0 || j < 0 || i > 10 || j > 10){
		return local;
	}
	
	

	if(tabuleiro[i+1][j] == ' '){
			
		tabuleiro[i+1][j] = '#';
		local = 1 + recurcao(tabuleiro, i+1, j, local);
	}
	
	if(tabuleiro[i-1][j] == ' '){
	
		tabuleiro[i-1][j] = '#';
		local = 1 + recurcao(tabuleiro, i-1, j, local);
		
	}
	
	if(tabuleiro[i][j+1] == ' '){
		
		tabuleiro[i][j+1] = '#';
		local = 1 + recurcao(tabuleiro, i, j+1, local);
			
	}
	
	if(tabuleiro[i][j-1] == ' '){
		
		tabuleiro[i][j-1] = '#';
		local = 1 + recurcao(tabuleiro, i, j-1, local);
		
	}	 	  	 	      	   	  		 	      	   	 	
	
	return local;	

	
}

int main(){

	char tabuleiro[10][11];
	int i = 0, j = 0, local = 1, cont = 0, resposta[30], aux = 0;
	
	
	for(i=0; i<10 ; i++){
		for(j=0 ; j<11 ; j++){
			scanf("%c", &tabuleiro[i][j]);
		}
	}
	
		for(i=0; i<10 ; i++){
		for(j=0 ; j<10 ; j++){
			printf("%c", tabuleiro[i][j]);
		}printf("\n");
	}
	
	
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			if(tabuleiro[i][j] == ' '){
				tabuleiro[i][j] = '#';
				printf("%i, %i\n", i, j);
				local = 1 + recurcao(tabuleiro, i, j, aux);
				cont = cont + 1;
				aux = 0;
			}
			resposta[cont - 1] = local;
			
		}	 	  	 	      	   	  		 	      	   	 	
	}
	
	int aux2 = 0;
	
	
	for(i=0; i<cont ; i++){
		for(j=1+i; j<cont ; j++){
			if(resposta[i] > resposta[j]){
				aux2 = resposta[i];
				resposta[i] = resposta[j];
				resposta[j] = aux2;
			
			}
			
		}
	}
	
	printf("O tabuleiro possui %i regioes, de tamanhos:\n", cont);
	
	
	
	for(i=0; i<cont; i++){
		printf("%i", resposta[i]);
		if(i < cont - 1){
			printf(",");
		}else if(i == cont-1){
			printf(".");
		}
	}

	if(cont == 0){
		printf(".");
	}
	
}	 	  	 	      	   	  		 	      	   	 	
