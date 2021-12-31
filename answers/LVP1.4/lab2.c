#include "lab2.h"

int quociente(int a, int b){
    int div;
    div = a / b;

    return div;

}

int resto(int a, int b){
    int resto, termo, div;

    div = a / b;

    termo = div * b;

    resto = a - termo;

    return resto;

}


char* separa(int numero){

    char vet_aux[6];
    int cont = 0, aux_numero, i, elevado = 1, aux_divisao, aux_resto, aux_cont, c = 1;

    char* intervalo=(char*)calloc(11,sizeof(char));

    aux_divisao = numero;
    aux_resto = numero;
    aux_numero = numero;

    intervalo[0] = '\0';


    while(aux_numero != 0){	 	  	 	      	   	  		 	      	   	 	
        aux_numero = aux_numero/10;
        cont = cont + 1;
    }
    //printf("%i\n", cont);

    aux_cont = cont;


    for(i=0; i<cont; i++){


        while(aux_cont != 1){
            elevado = elevado * 10;
            aux_cont = aux_cont - 1;
            c = c + 1;
        }
        //printf("ele:%i\n", elevado);

        aux_divisao = numero / elevado;
        aux_resto = numero % elevado;

        //printf("div:%i\n", aux_divisao);
        //printf("rest:%i\n", aux_resto);

        sprintf(vet_aux, "%i", aux_divisao);

        //printf("%s\n", vet_aux);

        strcat(intervalo, vet_aux);
        strcat(intervalo, " ");

        numero = aux_resto;
        aux_cont = c;
        aux_cont = aux_cont - 1;
        elevado = 1;
        c = 1;


    }	 	  	 	      	   	  		 	      	   	 	
    intervalo[(cont * 2) - 1] = '\0';

    //printf("\n\nIntervalo:%s\n\n", intervalo);
    return intervalo;

}