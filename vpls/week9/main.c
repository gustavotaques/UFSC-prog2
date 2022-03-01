#include <string.h>
#include <ctype.h>
#include "pilha.c"
#include "pilha.h"

int is_str_valid(char *p) {
    if (p == NULL) return 0;

    while (*p != 0) {
        if (!(isalpha(*p))) return 0;

        p++;
    }

    return 1;
}

int str_upper(char *p) {
    if (p == NULL) return 0;

    while (*p != 0) {
        if (islower(*p)) {
            *p = toupper(*p);
        }

        p++;
    }

    return 1;
}

int main () {
    int altura_max;
    int cont = 0;
    char str[100];
    int arr[100];

    pilha_t *terminal;

    scanf("%d", &altura_max);

    while (altura_max != 0) {
        scanf("%s", str);

        if (!(is_str_valid(str))) {
            scanf("%d", &altura_max);
            continue;
        }

        str_upper(str);

        terminal = pilha_cria();

        if (terminal == NULL) {
            scanf("%d", &altura_max);
            continue;
        }    

        for (int i=0; i<strlen(str); i++) {
            pilha_empilha(terminal, str[i], altura_max);
        }

        arr[cont++] = info_tamanho(terminal);

        pilha_destroi(&terminal);

        //---------------------
        scanf("%d", &altura_max);
    }

    for (int i=0; i<cont; i++) {
        if (i == cont - 1) {
            printf("%d", arr[i]);
        } else {
            printf("%d\n", arr[i]);
        }
    }

    return 0;
}