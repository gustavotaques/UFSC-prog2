#include "strlib.h"

int str_length (const char *str) {
    if (str == 0) return -1;

    int cont = 0;

    while (str[cont]!='\0') {
        cont++;
    }
    return cont;
}


char* str_duplicate (const char *str) {
    if (str == 0) {
        return 0;
    }

    char *aux;
    int text_length = str_length(str);

    aux = (char*) malloc(sizeof(int) * (text_length + 1));

    for (int i=0; i<(text_length+1); i++) {
        aux[i] = str[i];
    }
    return aux;
}


int str_compare (const char *stra, const char *strb) {
    
    while (*stra != 0 || *strb != 0) {
        if (*stra < *strb) return -1;
        if (*stra > *strb) return 1;

        stra++;
        strb++;

    }
    return 0;
}


int str_reverse (char *str) {
    if (str == 0) return 0;
    
    int n = str_length(str) - 1;
    int i = 0;
    char aux;

    while (i < n) {
        aux = str[i];
        str[i] = str[n];
        str[n] = aux;

        i++;
        n--;
    }
    return 1;
}


int	str_upper (char *str) {
    if (str == 0) return -1;

    int cont = 0;
    int lower = 122;
    int upper = 90;

    while (*str != 0) {
        int aux = 0;

        if (*str >= 97 && *str <= 122) {
            aux = lower - *str;
            *str = upper - aux;
            cont++;
        }
        
        str++;
    }
    return cont;
}


int	str_lower (char *str) {
    if (str == 0) return -1;

    int cont = 0;
    int lower = 122;
    int upper = 90;

    while (*str != 0) {
        int aux = 0;

        if (*str >= 65 && *str <= 90) {
            aux = upper - *str;
            *str = lower - aux;
            cont++;
        }
        
        str++;
    }
    return cont;
}

int str_copy (char *dst, const char *src) {
    if (src == 0 || dst == 0) return -1;

    int src_len = str_length(src);
    int dst_len = str_length(dst);

    if (dst_len + 1 >= src_len + 1) {
        for (int i=0; i<src_len; i++) {
            dst[i] = src[i];
        }
        dst[src_len] = 0;
        return 1;
    }
    return 0;
}

char* str_concatenate (const char *stra, const char *strb) {
    if (stra == 0 && strb == 0) return 0;

    int stra_len = str_length(stra);
    int strb_len = str_length(strb);
    char *p_aux;

    if (strb == 0) {
        p_aux = (char*) malloc(sizeof(int) * (stra_len + 1));

        for (int i=0; i<stra_len; i++) {
            p_aux[i] = stra[i];
        }

    } else if (stra == 0) {
        p_aux = (char*) malloc(sizeof(int) * (strb_len + 1));

        for (int i=0; i<strb_len; i++) {
            p_aux[i] = strb[i];
        }

    } else {
        int i = 0;
        int j = 0;
        p_aux = (char*) malloc(sizeof(int) * (stra_len + strb_len + 1));

        while (i < (stra_len + strb_len)) {
            while (i < stra_len) {
                p_aux[i] = stra[i];
                i++;
            }
            if (i == stra_len - 1) i = stra_len;

            p_aux[i] = strb[j];
            j++;
            i++;
        }
    }
    return p_aux;
}


int str_find_first (const char *str, const char c) {
    if (str == 0) return -1;

    int str_len = str_length(str);
    int cont = 0;

    for (int i=0; i<str_len; i++) {
        if (str[i] == c) {
            return cont;
        }
        cont++;
    }
    return -1;
}


int str_find_last (const char *str, const char c) {
    if (str == 0) return -1;

    int str_len = str_length(str);
    int cont = str_len - 1;

    for (int i=(str_len-1); i>=0; i--) {
        if (str[i] == c) {
            return cont;
        }
        cont--;
    }
    return -1;
}

int str_count_words (const char *str) {
    if (str == 0) return -1;

    int cont = 0;
    char estado = 's';

    while (*str) {
        if (*str == 32) {
            estado = 's';
        } else if (estado == 's') {
            estado = 'n';
            cont ++;
        }
        str++;
    }
    return cont;
}