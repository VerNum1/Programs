#include "libs/string/string_.h"

#include "libs/string/tasks/removeNonLetters.h"
#include "libs/string/tasks/removeExtraSpaces.h"
#include "libs/string/tasks/removeNumbersAndLetters.h"
#include "libs/string/tasks/replacementNumbersToSpace.h"
#include "libs/string/tasks/replace.h"
#include "libs/string/tasks/areLexicographicallyOrdered.h"

void test_strlen() {
    char s[6] = "Hello";

    assert(strlen_(s) == 5);
}

void test_strlen_zeroElements() {
    char s[] = "";

    assert(strlen_(s) == 0);
}

void test_find_notRepeatingElements() {
    char s[11] = "ctpvprogra";
    char ch = 118;
    char *symbol = find_(&s[0], &s[10], ch);
    assert(*symbol == s[3]);
}

void test_find_withRepeatingElementsNotNormal() {
    char s[12] = "ctpvpovitis";
    char ch = 118; // v
    char *symbol = find_(&s[0], &s[5], ch);
    assert(*symbol == s[6]);
}

void test_findNonSpace_firstElementNonSpace() {
    char s[7] = "abc de";
    char *symbol = findNonSpace_(&s[0]);
    assert(symbol == &s[0]);
}

void test_findNonSpace_afterFirstElementNonSpace() {
    char s[9] = "   hello";
    char *symbol = findNonSpace_(&s[0]);
    assert(symbol == &s[3]);
}

void test_findNonSpace_allElementsIsSpace() {
    char s[7] = "      ";
    char *symbol = findNonSpace_(&s[0]);
    assert(symbol == &s[6]);
}

void test_findSpace_firstSpace() {
    char s[12] = " let me die";
    char *symbol = findSpace_(&s[0]);
    assert(symbol == &s[0]);
}

void test_findSpace_SecondElementSpace() {
    char s[5] = "a bcd";
    char *symbol = findSpace_(&s[0]);
    assert(symbol == &s[1]);
}

void test_findSpace_allElementsIsntSpace() {
    char s[8] = "abcdefg";
    char *symbol = findSpace_(&s[0]);
    assert(symbol == &s[7]);
}

void test_test_findNonSpaceReverse_firstSymbolRightNotSpace() {
    char s[7] = "abc de";
    char *symbol = findNonSpaceReverse_(&s[5], &s[-1]);
    assert(symbol == &s[5]);
}

void test_test_findNonSpaceReverse_afterFirstElementRightNotSpace() {
    char s[13] = "abs pasca   ";
    char *symbol = findNonSpaceReverse_(&s[11], &s[-1]);
    assert(symbol == &s[8]);
}

void test_test_findNonSpaceReverse_allElementsIsSpace() {
    char s[8] = "       ";
    char *symbol = findNonSpaceReverse_(&s[6], &s[-1]);
    assert(symbol == &s[-1]);
}

void test_findSpaceReverse_firstSpace() {
    char s[14] = "aa aa aaaaaaa ";
    char *symbol = findSpaceReverse_(&s[14], &s[-1]);
    assert(symbol == &s[13]);
}

void test_findSpaceReverse_afterFirstElementSpace() {
    char s[10] = "1 2 3 4 5 ";
    char *symbol = findSpaceReverse_(&s[25], &s[-1]);
    assert(symbol == &s[9]);
}

void test_findSpaceReverse_allElementsNonSpace() {
    char s[8] = "abcdefg";
    char *symbol = findSpaceReverse_(&s[6], &s[-1]);
    assert(symbol == &s[-1]);
}


void test_strcmp_lhsMoreThenRhs() {
    char s1[5] = "abcd";
    char s2[3] = "ab";
    assert(strcmp_(s1, s2) > 0);
}

void test_strcmp_rhsMoreThenlhs() {
    char s1[3] = "ab";
    char s2[5] = "abcd";
    assert(strcmp_(s1, s2) < 0);
}

void test_strcmp_lhsEqualRhs() {
    char s1[5] = "abcd";
    char s2[5] = "abcd";
    assert(strcmp_(s1, s2) == 0);
}

