#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)

        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                    count++;
            }
        }
        return count;
    }
    int numIdenticalPairs2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        unordered_map<int, int> map;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            map[nums[i]]++;
        }
        for (auto &&i : map)
        {
            int temp = i.second;
            if (temp > 1)
            {
                int sum = (temp * (temp - 1)) / 2;
                count += sum;
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 1, 1, 3};
    // vector<int> nums{1, 1, 1, 1};
    cout << "No of Good Pairs: " << s.numIdenticalPairs2(nums);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/number-of-good-pairs/submissions

Youtube:

algorithm:

- use nCr formula
- here we know we have to find the combinations of 2, hence simplifying nCr formula,
  we get n(n*1)/2, which is same as sum 1....n.

*/