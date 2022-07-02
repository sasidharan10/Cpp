#include <iostream>
#include <algorithm>
using namespace std;
class base
{
public:
    virtual void print() // to avoid during runtime
    {
        cout << "This is base print()" << endl;
    }
    void display()
    {
        cout << "This is base display()" << endl;
    }
};
class derived : public base
{
public:
    void print()
    {
        cout << "This is derived print()" << endl;
    }
    void display()
    {
        cout << "This is derived display()" << endl;
    }
};
int main()
{
    base *b;
    derived d;
    b = &d;
    b->print();
    b->display();
    return 0;
}

/*

to print function from derived class we have to add virtual keyword to base function

*/