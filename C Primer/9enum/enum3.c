/*enum±éÀú*/
#include <stdio.h>

enum Day
{
    Monday,Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday 
};


int main()
{
    
    enum Day weekday;
    
    for(weekday = Monday; weekday <=Sunday; weekday++)
    {
        printf("%d ", weekday);
    }
    printf("\n");

}