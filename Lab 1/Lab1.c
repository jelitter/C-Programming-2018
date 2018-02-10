#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number = 31;
    char letter = 'A';

    printf("\n number is\t %d : %x\n", number, number);
    printf("\n letter is\t %c : %x\n", letter, letter);
    printf("Press enter to continue");
    getchar();

    printf("\n letter is\t %c : %d: %x\n", letter, letter, letter);

    return 0;
}
