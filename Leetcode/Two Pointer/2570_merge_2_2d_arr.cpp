#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - using ordered map
    vector<vector<int>> mergeArrays2(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        // TC: O(m+n + NlogN), N = m+n
        // SC: O(m+n)

        int n1 = nums1.size();
        int n2 = nums2.size();
        map<int, int> mp;
        for (int i = 0; i < n1; i++)
        {
            int idx = nums1[i][0];
            int val = nums1[i][1];

            if (mp[idx])
            {
                mp[idx] = mp[idx] + val;
            }
            else
                mp[idx] = val;
        }

        for (int i = 0; i < n2; i++)
        {
            int idx = nums2[i][0];
            int val = nums2[i][1];

            if (mp[idx])
            {
                mp[idx] = mp[idx] + val;
            }
            else
                mp[idx] = val;
        }
        vector<vector<int>> res;
        map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            int idx = it->first;
            int val = it->second;
            res.push_back({idx, val});
        }
        return res;
    }

    // optimal - without map
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        // TC: O(m+n)
        // SC: O(m+n)

        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> res;

        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            int idx1 = nums1[i][0];
            int val1 = nums1[i][1];

            int idx2 = nums2[j][0];
            int val2 = nums2[j][1];

            if (idx1 < idx2)
            {
                res.push_back({idx1, val1});
                i++;
            }
            else if (idx2 < idx1)
            {
                res.push_back({idx2, val2});
                j++;
            }
            else
            {
                res.push_back({idx1, val1 + val2});
                i++;
                j++;
            }
        }
        while (i < n1)
        {
            int idx1 = nums1[i][0];
            int val1 = nums1[i][1];
            res.push_back({idx1, val1});
            i++;
        }
        while (j < n2)
        {
            int idx2 = nums2[j][0];
            int val2 = nums2[j][1];
            res.push_back({idx2, val2});
            j++;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> nums1 = {{2, 4}, {3, 6}, {5, 5}}, nums2 = {{1, 3}, {4, 3}};
    vector<vector<int>> ans = s.mergeArrays2(nums1, nums2);
    cout << "Result: " << endl;
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values

Youtube: https://www.youtube.com/watch?v=G2XFLIjoIHA

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Merge%20Two%202D%20Arrays%20by%20Summing%20Values.cpp

algorithm:

- Brute Force Approach:

- using ordered map

- Optimal Approach:

- using 2 - pointer

*/

/*

2570. Merge Two 2D Arrays by Summing Values

You are given two 2D integer arrays nums1 and nums2.

nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
Each array contains unique ids and is sorted in ascending order by id.

Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:

Only ids that appear in at least one of the two arrays should be included in the resulting array.
Each id should be included only once and its value should be the sum of the values of this id in the two arrays.
If the id does not exist in one of the two arrays, then assume its value in that array to be 0.
Return the resulting array. The returned array must be sorted in ascending order by id.

Example 1:

Input: nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
Output: [[1,6],[2,3],[3,2],[4,6]]
Explanation: The resulting array contains the following:
- id = 1, the value of this id is 2 + 4 = 6.
- id = 2, the value of this id is 3.
- id = 3, the value of this id is 2.
- id = 4, the value of this id is 5 + 1 = 6.

Example 2:

Input: nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]
Explanation: There are no common ids, so we just include each id with its value in the resulting list.

Constraints:

1 <= nums1.length, nums2.length <= 200
nums1[i].length == nums2[j].length == 2
1 <= idi, vali <= 1000
Both arrays contain unique ids.
Both arrays are in strictly ascending order by id.

*/

/*
************* Java Code **************

    public static int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        Map<Integer, Integer> mp = new TreeMap<>();
        for (int i = 0; i < n1; i++) {
            int idx = nums1[i][0];
            int val = nums1[i][1];

            if (mp.containsKey(idx)) {
                mp.replace(idx, mp.get(idx) + val);
            } else
                mp.put(idx, val);
        }

        for (int i = 0; i < n2; i++) {
            int idx = nums2[i][0];
            int val = nums2[i][1];

            if (mp.containsKey(idx)) {
                mp.replace(idx, mp.get(idx) + val);
            } else
                mp.put(idx, val);
        }
        List<int[]> res = new ArrayList<>();

        for (Map.Entry<Integer, Integer> it : mp.entrySet()) {
            int idx = it.getKey();
            int val = it.getValue();
            res.add(new int[] { idx, val });
        }
        int[][] ans = res.toArray(new int[res.size()][]);
        // int[][] ans = res.stream().toArray(int[][]::new);
        return ans;
    }

    public static int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        List<int[]> res = new ArrayList<>();

        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            int idx1 = nums1[i][0];
            int val1 = nums1[i][1];

            int idx2 = nums2[j][0];
            int val2 = nums2[j][1];

            if (idx1 < idx2) {
                res.add(new int[] { idx1, val1 });
                i++;
            } else if (idx2 < idx1) {
                res.add(new int[] { idx2, val2 });
                j++;
            } else {
                res.add(new int[] { idx1, val1 + val2 });
                i++;
                j++;
            }
        }
        while (i < n1) {
            int idx1 = nums1[i][0];
            int val1 = nums1[i][1];
            res.add(new int[] { idx1, val1 });
            i++;
        }
        while (j < n2) {
            int idx2 = nums2[j][0];
            int val2 = nums2[j][1];
            res.add(new int[] { idx2, val2 });
            j++;
        }
        return res.stream().toArray(int[][]::new);
    }

*/