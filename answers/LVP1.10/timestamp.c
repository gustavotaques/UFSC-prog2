#include "timestamp.h"

int converte_data_para_epoca(char time[]){
    
    printf("%s", time);
    
    char aux_data[7], aux_hora[7];

    int dia, mes, ano, hora, minuto, segundo;
    int n_data, n_hora, aux_ano, aux_bissexto;

    aux_data[0] = time[0];
    aux_data[1] = time[1];
    aux_data[2] = time[3];
    aux_data[3] = time[4];
    aux_data[4] = time[6];
    aux_data[5] = time[7];

    aux_hora[0] = time[9];
    aux_hora[1] = time[10];
    aux_hora[2] = time[12];
    aux_hora[3] = time[13];
    aux_hora[4] = time[15];
    aux_hora[5] = time[16];

    n_data = atoi(aux_data);
    n_hora = atoi(aux_hora);

    ano = n_data / 10000;
    aux_bissexto = ano;

    mes = (n_data - (ano * 10000)) / 100;

    dia = n_data % 100;

    hora = n_hora / 10000;

    minuto = (n_hora - (hora * 10000)) / 100;

    segundo = n_hora % 100;

    int seg_ano, seg_mes, seg_dia, seg_hora, seg_minuto, i;
    int vet_mes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int dia_mes = 0;

    if(mes>12 || dia>31 || hora>24 || minuto>60 || segundo>60){	 	  	 	      	   	  		 	      	   	 	
        return 0;

    }else{
        if(ano <= 70){
            ano = ano +100;
        }
        ano = ano - 70;

        seg_ano = ano * 24 * 365 * 3600;
        
        int arruma_bissexto = 0;
        
        if(aux_bissexto % 4 == 0 && mes < 03){
            arruma_bissexto = -1;
        }

        seg_dia = ((ano/4)+ arruma_bissexto + dia) * 24 * 3600;

        for(i=0; i<mes-1; i++){
            dia_mes = dia_mes + vet_mes[i];
        }
        seg_mes = dia_mes * 24 * 3600;

        seg_hora = hora * 3600;

        seg_minuto = minuto * 60;

        int timestamp;

        timestamp = seg_ano + seg_mes + seg_dia + seg_hora + seg_minuto + segundo;

        return timestamp;


    }
}	 	  	 	      	   	  		 	      	   	 	