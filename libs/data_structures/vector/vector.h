#ifndef UNTITLED3_VECTOR_H
#define UNTITLED3_VECTOR_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct vector {
    int *data;        // указатель на элементы вектора
    size_t size;      // размер вектора
    size_t capacity;  // вместимость вектора
} vector;

// Вовращает вектор размера n, элементы: мусор
vector createVector(size_t size);

// Изменяет количество памяти newCapacity, выделенное под хранение элементов вектора v
void reserve(vector *v, size_t newCapacity);

// удаляет элементы вектора v, но не высвобождает выделеную память
void clear(vector *v);

// освобождает память, выделенную под неиспользуемые элементы вектора vector1
void shrinkToFit(vector *vector1);

// освобождает память, выделенную вектору v
void deleteVector(vector *v);

// возвращает значение "истина", если вектор v пустой, иначе "ложь"
bool isEmpty(vector *v);

// возвращает значение "истина", если вектор v полный, иначе "ложь"
bool isFull(vector *v);

// возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);

// добавляет элемент x в конец вектора v, в случае если он не заполнен,
// иначе увеличиваем количество выделенной памяти в 2 раза
void pushBack(vector *v, int x);

// удаляет последний элемент вектора v, если он не является пустым, иначе
// выводит соответсвующеее сообщение
void popBack(vector *v);

// возвращает указатель на index-ный элемент вектора v,
// если указанная позиция в границах вектора
int *atVector(vector *v, size_t index);

// возвращаеет указатель на последний элемент вектора v
int* back(vector *v);

// возвращает указатель на нулевой элемент вектора v
int* front(vector *v);

#endif //UNTITLED3_VECTOR_H
