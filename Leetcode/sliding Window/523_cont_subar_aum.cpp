#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force
    bool checkSubarraySum2(vector<int> &nums, int k)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            int start = 0;
            int end = i + 1;
            while (end < n)
            {
                int s = start;
                int sum = 0;
                while (s <= end)
                {
                    sum += nums[s];
                    s++;
                }
                if (sum % k == 0)
                    return true;
                start++;
                end++;
            }
        }
        return false;
    }
    // Optimal
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        // TC: O(n)
        // SC: O(n)
        unordered_map<int, int> map;
        map[0] = -1;
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
            int r = total % k;
            if (map.find(r) == map.end())
            {
                map[r] = i;
            }
            else if (abs(map[r] - i) >= 2)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> nums{23, 2, 4, 6, 7};
    int k = 6;
    cout << "Array contains Continuous Subarray Sum?: " << s.checkSubarraySum(nums, k);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/continuous-subarray-sum/

Youtube: https://www.youtube.com/watch?v=OKcrLfR-8mE

algorithm:

*/