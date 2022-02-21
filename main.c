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
long long getSum(int *a, int n) {
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
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix m = mulMatrices(m1, m2);

    return (bool) isEMatrix(m);
}

// target 7
int sumMaxOfDiagonalsOfMatrixExceptMainOne(matrix m) {
    int sizeSumArray = m.nCols + m.nRows - 1;
    int sumArray[sizeSumArray];
    for (size_t i = 0; i < sizeSumArray; i++) {
        sumArray[i] = 0;
    }

    for (size_t i = 0; i < m.nRows; i++) {
        for (size_t j = 0; j < m.nCols; j++)
            if (i != j)
                sumArray[j - i + 2] = max(sumArray[j - i + 2], m.values[i][j]);
    }
    int sum = sumInArray(sumArray, m.nRows + m.nCols - 1);

    return sum;
}

// 8 target
int getMinInArea(matrix m) {
    position maxPos = getMaxValuePos(m);

    int minElement = m.values[maxPos.rowIndex][maxPos.colIndex];
    int left = maxPos.colIndex;
    int right = maxPos.colIndex;

    for (int i = maxPos.rowIndex - 1; i >= 0; i--) {
        if (left - 1 >= 0)
            left--;
        if (right + 1 < m.nCols)
            right++;
        int j = right;
        while (j >= left) {
            minElement = min(minElement, m.values[i][j]);
            j--;
        }
    }

    return minElement;
}

// 9 target
float getDistance(int *a, int size) {
    int distance = 0;
    for (size_t i = 0; i < size; i++) {
        distance += a[i];
    }

    return sqrtf(distance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float *criteriaArray = (float *) malloc(sizeof(float) * m.nRows);

    for (int i = 0; i < m.nRows; ++i) {
        criteriaArray[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = i; j > 0 && criteriaArray[j - 1] > criteriaArray[j]; j--) {
            swap_(&criteriaArray[j - 1], &criteriaArray[j], sizeof(float));
            swapRows(m, j, j - 1);
        }
    }

    free(criteriaArray);
}

void sortByDistance(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

// 10 target
int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2)
        return -1;
    else if (arg1 > arg2)
        return 1;
    else
        return 0;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);

    int totalUnique;
    if (n != 0) {
        totalUnique = 1;
    }

    int i = 1;
    while (i < n) {
        if (a[i - 1] != a[i])
            totalUnique++;
        i++;
    }
    return totalUnique;
}

int countEqClassesByRowsSum(matrix m) {
    long long rowsSum[m.nRows];
    for (size_t i = 0; i < m.nRows; i++) {
        rowsSum[i] = sumInArray(m.values[i], m.nCols);
    }

    return countNUnique(rowsSum, m.nRows);
}

// 11 target
int getNSpecialElement(matrix m) {
    int nSpecialElement = 0;
    for (size_t j = 0; j < m.nCols; j++) {
        int specialElement = m.values[0][j];
        int sumElementInCol = 0;
        for (size_t i = 1; i < m.nRows; i++) {
            if (m.values[i][j] > specialElement) {
                sumElementInCol += specialElement;
                specialElement = m.values[i][j];
            } else
                sumElementInCol += m.values[i][j];
        }
        if (specialElement > sumElementInCol)
            nSpecialElement++;
    }
    return nSpecialElement;
}

// 12 target
position getLeftMin(matrix m) {
    int min = m.values[0][0];
    position minPosition = {0, 0};

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                minPosition = (position) {i, j};
            }
        }
    }

    return minPosition;
}

void swapPenultimateRow(matrix m) {
    if (m.nRows <= 1)
        printf("two or more lines are needed");

    position min = getLeftMin(m);
    int column[m.nRows];

    for (size_t i = 0; i < m.nRows; i++) {
        column[i] = m.values[i][min.colIndex];
    }

    memcpy(m.values[m.nRows - 2], column, sizeof(int) * m.nCols);
}

// 13 target
bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int numberRightMatrix = 0;
    for (size_t i = 0; i < nMatrix; i++)
        numberRightMatrix += hasAllNonDescendingRows(ms[i]);

    return numberRightMatrix;
}

// tests of targets
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

