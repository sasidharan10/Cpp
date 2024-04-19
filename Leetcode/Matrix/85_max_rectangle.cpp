#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getNSR(vector<int> &height)
    {
        int n = height.size();
        vector<int> NSR(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && height[st.top()] >= height[i])
            {
                st.pop();
            }
            if (st.empty())
                NSR[i] = n;
            else
                NSR[i] = st.top();
            st.push(i);
        }
        return NSR;
    }
    vector<int> getNSL(vector<int> &height)
    {
        int n = height.size();
        vector<int> NSL(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && height[st.top()] >= height[i])
            {
                st.pop();
            }
            if (st.empty())
                NSL[i] = -1;
            else
                NSL[i] = st.top();
            st.push(i);
        }
        return NSL;
    }
    int findMaxArea(vector<int> &height)
    {
        int n = height.size();
        int maxArea = 0;
        vector<int> NSL = getNSL(height);
        vector<int> NSR = getNSR(height);

        vector<int> width(n);
        for (int i = 0; i < n; i++)
        {
            width[i] = NSR[i] - NSL[i] - 1;
        }

        for (int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, width[i] * height[i]);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (matrix[0][j] == '1')
                height[j] = 1;
        }
        int maxArea = 0;
        maxArea = findMaxArea(height);
        for (int row = 1; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (matrix[row][col] == '0')
                    height[col] = 0;
                else
                    height[col] += 1;
            }
            maxArea = max(maxArea, findMaxArea(height));
        }
        return maxArea;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> grid{{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << "Result: " << s.maximalRectangle(grid) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

Code Link:

algorithm:

-

*/

/*

85. Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle
containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = [["0"]]
Output: 0

Example 3:

Input: matrix = [["1"]]
Output: 1

*/

/*
************* Java Code **************



*/