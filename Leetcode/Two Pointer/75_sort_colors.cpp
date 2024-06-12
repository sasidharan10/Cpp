#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // Brute force - counting 0's, 1's and 2's and assigning it.
    void sortColors2(vector<int> &nums)
    {
        // TC: O(n) + O(n)
        // SC: O(1)

        int n = nums.size();
        int zeroes = 0, ones = 0, twos = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                zeroes++;
            else if (nums[i] == 1)
                ones++;
            else
                twos++;
        }

        for (int i = 0; i < zeroes; i++)
        {
            nums[i] = 0;
        }
        for (int i = zeroes; i < zeroes + ones; i++)
        {
            nums[i] = 1;
        }
        for (int i = zeroes + ones; i < n; i++)
        {
            nums[i] = 2;
        }
    }

    // Optimal - using 2 pointers.
    void sortColors(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid++], nums[low++]);
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[high--]);
            }
            else
                mid++;
        }
    }
};
int main()
{
    Solution s;
    vector<int> a{2, 0, 2, 1, 1, 0};
    s.sortColors(a);
    for (int i : a)
        cout << i << " ";
}

/*

link:

leetcode: https://leetcode.com/problems/sort-colors/description/

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

- counting 0's, 1's and 2's and assigning it.

- Optimal Approach:

- Using two pointers method.

*/

/*

75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place
so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

*/

/*
************* Java Code **************

public void sortColors(int[] nums) {
        int low = 0;
        int mid = 0;
        int high = nums.length - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                int temp = nums[mid];
                nums[mid] = nums[low];
                nums[low] = temp;
                mid++;
                low++;
            }
            else if (nums[mid] == 2)
            {
                int temp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = temp;
                high--;
            }
            else
                mid++;
        }
    }

*/