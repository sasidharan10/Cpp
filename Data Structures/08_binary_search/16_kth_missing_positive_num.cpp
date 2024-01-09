#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = arr.size();
        int num = 1, i = 0;
        while (i < n && k > 0)
        {
            if (num != arr[i])
            {
                k--;
                if (k == 0)
                    return num;
            }
            else
                i++;
            num++;
        }
        return num + k - 1;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{2, 3, 4, 7, 11};
    // int k = 5;
    vector<int> nums{1, 2, 3, 4};
    int k = 2;
    cout << "Result: " << s.findKthPositive(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/kth-missing-positive-number/

Youtube:

algorithm:

*/

/*

1539. Kth Missing Positive Number

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...].
The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...].
The 2nd missing positive integer is 6.

*/