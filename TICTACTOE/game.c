
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "useful.h"
#include "game.h"

const char* MARGIN = "     ";
const char SPACE = ' ';
const char X_SYMBOL = 'X';
const char O_SYMBOL = 'O';

void play_game()
{
	struct game* p_game_info = (struct game*) malloc(sizeof(struct game));

	initialise_game(p_game_info, "John", "Annie");

	//p_game_info->board[0][0] = X_SYMBOL; // top left X
	//p_game_info->board[2][2] = O_SYMBOL; // bottom right o

	//int row = -1;
	//int col = -1;
	//get_row_col(7, &row, &col);
	//printf(" Pos: %d -> %d, %d\n", 7, row, col);


	// Game loop
	do {
		draw_banner(p_game_info);
		display_board(p_game_info->board);
		print_status(p_game_info);
		process_move(p_game_info);
	} while (!p_game_info->finished);

	draw_banner(p_game_info);
	display_board(p_game_info->board);
	print_status(p_game_info);

	printf("\n\n Game Over.");
	getch();
		
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

void draw_banner(struct game* p_game_info)
{
	clearScreen();
	printf("  /-----------------\\        %s: %c\n", p_game_info->playerNames[0], X_SYMBOL);
	printf("  |   GAME STATUS   |       %s: %c\n", p_game_info->playerNames[1], O_SYMBOL);
	printf("  \\-----------------/\n\n");
}

void display_board(char board[3][3]) {

	printf("%s             %s  Positions  \n", MARGIN, MARGIN);
	printf("%s|-----------|%s|-----------|\n", MARGIN, MARGIN);
	for (int i = 0; i < 3; i++) {

		printf("%s| %c | %c | %c |%s| %i | %i | %i | \n", MARGIN, board[i][0], board[i][1], board[i][2], MARGIN, i * 3, i * 3 + 1, i * 3 + 2);
		printf("%s|-----------|%s|-----------|\n", MARGIN, MARGIN);

	}
	printf("\n\n");
}

void print_status(struct game * p_game_info) {
	switch (p_game_info->status) {
	case (P1_TURN):
		printf(" Player 1 turn: %s", p_game_info->playerNames[0]);
		return;
	case (P2_TURN):
		printf(" Player 2 turn: %s", p_game_info->playerNames[1]);
		return;
	default:
		break;
	}
}

//void display_board_positions() {
//
//  // Integrated into display_board()
//
//	printf("\n\n         Board");
//	printf("\n       positions:");
//		
//	printf("\n%s|-----------|\n", MARGIN);
//	for (int i = 0; i < 3; i++) {
//
//		printf("%s| %i | %i | %i |\n", MARGIN, i*3, i*3 + 1, i*3 + 2);
//		printf("%s|-----------|\n", MARGIN);
//
//	}
//	printf("\n\n");
//}

void get_row_col(int position, int *row, int *col) {

	//     |-----------|       |-----------------|
	//     | 0 | 1 | 2 |  ==>  | 0,0 | 0,1 | 0,2 |
	//     |-----------|       |-----------------|
	//     | 3 | 4 | 5 |  ==>  | 1,0 | 1,1 | 1,2 |
	//     |-----------|       |-----------------|
	//     | 6 | 7 | 8 |  ==>  | 2,0 | 2,1 | 2,2 |
	//     |-----------|       |-----------------|

	if (position < 0 || position > 8) {
		*row = -1;
		*col = -1;
	}
	else {
		/* The following algorithm is for 0-8 positions, so we deduct 1 from the "pretty" position the players introduces */
		*row = position / 3;
		*col = position % 3;
	}
}

boolean boardIsFull(struct game* game_info) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (game_info->board[i][j] == SPACE) {
				return False;
			}
		}
	}
	return True;
}

void process_move(struct game* game_info) {
	
	int row = -1;
	int col = -1;
	int pos = -1;
	char cellContent = SPACE;

	do {
		pos = getDigitFromKeyboard();
		get_row_col(pos, &row, &col);
		cellContent = game_info->board[row][col];
		if (cellContent == X_SYMBOL) {
			printf("\n Position %d is already used by Player 1 (%s)", pos, game_info->playerNames[0]);
		}
		else if (cellContent == O_SYMBOL) {
			printf("\n Position %d is already used by Player 2 (%s)", pos, game_info->playerNames[1]);
		}
	} while (cellContent != SPACE);

	// Now we have an empty position to fill
	if (game_info->status == P1_TURN) {
		game_info->board[row][col] = X_SYMBOL;
		game_info->status = P2_TURN;
	} else if (game_info->status == P2_TURN) {
		game_info->board[row][col] = O_SYMBOL;
		game_info->status = P1_TURN;
	}

	game_info->finished = boardIsFull(game_info);

}
