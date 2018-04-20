#define MAX_NAME_LEN 50
enum Bool { False, True };
enum status { P1_TURN, P2_TURN, P1_WON, P2_WON, DRAW };
typedef enum Bool boolean;

extern const char SPACE;
extern const char X_SYMBOL;
extern const char O_SYMBOL;


struct game {
	char board[3][3];
	char playerNames[2][MAX_NAME_LEN];
	int status;
	boolean finished;
};

void play_game();

void initialise_game(struct game* p_game_info, char* name1, char* name2);

void draw_banner();
void display_board(char board[3][3]);
void print_status(struct game* p_game_info);
