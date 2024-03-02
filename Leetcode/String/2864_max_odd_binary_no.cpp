#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        // TC: O(n) + O(n)
        // SC: O(1)
        
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                cnt++;
        }
        s[n - 1] = '1';
        cnt--;
        for (int i = 0; i < n - 1; i++)
        {
            if (i < cnt)
                s[i] = '1';
            else
                s[i] = '0';
        }
        return s;
    }
};
int main()
{
    Solution s;
    string str = "0101";
    cout << "Max Odd Number: " << s.maximumOddBinaryNumber(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-odd-binary-number/

Youtube:

algorithm:

- Brute Force Approach:

- Sort the string in descending order, and swap the last '1', to the last position.

- Optimal Approach:

- Count no of '1's and place them at the left, and keep only one '1's at the
  end to make it a odd number.

*/

/*

2864. Maximum Odd Binary Number

You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary
number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can
be created from the given combination.

Note that the resulting string can have leading zeros.

Example 1:

Input: s = "010"
Output: "001"
Explanation: Because there is just one '1', it must be in the last position.
So the answer is "001".

Example 2:

Input: s = "0101"
Output: "1001"
Explanation: One of the '1's must be in the last position. The maximum number
that can be made with the remaining digits is "100". So the answer is "1001".

*/