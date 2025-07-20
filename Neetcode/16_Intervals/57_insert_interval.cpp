#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute Force
    vector<vector<int>> insert2(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int i = 0;

        while (i < intervals.size())
        {
            if (intervals[i][1] < newInterval[0])
                i++;
            else if (intervals[i][0] > newInterval[1])
            {
                intervals.insert(intervals.begin() + i, newInterval);
                return intervals;
            }
            else
            {
                // Overlap : merge them
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                intervals.erase(intervals.begin() + i);
            }
        }

        intervals.push_back(newInterval);
        return intervals;
    }

    // Optimal
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        // TC: O(n)
        // SC: O(n)

        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;
        while (i < n)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (intervals[i][1] < newInterval[0])
                ans.push_back(intervals[i]);
            else if (newInterval[1] < intervals[i][0])
                break;
            else
            {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        ans.push_back(newInterval);
        while (i < n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> intervals{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval{4, 8};
    vector<vector<int>> ans = s.insert(intervals, newInterval);
    cout << "Array after inserting interval: " << endl;
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

leetcode: https://leetcode.com/problems/insert-interval/

Youtube: https://www.youtube.com/watch?v=XXaVIDIbUn4

algorithm:

Code Link:

- Approach:

-

*/

/*

57. Insert Interval

You are given an array of non-overlapping intervals intervals where
intervals[i] = [starti, endi] represent the start and the end of the ith
interval and intervals is sorted in ascending order by starti. You are also
given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in
ascending order by starti and intervals still does not have any overlapping
intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

*/

/*
************* Java Code **************

    public int[][] insert(int[][] intervals, int[] newInterval) {
        int i = 0;

        while (i < intervals.length) {
            if (intervals[i][1] < newInterval[0])
                i++;
            else if (intervals[i][0] > newInterval[1]) {
                List<int[]> result = new ArrayList<>();
                for (int j = 0; j < i; j++) {
                    result.add(intervals[j]);
                }
                result.add(newInterval);
                for (int j = i; j < intervals.length; j++) {
                    result.add(intervals[j]);
                }
                return result.toArray(new int[result.size()][]);
            } else {
                // Overlap: merge them
                newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
                newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
                List<int[]> tempList = new ArrayList<>();
                for (int j = 0; j < intervals.length; j++) {
                    if (j != i) {
                        tempList.add(intervals[j]);
                    }
                }
                intervals = tempList.toArray(new int[tempList.size()][]);
            }
        }

        List<int[]> result = new ArrayList<>();
        for (int[] interval : intervals) {
            result.add(interval);
        }
        result.add(newInterval);
        return result.toArray(new int[result.size()][]);
    }

    public static int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length;
        ArrayList<int[]> ans = new ArrayList<>();
        int i = 0;
        while (i < n) {
            if (intervals[i][1] < newInterval[0]) {
                ans.add(intervals[i]);
            } else if (newInterval[1] < intervals[i][0])
                break;
            else {
                newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
                newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        ans.add(newInterval);
        while (i < n) {
            ans.add(intervals[i]);
            i++;
        }
        return ans.toArray(new int[ans.size()][]);
    }

*/