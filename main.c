#include "libs/data_structures/matrix/matrix.h"

void test_firstTarget_1(){
    matrix m = createMatrixFromArray((int[]){1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);


}

void swapRowsWithMinAndMaxElements(matrix m){
    position minPosition = getMinValuePos(m);
    position maxPosition = getMaxValuePos(m);

    swapRows(m, minPosition.rowIndex, maxPosition.rowIndex);
}

void test(){
    void test_firstTarget_1();
}

int main() {
    test();

    return 0;
}
