#ifndef UNTITLED3_REPLACE_H
#define UNTITLED3_REPLACE_H

#include "../../string/string_.h"

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

    WordDescriptor curWord;
    while (getWord(readPtr, &curWord)) {
        recPtr = copy_(readPtr, curWord.begin, recPtr);
        if (isEqualWords(curWord, word1) == 0) {
            recPtr = copy_(word2.begin, word2.end, recPtr);
        } else {
            recPtr = copy_(curWord.begin, curWord.end, recPtr);
        }
        readPtr = curWord.end;
    }

    *recPtr = '\0';
}

void test_replace(){
    char source[] = "adobe a b c";
    char w1[] = "adobe";
    char w2[]= "pick";

    replace(source, w1, w2);

    ASSERT_STRING("pick a b c", source);
}

#endif
