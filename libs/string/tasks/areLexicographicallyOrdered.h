#ifndef UNTITLED3_ARELEXICOGRAPHICALLYORDERED_H
#define UNTITLED3_ARELEXICOGRAPHICALLYORDERED_H

#include "../../string/string_.h"

bool areLexicographicallyOrdered(char *s){
    WordDescriptor w1;
    WordDescriptor w2;
    if (getWord(s, &w1)) {
        w2 = w1;
        while (getWord(s, &w1)) {
            if (!areWordsEqual_(w1, w2))
                return false;
            w2 = w1;
            s = w1.end;
        }
        return true;
    } else
        return true;
}

void test_areLexicographicallyOrdered_emptyString() {
    char s[] = "";
    assert(areLexicographicallyOrdered(s) == true);
}

void test_areWordsOrdered_oneWord() {
    char s[] = "one";
    assert(areLexicographicallyOrdered(s) == true);
}

void test_areLexicographicallyOrdered_notOrderedString() {
    char s[] = "hahaha aaaaa";
    assert(areLexicographicallyOrdered(s) == false);
}

void test_areLexicographicallyOrdered_orderedString() {
    char s[] = "a ab bcs cs ss";
    assert(areLexicographicallyOrdered(s) == true);
}

void test_areLexicographicallyOrdered(){
    test_areLexicographicallyOrdered_emptyString();
    test_areWordsOrdered_oneWord();
    test_areLexicographicallyOrdered_notOrderedString();
    test_areLexicographicallyOrdered_orderedString();
}

#endif
