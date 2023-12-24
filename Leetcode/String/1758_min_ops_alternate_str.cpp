#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better
    int minOperations2(string s)
    {
        int n = s.length();
        int start_with_0 = 0; // 010101
        int start_with_1 = 0; // 101010
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '1')
                    start_with_0++;
                else
                    start_with_1++;
            }
            else
            {
                if (s[i] == '0')
                    start_with_0++;
                else
                    start_with_1++;
            }
        }
        return min(start_with_0, start_with_1);
    }

    // Optimal
    int minOperations(string s)
    {
        int n = s.length();
        int start_with_0 = 0; // 010101
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '1')
                    start_with_0++;
            }
            else
            {
                if (s[i] == '0')
                    start_with_0++;
            }
        }
        int start_with_1 = n - start_with_0;
        return min(start_with_0, start_with_1);
    }
};
int main()
{
    Solution s;
    string str = "0100";
    cout << "Result: " << s.minOperations(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

Youtube: https://www.youtube.com/watch?v=YB4oUR2Skfk

algorithm:

- Greedy approach won't work in some test cases like:
- Ex: "011010" using greedy will give "010101" in 4 ops, b
  But it can be solved using 2 ops also = "101010".
- The trick is, there can be only 2 types of answer, i.e., either
  the result will start from 0 = "010101..." or from 1 = "101010...".
- Hence, we try to count no of operations it will take, by starting with
  '1', and then with '0', and then return the minimum.
- No need to create a new string, we know that if string is starting with '1'
  then in all even places, '1' should be placed, and '0' in odd places.
  If not, we increase the ops count. and do the vice verse for starting with '0';

- Optimised Approach:

- We just need to find the operations for converting into alternate 
  string start from 0 = "010101...". for getting the operation count
  for start with 1 = "101010...", we can find by (n - start_with_0).
  
  
*/

/*

1758. Minimum Changes To Make Alternating Binary String

You are given a string s consisting only of the characters '0' and '1'. 
In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. 
For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.

Example 1:

Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.

Example 2:

Input: s = "10"
Output: 0
Explanation: s is already alternating.

Example 3:

Input: s = "1111"
Output: 2
Explanation: You need two operations to reach "0101" or "1010".

*/