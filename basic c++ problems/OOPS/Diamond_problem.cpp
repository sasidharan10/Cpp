#include <iostream>
#include <algorithm>
using namespace std;
class base
{
public:
    int val;
};
class child1 : virtual public base
{
public:
    child1()
    {
        val = 10;
    }
};
class child2 : virtual public base
{
public:
    child2()
    {
        val = 20;
    }
};
class grandChild : public child2, public child1
{
public:
    grandChild()
    {
        cout << "Val: " << val;
    }
};
int main()
{
    grandChild g;
    return 0;
}

/*

- To avoid ambiguity, we inherit base class virtually, so when we try to access members
  from base class, compiler will automatically access base class through last inherited class
- That is, through child1(since child1 inherited last). If we change the order, we can access base
  through child2.

*/