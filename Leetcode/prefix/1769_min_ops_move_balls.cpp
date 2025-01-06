#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force - my approach
    vector<int> minOperations4(string boxes)
    {
        // TC: O(n^2)
        // SC: O(n)

        int n = boxes.length();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
        {
            int lt = i - 1;
            int rt = i + 1;
            int dist = 1;
            int pathSum = 0;
            // traversing left, and
            while (lt >= 0)
            {
                if (boxes[lt] == '1')
                    pathSum += dist;
                dist++;
                lt--;
            }
            dist = 1;
            while (rt < n)
            {
                if (boxes[rt] == '1')
                    pathSum += dist;
                dist++;
                rt++;
            }
            res[i] = pathSum;
        }
        return res;
    }

    vector<int> minOperations3(string boxes)
    {
        // TC: O(n^2)
        // SC: O(n)

        int n = boxes.length();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (boxes[i] == '1')
            {
                for (int j = 0; j < n; j++)
                {
                    res[j] += abs(i - j);
                }
            }
        }
        return res;
    }

    // Better - using set
    vector<int> minOperations2(string boxes)
    {
        // TC: O(n*m) where m = no of 1's.
        // SC: O(n)

        int n = boxes.length();
        vector<int> res(n, 0);
        unordered_set<int> uset;
        for (int i = 0; i < n; i++)
        {
            if (boxes[i] == '1')
                uset.insert(i);
        }
        for (int i = 0; i < n; i++)
        {
            for (int it : uset)
            {
                res[i] += abs(i - it);
            }
        }
        return res;
    }

    // Optimal
    vector<int> minOperations(string boxes)
    {
        // TC: O(2n) ~ O(n)
        // SC: O(n)

        int n = boxes.length();
        vector<int> res(n, 0);
        int cnt = 0, distSum = 0;
        for (int i = 0; i < n; i++)
        {
            distSum += cnt;
            res[i] = distSum;
            if (boxes[i] == '1')
                cnt++;
        }
        cnt = 0, distSum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            distSum += cnt;
            res[i] += distSum;
            if (boxes[i] == '1')
                cnt++;
        }
        return res;
    }
};
int main()
{
    Solution s;
    string str = "001011";
    vector<int> ans = s.minOperations(str);
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

leetcode: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box

Youtube: https://www.youtube.com/watch?v=1j_ssSAjDcI

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/strings/Minimum%20Number%20of%20Operations%20to%20Move%20All%20Balls%20to%20Each%20Box.cpp

algorithm:

- Brute Force Approach:

- simulate the problem

- Optimal Approach:

- using prefix

*/

/*

1769. Minimum Number of Operations to Move All Balls to Each Box

You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box
is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j
if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move
all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.

Example 1:

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move
one ball from the second box to the third box in one operation.

Example 2:

Input: boxes = "001011"
Output: [11,8,5,4,3,4]

Constraints:

n == boxes.length
1 <= n <= 2000
boxes[i] is either '0' or '1'.

*/

/*
************* Java Code **************

    public static int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] res = new int[n];
        int cnt = 0, distSum = 0;
        for (int i = 0; i < n; i++) {
            distSum += cnt;
            res[i] = distSum;
            if (boxes.charAt(i) == '1')
                cnt++;
        }
        cnt = 0;
        distSum = 0;
        for (int i = n - 1; i >= 0; i--) {
            distSum += cnt;
            res[i] += distSum;
            if (boxes.charAt(i) == '1')
                cnt++;
        }
        return res;
    }

    public static int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] res = new int[n];
        HashSet<Integer> hset = new HashSet<>();
        for (int i = 0; i < n; i++) {
            if (boxes.charAt(i) == '1')
                hset.add(i);
        }
        for (int i = 0; i < n; i++) {
            for (int it : hset) {
                res[i] += Math.abs(i - it);
            }
        }
        return res;
    }

*/