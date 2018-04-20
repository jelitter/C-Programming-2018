
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "useful.h"

const char* MARGIN = "     ";
const char SPACE = ' ';
const char X_SYMBOL = 'X';
const char O_SYMBOL = 'O';

void play_game()
{
	printf("Xs and Os!\n");

	struct game* p_game_info = (struct game*) malloc(sizeof(struct game));

	printf("This is the pointer %p", p_game_info);

	initialise_game(p_game_info, "John", "Annie");

	p_game_info->board[0][0] = X_SYMBOL; // top left X
	p_game_info->board[2][2] = O_SYMBOL; // bottom right o


	draw_banner();
	display_board(p_game_info->board);
	print_status(p_game_info);
	//display_board_positions();

}

void initialise_game(struct game* p_game_info, char* name1, char* name2) {
	// New game
	p_game_info->finished = False;

	// Player 1 will start
	p_game_info->status = P1_TURN;

	// Setting Player Names
	strncpy(p_game_info->playerNames[0], name1, MAX_NAME_LEN);
	strncpy(p_game_info->playerNames[1], name2, MAX_NAME_LEN);

	// Board initialization
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			p_game_info->board[i][j] = SPACE;
		}
	}
}

void clearScreen() {
	// Helper function to 'clear' the screen
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	return;
}

void draw_banner()
{
	clearScreen();
	printf("  /-----------------\\\n");
	printf("  |   GAME STATUS   |\n");
	printf("  \\-----------------/\n");
}

void display_board(char board[3][3]) {

	printf("\n%s|-----------|\n", MARGIN);
	for (int i = 0; i < 3; i++) {

		printf("%s| %c | %c | %c |\n", MARGIN, board[i][0], board[i][1], board[i][2]);
		printf("%s|-----------|\n", MARGIN);

	}
	printf("\n\n");
}

void print_status(struct game * p_game_info) {

	switch (p_game_info->status) {
	case (P1_TURN):
		printf("P1 turn");
	default:
		break;
	}

}

