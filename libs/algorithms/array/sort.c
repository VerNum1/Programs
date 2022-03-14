#include "sort.h"

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// sort
void outputArray_(int *a, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
}

void bubbleSort(int *a, size_t n) {
    for (size_t i = 0; i < n - 1; i++)
        for (size_t j = n - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
}

void selectionSort(int *a, size_t n) {
    for (int i = 0; i < n - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap(&a[i], &a[minPos]);
    }
}

void insertionSort(int *a, size_t n) {
    for (size_t i = 1; i < n; i++) {
        int t = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

void combSort(int *a, size_t n) {
    size_t step = n;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < n; ++i, ++j)
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }
}

void shellSort(int *a, size_t n) {
    size_t j;
    int tmp;
    for (size_t step = n / 2; step > 0; step /= 2)
        for (size_t i = step; i < n; i++) {
            tmp = a[i];
            for (j = i; j >= step; j -= step) {
                if (tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = tmp;
        }
}

//
void getPrefixSum(int *a, int n) {
    int p[n];
    p[0] = a[0];
    for (int i = 1; i < n; i++)
        p[i] = p[i - 1] + a[i];
}

//
int digit(int n, int k, int N, int M) {
    return (n >> (N * k) & (M - 1));
}

void radixSort_(int *a, int *n) {
    int bit = 8;
    int k = (32 + bit - 1) / bit;
    int M = 1 << bit;
    int sz = n - a;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++)
            c[j] = 0;

        for (int *j = a; j < n; j++)
            c[digit(*j, i, bit, M)]++;

        for (int j = 1; j < M; j++)
            c[j] += c[j - 1];

        for (int *j = n - 1; j >= a; j--)
            b[--c[digit(*j, i, bit, M)]] = *j;

        int cur = 0;
        for (int *j = a; j < n; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);
}

void radixSort(int *a, size_t n) {
    radixSort_(a, a + n);
}

// генерации
void generateOrderedArray(int *a, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        a[i] = (int) i;
    }
}

void generateOrderedBackwards(int *a, size_t n) {
    for (int i = 0; i < n; ++i) {
        a[i] = (int) n - i;
    }
}

void generateRandomArray(int *a, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        a[i] = rand() % n;
    }
}

int isOrdered(const int *a, size_t n) {
    for (size_t i = 1; i < n && a[i - 1] <= a[i]; i++)
        if (a[i - 1] > a[i])
            return 0;
    return 1;
}