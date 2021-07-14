#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
void nTimesElementOccurence(int *a, int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    // cout << "Elements are : ";
    for (auto i : m)
        if (i.second > n/k)
            cout << "Number : " << i.first << " "
                 << "occurence : " << i.second << endl;
}
int main()
{
    int a[] = {6, 5, 1, 1, 10, 7, 2, 2, 2, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;
    nTimesElementOccurence(a, n, k);
    return 0;
}