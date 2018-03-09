
# Lab 5

Copy the file useful.c and useful.h to your project. 

Copy them to the correct directory and then in codeblocks select your project and then Add files… Add both files to  the debug and release build targets.

 The useful.h file  contains the  definition of  the method  and a typedef for Boolean.


char myGetChar()  

enum Bool { False, True };
typedef enum Bool boolean;
	
### 1.	Add an include for useful.h to main.c and pal.ch

#include "useful.h"

### 2.	Introduce a new local variable in the main method as part of the state of the game. numberOfGoes

int numberOfGoes = 0;

Modify  displayState to display this variable.


### 3.	Write and test the following methods isPalindrome.   This can be declared using either array notation or just pointer  notation as follows. Note that either way size of the array must be passed into the method.


boolean is_palindrome(int* plist_of_numbers, int size)
boolean is_palindrome(int list[] list_of_numbers, int size)


Test this method by calling it several times with the following numbers in the arrays and printing out the return value.

      123321
      123322
 123121
 123133


### 4.	Write a method getCommand  in pal.c . This method will call myGetChar.  It will only return  a character only if it is one of our valid command characters a, d, w or x.

It  should also display a prompt and  a list of valid characters to the user.


char get_command()
{
	 char  validCharacters = { 'a','d', 'w', 'x'};
	
	// display prompt
	// list the valid characters
// get the character from the user  until a valid char is //entered
// return a valid char 
}

Test calling this method from main and check it behaves correctly  for all the valid commands and  doesn’t return invalid commands.

### 5.	Write the method process_command .

void processCommand(int* pList, int size, int* pPositionOfCursor, char command)
{

}

Note that the positionOftheCursor  is passed by address as this may change in the     method.   The list address is passed in so items in the list may also change when this method is called. 

Call the methods we wrote in the previous lab to change an item in the list or the cursor position  here in response to the correct key command.

Test this  by calling it with each of the different command characters  and calling displayState before and after to check it is working correctly.


### 6.	Now  write a method  startGame  in main.c.  The  main method will simply call the method startGame.  startGame will now contain all the variables that represent the state of the game.

The start game will contain the game loop. The logic for the game loop will be the following:

check if it’s a palindrome
while its not a palindrome
		getCommand from the user
		process the  command
		display the state of the game.
		check if it’s a palindrome



void start_game()
{
    int listOfNumbers[] = {1,2,3,3,4,1};
    int numberOfDigits = 6;
    int positionOfCursor = 0;

	

}


### 7.	Modify the code to keep track of the number of valid goes and to print this number at the end .





