#include <stdio.h>


void recursive (int ninferior, int nsuperior, int inc) {
    if (inc <= 0) return;
    if (ninferior > nsuperior) return;

    printf("%d ", ninferior);

    if (ninferior <= nsuperior) recursive(ninferior+inc, nsuperior, inc);
}

int main () {
    recursive(0,10,1);
    return 0;
}