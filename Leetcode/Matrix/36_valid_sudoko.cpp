#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Vertical check: ensures no duplicate in any column
    bool verticalCheck(vector<vector<char>> &board)
    {
        int n = board.size();
        for (int col = 0; col < n; col++)
        {
            unordered_set<char> uset; // track digits in current column
            for (int row = 0; row < n; row++)
            {
                if (board[row][col] == '.') // skip empty cells
                    continue;
                if (uset.count(board[row][col]) > 0) // duplicate found
                    return false;
                uset.insert(board[row][col]);
            }
        }
        return true;
    }

    // Horizontal check: ensures no duplicate in any row
    bool horizontalCheck(vector<vector<char>> &board)
    {
        int n = board.size();
        for (int row = 0; row < n; row++)
        {
            unordered_set<char> uset; // track digits in current row
            for (int col = 0; col < n; col++)
            {
                if (board[row][col] == '.')
                    continue;
                if (uset.count(board[row][col]) > 0) // duplicate found
                    return false;
                uset.insert(board[row][col]);
            }
        }
        return true;
    }

    // Box check: ensures no duplicate in any 3x3 subgrid
    bool boxCheck(vector<vector<char>> &board)
    {
        int n = board.size();
        for (int row = 0; row < n; row += 3) // each box starts at (row, col) multiple of 3
        {
            for (int col = 0; col < n; col += 3)
            {
                unordered_set<char> uset;
                // iterate over the 3x3 block
                for (int i = row; i < row + 3; i++)
                {
                    for (int j = col; j < col + 3; j++)
                    {
                        if (board[i][j] == '.')
                            continue;
                        if (uset.count(board[i][j]) > 0) // duplicate in subgrid
                            return false;
                        uset.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }

    // Main function: combine all 3 checks
    bool isValidSudoku2(vector<vector<char>> &board)
    {
        // TC: O(n*n) → we check each cell in rows, columns, and boxes
        // SC: O(n*n) → sets store up to 9 values per row/col/box
        return verticalCheck(board) && horizontalCheck(board) && boxCheck(board);
    }

    // Optimal approach: Do row, column, and box checks in ONE pass
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // TC: O(n*n) → visit each cell once
        // SC: O(n*n) → store constraints in set

        int n = board.size();
        unordered_set<string> uset; // stores uniqueness keys
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.') // skip empty cell
                    continue;

                // Create unique strings for row, column, and 3x3 box
                string row = string(1, board[i][j]) + "_row_" + to_string(i);
                string col = string(1, board[i][j]) + "_col_" + to_string(j);
                string box = string(1, board[i][j]) + "_box_" + to_string(i / 3) + to_string(j / 3);

                // If any duplicate found → invalid
                if (uset.count(row) > 0 || uset.count(col) > 0 || uset.count(box) > 0)
                    return false;

                // Insert keys to track constraints
                uset.insert(row);
                uset.insert(col);
                uset.insert(box);
            }
        }
        return true;
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
    cout << "Result: " << s.isValidSudoku(board) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/valid-sudoku

Youtube: https://www.youtube.com/watch?v=dGZjzA9zLW8

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/2-D%20Array/Valid%20Sudoku.cpp

algorithm:

- Brute Force Approach:

- Sudoku is valid if every row, column, and 3×3 box has no duplicate digits (ignoring '.').
- Use a hash set to track seen digits in each row/col/box.
- Row check → iterate row-wise and verify uniqueness.
- Column check → iterate column-wise and verify uniqueness.
- Box check → for each 3×3 subgrid, check duplicates.
- If all 3 checks pass → return true.
- Time complexity: O(9×9) = O(81) (constant, since board is always 9×9).
- Space complexity: O(9×9) for sets (but practically O(1) since size is fixed).

- Optimal Approach:

- Instead of running 3 separate checks, this does all checks in one loop.
- For each cell (i, j) with value digit:
    - Make a row key: digit_row_i
    - Make a col key: digit_col_j
    - Make a box key: digit_box_(i/3)(j/3) → (i/3, j/3) identifies which 3×3 subgrid.
- Use an unordered_set to store keys.
- If a key already exists → means duplicate in row/col/box → invalid.
- Otherwise, insert all 3 keys into the set.

*/

/*

36. Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according 
to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 
Example 1:

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]

Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]

Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there 
are two 8's in the top left 3x3 sub-box, it is invalid.
 
Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.

*/

/*
************* Java Code **************

    public boolean isValidSudoku(char[][] board) {
        int n = board.length;
        Set<String> seen = new HashSet<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                String row = board[i][j] + "_row_" + i;
                String col = board[i][j] + "_col_" + j;
                String box = board[i][j] + "_box_" + (i / 3) + (j / 3);

                if (seen.contains(row) || seen.contains(col) || seen.contains(box)) {
                    return false;
                }

                seen.add(row);
                seen.add(col);
                seen.add(box);
            }
        }
        return true;
    }

*/