#include <bits/stdc++.h>
using namespace std;
class A
{
    int a;
public:
    A &setData(int a)
    {
        this->a = a;
        return *this;
    }
    void getData()
    {
        cout << "The value of a is " << a << endl;
    }
};

int main()
{
    A a;
    a.setData(4).getData();
    return 0;
}

/*

- “this” is a keyword that is an implicit pointer. “this” pointer points
  to the object which calls the member function.
- “this” pointer can be used to return a reference to the invoking object.

*/