void test_transposeIfMatrixHasNotEqualSumOfRows_1() {
    matrix haveM = createMatrixFromArray((int[]) {1, 2,
                                                  2, 1}, 2, 2);

    matrix needM = createMatrixFromArray((int[]) {1, 2,
                                                  2, 1}, 2, 2);

    transposeIfMatrixHasEqualSumOfRows(haveM);

    assert(areTwoMatricesEqual(haveM, needM));

    freeMemMatrix(haveM);
    freeMemMatrix(needM);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_2() {
    matrix haveM = createMatrixFromArray((int[]) {1, 3,
                                                  1, 2}, 2, 2);

    matrix needM = createMatrixFromArray((int[]) {1, 1,
                                                  3, 2}, 2, 2);

    transposeIfMatrixHasEqualSumOfRows(haveM);

    assert(areTwoMatricesEqual(haveM, needM));

    freeMemMatrix(haveM);
    freeMemMatrix(needM);
}

void test_isMutuallyInverseMatrices_1() {
    matrix haveM1 = createMatrixFromArray((int[]) {3, -5,
                                                   1, -2}, 2, 2);

    matrix haveM2 = createMatrixFromArray((int[]) {2, -5,
                                                   1, -3}, 2, 2);

    assert(isMutuallyInverseMatrices(haveM1, haveM2) == true);

    freeMemMatrix(haveM1);
    freeMemMatrix(haveM2);
}

void test_isMutuallyInverseMatrices_2() {
    matrix haveM1 = createMatrixFromArray((int[]) {1, 3,
                                                   1, 2}, 2, 2);

    matrix haveM2 = createMatrixFromArray((int[]) {1, 1,
                                                   3, 2}, 2, 2);

    assert(isMutuallyInverseMatrices(haveM1, haveM2) == false);

    freeMemMatrix(haveM1);
    freeMemMatrix(haveM2);
}

void test_sumMaxOfDiagonalsOfMatrixExceptMainOne_1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    int sum = sumMaxOfDiagonalsOfMatrixExceptMainOne(m);

    assert(sum == 24);

    freeMemMatrix(m);
}

void test_getMinInArea_1() {
    matrix m = createMatrixFromArray((int[]) {5, 2, 3,
                                              4, 4, 6,
                                              7, 11, 9}, 3, 3);
    int min = getMinInArea(m);

    assert(min == 2);

    freeMemMatrix(m);
}

void test_getMinInArea_2_MaxInFirstRow() {
    matrix m = createMatrixFromArray((int[]) {12, 2, 3,
                                              4, 4, 6,
                                              7, 11, 9}, 3, 3);
    int min = getMinInArea(m);

    assert(min == 12);

    freeMemMatrix(m);
}

void test_sortByDistance_1() {
    matrix haveM = createMatrixFromArray((int[]) {14, 8, 5, 4,
                                                  3, 12, 8, 10,
                                                  6, 1, 9, 2}, 3, 4);
    sortByDistance(haveM);

    matrix needM = createMatrixFromArray((int[]) {6, 1, 9, 2,
                                                  3, 12, 8, 10,
                                                  14, 8, 5, 4}, 3, 4);
    assert(areTwoMatricesEqual(haveM, needM));

}

void test_countEqClassesByRowsSum_1() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              2, 7,
                                              5, 4,
                                              4, 3,
                                              1, 6,
                                              8, 0}, 6, 2);

    int totalEqClassesByRowsSum = countEqClassesByRowsSum(m);

    assert(totalEqClassesByRowsSum == 3);

}

void test_countEqClassesByRowsSum_2_allEqual() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              0, 8,
                                              2, 6,
                                              3, 5}, 4, 2);

    assert(countEqClassesByRowsSum(m) == 1);

}

void test_getNSpecialElement_1() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                              2, 3, 6, 7,
                                              12, 2, 1, 2}, 3, 4);

    int totalNSpecialElement = getNSpecialElement(m);

    assert(totalNSpecialElement == 2);

}

void test_swapPenultimateRow_1() {
    matrix haveM = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6,
                                                  7, 8, 1}, 3, 3);
    swapPenultimateRow(haveM);

    matrix needM = createMatrixFromArray((int[]) {1, 2, 3,
                                                  1, 4, 7,
                                                  7, 8, 1}, 3, 3);
    assert(areTwoMatricesEqual(haveM, needM));

}

void test_countNonDescendingRowsMatrices_1() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9
            },
            4, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);
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
    test_sumMaxOfDiagonalsOfMatrixExceptMainOne_1();
    test_getMinInArea_1();
    test_getMinInArea_2_MaxInFirstRow();
    test_sortByDistance_1();
    test_countEqClassesByRowsSum_1();
    test_countEqClassesByRowsSum_2_allEqual();
    test_getNSpecialElement_1();
    test_swapPenultimateRow_1();
    test_countNonDescendingRowsMatrices_1();
}

int main() {
    test();

    return 0;
}
