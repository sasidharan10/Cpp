#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n = 5;
    int a[5] = {1, 2, 3, 4, 5};
    int r = 4;
    int i = r;
    int pos;
    while (r--)
    {
        pos = n % i;
        a[pos] = 0;
        n--;
        if (a[pos] == 0)
        {
            pos++;
        }
    }
    cout << "\nPosition : " << a[pos] << endl;
    return 0;
}