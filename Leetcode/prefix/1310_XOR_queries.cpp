#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - Accepted but wont work for large test cases.
    vector<int> xorQueries2(vector<int> &arr, vector<vector<int>> &queries)
    {
        // TC: O(n * m)
        // SC: O(n)

        int n = arr.size();
        int m = queries.size();
        vector<int> res;
        for (int i = 0; i < m; i++)
        {
            int lt = queries[i][0];
            int rt = queries[i][1];
            if (lt == rt)
                res.push_back(arr[lt]);
            else
            {
                int XOR = arr[lt];
                lt++;
                while (lt <= rt)
                {
                    XOR ^= arr[lt];
                    lt++;
                }
                res.push_back(XOR);
            }
        }
        return res;
    }

    // Optimal - Using prefix XOR.
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        // TC: O(n + m)
        // SC: O(n)

        int n = arr.size();
        int m = queries.size();
        vector<int> prefix;
        vector<int> res;
        prefix.push_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            prefix.push_back(prefix[i - 1] ^ arr[i]);
        }
        for (int i = 0; i < m; i++)
        {
            int lt = queries[i][0];
            int rt = queries[i][1];
            if (lt == 0)
                res.push_back(prefix[rt]);
            else
                res.push_back(prefix[lt - 1] ^ prefix[rt]);
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1, 3, 4, 8};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
    vector<int> ans = s.xorQueries2(nums, queries);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/xor-queries-of-a-subarray

Youtube: https://www.youtube.com/watch?v=rZYdNpHXz0o

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Bit_Magic/XOR%20Queries%20of%20a%20Subarray.cpp

algorithm:

- Brute Force Approach:

- Just tak the XOR as per the given query, and put it into an array and return it.
- T.C: O(n*m)

- Optimal Approach:

- We can solve this problem in O(m) using prefix XOR.
- We know that, when we XOR same elements, the result will be 0.
- We will use this trick to solve this problem.
- Take prefix XOR of the arr[], and store it into a new array prefix.
- Let's say, we want to find the XOR for [3, 5].
- Which means a3 ^ a4 ^ a5
- Using prefix: (a1 ^ a2) ^ (a1 ^ a2 ^ a3 ^ a4 ^ a5) => a3 ^ a4 ^ a5.
- Since the same elements gets cancelled out.

*/

/*

1310. XOR Queries of a Subarray

You are given an array arr of positive integers. You are also given the array queries where
queries[i] = [lefti, righti].

For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR
arr[lefti + 1] XOR ... XOR arr[righti] ).

Return an array answer where answer[i] is the answer to the ith query.

Example 1:

Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8]
Explanation:
The binary representation of the elements in the array are:
1 = 0001
3 = 0011
4 = 0100
8 = 1000
The XOR values for queries are:
[0,1] = 1 xor 3 = 2
[1,2] = 3 xor 4 = 7
[0,3] = 1 xor 3 xor 4 xor 8 = 14
[3,3] = 8

Example 2:

Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]

Constraints:

1 <= arr.length, queries.length <= 3 * 10^4
1 <= arr[i] <= 10^9
queries[i].length == 2
0 <= lefti <= righti < arr.length

*/

/*
************* Java Code **************

    public static int[] xorQueries(int[] arr, int[][] queries) {
        // TC: O(n + m)
        // SC: O(n)

        int n = arr.length;
        int m = queries.length;
        int[] prefix = new int[n];
        int[] res = new int[m];
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }
        for (int i = 0; i < m; i++) {
            int lt = queries[i][0];
            int rt = queries[i][1];
            if (lt == 0)
                res[i] = prefix[rt];
            else
                res[i] = prefix[lt - 1] ^ prefix[rt];
        }
        return res;
    }

*/