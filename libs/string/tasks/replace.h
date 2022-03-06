#ifndef UNTITLED3_REPLACE_H
#define UNTITLED3_REPLACE_H

#include "../../string/string_.h"



void replacesWord(char *source, WordDescriptor word1, WordDescriptor word2, size_t w2Size) {
    while (w2Size != 0) {
        *source = *word2.begin;
        w2Size--;
    }
    while (word1.end - 1 - word2.begin != 0) {
        *source = ' ';
        word2.begin++;
    }
}
void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen(w1);
    size_t w2Size = strlen(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy_(source, getEndOfString(source), stringBuffer);
        readPtr = stringBuffer;
        recPtr = source;
    }
    char *copySource = source;
    size_t copyW2Size = w2Size;

}
void test_replace(){
    char source[] = "adobe a b c ";
    char w1[] = "adobe";
    char w2[]= "pick";

    replace(source, w1, w2);

    ASSERT_STRING("pick a b c ", source);
}

#endif
