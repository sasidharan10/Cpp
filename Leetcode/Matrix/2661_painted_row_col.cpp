#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkCol(int rowSize, int col, vector<vector<int>> &mat)
    {
        for (int i = 0; i < rowSize; i++)
        {
            if (mat[i][col] > 0)
                return false;
        }
        return true;
    }
    bool checkRow(int colSize, int row, vector<vector<int>> &mat)
    {
        for (int i = 0; i < colSize; i++)
        {
            if (mat[row][i] > 0)
                return false;
        }
        return true;
    }

    // Brute force - gives TLE - after painting each cell, check if row, col is filled.
    int firstCompleteIndex3(vector<int> &arr, vector<vector<int>> &mat)
    {
        // TC: O(row * col) + n * O(row + col)
        // SC: O(row * col)

        int n = arr.size();
        int row = mat.size();
        int col = mat[0].size();
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int elm = mat[i][j];
                mp[elm] = {i, j};
            }
        }

        for (int i = 0; i < n; i++)
        {
            int elm = arr[i];
            int curRow = mp[elm].first;
            int curCol = mp[elm].second;
            mat[curRow][curCol] = -mat[curRow][curCol];
            if (checkRow(col, curRow, mat) || checkCol(row, curCol, mat))
                return i;
        }
        return -1;
    }

    // better approach - Using row and col array to track the filled rows, columns
    int firstCompleteIndex2(vector<int> &arr, vector<vector<int>> &mat)
    {
        // TC: O(row * col) + n * O(row + col)
        // SC: O(row * col) + O(row) + O(col)

        int n = arr.size();
        int row = mat.size();
        int col = mat[0].size();
        vector<int> rowCount(row, 0);
        vector<int> colCount(col, 0);
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int elm = mat[i][j];
                mp[elm] = {i, j};
            }
        }

        for (int i = 0; i < n; i++)
        {
            int elm = arr[i];
            int curRow = mp[elm].first;
            int curCol = mp[elm].second;
            if (rowCount[curRow] + 1 == col || colCount[curCol] + 1 == row)
                return i;
            rowCount[curRow]++;
            colCount[curCol]++;
        }
        return -1;
    }

    // Optimal approach - finding the max index, of each row, col at which the row, col will be painted
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        // TC: O(row * col) + n * O(row + col)
        // SC: 2 * O(row * col) + O(row) + O(col)

        int n = arr.size();
        int row = mat.size();
        int col = mat[0].size();
        int minIndex = INT_MAX;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]] = i;
        }

        // traversing each row
        for (int r = 0; r < row; r++)
        {
            int curMaxIdx = 0;
            for (int c = 0; c < col; c++)
            {
                int elm = mat[r][c];
                int idx = mp[elm];
                curMaxIdx = max(curMaxIdx, idx);
            }
            minIndex = min(minIndex, curMaxIdx);
        }
        // traversing each column
        for (int c = 0; c < col; c++)
        {
            int curMaxIdx = 0;
            for (int r = 0; r < row; r++)
            {
                int elm = mat[r][c];
                int idx = mp[elm];
                curMaxIdx = max(curMaxIdx, idx);
            }
            minIndex = min(minIndex, curMaxIdx);
        }
        return minIndex;
    }
};
int main()
{
    Solution s;
    vector<int> arr{2, 8, 7, 4, 1, 3, 5, 6, 9};
    vector<vector<int>> mat{{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
    // vector<int> arr{1, 4, 5, 2, 6, 3};
    // vector<vector<int>> mat{{4, 3, 5}, {1, 2, 6}};
    cout << "Result: " << s.firstCompleteIndex(arr, mat) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/first-completely-painted-row-or-column

Youtube: https://www.youtube.com/watch?v=nqmR3aDwjwU

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/First%20Completely%20Painted%20Row%20or%20Column.cpp

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

2661. First Completely Painted Row or Column

You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the
integers in the range [1, m * n].
Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
Return the smallest index i at which either a row or a column will be completely painted in mat.

Example 1:

image explanation for example 1
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become
fully painted at arr[2].

Example 2:

image explanation for example 2
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].

Constraints:

m == mat.length
n = mat[i].length
arr.length == m * n
1 <= m, n <= 10^5
1 <= m * n <= 10^5
1 <= arr[i], mat[r][c] <= m * n
All the integers of arr are unique.
All the integers of mat are unique.

*/

/*
************* Java Code **************

    public static class Pair {
        private int first;
        private int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static int firstCompleteIndex(int[] arr, int[][] mat) {
        int n = arr.length;
        int row = mat.length;
        int col = mat[0].length;
        int[] rowCount = new int[row];
        int[] colCount = new int[col];
        HashMap<Integer, Pair> mp = new HashMap<>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int elm = mat[i][j];
                mp.put(elm, new Pair(i, j));
            }
        }

        for (int i = 0; i < n; i++) {
            int elm = arr[i];
            int curRow = mp.get(elm).first;
            int curCol = mp.get(elm).second;
            if (rowCount[curRow] + 1 == col || colCount[curCol] + 1 == row)
                return i;
            rowCount[curRow]++;
            colCount[curCol]++;
        }
        return -1;
    }

*/