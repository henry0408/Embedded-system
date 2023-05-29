/*
 *练习6：定义扑克类Poker，私有属性color，point，创建54张牌存入数组中
            大小王单独处理；只有花色，没有分值
            1.构造函数，初始化花色和点数（普通的牌）
            2.构造函数，初始化花色（大/小王）
            3.成员函数 toString();显示54张牌 例：红桃2  黑桃A

            4.main 创建数组，54个对象指针  p？ = new Poker("方片","A");
                                            p ？= new Poker("大王");
                    输出54张牌

string colors[4] = {"红桃", "黑桃", "方片", "草花"};
string points[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K"};
 */



#ifndef POCKER_H
#define POCKER_H

#include <iostream>
using std::string;

class Pocker
{
private:
    string point;
    string color;
public:
    Pocker(string p, string c);
    Pocker(string c);
    string toString();
};

#endif // POCKER_H
