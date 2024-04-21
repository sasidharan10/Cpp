#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getNSR(vector<int> &height)
    {
        // TC: O(2n)
        // SC: O(n)
        
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
        // TC: O(2n)
        // SC: O(n)

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
        // TC: O(n * (2m + 2m)) ~ O(n * m)
        // SC: O(3m) ~ O(m)

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
    cout << "Area of Maximal Rectangle: " << s.maximalRectangle(grid) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximal-rectangle/

Youtube: https://www.youtube.com/watch?v=sH5yj83ta_Y

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Stack/Maximal%20Rectangle.cpp

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

public static int[] getNSR(int[] height) {
        // TC: O(2n)
        // SC: O(n)

        int n = height.length;
        int[] NSR = new int[n];
        Stack<Integer> st = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && height[st.peek()] >= height[i]) {
                st.pop();
            }
            if (st.isEmpty())
                NSR[i] = n;
            else
                NSR[i] = st.peek();
            st.push(i);
        }
        return NSR;
    }

    public static int[] getNSL(int[] height) {
        // TC: O(2n)
        // SC: O(n)

        int n = height.length;
        int[] NSL = new int[n];
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && height[st.peek()] >= height[i]) {
                st.pop();
            }
            if (st.isEmpty())
                NSL[i] = -1;
            else
                NSL[i] = st.peek();
            st.push(i);
        }
        return NSL;
    }

    public static int findMaxArea(int[] height) {
        int n = height.length;
        int maxArea = 0;
        int[] NSL = getNSL(height);
        int[] NSR = getNSR(height);

        int[] width = new int[n];
        for (int i = 0; i < n; i++) {
            width[i] = NSR[i] - NSL[i] - 1;
        }

        for (int i = 0; i < n; i++) {
            maxArea = Math.max(maxArea, width[i] * height[i]);
        }
        return maxArea;
    }

    public static int maximalRectangle(char[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int[] height = new int[m];
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == '1')
                height[j] = 1;
        }
        int maxArea = 0;
        maxArea = findMaxArea(height);
        for (int row = 1; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (matrix[row][col] == '0')
                    height[col] = 0;
                else
                    height[col] += 1;
            }
            maxArea = Math.max(maxArea, findMaxArea(height));
        }
        return maxArea;
    }

*/