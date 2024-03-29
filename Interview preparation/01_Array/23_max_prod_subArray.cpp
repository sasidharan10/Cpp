#include <bits/stdc++.h>
using namespace std;
int maxProduct1(int *a, int n)
{
    // Time : O(n^2)
    // Space : O(1)

    int result = a[0], prod = 1;
    for (int i = 0; i < n; i++)
    {
        prod = a[i];
        for (int j = i + 1; j < n; j++)
        {
            prod *= a[j];
        }
        result = max(result, prod);
    }
    return result;
}
int maxProduct2(int *a, int n)
{
    // Time : O(n)
    // Space : O(1)

    int maxi = INT_MIN;
    int prefix = 1;
    int suffix = 1;
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;
        prefix = prefix * a[i];
        suffix = suffix * a[n - i - 1];
        maxi = max({prefix, suffix, maxi});
    }
    return maxi;
}
int main()
{
    // int a[] = {6, -3, -10, 0, 2};
    int a[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Max Prod O(n^2) : " << maxProduct1(a, n) << endl;
    cout << "Max Prod O(n)   : " << maxProduct2(a, n) << endl;
    return 0;
}