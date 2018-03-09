## Intro to Lab 4

The goal of today's lab is to start writing   some of  methods we will need for assignment 1. 
The complete specification for assignment 1 will be distributed / explained in class. 

The assignment is based on the idea of a simple game where the user is presented with a  6 digit number  ie "`138624`" which they must transform into a palindrome number.

In this case two possible  solutions might be   `138831` or  `426624`.

Each action of the user can only a change a selected digit up or down by  1 .

The selected digit is denoted by a cursor that the user can move left or right. The cursor has 6 possible positions 0 to 5.

The initial state of the game will eventually be  shown as follows: 

	138624
	^

The cursor ^ denotes the selected digit.

If the user moves the cursor right the state of the game is updated and the state is shown as

	138624
	  ^
If the user now decrements the selected digit the state of the game is then shown as

	128624
	 ^

# Lab 4 

In today's lab we will start by creating variables to hold the state of the game and writing some methods that will be called used later in response to user interacting with the game using the keyboard.



### 1.	Create a project with  two .c files and  one header file ( .h file)
When you add the second .c file  pal.c you must be sure to tick the relevant boxes so as to  add this to the Debug and Release build.  

	main.c
	pal.c
	pal.h


In codeblocks  the following code is automatically added to the .h file. Note you will later add code as shown:

	#ifndef PAL_H_INCLUDED
	#define PAL_H_INCLUDED

	// you will add code here later

	#endif


In this lab we will add the definition  or body of  or methods to pal.c

For each method a one line  declaration will be added to pal.h .  The declaration will tell the compiler the number and types of parameters a method requires. 

By  including  pal.h in main.c  we can then call these methods in main.c today to test our methods.


### 2.	Variables required to store the state of the game.

  
In the first version of the game we will always have an array of 6 digits.  This will be stored in an array of 6 numbers.  These numbers and the array size will be hardcoded into our initial version.  A single integer is used to remember the position of the cursor.  

Thus the initial state of the game is stored in the following variables  as follows. 
You should add this code to the start of the  main method.

	int listOfNumbers[] = {1,2,3,6,8,9};
	int number_of_digits = 6;
	int positionOfCursor = 0;

Add a print  statement to print the location/address of the array `listOfNumbers` . Remember  the location of the array is  `&listOfNumbers[0]`  or simply `listOfNumbers` .  Use `%p` to print this address.

Add another print  statement to print positionOfCursor.


### 3.	Write a method to displayState to show the state of the 'game'

The `displayState` method  will show the list of numbers in the array and the value of the cursor. 

This method will need to take three parameters 
- the location/address of the array `listOfNumbers`
- the value of `positionOfCursor` 
- the maximum number of elements in the array `number_of_digits`

Create the body of the  method as follows in `pal.c` 

	displayState(int* pListOfNumbers,  int  positionOfCursor, int number_of_digits)
	{
		printf("\n\nGame State:\n");
		// Add code to display all the numbers in the array later
		// Use  *pListOfNumbers or pListOfNumbers[0] to access the first item
	     // in the array

	}

In order to call the method successfully from the main method in `main.c`  we need to add a declaration of the method to `pal.h` 

Add the declaration of the method  to `pal.h`  Note the ; at the end of the line

	displayState(int* pListOfNumbers,  int  positionOfCursor, int number_of_digits);

Add a call to `displayState`  in the main method passing in the correct parameters.
This won't compile until we include the `pal.h` file  in `main.c` 

You will need to add the following line to the top of `main.c`.

	#include "pal.h"


Build and run the program. You should see the output 

Game State:

### 4.	Complete the method  displayState 
Add code to this `displayState` to show the numbers in the array and the value of the cursor on one line:


	Game State:   < 123689 >		Cursor at 0	


You can improve this method later to show the cursor visually.  This can be done at the end of the lab or at home.

	Game State:   < 123678 >	
		       ^	


### 5.	Write a method moveCursorRight

Create the method moveCursorRight in pal.c.

This method should increment the value of `positionOfCursor` by 1 up to a  maximum value of `number_of_digits`   The  value of the `positionOfCursor` will need to be changed in this method.  
This method will take the address `positionOfCursor` as a parameter

How should you call the method ? 
How should you declare the method ? 


Add the body/definition of  this method in  pal.c

	void moveCursorRight( int* pPosOfCursor, int max)
	{
		// Add the code here to increment the value of the cursor
		// within the allowed limits
	}

In order to be able to call this method from main add a declaration of it in pal.h

	void moveCursorRight ( int* pPosOfCursor, int max);


Implement the body of this method and call this method. 

You will need to call the method `displayState` before and after this method to see if the method has worked. 
Test the position of the cursor never goes outside the allowed range by calling it in a loop and then calling `displayState`.


### 6.	Write a similar method moveCursorLeft in pal.c

To test the method call moveCursorRight  2 time and them call moveCursorLeft 3 times.  Print the game state. Check that the cursor value never goes below  0.

### 7.	Create a method incrementDigitInListAtPos

 Create a method incrementDigitInListAtPos  in the pal.c that takes the following parameters
•	the location/address of the list of numbers  
•	the position of the cursor as parameters 


Add the following declaration to pal.h and implement the body of the method in pal.c

	void incrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor);

Add an initial version of this method that prints out the name of the method. 
Call the method from main  to test that it works.
Once you have successfully called the method then implement the method. 


Hints:
Array Notation:  
	`pListOfNumbers[0]` refers to the first item in the list
	`pListOfNumbers[3]` refers to the first item in the list

Pointer Notation: 
	`*( pListOfNumbers + 0)`  refers to the first item in the list
	`*( pListOfNumbers + 3)`  refers to the third item in the list


Again test this method by a suitable sequence of calls in main.









# Lab 5

Copy the file `useful.c` and `useful.h` to your project. 

Copy them to the correct directory and then in codeblocks select your project and then Add files… Add both files to  the debug and release build targets.

 The `useful.h` file  contains the  definition of  the method  and a typedef for `Boolean`.


	char myGetChar()  

	enum Bool { False, True };
	typedef enum Bool boolean;
	
### 1.	Add an include for useful.h to main.c and pal.ch

	#include "useful.h"

### 2.	Introduce a new local variable in the main method as part of the state of the game. numberOfGoes

	int numberOfGoes = 0;

Modify `displayState` to display this variable.


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

Note that the `positionOftheCursor` is passed by address as this may change in the method. The list address is passed in so items in the list may also change when this method is called. 

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





