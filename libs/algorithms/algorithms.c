#include "algorithms.h"

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int max(int a, int b){
    a > b ? a : b;
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