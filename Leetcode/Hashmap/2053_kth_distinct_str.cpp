#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Using map.
    string kthDistinct(vector<string> &arr, int k)
    {
        // TC: O(n)
        // SC: O(n)
        
        int n = arr.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp[arr[i]] == 1 && k == 1)
                return arr[i];
            if (mp[arr[i]] == 1 && k > 1)
                k--;
        }
        return "";
    }
};
int main()
{
    Solution s;
    vector<string> words{"d", "b", "c", "b", "c", "a"};
    int k = 2;
    cout << "Result: " << s.kthDistinct(words, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/kth-distinct-string-in-an-array

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

2053. Kth Distinct String in an Array

A distinct string is a string that is present only once in an array.
Given an array of strings arr, and an integer k, return the kth distinct string present in arr. 
If there are fewer than k distinct strings, return an empty string "".
Note that the strings are considered in the order in which they appear in the array.

Example 1:

Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned. 

Example 2:

Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"
Explanation:
All strings in arr are distinct, so the 1st string "aaa" is returned.

Example 3:

Input: arr = ["a","b","a"], k = 3
Output: ""
Explanation:
The only distinct string is "b". Since there are fewer than 3 distinct strings, we return 
an empty string "".
 
Constraints:

1 <= k <= arr.length <= 1000
1 <= arr[i].length <= 5
arr[i] consists of lowercase English letters.

*/

/*
************* Java Code **************

    public static int[] sortArray(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }
        int mini = Integer.MAX_VALUE;
        int maxi = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            mini = Math.min(nums[i], mini);
            maxi = Math.max(nums[i], maxi);
        }

        int idx = 0;
        for (int i = mini; i <= maxi; i++) {
            while (mp.containsKey(i) && mp.get(i) > 0) {
                nums[idx] = i;
                mp.replace(i, mp.get(i) - 1);
                idx++;
            }
        }
        return nums;
    }

*/