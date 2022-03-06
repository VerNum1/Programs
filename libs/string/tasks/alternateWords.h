#ifndef UNTITLED3_ALTERNATEWORDS_H
#define UNTITLED3_ALTERNATEWORDS_H

#include "../../string/string_.h"

char *alternateWords(char *string1, char *string2, char *s) {
    WordDescriptor w1, w2;
    char *sCopy = s;
    char *beginW1 = string1;
    char *beginW2 = string2;

    bool foundW1, foundW2;

    while ((foundW1 = getWord(beginW1, &w1)),
            (foundW2 = getWord(beginW2, &w2)),
            foundW1 || foundW2) {
        if (foundW1) {
            s = copy_(w1.begin, w1.end, s);
            *s++ = ' ';
            beginW1 = w1.end;
        }
        if (foundW2) {
            s = copy_(w2.begin, w2.end, s);
            *s++ = ' ';
            beginW2 = w2.end;
        }
    }
    if (s != sCopy)
        --s;
    *s = '\0';

    return sCopy;
}

void test_alternatingWords_isEmptyStrings() {
    char s1[] = "";
    char s2[] = "";
    char s3[MAX_STRING_SIZE];

    ASSERT_STRING("", alternateWords(s1, s2, s3));
}

void test_alternatingWords_oneStringEmpty() {
    char s1[] = "absd";
    char s2[] = "";
    char s3[MAX_STRING_SIZE];

    ASSERT_STRING("absd", alternateWords(s1, s2, s3));
}

void test_alternatingWords_() {
    char s1[] = "hello word";
    char s2[] = "hello word";
    char s3[MAX_STRING_SIZE];

    ASSERT_STRING("hello hello word word", alternateWords(s1, s2, s3));
}

void test_alternatingWords_oneWord() {
    char s1[] = "hello";
    char s2[] = "word";
    char s3[MAX_STRING_SIZE];

    ASSERT_STRING("hello word", alternateWords(s1, s2, s3));
}

void test_alternatingWords() {
    test_alternatingWords_isEmptyStrings();
    test_alternatingWords_oneStringEmpty();
    test_alternatingWords_();
    test_alternatingWords_oneWord();
}

#endif
