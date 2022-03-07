#ifndef UNTITLED3_ISSTRINGWITHCOUPLEEQUALWORDS_H
#define UNTITLED3_ISSTRINGWITHCOUPLEEQUALWORDS_H

#include "../../string/string_.h"


bool isStringWithCoupleEqualWords(char *s){
    WordDescriptor w1;
    WordDescriptor w2;

    bool equalWords = getWord(s, &w1);
    if(getWord((w1.end), &w2) == false && equalWords == false)
        return false;

    while (w1.end != '\0'){
        while (w2.end != '\0'){
            if(areWordsEqual_(w1, w2))
                equalWords = false;
            getWord(w2.end, &w2);
        }
        getWord(w1.end, &w1);
    }

    return equalWords;
}

void test_isStringWithCoupleEqualWords_equalWords(){
    char s[] = "abc abc ";

    assert(isStringWithCoupleEqualWords(s) == true);
}

void test_isStringWithCoupleEqualWords_NonEqualWords(){
    char s[] = "abc abs";

    assert(isStringWithCoupleEqualWords(s) == false);
}

void test_isStringWithCoupleEqualWords_emptyString(){
    char s[] = "";

    assert(isStringWithCoupleEqualWords(s) == false);
}

void test_isStringWithCoupleEqualWords(){
    test_isStringWithCoupleEqualWords_equalWords();
    test_isStringWithCoupleEqualWords_NonEqualWords();
    test_isStringWithCoupleEqualWords_emptyString();
}

#endif
