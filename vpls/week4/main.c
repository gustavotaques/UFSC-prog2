#include <stdio.h>
#include <stdlib.h>
#include "nba_stats.h" 
#include "nba_stats.c"

int main() {
	char nome_arquivo[] = "jogadores.dat";
	int n_jogadores = 0;
	char time[] = "TOT";
	char pos[] = "PF";

	jogador_t *j = le_jogadores(nome_arquivo, &n_jogadores);

	printf("%d\n", statt_posicao(j, n_jogadores, time, pos));

	return 0;
}