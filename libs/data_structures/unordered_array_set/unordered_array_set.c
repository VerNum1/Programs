#include "unordered_array_set.h"

#ifndef UNTITLED3_UNORDERED_ARRAY_SET_H
#define UNTITLED3_UNORDERED_ARRAY_SET_H

int compare_ints1(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

static void unordered_array_set_shrinkToFit ( unordered_array_set * a ) {
     if (a-> size != a ->capacity ) {
         a-> data = ( int *) realloc (a-> data , sizeof (int) * a-> size ) ;
         a-> capacity = a-> size ;
         }
     }


unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {malloc(capacity * sizeof(int)), 0, capacity};
}

unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (register size_t i = 0; i < size; i++)
        unordered_array_set_insert(&set, a[i]);
    unordered_array_set_shrinkToFit(&set);

    return set;
}

size_t unordered_array_set_in(unordered_array_set *set, int value) {
    size_t getIndexNumber = linearSearch_(set->data, set->size, value);
    return getIndexNumber != set->size ? getIndexNumber : set->size;
}

int unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size)
        return 0;
    qsort(set1.data, set1.size, sizeof(int) * set1.size, compare_ints1);
    qsort(set2.data, set2.size, sizeof(int) * set2.size, compare_ints1);

    return memcmp(set1.data, set2.data, set1.size) == 0;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    if (unordered_array_set_in(set, value) == set->size) {
        unordered_array_set_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}

void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t indexValue = unordered_array_set_in(set, value);
    assert(set->size != indexValue);
    set->data[set->size - 1] = set->data[indexValue];
    set->size--;

    unordered_array_set_shrinkToFit(set);
}

unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    size_t sizeOfSet3 = set1.size;
    int *set3 = (int *) malloc(sizeOfSet3 * sizeof(int));
    memcpy(set3, set1.data, set1.size * sizeof(int));
    size_t i = 0;
    while (i < set1.size) {
        if (unordered_array_set_in(&set2, set1.data[i]) == set2.size)
            append_(set3, &sizeOfSet3, set2.data[i]);
        i++;
    }

    unordered_array_set_shrinkToFit(&(unordered_array_set) {set3, sizeOfSet3,
                                                                 set1.capacity});
    return (unordered_array_set) {set3, sizeOfSet3, set1.capacity};
}


unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    size_t sizeOfSet3 = set1.size;
    int *set3 = (int *) malloc(sizeOfSet3 * sizeof(int));
    size_t i = 0;
    while (i < set1.size) {
        if (unordered_array_set_in(&set2, set1.data[i]) == set2.size)
            append_(set3, &sizeOfSet3, set2.data[i]);
        i++;
    }

    return (unordered_array_set) {set3, sizeOfSet3, set2.capacity};
}


unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    int *set3 = (int *) malloc(set1.size * sizeof(int));
    size_t newSize = set1.size;
    size_t i = 0;
    while (i < set2.size) {
        size_t j = unordered_array_set_in(&set1, set2.data[i]);
        if (j != newSize)
            append_(set3, &newSize, set1.data[i]);
        else
            newSize--;
        i++;
    }
    unordered_array_set_shrinkToFit(&(unordered_array_set) {set3,
                                                                 newSize, set1.capacity});
    return (unordered_array_set) {set3, newSize, set1.capacity};
}


unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set totalSet1 = unordered_array_set_difference(set1, set2);
    unordered_array_set totalSet2 = unordered_array_set_difference(set2, set1);

    unordered_array_set difference = unordered_array_set_union(totalSet1, totalSet2);
    unordered_array_set_delete(totalSet1);
    unordered_array_set_delete(totalSet2);

    return difference;
}

unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    return unordered_array_set_union(set, universumSet);
}

void unordered_array_set_print(unordered_array_set set) {
    printf("{");

    for (register size_t i = 0; i < set.size; i++)
        printf("%d, ", set.data[i]);

    if (set.size == 0)
        printf("}");
    else
        printf("\b\b}\n");
}

void unordered_array_set_delete(unordered_array_set set) { free(set.data); }

void test_unordered_array_set_in1() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {4, 1, 3, 8}, 4);
    int value = 8;
    size_t resultSet = unordered_array_set_in(&set, value);
    size_t requiredSet = 3;

    assert(requiredSet == resultSet);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in2() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -4}, 4);
    int value = -2;
    size_t resultSet = unordered_array_set_in(&set, value);
    size_t requiredSet = 2;

    assert(requiredSet == resultSet);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in3() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -4, 1, 3, 2, 4, -1}, 9);
    int value = 1;
    size_t resultSet = unordered_array_set_in(&set, value);
    size_t requiredSet = 4;
    assert(requiredSet == resultSet);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in() {
    test_unordered_array_set_in1();
    test_unordered_array_set_in2();
    test_unordered_array_set_in3();
}

void test_unordered_array_set_insert1() {
    unordered_array_set resultSet = unordered_array_set_create_from_array((int[]) {1, 3, 2, 4}, 5);
    int value = 1;
    unordered_array_set_insert(&resultSet, value);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {1, 3, 2, 4, 1}, 5);
    assert(unordered_array_set_isEqual(requiredSet, resultSet));

    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_insert2() {
    unordered_array_set resultSet = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -4}, 4);
    int value = -4;
    unordered_array_set_insert(&resultSet, value);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -4 }, 4);
    assert(unordered_array_set_isEqual(requiredSet, resultSet));

    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_insert3() {
    unordered_array_set resultSet = unordered_array_set_create_from_array((int[]) {-5, -4, -1, -3}, 5);
    int value = 10;
    unordered_array_set_insert(&resultSet, value);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {-5, -4, -1, -3, 10}, 5);
    assert(unordered_array_set_isEqual(requiredSet, resultSet));

    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_insert() {
    test_unordered_array_set_insert1();
    test_unordered_array_set_insert2();
    test_unordered_array_set_insert3();
}

