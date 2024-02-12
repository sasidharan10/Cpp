#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        // TC: O(2n)
        // SC: O(n)

        int element = 0, mostFreq = 0, n = nums.size(), cnt = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                mp[nums[i]]++;
                if (mp[nums[i]] == mostFreq)
                {
                    element = min(element, nums[i]);
                }
                else if (mp[nums[i]] > mostFreq)
                {
                    element = nums[i];
                    mostFreq = mp[nums[i]];
                }
            }
        }
        if (mostFreq == 0)
            return -1;
        else
            return element;
    }
};
int main()
{
    Solution s;
    vector<int> nums{4, 4, 4, 9, 2, 4};
    cout << "Majority Even Element : " << s.mostFrequentEven(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/most-frequent-even-element/

Youtube:

algorithm:

*/