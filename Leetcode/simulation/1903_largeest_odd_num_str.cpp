#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string largestOddNumber(string num)
    {
        string ans = "";
        int n = num.length();
        for (int i = n - 1; i >= 0; i--)
        {
            int x = num[i] - '0';
            if (x % 2 != 0)
            {
                ans += num.substr(0, i + 1);
                break;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    // string str = "52";
    string str = "35427";
    cout << "Largest Odd Number in String: " << s.largestOddNumber(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/largest-odd-number-in-string

Youtube:

algorithm:

- Search for odd number from the last, to get the largest odd number.

*/

/*

1903. Largest Odd Number in String

You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.



Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.


*/