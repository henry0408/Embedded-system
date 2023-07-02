#ifndef POKER_H
#define POKER_H
#include <iostream>

#include "pockermanager.h"

using namespace std;

class Poker
{
    string color;
    string point;
    int score;
public:
    Poker(string color);    //为大小王构造
    Poker(string color, string point);

    void show();

    inline int getS()
    {
        return score;
    }

    ~Poker();
};

#endif // POKER_H
