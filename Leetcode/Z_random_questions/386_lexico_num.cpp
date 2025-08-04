#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int currNum, int n, vector<int> &res)
    {
        if (currNum > n)
            return;
        res.push_back(currNum);

        for (int append = 0; append <= 9; append++)
        {
            int nextNum = currNum * 10 + append;
            if (nextNum > n)
                return;

            solve(nextNum, n, res);
        }
    }
    vector<int> lexicalOrder(int n)
    {
        vector<int> res;
        for (int currNum = 1; currNum <= 9; currNum++)
        {
            if (currNum > n)
                return res;
            solve(currNum, n, res);
        }
        return res;
    }
};
int main()
{
    Solution s;
    int n = 13;
    vector<int> ans = s.lexicalOrder(n);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/lexicographical-numbers

Youtube: https://www.youtube.com/watch?v=vuS3US_bDBo

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Recursion/Lexicographical%20Numbers.cpp

algorithm:

- Better Approach:

- Using dfs.

- Optimal Approach:

- susing trie, but not completed.

*/

/*

386. Lexicographical Numbers

Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
You must write an algorithm that runs in O(n) time and uses O(1) extra space.

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

Example 2:

Input: n = 2
Output: [1,2]

Constraints:

1 <= n <= 5 * 10^4

*/

/*
************* Java Code **************

    public static void solve(int currNum, int n, List<Integer> res) {
        if (currNum > n)
            return;
        res.add(currNum);

        for (int append = 0; append <= 9; append++) {
            int nextNum = currNum * 10 + append;
            if (nextNum > n)
                return;

            solve(nextNum, n, res);
        }
    }

    public static List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        for (int currNum = 1; currNum <= 9; currNum++) {
            if (currNum > n)
                return res;
            solve(currNum, n, res);
        }
        return res;
    }

*/