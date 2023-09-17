#include <iostream>

using namespace std;

struct Student
{
    double score[100];
    int number;
};

struct Student stu;

void display(struct Student*p, int i)
{
    int n;
    for(n = 0; n<i; n++)
    {
        cout<<"student "<< n+1 << " score is: "<<p->score[n]<<endl;
        
    }
}

int main()
{
    struct Student* pa = NULL;
    int n, k;
    k = 0;
    cout<<"Please enter the number of student: ";
    cin>> stu.number;
    for(n = 0; n<stu.number; n++)
    {
        cout<<"student "<< n+1 << " score is: ";
        cin>>stu.score[n];
        if(stu.score[n]>90)
        {
            k++;
        }
    }
    cout<<"There are "<<k <<" student"<<endl;
    pa = &stu;
    display(pa,stu.number);
    return 0;
}