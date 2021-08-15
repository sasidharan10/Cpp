#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int minSwaps(int *a, int n)
{
    // Time  : O(nlogn)
    // Space : O(n)

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i]={a[i],i};
    }
    sort(v.begin(), v.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second == i)
            continue;
        else
        {
            count++;
            swap(v[i], v[v[i].second]);
            i--;
        }
    }
    return count;
}
int main()
{
    int a[] = {1, 5, 4, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Min Swaps to Sort : " << minSwaps(a, n) << endl;
    return 0;
}