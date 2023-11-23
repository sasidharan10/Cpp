#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = height.size();
        int l = 0, r = n - 1;
        long long maxi = INT_MIN;
        long long area = 1;
        while (l < r)
        {
            area = (r - l) * min(height[l], height[r]);
            maxi = max(area, maxi);
            if (height[l] <= height[r])
            {
                l++;
            }
            else
                r--;
        }
        return maxi;
    }
};
int main()
{
    Solution s;
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Container With Most Water: " << s.maxArea(height) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/container-with-most-water/

Youtube:

algorithm:

- We use two pointer approach. The height of the container untill which it
  will hold water, is the min(height[l], height[r]) and its breadth will
  be the difference between those index = (r-l).
- We calculate the height and update the maxi.
- To decide which pointer to move, we choose the one, having less height among
  the two.

*/

/*

11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn
such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container
contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
In this case, the max area of water (blue section) the container can contain is 49.

Example 2:

Input: height = [1,1]
Output: 1

*/