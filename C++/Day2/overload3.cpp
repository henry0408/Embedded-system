/*
定义函数，判断一个年份是否是闰年，声明中给默认年份2016
*/

#include <iostream>

using namespace std;

void My_year(int year = 2016)
{
    if((year%4 == 0 && year % 100 !=0)||year%400 == 0)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
}

int main(int argc, char const *argv[])
{
    My_year(2012);
    My_year();
    My_year(2008);

    
    return 0;
}
