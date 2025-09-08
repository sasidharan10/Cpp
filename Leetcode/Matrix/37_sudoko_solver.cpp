#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to check if placing 'ch' at (row, col) is valid
    bool isValid(int row, int col, char ch, vector<vector<char>> &board)
    {
        // Check the column
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == ch) // if digit already in column
                return false;
        }

        // Check the row
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == ch) // if digit already in row
                return false;
        }

        // Find top-left corner of 3x3 subgrid
        int start_i = (row / 3) * 3;
        int start_j = (col / 3) * 3;

        // Check inside the 3x3 subgrid
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[start_i + i][start_j + j] == ch) // if digit already in box
                    return false;
            }
        }
        return true; // valid placement
    }

    // Recursive function to solve Sudoku using backtracking
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.') // skip already filled cells
                    continue;

                // Try filling numbers 1-9
                for (int d = 1; d <= 9; d++)
                {
                    char ch = '0' + d; // convert int to char
                    if (isValid(i, j, ch, board))
                    {
                        board[i][j] = ch; // place digit

                        // Recurse for the next cell
                        if (solve(board))
                            return true;

                        // Backtrack if placing 'ch' didn't work
                        board[i][j] = '.';
                    }
                }

                // If no number can be placed here, return false
                return false;
            }
        }
        // If all cells filled correctly
        return true;
    }

    // Wrapper function
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};
int main()
{
    Solution s;
    vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    s.solveSudoku(board);
    cout << "Result: " << endl;
    for (auto i : board)
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

leetcode: https://leetcode.com/problems/sudoku-solver/

Youtube: https://www.youtube.com/watch?v=5g6fheUtjRs

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Backtracking/Sudoku%20Solver.cpp

algorithm:

- Optimal Approach:

- Use backtracking to try placing digits in empty cells.
- At each empty cell, try numbers 1–9.
- Check if the number is valid in its row, column, and 3×3 box.
- If valid, place the number and continue solving recursively.
- If recursion fails, undo the placement (backtrack) and try the next number.
- If no number fits, return false to trigger backtracking.
- Base case: if the entire board is filled correctly, return true.
- The box check formula (row/3)*3, (col/3)*3 finds the top-left corner of the 3×3 grid containing the cell.
- how to find starting index of a 3 x 3 box in a board?
    - Each 3×3 subgrid can be indexed by (row / 3, col / 3).
    - row / 3 gives which block vertically (0, 1, 2).
    - col / 3 gives which block horizontally (0, 1, 2).
    - Multiply by 3 → starting index of that 3×3 block.
    - Example: Cell (5, 7) → (5/3, 7/3) = (1, 2) → box starting at (3, 6).
- Time complexity worst case exponential, but works efficiently due to pruning.
- Space complexity O(1) extra, as board is modified in place.

*/

/*

37. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],
                ["6",".",".","1","9","5",".",".","."],
                [".","9","8",".",".",".",".","6","."],
                ["8",".",".",".","6",".",".",".","3"],
                ["4",".",".","8",".","3",".",".","1"],
                ["7",".",".",".","2",".",".",".","6"],
                [".","6",".",".",".",".","2","8","."],
                [".",".",".","4","1","9",".",".","5"],
                [".",".",".",".","8",".",".","7","9"]   ]

Output:     [   ["5","3","4","6","7","8","9","1","2"],
                ["6","7","2","1","9","5","3","4","8"],
                ["1","9","8","3","4","2","5","6","7"],
                ["8","5","9","7","6","1","4","2","3"],
                ["4","2","6","8","5","3","7","9","1"],
                ["7","1","3","9","2","4","8","5","6"],
                ["9","6","1","5","3","7","2","8","4"],
                ["2","8","7","4","1","9","6","3","5"],
                ["3","4","5","2","8","6","1","7","9"]   ]

Explanation: The input board is shown above and the only valid solution is shown below:

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.

*/

/*
************* Java Code **************

public void solveSudoku(char[][] board) {
        solve(board);
    }
    
    private boolean solve(char[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    continue;
                }
                
                for (int d = 1; d <= 9; d++) {
                    char ch = (char)('0' + d);
                    if (isValid(i, j, ch, board)) {
                        board[i][j] = ch;
                        if (solve(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    
    private boolean isValid(int row, int col, char ch, char[][] board) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch) {
                return false;
            }
            if (board[row][i] == ch) {
                return false;
            }
        }
        
        int start_i = row / 3 * 3;
        int start_j = col / 3 * 3;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + start_i][j + start_j] == ch) {
                    return false;
                }
            }
        }
        return true;
    }

*/