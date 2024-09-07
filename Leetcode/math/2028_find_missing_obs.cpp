#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int sz = rolls.size();
        int totalRolls = sz + n;

        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        cout << "sum: " << sum << endl;
        int totalSum = mean * totalRolls;
        cout << "totalSum: " << totalSum << endl;
        if (totalSum / totalRolls > 6)
            return {};
        int remaining = totalSum - sum;
        cout << "remaining: " << remaining << endl;
        int rem = remaining % n;
        cout << "rem: " << rem << endl;
        int temp = floor(remaining / (float)n);
        cout << "temp (actual): " << remaining / (float)n << endl;
        cout << "temp: " << temp << endl;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(temp);
        }
        int i = 0;
        int m = res.size();
        while (i < m && rem > 0)
        {
            res[i] += 1;
            rem--;
            i++;
        }
        return res;
    }
};
int main()
{
    Solution s;
    // vector<int> nums{1, 5, 6};
    // int mean = 3, n = 4;
    vector<int> nums{4, 5, 6, 2, 3, 6, 5, 4, 6, 4, 5, 1, 6, 3, 1, 4, 5, 5, 3, 2, 3, 5, 3, 2, 1, 5, 4, 3, 5, 1, 5};
    int mean = 4, n = 40;
    vector<int> ans = s.missingRolls(nums, mean, n);
    cout << "Result: " << endl;
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    return 0;
}

/*

link:

leetcode:

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- self explanatory

*/

/*

2028. Find Missing Observations

You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the
observations went missing, and you only have the observations of m rolls. Fortunately, you have
also calculated the average value of the n + m rolls.

You are given an integer array rolls of length m where rolls[i] is the value of the ith observation.
You are also given the two integers mean and n.

Return an array of length n containing the missing observations such that the average value of
the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no
such array exists, return an empty array.

The average value of a set of k numbers is the sum of the numbers divided by k.

Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.

Example 1:

Input: rolls = [3,2,4,3], mean = 4, n = 2
Output: [6,6]
Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.

Example 2:

Input: rolls = [1,5,6], mean = 3, n = 4
Output: [2,3,2,2]
Explanation: The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.

Example 3:

Input: rolls = [1,2,3,4], mean = 6, n = 4
Output: []
Explanation: It is impossible for the mean to be 6 no matter what the 4 missing rolls are.

Constraints:

m == rolls.length
1 <= n, m <= 10^5
1 <= rolls[i], mean <= 6

*/

/*
************* Java Code **************



*/