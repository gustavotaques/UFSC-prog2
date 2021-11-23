#include <stdio.h>

int find_last_index (char *text) {
    int index = 1;

    for(int i=1; i<200; i++) {
        if (text[i] != '\n') {
            index++;
        } else {
            return index;
        }
    }
    return index;
}

int main () {
    char text[200];
    char aux[200] = {'`', '`'};
    int idx;
    int c = 1;
    int s = 2;

    while (c != EOF) {
        fgets(text, 200, stdin);
        idx = find_last_index(&text[0]);

        for (int i=0; i<=idx; i++) {
            if (text[i] == 34) {
                c--;
                if (c == -1) {
                    aux[s] = 39;
                    aux[s+1] = 39;
                    break;
                }
                continue;
            }
            if (c < 1) {
                aux[s] = text[i];
                s++;
            }
        }
    }

    printf("%s", aux);

    return 0;
}