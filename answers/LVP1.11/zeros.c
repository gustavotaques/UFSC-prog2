#include "zeros.h"

int numero_zeros(unsigned long long n) {
    

    int zeros = 0;
    
    unsigned long long fat;

    fat = fatorial(n);

    while(fat % 10 == 0){
        fat = fat / 10;
        zeros++;
    }

    return zeros;
}

