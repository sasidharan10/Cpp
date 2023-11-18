#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int bSearch(int target_idx, int k, vector<long long> &prefix, vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int r = target_idx;
        int target = nums[target_idx];
        int best_idx = target_idx;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            long long cnt = target_idx - mid + 1;
            int windowSum = cnt * target;
            int currSum = prefix[target_idx] - prefix[mid] + nums[mid];
            int ops = windowSum - currSum;
            if (ops > k)
            {
                l = mid + 1;
            }
            else
            {
                best_idx = mid;
                r = mid - 1;
            }
        }
        return target_idx - best_idx + 1;
    }
    int maxFrequency(vector<int> &nums, int k)
    {
        // TC: O(NlogN)
        // SC: O(N)

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int result = 0;
        for (int target_idx = 0; target_idx < n; target_idx++)
        {
            int freq = bSearch(target_idx, k, prefix, nums);
            result = max(freq, result);
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 4, 8, 13};
    int k = 5;
    cout << "Frequency of the Most Frequent Element: " << s.maxFrequency(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/frequency-of-the-most-frequent-element

Youtube: https://www.youtube.com/watch?v=iOqH_JnXIOQ

algorithm:

*/