void test_copy_allSymbol() {
    char s1[6] = "hello";
    char s2[10];
    char *a = copy_(&s1[0], &s1[5], s2);
    assert(s2[0] == 'h');
    assert(s2[1] == 'e');
    assert(s2[2] == 'l');
    assert(s2[3] == 'l');
    assert(s2[4] == 'o');
    assert(&s2[5] == a);
}

void test_copyIf_allElementsMatchCondition() {
    char s1[4] = "246";
    char s2[4];
    char *a = copyIf_(&s1[0], &s1[2], s2, isEvenSymbol);
    assert(s2[0] == '2');
    assert(s2[1] == '4');
    assert(&s2[2] == a);
}

void test_copyIf_allElementsNotSatisfyCondition() {
    char s1[4] = "134";
    char s2[4];
    char s3[4];
    char *a = copy_(&s2[0], &s2[2], s3);
    char *b = copyIf_(&s1[0], &s1[2], s2, isEvenSymbol);
    assert(s2[0] == s3[0]);
    assert(s2[1] == s3[1]);
    assert(&s2[0] == b);
}

void test_copyIf_randomElements() {
    char s1[7] = "123456";
    char s2[4];
    char *a = copyIf_(&s1[0], &s1[5], s2, isEvenSymbol);
    assert(s2[0] == '2');
    assert(s2[1] == '4');
    assert(&s2[2] == a);
}

void test_copyIfReverse_allElementsMatchCondition() {
    char s1[4] = "246";
    char s2[4];
    char *a = copyIfReverse_(&s1[2], &s1[0], s2, isEvenSymbol);
    assert(s2[0] == '6');
    assert(s2[1] == '4');
    assert(&s2[2] == a);
}

void test_copyIfReverse_allElementsNotSatisfyCondition() {
    char s1[4] = "135";
    char s2[4];
    char s3[4];
    char *a = copy_(&s2[0], &s2[2], s3);
    char *b = copyIfReverse_(&s1[2], &s1[0], s2, isEvenSymbol);
    assert(s2[0] == s3[0]);
    assert(s2[1] == s3[1]);
    assert(&s2[0] == b);
}

void test_copyIfReverse_mixedElements() {
    char s1[7] = "123456";
    char s2[4];
    char *a = copyIfReverse_(&s1[5], &s1[0], s2, isEvenSymbol);

    assert(s2[0] == '6');
    assert(s2[1] == '4');
    assert(s2[2] == '2');
    assert(&s2[3] == a);
}


void test_libs_string() {
    //
    test_strlen();
    test_strlen_zeroElements();
    //
    test_find_notRepeatingElements();
    test_find_withRepeatingElementsNotNormal();
    //
    test_findNonSpace_firstElementNonSpace();
    test_findNonSpace_afterFirstElementNonSpace();
    test_findNonSpace_allElementsIsSpace();
    //
    test_findSpace_firstSpace();
    test_findSpace_SecondElementSpace();
    test_findSpace_allElementsIsntSpace();
    //
    test_test_findNonSpaceReverse_firstSymbolRightNotSpace();
    test_test_findNonSpaceReverse_afterFirstElementRightNotSpace();
    test_test_findNonSpaceReverse_allElementsIsSpace();
    //
    test_findSpaceReverse_firstSpace();
    test_findSpaceReverse_afterFirstElementSpace();
    test_findSpaceReverse_allElementsNonSpace();
    //
    test_strcmp_lhsMoreThenRhs();
    test_strcmp_rhsMoreThenlhs();
    test_strcmp_lhsEqualRhs();
    //
    test_copy_allSymbol();
    //
    test_copyIf_allElementsMatchCondition();
    test_copyIf_allElementsNotSatisfyCondition();
    test_copyIf_randomElements();
    //
    test_copyIfReverse_allElementsMatchCondition();
    test_copyIfReverse_allElementsNotSatisfyCondition();
    test_copyIfReverse_mixedElements();
    //
}

void test_tasks(){
    test_removeNonLetters(); // 1
    test_removeExtraSpaces(); // 2
    test_removeNumbersAndLetters_(); // 3
    test_replacementNumbersToSpaces(); // 4
    //test_replace(); //5
    test_areLexicographicallyOrdered(); //6 просто assert
}

int main() {
    test_libs_string();
    test_tasks();

    return 0;
}
