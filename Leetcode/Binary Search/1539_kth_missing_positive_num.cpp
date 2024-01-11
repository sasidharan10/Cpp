#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute
    int findKthPositive2(vector<int> &arr, int k)
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

    // Better using Binary Search
    int findKthPositive(vector<int> &arr, int k)
    {
        // TC: O(logn)
        // SC: O(1)
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low + k;  // case 1
        // if (high < n)
        // {
        //     int miss = k - (arr[high] - (high + 1));
        //     return arr[high] + miss;
        // }
        // else
        //     return arr[n - 1] + k;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{2, 3, 4, 7, 11};
    // int k = 5;
    vector<int> nums{1, 2, 3, 4};
    int k = 2;
    cout << "Kth Missing Positive Number: " << s.findKthPositive(nums, k) << endl;
    return 0;
}

/*

link: https://www.codingninjas.com/studio/problems/kth-missing-element_893215

leetcode: https://leetcode.com/problems/kth-missing-positive-number/

Youtube: https://www.youtube.com/watch?v=uZ0N_hZpyps&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=21

algorithm:

case 1: 
- on how we got low + k as answer =>

- arr[high] + miss
- arr[high] + k - (arr[high] - (high + 1))
- arr[high] + k - (arr[high] - high - 1)
- arr[high] + k - arr[high] + high + 1 
- k + high + 1
- k + low

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