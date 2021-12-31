#ifndef LAB2_H
#define LAB2_H

/**
 * Função que retorna o quociente de uma divisão entre dois números inteiros
 * parametros:
 * a -> dividendo
 * b -> divisor
 * retorna um inteiro contendo o quociente da divisão.
 **/
int quociente(int a, int b);
/**
 * Função que retorna o resto de uma divisão entre dois números inteiros
 * parametros:
 * a -> dividendo
 * b -> divisor
 * retorna um inteiro contendo o resto da divisão.
 **/
int resto(int a, int b);

/**
 * Função que receba um inteiro entre 1 e 32767 e e cria uma string com uma série de dígitos, separados por espaços.
 * parametros:
 * numero -> inteiro a ser separado
 * retorna uma string alocada dinamicamente com os digitos separados por um espaço.
 **/
char* separa(int numero);

#endif

	 	  	 	      	   	  		 	      	   	 	
