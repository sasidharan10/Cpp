#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - Gives TLE
    int subarrayBitwiseORs2(vector<int> &arr)
    {
        // TC: O(n^2)
        // SC: O(32) ~ O(1)

        int n = arr.size();
        unordered_set<int> uset; // To store all unique OR results

        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            for (int j = i; j < n; j++)
            {
                temp |= arr[j];    // OR current element to previous result
                uset.insert(temp); // Add to set of unique ORs
            }
        }
        return uset.size(); // Return number of distinct OR values
    }

    // Optimal
    int subarrayBitwiseORs(vector<int> &arr)
    {
        // TC: O(n * 32)
        // SC: O(32) ~ O(1)

        int n = arr.size();
        unordered_set<int> prev;   // OR values from previous iteration (i - 1)
        unordered_set<int> curr;   // OR values ending at current index i
        unordered_set<int> result; // Final set of all distinct OR values

        for (int i = 0; i < n; i++)
        {
            // For every OR value from previous step, OR it with arr[i]
            for (int it : prev)
            {
                curr.insert(it | arr[i]);   // Extend subarrays ending at previous index
                result.insert(it | arr[i]); // Store in global result set
            }

            // Also consider subarray that starts and ends at index i
            curr.insert(arr[i]);
            result.insert(arr[i]);

            prev = curr;  // Update previous set for next iteration
            curr.clear(); // Clear current set for next iteration
        }
        return result.size(); // Return count of unique OR values across all subarrays
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 1, 2};
    cout << "Result: " << s.subarrayBitwiseORs(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/bitwise-ors-of-subarrays/

Youtube: https://www.youtube.com/watch?v=Jlj4LUJhQJY

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/HashSet/Bitwise%20ORs%20of%20Subarrays.cpp

algorithm:

- Brute Force Approach:

- For each index i, initialize temp = 0.
- Traverse from i to n-1, keep updating temp |= arr[j].
- Store each temp in a set to count unique ORs.

- Optimal Approach:

- prev: stores all OR values ending at i-1.
- curr: stores all OR values ending at current index i.
- For each i, do:
    - curr = {a | arr[i] for a in prev} ∪ {arr[i]}
    - Add all curr values to result set.
    - Set prev = curr and clear curr.
- Time Complexity: O(n × 32)
- Because a number has at most 32 different OR results due to 32-bit ints.
- Space Complexity: O(1) (bounded by bitwise possibilities)

*/

/*

898. Bitwise ORs of Subarrays

Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray
of one integer is that integer.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.

Example 2:

Input: arr = [1,1,2]
Output: 3
Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.

Example 3:

Input: arr = [1,2,4]
Output: 6
Explanation: The possible results are 1, 2, 3, 4, 6, and 7.

Constraints:

1 <= arr.length <= 5 * 10^4
0 <= arr[i] <= 10^9


*/

/*
************* Java Code **************

    public static int subarrayBitwiseORs(int[] arr) {
        int n = arr.length;
        HashSet<Integer> prev = new HashSet<>(); // OR values from previous iteration (i - 1)
        HashSet<Integer> curr = new HashSet<>(); // OR values ending at current index i
        HashSet<Integer> result = new HashSet<>(); // Final set of all distinct OR values

        for (int i = 0; i < n; i++) {
            // For every OR value from previous step, OR it with arr[i]
            for (int it : prev) {
                curr.add(it | arr[i]); // Extend subarrays ending at previous index
                result.add(it | arr[i]); // Store in global result set
            }

            // Also consider subarray that starts and ends at index i
            curr.add(arr[i]);
            result.add(arr[i]);

            prev = curr; // Update previous set for next iteration
            curr = new HashSet<>(); // Clear current set for next iteration
        }
        return result.size(); // Return count of unique OR values across all subarrays
    }

*/