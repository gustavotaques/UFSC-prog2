#include <stdio.h>
#include <stdlib.h>


int main()
{
    int  i, j, aux_jogada, linha, sentido, coluna, barcos[10] = {5, 4, 4, 3, 3, 3, 2, 2, 2, 2}, tam_barco;
    int nerro = 0, nacerto = 0, ntiro = 0, bA = 0, bB = 0, bC = 0, bD = 0, bE = 0, bF = 0, bG = 0, bH = 0, bI = 0, bJ = 0, barcos_derrubados[4] = {0, 0, 0, 0};
    int mult, soma, aux_jogada2;
    char tabuleiro[10][10], jogada[7];

    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            tabuleiro[i][j] = '0';
        }
    }

    for(i=0; i<10; i++){

        scanf("%[^\n]*c ", jogada);
        setbuf(stdin, NULL);
        jogada[1] = '7';
        jogada[3] = '7';

        //aux_jogada = atoi(jogada);

        if(jogada[2] == 'A'){
            linha = 1;
        }else if(jogada[2] == 'B'){
            linha = 2;
        }else if(jogada[2] == 'C'){
            linha = 3;
        }else if(jogada[2] == 'D'){
            linha = 4;
        }else if(jogada[2] == 'E'){
            linha = 5;
        }else if(jogada[2] == 'F'){	 	  	 	      	   	  		 	      	   	 	
            linha = 6;
        }else if(jogada[2] == 'G'){
            linha = 7;
        }else if(jogada[2] == 'H'){
            linha = 8;
        }else if(jogada[2] == 'I'){
            linha = 9;
        }else if(jogada[2] == 'J'){
            linha = 10;
        }

        if(jogada[0] == 'H'){
            sentido = 0;
        }else if(jogada[0] == 'V'){
            sentido = 1;
        }

        jogada[0] = '7';
        jogada[2] = '7';



        if(jogada[6] == ' '){

            aux_jogada = atoi(jogada);
            aux_jogada2 = aux_jogada;

            mult = aux_jogada / 100;
            coluna = aux_jogada2 - (mult*100);

        }else{

            aux_jogada = atoi(jogada);
            aux_jogada2 = aux_jogada;

            mult = aux_jogada / 10;
            coluna = aux_jogada2 - (mult*10);

        }	 	  	 	      	   	  		 	      	   	 	

        tam_barco = barcos[i];

        if(i == 0){
            if(sentido == 0){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'A';
                    coluna++;
                }
            }else if(sentido == 1){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'A';
                    linha++;
                }
            }
        }else if(i == 1){
            if(sentido == 0){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'B';
                    coluna++;
                }
            }else if(sentido == 1){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'B';
                    linha++;
                }
            }
        }else if(i == 2){
            if(sentido == 0){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'C';
                    coluna++;
                }
            }else if(sentido == 1){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'C';
                    linha++;
                }	 	  	 	      	   	  		 	      	   	 	
            }
        }else if(i == 3){
            if(sentido == 0){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'D';
                    coluna++;
                }
            }else if(sentido == 1){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'D';
                    linha++;
                }
            }
        }else if(i == 4){
            if(sentido == 0){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'E';
                    coluna++;
                }
            }else if(sentido == 1){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'E';
                    linha++;
                }
            }
        }else if(i == 5){
            if(sentido == 0){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'F';
                    coluna++;
                }
            }else if(sentido == 1){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'F';
                    linha++;
                }	 	  	 	      	   	  		 	      	   	 	
            }
        }else if(i == 6){
            if(sentido == 0){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'G';
                    coluna++;
                }
            }else if(sentido == 1){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'G';
                    linha++;
                }
            }
        }else if(i == 7){
            if(sentido == 0){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'H';
                    coluna++;
                }
            }else if(sentido == 1){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'H';
                    linha++;
                }
            }
        }else if(i == 8){
            if(sentido == 0){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'I';
                    coluna++;
                }
            }else if(sentido == 1){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'I';
                    linha++;
                }	 	  	 	      	   	  		 	      	   	 	
            }
        }else if(i == 9){
            if(sentido == 0){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'J';
                    coluna++;
                }
            }else if(sentido == 1){
                for(j=0; j<tam_barco; j++){
                    tabuleiro[linha-1][coluna-1] = 'J';
                    linha++;
                    tabuleiro[1][9] = 'J';
                }
            }
        }


    }

   

    while(jogada[0] != 'S'){

       scanf("%[^\n]*c ", jogada);
       setbuf(stdin, NULL);

       jogada[1] = '7';

       if(jogada[0] == 'A'){
            linha = 1;
        }else if(jogada[0] == 'B'){
            linha = 2;
        }else if(jogada[0] == 'C'){
            linha = 3;
        }else if(jogada[0] == 'D'){
            linha = 4;
        }else if(jogada[0] == 'E'){	 	  	 	      	   	  		 	      	   	 	
            linha = 5;
        }else if(jogada[0] == 'F'){
            linha = 6;
        }else if(jogada[0] == 'G'){
            linha = 7;
        }else if(jogada[0] == 'H'){
            linha = 8;
        }else if(jogada[0] == 'I'){
            linha = 9;
        }else if(jogada[0] == 'J'){
            linha = 10;
        }

        if(jogada[0] != 'S'){
             jogada[0] = '7';
        }

        if(jogada[0] != 'S'){

            if(jogada[3] == '\0'){

                aux_jogada = atoi(jogada);
                aux_jogada2 = aux_jogada;

                mult = aux_jogada / 10;
                coluna = aux_jogada2 - (mult*10);

            }else{

                aux_jogada = atoi(jogada);
                aux_jogada2 = aux_jogada;

                mult = aux_jogada / 100;
                coluna = aux_jogada2 - (mult*100);

            }	 	  	 	      	   	  		 	      	   	 	

            if(tabuleiro[linha-1][coluna-1] == '0' || tabuleiro[linha-1][coluna-1] == 'X'){
                nerro++;
                ntiro++;
                tabuleiro[linha-1][coluna-1] = 'X';

            }else if(tabuleiro[linha-1][coluna-1] == 'A'){
                bA++;
                ntiro++;
                nacerto++;
                tabuleiro[linha-1][coluna-1] = 'X';
                if(bA == 5){
                    barcos_derrubados[0] = barcos_derrubados[0] + 1;
                }

            }else if(tabuleiro[linha-1][coluna-1] == 'B'){
                bB++;
                ntiro++;
                nacerto++;
                tabuleiro[linha-1][coluna-1] = 'X';
                if(bB == 4){
                    barcos_derrubados[1] = barcos_derrubados[1] + 1;
                }

            }else if(tabuleiro[linha-1][coluna-1] == 'C'){
                bC++;
                ntiro++;
                nacerto++;
                tabuleiro[linha-1][coluna-1] = 'X';
                if(bC == 4){
                    barcos_derrubados[1] = barcos_derrubados[1] + 1;
                }

            }else if(tabuleiro[linha-1][coluna-1] == 'D'){
                bD++;
                ntiro++;
                nacerto++;
                tabuleiro[linha-1][coluna-1] = 'X';
                if(bD == 3){	 	  	 	      	   	  		 	      	   	 	
                    barcos_derrubados[2] = barcos_derrubados[2] + 1;
                }

            }else if(tabuleiro[linha-1][coluna-1] == 'E'){
                bE++;
                ntiro++;
                nacerto++;
                tabuleiro[linha-1][coluna-1] = 'X';
                if(bE == 3){
                    barcos_derrubados[2] = barcos_derrubados[2] + 1;
                }

            }else if(tabuleiro[linha-1][coluna-1] == 'F'){
                bF++;
                ntiro++;
                nacerto++;
                tabuleiro[linha-1][coluna-1] = 'X';
                if(bF == 3){
                    barcos_derrubados[2] = barcos_derrubados[2] + 1;
                }

            }else if(tabuleiro[linha-1][coluna-1] == 'G'){
                bG++;
                ntiro++;
                nacerto++;
                tabuleiro[linha-1][coluna-1] = 'X';
                if(bG == 2){
                    barcos_derrubados[3] = barcos_derrubados[3] + 1;
                }

            }else if(tabuleiro[linha-1][coluna-1] == 'H'){
                bH++;
                ntiro++;
                nacerto++;
                tabuleiro[linha-1][coluna-1] = 'X';
                if(bH == 2){	 	  	 	      	   	  		 	      	   	 	
                    barcos_derrubados[3] = barcos_derrubados[3] + 1;
                }

            }else if(tabuleiro[linha-1][coluna-1] == 'I'){
                bI++;
                ntiro++;
                nacerto++;
                tabuleiro[linha-1][coluna-1] = 'X';
                if(bI == 2){
                    barcos_derrubados[3] = barcos_derrubados[3] + 1;
                }

            }else if(tabuleiro[linha-1][coluna-1] == 'J'){
                bJ++;
                ntiro++;
                nacerto++;
                tabuleiro[linha-1][coluna-1] = 'X';
                if(bJ == 2){
                    barcos_derrubados[3] = barcos_derrubados[3] + 1;
                }

            }

        }
        //printf("linha:%i\n", linha);
        //printf("coluna:%i\n", coluna);

        //printf("Opa");


    }




    //printf("linha:%i\n", linha);
    //printf("coluna:%i\n", coluna);
    //printf("tam_barco:%i\n", tam_barco);

    printf("Foram dados %i tiros.\n", ntiro);
    printf("%i tiros acertaram navios.\n", nacerto);
    printf("%i tiros erraram.\n", nerro);

    printf("Naufragaram:\n");

    printf("%i porta-avioes.\n", barcos_derrubados[0]);
    printf("%i barco(s) de quatro canos.\n", barcos_derrubados[1]);
    printf("%i barco(s) de tres canos.\n", barcos_derrubados[2]);
    printf("%i barco(s) de dois canos.\n", barcos_derrubados[3]);
}	 	  	 	      	   	  		 	      	   	 	