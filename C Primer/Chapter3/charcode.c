#include <stdio.h>

int main(void)
{
    char ch;

    printf("Please enter a new character. ");
    scanf("%c", &ch);
    printf("The code for %c is %d. \n", ch, ch);

    return 0;

}