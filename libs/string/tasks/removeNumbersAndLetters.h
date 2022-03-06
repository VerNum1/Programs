#ifndef UNTITLED3_REMOVENUMBERSANDLETTERS_H
#define UNTITLED3_REMOVENUMBERSANDLETTERS_H

#include "../../string/string_.h"
#include <stdbool.h>

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

bool getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace_(beginSearch);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace_(word->begin);

    return true;
}

bool getWordReverse(char *rbegin, const char *rend, WordDescriptor *word) {
    word->begin = findNonSpaceReverse_(rbegin, rend);
    if (word->begin == rend)
        return false;

    word->end = findNonSpaceReverse_(word->begin, rend);

    return true;
}

void reverseDigitToStart(WordDescriptor word) {
    char *endStringBuffer = copy_(word.begin, word.end, stringBuffer);
    char *recPosition = copyIfReverse_(endStringBuffer - 1, stringBuffer - 1, word.begin, isdigit);
    copyIf_(stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToEnd(WordDescriptor word) {
    char *endStringBuffer = copy_(word.begin, word.end, stringBuffer);
    char *recPosition = copyIf_(endStringBuffer - 1, stringBuffer - 1, word.begin, isalpha);
    copyIf_(stringBuffer, endStringBuffer, recPosition, isdigit);
}

void reverseDigitToEnd(WordDescriptor word) {
    char *endStringBuffer = copy_(word.begin, word.end, stringBuffer);
    char *recPosition = copyIf_(endStringBuffer - 1, stringBuffer - 1, word.begin, isalpha);
    copyIfReverse_(stringBuffer, endStringBuffer, recPosition, isdigit);
}

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
    char s[MAX_STRING_SIZE] = "Hi123 4Rand56";
    removeDigitToStart(s);
    ASSERT_STRING("123Hi 456Rand", s);
}

void test_removeNumbersAndLetters_() {
    test_removeDigitToStart_voidString();
    test_removeDigitToStart_oneWord();
    test_removeDigitToStart_onlyLetters();
    test_removeDigitToStart_manyNumbersAtWord();
}

#endif
