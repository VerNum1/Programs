#ifndef UNTITLED3_GETLASTWORDFIRSTSTRINGINSECOND_H
#define UNTITLED3_GETLASTWORDFIRSTSTRINGINSECOND_H

#include "../../string/string_.h"

void wordDescriptorToString(WordDescriptor word, char *destination) {
    *copy(word.begin, word.end, destination) = '\0';
}


#endif
