#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	
	int n, aux = 1, mult, i;
	
	scanf("%i", &n);
	
	if(n > 0 && n < 11){
		
		printf("x ");
		
		for(i=1; i<n+1; i++){
			
			printf("%i", i);
			
			if(i<n){
				printf(" ");
			}
			
		}
		printf("\n");
			
		//printf("%i", n);
		for(i=0; i<10; i++){
			
			for(int j=1; j<n+2; j++){
				
				if(j == 1){
					printf("%i ", aux);
					
				}else if(j != 1){
					
					mult = (j-1) * aux;
					printf("%i", mult);
					
					if(j<n+1){	 	  	 	      	   	  		 	      	   	 	
						printf(" ");
					}
				}
					
			}
			aux = aux + 1;
			printf("\n");	
		}
		
		
	}
	
	return 0;
}