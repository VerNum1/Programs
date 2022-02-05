#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"

void test() {

}

int main() {
    vector v = createVector(15);
    reserve(&v, 15);
    clear(&v);

    printf("%d", (v).capacity);

    return 0;
}
