#include <stdio.h>

enum Weekday
{
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

int main (void)
{
    enum Weekday day = Wednesday;
    switch (day)
    {
    case 0:
        printf("Monday");
        break;

    case 1:
        printf("Tuesday");
        break;

    case 2:
        printf("Wednesday");
        break;
    
    default:
        break;
    }

    return 0;
}
