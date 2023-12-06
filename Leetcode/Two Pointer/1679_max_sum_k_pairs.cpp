#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute
    int maxOperations3(vector<int> &nums, int k)
    {
        // TC: O(n^2) brute force
        // SC: O(1)

        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == -1) // ignoring visited numbers
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] == -1)
                    continue;
                if (nums[i] + nums[j] == k)
                {
                    cnt++;
                    // marking visited pairs
                    nums[i] = -1;
                    nums[j] = -1;
                }
            }
        }
        return cnt;
    }

    // Better
    int maxOperations2(vector<int> &nums, int k)
    {
        // TC: O(nlogn)
        // SC: O(n)

        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = k - nums[i];
            if (mp.find(temp) != mp.end())
            {
                cnt++;
                if (mp[temp] == 1)
                    mp.erase(temp);
                else
                    mp[temp]--;
            }
            else
                mp[nums[i]]++;
        }
        return cnt;
    }

    // Optimal
    int maxOperations(vector<int> &nums, int k)
    {
        // TC: O(n) + O(nlogn)
        // SC: O(1)

        // using 2-pointer approach
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int cnt = 0;
        while (left < right)
        {
            if (nums[left] + nums[right] == k)
            {
                cnt++;
                left++;
                right--;
            }
            else if (nums[left] + nums[right] > k)
            {
                right--;
            }
            else
                left++;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> nums{3, 1, 3, 4, 3};
    int k = 6;
    cout << "Max Number of Operations to remove K-Sum Pairs: " << s.maxOperations(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/max-number-of-k-sum-pairs

Youtube:

algorithm:

*/

/*

1679. Max Number of K-Sum Pairs

You are given an integer array nums and an integer k.
In one operation, you can pick two numbers from the array whose sum
equals k and remove them from the array.
Return the maximum number of operations you can perform on the array.

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.

 */