#ifndef UNTITLED3_GETSTRINGWITHWORDSNONEQUALOFLAST_H
#define UNTITLED3_GETSTRINGWITHWORDSNONEQUALOFLAST_H

#include "../../string/string_.h"

void getStringWithWordsNonEqualOfLast(char *s){
    WordDescriptor lastWord;
    getWordReverse(getEndOfString(s), s, &lastWord);

    qsort(lastWord.begin, lastWord.end - lastWord.begin, sizeof(char), cmp);
    deleteWordFromString(s, lastWord);
}


void test_getStringWithWordsNonEqualOfLast_oneWordDelete() {
    char s[] = "hello world";
    getStringWithWordsNonEqualOfLast(s);

    ASSERT_STRING("hello", s);
}

void test_getStringWithWordsNonEqualOfLast() {
    test_getStringWithWordsNonEqualOfLast_oneWordDelete();
}

#endif
