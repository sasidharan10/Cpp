#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> ans;
    int maxi = 0;
    void solve(int ind, int n, vector<int> &nums, vector<int> lt, int last)
    {
        if (ind == n)
        {
            if (lt.size() > maxi)
            {
                maxi = lt.size();
                ans = lt;
            }
            return;
        }

        if ((last == -1) || (nums[ind] % last == 0 || last % nums[ind] == 0))
        {
            solve(ind + 1, n, nums, lt, last);
            last = nums[ind];
            lt.push_back(nums[ind]);
            solve(ind + 1, n, nums, lt, last);
            // lt.pop_back();
        }
        else
        {
            solve(ind + 1, n, nums, lt, last);
            // lt.pop_back();
        }
    }
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lt;
        sort(nums.begin(), nums.end());
        solve(0, n, nums, lt, -1);
        return ans;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{1, 2, 4, 8};
    // vector<int> nums{3, 4, 6, 9};
    vector<int> nums{5, 9, 18, 54, 108, 540, 90, 180, 360, 720};
    vector<int> ans = s.largestDivisibleSubset(nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/largest-divisible-subset

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

368. Largest Divisible Subset

Given a set of distinct positive integers nums, return the largest
subset answer such that every pair (answer[i], answer[j]) of
elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]

*/