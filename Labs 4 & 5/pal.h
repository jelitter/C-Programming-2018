#ifndef PAL_H_INCLUDED
#define PAL_H_INCLUDED

void displayState    (int* pListOfNumbers, int cursorPosition, int numberOfDigits, int numberOfGoes);
void moveCursorLeft  (int* pPosOfCursor);
void moveCursorRight (int* pPosOfCursor,   int max);
void incrementDigitInListAtPos (int* pListOfNumbers, int cursorPosition);
void decrementDigitInListAtPos (int* pListOfNumbers, int cursorPosition);
boolean isPalindrome(int* pListOfNumbers, int size);
void palindromeTest ();
char getCommand();
void processCommand(int* pList, int size, int* cursorPosition, char command);

#endif
