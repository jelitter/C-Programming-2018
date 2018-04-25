
int getDigitFromKeyboard() {
	
	const zero = 48;
	const eight = 55;
	char inputChar = ' ';
	int n = -1;

	do {
		printf("\n Enter a position (0-8): ");
		inputChar = getche();
		n = inputChar - zero;
	} while (n < 0 || n > 8);
	return n;
}
