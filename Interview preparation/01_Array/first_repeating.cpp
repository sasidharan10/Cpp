#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;
void first_repeat1(int *a, int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    // for (auto i : m)
    //     cout << i.first << " : " << i.second << endl;
    cout << "\nThe first repeating is : ";
    for (int j = 0; j < n; j++)
    {
        if (m[a[j]] > 1)
        {
            cout << a[j];
            return;
        }
    }
}
void first_repeat2(int *a, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    int *b = new int[max + 1]{};
    for (int j = 0; j < n; j++)
    {
        b[a[j]]++;
    }
    cout << "\nThe first repeating is : ";
    for (int k = 0; k < n; k++)
    {
        if (b[a[k]] > 1)
        {
            cout << a[k];
            break;
        }
    }
    delete[] b;
}
int main()
{
    int a[] = {1, 10, 12, 7, 3, 4, 7, 12, 5, 6, 4, 12, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    first_repeat1(a, n);
    first_repeat2(a, n);
    return 0;
}