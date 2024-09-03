#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getLucky(string s, int k)
    {
        // TC: O(n) + O(k)
        // SC: O(n)

        int n = s.length();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int num = s[i] - 'a' + 1; // adding 1 since 'a' == 1, not 0.
            if (num > 19)
                sum = sum + 2 + (num % 10);
            else if (num > 9)
                sum = sum + 1 + (num % 10);
            else
                sum += num;
        }
        k--;  // since we already added the digit's sum once, in the avobe loop.
        while (k > 0 && sum > 9)
        {
            int temp = sum;
            sum = 0;
            while (temp > 0)
            {
                sum += temp % 10;
                temp /= 10;
            }
            k--;
        }
        return sum;
    }
};
int main()
{
    Solution s;
    string str = "leetcode";
    int k = 2;
    cout << "Result: " << s.getLucky(str, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/sum-of-digits-of-string-after-convert

Youtube:

Code Link:

algorithm:

- Optimal Approach:

- Its given that k >= 1, so we can directly take the sum of digits, while converting the
  characters into numbers. Why? because, length of string can be upto hundred. And if every
  character is of 2 digit number, then its impossible to represent it as an integer.
- But if we take the sum of digits, as we traverse, it gets reduced to a smaller number.
- Eg: s = "zzzz..." till 100.
- Then its sum = (2 + 6) + (2 + 6) + (2 + 6) + (2 + 6).... till 100
- Sum = 800. hence if we directly sum the digits, we can reduce it to a smaller number.
- Then we can again sum the digits, until k==0.
- Optimization: lets say k = 10, but the sum is already reduced to single digit during 3rd
  iteration. Then we can skip the rest of the iteration, as the result will be the same.  
- Hence, we added the condition (sum > 9) in the while loop.

*/

/*

1945. Sum of Digits of String After Convert

You are given a string s consisting of lowercase English letters, and an integer k.
First, convert s into an integer by replacing each letter with its position in the
alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). Then, transform the
integer by replacing it with the sum of its digits. Repeat the transform operation k times in total.

For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
Transform #2: 17 ➝ 1 + 7 ➝ 8
Return the resulting integer after performing the operations described above.

Example 1:

Input: s = "iiii", k = 1
Output: 36
Explanation: The operations are as follows:
- Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
Thus the resulting integer is 36.

Example 2:

Input: s = "leetcode", k = 2
Output: 6
Explanation: The operations are as follows:
- Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
- Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
- Transform #2: 33 ➝ 3 + 3 ➝ 6
Thus the resulting integer is 6.

Example 3:

Input: s = "zbax", k = 2
Output: 8

Constraints:

1 <= s.length <= 100
1 <= k <= 10
s consists of lowercase English letters.

*/

/*
************* Java Code **************

    public static int getLucky(String s, int k) {
        int n = s.length();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int num = s.charAt(i) - 'a' + 1;
            if (num > 19)
                sum = sum + 2 + (num % 10);
            else if (num > 9)
                sum = sum + 1 + (num % 10);
            else
                sum += num;
        }
        k--;
        while (k > 0 && sum > 9) {
            int temp = sum;
            sum = 0;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            k--;
        }
        return sum;
    }

*/