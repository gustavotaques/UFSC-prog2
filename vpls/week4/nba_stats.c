#include "nba_stats.h" 


int le_cabecario (char *nome) {
    if (nome == NULL) return -1;
    FILE *arq = fopen(nome, "r");
    if (!arq) return 0;

    int n;

    fread(&n, sizeof(int), 1, arq);
    fclose(arq);

    return n;
}


jogador_t* le_jogadores (char *nome, int *njogadores) {
    if (nome == NULL || njogadores == NULL) return NULL;
    FILE *arq = fopen(nome, "r");
    if (!arq) return NULL;

    int n;
    fread(&n, sizeof(int), 1, arq);

    jogador_t *jogadores = (jogador_t*) malloc(sizeof(jogador_t) * n);

    for (int i=0; i<n; i++) {
        jogador_t jogador;
        fread(&jogador, sizeof(jogador_t), 1, arq);

        jogadores[i] = jogador; 
    }
    
    *njogadores = n;
    fclose(arq);
    return jogadores;
}


int statj_mais_arremessos (jogador_t *jogadores, int njogadores, char tipo) {
    if (jogadores == NULL) return -1;
    if (tipo != '2' && tipo != '3' && tipo != 'T' && tipo != 'L') return -2;

    int indice = 0;
    int arr = 0;

    for (int i=0; i<njogadores; i++) {
        if (tipo == '2') {
            if (jogadores[i].a2.arremessos > arr) {
                indice = i;
                arr = jogadores[i].a2.arremessos;
            }
        } else if (tipo == '3') {
            if (jogadores[i].a3.arremessos > arr) {
                indice = i;
                arr = jogadores[i].a3.arremessos;
            }
        } else if (tipo == 'T') {
            if (jogadores[i].aT.arremessos > arr) {
                indice = i;
                arr = jogadores[i].aT.arremessos;
            }
        } else {
            if (jogadores[i].aL.arremessos > arr) {
                indice = i;
                arr = jogadores[i].aL.arremessos;
            }
        }
    }
    return indice;
}


int statj_mais_cestas (jogador_t *jogadores, int njogadores, char tipo) {
    if (jogadores == NULL) return -1;
    if (tipo != '2' && tipo != '3' && tipo != 'T' && tipo != 'L') return -2;

    int indice = 0;
    int arr = 0;

    for (int i=0; i<njogadores; i++) {
        if (tipo == '2') {
            if (jogadores[i].a2.cestas > arr) {
                indice = i;
                arr = jogadores[i].a2.cestas;
            }
        } else if (tipo == '3') {
            if (jogadores[i].a3.cestas > arr) {
                indice = i;
                arr = jogadores[i].a3.cestas;
            }
        } else if (tipo == 'T') {
            if (jogadores[i].aT.cestas > arr) {
                indice = i;
                arr = jogadores[i].aT.cestas;
            }
        } else {
            if (jogadores[i].aL.cestas > arr) {
                indice = i;
                arr = jogadores[i].aL.cestas;
            }
        }
    }
    return indice;
}


int statj_melhor_percentual (jogador_t *jogadores, int njogadores, char tipo) {
    if (jogadores == NULL) return -1;
    if (tipo != '2' && tipo != '3' && tipo != 'T' && tipo != 'L') return -2;

    int indice = 0;
    float arr = 0.0;

    for (int i=0; i<njogadores; i++) {
        if (tipo == '2') {
            if (jogadores[i].a2.percentual > arr) {
                indice = i;
                arr = jogadores[i].a2.percentual;
            }
        } else if (tipo == '3') {
            if (jogadores[i].a3.percentual > arr) {
                indice = i;
                arr = jogadores[i].a3.percentual;
            }
        } else if (tipo == 'T') {
            if (jogadores[i].aT.percentual > arr) {
                indice = i;
                arr = jogadores[i].aT.percentual;
            }
        } else {
            if (jogadores[i].aL.percentual > arr) {
                indice = i;
                arr = jogadores[i].aL.percentual;
            }
        }
    }
    return indice;

}


int statj_jogos (jogador_t *jogadores, int njogadores, char tipo) {
    if (jogadores == NULL) return -1;
    if (tipo != '+' && tipo != '-') return -2;

    int indice = 0;
    int maior_n_jogos = 0;

    for (int i=0; i<njogadores; i++) {
        if (tipo == '+') {
            if (jogadores[i].jogos > maior_n_jogos) {
                indice = i;
                maior_n_jogos = jogadores[i].jogos;
            }
        } else {
            if (i == 0) {
                indice = i;
                maior_n_jogos = jogadores[i].jogos;
            }
            if (jogadores[i].jogos < maior_n_jogos) {
                indice = i;
                maior_n_jogos = jogadores[i].jogos;
            }
        }
    }
    return indice;
}


