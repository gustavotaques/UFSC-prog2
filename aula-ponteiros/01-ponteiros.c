# include <stdio.h>

int main () {
    float pi = 3.1415;
    float *pf , ** ppf;

    pf = &pi;
    ppf = &pf;

    printf ("valor de pi: %.4f\n", pi);
    printf ("valor de pi: %.4f\n", *pf);
    printf ("valor de pi: %.4f\n", **ppf);

    printf ("endereco de pi: %p\n", &pi);
    printf ("conteudo de pf: %p\n", pf);
    printf ("endereco de pf: %p\n", &pf);
    printf ("conteudo de ppf: %p\n", ppf);

    return 0;
}