#include <stdio.h>
#include <stdlib.h>
#include "useful.h"
#include "pal.h"

int main() {

//    int listOfNumbers[] = {1, 2, 3, 6, 8, 9};
//    int numberOfDigits = 6;
//    int cursorPosition = 0;
    int numberOfGoes = 0;


//    printf ("\nLocation of listOfNumbers: %p", listOfNumbers);
//    printf ("\nPosition of cursor: %d", cursorPosition);
//
//    displayState  (listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);
//
//    moveCursorRight (&cursorPosition, numberOfDigits);
//    displayState  (listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);
//
//    incrementDigitInListAtPos(&listOfNumbers, cursorPosition);
//    displayState  (listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);
//
//    moveCursorRight (&cursorPosition, numberOfDigits);
//    decrementDigitInListAtPos(&listOfNumbers, cursorPosition);
//    displayState  (listOfNumbers, cursorPosition, numberOfDigits, numberOfGoes);


//    palindromeTest ();

    startGame(&numberOfGoes);


    return 0;
}


void startGame(int *numberOfGoes) {
    char command;
    int listOfNumbers[] = {1,2,3,3,4,1};
    int numberOfDigits = 6;
    int positionOfCursor = 0;


    displayState  (listOfNumbers, positionOfCursor, numberOfDigits, *numberOfGoes);
    while (isPalindrome (listOfNumbers, 6) == False) {
        command = getCommand();
        *numberOfGoes += 1;
        processCommand (&listOfNumbers, numberOfDigits, &positionOfCursor, command);
        displayState  (listOfNumbers, positionOfCursor, numberOfDigits, *numberOfGoes);
    }

    printf("\n\nCongratulations! You found a palindrome after %d movements.\n\n", *numberOfGoes);
    return;
}
