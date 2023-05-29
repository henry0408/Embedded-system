#include <iostream>
#include "student.h"
#include "teacher.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    Student s1(18, "aa");
    Student s2(20, "bb");
    Student s3(21, "cc");

    Student *students[]={&s1,&s2,&s3};

    Teacher t(students);

    t.hehe(t.randHappy());
    t.show();

    return 0;
}

