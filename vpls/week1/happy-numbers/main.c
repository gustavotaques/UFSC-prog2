#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);

    for (int i=1; i<=n; i++) {
        int number, n_final, soma = 0;
        scanf("%d", &number);
        n_final = number;

        while (soma != 1 && soma != 4) {
            soma = 0;
            while (number > 0) {
                soma += (number % 10) * (number % 10);
                number = number / 10;
            }
            number = soma;
        }
        if (soma == 1) {
            printf("Entrada #%d: %d e um numero feliz.\n", i, n_final);
        }else{
            printf("Entrada #%d: %d e um numero infeliz.\n", i, n_final);
        }
    }
}