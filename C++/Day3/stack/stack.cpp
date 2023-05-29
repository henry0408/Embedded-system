#include "stack.h"

void MyStack::init(int t, int len)
{
    stack = new int[len]();
    top = t;
    length = len;
}

int MyStack::pop()
{
    length--;
    int pop_val = stack[top-1];
    top--;
    return pop_val;
}

bool MyStack::push(int data)
{
    if(length == top)
    {
        return false;
    }
    stack[top] = data;
    top++;
    length++;
}

void MyStack::print_info()
{
    for(int i=0; i<top; i++)
    {
        cout<<stack[i]<<" ";
    }
    cout<<""<<endl;
}

void MyStack::expand()
{
    int new_length = 2*length;
    int *new_stack = new int[new_length]();
    for(int i = 0; i<top; i++)
    {
        new_stack[i] = stack[i];
    }
    delete []stack;
    stack = new_stack;
    length = 2*length;
}