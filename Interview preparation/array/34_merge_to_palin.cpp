#include <iostream>
#include <algorithm>
using namespace std;
int findMinMerge(int *a, int n)
{
    int count = 0;
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (a[i] == a[j])
        {
            i++;
            j--;
        }
        else if (a[i] < a[j])
        {
            ++i;
            a[i] += a[i - 1];
            count++;
        }
        else
        {
            --j;
            a[j] += a[j + 1];
            count++;
        }
    }
    return count;
}
int main()
{
    int a[] = {1, 4, 5, 9, 1};
    // int a[] = {11, 14, 15, 99};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Min Merge Operation To make Palindrome : " << findMinMerge(a, n) << endl;
    return 0;
}