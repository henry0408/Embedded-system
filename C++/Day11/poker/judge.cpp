#include "judge.h"

Judge::Judge()
{
    //获取花色
    vector<string> colors = Pockermanager::getIns()->getColor();
    //获取点数
    vector<string> points = Pockermanager::getIns()->getPoint();
    //创建扑克牌，放入容器
    for(int i = 0; i<colors.size();i++)
    {
        for(int j = 0; j<points.size();j++)
        {
            pv.push_back(Poker(colors[i],points[j]));
        }
    }

//    //创建大小王
//    pv.push_back(Poker("king"));
//    pv.push_back(Poker("king2"));

    srand(time(0));
    shuffle();      //创建时直接洗牌
}

void Judge::shuffle()
{
    for(int i = 0; i<50; i++)
    {
        //产生随机数
        int r1 = rand()%52;
        int r2 = rand()%52;
        //交换
        Poker tmp = pv[1];
        pv[r1] = pv[r2];
        pv[r2] = tmp;
    }
}

Poker Judge::deal()
{
    //获取尾部元素
    Poker p = pv.back();

    cout<<"The card sent by Judge is: ";
    p.show();   //打印牌的信息

    //删除尾部元素
    pv.pop_back();

    return p;
}

Judge::~Judge()
{

}