void test_unordered_array_set_deleteElement1() {
    unordered_array_set resultSet = unordered_array_set_create_from_array((int[]) {-1, -4, -3, -2}, 4);
    int value = -9;
    unordered_array_set_deleteElement(&resultSet, value);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {-1, -4, -3, -2}, 4);
    assert(unordered_array_set_isEqual(requiredSet, resultSet));

    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_deleteElement2() {
    unordered_array_set resultSet = unordered_array_set_create_from_array((int[]) {1, 2, 6, 4}, 4);
    int value = 4;
    unordered_array_set_deleteElement(&resultSet, value);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {1, 2, 4}, 3);
    assert(unordered_array_set_isEqual(requiredSet, resultSet));

    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_deleteElement3() {
    unordered_array_set resultSet = unordered_array_set_create_from_array((int[]) {-1, -2, 1, 3}, 4);
    int value = 1;
    unordered_array_set_deleteElement(&resultSet, value);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {-1, -2, 3}, 3);
    assert(unordered_array_set_isEqual(requiredSet, resultSet));

    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_deleteElement() {
    test_unordered_array_set_deleteElement1();
    test_unordered_array_set_deleteElement2();
    test_unordered_array_set_deleteElement3();
}

void test_unordered_array_set_union1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-3, -1, -2, -4}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {3, 1, 2}, 3);
    unordered_array_set resultSet = unordered_array_set_union(set1, set2);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {-3, -1, -2, -4, 3, 1, 2}, 7);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_union2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-1, -2, -3, -5}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-3, -2, -1}, 3);
    unordered_array_set resultSet = unordered_array_set_union(set1, set2);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {-1, -2, -3, -5}, 4);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_union3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-3, -2, -1, -5}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-1, 2, 3}, 3);
    unordered_array_set resultSet = unordered_array_set_union(set1, set2);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {-3, -2, -1, -5, 2, 3}, 6);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_union() {
    test_unordered_array_set_union1();
    test_unordered_array_set_union2();
    test_unordered_array_set_union3();
}

void test_unordered_array_set_intersection1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-3, -2, -1, -4}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {3, 1, 2}, 3);
    unordered_array_set resultSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {0}, 0);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_intersection2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-1, -2, -3, 1}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-1, 2, 3}, 3);
    unordered_array_set resultSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {-1}, 1);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_intersection3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-1, -3, -2, -4, 1, 3, 2, 4, 6}, 8);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-3, 2, 4, 7}, 4);
    unordered_array_set resultSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {-3, 2, 4}, 3);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_intersection() {
    test_unordered_array_set_intersection1();
    test_unordered_array_set_intersection2();
    test_unordered_array_set_intersection3();
}

void test_unordered_array_set_difference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {0, 3, 2, 1}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {3, 1, 2}, 3);
    unordered_array_set resultSet = unordered_array_set_difference(set1, set2);
    unordered_array_set_print(resultSet);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {0}, 1);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_difference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {6, 2, 4, -1}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {0, 1, 2}, 3);
    unordered_array_set resultSet = unordered_array_set_difference(set1, set2);
    unordered_array_set_print(resultSet);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {6, 4, -1}, 3);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_difference3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-1, -3, -2, 0, 6, 1}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-3, 2, 1, 6, 3}, 5);
    unordered_array_set resultSet = unordered_array_set_difference(set1, set2);
    unordered_array_set_print(resultSet);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {-1, -2, 0}, 3);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_difference() {
    test_unordered_array_set_difference1();
    test_unordered_array_set_difference2();
    test_unordered_array_set_difference3();
}

void test_unordered_array_set_symmetricDifference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {5, 6, 7, 2, 3}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-1, 2, 5, 6, 7}, 5);
    unordered_array_set resultSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {-1, 3}, 2);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_symmetricDifference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {3, 2, 1, -3, -2, -1}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 3, -1}, 4);
    unordered_array_set resultSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {-3, -2}, 2);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_symmetricDifference3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-4, -5, 5, 6, -2}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-2, 6, 5, -5, -4}, 5);
    unordered_array_set resultSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {0}, 0);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_symmetricDifference() {
    test_unordered_array_set_symmetricDifference1();
    test_unordered_array_set_symmetricDifference2();
    test_unordered_array_set_symmetricDifference3();
}

void test_unordered_array_set_complement1() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 3, 5}, 3);
    unordered_array_set setUniverse = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set resultSet = unordered_array_set_symmetricDifference(set, setUniverse);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set);
    unordered_array_set_delete(setUniverse);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_complement2() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {3, 2, 4, 2, 5}, 5);
    unordered_array_set setUniverse = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set resultSet = unordered_array_set_symmetricDifference(set, setUniverse);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set);
    unordered_array_set_delete(setUniverse);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_complement3() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {0}, 0);
    unordered_array_set setUniverse = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set resultSet = unordered_array_set_symmetricDifference(set, setUniverse);
    unordered_array_set requiredSet = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    assert(unordered_array_set_isEqual(resultSet, requiredSet));

    unordered_array_set_delete(set);
    unordered_array_set_delete(setUniverse);
    unordered_array_set_delete(resultSet);
    unordered_array_set_delete(requiredSet);
}

void test_unordered_array_set_complement() {
    test_unordered_array_set_complement1();
    test_unordered_array_set_complement2();
    test_unordered_array_set_complement3();
}

void test_unordered_array_set() {
    test_unordered_array_set_in();
    test_unordered_array_set_insert();
    test_unordered_array_set_deleteElement();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_complement();
}

#endif //UNTITLED3_UNORDERED_ARRAY_SET_H

