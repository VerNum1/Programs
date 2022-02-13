#ifndef UNTITLED3_MATRIX_H
#define UNTITLED3_MATRIX_H

#include <malloc.h>
#include <stdlib.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

// Возвращает матрицу. Размещает в динамической памяти матрицу размером nRows на nCols.
matrix getMemMatrix(int nRows, int nCols);

// Возвращает указатель на нулевую матрицу.
// Размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols.
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);



#endif //UNTITLED3_MATRIX_H
