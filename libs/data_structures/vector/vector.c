#include "vector.h"

vector createVector(size_t size) {
    vector *v = (int *) malloc(sizeof(int) * size);

    if (v == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {v, 0, size};
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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, v->capacity + 1);
    else if (isFull(v))
        reserve(v, v->capacity * 2);
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "bad alloc");
        exit(1);
    } else
        v->size--;
}

int *atVector(vector *v, size_t index) {
    if (index > v->size || index < 0) {
        fprintf(stderr, "IndexError: a[%lld] is not exists", index);
        exit(1);
    } else
        return &v->data[index];
}

int *back(vector *v) {
    return &v->data[v->size - 1];
}

int *front(vector *v) {
    return v->data;
}