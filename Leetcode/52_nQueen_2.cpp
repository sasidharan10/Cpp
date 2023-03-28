#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int solve(int col, vector<string> &board, vector<int> &leftRow, vector<int> &upperDiagonal,
              vector<int> &lowerDiagonal, int n)
    {
        if (col == n)
            return 1;
        int cnt = 0;
        for (int row = 0; row < n; row++)
        {
            if (leftRow[row] == 0 && upperDiagonal[row + col] == 0 && lowerDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[row + col] = 1;
                lowerDiagonal[n - 1 + col - row] = 1;
                cnt += solve(col + 1, board, leftRow, upperDiagonal, lowerDiagonal, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[row + col] = 0;
                lowerDiagonal[n - 1 + col - row] = 0;
            }
        }
        return cnt;
    }

    int totalNQueens(int n)
    {
        vector<string> board(n);
        string temp(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = temp;
        }
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        return solve(0, board, leftRow, upperDiagonal, lowerDiagonal, n);
    }
};
int main()
{
    Solution s;
    int n = 4;
    cout << "total boards: " << s.totalNQueens(n) << endl;
    return 0;
}