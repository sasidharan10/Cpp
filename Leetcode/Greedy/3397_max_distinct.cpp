#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force - finding all combinations and inserting into a set.
    int maxDistinctElements2(vector<int> &nums, int k)
    {
        // TC: O(n * 2k) — each element tries up to 2k+1 possible values
        // SC: O(n) — for storing distinct elements

        int n = nums.size();
        unordered_set<int> uset; // stores unique reachable values

        for (int i = 0; i < n; i++)
        {
            // Try shifting current element by all values in range [-k, k]
            for (int j = -k; j <= k; j++)
            {
                int newVal = nums[i] + j;

                // Insert only if not already present
                if (!uset.count(newVal))
                {
                    uset.insert(newVal);

                    // Early stop — if all n elements are distinct already
                    if (uset.size() == n)
                        return n;
                }
            }
        }
        return uset.size(); // total distinct elements achievable
    }

    // Optimal - Greedy + Sorting approach
    int maxDistinctElements(vector<int> &nums, int k)
    {
        // TC: O(n log n) — due to sorting
        // SC: O(1) — constant extra space

        int n = nums.size();
        sort(nums.begin(), nums.end()); // sort to process smaller numbers first

        int prev = INT_MIN; // tracks last chosen distinct value
        int cnt = 0;        // count of distinct elements

        for (int i = 0; i < n; i++)
        {
            int minVal = nums[i] - k; // smallest possible value after operation

            if (prev < minVal)
            {
                // Choose the smallest available value within range
                prev = minVal;
                cnt++;
            }
            else if (prev < nums[i] + k)
            {
                // Shift slightly forward to make it distinct
                prev = prev + 1;
                cnt++;
            }
            // else → current range already fully covered, skip
        }

        return cnt; // maximum number of distinct elements
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 2, 2, 3, 3, 4};
    int k = 2;
    cout << "Result: " << s.maxDistinctElements(nums, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations

Youtube: https://www.youtube.com/watch?v=Vg3NjGAgOzU

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Greedy/Maximum%20Number%20of%20Distinct%20Elements%20After%20Operations.cpp

algorithm:

- Brute Force Approach:

- Each element can vary within the range [nums[i] - k, nums[i] + k].
- For every element, try all possible shifted values from -k to k.
- Use an unordered set to store unique achievable numbers.
- Insert only the first unused value to keep elements distinct.
- Stop early if the number of distinct elements equals the array size.
- Maximizes distinct values by greedily filling available numbers.
- Time Complexity: O(n * 2k) — each element checks up to 2k + 1 values.
- Space Complexity: O(n) — for the unordered set.

- Optimal Approach:

- Sort the array to handle elements in increasing order.
- Maintain prev to track the last assigned distinct number.
- For each element, try assigning it a value in [nums[i] - k, nums[i] + k].
- If prev < nums[i] - k, assign the lowest possible (nums[i] - k).
- Otherwise, assign the next available value (prev + 1) if within range.
- Skip the element if the range is already used up.
- Greedily ensures minimal overlap and maximum distinctness.
- Time Complexity: O(n log n) due to sorting.
- Space Complexity: O(1) — in-place operations.

*/

/*

3397. Maximum Number of Distinct Elements After Operations

You are given an integer array nums and an integer k.
You are allowed to perform the following operation on each element of the array at most once:
Add an integer in the range [-k, k] to the element.
Return the maximum possible number of distinct elements in nums after performing the operations.

Example 1:

Input: nums = [1,2,2,3,3,4], k = 2
Output: 6
Explanation:
nums changes to [-1, 0, 1, 2, 3, 4] after performing operations on the first four elements.

Example 2:

Input: nums = [4,4,4,4], k = 1
Output: 3
Explanation:
By adding -1 to nums[0] and 1 to nums[1], nums changes to [3, 5, 4, 4].

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= k <= 10^9

*/

/*
************* Java Code **************

    public int maxDistinctElements(int[] nums, int k) {
        int n = nums.length;

        Arrays.sort(nums);

        int count = 0;
        int prev = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            int minVal = nums[i] - k;

            if (prev < minVal) {
                // choose nums[i] - k
                prev = minVal;
                count++;
            } else if (prev < nums[i] + k) {
                // choose next available distinct value greater than prev
                prev = prev + 1;
                count++;
            }
        }

        return count;
    }

*/