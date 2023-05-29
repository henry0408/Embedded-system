/*
1. 定义结构体Student 结构体成员：string name 
								 string num
   编写函数实现：N个学生信息 宏定义N  3
2. inputStudentInfo(Student* s)函数，需要将每个学生信息(姓名 学号)输入计算机保存 cin

3.find_stu(string serchName)函数,键盘输入某个学生的姓名 如果该学生存在 则输出其基本信息，
  如果不存在,则输出"not found"

main：结构体数组 3个成员
input(结构体数组的指针);
输入一个待查找的学生姓名 ：小明
find（小明）
*/

#include <iostream>
#define N 3
using namespace std;

struct Student
{
    string name;
    string num;
};

Student s[N];

void inputStudentInfo(struct Student *s)
{
    for(int i = 0; i<N; i++)
    {
        cout<<"Please enter the info of the student:"<<endl;
        cout<<"Please enter the name: "<<endl;
        getline(cin,s[i].name);
        cout<<"Please enter the num: "<<endl;
        getline(cin, s[i].num);
    } 
    
    
}

void find_stu(string serchName)
{
    cout<<serchName<<endl;
    
    cout<<"search: "<<endl;
    string stu_name;
    getline(cin,stu_name);
    for(int i = 0; i<N; i++)
    {
        if(s[i].name == serchName)
        {
            cout<<s[i].name<<" "<<s[i].num<<endl;
            return;
        }
    }
    cout<<"Not found"<<endl;
}



int main(int argc, char const *argv[])
{
    /* code */
    inputStudentInfo(s);
    cout<<s[1].name<<endl;

    // 
    string search_name;
    cin>>search_name;
    find_stu(search_name);
    return 0;
}
