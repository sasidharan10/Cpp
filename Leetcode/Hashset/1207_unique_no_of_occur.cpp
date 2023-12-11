#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        // TC: O(n)
        // SC: O(2n)

        unordered_map<int, int> mp;
        unordered_set<int> set;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        for (auto it : mp)
        {
            if (set.find(it.second) != set.end())
                return false;
            else
                set.insert(it.second);
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 2, 1, 1, 3};
    cout << "Unique Number of Occurrences: " << s.uniqueOccurrences(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/unique-number-of-occurrences

Youtube:

algorithm:

*/

/*

1207. Unique Number of Occurrences

Given an array of integers arr, return true if the number of occurrences
of each value in the array is unique or false otherwise.

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1.
No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

*/