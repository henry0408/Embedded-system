#include <iostream>

using namespace std;

namespace Worker
{
    int age = 18;
    char name[] = "xiaohong";
    void show_name()
    {
        cout<<name<<endl;
    }
}

using namespace Worker;

namespace Teacher
{
    //int age = 19;
    char name[] = "xiaoli";
    void show_name()
    {
        cout<<name<<endl;
    }
} // namespace YourStd

using namespace Teacher;

int main(int argc, char const *argv[])
{
    /* code */
    Teacher::show_name();
    Worker::show_name();
    cout<<age<<endl;
    return 0;
}
