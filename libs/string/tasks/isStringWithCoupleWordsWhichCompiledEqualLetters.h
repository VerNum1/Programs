#ifndef UNTITLED3_ISSTRINGWITHCOUPLEWORDSWHICHCOMPILEDEQUALLETTERS_H
#define UNTITLED3_ISSTRINGWITHCOUPLEWORDSWHICHCOMPILEDEQUALLETTERS_H

#include "../../string/string_.h"

bool isWordsWithEqualLetters(WordDescriptor w1, WordDescriptor w2) {
    while (w1.begin < w1.end) {
        while (w2.begin < w2.end) {
            if (*w1.begin != *w2.begin)
                return false;
            w2.begin++;
        }
        w1.begin++;
    }
    return true;
}

bool isStringWithCoupleWordsWhichCompiledEqualLetters(char *s) {
    getBagOfWords(&_bag, s);
    for (int i = 0; i < _bag.size; ++i)
        for (int j = i + 1; j < _bag.size; ++j)
            if (isWordsWithEqualLetters(_bag.words[i], _bag.words[j]) == 0)
                return true;

    return false;
}

void test_task14() {
    char s[] = "abc gfd gfr cab";

    assert(isStringWithCoupleWordsWhichCompiledEqualLetters(s) == true);
}

#endif
