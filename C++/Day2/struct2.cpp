/*
1. ����ṹ��Student �ṹ���Ա��string name 
								 string num
   ��д����ʵ�֣�N��ѧ����Ϣ �궨��N  3
2. inputStudentInfo(Student* s)��������Ҫ��ÿ��ѧ����Ϣ(���� ѧ��)������������ cin

3.find_stu(string serchName)����,��������ĳ��ѧ�������� �����ѧ������ ������������Ϣ��
  ���������,�����"not found"

main���ṹ������ 3����Ա
input(�ṹ�������ָ��);
����һ�������ҵ�ѧ������ ��С��
find��С����
*/

#include <iostream>
#define N 3
using namespace std;

struct Student
{
    string name;
    string num;
};

Student s[N];

void inputStudentInfo(struct Student *s)
{
    for(int i = 0; i<N; i++)
    {
        cout<<"Please enter the info of the student:"<<endl;
        cout<<"Please enter the name: "<<endl;
        getline(cin,s[i].name);
        cout<<"Please enter the num: "<<endl;
        getline(cin, s[i].num);
    } 
    
    
}

void find_stu(string serchName)
{
    cout<<serchName<<endl;
    
    cout<<"search: "<<endl;
    string stu_name;
    getline(cin,stu_name);
    for(int i = 0; i<N; i++)
    {
        if(s[i].name == serchName)
        {
            cout<<s[i].name<<" "<<s[i].num<<endl;
            return;
        }
    }
    cout<<"Not found"<<endl;
}



int main(int argc, char const *argv[])
{
    /* code */
    inputStudentInfo(s);
    cout<<s[1].name<<endl;

    // 
    string search_name;
    cin>>search_name;
    find_stu(search_name);
    return 0;
}
