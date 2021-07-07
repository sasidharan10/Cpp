#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;
void first_not_repeat(int *a, int n)
{
    unordered_map<int, int> m{};
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    cout << "The first non repeating is : ";
    for (auto i : m)
        if (i.second == 1)
            cout << i.first << " ";
}
int main()
{
    int a[] = {1, 2, 3, 3, 4, 5, 6, 6, 7, 1, 8, 2, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    first_not_repeat(a, n);
    return 0;
}