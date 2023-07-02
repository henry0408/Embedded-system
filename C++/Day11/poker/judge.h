#ifndef JUDGE_H
#define JUDGE_H

#include "poker.h"
#include <vector>
#include <cstdlib>
#include <ctime>


class Judge
{
    //私有成员容器，存放顺序的54张牌
    vector<Poker> pv;

public:
    Judge();    //构造函数中给容器初始化
    void shuffle();     //洗牌
    Poker deal();
    ~Judge();
};

#endif // JUDGE_H
