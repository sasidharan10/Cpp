#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // TC: O(KlogN)
        // SC: O(n)

        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        vector<int> ans;
        for (auto &&it : mp)
        {
            pq.push({it.second, it.first});
        }
        while (k > 0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> ans = s.topKFrequent(nums, k);
    cout << "Top K elements: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/top-k-frequent-elements/description/

Youtube: https://www.youtube.com/watch?v=Wh3A29psE_Y

algorithm:

*/