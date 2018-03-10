#include <stdio.h>
#include <stdlib.h>
#include "useful.h"
#include "pal.h"

int main() {

    int initialNumber = 123671;

//    runTests();
    startGame(initialNumber);

    return 0;
}


void startGame(int initialNumber) {
    char command;
    int numberOfGoes = 0;
//    int listOfNumbers[] = {1,2,3,3,4,1};
    int * listOfNumbers = initialiseArray(initialNumber);
    int numberOfDigits = 6;
    int positionOfCursor = 0;

    displayState  (listOfNumbers, positionOfCursor, numberOfDigits, numberOfGoes);
    while (isPalindrome (listOfNumbers, 6) == False) {
        command = getCommand();
//        *numberOfGoes += 1;
        processCommand (&listOfNumbers, numberOfDigits, &positionOfCursor, command, &numberOfGoes);
        displayState  (listOfNumbers, positionOfCursor, numberOfDigits, numberOfGoes);
    }

    printf("\n\nCongratulations! You found a palindrome after %d movements.\n\n", numberOfGoes);
    return;
}

void runTests() {
    int listOfNumbers[] = {1, 2, 3, 6, 8, 9};
    int numberOfDigits = 6;
    int cursorPosition = 0;
    int numberOfGoes = 0;

    printf ("\nLocation of listOfNumbers: %p", listOfNumbers);
    printf ("\nPosition of cursor: %d", cursorPosition);

    displayState  (listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);

    moveCursorRight (&cursorPosition, numberOfDigits, &numberOfGoes);
    displayState  (listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);

    incrementDigitInListAtPos (&listOfNumbers, cursorPosition, &numberOfGoes);
    displayState  (listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);

    moveCursorRight (&cursorPosition, numberOfDigits, &numberOfGoes);
    decrementDigitInListAtPos (&listOfNumbers, cursorPosition, &numberOfGoes);
    displayState  (listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);

    palindromeTest ();
}

