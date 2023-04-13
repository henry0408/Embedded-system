#include <stdio.h>

//只定义了一个数据类型，没有定义变量；且该数据类型的名字叫做Weekday
enum Weekday
{
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

// //默认从0开始，但可以修改为从4开始
// enum Weekday
// {
//     Monday = 4, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
// };

int main (void)
{
    //enum Weekday day = Wednesday;
    enum Weekday day;

    printf("%d\n", day);
    printf("%d\n", Wednesday);

    return 0;
}
