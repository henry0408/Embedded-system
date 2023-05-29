/*
��ϰ1��������MyArray ���������������� ���������Ԫ���е����ֵ����Сֵ��ƽ��ֵ
1.	�����Ա����private����  
int *p;
int length;
2.��Ա����input(int length);
		       lengthΪ����ĳ���;
			   ���鶯̬����new����������ĳ��ȣ��������飩
			   ���ܣ�cin��ʽ�����������ֵ
3.��Ա���� int max(); Ҫ�������ֵ
4.��Ա���� int min();
5.��Ա���� int avg();
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
        this->length = length;      //�����β����ֺͳ�Ա���������ظ�����this
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
