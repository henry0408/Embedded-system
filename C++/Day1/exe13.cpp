/*
��ϰ6����������ַ�������
�������  �����������飨�ַ������飩string names[]={"rose","jack","tom"}��
			�����ȡһ�������е���Ա 

		ͷ�ļ���#include<cstdlib>
				#include<ctime>
		������srand(time(0));��ʼ���������
				rand()%5;���������

*/

#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    // string names[]={"rose","jack","tom"};
    // srand(time(0));

    // int num = rand()%3;  //5%3 -2 2%2 -2
    // cout<<names[num]<<endl;

    // cout<<sizeof(names)/sizeof(string)<<endl;
    
    
    int length;
    cout<<"please enter the len"<<endl;
    cin>>length;
    string str[length];
    for(int i = 0; i<length; i++)
    {
        /* code */
        string s1;
        cout<<"please enter the name"<<endl;
        cin>>s1;
        str[i] = s1;
    }

    for(int j = 0; j<length; j++)
    {
        cout<<str[j]<<endl;
    }
    

    return 0;
}
