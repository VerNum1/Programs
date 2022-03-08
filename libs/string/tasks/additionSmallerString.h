#ifndef UNTITLED3_ADDITIONSMALLERSTRING_H
#define UNTITLED3_ADDITIONSMALLERSTRING_H

#include "../../string/string_.h"

void additionSmallerString(char *s1, char *s2, int n1, int n2) {
    bool isEqualStrings = (n2 == n1);

    char *endS1 = getEndOfString(s1);
    char *endS2 = getEndOfString(s2) - 1;

    WordDescriptor word;
    while (!isEqualStrings) {
        char *beginWord = findSpaceReverse_(endS2, s2);
        getWordReverse(endS2, beginWord, &word);
        *endS1++ = ' ';

        while (word.begin != word.end) {
            *endS1++ = *word.begin++;
        }

        isEqualStrings = n2 == n1;
        endS2 = beginWord - 1;
        n1++;
    }
}

void addMissingWords(char *string1, char *string2, int n1, int n2) {
    if (n2 > n1) {
        additionSmallerString(string1, string2, n1, n2);

    } else if (n1 > n2) {
        additionSmallerString(string2, string1, n2, n1);

    }
}

void test_additionSmallerString_firstStringMore() {
    char s1[MAX_STRING_SIZE] = "hello world";
    char s2[MAX_STRING_SIZE] = "empty string of";

    addMissingWords(s1, s2, 2, 4);

    ASSERT_STRING("hello world of string empty", s1);
}

void test_additionSmallerString_oneWord() {
    char s1[MAX_STRING_SIZE] = "abs";
    char s2[MAX_STRING_SIZE] = "";

    addMissingWords(s1, s2, 1, 0);

    ASSERT_STRING("abs", s2);
}

void test_additionSmallerString_emptyStrings() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";

    addMissingWords(s1, s2, 0, 0);

    ASSERT_STRING("", s1);
    ASSERT_STRING("", s2);
}


void test_additionSmallerString() {
    test_additionSmallerString_firstStringMore();
    test_additionSmallerString_emptyStrings();
    test_additionSmallerString_oneWord();
}

#endif
