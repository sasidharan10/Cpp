#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better - using sorting and unordered_map
    vector<int> arrayRankTransform2(vector<int> &arr)
    {
        // TC: O(nlogn)
        // SC: O(n)

        int n = arr.size();
        if (n == 0)
            return arr;
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        int rank = 1;
        mp[temp[0]] = rank;
        for (int i = 1; i < n; i++)
        {
            if (temp[i - 1] != temp[i])
            {
                rank++;
                mp[temp[i]] = rank;
            }
            else
                mp[temp[i]] = rank;
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }

    // Optimal - using set(remove duplicates) and unordered_map
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        // TC: O(nlogn)
        // SC: O(n)

        int n = arr.size();
        if (n == 0)
            return arr;
        set<int> oset(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        int rank = 1;
        for (auto it = oset.begin(); it != oset.end(); it++)
        {
            mp[*it] = rank;
            rank++;
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};
int main()
{
    Solution s;
    vector<int> nums{37, 12, 28, 9, 100, 56, 80, 5, 12};
    vector<int> ans = s.arrayRankTransform(nums);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/rank-transform-of-an-array

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- self explanatory

*/

/*

1331. Rank Transform of an Array

Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.

Example 1:

Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the
third smallest.

Example 2:

Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.

Example 3:

Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]

Constraints:

0 <= arr.length <= 10^5
-10^9 <= arr[i] <= 10^9

*/

/*
************* Java Code **************

    public static int[] arrayRankTransform(int[] arr) {
        int n = arr.length;
        if (n == 0)
            return arr;
        TreeSet<Integer> tset = new TreeSet<>();
        for (int it : arr) {
            tset.add(it);
        }
        HashMap<Integer, Integer> mp = new HashMap<>();
        int rank = 1;
        for (int it : tset) {
            mp.put(it, rank);
            rank++;
        }
        for (int i = 0; i < n; i++) {
            arr[i] = mp.get(arr[i]);
        }
        return arr;
    }

*/