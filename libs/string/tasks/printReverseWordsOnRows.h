#ifndef UNTITLED3_PRINTREVERSEWORDSONROWS_H
#define UNTITLED3_PRINTREVERSEWORDSONROWS_H

void getBagOfWords(BagOfWords *bag, char *s){
    for (int i = 0; i < bag->size; ++i) {
        WordDescriptor w1;
        getWord(s, &w1);
        bag->words[i] = w1;
    }
}

char *copyReverse_(char *rbeginSource, const char *rendSource,
                  char *beginDestination) {
    while (rbeginSource != rendSource) {
        *beginDestination++ = *rbeginSource;
        rbeginSource--;
    }
    return beginDestination;
}

void printReverseWordsOnRows(char *s){
    *copy_(s, getEndOfString(s), stringBuffer) = '\0';
    getBagOfWords(&_bag, stringBuffer);

    char *beginOfString = s;

    for (int i = 0; i < _bag.size; i++) {
        *copyReverse_(_bag.words[i].end - 1, _bag.words[i].begin - 1, beginOfString) = '\0';
        printf("%s \n", beginOfString);
    }
}

void test_printReverseWordsOnRows(){
    char s[] = "Hello word!";

    printReverseWordsOnRows(s);
}

#endif
