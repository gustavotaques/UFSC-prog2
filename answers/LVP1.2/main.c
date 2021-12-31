#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int npalavras, j;

    printf("Numero de mensagens T: ");
    scanf("%i", &npalavras);
    
    

    for(j=0 ; j<npalavras ; j++){

        long long int codigo;

        char letras[27];

        printf("Ordem de atribuicao de letras em numeros: ");
        scanf("%s", letras);
        
        printf("Mensagem codificada: ");
        scanf("%lld", &codigo);
    
        printf("Mensagem decodificada: ");

        int let = 0;
        
        long long int variavelcodigo;

        variavelcodigo = codigo;

        while(variavelcodigo != 0){
            variavelcodigo = variavelcodigo / 100;
            let = let + 1;
        }	 	  	 	      	   	  		 	      	   	 	

        int cod[let+1], i;

        i = let;

        while(codigo != 0){
            cod[i-1] = codigo % 100;
            codigo = codigo / 100;
            i = i -1;

        }



        int x;
        
        
       
        for(i=0 ; i<let ; i++){
            x = cod[i];
            printf("%c", letras[x-1]);
        }
        
        printf("\n");
    }




}	 	  	 	      	   	  		 	      	   	 	