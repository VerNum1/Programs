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

// 3 target
int getMinToMax(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; ++i) {
        if (a[i] < min)
            min = a[i];
    }

    return -min;
}


void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMinToMax);
}

// 4 target
matrix mulMatrices(matrix m1, matrix m2) {
    matrix m = getMemMatrix(m1.nRows, m1.nCols);

    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            m.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++)
                m.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    return m;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m)) {
        matrix m1 = mulMatrices(*m, *m);
        for (int i = 0; i < m->nRows; ++i)
            for (int j = 0; j < m->nCols; ++j)
                m->values[i][j] = m1.values[i][j];

    }
}

// 5 target
long long getSum(int *a, int n){
    long long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];
    return sum;
}

bool isUnique(long long *a, int n) {
    bool isUnique = true;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j])
                isUnique = false;
        }
    }
    return isUnique;
}

void transposeIfMatrixHasEqualSumOfRows(matrix m) {
    long long sumRows[m.nRows];
    for (int i = 0; i < m.nRows; ++i) {
        sumRows[i] = getSum(m.values[i], m.nCols);
    }
    if (isUnique(sumRows, m.nRows))
        transposeSquareMatrix(m);
}

// 6 target
bool isMutuallyInverseMatrices(matrix m1, matrix m2){
    matrix m = mulMatrices(m1, m2);

    return (bool) isEMatrix(m);
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

void test_sortColsByMinElement_1() {
    matrix haveM = createMatrixFromArray((int[]) {1, 3, 0,
                                                  2, 5, 4,
                                                  3, 6, 7}, 3, 3);
    matrix needM = createMatrixFromArray((int[]) {0, 1, 3,
                                                  4, 2, 5,
                                                  7, 3, 6}, 3, 3);

    sortColsByMinElement(haveM);

    assert(areTwoMatricesEqual(haveM, needM));

    freeMemMatrix(haveM);
    freeMemMatrix(needM);
}

void test_getSquareOfMatrixIfSymmetric_1() {
    matrix haveM = createMatrixFromArray((int[]) {1, 2,
                                                  2, 1}, 2, 2);

    matrix needM = createMatrixFromArray((int[]) {5, 4,
                                                  4, 5}, 2, 2);

    getSquareOfMatrixIfSymmetric(&haveM);

    assert(areTwoMatricesEqual(haveM, needM));

    freeMemMatrix(haveM);
    freeMemMatrix(needM);
}

void test_getSquareOfMatrixIfSymmetric_2() {
    matrix haveM = createMatrixFromArray((int[]) {1, 3,
                                                  21, 1}, 2, 2);

    matrix needM = createMatrixFromArray((int[]) {1, 3,
                                                  21, 1}, 2, 2);

    getSquareOfMatrixIfSymmetric(&haveM);

    assert(areTwoMatricesEqual(haveM, needM));

    freeMemMatrix(haveM);
    freeMemMatrix(needM);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_1(){
    matrix haveM = createMatrixFromArray((int[]) {1, 2,
                                                  2, 1}, 2, 2);

    matrix needM = createMatrixFromArray((int[]) {1, 2,
                                                  2, 1}, 2, 2);

    transposeIfMatrixHasEqualSumOfRows(haveM);

    assert(areTwoMatricesEqual(haveM, needM));

    freeMemMatrix(haveM);
    freeMemMatrix(needM);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_2(){
    matrix haveM = createMatrixFromArray((int[]) {1, 3,
                                                  1, 2}, 2, 2);

    matrix needM = createMatrixFromArray((int[]) {1, 1,
                                                  3, 2}, 2, 2);

    transposeIfMatrixHasEqualSumOfRows(haveM);

    assert(areTwoMatricesEqual(haveM, needM));

    freeMemMatrix(haveM);
    freeMemMatrix(needM);
}

void test_isMutuallyInverseMatrices_1(){
    matrix haveM1 = createMatrixFromArray((int[]) {3, -5,
                                                  1, -2}, 2, 2);

    matrix haveM2 = createMatrixFromArray((int[]) {2, -5,
                                                  1, -3}, 2, 2);

    assert(isMutuallyInverseMatrices(haveM1, haveM2) == true);

    freeMemMatrix(haveM1);
    freeMemMatrix(haveM2);
}

void test_isMutuallyInverseMatrices_2(){
    matrix haveM1 = createMatrixFromArray((int[]) {1, 3,
                                                   1, 2}, 2, 2);

    matrix haveM2 = createMatrixFromArray((int[]) {1, 1,
                                                   3, 2}, 2, 2);

    assert(isMutuallyInverseMatrices(haveM1, haveM2) == false);

    freeMemMatrix(haveM1);
    freeMemMatrix(haveM2);
}

void test() {
    test_swapRowsWithMinAndMaxElements_1();
    test_sortRowsByMinElement_1();
    test_sortColsByMinElement_1();
    test_getSquareOfMatrixIfSymmetric_1();
    test_getSquareOfMatrixIfSymmetric_2();
    test_transposeIfMatrixHasNotEqualSumOfRows_1();
    test_transposeIfMatrixHasNotEqualSumOfRows_2();
    test_isMutuallyInverseMatrices_1();
    test_isMutuallyInverseMatrices_2();
}

int main() {
    test();

    return 0;
}
