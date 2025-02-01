#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // optimal approach: using row, column aray to keep the count of servers in that row, column.
    int countServers(vector<vector<int>> &grid)
    {
        // TC: O(n*m) * 2
        // SC: O(n) + O(m)
        
        int n = grid.size();
        int m = grid[0].size();

        vector<int> rowOnes(n, 0);
        vector<int> colOnes(m, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    rowOnes[i]++;
                    colOnes[j]++;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && (rowOnes[i] > 1 || colOnes[j] > 1))
                    cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums{{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    cout << "Result: " << s.countServers(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-servers-that-communicate/

Youtube:

algorithm:

- Brute Force Approach:

- check if (grid[i][j] == 1) and traverse its row and column, and find if
  we find any extra 1's, if yes, then increase the cnt.

- Optimal Approach:

- We traverse the matrix and keep the count of 1's in each row and column.
- Again we traverse the matrix, and check if (grid[i][j] == 1), then check
  if (rowOnes[i] > 1 || colOnes[j] > 1), if yes, increase the cnt.

*/

/*

1267. Count Servers that Communicate

You are given a map of a server center, represented as a m * n integer
matrix grid, where 1 means that on that cell there is a server and 0
means that it is no server. Two servers are said to communicate if
they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.

Example 2:

Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.

Example 3:

Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other.
The two servers in the third column can communicate with each other. The
server at right bottom corner can't communicate with any other server.

*/

/*   
************* Java Code **************

public static int countServers(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[] rowOnes = new int[n];
        int[] colOnes = new int[m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    rowOnes[i]++;
                    colOnes[j]++;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && (rowOnes[i] > 1 || colOnes[j] > 1))
                    cnt++;
            }
        }
        return cnt;
    }

*/