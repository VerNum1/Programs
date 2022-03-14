#include "algorithms.h"

int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

int sumInArray(int *a,  int n){
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }

    return sum;
}

void swap_(void *a, void *b, int size) {
    char *pa = a;
    char *pb = b;
    for (int i = 0; i < size; i++) {
        char t = *pa;
        *pa = *pb;
        *pb = t;
        pa++;
        pb++;
    }
}

int isEvenSymbol(int a) {
    if(a > 48 && a < 57)
        return (a - 48) % 2 == 0;
    return 0;
}

char *getEndOfString (char *s) {
    while (*s != '\0')
        s++;
    return s;
}