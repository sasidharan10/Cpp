#include <iostream>
#include <algorithm>
using namespace std;
int smallestSubArraySum1(int *a, int n, int x)
{
    int min = n + 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
            return 1;
        sum = a[i];
        for (int j = i + 1; j < n; j++)
        {
            sum += a[j];
            if (sum > x && j - i + 1 < min)
                min = j - i + 1;
        }
    }
    return min;
}
int smallestSubArraySum2(int *a, int n, int x)
{
    int minlength = n + 1;
    int sum = 0;
    int i = 0, j = 0;
    while (i <= j && j < n)
    {
        while (sum <= x && j < n)
        {
            sum += a[j++];
        }
        while (sum > x && i < n)
        {
            minlength = min(minlength, j - i);
            sum -= a[i++];
        }
    }
    return minlength;
}
int main()
{
    int a[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Min Length Of Sub-Array : " << smallestSubArraySum1(a, n, x) << endl;
    cout << "Min Length Of Sub-Array : " << smallestSubArraySum2(a, n, x) << endl;
    return 0;
}