#ifndef UNTITLED3_ISSTRINGWITHCOUPLEWORDSWHICHCOMPILEDEQUALLETTERS_H
#define UNTITLED3_ISSTRINGWITHCOUPLEWORDSWHICHCOMPILEDEQUALLETTERS_H

#include "../../string/string_.h"

bool isStringWithCoupleWordsWhichCompiledEqualLetters(char *s) {
    *copy_(s, getEndOfString(s), stringBuffer) = '\0';

    getBagOfWords(&_bag, stringBuffer);

    for (int i = 0; i < _bag.size; ++i)
        qsort(_bag.words[i].begin, _bag.words[i].end - _bag.words[i].begin, sizeof(char), cmp);

    return isStringWithCoupleEqualWords(stringBuffer);
}

void test_task14_emptyString() {
    char s[] = "";

    assert(isStringWithCoupleWordsWhichCompiledEqualLetters(s) == false);
}

void test_task14_wordsWithEqualLetters() {
    char s[MAX_STRING_SIZE] = "abc hgf klj cab";

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
