//--------------------------------------------------
// DATA TYPES DEFINITIONS
//--------------------------------------------------
enum Bool { False, True };
typedef enum Bool boolean;

char *stringFromBoolean(boolean b) {
    static const char *strings[] = { "False", "True" };
    return strings[b];
}

//--------------------------------------------------
// my_getchar
//--------------------------------------------------
char my_get_char() {
	//1. We create the output variable with the value the user has input by keyboard
	char res = getchar();

	//2. We discard any extra character the user has input by keyboard
	boolean finish = False;
	char dummy_char = res;

	while (finish == False) {
		if (dummy_char == '\n')
			finish = True;
		else
			dummy_char = getchar();
	}

	//3. We return the output variable
	return res;
}


char myGetChar() {
    char res = ' ';

    while (res != 'w' && res != 'x' && res != 'a' && res != 'd' && res != 'n' && res != 'k') {
        res = getch();
    }
    return res;
}

