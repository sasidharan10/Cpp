#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Worst solution
    int subarraySum3(vector<int> &nums, int k)
    {
        // TC: O(n ^ 3) gives TLE
        // SC: O(1)

        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 0;
                bool flag = false;
                for (int l = i; l <= j; l++)
                {
                    flag = true;
                    sum += nums[l];
                }
                if (sum == k && flag)
                {
                    cnt++;
                    flag = false;
                }
            }
        }
        return cnt;
    }

    // brute force
    int subarraySum2(vector<int> &nums, int k)
    {
        // TC: O(n ^ 2)
        // SC: O(1)

        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = nums[i];
            if (sum == k)
                cnt++;
            for (int j = i + 1; j < n; j++)
            {
                sum += nums[j];
                if (sum == k)
                    cnt++;
            }
        }
        return cnt;
    }

    // Optimal
    int subarraySum(vector<int> &nums, int k)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1; // edge case (if whole array sum == k, then (cumSum - k) = 0)
        int cnt = 0;
        int cumSum = 0;
        for (int i = 0; i < n; i++)
        {
            cumSum += nums[i];
            if (mp[cumSum - k])
            {
                cnt += mp[cumSum - k];
            }
            mp[cumSum]++;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{1, 2, 3};
    // int k = 3;
    vector<int> nums{3, 4, 7, -2, 2, 1, 4, 2};
    int k = 7;
    cout << "Total SubArray Sum K: " << s.subarraySum(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/subarray-sum-equals-k/

Youtube: https://www.youtube.com/watch?v=-SWrz90jCUM

algorithm:

- worst and brute force

- In worst solution, we just generate every possible subarray
  and then take their sum, and check if(sum == k).
- In Brute force, we take the sum while traversing itself,
  hence reduces TC from O(n ^ 3) -> O(n ^ 2).

- Optimal approach

- In optimal approach, we use a map, to keep track of previous
  cummulative sums.
- As we traverse the array, we take the cummulative sum, and check
  if if (mp[cumSum - k]) exists. if yes, then a subarray with
  sum k exists.

*/