#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
void countOccurence1(int *a, int n, int k)
{
    // Time  :  O(2n)
    // Space :  O(n)

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
void countOccurence2(int *a, int n, int k)
{
    // Time  :  O(2n)
    // Space :  O(n)

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
    countOccurence1(a, n, k);
    return 0;
}

/*

MOORE VOTING ALGORITHM

*/