#ifndef UNTITLED3_STRING__H
#define UNTITLED3_STRING__H

#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <string.h>
#include <assert.h>

#include "../../libs/algorithms/algorithms.h"

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__ , __FUNCTION__ , __LINE__ )

char stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

BagOfWords _bag;
BagOfWords _bag2;


// возвращает количество символов в строке
// (не считая ноль-символ)
size_t strlen_(char *begin);

// возвращает указатель
// на первый элемент с кодом ch, расположенным на ленте памяти между
// адресами begin и end не включая end
char *find_(char *begin, const char *end, int ch);

//  возвращает указатель на первый
// символ, отличный от пробельных, расположенный на ленте памяти,
// начиная с begin и заканчивая ноль-символом
// если символ не найден, возвращается адрес первого ноль-символа
char *findNonSpace_(char *begin);

// возвращает указатель на первый пробельный символ,
// расположенный на ленте памяти начиная с адреса begin
// или на первый ноль-символ
char *findSpace_(char *begin);

// возвращает указатель на первый справа символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с rbegin и заканчивая rend.
// если символ не найден, возвращается адрес rend
char *findNonSpaceReverse_(char *rbegin, const char *rend);

//  возвращает указатель на первый пробельный символ справа,
//  расположенный на ленте памяти, начиная с rbegin и заканчивая rend. Если символ не найден,
//  возвращается адрес rend
char *findSpaceReverse_(char *rbegin, const char *rend);

// функция возвращает отрицательное значение, если lhs
// располагается до rhs, значение 0, если lhs и rhs
// равны, иначе – положительное значение.
int strcmp_(const char *lhs, const char *rhs);

// записывает по адресу beginDestination
// фрагмент памяти, начиная с адреса beginSource до endSource.
// возвращает указатель на следующий свободный фрагмент памяти в
// destination
char *copy_(const char *beginSource, const char *endSource,
            char *beginDestination);

// записывает по адресу
// beginDestination элементы из фрагмента памяти начиная с beginSource
// заканчивая endSource, удовлетворяющие функции-предикату f. Функция
// возвращает указатель на следующий свободный для записи фрагмент в памяти.
char *copyIf_(char *beginSource, const char *endSource,
              char *beginDestination, int (*f)(int));

// записывает по адресу
// beginDestination элементы из фрагмента памяти начиная с rbeginSource
// заканчивая rendSource, удовлетворяющие функции-предикату f.
// Функция возвращает значение beginDestination по окончанию работы функции.
char *copyIfReverse_(char *rbeginSource, const char *rendSource,
                     char *beginDestination, int (*f)(int));

// функция для тестирования
void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

#endif
