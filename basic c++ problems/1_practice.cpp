#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if (j < i + 1 || j >= 2 * n - i - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = 2 * n; j > 0; j--)
        {
            if (j < i + 1 || j >= 2 * n - i + 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}