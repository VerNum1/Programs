#ifndef UNTITLED3_REPLACEMENTNUMBERSTOSPACE_H
#define UNTITLED3_REPLACEMENTNUMBERSTOSPACE_H

#define ZERO 48

void replacementNumbersToSpaces(char *s) {
    char *endSource = getEndOfString(s);
    char *stringBufferStart = stringBuffer;
    char *StringBufferEnd = copy_(s, endSource, stringBufferStart);

    *StringBufferEnd = '\0';

    while (*stringBufferStart != '\0') {
        if (isalpha(*stringBufferStart))
            *s++ = *stringBufferStart;
        else if (isdigit(*stringBufferStart)) {
            while (*stringBufferStart - ZERO > 0) {
                (*s++) = ' ';

                (*stringBufferStart)--;
            }
        }

        ++stringBufferStart;
    }
}

void test_replacementNumbersToSpaces_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    replacementNumbersToSpaces(s);
    ASSERT_STRING("", s);
}

void test_replacementNumbersToSpaces_onlyLetters() {
    char s[MAX_STRING_SIZE] = "asd";
    replacementNumbersToSpaces(s);
    ASSERT_STRING("asd", s);
}

void test_replacementNumbersToSpaces_onlyDigits() {
    char s[MAX_STRING_SIZE] = "123";
    replacementNumbersToSpaces(s);
    ASSERT_STRING("      ", s);
}

void test_replacementNumbersToSpaces_simple() {
    char s[MAX_STRING_SIZE] = "z0x1y2";
    replacementNumbersToSpaces(s);
    ASSERT_STRING("zx y  ", s);
}

void test_replacementNumbersToSpaces() {
    test_replacementNumbersToSpaces_emptyString();
    test_replacementNumbersToSpaces_onlyLetters();
    test_replacementNumbersToSpaces_onlyDigits();
    test_replacementNumbersToSpaces_simple();
}


#endif
