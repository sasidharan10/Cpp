#include <iostream>
#include <algorithm>
using namespace std;
class base1
{
public:
    void print()
    {
        cout << "This is Base_1 print" << endl;
    }
};
class base2
{
public:
    void print()
    {
        cout << "This is Base_2 print" << endl;
    }
};
class derived : public base1, public base2
{
public:
    derived()
    {
        base1::print();
    }
    void print() // overrides base class functions
    {
        cout << "This is Derived print" << endl;
    }
};
int main()
{
    derived d;
    d.print(); // here ambiguity occurs whether which 'print' function it should call from two classes
    // or use base2::print() while calling itself
    d.base1::print();
    d.base2::print();
    return 0;
}

/*

To resolve this issue, we explicitly tell the compiler to call 'print()' from base1 class.

void print()
    {
        base1::print();
    }

*/