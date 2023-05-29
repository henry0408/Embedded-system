#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

//declare class
class Person
{
private:
    int age;
public:
    void set_age(int age);
    void get_age();
};
#endif