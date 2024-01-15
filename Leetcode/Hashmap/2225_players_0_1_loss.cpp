#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        // TC: O(n) + O(klogk) + O(mlogm) 
        // SC: O(n)
        
        int n = matches.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int winner = matches[i][0];
            int loser = matches[i][1];

            mp[loser]++;
            if (!mp[winner])
            {
                mp[winner] = 0;
            }
        }
        vector<vector<int>> ans{{}, {}};
        for (auto &&it : mp)
        {
            if (it.second == 0)
                ans[0].push_back(it.first);
            else if (it.second == 1)
                ans[1].push_back(it.first);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
    vector<vector<int>> ans = s.findWinners(nums);
    cout << "Players with 0 and 1 Loss: " << endl;
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

leetcode: https://leetcode.com/problems/find-players-with-zero-or-one-losses

Youtube:

algorithm:

*/

/*

2225. Find Players With Zero or One Losses

You are given an integer array matches where matches[i] = [winneri, loseri]
indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.

Example 1:

Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
Output: [[1,2,10],[4,5,7,8]]
Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].

Example 2:

Input: matches = [[2,3],[1,3],[5,4],[6,4]]
Output: [[1,2,5,6],[]]
Explanation:
Players 1, 2, 5, and 6 have not lost any matches.
Players 3 and 4 each have lost two matches.
Thus, answer[0] = [1,2,5,6] and answer[1] = [].

*/