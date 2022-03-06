#ifndef UNTITLED3_REVERSEWORDS_H
#define UNTITLED3_REVERSEWORDS_H

#include "../../string/string_.h"

int isNonSpace(char s) {
    if (s != ' ')
        return 1;
    return 0;
}

void reverseWord(char *s) {
    WordDescriptor word;
    char *endOfStringBuffer = copy_(s, getEndOfString(s), stringBuffer);


    char *beginCopy = s;

    while (getWordReverse(endOfStringBuffer, s, &word)) {
        beginCopy = copyIf_(word.begin - 1, word.end + (*word.end != '\0'), beginCopy, isNonSpace);

        *beginCopy = ' ';
        beginCopy++;
        endOfStringBuffer = word.begin - 1;
    }
}

void test_reverseWord_emptyString() {
    char s[] = "";
    reverseWord(s);

    ASSERT_STRING(s, "");
}

void test_reverseWord_() {
    char s[] = "hello word";
    reverseWord(s);

    ASSERT_STRING(s, "word hello");
}

void test_reverseWord() {
    //test_reverseWord_emptyString();
    //test_reverseWord_();
}

#endif
