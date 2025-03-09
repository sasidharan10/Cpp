#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = colors.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int prev = colors[(i - 1 + n) % n];    // Circular previous element
            int curr = colors[i];
            int next = colors[(i + 1) % n];        // Circular next element

            if (curr != prev && curr != next)
            {
                count++;
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    vector<int> nums{0, 1, 0, 0, 1};
    cout << "Result: " << s.numberOfAlternatingGroups(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/alternating-groups-i/

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

3206. Alternating Groups I

There is a circle of red and blue tiles. You are given an array of integers colors. The color of tile i is
represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
Every 3 contiguous tiles in the circle with alternating colors (the middle tile has a different color from
its left and right tiles) is called an alternating group.

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

Example 1:

Input: colors = [1,1,1]
Output: 0

Example 2:

Input: colors = [0,1,0,0,1]
Output: 3

Constraints:

3 <= colors.length <= 100
0 <= colors[i] <= 1

*/

/*
************* Java Code **************

    public int numberOfAlternatingGroups(int[] colors) {
        int n = colors.length;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int prev = colors[(i - 1 + n) % n]; // Circular previous element
            int curr = colors[i];
            int next = colors[(i + 1) % n]; // Circular next element
            if (curr != prev && curr != next) {
                count++;
            }
        }
        return count;
    }

*/