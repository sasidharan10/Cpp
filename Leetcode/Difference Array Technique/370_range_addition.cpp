#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates)
    {
        // TC: O(n + length)
        // SC: O(length)

        int n = updates.size();
        vector<int> cumSum(length, 0);
        for (int i = 0; i < n; i++)
        {
            int start = updates[i][0];
            int end = updates[i][1];
            int inc = updates[i][2];
            cumSum[start] += inc;
            if (end + 1 < length)
                cumSum[end + 1] -= inc;
        }
        // finding the cummulative sum
        for (int i = 1; i < length; i++)
        {
            cumSum[i] += cumSum[i - 1];
        }
        return cumSum;
    }
};
int main()
{
    Solution s;
    int length = 5;
    vector<vector<int>> updates = {{1, 3, 2}, {2, 4, 3}, {0, 2, -2}};
    vector<int> ans = s.getModifiedArray(length, updates);
    cout << "Result: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.ca/2016-12-04-370-Range-Addition/

Youtube: https://www.youtube.com/watch?v=ZHNVmtm08WY

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Difference%20Array%20Technique/Range%20Addition.cpp

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

370. Range Addition

Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of
subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
Output: [-2,0,3,5,3]
Explanation:

Initial state:
[0,0,0,0,0]

After applying operation [1,3,2]:
[0,2,2,2,0]

After applying operation [2,4,3]:
[0,2,5,5,3]

After applying operation [0,2,-2]:
[-2,0,3,5,3]

*/

/*
************* Java Code **************

    public static int[] getModifiedArray(int length, int[][] updates) {
        // TC: O(n + length)
        // SC: O(length)

        int n = updates.length;
        int[] cumSum = new int[length];
        for (int i = 0; i < n; i++) {
            int start = updates[i][0];
            int end = updates[i][1];
            int inc = updates[i][2];
            cumSum[start] += inc;
            if (end + 1 < length)
                cumSum[end + 1] -= inc;
        }
        // finding the cummulative sum
        for (int i = 1; i < length; i++) {
            cumSum[i] += cumSum[i - 1];
        }
        return cumSum;
    }

*/