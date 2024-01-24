#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    vector<int> findErrorNums3(vector<int> &nums)
    {
        // TC: O(nlogn)
        // SC: O(1)

        int n = nums.size();
        vector<int> ans(2, 0);
        sort(nums.begin(), nums.end());
        int dup = 0;
        int sum = nums[0];
        for (int i = 1; i < n; i++)
        {
            sum += nums[i];
            if (nums[i] == nums[i - 1])
            {
                dup = nums[i];
            }
        }
        int total = (n * (n + 1)) / 2;
        int missing = total - (sum - dup);
        ans[0] = dup;
        ans[1] = missing;
        return ans;
    }

    // Better
    vector<int> findErrorNums2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        vector<int> mp(n + 1, 0);
        vector<int> ans(2, 0);
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (mp[i] == 2)
                ans[0] = i;
            if (mp[i] == 0)
                ans[1] = i;
        }
        return ans;
    }

    // Optimal
    vector<int> findErrorNums(vector<int> &nums)
    {
        // TC: O(n) + O(n)
        // SC: O(2)

        int n = nums.size();
        vector<int> ans(2, 0);
        int duplicate = 0, missing = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[abs(nums[i]) - 1] < 0)
                duplicate = abs(nums[i]);
            else
                nums[abs(nums[i]) - 1] *= (-1);
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                missing = i + 1;
                break;
            }
        }
        ans[0] = duplicate;
        ans[1] = missing;
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 2, 3};
    vector<int> ans = s.findErrorNums(nums);
    cout << "Duplicate and Missing number: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/set-mismatch

Youtube:

algorithm:

- Brute Force Approach:

- sort and find the duplicate no.
- use (n*(n+1))/2 to find the sum from 1 - n.
- Subtract the duplicate no, and then subtract the result with n to get the
  missing no.

- Better Approach:

- Use map and find freq of every no.
- (freq == 2) will be duplicate no and (freq == 0) will be missing no.

- Optimal Approach

- we mark each nums[i]'s corresponding index(nums[i] - 1), if it was sorted) as negative.
  If any number's index(nums[i] - 1) is already marked as negative,
  then that's the duplicate number.
- Iterate again, check which number is positive, and that number's i+1 will be the
  missing number.

*/

/*

645. Set Mismatch

You have a set of integers s, which originally contains all the numbers
from 1 to n. Unfortunately, due to some error, one of the numbers in s
got duplicated to another number in the set, which results in repetition
of one number and loss of another number.

You are given an integer array nums representing the data
status of this set after the error.

Find the number that occurs twice and the number that is missing
and return them in the form of an array.

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:

Input: nums = [1,1]
Output: [1,2]

*/