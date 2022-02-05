//add_executable(untitled3 main.c bitset.h cmake-build-debug/bitset.c) в симейк для структур
#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void selectionSort(int *a, const int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minPos=i;
        for (int j = i+1; j < size; ++j)
            if (a[i] > a[j])
                minPos = j;
        swap(&a[i], &a[minPos]);
    }
}

int main() {

    int a[5]= {5, 4, 3, 2, 2};

    selectionSort(a, 5);

    for (int i = 0; i < 5; ++i) {
        printf("%d ", a[i]);
    }

    return 0;
}
