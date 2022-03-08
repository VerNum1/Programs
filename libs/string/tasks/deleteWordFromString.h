#ifndef UNTITLED3_DELETEWORDFROMSTRING_H
#define UNTITLED3_DELETEWORDFROMSTRING_H

#include "../../string/string_.h"


void test_deleteWordFromString_oneWord() {
    char s[] = "hello word word world";
    //
    char wordInDeleteString[] = "word";
    WordDescriptor word;
    getWord(wordInDeleteString, &word);
    //
    deleteWordFromString(s, word);

    ASSERT_STRING("hello world", s);
}

#endif
