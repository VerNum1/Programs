#ifndef UNTITLED3_GETSTRINGWITHWORDSNONEQUALOFLAST_H
#define UNTITLED3_GETSTRINGWITHWORDSNONEQUALOFLAST_H

#include "../../string/string_.h"

void getStringWithWordsNonEqualOfLast(char *string) {

}

void test_getStringWithWordsNonEqualOfLast_oneWord(){
    char s[] = "hello";
    getStringWithWordsNonEqualOfLast(s);

    ASSERT_STRING("", s);
}

void test_getStringWithWordsNonEqualOfLast_oneWordDelete(){
    char s[] = "hello word";
    getStringWithWordsNonEqualOfLast(s);

    ASSERT_STRING("hello", s);
}

void test_getStringWithWordsNonEqualOfLast_manyWords(){
    char s[] = "word hello word";
    getStringWithWordsNonEqualOfLast(s);

    ASSERT_STRING("hello", s);
}

void test_getStringWithWordsNonEqualOfLast(){
    test_getStringWithWordsNonEqualOfLast_oneWord();
    test_getStringWithWordsNonEqualOfLast_oneWordDelete();
    test_getStringWithWordsNonEqualOfLast_manyWords();
}

#endif
