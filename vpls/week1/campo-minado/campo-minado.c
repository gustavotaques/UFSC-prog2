#include <stdio.h>
#define TAM 10

int main () {
    char m[TAM][TAM] = {0};
    char aux[TAM][TAM];

    for (int i=0; i<TAM; i++) {
        int r=0, c=0;
        scanf("%d %d", &r, &c);
        m[r][c] = 42;

        if  (r<(TAM-1) && c<(TAM-1)) {
            if (m[r+1][c+1] != 42) m[r+1][c+1]++;
            if (m[r][c+1] != 42) m[r][c+1]++;
            if (m[r+1][c] != 42) m[r+1][c]++;

            if (c != 0) {
                if (m[r][c-1] != 42) m[r][c-1]++;
                if (m[r+1][c-1] != 42) m[r+1][c-1]++;
            }

            if (r != 0) {
                if (m[r-1][c] != 42) m[r-1][c]++;
                if (m[r-1][c+1] != 42) m[r-1][c+1]++;

                if (c != 0) {
                    if (m[r-1][c-1] != 42) m[r-1][c-1]++;
                }
            }

        }

            if (r == (TAM-1) && c != (TAM-1)) {
                if (m[r-1][c] != 42) m[r-1][c]++;
                if (m[r-1][c+1] != 42) m[r-1][c+1]++;
                if (m[r][c+1] != 42) m[r][c+1]++;

                if (c != 0) {
                    if (m[r][c-1] != 42) m[r][c-1]++;
                    if (m[r-1][c-1] != 42) m[r-1][c-1]++;
                }
            }

            if (r != (TAM-1) && c == (TAM-1)) {
                if (m[r][c-1] != 42) m[r][c-1]++;
                if (m[r+1][c-1] != 42) m[r+1][c-1]++;
                if (m[r+1][c] != 42) m[r+1][c]++;

                if (r != 0) {
                    if (m[r-1][c] != 42) m[r-1][c]++;
                    if (m[r-1][c-1] != 42) m[r-1][c-1]++;
                }
            }

            if (r == (TAM-1) && c == (TAM-1)) {
                if (m[r-1][c] != 42) m[r-1][c]++;
                if (m[r-1][c-1] != 42) m[r-1][c-1]++;
                if (m[r][c-1] != 42) m[r][c-1]++;
            }

    }

    for (int i=0; i<TAM; i++) {
        for (int j=0; j<TAM; j++) {
            if (m[i][j] != 42) {
                aux[i][j] = '0' + m[i][j];
            } else {
                aux[i][j] = 42;
            }
            if (j < (TAM-1)) {
                printf("%c ", aux[i][j]);
            } else {
                printf("%c", aux[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}