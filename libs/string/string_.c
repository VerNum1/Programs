#include "string_.h"

size_t strlen_(char *begin) {
    char *end = begin;

    while (*end != '\0')
        end++;

    return end - begin;
}

char *find_(char *begin, const char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace_(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char *findSpace_(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char *findNonSpaceReverse_(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;
    return rbegin;
}

char *findSpaceReverse_(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;
    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return (unsigned char) *lhs - (unsigned char) *rhs;
}

char *copy_(const char *beginSource, const char *endSource,
            char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);

    return beginDestination + (endSource - beginSource);
}

char *copyIf_(char *beginSource, const char *endSource,
              char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }

    return beginDestination;
}

char *copyIfReverse_(char *rbeginSource, const char *rendSource,
                     char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }
        rbeginSource--;
    }

    return beginDestination;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse_(rbegin, rend) + 1;
    if (word->end == rend)
        return false;

    word->begin = findSpaceReverse_(word->end - 1, rend) + 1;
    return true;
}

bool getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace_(beginSearch);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace_(word->begin);

    return true;
}

void reverseDigitToStart(WordDescriptor word) {
    char *endStringBuffer = copy_(word.begin, word.end, stringBuffer);
    char *recPosition = copyIfReverse_(endStringBuffer - 1, stringBuffer - 1, word.begin, isdigit);
    copyIf_(stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToEnd(WordDescriptor word) {
    char *endStringBuffer = copy_(word.begin, word.end, stringBuffer);
    char *recPosition = copyIf_(endStringBuffer - 1, stringBuffer - 1, word.begin, isalpha);
    copyIf_(stringBuffer, endStringBuffer, recPosition, isdigit);
}

void reverseDigitToEnd(WordDescriptor word) {
    char *endStringBuffer = copy_(word.begin, word.end, stringBuffer);
    char *recPosition = copyIf_(endStringBuffer - 1, stringBuffer - 1, word.begin, isalpha);
    copyIfReverse_(stringBuffer, endStringBuffer, recPosition, isdigit);
}

bool areWordsEqual_(WordDescriptor w1, WordDescriptor w2){
    if (strcmp_(w1.begin, w2.begin) < 0)
        return false;
    return true;
}

bool isEqualWords(WordDescriptor w1, WordDescriptor w2) {
    while (w1.begin != w1.end - 1 && (*w1.begin == *w2.begin)) {
        (w1.begin)++;
        (w2.begin)++;
    }

    return *w1.begin - *w2.begin;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    bag->size = 0;
    WordDescriptor word;
    while (getWord(s, &word)) {
        bag->words[bag->size] = word;
        bag->size++;
        s = word.end;
    }
}

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s \"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void deleteWordFromString(char *string, WordDescriptor deleteWord) {
    char *copyS = string;
    char *copyS1 = string;

    WordDescriptor currentWord;

    while (getWord(copyS, &currentWord)) {
        if (isEqualWords(currentWord, deleteWord) != 0) {
            string = copy_(currentWord.begin, currentWord.end, string);
            *string++ = ' ';
        }
        copyS = currentWord.end;
    }

    if (string != copyS1)
        --string;
    *string = '\0';
}

int cmp(const void *a, const void *b) {
    return *(const char *) a - *(const char *) b;
}
