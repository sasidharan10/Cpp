#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - create new array of size 2n, and then using Sliding window.
    int minSwaps2(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(2n)

        int n = nums.size();
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);
        vector<int> newArr(2 * n, 0);
        for (int i = 0; i < 2 * n; i++)
        {
            newArr[i] = nums[i % n];
        }
        int maxCount = 0, currOnes = 0;
        int i = 0, j = 0;
        while (j < 2 * n)
        {
            if (newArr[j] == 1)
            {
                currOnes++;
            }

            if (j - i + 1 > totalOnes) // if curr window greater than the given window
            {
                currOnes -= newArr[i];
                i++;
            }
            maxCount = max(maxCount, currOnes);
            j++;
        }
        return totalOnes - maxCount;
    }

    // Optimal - Using Sliding window, without creating new array.
    int minSwaps(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(1)

        int n = nums.size();
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);

        int maxOnes = 0, currOnes = 0;
        int i = 0, j = 0;
        while (j < 2 * n)
        {
            if (nums[j % n] == 1)
                currOnes++;

            if (j - i + 1 > totalOnes) // if curr window greater than the given window
            {
                currOnes -= nums[i % n];
                i++;
            }
            maxOnes = max(maxOnes, currOnes);
            j++;
        }
        return totalOnes - maxOnes;
    }
};
int main()
{
    Solution s;
    vector<int> nums{0, 1, 1, 1, 0, 0, 1, 1, 0};
    // vector<int> nums{1, 1, 0, 0, 1};
    cout << "Result: " << s.minSwaps(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii

Youtube: https://www.youtube.com/watch?v=t82KJaI1kNQ

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/Minimum%20Swaps%20to%20Group%20All%201's%20Together%20II.cpp

algorithm:

- Better Approach:

- Since its a circular aray, either all 0's or all 1's being together is enough to separate both
  elements.
- Hence we find the no of 1's present inthe array, then take that as the window size.
- We find the window with max no of 1's present in the array.
- The min no of swaps will be = totalOnes - maxOnes.
- Since its a circular array, we create a new array of size 2*n, and then perform the 
  operations.

- Optimal Approach:

- Same as above but instea of creating a new array, we simply traverse in the same array.
- For traverse circular in the array, we use this formula => index = (index % n);

*/

/*

2134. Minimum Swaps to Group All 1's Together II

A swap is defined as taking two distinct positions in an array and swapping the values in them.
A circular array is defined as an array where we consider the first element and the last element
to be adjacent.
Given a binary circular array nums, return the minimum number of swaps required to group all 1's
present in the array together at any location.

Example 1:

Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.

Example 2:

Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.

Example 3:

Input: nums = [1,1,0,0,1]
Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.

Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.

*/

/*
************* Java Code **************

    public static int minSwaps(int[] nums) {
        int n = nums.length;
        int totalOnes = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                totalOnes++;
        }

        int maxCount = 0, currOnes = 0;
        int i = 0, j = 0;
        while (j < 2 * n) {
            if (nums[j % n] == 1)
                currOnes++;

            if (j - i + 1 > totalOnes) {
                currOnes -= nums[i % n];
                i++;
            }
            maxCount = Math.max(maxCount, currOnes);
            j++;
        }
        return totalOnes - maxCount;
    }

*/