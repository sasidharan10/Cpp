#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool isSafe(int row, int col, vector<string> &board, int n)
{
    // queen can go in 8 directions, since we are going from left to right there will not be any queens in the
    // right side of the spot where th contol is or col is,and as there would be only 1 queen in a
    // column,therefore top and bootom is also not needed. So we only need to check 3 sides on left;

    int dumRow = row;
    int dumCol = col;
    // left upper cross
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }
    row = dumRow;
    col = dumCol;
    // left
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }
    row = dumRow;
    col = dumCol;
    // left down cross
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}
void solve(int col, int n, vector<string> &board)
{
    if (col == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, n, board);
            board[row][col] = '.';
        }
    }
}
void solve2(int col, int n, vector<string> &board, vector<int> &leftRow, vector<int> &leftUp,
            vector<int> &leftDown)
{
    if (col == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && leftUp[row + col] == 0 && leftDown[(n - 1) + (col - row)] == 0)
        {
            board[row][col] = 'Q'; // marking queen
            leftRow[row] = 1;      // marking row as it has queen now
            leftUp[row + col] = 1;
            leftDown[(n - 1) + (col - row)] = 1;
            solve2(col + 1, n, board, leftRow, leftUp, leftDown);
            board[row][col] = '.';
            leftRow[row] = 0;
            leftUp[row + col] = 0;
            leftDown[(n - 1) + (col - row)] = 0;
        }
    }
    return;
}
void nQueen(int n)
{
    vector<string> board(n);
    string temp(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = temp;
    }

    // solve(0, n, board);

    // optimised technique

    vector<int> leftRow(n, 0), leftUp(2 * n - 1, 0), leftDown(2 * n - 1, 0);
    solve2(0, n, board, leftRow, leftUp, leftDown);
}

int main()
{
    int n = 4;
    nQueen(n);
    return 0;
}