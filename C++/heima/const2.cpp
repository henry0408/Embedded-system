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
    	//m_value = value;	//error, ������const��Ա�����иı��Ա������ֵ
        fun2();				//OK, const��Ա����ֻ�ܵ���const��Ա����
	    //fun3();				//error, const��Ա�������ܵ��÷�const��Ա����
    }
 
    void fun2() const
    {
    	fun1(34);
    }
 
    void fun3()
    {
    	fun1(34);	//OK, ��const ��Ա�����п��Ե���const��Ա����
    }
};
 
int main()
{
    const test t;	//����һ��const����
    t.fun1(12);		//OK, const����ֻ�ܵ���const��Ա����
    //t.fun3();		//error, const�������ܵ��÷�const��Ա����
 
    system("pause");
}