#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute
    int floorSqrt2(int x)
    {
        // TC: O(n)
        // SC: O(1)

        int ans = 0;
        for (int i = 1; i < x; i++)
        {
            if (i * i <= x)
            {
                ans = i;
            }
            else
                break;
        }
        return ans;
    }
    // Optimal
    int floorSqrt(int x)
    {
        // TC: O(Logn)
        // SC: O(1)
        
        int ans = 0;
        int low = 1, high = x;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (mid * mid <= x)
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
    int x = 28;
    cout << "Square Root: " << s.floorSqrt(x) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/square-root-integral_893351

leetcode: https://leetcode.com/problems/sqrtx/description/

Youtube: https://www.youtube.com/watch?v=Bsv3FPUX_BA&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=11

algorithm:

- Binary search

*/


/*

69. Sqrt(x)

Given a non-negative integer x, return the square root of x rounded down 
to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down 
to the nearest integer, 2 is returned.


*/