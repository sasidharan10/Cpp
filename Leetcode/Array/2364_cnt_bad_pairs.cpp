#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    long long countBadPairs2(vector<int> &nums)
    {
        // TC: O(n^2)
        // SC: O(1)

        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] - nums[i] != j - i)
                    cnt++;
            }
        }
        return cnt;
    }

    // Optimal - using algebra and hashmap
    long long countBadPairs(vector<int> &nums)
    {
        // TC: O(n)
        // SC: O(n)

        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            nums[i] = nums[i] - i;
        }
        mp[nums[0]] = 1;
        long long res = 0;
        for (int i = 1; i < n; i++)
        {
            int currFreq = mp[nums[i]];
            int totalNumsBefore = i;
            int badPairs = totalNumsBefore - currFreq;
            res += badPairs;
            mp[nums[i]]++;
        }
        return res;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{1, 2, 3, 4, 5};
    vector<int> nums{4, 1, 3, 3};
    cout << "Result: " << s.countBadPairs(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-number-of-bad-pairs

Youtube: https://www.youtube.com/watch?v=quUIQ2pw5EU

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/HashMap/Count%20Number%20of%20Bad%20Pairs.cpp

algorithm:

- Brute Force Approach:

- Find all possible pairs, and check for the condition: (j - i != nums[j] - nums[i])

- Optimal Approach:

- Convert the given equation:
- => (j - i != nums[j] - nums[i])
- => (nums[i] - i = nums[j] - j)
- Now, we just convert the given array, by subtracting its index, as per our new equation.
- Now we just have to find the elements which are not equal, as they will make the bad pairs.
- We use a map to store the elements frequency.

*/

/*

2364. Count Number of Bad Pairs

You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair
if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.

Example 1:

Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.

Example 2:

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9

*/

/*
************* Java Code **************

    public long countBadPairs(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] - i;
        }
        mp.put(nums[0], 1);
        long res = 0;
        for (int i = 1; i < n; i++) {
            int currFreq = mp.getOrDefault(nums[i], 0);
            int totalNumsBefore = i;
            int badPairs = totalNumsBefore - currFreq;
            res += badPairs;
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }
        return res;
    }

*/