#ifndef UNTITLED3_SORT_H
#define UNTITLED3_SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void swap(int *a, int *b);

// вывод массива a размера n
void outputArray_(int *a, size_t n);

//алгоритм сортировки обменом (пузырьковую).
void bubbleSort(int *a, size_t n);

// алгоритм сортировки выбором
void selectionSort(int *a, size_t n);

// влгоритм сортировки вставками
void insertionSort(int *a, size_t n);

// алгоритм сортировки расчёской
void combSort(int *a, size_t n);

// алгоритм сортировки Шелла
void shellSort(int *a, size_t n);

// цифровая сортир.
int digit(int n, int k, int N, int M);

void radixSort_(int *a, int *n);

void radixSort(int *a, size_t n);

long long getBubbleSortNComp(int *a, size_t n);

long long getSelectionSortNComp(int *a, size_t n);

long long getInsertionSortNComp(int *a, size_t n);

long long getCombSortNComp(int *a, size_t n);

long long getShellSortNComp(int *a, size_t n);

long long getRadixSortNComps_(int *a, int *n);
long long getRadixSortNComps(int *a, int n);

// генерация массива от i до n с шагом 1
void generateOrderedArray(int *a, size_t n);

// генерация массива от n до i с шагом 1
void generateOrderedBackwards(int *a, size_t n);

// генеарция массива a размера n
void generateRandomArray(int *a, size_t n);

// проверка массива на упорядоченость
int isOrdered( const int *a , size_t n );

#endif
