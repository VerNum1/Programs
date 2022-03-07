#ifndef UNTITLED3_PRINTWORDBEFOREFIRSTWORDWITHA_H
#define UNTITLED3_PRINTWORDBEFOREFIRSTWORDWITHA_H

#include "../../string/string_.h"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWord, char **endWord) {
    WordDescriptor word1;
    WordDescriptor word2;
    char *begin = s;

    if (!getWord(begin, &word1))
        return EMPTY_STRING;

    else if (find_(word1.begin, word1.end, 'a') != word1.end)
        return FIRST_WORD_WITH_A;

    while (getWord(begin, &word2)) {
        if (find_(word2.begin, word2.end, 'a') != word2.end) {
            *beginWord = word1.begin;
            *endWord = word1.end;

            return WORD_FOUND;
        }
        begin = word1.end;
        word1 = word2;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void test_getWordBeforeFirstWordWithA() {
    char *beginWord, *endWord;

    char s1[] = "";
    assert (getWordBeforeFirstWordWithA(s1, &beginWord, &endWord)
            == EMPTY_STRING);

    char s2[] = "abs";
    assert (getWordBeforeFirstWordWithA(s2, &beginWord, &endWord)
            == FIRST_WORD_WITH_A);

    char s3[] = "bc a";
    assert (getWordBeforeFirstWordWithA(s3, &beginWord, &endWord)
            == WORD_FOUND);

    char got[MAX_WORD_SIZE];
    copy_(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING ("bc", got);

    char s4[] = "B Q WE YR OW IUWR ";
    assert (getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) ==
            NOT_FOUND_A_WORD_WITH_A);
}

#endif
