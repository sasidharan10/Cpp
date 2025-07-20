#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // TC: O(n)
        // SC: O(n)
        
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        for (vector<int> i : intervals)
        {
            if (temp[1] >= i[0])
            {
                temp[1] = max(temp[1], i[1]);
            }
            else
            {
                ans.push_back(temp);
                temp = i;
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
    vector<vector<int>> ans = s.merge(v);
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

Youtube: https://www.youtube.com/watch?v=44H3cEC2fFM

algorithm:

- Sort the intervals, by its starting value
- Let A = (x1, y1) and B = (x2, y2), then if (y1 > x2) then its overlapping.
- If over lapping then we update its prev_Y as => prev_Y = max(y1, y2);
- If not, we push that intervals into resultant vector.

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

/*   
************* Java Code **************

    public static int[][] merge(int[][] intervals) {
        List<int[]> res = new ArrayList<>();
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        int[] tempInterval = intervals[0];
        int n = intervals.length;
        for (int i = 1; i < n; i++) {
            if (tempInterval[1] >= intervals[i][0]) {
                tempInterval[1] = Math.max(tempInterval[1], intervals[i][1]);
            } else {
                res.add(tempInterval);
                tempInterval = intervals[i];
            }
        }
        res.add(tempInterval);
        return res.toArray(new int[res.size()][]);
    }

*/