#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char jogada[6], aux[3];
    int contador = 0, local;

    int tabuleiro[3][3], linha, coluna, O = 1, X = 2;

    int i=0;
	jogada[0]='\0';
    tabuleiro[0][0] = 0;
    tabuleiro[0][1] = 0;
    tabuleiro[0][2] = 0;
    tabuleiro[1][0] = 0;
    tabuleiro[2][0] = 0;
    tabuleiro[1][1] = 0;
    tabuleiro[2][2] = 0;
    tabuleiro[1][2] = 0;
    tabuleiro[2][1] = 0;



    for(i=0 ; i<9 ; i++){

        scanf("%[^\n]%*c",jogada);
        setbuf(stdin, NULL);


        if(jogada[0] == 'O'){

            aux[0] = jogada[2];
            aux[1] = jogada[4];

            local = atoi(aux);

            linha = local/10;
            coluna = local%10;

            tabuleiro[linha-1][coluna-1] =O;



        }else if(jogada[0] == 'X'){	 	  	 	      	   	  		 	      	   	 	

            aux[0] = jogada[2];
            aux[1] = jogada[4];

            local = atoi(aux);

            linha = local/10;
            coluna = local%10;


            tabuleiro[linha-1][coluna-1] = X;

        }

        if((tabuleiro[0][0] == O) && (tabuleiro[1][0] == O) && (tabuleiro[2][0] == O)){
            printf("Jogador O ganhou.");
            i=10;

        }else if((tabuleiro[0][1] == O) && (tabuleiro[1][1] == O) && (tabuleiro[2][1] == O)){
            printf("Jogador O ganhou.");
            i=10;

        }else if((tabuleiro[0][2] == O) && (tabuleiro[1][2] == O) && (tabuleiro[2][2] == O)){
            printf("Jogador O ganhou.");
            i=10;

        }else if((tabuleiro[0][0] == O) && (tabuleiro[0][1] == O) && (tabuleiro[0][2] == O)){
            printf("Jogador O ganhou.");
            i=10;

        }else if((tabuleiro[1][0] == O) && (tabuleiro[1][1] == O) && (tabuleiro[1][2] == O)){
            printf("Jogador O ganhou.");
            i=10;

        }else if((tabuleiro[2][0] == O) && (tabuleiro[2][1] == O) && (tabuleiro[2][2] == O)){
            printf("Jogador O ganhou.");
            i=10;

        }else if((tabuleiro[0][0] == O) && (tabuleiro[1][1] == O) && (tabuleiro[2][2] == O)){	 	  	 	      	   	  		 	      	   	 	
            printf("Jogador O ganhou.");
            i=10;

        }else if((tabuleiro[0][2] == O) && (tabuleiro[1][1] == O) && (tabuleiro[2][0] == O)){
            printf("Jogador O ganhou.");
            i=10;

        }else if((tabuleiro[0][0] == X) && (tabuleiro[1][0] == X) && (tabuleiro[2][0] == X)){
            printf("Jogador X ganhou.");
            i=10;

        }else if((tabuleiro[0][1] == X) && (tabuleiro[1][1] == X) && (tabuleiro[2][1] == X)){
            printf("Jogador X ganhou.");
            i=10;

        }else if((tabuleiro[0][2] == X) && (tabuleiro[1][2] == X) && (tabuleiro[2][2] == X)){
            printf("Jogador X ganhou.");
            i=10;

        }else if((tabuleiro[0][0] == X) && (tabuleiro[0][1] == X) && (tabuleiro[0][2] == X)){
            printf("Jogador X ganhou.");
            i=10;

        }else if((tabuleiro[1][0] == X) && (tabuleiro[1][1] == X) && (tabuleiro[1][2] == X)){
            printf("Jogador X ganhou.");
            i=10;

        }else if((tabuleiro[2][0] == X) && (tabuleiro[2][1] == X) && (tabuleiro[2][2] == X)){
            printf("Jogador X ganhou.");
            i=10;

        }else if((tabuleiro[0][0] == X) && (tabuleiro[1][1] == X) && (tabuleiro[2][2] == X)){
            printf("Jogador X ganhou.");
            i=10;

        }else if((tabuleiro[0][2] == X) && (tabuleiro[1][1] == X) && (tabuleiro[2][0] == X)){	 	  	 	      	   	  		 	      	   	 	
            printf("Jogador X ganhou.");
            i=10;
        }

    }

    if(i==9){
        printf("Empate.");
    }

    return 0;
}