#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using  namespace std;

class Computer
{
private:
    string name;
    int score;
public:
    Computer(string name);
    int firstCOmputer();
    void addScore();
    string getName();
    int getScore();

    ~Computer();
};

#endif // COMPUTER_H
