#include <stdio.h>
#include "useful.h"



void displayState (int* pListOfNumbers,  int  cursorPosition, int numberOfDigits, int numberOfGoes) {

    const int padding = 16;

    printf ("\n\nGame State:   < ");

    for (int i = 0; i < numberOfDigits; i++) {
        printf ("%d", pListOfNumbers[i]);
    }

    printf (" >		Cursor at %d  -  Number of goes: %d\n", cursorPosition, numberOfGoes);

    for (int i = 0; i < padding + cursorPosition; i++) {
        printf (" ");
    }

    printf ("^");

}

void moveCursorRight ( int* pPosOfCursor, int max) {
    if (*pPosOfCursor < max -1) {
        *pPosOfCursor += 1;
    }
}

void moveCursorLeft ( int* pPosOfCursor) {
    if (*pPosOfCursor > 0) {
        *pPosOfCursor -= 1;
    }
}

void incrementDigitInListAtPos (int* pListOfNumbers, int cursorPosition) {

    if (pListOfNumbers[cursorPosition] < 9) {
        pListOfNumbers[cursorPosition] += 1;
    }
}

void decrementDigitInListAtPos (int* pListOfNumbers, int cursorPosition) {

    if (pListOfNumbers[cursorPosition] > 0) {
        pListOfNumbers[cursorPosition] -= 1;
    }
}

boolean isPalindrome (int* pListOfNumbers, int size) {
    for (int i = 0; i < (int) size / 2; i++) {
        if (pListOfNumbers[i] != pListOfNumbers[size - i - 1]) {
            return False;
        }
    }

    return True;
}

char *arrToString (int *arr, char *ret, int size) {
    for (int i = 0; i < size; i++) {
        ret[3 * i] = '0' + arr[i];

        if (i < size - 1) {
            ret[3 * i + 1] = ',';
            ret[3 * i + 2] = ' ';
        }
    }

    return ret;
}

void palindromeTest () {
    char ret[15];
    int testList1[6] = {1, 2, 3, 3, 2, 1};
    int testList2[6] = {1, 2, 3, 3, 2, 2};
    int testList3[6] = {1, 2, 3, 1, 2, 1};
    int testList4[6] = {1, 2, 3, 1, 3, 3};

    printf ("\n");
    printf ("\nPalindrome test 1 [ %s ]: %s", arrToString (testList1, ret, 6), stringFromBoolean ( isPalindrome (testList1, 6) ) );
    printf ("\nPalindrome test 2 [ %s ]: %s", arrToString (testList2, ret, 6), stringFromBoolean ( isPalindrome (testList2, 6) ) );
    printf ("\nPalindrome test 3 [ %s ]: %s", arrToString (testList3, ret, 6), stringFromBoolean ( isPalindrome (testList3, 6) ) );
    printf ("\nPalindrome test 4 [ %s ]: %s", arrToString (testList4, ret, 6), stringFromBoolean ( isPalindrome (testList4, 6) ) );
    printf ("\n");
    return;
}


char getCommand() {
    char  validCharacters = { 'a', 'd', 'w', 'x'};

    printf ("\nPress key (a,d to move, w,x to modify): ");
    return my_get_char();
}

void processCommand (int* pList, int size, int* cursorPosition, char command) {

    switch (command) {
        case 'a'  :
            moveCursorLeft (cursorPosition);
            break;

        case 'd'  :
            moveCursorRight (cursorPosition, size);
            break;

        case 'w'  :
            incrementDigitInListAtPos(pList, *cursorPosition);
            break;

        case 'x'  :
            decrementDigitInListAtPos(pList, *cursorPosition);
            break;

        default :
            break;
    }

}
