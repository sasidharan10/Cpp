#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        // TC: O(n)
        // SC: O(1)
        
        int n = arr.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
                cnt = 0;
            else
                cnt++;
            if (cnt == 3)
                return true;
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 34, 3, 4, 5, 7, 23, 12};
    cout << "Result: " << s.threeConsecutiveOdds(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/three-consecutive-odds

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

1550. Three Consecutive Odds

Given an integer array arr, return true if there are three consecutive odd numbers in the
array. Otherwise, return false.

Example 1:

Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.
Example 2:

Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.


Constraints:

1 <= arr.length <= 1000
1 <= arr[i] <= 1000

*/

/*
************* Java Code **************

public boolean threeConsecutiveOdds(int[] arr) {
        int n = arr.length;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
                cnt = 0;
            else
                cnt++;
            if (cnt == 3)
                return true;
        }
        return false;
    }

*/