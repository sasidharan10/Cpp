#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    vector<int> findThePrefixCommonArray3(vector<int> &numsA, vector<int> &numsB)
    {
        // TC: O(n^3)
        // SC: O(n)

        int n = numsA.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int A_i = 0; A_i <= i; A_i++)
            {
                for (int B_i = 0; B_i <= i; B_i++)
                {
                    if (numsA[A_i] == numsB[B_i])
                    {
                        cnt++;
                        break;
                    }
                }
            }
            res[i] = cnt;
        }
        return res;
    }

    // Better - using set
    vector<int> findThePrefixCommonArray2(vector<int> &numsA, vector<int> &numsB)
    {
        // TC: O(n^2)
        // SC: O(n)

        int n = numsA.size();
        unordered_set<int> uset;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            uset.insert(numsA[i]);
            for (int j = 0; j <= i; j++)
            {
                if (uset.find(numsB[j]) != uset.end())
                    cnt++;
            }
            res[i] = cnt;
        }
        return res;
    }

    // Optimal - using 2 maps
    vector<int> findThePrefixCommonArray(vector<int> &numsA, vector<int> &numsB)
    {
        // TC: O(n)
        // SC: O(2n) ~ O(n)

        int n = numsA.size();
        vector<int> res(n, 0);
        vector<int> mp(n + 1, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            mp[numsA[i]]++;
            if (mp[numsA[i]] == 2)
                cnt++;

            mp[numsB[i]]++;
            if (mp[numsB[i]] == 2)
                cnt++;

            res[i] = cnt;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> numsA{1, 3, 2, 4}, numsB{3, 1, 2, 4};
    vector<int> ans = s.findThePrefixCommonArray(numsA, numsB);
    cout << "Result: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays

Youtube: https://www.youtube.com/watch?v=hVda-pNPiuA

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Find%20the%20Prefix%20Common%20Array%20of%20Two%20Arrays.cpp

algorithm:

- Brute Force Approach:

- Just 3 loops

- Optimal Approach:

- using map

*/

/*

2657. Find the Prefix Common Array of Two Arrays

You are given two 0-indexed integer permutations A and B of length n.
A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that
are present at or before the index i in both A and B.
Return the prefix common array of A and B.
A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

Example 1:

Input: A = [1,3,2,4], B = [3,1,2,4]
Output: [0,2,3,4]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.

Example 2:

Input: A = [2,3,1], B = [3,1,2]
Output: [0,1,3]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: only 3 is common in A and B, so C[1] = 1.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.

Constraints:

1 <= A.length == B.length == n <= 50
1 <= A[i], B[i] <= n
It is guaranteed that A and B are both a permutation of n integers.

*/

/*
************* Java Code **************

    public int[] findThePrefixCommonArray(int[] numsA, int[] numsB) {
        int n = numsA.length;
        Set<Integer> set = new HashSet<>();
        int[] res = new int[n];

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            set.add(numsA[i]);
            for (int j = 0; j <= i; j++) {
                if (set.contains(numsB[j])) {
                    cnt++;
                }
            }
            res[i] = cnt;
        }
        return res;
    }


    public int[] findThePrefixCommonArray(int[] numsA, int[] numsB) {
        int n = numsA.length;
        int[] res = new int[n];
        int[] mp = new int[n + 1];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            mp[numsA[i]]++;
            if (mp[numsA[i]] == 2)
                cnt++;

            mp[numsB[i]]++;
            if (mp[numsB[i]] == 2)
                cnt++;

            res[i] = cnt;
        }
        return res;
    }


*/