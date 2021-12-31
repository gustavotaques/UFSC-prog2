#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char lista[82], tabuleiro[9][9];
    int cont = 0, i, j, aux = 0, g = 1, n_sudoku = 1;
	     scanf("%s", lista);
    while(lista[0] != 's'){
  

        for(i=0; i<9; i++){
            for(j=0; j<9; j++){

                tabuleiro[i][j] = lista[aux];
                aux = aux + 1;
                //printf("%c ", tabuleiro[i][j]);
            }
            //printf("\n");
        }

        for(i=0; i<9; i++){
            for(j=0; j<9; j++){

                if(j != 0){
                    g = j + 1;
                }
                while(g < 9){
                    if(tabuleiro[i][j] == tabuleiro[i][g]&&j!=g){
                        cont = cont + 1;//printf("\ni:%c  g:%c",tabuleiro[j][i],tabuleiro[g][i]);

                    }
                g = g + 1;
                }

            }	 	  	 	      	   	  		 	      	   	 	
            g = 1;
        }



        g = 1;
        for(i=0; i<9; i++){
            for(j=0; j<9; j++){

                if(j != 0){
                    g = j + 1;
                }
                while(g < 9){
                    if(tabuleiro[j][i] == tabuleiro[g][i]&&i!=g){
                        cont = cont + 1;

                    }
                g = g + 1;
                }

            }
            g = 1;
        }

        if(cont == 0){
            printf("Sudoku %i correto.\n", n_sudoku);
        }else if(cont != 0){
            printf("Sudoku %i incorreto.\n", n_sudoku);

        }
        n_sudoku = n_sudoku + 1;



cont = 0;
lista[0]='\0';
     scanf("%s%*c", lista);
aux=0;
    }	 	  	 	      	   	  		 	      	   	 	
return 0;
}