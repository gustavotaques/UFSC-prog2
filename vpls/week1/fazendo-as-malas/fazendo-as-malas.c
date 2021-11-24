#include <stdio.h>

int main () {
    int n;
    scanf("%d", &n);

    int dim;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=3; j++) {
            scanf("%d", &dim);

            if (dim > 20) {
                printf("Caso %i: bad\n", i);
                break;
            }
            if (j == 3) {
                printf("Caso %i: good\n", i);
            }
        }
    }
    return 0;
}