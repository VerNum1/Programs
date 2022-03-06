#ifndef UNTITLED3_REMOVENUMBERSANDLETTERS_H
#define UNTITLED3_REMOVENUMBERSANDLETTERS_H

#include "../../string/string_.h"
#include <stdbool.h>

//
void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy_(word.begin, word.end, stringBuffer);
    char *recPosition = copyIf_(stringBuffer, endStringBuffer, word.begin, isdigit);

    copyIf_(stringBuffer, endStringBuffer, recPosition, isalpha);
}

void removeDigitToStart(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

void test_removeDigitToStart_voidString() {
    char s[MAX_STRING_SIZE] = "";
    removeDigitToStart(s);
    ASSERT_STRING("", s);
}

void test_removeDigitToStart_oneWord() {
    char s[MAX_STRING_SIZE] = "Hello12345";
    removeDigitToStart(s);
    ASSERT_STRING("12345Hello", s);
}

void test_removeDigitToStart_onlyLetters() {
    char s[MAX_STRING_SIZE] = "err err";
    removeDigitToStart(s);
    ASSERT_STRING("err err", s);
}

void test_removeDigitToStart_manyNumbersAtWord() {
    char s[MAX_STRING_SIZE] = "Hello12345 12Heel34";
    removeDigitToStart(s);
    ASSERT_STRING("12345Hello 1234Heel", s);
}

void test_removeNumbersAndLetters_() {
    test_removeDigitToStart_voidString();
    test_removeDigitToStart_oneWord();
    test_removeDigitToStart_onlyLetters();
    test_removeDigitToStart_manyNumbersAtWord();
}

#endif
