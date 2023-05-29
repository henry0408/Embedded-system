/*¿‡÷–…Í«Î∂—ø’º‰*/


#include <iostream>

using namespace std;

class Student
{
public:
    int*p;
    void init_arr()
    {
        p = new int[4];
        for(int i= 0; i<4; i++)
        {
            p[i] = i;
        }
    }
    void show()
    {
        for(int i= 0; i<4; i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<""<<endl;
    }

    void free()
    {
        delete []p;
        p = NULL;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Student *s = new Student;
    s->init_arr();
    s->show();
    s->free();
    delete s;
    s = NULL;
    return 0;
}
