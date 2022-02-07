#include "libs/data_structures/vector/vector.h"

void test_pushBack_fullVector() {
    vector v = createVector(3);
    pushBack(&v, 1);

    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 3);

    clear(&v);
}

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 5);

    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);

    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test_atVector_notEmptyVector(){
    vector v = {(int[5]){1, 3, 5, 7, 9}, 5, 6};

    assert(*atVector(&v, 1) == 3);
}

void test_atVector_requestToLastElement(){
    vector v = {(int[3]){1, 3, 5}, 3, 5};

    assert(*atVector(&v, v.size - 1) == 5);
}

void test_back_oneElementInVector(){
    vector v = {(int[1]) {2}, 1, 1};

    assert(*back(&v) == 2);
}

void test_front_oneElementInVector(){
    vector v = {(int[1]){2}, 1, 1};

    assert(*front(&v) == 2);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();

    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();

    return 0;
}
