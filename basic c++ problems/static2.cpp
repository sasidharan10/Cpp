#include <bits/stdc++.h>
using namespace std;
class base
{
public:
    int x;
    static int y;
    void printX()
    {
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
    }
    static void printY()
    {
        // cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
    }
};

int base::y;

int main()
{
    base b1;
    b1.x = 10;
    b1.y = 20;
    base b2;
    b2.x = 30;
    b2.y = 40;
    cout << "X: " << b1.x << endl;
    cout << "X: " << b2.x << endl;
    cout << "Y: " << b1.y << endl;
    cout << "Y: " << b2.y << endl;
    cout << "Using functions: " << endl;
    b1.printX();
    b1.printY();
    return 0;
}

/*

- Static members are created only one, and they have a separate memory space.
- unlike normal data members, which have separate memory for each object, static variables can only have
  1 memory space, hence, its values will be reflected, if changes are made by any objects.
- Static functions can only access static variables, while normal functions can access both,
  normal and static variables.

*/