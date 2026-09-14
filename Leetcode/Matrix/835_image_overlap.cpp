#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countOverlaps(vector<vector<int>> &A, vector<vector<int>> &B, int rowOff, int colOff)
    {
        int n = A.size();
        int count = 0;

        /*
            Uncomment these to see how the matrix is moving. For ease, take example :
            [[0,1],[0,0]]
            [[0,0],[1,0]]

            cout << "\n----------------------------\n";
            cout << "Checking for rowOff = " << rowOff << ", collOff = " << colOff << endl;
        */

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row + rowOff < 0 || row + rowOff >= n || col + colOff < 0 || col + colOff >= n)
                    continue;

                /*
                    cout << "A[" << row << "][" << col << "] = " << A[row][col] << ", ";
                    cout  << "B[" << row+rowOff << "][" << col+colOff << "] = " << B[row+rowOff][col+colOff] << endl;
                */

                count += A[row][col] * B[row + rowOff][col + colOff];
            }
        }

        /*
            cout << "\n----------------------------\n";
        */

        return count;
    }
    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {

        // TC: O(n^4)
        // SC: O(1)

        int n = A.size();
        int maxOverlap = 0;

        for (int rowOff = -n + 1; rowOff < n; rowOff++)
        {
            for (int collOff = -n + 1; collOff < n; collOff++)
            {
                maxOverlap = max(maxOverlap, countOverlaps(A, B, rowOff, collOff));
            }
        }
        return maxOverlap;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid1{{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    vector<vector<int>> grid2{{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    cout << "Result: " << s.largestOverlap(grid1, grid2) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/image-overlap

Youtube: https://www.youtube.com/watch?v=3--u8aPXzWs

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-
    For ease take this example :
    [[0,1],[0,0]]
    [[0,0],[1,0]]

    So, we are basically having rowOffsets from (-n+1) to (n-1). Why ? Read all the comments to know
    For example : n = 2
    rowOff will have values -1, 0, 1
    colOff will have values -1, 0, 1

    Based on this rowOff,colOff, we will move B over A starting from "bottom left"
    1) rowOff  = -1, colOff = -1, means B is at bottom left overlapping with A[row][col] and B[row+rowOff][col+colOff]
    i.e. A[row][col] = A[1][1]
    i.e. B[row+rowOff][col+colOff] = B[0][0]

    2) For rowOff = -1 , we will have colOff -1, 0, 1 which means we are moving the window B towards right till we cross boundary

    Similarly we move ahead with rowOff  = 0, and then 1.....

*/

/*






*/

/*
************* Java Code **************

    public static int countOverlap(int[][] img1, int[][] img2, int rowoff, int coloff) {
        int n = img1.length;
        int overlapCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int newRow = i + rowoff;
                int newCol = j + coloff;
                if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= n)
                    continue;
                if(img1[i][j] == 1 && img2[newRow][newCol] == 1)
                    overlapCount++;
            }
        }
        return overlapCount;
    }

    public static int largestOverlap(int[][] img1, int[][] img2) {
        int n = img1.length;
        int maxOverlap = 0;
        for (int rowoff= -n + 1; rowoff< n; rowoff++) {
            for (int coloff = -n + 1; coloff < n; coloff++) {
                int overlapCount = countOverlap(img1, img2, rowoff, coloff);
                maxOverlap = Math.max(overlapCount, maxOverlap);
            }
        }
        return maxOverlap;
    }

*/