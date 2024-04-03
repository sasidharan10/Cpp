#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(int row, int col, int index, int len, vector<vector<char>> &board, string word, vector<vector<int>> &vis)
    {
        cout << word[index] << ", ";
        int n = board.size();
        int m = board[0].size();
        if (index == len - 1)
            return true;
        vis[row][col] = 1;
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, 1, 0, -1};
        bool res = false;
        for (int i = 0; i < 4; i++)
        {
            int newRow = dRow[i] + row;
            int newCol = dCol[i] + col;
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && board[newRow][newCol] == word[index + 1])
            {
                res |= dfs(newRow, newCol, index + 1, len, board, word, vis);
            }
        }
        vis[row][col] = 0;
        return res;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        int len = word.length();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bool res = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    res |= dfs(i, j, 0, len, board, word, vis);
                    cout << endl;
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

leetcode:

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*






*/

/*
************* Java Code **************



*/