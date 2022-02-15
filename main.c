#include "libs/data_structures/matrix/matrix.h"


// 1 target
void swapRowsWithMinAndMaxElements(matrix m) {
    position minPosition = getMinValuePos(m);
    position maxPosition = getMaxValuePos(m);

    swapRows(m, minPosition.rowIndex, maxPosition.rowIndex);
}

int getMax(int *a, const int n) {
    int max = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

// 2 target
void sortRowsByMinElement(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        int maxElement = getMax(m.values[i], m.nCols);

    }
}

matrix mulMatrices(matrix m1, matrix m2){
    matrix m = getMemMatrix(m1.nCols, m2.nRows);


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

void test() {
    void test_firstTarget_1();

}

int main() {
    matrix m = getMemMatrix(2, 2);
    inputMatrix(m);

    getSquareOfMatrixIfSymmetric(&m);

    outputMatrix(m);

    return 0;
}
