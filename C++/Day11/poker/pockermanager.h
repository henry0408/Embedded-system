#ifndef POCKERMANAGER_H
#define POCKERMANAGER_H
#include <iostream>
#include <vector>
#include <map>
using namespace std;

//单例模式

//私有构造和拷贝构造函数
//静态类指针

class Pockermanager
{
private:
    vector<string> color;       //花色
    vector<string> point;       //点数
    map<string,int> score;      //扑克牌对应的分数

    static Pockermanager* ins;  //静态类指针
    Pockermanager();
    Pockermanager(const Pockermanager& o);

public:
    static Pockermanager* getIns();     //静态成员函数

    //inline函数减少开销
    inline vector<string> getColor()
    {
        return color;
    }

    inline vector<string> getPoint()
    {
        return point;
    }

    inline map<string,int> getScore()
    {
        return score;
    }

    ~Pockermanager();
};

#endif // POCKERMANAGER_H
