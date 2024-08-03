#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        // TC: O(n)
        // SC: O(n)
        
        int n = arr.size();
        vector<int> mp(1001, 0);
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (!mp[target[i]])
                return false;
            else
                mp[target[i]]--;
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<int> target = {1, 2, 3, 4}, arr = {2, 4, 1, 3};
    cout << "Result: " << s.canBeEqual(target, arr) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- If any 2 arrays have same elements, in any order, then its possible to convert the order of 
  first array into second array and vice-versa, via reversing its sub-arrays.
- So, we have to just check, if all elements present in arr[] are also present in target[].
- If yes, then return true, or return false.

*/

/*

1460. Make Two Arrays Equal by Reversing Subarrays

You are given two integer arrays of equal length target and arr. In one step, you can select any
non-empty subarray of arr and reverse it. You are allowed to make any number of steps.

Return true if you can make arr equal to target or false otherwise.

Example 1:

Input: target = [1,2,3,4], arr = [2,4,1,3]
Output: true
Explanation: You can follow the next steps to convert arr to target:
1- Reverse subarray [2,4,1], arr becomes [1,4,2,3]
2- Reverse subarray [4,2], arr becomes [1,2,4,3]
3- Reverse subarray [4,3], arr becomes [1,2,3,4]
There are multiple ways to convert arr to target, this is not the only way to do so.

Example 2:

Input: target = [7], arr = [7]
Output: true
Explanation: arr is equal to target without any reverses.

Example 3:

Input: target = [3,7,9], arr = [3,7,11]
Output: false
Explanation: arr does not have value 9 and it can never be converted to target.

Constraints:

target.length == arr.length
1 <= target.length <= 1000
1 <= target[i] <= 1000
1 <= arr[i] <= 1000

*/

/*
************* Java Code **************

public static boolean canBeEqual(int[] target, int[] arr) {
        int n = arr.length;
        int[] mp = new int[1001];
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (mp[target[i]] == 0)
                return false;
            else
                mp[target[i]]--;
        }
        return true;
    }

*/