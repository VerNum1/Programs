#ifndef UNTITLED3_GETSTRINGWITHWORDSNONEQUALOFLAST_H
#define UNTITLED3_GETSTRINGWITHWORDSNONEQUALOFLAST_H

#include "../../string/string_.h"

void getStringWithWordsNonEqualOfLast(char *string) {
    char *copyS1 = string;
    char *copyS2 = string;
    WordDescriptor lastWord;
    getWordReverse(getEndOfString(string), string - 1, &lastWord);
    WordDescriptor currentWord;
    while (getWord(copyS1, &currentWord)) {
        if (isEqualWords(currentWord, lastWord) != 0) {
            string = copy_(currentWord.begin, currentWord.end, string);
            *string++ = ' ';
        }
        copyS1 = currentWord.end;
    }
    if (string != copyS2)
        --string;
    *string = '\0';
}

void test_getStringWithWordsNonEqualOfLast_oneWord() {
    char s[] = "hello";
    getStringWithWordsNonEqualOfLast(s);

    ASSERT_STRING("", s);
}

void test_getStringWithWordsNonEqualOfLast_oneWordDelete() {
    char s[] = "hello word";
    getStringWithWordsNonEqualOfLast(s);

    ASSERT_STRING("hello", s);
}

void test_getStringWithWordsNonEqualOfLast_manyWords() {
    char s[] = "word hello word";
    getStringWithWordsNonEqualOfLast(s);

    ASSERT_STRING("hello", s);
}

void test_getStringWithWordsNonEqualOfLast() {
    test_getStringWithWordsNonEqualOfLast_oneWord();
    test_getStringWithWordsNonEqualOfLast_oneWordDelete();
    test_getStringWithWordsNonEqualOfLast_manyWords();
}

#endif
