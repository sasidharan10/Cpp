#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // better - using set or map
    vector<int> findMissingAndRepeatedValues2(vector<vector<int>> &grid)
    {
        // TC: O(n^2)
        // SC: O(n^2)

        int n = grid.size();
        unordered_set<int> uset;
        int sum = 0;
        int num = n * n;
        int total = (num * (num + 1)) / 2;
        vector<int> res(2, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (uset.find(grid[i][j]) != uset.end())
                {
                    res[0] = grid[i][j];
                }
                else
                {
                    uset.insert(grid[i][j]);
                    sum += grid[i][j];
                }
            }
        }
        int missing = total - sum;
        res[1] = missing;
        return res;
    }

    // Optimal - using math equations
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = grid.size();
        long long gridSum = 0;
        long long gridSqrSum = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                gridSum += grid[i][j];
                gridSqrSum += grid[i][j] * grid[i][j];
            }
        }
        long long num = n * n;
        long long sum = (num * (num + 1)) / 2;
        long long sqrSum = (num * (num + 1) * (2 * num + 1)) / 6;

        long long sumDiff = sum - gridSum;
        long long sqrDiff = sqrSum - gridSqrSum;

        int a = (sqrDiff / sumDiff - sumDiff) / 2;
        int b = (sqrDiff / sumDiff + sumDiff) / 2;
        return {a, b};
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    vector<int> ans = s.findMissingAndRepeatedValues(nums);
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

leetcode: https://leetcode.com/problems/find-missing-and-repeated-values

Youtube: https://www.youtube.com/watch?v=9tUv0SfUyGg

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Mathematical/Leetcode%20Easy/Find%20Missing%20and%20Repeated%20Values.cpp

algorithm:

- Brute Force Approach:

- using map or set

- Optimal Approach:

- using math equations

*/

/*

2965. Find Missing and Repeated Values

You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer
appears exactly once except a which appears twice and b which is missing. The task is to find the repeating
and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

Example 1:

Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].

Example 2:

Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
Output: [9,5]
Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].

Constraints:

2 <= n == grid.length == grid[i].length <= 50
1 <= grid[i][j] <= n * n
For all x that 1 <= x <= n * n there is exactly one x that is not equal to any of the grid members.
For all x that 1 <= x <= n * n there is exactly one x that is equal to exactly two of the grid members.
For all x that 1 <= x <= n * n except two of them there is exatly one pair of i, j that 0 <= i, j <= n - 1
and grid[i][j] == x.

*/

/*
************* Java Code **************

    public static int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        long gridSum = 0;
        long gridSqrSum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                gridSum += grid[i][j];
                gridSqrSum += grid[i][j] * grid[i][j];
            }
        }
        long num = n * n;
        long sum = (num * (num + 1)) / 2;
        long sqrSum = (num * (num + 1) * (2 * num + 1)) / 6;

        long sumDiff = sum - gridSum;
        long sqrDiff = sqrSum - gridSqrSum;

        int a = (int) (sqrDiff / sumDiff - sumDiff) / 2;
        int b = (int) (sqrDiff / sumDiff + sumDiff) / 2;
        return new int[] { a, b };
    }

*/