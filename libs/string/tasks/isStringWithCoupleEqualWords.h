#ifndef UNTITLED3_ISSTRINGWITHCOUPLEEQUALWORDS_H
#define UNTITLED3_ISSTRINGWITHCOUPLEEQUALWORDS_H

#include "../../string/string_.h"

int isEqualWords(WordDescriptor w1, WordDescriptor w2) {
    char *begin1 = w1.begin;
    char *begin2 = w2.begin;
    while (begin1 != w1.end - 1 && (*begin1 == *begin2))
        begin1++, begin2++;

    return *begin1 - *begin2;
}

bool isStringWithCoupleEqualWords(char *s) {
    getBagOfWords(&_bag, s);
    for (int i = 0; i < _bag.size; ++i)
        for (int j = i + 1; j < _bag.size; ++j)
            if (isEqualWords(_bag.words[i], _bag.words[j]) == 0)
                return true;

    return false;
}

void test_isStringWithCoupleEqualWords_equalWords() {
    char s[] = "AAA AAA  AAb AAb";

    assert(isStringWithCoupleEqualWords(s) == true);
}

void test_isStringWithCoupleEqualWords_NonEqualWords() {
    char s[] = "abc abs";

    assert(isStringWithCoupleEqualWords(s) == false);
}

void test_isStringWithCoupleEqualWords_emptyString() {
    char s[] = "";

    assert(isStringWithCoupleEqualWords(s) == false);
}

void test_isStringWithCoupleEqualWords() {
    test_isStringWithCoupleEqualWords_equalWords();
    test_isStringWithCoupleEqualWords_NonEqualWords();
    test_isStringWithCoupleEqualWords_emptyString();
}

#endif
