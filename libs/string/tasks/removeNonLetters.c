#include "removeNonLetters.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_() {
    char s[] = " H e l l o ";

    removeNonLetters(s);

    ASSERT_STRING("Hello", s);
}