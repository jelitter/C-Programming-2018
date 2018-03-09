#ifndef PAL_H_INCLUDED
#define PAL_H_INCLUDED

void displayState    (int* pListOfNumbers, int cursorPosition, int numberOfDigits, int numberOfGoes);
void moveCursorLeft  (int* pPosOfCursor,             int* numberOfGoes);
void moveCursorRight (int* pPosOfCursor,   int max, int* numberOfGoes);
void incrementDigitInListAtPos (int* pListOfNumbers, int cursorPosition, int* numberOfGoes);
void decrementDigitInListAtPos (int* pListOfNumbers, int cursorPosition, int* numberOfGoes);
boolean isPalindrome(int* pListOfNumbers, int size);
void palindromeTest ();
char getCommand();
void processCommand(int* pList, int size, int* cursorPosition, char command, int* numberOfGoes);

#endif
