#ifndef UNTITLED3_REVERSEWORDS_H
#define UNTITLED3_REVERSEWORDS_H

#include "../../string/string_.h"

void reverseWord(char *s) {
    char *copyString = s;
    *copy_(s, getEndOfString(s), stringBuffer) = '\0';
    getBagOfWords(&_bag, stringBuffer);

    for (int i = _bag.size - 1; i >= 0; --i) {
        s = copy_(_bag.words[i].begin, _bag.words[i].end, s);
        *s++ = ' ';
    }
    if (s != copyString)
        --s;

    *s = '\0';
}

void test_reverseWord_emptyString() {
    char s[] = "";
    reverseWord(s);

    ASSERT_STRING("", s);
}

void test_reverseWord_simpleTest() {
    char s[] = "hello world da";
    reverseWord(s);
    ASSERT_STRING("da world hello", s);
}

void test_reverseWord() {
    test_reverseWord_emptyString();
    test_reverseWord_simpleTest();
}

#endif
