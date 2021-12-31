#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//teste | ooo o  |

int main()
{
    char fita[11], palavra[100];
    int i, fita_int[11], j=0, soma = 0, ajuda = 0, ordem_letra = -1;


    fita[0] = '\0';

    while(fita[0] != '-' || ajuda == 0 || ajuda == 1){
        ajuda = ajuda + 1;
        scanf("%[^\n]%*c", fita);
        setbuf(stdin, NULL);

        if(fita[0] != '-'){
            ordem_letra = ordem_letra + 1;
        }

        for(i=0; i<10; i++){
        if(fita[i] == 'o'){
            fita_int[i] = 1;
        }else if(fita[i] == '|'){
            fita_int[i] = 2;
        }else if(fita[i] == ' '){
            fita_int[i] = 0;
        }
        }

        /*
        for(i=0; i<10; i++){
            printf("%i,", fita_int[i]);
        }	 	  	 	      	   	  		 	      	   	 	
        */

        for(i=0; i<10; i++){
            if(fita_int[i] == 1){
                j = i;

                i = 8 - i;
                soma = soma + pow(2,i);

                i = j;

            }
        }
        //printf("soma: %i\n", soma);


        palavra[ordem_letra] = soma;
        soma = 0;
    }




    palavra[ordem_letra] = '\0';

    printf("%s\n", palavra);


    return 0;
}