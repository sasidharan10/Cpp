#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Helper: sorts one diagonal (starting at (row,col))
    void sortDiagonal(int row, int col, vector<vector<int>> &grid, bool sortAscending)
    {
        int n = grid.size();
        int m = grid[0].size();

        int i = row, j = col;
        vector<int> arr;

        // Collect all elements along this diagonal
        while (i < n && j < m)
        {
            arr.push_back(grid[i][j]);
            i++;
            j++;
        }

        // Sort the diagonal either ascending or descending
        if (sortAscending)
            sort(arr.begin(), arr.end());
        else
            sort(arr.begin(), arr.end(), greater<>());

        // Put sorted values back into the diagonal
        i = row, j = col;
        for (int val : arr)
        {
            grid[i][j] = val;
            i++;
            j++;
        }
    }

    // Better
    vector<vector<int>> sortMatrix2(vector<vector<int>> &grid)
    {
        // TC: O(n^2 * log n)  (sorting each diagonal)
        // SC: O(n)            (temporary array for diagonal)

        int n = grid.size();
        int m = grid[0].size();

        // Sort diagonals starting from first row (ascending order)
        for (int col = 1; col < m; col++)
        {
            sortDiagonal(0, col, grid, true);
        }

        // Sort diagonals starting from first column (descending order)
        for (int row = 0; row < n; row++)
        {
            sortDiagonal(row, 0, grid, false);
        }

        return grid;
    }

    // Approach: group elements by diagonal (i - j is constant on each diagonal)
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<int, vector<int>> mp; // diag → elements

        // Step 1: Collect elements of each diagonal
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int diag = i - j; // same diag if i - j is equal
                mp[diag].push_back(grid[i][j]);
            }
        }

        // Step 2: Sort each diagonal
        for (auto &it : mp)
        {
            if (it.first >= 0) // diagonals starting from first column → ascending
                sort(it.second.begin(), it.second.end());
            else // diagonals starting from first row → descending
                sort(it.second.begin(), it.second.end(), greater<>());
        }

        // Step 3: Refill grid from sorted diagonals
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int diag = i - j;
                grid[i][j] = mp[diag].back(); // take from end
                mp[diag].pop_back();          // remove used element
            }
        }

        return grid;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> matrix{{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
    vector<vector<int>> ans = s.sortMatrix(matrix);
    cout << "Result: " << endl;
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

leetcode: https://leetcode.com/problems/sort-matrix-by-diagonals

Youtube: https://www.youtube.com/watch?v=Up445vSkzHQ

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/Sort%20Matrix%20by%20Diagonals.cpp

algorithm:

- Brute Force Approach:

- For diagonals starting at top row → sort in ascending order.
- For diagonals starting at first column → sort in descending order.
- Use helper function:
    - Extract diagonal into array.
    - Sort it.
    - Place elements back.
- Do this for all diagonals.

- Optimal Approach:

- Use property: all cells on same diagonal have constant i - j.
- Group elements by diagonal index i - j.
- Sort diagonals:
    - If i - j >= 0 → diagonal starts at first column → sort ascending.
    - If i - j < 0 → diagonal starts at first row → sort descending.
- Refill grid by placing back sorted diagonal elements.
- Use pop_back() to fill efficiently.

*/

/*

3446. Sort Matrix by Diagonals

You are given an n x n square matrix of integers grid. Return the matrix such that:
The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
The diagonals in the top-right triangle are sorted in non-decreasing order.

Example 1:

Input: grid = [[1,7,3],[9,8,2],[4,5,6]]

Output: [[8,2,3],[9,6,7],[4,5,1]]

Explanation:
The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:

[1, 8, 6] becomes [8, 6, 1].
[9, 5] and [4] remain unchanged.

The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:

[7, 2] becomes [2, 7].
[3] remains unchanged.

Example 2:

Input: grid = [[0,1],[1,2]]
Output: [[2,1],[1,0]]

Explanation:
The diagonals with a black arrow must be non-increasing, so [0, 2] is changed to [2, 0]. The other diagonals
are already in the correct order.

Example 3:

Input: grid = [[1]]
Output: [[1]]

Explanation:
Diagonals with exactly one element are already in order, so no changes are needed.

Constraints:

grid.length == grid[i].length == n
1 <= n <= 10
-10^5 <= grid[i][j] <= 10^5

*/

/*
************* Java Code **************

    public void sortDiagonal(int row, int col, int[][] grid, boolean sortAscending) {
        int n = grid.length;
        int m = grid[0].length;
        int i = row;
        int j = col;
        List<Integer> arr = new ArrayList<>();

        while (i < n && j < m) {
            arr.add(grid[i][j]);
            i++;
            j++;
        }

        if (sortAscending) {
            Collections.sort(arr);
        } else {
            Collections.sort(arr, Collections.reverseOrder());
        }

        i = row;
        j = col;
        for (int num : arr) {
            grid[i][j] = num;
            i++;
            j++;
        }
    }

    public int[][] sortMatrix(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        for (int col = 1; col < m; col++) {
            sortDiagonal(0, col, grid, true);
        }

        for (int row = 0; row < n; row++) {
            sortDiagonal(row, 0, grid, false);
        }

        return grid;
    }

    // Optimal:
    public int[][] sortMatrix(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        Map<Integer, List<Integer>> mp = new HashMap<>();

        // Collect all elements by their diagonal (i - j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int diag = i - j;
                mp.putIfAbsent(diag, new ArrayList<>());
                mp.get(diag).add(grid[i][j]);
            }
        }

        // Sort each diagonal
        for (Map.Entry<Integer, List<Integer>> entry : mp.entrySet()) {
            int diag = entry.getKey();
            List<Integer> list = entry.getValue();

            if (diag >= 0) {
                Collections.sort(list);
            } else {
                Collections.sort(list, Collections.reverseOrder());
            }
        }

        // Reconstruct the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int diag = i - j;
                List<Integer> list = mp.get(diag);
                grid[i][j] = list.get(list.size() - 1);
                list.remove(list.size() - 1);
            }
        }

        return grid;
    }

*/