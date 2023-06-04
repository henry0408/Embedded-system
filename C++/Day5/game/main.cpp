#include <iostream>
#include "computer.h"
#include "people.h"

using namespace std;

string chuquan(int r)
{
    string str;
    switch (r) {
    case 0:
        str = "rock";
        break;
    case 1:
        str = "scissors";
        break;
    case 2:
        str = "paper";
        break;
    case 4:
        str = "rock";
        break;
    case 7:
        str = "scissors";
        break;
    case 10:
        str = "paper";
        break;
    default:
        break;
    }
}

int main()
{
    People p("xm");
    Computer c("AI");

    int pf = p.firstPeople();
    int cf = c.firstCOmputer();

    int result = cf + pf;

    if(result == 5 || result == 9 || result == 10)
    {
        p.addScore();
    }
    else if(result == 6 || result == 7 || result == 11)
    {
        c.addScore();
    }
    else
    {
        cout<<"equal"<<endl;
    }
    return 0;
}

