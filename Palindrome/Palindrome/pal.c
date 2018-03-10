#include <stdio.h>
#include <math.h>
#include "useful.h"

void resetScreen() {
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	return;
}

void displayState(int * pListOfNumbers, int cursorPosition, int numberOfDigits, int numberOfGoes) {
	const int padding = 18;
	resetScreen();
	printf("  Game State:   < ");

	for (int i = 0; i < numberOfDigits; i++) {
		printf("%d", pListOfNumbers[i]);
	}

	printf(" >		[ Digits: %d ] [ Cursor pos: %d ] [ Value: %d ] [ Goes: %d ]\n", numberOfDigits, cursorPosition, pListOfNumbers[cursorPosition], numberOfGoes);

	for (int i = 0; i < padding + cursorPosition; i++) {
		printf(" ");
	}
	printf("^");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	return;
}

void moveCursorRight(int* pPosOfCursor, int max, int* numberOfGoes) {
	if (*pPosOfCursor < max - 1) {
		*pPosOfCursor += 1;
		*numberOfGoes += 1;
	}
}

void moveCursorLeft(int* pPosOfCursor, int* numberOfGoes) {
	if (*pPosOfCursor > 0) {
		*pPosOfCursor -= 1;
		*numberOfGoes += 1;
	}
}

void incrementDigitInListAtPos(int* pListOfNumbers, int cursorPosition, int* numberOfGoes) {
	pListOfNumbers[cursorPosition] = (pListOfNumbers[cursorPosition] + 1) % 10;
	*numberOfGoes += 1;
}

void decrementDigitInListAtPos(int* pListOfNumbers, int cursorPosition, int* numberOfGoes) {
	pListOfNumbers[cursorPosition] -= 1;
	if (pListOfNumbers[cursorPosition] < 0) {
		pListOfNumbers[cursorPosition] = 9;
	}
	*numberOfGoes += 1;
}

boolean isPalindrome(int* pListOfNumbers, int size) {
	for (int i = 0; i < (int) size / 2; i++) {
		if (pListOfNumbers[i] != pListOfNumbers[size - i - 1]) {
			return False;
		}
	}
	return True;
}

char *arrToString(int *arr, char *ret, int size) {
	for (int i = 0; i < size; i++) {
		ret[3 * i] = '0' + arr[i];

		if (i < size - 1) {
			ret[3 * i + 1] = ',';
			ret[3 * i + 2] = ' ';
		}
	}
	return ret;
}

void palindromeTest() {
	char ret[15];
	int testList1[6] = { 1, 2, 3, 3, 2, 1 };
	int testList2[6] = { 1, 2, 3, 3, 2, 2 };
	int testList3[6] = { 1, 2, 3, 1, 2, 1 };
	int testList4[6] = { 1, 2, 3, 1, 3, 3 };

	printf("\n");
	printf("\nPalindrome test 1 [ %s ]: %s", arrToString(testList1, ret, 6), stringFromBoolean(isPalindrome(testList1, 6)));
	printf("\nPalindrome test 2 [ %s ]: %s", arrToString(testList2, ret, 6), stringFromBoolean(isPalindrome(testList2, 6)));
	printf("\nPalindrome test 3 [ %s ]: %s", arrToString(testList3, ret, 6), stringFromBoolean(isPalindrome(testList3, 6)));
	printf("\nPalindrome test 4 [ %s ]: %s", arrToString(testList4, ret, 6), stringFromBoolean(isPalindrome(testList4, 6)));
	printf("\n");
	return;
}


char getCommand() {
	printf("\n  n: new game");
	printf("\n  k: quit game");
	printf("\n");
	printf("\n    w");
	printf("\n  a   d");
	printf("\n    x");
	printf("\n\nPress key: ");

	return myGetChar();
}


void processCommand(int* pList, int size, int* cursorPosition, char command, int* numberOfGoes, boolean* gameInProgress) {

	switch (command) {
	case 'a':
		moveCursorLeft(cursorPosition, numberOfGoes);
		break;

	case 'd':
		moveCursorRight(cursorPosition, size, numberOfGoes);
		break;

	case 'w':
		incrementDigitInListAtPos(pList, *cursorPosition, numberOfGoes);
		break;

	case 'x':
		decrementDigitInListAtPos(pList, *cursorPosition, numberOfGoes);
		break;

	case 'n':
		newGame();
		break;
	case 'k':
		*gameInProgress = False;
		break;
	default:
		break;
	}
}
int * initialiseArray(int number) {

	int digits = log10(number) + 1;
	
	int * arr = (int *) malloc((digits) * sizeof(int));
	int i = 0;
	do {
		arr[digits - i - 1] = number % 10;
		number /= 10;
		i++;
	} while (number != 0);
	return arr;
}

int randomPosition(int max) {
	srand(time(NULL));
	return rand() % max;
}


