#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        // TC: O(min(n1, n2))
        // SC: O(1)

        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (nums1[i] == nums2[j])
                return nums1[i];
            else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums1{1, 2, 3, 6};
    vector<int> nums2{2, 3, 4, 5};
    cout << "Minimum Common Value: " << s.getCommon(nums1, nums2) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-common-value/

Youtube:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

2540. Minimum Common Value

Given two integer arrays nums1 and nums2, sorted in non-decreasing order,
return the minimum integer common to both arrays. If there is no common
integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays
have at least one occurrence of that integer.

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.

Example 2:

Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2
is the smallest, so 2 is returned.

*/