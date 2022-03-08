#ifndef UNTITLED3_PRINTREVERSEWORDSONROWS_H
#define UNTITLED3_PRINTREVERSEWORDSONROWS_H

char *copyReverse_(char *rbeginSource, const char *rendSource, char *beginDestination) {
    while (rbeginSource != rendSource) {
        *beginDestination++ = *rbeginSource;
        rbeginSource--;
    }
    return beginDestination;
}

void printReverseWordsOnRows(char *s) {
    *copy_(s, getEndOfString(s), stringBuffer) = '\0';
    getBagOfWords(&_bag, stringBuffer);
    char *word = s;

    for (int i = 0; i < _bag.size; i++) {
        *copyReverse_(_bag.words[i].end - 1, _bag.words[i].begin - 1, word) = '\0';
        printf("%s \n", word);
    }
}

void test_printReverseWordsOnRows() {
    char s[] = "Hello word";

    printReverseWordsOnRows(s);
}

#endif
