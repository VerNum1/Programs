#ifndef UNTITLED3_REVERSEWORDS_H
#define UNTITLED3_REVERSEWORDS_H

#include "../../string/string_.h"

int isNonSpace(char *s) {
    if (isspace(*s))
        return 0;
    return 1;
}

void reverseWord(char *string) {

}

void test_reverseWord_emptyString() {
    char s[] = "";
    reverseWord(s);

    ASSERT_STRING("", s);
}

void test_reverseWord_simpleTest() {
    char s[] = "hello world";
    reverseWord(s);
    ASSERT_STRING("word hello", s);
}

void test_reverseWord() {
    test_reverseWord_emptyString();
    test_reverseWord_simpleTest();
}

#endif
