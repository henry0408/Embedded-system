#include "pockermanager.h"

Pockermanager* Pockermanager::ins = NULL;   //懒汉模式

Pockermanager::Pockermanager()
{
    color.push_back("red heart");
    color.push_back("black heart");
    color.push_back("square");
    color.push_back("flower");

    point.push_back("A");
    point.push_back("2");
    point.push_back("3");
    point.push_back("4");
    point.push_back("5");
    point.push_back("6");
    point.push_back("7");
    point.push_back("8");
    point.push_back("9");
    point.push_back("10");
    point.push_back("J");
    point.push_back("Q");
    point.push_back("K");

    //map容器作用：当发到一张牌的时候，获取一张牌的分值为多少
    score["A"] = 1;
    score["2"] = 2;
    score["3"] = 3;
    score["4"] = 4;
    score["5"] = 5;
    score["6"] = 6;
    score["7"] = 7;
    score["8"] = 8;
    score["9"] = 9;
    score["10"] = 10;
    score["J"] = 10;
    score["Q"] = 10;
    score["K"] = 10;
}

Pockermanager::Pockermanager(const Pockermanager &o)
{
    //功能：给成员变量逐个赋值
}

Pockermanager *Pockermanager::getIns()
{
    if(ins == NULL)
        ins = new Pockermanager;        //想什么时候用就什么时候给
    return ins;
}

Pockermanager::~Pockermanager()
{

}

