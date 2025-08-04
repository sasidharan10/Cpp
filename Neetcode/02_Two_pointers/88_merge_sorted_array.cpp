#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    // Brute force - sorting
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[i + m] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }

    // Optimal - 2 pointer
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // TC: O(m + n) → At most m + n elements processed once
        // SC: O(1) → In-place merging, no extra space used

        // Start from the end of both arrays (excluding extra 0s in nums1)
        int i = m - 1;        // Pointer for the last valid element in nums1
        int j = n - 1;        // Pointer for the last element in nums2
        int last = m + n - 1; // Position to fill from the end of nums1

        // Compare elements from the back and place the larger one at the end
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] >= nums2[j])
                nums1[last--] = nums1[i--]; // Place nums1[i] and move i & last
            else
                nums1[last--] = nums2[j--]; // Place nums2[j] and move j & last
        }

        // If any elements remain in nums2, copy them to nums1
        while (j >= 0)
        {
            nums1[last--] = nums2[j--];
        }
    }
};
int main()
{
    Solution s;
    int m = 3, n = 3;
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    s.merge(nums1, m, nums2, n);
    for (auto &&i : nums1)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/merge-sorted-array/

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

- sort the array, after adding all elements in nums1.

- Optimal Approach:

- nums1 has enough space (length m + n) to hold both arrays.
- Use three pointers:
    - i = m - 1 → last valid element in nums1
    - j = n - 1 → last element in nums2
    - last = m + n - 1 → fill position in nums1 from the end
- Compare nums1[i] and nums2[j], place the larger at nums1[last].
- Decrement the respective pointers (i, j, last) accordingly.
- After the loop:
    - If elements left in nums2 → copy them to nums1
    - If elements left in nums1 → already in correct place

*/

/*

88. Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers
m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array
nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements
that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-10^9 <= nums1[i], nums2[j] <= 10^9

*/

/*
************* Java Code **************

    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // TC: O(m + n) - linear pass through both arrays
        // SC: O(1) - no extra space used (modifies nums1 in-place)

        int i = m - 1;
        int j = n - 1;
        int last = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[last--] = nums1[i--];
            } else {
                nums1[last--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[last--] = nums2[j--];
        }

        // Note: No need to copy remaining nums1 elements as they're already in place
    }

*/