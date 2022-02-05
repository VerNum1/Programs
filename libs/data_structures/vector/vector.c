#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"

vector createVector(size_t n) {
    vector *v = (int *) malloc(sizeof(int) * n);

    if (v == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else if (n == 0)
        v = NULL;

    return (vector) {v, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
    } else if (newCapacity < v->size)
        v->size = newCapacity;
    else if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    if (v->size != v->capacity) {
        v->data = (int *) malloc(sizeof(int) * v->size);
        v->capacity = v->size;
    }
}

void deleteVector(vector *v) {
    free(v->data);
}

