#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute
    int floorSqrt2(int n)
    {
        // TC: O(n)
        // SC: O(1)

        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (i * i <= n)
            {
                ans = i;
            }
            else
                break;
        }
        return ans;
    }
    // Optimal
    int floorSqrt(int n)
    {
        // TC: O(Logn)
        // SC: O(1)

        int ans = 0;
        int low = 1, high = n;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (mid * mid <= n)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    int n = 28;
    cout << "Square Root: " << s.floorSqrt(n) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/square-root-integral_893351

leetcode: https://leetcode.com/problems/sqrtx/description/

Youtube: https://www.youtube.com/watch?v=Bsv3FPUX_BA&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=11

algorithm:

- Binary search

*/