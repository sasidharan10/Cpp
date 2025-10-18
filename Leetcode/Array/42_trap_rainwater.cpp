#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap1(vector<int> &height)
    {
        // Time : O(n^2)
        // Space : O(n)
        int n = height.size();
        if (n <= 2)
            return 0;
        int trappedWater = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int leftmax = height[i];
            for (int j = 0; j < i; j++)
            {
                leftmax = max(leftmax, height[j]);
            }
            int rightmax = height[i];
            for (int k = i + 1; k < n; k++)
            {
                rightmax = max(rightmax, height[k]);
            }
            trappedWater += min(leftmax, rightmax) - height[i];
        }
        return trappedWater;
    }
    int trap2(vector<int> &height)
    {
        // Time : O(3n)
        // Space : O(2n)

        int n = height.size();

        // water will overflow if it has only 2 structure
        if (n <= 2)
            return 0;

        // to store left max prefix and right max suffix
        vector<int> left(n), right(n);

        left[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], height[i]);
        }
        right[n - 1] = height[n - 1];
        for (int j = n - 2; j >= 0; j--)
        {
            right[j] = max(right[j + 1], height[j]);
        }
        int trappedWater = 0;
        // for (auto &&it : left)
        // {
        //     cout << it << ", ";
        // }
        // cout << endl;
        // for (auto &&it : right)
        // {
        //     cout << it << ", ";
        // }
        // cout << endl;

        for (int i = 1; i < n - 1; i++)
        {
            if (height[i] < left[i] && height[i] < right[i])
            {
                trappedWater += (min(left[i], right[i]) - height[i]);
            }
        }
        return trappedWater;
    }
    int trap(vector<int> &height)
    {
        // Time : O(n)
        // Space : O(1)

        int n = height.size();
        if (n <= 2)
            return 0;
        int leftmax = height[0];
        int rightmax = height[n - 1];
        int left = 1;
        int right = n - 2;
        int trappedWater = 0;
        while (left <= right)
        {
            if (leftmax < rightmax) // if min-height is leftmax
            {
                if (height[left] > leftmax) // if current element is greater
                    leftmax = height[left];
                else
                    trappedWater += leftmax - height[left];
                left++;
            }
            else
            {
                if (height[right] > rightmax) // if min-height is rightmax
                    rightmax = height[right];
                else
                    trappedWater += rightmax - height[right];
                right--;
            }
        }
        return trappedWater;
    }
};

int main()
{
    Solution s;
    // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> height = {4, 2, 0, 3, 2, 5};
    // cout << "Total Trapped water : " << s.trap1(height) << endl;
    cout << "Total Trapped water : " << s.trap(height) << endl;
    // cout << "Total Trapped water : " << s.trap(height) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/trapping-rain-water/

Youtube: https://www.youtube.com/watch?v=m18Hntz4go8

Code Link:

algorithm:

- the Algorithm here is to find the water level of each structure and subtract it
  with the height of the structure (min(left[i],right[i])-a[i]);
- In first solution, we store all rightmax and leftmax of all the element
  in a array and then compare it with the current element
- In 2nd solution, we traverse the array only once, keeping the current left,current
  right element as max and update it if the current is bigger.

*/

/*

42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of
each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by
array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

*/

/*
************* Java Code **************

public int trap(int[] height) {
        int n = height.length;
        if (n <= 2)
            return 0;
        int[] left = new int[n];
        int[] right = new int[n];

        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = Math.max(left[i - 1], height[i]);
        }
        right[n - 1] = height[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            right[j] = Math.max(right[j + 1], height[j]);
        }
        int trappedWater = 0;
        for (int i = 1; i < n - 1; i++) {
            if (height[i] < left[i] && height[i] < right[i]) {
                trappedWater += (Math.min(left[i], right[i]) - height[i]);
            }
        }
        return trappedWater;
    }

*/