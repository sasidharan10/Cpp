#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    // Better - Using 2 prefix sum for both rows.
    long long gridGame2(vector<vector<int>>& grid)
    {
        // TC: O(n)
        // SC: O(n) + O(n)
        
        int col = grid[0].size();
        vector<long long>prefix1(grid[0].begin(), grid[0].end());
        vector<long long>prefix2(grid[1].begin(), grid[1].end());
        for (int i = 1; i < col; i++)
        {
            prefix1[i] += prefix1[ i  - 1];
            prefix2[i] += prefix2[ i  - 1];
        }
        long long minRobot2Sum = LONG_LONG_MAX;
        for (int i = 0; i < col; i++)
        {
            long long topRemainingSumForRobot2 = prefix1[col - 1] - prefix1[i];  // prefix1[col - 1] gives sum of the whole array.
            long long bottomRemaningSumForRobot2 = (i == 0) ? 0 : prefix2[ i - 1];
            long long maxSumForRobot2 = max(topRemainingSumForRobot2, bottomRemaningSumForRobot2);
            minRobot2Sum = min(minRobot2Sum, maxSumForRobot2);
        }
        return minRobot2Sum;
    }

    // Optimal - Using only 1 prefix sum array.
    long long gridGame(vector<vector<int>>& grid)
    {
        // TC: O(n)
        // SC: O(n) + O(n)
        
        int col = grid[0].size();
        vector<long long>prefix(grid[0].begin(), grid[0].end());
        for (int i = 1; i < col; i++)
        {
            prefix[i] += prefix[ i  - 1];
        }
        long long minRobot2Sum = LONG_LONG_MAX;
        long long bottomRemaningSumForRobot2 = 0;
        for (int i = 0; i < col; i++)
        {
            // prefix1[col - 1] gives sum of the whole array.
            long long topRemainingSumForRobot2 = prefix[col - 1] - prefix[i];  
            long long maxSumForRobot2 = max(topRemainingSumForRobot2, bottomRemaningSumForRobot2);
            bottomRemaningSumForRobot2 += grid[1][i];
            minRobot2Sum = min(minRobot2Sum, maxSumForRobot2);
        }
        return minRobot2Sum;
    }
};
int main()
{
    Solution s;
    // vector<vector<int>> grid{{1,3,1,15},{1,3,3,1}};
    vector<vector<int>> grid{{2,5,4},{1,5,1}};
    cout << "Result: " <<s.gridGame(grid)<< endl;
    return 0;
}

/*

link: 

leetcode: https://leetcode.com/problems/grid-game

Youtube: https://www.youtube.com/watch?v=Y8VC_OnkazE

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Cumulative_Sum(Prefix%20Array)/Grid%20Game.cpp

algorithm: 

- Optimal Approach:

- The concept here is, the first robot wants to minimize the path sum for the second robot. Hence, finding the
  maximum path sum for robot1 wont ensure, the second robot will have the minimum possible path sum. refer below.
- [[ 5, 12, 14 ],
  [  20, 7, 17 ]] try this.
- Maximizing will take a path of 5, 20, 7, 17 => 49. which means max path sum for robot2 = 0, 12, 14, 0 => 26.
- But the correct path is        5, 12, 7, 17 => 41. which means max path sum for robot2 = 0, 20,  0, 0 => 20.

- Note: Once Robot1 goes to row2, it cannot go up.
- hence, we just traverse the grid, in each column, and find the remaining sum for the robot2.
- let's say the robot1 goes to bottom row at ith column. Then the remaining sum for the robot2 will be either
  the sum of all elements in top row, from i+1 to n, or the sum of all elements in bottom row, from 0 to i-1.
- Hence we use a prefix array to calculate this.

*/

/*

2017. Grid Game

You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at 
position (r, c) on the matrix. Two robots are playing a game on this matrix.

Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the 
right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).

At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the 
cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. Then, the second 
robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect 
with one another.

The first robot wants to minimize the number of points collected by the second robot. In contrast, the 
second robot wants to maximize the number of points it collects. If both robots play optimally, return the 
number of points collected by the second robot.

Example 1:

Input: grid = [[2,5,4],[1,5,1]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the 
second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 0 + 4 + 0 = 4 points.

Example 2:

Input: grid = [[3,3,1],[8,5,2]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the 
second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 3 + 1 + 0 = 4 points.

Example 3:

Input: grid = [[1,3,1,15],[1,3,3,1]]
Output: 7
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the 
second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 1 + 3 + 3 + 0 = 7 points.
 
Constraints:

grid.length == 2
n == grid[r].length
1 <= n <= 5 * 10^4
1 <= grid[r][c] <= 10^5

*/

/*   
************* Java Code **************



*/