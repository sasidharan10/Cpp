#include <bits/stdc++.h>
using namespace std;
int lcm1(int a, int b)
{
    // TC: O(n)
    // SC: O(n)
    int mini = min(a, b);
    int maxi = max(a, b);
    int prod = mini * maxi;
    for (int i = maxi; i <= prod; i += maxi)
    {
        if (i % mini == 0)
            return i;
    }
    return prod;
}
int lcm2(int a, int b)
{
    // TC: O(n)
    // SC: O(n)

    int gcd = __gcd(a, b);
    int lcm = (a / gcd) * b;
    return lcm;
}
int main()
{
    int a = 4, b = 5;
    cout << "LCM (Brute force) : " << lcm1(a, b);
    cout << "\nLCM (using GCD) : " << lcm2(a, b);
    return 0;
}