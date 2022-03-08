#ifndef UNTITLED3_ISSTRINGWITHALLLETTERSOFWORD_H
#define UNTITLED3_ISSTRINGWITHALLLETTERSOFWORD_H

#include "../../string/string_.h"

#define MAX_SIZE_ARR 100

bool isStringWithAllLettersOfWord(char *string, char *word) {
    static char arrayOfString[MAX_SIZE_ARR];

    if (*word == '\0' || *string == '\0')
        return false;
    while (*string != '\0') {
        arrayOfString[*string]++;
        string++;
    }
    while (*word != '\0') {
        if (!arrayOfString[*word])
            return false;
        word++;
    }
    return true;
}

void test_isStringWithAllLettersOfWord_hasAllLetters() {
    char s[] = "abc de";
    char word[] = "de";

    assert(isStringWithAllLettersOfWord(s, word) == true);
}

void test_isStringWithAllLettersOfWord_hasNotAllLetters() {
    char s[] = "ab cd ef";
    char word[] = "efg";

    assert(isStringWithAllLettersOfWord(s, word) == false);
}

void test_isStringWithAllLettersOfWord_NoLettersOfWord() {
    char s[] = "abc";
    char word[] = "";

    assert(isStringWithAllLettersOfWord(s, word) == false);
}

void test_isStringWithAllLettersOfWord() {
    test_isStringWithAllLettersOfWord_hasAllLetters();
    test_isStringWithAllLettersOfWord_hasNotAllLetters();
    test_isStringWithAllLettersOfWord_NoLettersOfWord();
}

#endif
