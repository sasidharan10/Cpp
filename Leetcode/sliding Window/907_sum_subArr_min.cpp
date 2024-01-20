#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    int sumSubarrayMins(vector<int> &arr)
    {
        // TC: O(n^2)
        // SC: O(1)
        
        int n = arr.size();
        int mod = 1e9 + 7;
        int mini = INT_MAX;
        long long sum = 0, i = 0, j = 0;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, arr[i]);
            for (int j = i; j < n; j++)
            {
                mini = min(mini, arr[j]);
                sum = (sum + mini) % mod;
            }
            mini = INT_MAX;
        }
        return sum;
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 1, 2, 4};
    cout << "Result: " << s.sumSubarrayMins(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sum-of-subarray-minimums

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

907. Sum of Subarray Minimums

Given an array of integers arr, find the sum of min(b), where b ranges
over every (contiguous) subarray of arr. Since the answer may be
large, return the answer modulo 109 + 7.

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:

Input: arr = [11,81,94,43,3]
Output: 444

*/