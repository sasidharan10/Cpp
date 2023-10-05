#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        // TC: O(2n)
        // SC: O(n)
        
        int el = 0, mostFreq = 0, n = nums.size(), cnt = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                map[nums[i]]++;
                mostFreq = max(mostFreq, map[nums[i]]);
            }
        }
        if (mostFreq == 0)
            return -1;
        int res = INT_MAX;
        for (auto &&i : map)
        {
            if (i.second == mostFreq && i.first < res)
            {
                res = i.first;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{4, 4, 4, 9, 2, 4};
    cout << "Majority element : " << s.mostFrequentEven(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/most-frequent-even-element/

Youtube:

algorithm:

*/