#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(30);
    s.insert(30);
    //»á×Ô¶¯ÉıĞòÅÅĞò

    //µü´úÆ÷±éÀú
    for(set<int>::iterator it = s.begin();it!= s.end();it++)
    {
        cout<<*it<<endl;    
    }

    //Çå¿Õ
    //s.clear();

    //´óĞ¡
    cout<<s.size()<<endl;

    //²éÕÒ
    cout<<s.count(30)<<endl;

    //²éÕÒ2
    set<int>::iterator iter = s.find(30);
    //É¾³ı
    if(iter != s.end())
    {
        s.erase(iter);
    }
    //É¾³ı2
    s.erase(10);    //ÓÃ¹Ø¼ü×ÖÉ¾³ı

    //É¾³ı3
    s.erase(s.begin(),s.end()); //ÇøÓòÉ¾³ı
}