int statj_idade (jogador_t *jogadores, int njogadores, char tipo) {
    if (jogadores == NULL) return -1;
    if (tipo != '+' && tipo != '-') return -2;

    int indice = 0;
    int n_idade = 0;

    for (int i=0; i<njogadores; i++) {
        if (tipo == '+') {
            if (jogadores[i].idade > n_idade) {
                indice = i;
                n_idade = jogadores[i].idade;
            }
        } else {
            if (i == 0) {
                indice = i;
                n_idade = jogadores[i].idade;
            }
            if (jogadores[i].idade < n_idade) {
                indice = i;
                n_idade = jogadores[i].idade;
            }
        }
    }
    return indice;
}


int statj_minutos (jogador_t *jogadores, int njogadores, char tipo) {
    if (jogadores == NULL) return -1;
    if (tipo != '+' && tipo != '-') return -2;

    int indice = 0;
    int n_tempo = 0;

    for (int i=0; i<njogadores; i++) {
        if (tipo == '+') {
            if (jogadores[i].minutos > n_tempo) {
                indice = i;
                n_tempo = jogadores[i].minutos;
            }
        } else {
            if (i == 0) {
                indice = i;
                n_tempo = jogadores[i].minutos;
            }
            if (jogadores[i].minutos < n_tempo) {
                indice = i;
                n_tempo = jogadores[i].minutos;
            }
        }
    }
    return indice;
}


int statj_pontos (jogador_t *jogadores, int njogadores, char tipo) {
    if (jogadores == NULL) return -1;
    if (tipo != '+' && tipo != '-') return -2;

    int indice = 0;
    int n_pontos = 0;

    for (int i=0; i<njogadores; i++) {
        if (tipo == '+') {
            if (jogadores[i].pontos > n_pontos) {
                indice = i;
                n_pontos = jogadores[i].pontos;
            }
        } else {
            if (i == 0) {
                indice = i;
                n_pontos = jogadores[i].pontos;
            }
            if (jogadores[i].pontos < n_pontos) {
                indice = i;
                n_pontos = jogadores[i].pontos;
            }
        }
    }
    return indice;
}


int statt_soma_pontos (jogador_t *jogadores, int njogadores, char* time) {
    if (jogadores == NULL || time == NULL) return -1;
    
    int soma_pontos_time = 0;

    int tam_time = strlen(time);

    for (int i=0; i<njogadores; i++) {
        int c_igual = 0;
        for (int j=0; j<tam_time; j++) {
            if (jogadores[i].time[j] == time[j]) {
                c_igual++;
            }
        }
        if (c_igual != tam_time) continue;

        soma_pontos_time += jogadores[i].pontos;
    }
    if (soma_pontos_time == 0) return 0;

    return soma_pontos_time;
}


float statt_media_pontos (jogador_t *jogadores, int njogadores, char* time) {
    if (jogadores == NULL || time == NULL) return -1;

    float soma_pontos_time = 0.0;
    float qtd_jogadores_time = 0.0;

    int tam_time = strlen(time);

    for (int i=0; i<njogadores; i++) {
        int c_igual = 0;
        for (int j=0; j<tam_time; j++) {
            if (jogadores[i].time[j] == time[j]) {
                c_igual++;
            }
        }
        if (c_igual != tam_time) continue;

        soma_pontos_time += jogadores[i].pontos;
        qtd_jogadores_time++;
    }
    if (soma_pontos_time == 0) return 0;

    return soma_pontos_time / qtd_jogadores_time;
}


float statt_media_idade (jogador_t *jogadores, int njogadores, char* time) {
    if (jogadores == NULL || time == NULL) return -1;

    float soma_idades_time = 0.0;
    float qtd_jogadores_time = 0.0;

    int tam_time = strlen(time);

    for (int i=0; i<njogadores; i++) {
        int c_igual = 0;
        for (int j=0; j<tam_time; j++) {
            if (jogadores[i].time[j] == time[j]) {
                c_igual++;
            }
        }
        if (c_igual != tam_time) continue;

        soma_idades_time += jogadores[i].idade;
        qtd_jogadores_time++;
    }
    if (soma_idades_time == 0) return 0;

    return soma_idades_time / qtd_jogadores_time;
}


int statt_posicao (jogador_t *jogadores, int njogadores, char *time, char* posicao) {
    if (jogadores == NULL || time == NULL || posicao == NULL) return -1;

    int soma = 0;
    // int tam_time = strlen(time);
    // int tam_pos = strlen(posicao);


    for (int i=0; i<njogadores; i++) {
        //int c_igual = 0;

        if (strcmp(jogadores[i].time, time) != 0) continue;
        // for (int j=0; j<tam_time; j++) {
        //     if (jogadores[i].time[j] == time[j]) {
        //         c_igual++;
        //     }
        // }

        // if (c_igual != tam_time) continue;

        if (strcmp(jogadores[i].posicao, posicao) != 0) continue;

        soma++;
        // c_igual = 0;
        // for (int j=0; j<tam_pos; j++) {
        //     if (jogadores[i].posicao[j] == posicao[j]) {
        //         c_igual++;
        //     }
        // }
        // if (c_igual != tam_pos) continue;

        // soma++;
    }
    if (soma == 0) return 0;

    return soma;
}