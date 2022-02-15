#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms->values);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; ++j) {
            printf("%d ", m.values[i][j]);
            printf("\n");
        }
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        outputMatrix(ms[i]);
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *temp = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = temp;
}


void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; ++i)
        swap(&m.values[i][j1], &m.values[i][j2]);
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int criteriaArr[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        criteriaArr[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 0; i < m.nRows; ++i) {
        int indexMax = i;
        for (int j = i; j < m.nRows; j++)
            if (criteriaArr[j] > criteriaArr[indexMax])
                indexMax = j;

        swap(&criteriaArr[indexMax], &criteriaArr[i]);

        swapRows(m, i, indexMax);
    }
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int criteriaArr[m.nCols];
    int column[m.nRows];

    for (int i = 0; i < m.nCols; ++i) {
        for (int j = 0; j < m.nRows; ++j)
            column[j] = m.values[j][i];
        criteriaArr[i] = criteria(column, m.nRows);
    }

    for (int i = 0; i < m.nCols; ++i) {
        int indexMax = i;
        for (int j = i; j < m.nCols; j++) {
            if (criteriaArr[j] > criteriaArr[indexMax])
                indexMax = j;
        }
        swap(&criteriaArr[indexMax], &criteriaArr[i]);
        swapColumns(m, i, indexMax);
    }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    for (int i = 0; i < m1.nRows; ++i)
        for (int j = 0; j < m1.nCols; ++j)
            if (m1.values[i][j] != m2.values[i][j])
                return false;
    return true;
}

bool isEMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        if (m.values[i][i] != 1)
            return false;
    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    else {
        bool isSymmetric = true;
        int i = 0;
        while (isSymmetric && i < m.nRows) {
            int j = 0;
            while (isSymmetric && j < m.nCols) {
                isSymmetric = m.values[i][j] == m.values[j][i];
                j++;
            }
            i++;
        }
        return isSymmetric;
    }
}

void transposeSquareMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        for (int j = i + 1; j < m.nCols; ++j)
            swap(&m.values[i][j], &m.values[j][i]);
}

position getMinValuePos(matrix m) {
    position minPos = (position){0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 1; j < m.nCols; ++j)
            if (m.values[i][j] < m.values[minPos.rowIndex][minPos.colIndex])
                minPos = (position){i, j};
    }
    return minPos;
}

position getMaxValuePos(matrix m) {
    position maxPos = (position){0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 1; j < m.nCols; ++j)
            if (m.values[i][j] > m.values[maxPos.rowIndex][maxPos.colIndex])
                maxPos = (position){i, j};
    }
    return maxPos;
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices,
                                     int nRows, int nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}