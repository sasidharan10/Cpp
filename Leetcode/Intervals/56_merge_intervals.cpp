#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        vector<int>temp = intervals[0];
        for (auto i :intervals)
        {
            if(temp[1] >= i[0])
            {
                temp[1]=max(temp[1], i[1]);
            }
            else
            {
                ans.push_back(temp);
                temp=i;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans=s.merge(v);
    cout << "Non-Overlapping pairs are : ";
    for (vector<int> vec : ans)
    {
        cout << "{ ";
        for (int i : vec)
        {
            cout << i << " ";
        }
        cout << "}, ";
    }
    return 0;
}

/*

link: 

leetcode: https://leetcode.com/problems/merge-intervals/description/

Youtube: 

algorithm: 

- Sort the intervals, by its starting value
- Let A = (x1, y1) and B = (x2, y2), then if (y1 > x2) then its overlapping.
- If over lapping then we update its prev_Y as => prev_Y = max(y1, y2);
- If not, we push that intervals into ans vector.

*/

/*

56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping 
intervals, and return an array of the non-overlapping intervals 
that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/