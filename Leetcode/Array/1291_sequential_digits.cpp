#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better using BFS
    vector<int> sequentialDigits2(int low, int high)
    {
        // TC: O(n)
        // SC: O(n)

        queue<int> que;
        for (int i = 1; i <= 8; i++)
        {
            que.push(i);
        }
        vector<int> ans;
        while (!que.empty())
        {
            int temp = que.front();
            que.pop();

            if (temp > high)
                break;
            if (temp >= low && temp <= high)
                ans.push_back(temp);

            int lastDisit = temp % 10;
            if (lastDisit + 1 <= 9)
            {
                que.push((temp * 10) + lastDisit + 1);
            }
        }
        return ans;
    }

    // Optimal using enumeration
    vector<int> sequentialDigits(int low, int high)
    {
        // TC: O(1)
        // SC: O(1)
        
        vector<int> mp{12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345, 456,
                       567, 678, 789, 1234, 2345, 3456, 4567, 5678, 6789, 12345, 23456, 34567,
                       45678, 56789, 123456, 234567, 345678, 456789, 1234567, 2345678, 3456789,
                       12345678, 23456789, 123456789};

        int n = mp.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (mp[i] < low)
                continue;

            if (mp[i] > high)
                break;

            ans.push_back(mp[i]);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    int low = 1000, high = 13000;
    vector<int> ans = s.sequentialDigits(low, high);
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

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

-

*/

/*

1291. Sequential Digits

An integer has sequential digits if and only if each digit in
the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high]
inclusive that have sequential digits.

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]

*/