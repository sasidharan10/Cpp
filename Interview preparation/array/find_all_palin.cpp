#include <iostream>
#include <algorithm>
using namespace std;
bool findAllPalinfrome(int *a, int n)
{
    int ans = 0,temp=0,rem=0;
    for (int i = 0; i < n; i++)
    {
        ans=0;
        temp = a[i];
        while (temp > 0)
        {
            rem = temp % 10;
            temp /= 10;
            ans = ans * 10 + rem;
        }
        if (ans != a[i])
            return false;
    }
    return true;
}
int main()
{
    int a[] = {121, 131, 20};
    // int a[] = {111, 121, 222, 333, 444};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Min Merge Operation To make Palindrome : " << findAllPalinfrome(a, n) << endl;
    return 0;
}