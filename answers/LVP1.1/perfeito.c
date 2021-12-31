#include "perfeito.h"

int numero_perfeito(int n){

    int i, soma;

    if(n != 1 && n != 0){
        soma = 0;
        for(i=1; i<n; i++){
            if(n % i == 0){
                soma = i + soma;
            }
        }
    }

    if(soma == n){
        return 1;
    }else if(soma != n){
        return 0;
    }

}


void encontra_perfeito(int min, int max, char vet[]){
    
    vet[0]='\0';
    //printf("%i ", min);
    //printf("%i ", max);

    int i;

    char vet_aux[40];
    
    vet_aux[0] = '\0';

    if(min > max){	 	  	 	      	   	  		 	      	   	 	
        return;
    }
    
    for(i=min; i<=max; i++){
        if(numero_perfeito(i) == 1 && i != 1){

            sprintf(vet_aux, "%i", i);
            strcat(vet, vet_aux);

            strcat(vet, ",");

            //cont = cont + 1;

            //vet[cont+1] = ',';
            //cont = cont +2;

        }
    }
    
	int j=0;
	
	while(vet[j] != '\0'){
		j++;

	}
    vet[j-1] = '\0';

}	 	  	 	      	   	  		 	      	   	 	
