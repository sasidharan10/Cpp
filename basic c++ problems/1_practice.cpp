#include <iostream>
using namespace std;
int main()
{
    int x = 321;  // 371
    int sum = 0, n = 0;
    n = x;
    while (n > 0)
    {
        int r = n % 10;
        n = n / 10;
        sum += (r * r * r);
    }
    if (x == sum)
        cout << "They are armstrong" << endl;
    else
        cout << "Not armstrong!!!" << endl;
    return 0;
}