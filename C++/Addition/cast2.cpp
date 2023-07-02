#include <iostream>

using namespace std;


int main(){
    double a = 7;
    void *p = &a;
    double* dp = static_cast<double*>(p);
    *dp = 100;
    cout<<a<<endl;
}