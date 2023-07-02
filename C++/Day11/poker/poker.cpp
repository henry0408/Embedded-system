#include "poker.h"

Poker::Poker(string color):color(color)     //大小王
{

}

Poker::Poker(string color, string point):color(color),point(point)
{
    //通过pockermanager获取当前牌的score
    map<string,int> s = Pockermanager::getIns()->getScore();
    this->score = s[point];
}

void Poker::show()
{
    cout<<color<<point<<endl;
}

Poker::~Poker()
{

}

