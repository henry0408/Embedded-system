#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>

using namespace std;

class People
{
private:
    string name;
    int score;

public:
    People(string name);
    int firstPeople();
    void addScore();
    string getName();
    int getScore();
    ~People();
};

#endif // PEOPLE_H
