#include "computer.h"


Computer::Computer()
{

}

Computer::Computer(string name)
{
    this->name = name;
    this->score = 0;
    srand(time(0));
}

int Computer::firstCOmputer()
{
    int re = rand()%3;
    return re;
}

void Computer::addScore()
{
    this->score +=1;
}

string Computer::getName()
{
    return name;
}

int Computer::getScore()
{
    return score;
}

Computer::~Computer()
{

}

