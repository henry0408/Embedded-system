/*
��ϰ.�Զ���һ����ʵ��ջ�ṹ���г�ջ��pop������ջ��push�����ܣ����Դ�����������

class MyStack

	1.��Ա����ָ��ָ������int* stack;

	2.��Ա������ʾ���鳤��length = 10

	4.��Ա������ʾջ��  top = 0

	3.��Ա����pop()��push(int data)

	5.��Աinit����Ա��������ʼֵ(index��length = 10����������)

6.	��Ա����expand(); �������飬����Ϊԭ�����������(���Բ���)

˼·��������ڵ��������ˣ�����һ����������飬��ԭ����������ݿ������µ�������


*/
#include "stack.h"

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    MyStack st;
    st.init(0,10);
    st.push(9);
    st.push(8);
    st.push(11);
    st.print_info();

    int value = st.pop();
    cout<<"The pop value is "<<value<<endl;
    st.print_info();

    int value2 = st.pop();
    cout<<"The pop value is "<<value2<<endl;
    st.print_info();

    st.push(100);
    st.push(200);
    st.print_info();

    st.expand();
    st.print_info();
    return 0;
}

