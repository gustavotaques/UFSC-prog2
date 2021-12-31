#include "digitos.h"

int verifica_ultimos_digitos(int a, int b){

    int A, B, acarac = 0, bcarac = 0, sub, potb = 1, i;

    A = a;
    B = b;

    if(a == b){
        return 1;
    }

    while(A != 0){
        A = A / 10;
        acarac = acarac + 1;
    }

    while(B != 0){
        B = B / 10;
        bcarac = bcarac + 1;
    }


    for(i=0; i<bcarac; i++){
        potb = potb *10;
    }


    if(a > b){
        sub = a - b;
        if(sub % potb == 0){
            return 1;
        }else if(sub % potb != 0){
            return 0;
        }
    }	 	  	 	      	   	  		 	      	   	 	
}

int verifica_segmento(int a, int b){
    int i, x;
  
    if(a==b){
        return 1;
    }
    
    
    
    if(a > b){
        for(i=0; i<10; i++){
            x = verifica_ultimos_digitos(a,b);
            if(x == 1){
                return 1;
            }
            a = a/10;
            if(a<b){
                return 0;
            }
            if(a == 0){
                return 0;
            }
        }
    }else
    if(a < b){
        for(i=0; i<10; i++){
            x = verifica_ultimos_digitos(a,b);
            if(x == 1){
                return 1;
            }
            b = b/10;
            if(b<a){
                return 0;
            }	 	  	 	      	   	  		 	      	   	 	
            if(b == 0){
                return 0;
            }
        }
    }




}