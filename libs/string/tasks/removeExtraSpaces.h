#ifndef UNTITLED3_REMOVEEXTRASPACES_H
#define UNTITLED3_REMOVEEXTRASPACES_H

#include "../../string/string_.h"

void removeExtraSpaces(char *s) {
    char *begin = s;
    char *element = begin;
    char last = *begin;

    while (*begin != '\0') {
        if (*begin != last || last != ' ')
            *element++ = *begin;

        last = *begin++;
    }

    if (last == ' ')
        element--;

    *element = '\0';
}

void test_removeExtraSpaces_(){
    char s[] = "He    ll     o";
    removeExtraSpaces(s);
    ASSERT_STRING(s, "He ll o");
}

void test_removeExtraSpaces_noSpaces(){
    char s[] = "removeExtraSpaces";
    removeExtraSpaces(s);
    ASSERT_STRING(s, "removeExtraSpaces");
}

void test_removeExtraSpaces_allSpaces(){
    char s[] = "    ";
    removeExtraSpaces(s);
    ASSERT_STRING(s, "    ");
}

void test_removeExtraSpaces(){
    test_removeExtraSpaces_();
    test_removeExtraSpaces_noSpaces();
    test_removeExtraSpaces_allSpaces();
}
#endif
