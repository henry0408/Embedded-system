#include <iostream>
#include <string>
 
using namespace std;
 
class test
{
private:
    int m_value;
public:
 
    void fun1(int value) const
    {
    	//m_value = value;	//error, 不能在const成员函数中改变成员变量的值
        fun2();				//OK, const成员函数只能调用const成员函数
	    //fun3();				//error, const成员函数不能调用非const成员函数
    }
 
    void fun2() const
    {
    	fun1(34);
    }
 
    void fun3()
    {
    	fun1(34);	//OK, 非const 成员函数中可以调用const成员函数
    }
};
 
int main()
{
    const test t;	//定义一个const对象
    t.fun1(12);		//OK, const变量只能调用const成员函数
    //t.fun3();		//error, const变量不能调用非const成员函数
 
    system("pause");
}