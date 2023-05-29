#include "student.h"

using namespace std;

Student::Student(int score, string name)
{
    this->score = score;
    this->name = name;
}

void Student::setScore(int score)
{
    this->score = score;
}

void Student::show()
{
    cout<<"score is: "<<this->score<<" name is: "<<this->name<<endl;
}

Student::~Student()
{

}

