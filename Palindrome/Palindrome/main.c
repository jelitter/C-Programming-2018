#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "useful.h"
#include "pal.h"

//void flushStdIn() {
//	char c;
//	do {
//		c = get(stdin);
//	} while (c != EOF && c != '\n');
//}

int getRandomLength() {
	// Returning random digit length between 5 and 10.
	srand(time(NULL));
	int min = 5;
	int max = 10;
	int ret = rand() % (max + 1 - min) + min;
	printf("Returning length: %d", ret);
	return ret;
}

long int getRandomNumberOfLength(int length) {
	// Returning a random number with 'length' digits.
	srand(time(NULL));
	long unsigned int num = rand();
	srand(time(NULL));
	long int num2 = rand() * 1000;
	srand(time(NULL));
	long int num3 = rand() * 100000;

	num += num2 + num3;
	num = num % (int)(pow(10, length));
	printf("Returning num: %d", num);
	return num;
}

void startGame(int initialNumber) {
	boolean gameInProgress = True;
    char command;
    int numberOfGoes = 0;
    int numberOfDigits = log10(initialNumber) + 1;
    int positionOfCursor = 0;
    int * listOfNumbers = initialiseArray(initialNumber);

	positionOfCursor = randomPosition(numberOfDigits);

    displayState (listOfNumbers, positionOfCursor, numberOfDigits, numberOfGoes);
    while (!isPalindrome (listOfNumbers, numberOfDigits) && gameInProgress) {
        command = getCommand();
        processCommand (listOfNumbers, numberOfDigits, &positionOfCursor, command, &numberOfGoes, &gameInProgress);
        displayState  (listOfNumbers, positionOfCursor, numberOfDigits, numberOfGoes);
    }
	if (gameInProgress) {
		printf("\n\n Congratulations! You found a palindrome after %d movements.\n", numberOfGoes);
	}
	else {
		printf("\n\n Quitting game! You didn't find a palindrome after %d movements.\n", numberOfGoes);
	}
    return;
}

void newGame() {
	unsigned int digitLength = getRandomLength();
	long unsigned int initialNumber = getRandomNumberOfLength(digitLength);

	printf("\n Starting game with number: %d, length: %d", initialNumber, digitLength);

	startGame(initialNumber);
	return;
}

int main() {
	char opt = ' ';
	do {
		newGame();
		fflush(stdin);
		printf("\n Type 'y' to play again, other to exit: ");
		opt = getch();
	} while (opt == 'y');

	return 0;
}