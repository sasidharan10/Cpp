#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        // TC: O(n*m)
        // SC: O(n+m)

        int n = maze.size();
        int m = maze[0].size();

        int entRow = entrance[0];
        int entCol = entrance[1];

        int dRow[]{-1, 0, 1, 0};
        int dCol[]{0, 1, 0, -1};

        int dist = 0;
        queue<pair<int, int>> q;
        q.push({entRow, entCol});
        maze[entRow][entCol] = '+';
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if ((i != entRow || j != entCol) && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
                    return dist;

                for (int k = 0; k < 4; k++)
                {
                    int newRow = i + dRow[k];
                    int newCol = j + dCol[k];
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && maze[newRow][newCol] != '+')
                    {
                        q.push({newRow, newCol});
                        maze[newRow][newCol] = '+';
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> maze{{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    vector<int> entrance{1, 2};
    cout << "Min steps to nearest Exit from Entrance in Maze: ";
    cout << s.nearestExit(maze, entrance) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

Youtube: https://www.youtube.com/watch?v=Q4bqto_yG6I

algorithm:

- BFS traversal
*/

/*

1926. Nearest Exit from Entrance in Maze

You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.')
and walls (represented as '+'). You are also given the entrance of the maze,
where entrance = [entrancerow, entrancecol] denotes the row and column of the
cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step
into a cell with a wall, and you cannot step outside the maze. Your goal is
to find the nearest exit from the entrance. An exit is defined as an empty
cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the
nearest exit, or -1 if no such path exists.

Example 1:

Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
Output: 1
Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.
Example 2:


Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
Output: 2
Explanation: There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.
Example 3:


Input: maze = [[".","+"]], entrance = [0,0]
Output: -1
Explanation: There are no exits in this maze.

*/