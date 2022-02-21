#include "algorithms.h"

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

void selectionSort(int *a, const int size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap(&a[i], &a[minPos]);
    }
}

int sumInArray(int *a, const int n){
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