#include "player.h"


Player::Player(string name):name(name)
{

}


void Player::showV()
{
    for(vector<Poker>::iterator it = plv.begin();it != plv.end();it++)
    {
        it->show();
    }
}

int Player::getScore()      //当前手牌总分
{
    int sum = 0;
    for(vector<Poker>::iterator it = plv.begin();it != plv.end();it++)
    {
        //it->show();
        int s = it->getS();
        sum+=s;
    }
    return sum;
}

void Player::addPoker(Poker p)
{
    plv.push_back(p);
}

Player::~Player()
{

}

