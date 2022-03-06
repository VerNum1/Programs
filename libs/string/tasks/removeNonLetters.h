#ifndef UNTITLED3_REMOVENONLETTERS_H
#define UNTITLED3_REMOVENONLETTERS_H

#include "../../string/string_.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf_(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_() {
    char s[] = " H e l l o ";

    removeNonLetters(s);

    ASSERT_STRING("Hello", s);
}

void test_removeNonLetters_noSpaces() {
    char s[] = "hello";
    removeNonLetters(s);
    ASSERT_STRING("hello", s);
}

void test_removeNonLetters_allSpaces() {
    char s[] = "      ";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters(){
    test_removeNonLetters_();
    test_removeNonLetters_noSpaces();
    test_removeNonLetters_allSpaces();
}
#endif
