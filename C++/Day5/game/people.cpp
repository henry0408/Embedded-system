#include "people.h"

People::People(string name)
{
    this->name = name;
    this->score = 0;
}

int People::firstPeople()
{
    int re;
    cin>>re;
    return re;
}

void People::addScore()
{
    this->score +=1;
}

string People::getName()
{
    return name;
}

int People::getScore()
{
    return score;
}

People::~People()
{

}

