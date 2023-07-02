#include <iostream>
#include "player.h"
#include "judge.h"


using namespace std;

int main()
{
    //创建裁判类对象
    Judge j;

    //创建玩家
    Player p("xm");


    bool flag = true;      //控制游戏是否继续
    while (flag) {
        cout<<"Want poker ? y/n"<<endl;
        char c;
        cin>>c;
        if(c == 'n')
        {
            flag = false;
            cout<<"Finished"<<endl;
            cout<<"Your score is: "<<p.getScore()<<endl;
        }
        else
        {

            //发牌
            Poker p1 = j.deal();
            p.addPoker(p1); //放入手牌
            //显示玩家手牌
            p.showV();


        }
        //获取总分
        if(p.getScore()>21)
        {
            flag = false;
            cout<<"Game Over"<<endl;
        }
        else if(p.getScore()==21)
        {
            flag = false;
            cout<<"Win"<<endl;
        }

    }
//    //获取总分
//    p.getScore();

    return 0;
}

