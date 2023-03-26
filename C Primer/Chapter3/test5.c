/*scanf + Ç³¿½±´*/
#include <stdio.h>

int main (void)
{
    int ch;
    int * point;
    for (int i = 0; i<3; i++)
    {
        scanf("%d", &ch);
        point[i] = ch;
    }

    for (int j = 0; j<3; j++)
    {
        printf("%d\n", point[j]);
    }

    //point[0] = 99;
    *(point) = 99;
    printf("%d\n", *point);
    
    // char str1[10], str2[10], str3[10];
    // printf("Please enter your word: ");
    // scanf("%s%s%s", str1, str2, str3);
    // printf("The final result is: %s %s %s\n", str1, str2, str3);


    return 0;
}