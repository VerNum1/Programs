#ifndef UNTITLED3_GETLASTWORDFIRSTSTRINGWITCHFOUNDINSECOND_H
#define UNTITLED3_GETLASTWORDFIRSTSTRINGWITCHFOUNDINSECOND_H

#include "../../string/string_.h"


void wordDescriptorToString(WordDescriptor word, char *destination) {
    *copy_(word.begin, word.end, destination) = '\0';
}

WordDescriptor getLastWordFirstStringWitchFoundInSecond(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    for (int i = _bag.size - 1; i >= 0; --i) {
        for (int j = 0; j < _bag2.size; ++j)
            if (isEqualWords(_bag.words[i], _bag2.words[j]) == 0)
                return _bag.words[i];
    }
    WordDescriptor word = {NULL, NULL};

    return word;
}

void test_getLastWordFirstStringWitchFoundInSecond_WordIsFound() {
    char s1[] = "am for fu";
    char s2[] = "gen su fu";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(getLastWordFirstStringWitchFoundInSecond(s1, s2), s3);

    ASSERT_STRING("fu", s3);
}

void test_getLastWordFirstStringWitchFoundInSecond_WordIsNotFound() {
    char s1[] = "abc pascal";
    char s2[] = "hello";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(getLastWordFirstStringWitchFoundInSecond(s1, s2), s3);

    ASSERT_STRING("\0", s3);
}

void test_getLastWordFirstStringWitchFoundInSecond_firstFromTheEndIsFound() {
    char s1[] = "am pm";
    char s2[] = "am st";
    char s3[MAX_STRING_SIZE];
    wordDescriptorToString(getLastWordFirstStringWitchFoundInSecond(s1, s2), s3);

    ASSERT_STRING("am", s3);
}

void test_getLastWordFirstStringWitchFoundInSecond() {
    test_getLastWordFirstStringWitchFoundInSecond_WordIsFound();
    test_getLastWordFirstStringWitchFoundInSecond_WordIsNotFound();
    test_getLastWordFirstStringWitchFoundInSecond_firstFromTheEndIsFound();
}

#endif
