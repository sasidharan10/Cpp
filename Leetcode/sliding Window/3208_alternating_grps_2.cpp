#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // int numberOfAlternatingGroups(vector<int> &colors, int k)
    // {
    //     int n = colors.size();
    //     int beg = 0, end = 0;
    //     int len = 1;
    //     for (int i = 0; i < n - 1; i++)
    //     {
    //         if(colors)
    //     }

    // }

    // Brute force - gives TLE
    int numberOfAlternatingGroups3(vector<int> &colors, int k)
    {
        // TC: O(n*k)
        // SC: O(1)

        int n = colors.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            bool isAlternating = true;
            for (int j = i; j < i + k - 1; j++)
            {
                if (colors[j % n] == colors[(j + 1) % n])
                {
                    isAlternating = false;
                    break;
                }
            }
            if (isAlternating)
            {
                cnt++;
            }
        }
        return cnt;
    }

    // Optimal - using sliding window
    int numberOfAlternatingGroups2(vector<int> &colors, int k)
    {
        // TC: O(n + k)
        // SC: O(1)

        int n = colors.size();
        int cnt = 0;
        int i = 0, j = 1;
        while (j < n + k - 1)
        {
            if (colors[j % n] == colors[(j - 1) % n])
            {
                i = j;
                j++;
                continue;
            }
            if (j - i + 1 == k)
            {
                i++;
                cnt++;
            }
            j++;
        }
        return cnt;
    }

    // Optimal - using sliding window
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        // TC: O(n + k)
        // SC: O(1)

        int n = colors.size();
        int cnt = 0;
        int len = 1;
        for (int i = 1; i < n + k - 1; i++)
        {
            if (colors[i % n] == colors[(i - 1) % n])
            {
                len = 1;
            }
            else
                len++;
            if (len >= k)
                cnt++;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<int> nums{0, 1, 0, 1, 0};
    int k = 3;
    // vector<int> nums{1, 1, 0, 1};
    // int k = 4;
    cout << "Result: " << s.numberOfAlternatingGroups(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/alternating-groups-ii/

Youtube: https://www.youtube.com/watch?v=EZVLzXvaQ2A

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/Alternating%20Groups%20II.cpp

algorithm:

- Brute Force Approach:

- self explanatory

- Optimal Approach:

- using sliding window

*/

/*

3208. Alternating Groups II

There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The
color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the
group except the first and last one has a different color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

Example 1:

Input: colors = [0,1,0,1,0], k = 3
Output: 3

Example 2:

Input: colors = [0,1,0,0,1,0,1], k = 6
Output: 2

Example 3:

Input: colors = [1,1,0,1], k = 4
Output: 0

Constraints:

3 <= colors.length <= 10^5
0 <= colors[i] <= 1
3 <= k <= colors.length

*/

/*
************* Java Code **************

    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length;
        int cnt = 0;
        int len = 1;
        for (int i = 1; i < n + k - 1; i++) {
            if (colors[i % n] == colors[(i - 1) % n]) {
                len = 1;
            } else
                len++;
            if (len >= k)
                cnt++;
        }
        return cnt;
    }

*/