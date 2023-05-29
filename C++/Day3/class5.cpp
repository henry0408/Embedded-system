/*
练习1：定义类MyArray 向数组中输入整数 并求出数组元素中的最大值，最小值和平均值
1.	数组成员变量private修饰  
int *p;
int length;
2.成员函数input(int length);
		       length为数组的长度;
			   数组动态创建new（按照输入的长度，创建数组）
			   功能：cin方式，输入数组的值
3.成员函数 int max(); 要求带返回值
4.成员函数 int min();
5.成员函数 int avg();
*/

#include <iostream>

using namespace std;

class MyArray
{
private:
    int *p;
    int length;
public:
    void input(int length)
    {
        p = new int[length]();
        for(int i =0;i<length; i++)
        {
            cin>>p[i];
            getchar();
        }
        this->length = length;      //函数形参名字和成员变量名字重复，用this
    }

    void print_info()
    {
        cout<<"the len is: "<<length<<endl;
        for(int i = 0; i<length; i++)
        {
            cout<<p[i]<<endl;
        }
    }

    void free()
    {
        delete []p;
        p = NULL;
    }

    int max()
    {
        int max_num = p[0];
        int max_index = 0;
        for(int i = 1; i<length; i++)
        {
            if(p[i]>max_num)
            {
                max_num = p[i];
                max_index = i;
            }
        }
        return max_num;
    }

    int min()
    {
        int min_num = p[0];
        int min_index = 0;
        for(int i = 1; i<length; i++)
        {
            if(p[i]<min_num)
            {
                min_num = p[i];
                min_index = i;
            }
        }
        return min_num;
    }

};

int main(int argc, char const *argv[])
{
    /* code */
    MyArray arr;
    int len;
    cout<<"please enter the len: ";
    cin>>len;
    arr.input(len);

    arr.print_info();
    // int max_num = arr.max();
    // int min_num = arr.min();

    // cout<<max_num<<" "<<min_num<<endl;

    arr.free();
    return 0;
}
