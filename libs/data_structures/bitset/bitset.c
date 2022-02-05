#include "bitset.h"
#include <assert.h>
#include <stdio.h>

bitset bitset_create(uint32_t maxValue) {
    assert(maxValue < 32);
    return (bitset) {0, maxValue};
}

void bitset_inputValues(bitset *set) {
    scanf("%u", &set->values);
}

bool bitset_checkValue(bitset set, uint32_t x) {
    return x >= 0 && x <= set.maxValue;
}

bool bitset_in(bitset set, uint32_t x) {
    assert(bitset_checkValue(set, x));
    return set.values >> x & 1;
}

bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values;
}

bool bitset_isSubset(bitset subset, bitset set) {
    return subset.values <= set.values && (set.values & subset.values) > 0;
}

void bitset_insert(bitset *set, uint32_t x) {
    assert(bitset_checkValue(*set, x));
    set->values |= 1 << x;
}

void bitset_deleteElement(bitset *set, uint32_t x) {
    set->values &= ~(1 << x);
}

bitset bitset_union(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values | set2.values, set1.maxValue};
}

bitset bitset_intersection(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & set2.values, set1.maxValue};

}

bitset bitset_difference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & ~(set2.values), set1.maxValue};
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values ^ set2.values, set1.maxValue};
}

bitset bitset_complement(bitset set) {
    return (bitset) {~set.values, set.maxValue};
}

void bitset_print(bitset set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i <= set.maxValue; ++i) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = 0;
        }
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}
