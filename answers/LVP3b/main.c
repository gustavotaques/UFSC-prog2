#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * abre_arquivo(const char *arquivo){

	if(arquivo==NULL){
		return NULL;
	}
	FILE * arqv;
	arqv=fopen(arquivo,"r");//VER SE 'E SO PARA LER OU PRA ESCREVER NO ARQUIVO TAMBEM
	if(arqv==NULL){
		return NULL;
	}
	
	return arqv;
}

char ** constroi_labirinto(const char *nome_arquivo, int *i, int *j){

	FILE *arq=abre_arquivo(nome_arquivo);

	if(arq==NULL){
		return 0;
	}
	char aux,**l;
	int k=0,g;
	*i=0; *j=0;

	fscanf(arq,"%c", &aux);
	while(aux!='\n'){
		fscanf(arq,"%c", &aux);
		*j +=1;
	}
	rewind(arq);
	
	while(!feof(arq)){	 	  	 	    	   	     	    		   	       	 	
		fscanf(arq,"%c", &aux);
		if(k==*j){
			*i +=1;
			k=0;
		}else{
			k++;
		}
		
	}
	rewind(arq);
	
	l=(char**) malloc(sizeof(char*)*(*i));
	for(k=0;k<*i;k++){
		l[k]=(char*) malloc(sizeof(char)*((*j)+1));
	}
	

	for(k=0;k<*i;k++){
		for(g=0;g<*j+1;g++){
			fscanf(arq,"%c",&aux);
			l[k][g]=aux;
		}
	}
	return l;


}


int acha_saida(char **l,int i,int j,int linha, int coluna){
	
	l[i][j]='.';
	int k=0;
	if(l[linha-2][coluna-1]=='.'){
		return 1;
	}	 	  	 	    	   	     	    		   	       	 	

	if((i+1)!=linha && l[i+1][j]==' ' && k!=1){
		k=acha_saida(l,i+1,j,linha,coluna);
	}

	if((i-1)!=0 && l[i-1][j]==' ' && k!=1){
		k=acha_saida(l,i-1,j,linha,coluna);
	}
	if((j+1)!=coluna && l[i][j+1]==' ' && k!=1){
		k=acha_saida(l,i,j+1,linha,coluna);
	}

	if((j-1)!=0 && l[i][j-1]==' ' && k!=1){
		k=acha_saida(l,i,j-1,linha,coluna);
	}

	if(k==0){
		l[i][j]=' ';
		return 0;
	}
	return 1;
}

int main(int argc, char *argv[]) {

	if(argv==NULL){
		return 1;
	}

	const char *nome_arquivo=argv[1];
	char **lab;
	int linha,coluna;

	lab=constroi_labirinto(nome_arquivo,&linha,&coluna);
	
	int resolvido=0;
	
	resolvido=acha_saida(lab,1,0,linha,coluna);

    
    for(int k=0;k<linha;k++){	 	  	 	    	   	     	    		   	       	 	
		for(int g=0;g<coluna;g++){
			printf("%c",lab[k][g]);
		}
		if(k!=linha-1){
		    printf("\n");
		}
	}
	
	
	for(int k=0;k<linha;k++){
		free(lab[k]);

	}
	free(lab);
 
    return 0;   
}