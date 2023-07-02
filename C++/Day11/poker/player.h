#ifndef PLAYER_H
#define PLAYER_H
#include "poker.h"

class Player
{
    vector<Poker> plv;  //手牌
    string name;        //名字
public:
    Player(string name);

    void addPoker(Poker p);

    void showV();

    int getScore();
    ~Player();
};

#endif // PLAYER_H
