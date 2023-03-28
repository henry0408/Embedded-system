#include <stdio.h>

// typedef struct Student
// {
// 	int sid;
// 	char name[100];
// 	char sex;
// } * PST, ST;				//struct Student* == PST, struct Student == ST

// int main(void)
// {
// 	ST st;
// 	PST ps = &st;
// 	ps->sid = 100;
// 	printf("%d\n",st.sid);
//     printf("%d\n", (*ps).sid);

//     // if(st == *ps)
//     // {
//     //     printf("yes\n");
//     // }
// }

struct Student
{
    int sid;
	char name[100];
	char sex;
};

int main (void)
{
    struct Student s1 = {100, "hangyu", 'M'};
    struct Student *p = &s1;

    printf("%d\n", p->sid);
    printf("%d\n", (*p).sid);

    return 0;
}