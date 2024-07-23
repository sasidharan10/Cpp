#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal - using comparator to sort as per required.
    vector<int> frequencySort(vector<int> &nums)
    {
        // TC: O(nlogn)
        // SC: O(1)

        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        auto lambda = [&](int a, int b)
        {
            if (mp[a] == mp[b])
            {
                return a > b;
            }
            else
                return mp[a] < mp[b];
        };
        sort(nums.begin(), nums.end(), lambda);
        return nums;
    }
};
int main()
{
    Solution s;
    vector<int> nums{2, 3, 1, 3, 2};
    vector<int> ans = s.frequencySort(nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sort-array-by-increasing-frequency

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- create a custom sorting algo using lambda function, and sort it.

*/

/*

1636. Sort Array by Increasing Frequency

Given an array of integers nums, sort the array in increasing order based on the frequency of
the values. If multiple values have the same frequency, sort them in decreasing order.
Return the sorted array.

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100

*/

/*
************* Java Code **************

public static int[] frequencySort(int[] nums) {
        // TC: O(nlogn)
        // SC: O(1)

        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

        Integer[] array = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        Comparator cmp = new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                if (mp.get(a).equals(mp.get(b))) {
                    return Integer.compare(b, a);
                } else
                    return Integer.compare(mp.get(a), mp.get(b));
            }
        };

        Arrays.sort(array, cmp);

        return Arrays.stream(array).mapToInt(Integer::intValue).toArray();
    }

*/