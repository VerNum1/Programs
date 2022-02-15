#include "libs/data_structures/matrix/matrix.h"


// 1 target
void swapRowsWithMinAndMaxElements(matrix m) {
    position minPosition = getMinValuePos(m);
    position maxPosition = getMaxValuePos(m);

    swapRows(m, minPosition.rowIndex, maxPosition.rowIndex);
}

// 2 target
int getMaxToMin(int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] > max)
            max = a[i];
    }

    return -max;
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMaxToMin);
}

matrix mulMatrices(matrix m1, matrix m2){
    matrix m = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; ++i) {
        for (int j = 0; j < m2.nCols; ++j) {
            m.values[i][j] = m.values[i][j] + m1.values[i][j] * m2.values[i][j];
        }
    }

    return m;
}

void getSquareOfMatrixIfSymmetric(matrix *m){
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}


void test_swapRowsWithMinAndMaxElements_1() {
    matrix haveM = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6,
                                                  7, 8, 9}, 3, 3);
    matrix needM = createMatrixFromArray((int[]) {7, 8, 9,
                                                  4, 5, 6,
                                                  1, 2, 3}, 3, 3);

    swapRowsWithMinAndMaxElements(haveM);

    assert(areTwoMatricesEqual(haveM, needM));

    freeMemMatrix(haveM);
    freeMemMatrix(needM);
}

void test_sortRowsByMinElement_1() {
    matrix haveM = createMatrixFromArray((int[]) {1, 1, 2,
                                                  1, 1, 3,
                                                  1, 1, 1}, 3, 3);
    matrix needM = createMatrixFromArray((int[]) {1, 1, 1,
                                                  1, 1, 2,
                                                  1, 1, 3}, 3, 3);

    sortRowsByMinElement(haveM);

    assert(areTwoMatricesEqual(haveM, needM));

    freeMemMatrix(haveM);
    freeMemMatrix(needM);
}

void test_getSquareOfMatrixIfSymmetric_1() {
    matrix haveM = createMatrixFromArray((int[]) {1, 2,
                                                     1, 2}, 2, 2);

    matrix needM = createMatrixFromArray((int[]) {3, 6,
                                                     3, 6}, 2, 2);

    getSquareOfMatrixIfSymmetric(&haveM);

    assert(areTwoMatricesEqual(haveM, needM));

    freeMemMatrix(haveM);
    freeMemMatrix(needM);
}

void test() {
    test_sortRowsByMinElement_1();
    test_swapRowsWithMinAndMaxElements_1();
}

int main() {
    matrix m = getMemMatrix(3, 3);
    inputMatrix(m);

    sortRowsByMinElement(m);

    outputMatrix(m);

    return 0;
}
