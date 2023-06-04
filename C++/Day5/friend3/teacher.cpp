#include "teacher.h"


void Teacher::swap(Student &a, Student &b)
{
    Student tmp = a;
    a = b;
    b = tmp;
}

void Teacher::sort()
{
    for(int i=0; i<5-1; i++)
    {
        for(int j = 0; j<5-1-i; j++)
        {
            if(s[j]->score<s[j+1]->score)
            {
                //swap(*s[j],*s[j+1]);
                Student *tmp = s[j];
                s[j] = s[j+1];
                s[j+1] = tmp;
            }
        }
    }
}

void Teacher::show()
{
    for(int i = 0; i<5; i++)
    {
        cout<<s[i]->name<<" "<<s[i]->score<<endl;
    }
}

Teacher::~Teacher()
{

}

