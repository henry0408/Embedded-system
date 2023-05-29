#include "teacher.h"
# include "student.h"

Teacher::Teacher(Student *s[])
{
    for(int i = 0; i<3; i++)
    {
        this->students[i] = s[i];
    }
}

Student *Teacher::randHappy()
{
    srand(time(0));
    int id = rand()%3;
    return this->students[id];
}

void Teacher::hehe(Student *s)
{
    s->setScore(0);
}

void Teacher::show()
{
    for(int i = 0; i<3; i++)
    {
        students[i]->show();
    }
}


Teacher::~Teacher()
{

}

