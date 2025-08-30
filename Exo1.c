#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int f(int n) {
    return (int)pow(2, n);
}


int g(int m) {
    return 2 * m;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage : %s [-f n] [-g n]\n", argv[0]);
        return 1;
    }

    int val = 0;   
    int init = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            if (i + 1 < argc) { 
                int n = atoi(argv[i+1]);
                if (!init) {
                    val = f(n);
                    init = 1;
                } else {
                    val= f(val);
                }
                i++;
            } else {
               
                if (init) {
                    val = f(val);
                } else {
                    printf("Erreur : option -f nécessite un argument au début.\n");
                    return 1;
                }
            }
        }
        else if (strcmp(argv[i], "-g") == 0) {
            if (i + 1 < argc && argv[i+1][0] != '-') {
                int m = atoi(argv[i+1]);
                if (!init) {
                    val = g(m);
                    init = 1;
                } else {
                    val = g(val);
                }
                i++;
            } else {
               
                if (init) {
                    val = g(val);
                } else {
                    printf("Erreur : option -g nécessite un argument au début.\n");
                    return 1;
                }
            }
        }
        else {
            printf("Option inconnue : %s\n", argv[i]);
            return 1;
        }
    }

    printf("Résultat = %d\n", val);
    return 0;
}
