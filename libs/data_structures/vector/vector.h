//
// Created by vadim on 05.02.2022.
//
#ifndef UNTITLED3_VECTOR_H
#define UNTITLED3_VECTOR_H

typedef struct vector {
    int *data;        // указатель на элементы вектора
    size_t size;      // размер вектора
    size_t capacity;  // вместимость вектора
} vector;

// Вовращает вектор размера n, элементы: мусор
vector createVector(size_t n);

// Изменяет количество памяти newCapacity, выделенное под хранение элементов вектора v
void reserve(vector *v, size_t newCapacity);

// удаляет элементы вектора v, но не высвобождает выделеную память
void clear(vector *v);

// освобождает память, выделенную под неиспользуемые элементы вектора vector1
void shrinkToFit(vector *vector1);

// освобождает память, выделенную вектору v
void deleteVector(vector *v);

#endif //UNTITLED3_VECTOR_H
