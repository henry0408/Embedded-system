/*1.有个学生类Student
    包括：私有成员：姓名 成绩
        void setData(string name, int score)给成员变量赋值,没有初始化列表
        void show();
2.在main定义 student数组5个元素并赋值 Students[5]  使用匿名对象初始化
3.设计一个全局友元函数 比较两个学生的成绩的高低 int compare(Student& a, Student& b);
                    a的成绩>b的成绩 return 1; a<b return -1; 相等 0
4. 求出最高分和最低分的学生
*/


#include <iostream>

using namespace std;

class Student
{
    friend void set_info(Student &p,string name, int score);
    friend int compare(Student& a, Student& b);
private:
    string name;
    int score;
public:
    Student()
    {

    }
    void setData(string name,int score)
    {
        this->name = name;
        this->score = score;
    }

    void show()
    {
        cout<<name<<" "<<score<<endl;
    }
};

void set_info(Student &p,string name, int score)
{
    p.setData(name,score);
}

int compare(Student& a, Student& b)
{
    if(a.score>b.score)
    {
        return 1;
    }
    else if(a.score<b.score)
    {
        return -1;
    }
    else
        return 0;
}

int main()
{
    Student s[5] = {Student(),Student(),Student(),Student(),Student()};
    set_info(s[0],"aa",100);
    set_info(s[1],"bb",200);
    set_info(s[2],"cc",500);
    set_info(s[3],"dd",250);
    set_info(s[4],"ee",300);

    s[0].show();
    s[1].show();
    s[2].show();
    s[3].show();
    s[4].show();

    cout<< compare(s[0],s[1])<<endl;
    return 0;
}

