#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        // TC: O(nlogn) + O(n)
        // SC: O(n)
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i += 3)
        {
            if (nums[i + 2] - nums[i] > k)
                return {};
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 2;
    vector<vector<int>> ans = s.divideArray(nums, k);
    cout << "Result: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

2966. Divide Array Into Arrays With Max Difference

You are given an integer array nums of size n and a positive integer k.

Divide the array into one or more arrays of size 3 satisfying the following conditions:

Each element of nums should be in exactly one array.
The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing all the arrays. If it is impossible to
satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

Example 1:

Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
Output: [[1,1,3],[3,4,5],[7,8,9]]
Explanation: We can divide the array into the following arrays: [1,1,3], [3,4,5] and [7,8,9].
The difference between any two elements in each array is less than or equal to 2.
Note that the order of elements is not important.

Example 2:

Input: nums = [1,3,3,2,7,3], k = 3
Output: []
Explanation: It is not possible to divide the array satisfying all the conditions.

*/