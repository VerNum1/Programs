#ifndef UNTITLED3_GETPALINDROMWORDS_H
#define UNTITLED3_GETPALINDROMWORDS_H

#include "../../string/string_.h"

size_t isPalindromeWord(char *begin, char *end) {
    while (*end - *begin > 0) {
        if (*begin != *end)
            return 0;

        begin++;
        end--;
    }

    return 1;
}

size_t getTotalPalindromesWords(char *s) {
    char *endS = getEndOfString(s);
    char *beginSearch = findNonSpace_(s);

    size_t countPalindromes = 0;

    char *commaPos = find_(beginSearch, endS, ',');

    bool lastComma = *commaPos == '\0' && endS - beginSearch != 0;

    while (*commaPos != '\0' || lastComma) {
        beginSearch = findNonSpace_(beginSearch);

        countPalindromes += isPalindromeWord(beginSearch, commaPos - 1);

        beginSearch = commaPos + 1;

        if (lastComma)
            break;

        commaPos = find_(beginSearch, endS, ',');
        lastComma = *commaPos == '\0';
    }
    return countPalindromes;
}

void test_getTotalPalindromesWords_manyWords(){
    char s[] = "aba,ababa";

    assert(getTotalPalindromesWords(s) == 2);
}

void test_getTotalPalindromesWords_emptyString(){
    char s[] = "";

    assert(getTotalPalindromesWords(s) == 0);
}

void test_getTotalPalindromesWords(){
    test_getTotalPalindromesWords_manyWords();
    test_getTotalPalindromesWords_emptyString();
}

#endif
