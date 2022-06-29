#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 1, c = 0;
    int x = 8;
    cout << "The fibonacci series is : " << endl;
    for (int i = 0; i < x; i++)
    {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    // cout<<a;
    return 0;
}
