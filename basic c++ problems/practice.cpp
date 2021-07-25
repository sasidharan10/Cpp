#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
bool findSubArray5(int *a, int *b, int n, int m)
{
    // Time : O(n)+O(m)
    // Space : O(n)
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    for (int j = 0; j < m; j++)
    {
        if(m[b[j]]>0)
        {
            m[b[j]]--;
        }
        else 
            return false;
    }
    return true;
}
int main()
{
    int a[] = {3, 5, 6, 4, 1, 2};
    int b[] = {1, 2, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    cout << "5) Sub-Array Exists (using map) ?   : " << findSubArray5(a, b, n, m) << endl;
    return 0;
}