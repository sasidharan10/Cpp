#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;
    bool dfs(int row, int col, int index, int len, vector<vector<char>> &board, string word)
    {
        if (index == len - 1)
            return true;
        char temp = board[row][col];
        board[row][col] = '$';
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, 1, 0, -1};
        bool res = false;
        for (int i = 0; i < 4; i++)
        {
            int newRow = dRow[i] + row;
            int newCol = dCol[i] + col;
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && board[newRow][newCol] != '$' && board[newRow][newCol] == word[index + 1])
            {
                res |= dfs(newRow, newCol, index + 1, len, board, word);
            }
        }
        board[row][col] = temp;
        return res;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        // TC: O(L)
        // SC: O(M * N * 3^L)

        n = board.size();
        m = board[0].size();
        int len = word.length();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bool res = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    res |= dfs(i, j, 0, len, board, word);
                }
                if (res)
                    return res;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << "Result: " << s.exist(board, word) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/word-search/

Youtube: https://www.youtube.com/watch?v=whyax_vB8xY

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Backtracking/Word%20Search.cpp

algorithm:

- We search for first character in the matrix, if we found it, then we apply dfs
  from that cell, and check if we are able to find the word in the matrix.
- While visiting a node, we mark it as visited, and when dfs is completed, we mark it
  as unvisited.

- Time complexity analysis:
- Space Complexity is because of recursion - to store function stack context.
- Time Complexity - from every block we go in three adjacent blocks (avoiding the direction we came from). 
- This walk can go for max of L times. So each thred at most goes L length long. -> O(3^L).
- Now this is applied at each node from main calling function -> O(M * N). Therefore, O(M * N * 3^L).

*/

/*

79. Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where 
adjacent cells are horizontally or vertically neighboring. The same letter cell 
may not be used more than once.

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

*/

/*
************* Java Code **************

public static int n, m;

    public static boolean dfs(int row, int col, int index, int len, char[][] board, String word) {
        if (index == len - 1)
            return true;
        char temp = board[row][col];
        board[row][col] = '$';
        int[] dRow = { -1, 0, 1, 0 };
        int[] dCol = { 0, 1, 0, -1 };
        boolean res = false;
        for (int i = 0; i < 4; i++) {
            int newRow = dRow[i] + row;
            int newCol = dCol[i] + col;
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && board[newRow][newCol] != '$'
                    && board[newRow][newCol] == word.charAt(index + 1)) {
                res |= dfs(newRow, newCol, index + 1, len, board, word);
            }
        }
        board[row][col] = temp;
        return res;
    }

    public static boolean exist(char[][] board, String word) {
        n = board.length;
        m = board[0].length;
        int len = word.length();
        boolean res = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word.charAt(0)) {
                    res |= dfs(i, j, 0, len, board, word);
                }
                if (res)
                    return res;
            }
        }
        return res;
    }

*/