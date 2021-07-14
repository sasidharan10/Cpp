#include <iostream>
#include <algorithm>
using namespace std;
int minimumJump(int *a, int n)
{
    int count = 1;
    if (n == 1)
        return 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= n - i)
        {
            i = i + a[i] - 1;
            count++;
        }
    }
    return count;
}
int main()
{
    int a[] = {1, 3, 6, 1, 0, 9};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Minimum jump : " << minimumJump(a, n);
    return 0;
}