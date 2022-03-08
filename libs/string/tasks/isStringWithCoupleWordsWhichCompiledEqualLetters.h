#ifndef UNTITLED3_ISSTRINGWITHCOUPLEWORDSWHICHCOMPILEDEQUALLETTERS_H
#define UNTITLED3_ISSTRINGWITHCOUPLEWORDSWHICHCOMPILEDEQUALLETTERS_H

#include "../../string/string_.h"

bool isWordsWithEqualLetters(WordDescriptor w1, WordDescriptor w2) {
    bool isEqual = true;
    while (*w1.begin < *w1.end) {
        while (*w2.begin < *w2.end) {
            if (w1.begin != w2.begin)
                isEqual = false;
            (*w2.begin)++;
        }
        (*w1.begin)++;
    }

    return isEqual;
}

bool isStringWithCoupleWordsWhichCompiledEqualLetters(char *s) {
    if (*findNonSpace_(s) == '\0')
        return false;

    getBagOfWords(&_bag, s);
    for (int i = 0; i < _bag.size; ++i)
        for (int j = i + 1; j < _bag.size; ++j)
            if (isWordsWithEqualLetters(_bag.words[i], _bag.words[j]) == 0)
                return false;

    return true;
}

void test_task14_emptyString() {
    char s[] = "";

    assert(isStringWithCoupleWordsWhichCompiledEqualLetters(s) == false);
}

void test_task14_wordsWithEqualLetters() {
    char s[MAX_STRING_SIZE] = "abc cab";

    assert(isStringWithCoupleWordsWhichCompiledEqualLetters(s) == true);
}

void test_task14_wordsWithNonEqualLetters() {
    char s[MAX_STRING_SIZE] = "abc ytr";

    assert(isStringWithCoupleWordsWhichCompiledEqualLetters(s) == false);
}

void test_task14() {
    test_task14_emptyString();
    test_task14_wordsWithEqualLetters();
    test_task14_wordsWithNonEqualLetters();
}

#endif
