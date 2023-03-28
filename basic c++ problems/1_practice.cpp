#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
bool isSafe(int row, int col, vector<string> board, int n)
{
    int duprow = row;
    int dupcol = col;

    // upper left
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    // left
    row = duprow;
    col = dupcol;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    // left down
    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
        row++;
    }
}
void solveNqueen(int col, vector<string> &board, int n)
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
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solveNqueen(col + 1, board, n);
            board[row][col] = '_';
        }
    }
}

// optimised method:

void solveNqueen2(int col, vector<string> &board, int n, vector<int> &leftRow, vector<int> &Upperleft, vector<int> &lowerLeft)
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
        if (leftRow[row] == 0 && Upperleft[row + col] == 0 && lowerLeft[n - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            Upperleft[row + col] = 1;
            lowerLeft[n - 1 + col - row] = 1;
            solveNqueen2(col + 1, board, n, leftRow, Upperleft, lowerLeft);
            board[row][col] = '_';
            leftRow[row] = 0;
            Upperleft[row + col] = 0;
            lowerLeft[n - 1 + col - row]=0;
        }
    }
}

void nQueen(int n)
{
    vector<string> board(n);
    string temp(n, '_');
    for (int i = 0; i < n; i++)
    {
        board[i] = temp;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<board[i]<<endl;
    // }

    // solveNqueen(0, board, n);
    vector<int> leftRow(n, 0), upperLeft(2 * n - 1, 0), lowerLeft(2 * n - 1, 0);
    solveNqueen2(0, board, n, leftRow, upperLeft, lowerLeft);
}
int main()
{
    int n = 4;
    nQueen(n);
    return 0;
}