#include <iostream>

using namespace std;

class Product
{
private:
    /* data */
    string name;
    int price;
public:
    void set_product(string name, int price);
    string get_name();
    int get_price();
};

void Product::set_product(string name, int price)
{
    this->name = name;
    this->price = price;
}

string Product::get_name()
{
    return name;
}

int Product::get_price()
{
    return price;
}


int main(int argc, char const *argv[])
{
    /* code */
    Product p1;
    p1.set_product("sofa",100);
    cout<<p1.get_name()<<endl;
    cout<<p1.get_price()<<endl;

    Product *p2 = new Product;
    p2->set_product("television",50);
    cout<<p2->get_name()<<endl;
    cout<<p2->get_price()<<endl;
    return 0;
}
