#include <iostream>

using namespace std;

class Person
{
public:
	Person()
	{
		cout<<"moren"<<endl;
	}
	Person(int age, int height)
	{
		cout<<"youcan"<<endl;
		m_age = age;
		m_height = new int(height);
	}

    //�Լ�ʵ�ֿ�������
	Person(const Person&p)
	{
		cout<<"kaobei"<<endl;
		m_age = p.m_age;
		//m_height = p.m_height;		//������Ĭ��ʵ�ֵ������д���
		
		//���
		m_height = new int(*p.m_height);
	}

	~Person()
	{
		//���������ٵ����ݽ����ͷ�
		if(m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		
		cout<<"xigou"<<endl;
	}
	
	int m_age;
	int *m_height;
};

void test()
{
    Person p1(18,160);
    cout<<"p1 age is "<<p1.m_age<<" height is "<<*p1.m_height<<endl;	//18 160
    
    Person p2(p1);
    cout<<"p2 age is "<<p1.m_age<<" height is "<<*p2.m_height<<endl;//18 160�Զ���Ŀ�������
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
