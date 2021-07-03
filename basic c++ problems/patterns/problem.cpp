#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, count = 1;
    cout << "Enter n : ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << "*";
        }
        cout << " ";
        count=i;
        for (int k = 1; k <= i; k++)
        {
            cout << count;
            count++;
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        int s = n;
        for (int j = 1; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= n - i + 1; k++)
        {
            cout << s--;
        }
        cout << " ";
        for (int l = 2 * i - 1; l <= 2*n; l = l + 2)
        {
            cout << l;
        }
        cout << endl;
    }
    return 0;
}