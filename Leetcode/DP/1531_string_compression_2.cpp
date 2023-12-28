#include <bits/stdc++.h>
using namespace std;
int dp[101][27][101][101];
class Solution
{
public:
    int solve(string &s, int i, int prev_char, int freq, int k)
    {
        if (k < 0)
            return INT_MAX;
        if (i >= s.length())
            return 0;
        if (dp[i][prev_char][freq][k] != -1)
            return dp[i][prev_char][freq][k];
        // case 1:
        int delete_i = solve(s, i + 1, prev_char, freq, k - 1);
        int keep_i = 0;
        // case 2:
        if (s[i] - 'a' == prev_char)
        {
            int extra = 0;
            if (freq == 1 || freq == 9 || freq == 99)
            {
                extra = 1;
            }
            keep_i = extra + solve(s, i + 1, prev_char, freq + 1, k);
        }
        // case 3:
        else
        {
            keep_i = 1 + solve(s, i + 1, s[i] - 'a', 1, k);
        }
        return dp[i][prev_char][freq][k] = min(delete_i, keep_i);
    }
    int getLengthOfOptimalCompression(string s, int k)
    {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 26, 0, k);
    }
};
int main()
{
    Solution s;
    string str = "aaabcccd";
    int k = 2;
    cout << "Result: " << s.getLengthOfOptimalCompression(str, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/string-compression-ii

Youtube: https://www.youtube.com/watch?v=6rgO0obJG0k

algorithm:

- run length encoding (RLE) is a compression technique.
- "aabccc" can be compressed to "a2bc3".
- Our task is to remove 'k' elements from the string, such that the RLE length
  of that string is minimum.
- Hence, we need to try every ways, to remove k elements from the string, and 
  then calculate the RLE length.
- Using recursion, at every step, either we pick that character, or not.
- case 1: If not, then it means we are deleting that char from the string, hence
  k-1. The previous char will still remain the same, and its frequency also
  remain the same(as its previous character's freq).
- case 2: If we pick the current char and (s[i] - 'a' == prev_char), we increase
  the freq, prev char will not change. and if (freq == 1 || freq == 9 || freq == 99)
  which means the RLE will need 1 more char to represent the count, as the no of digits 
  are increased in this case. Or else, the no of chars will remain the same.
- case 3: If not equal, then the freq will change to 1, prev char will be current char
  and RLE + 1 because we get a new character.
- Now the first edge case will be if (k < 0), to eliminate non-valid answers, as we only
  need to remove k chars. Why not if (k == 0), because we might have removed k chars
  before traversing the whole array, so if (k == 0), means the recursion will stop
  there itself, hence we keep if (k < 0), so we can have k==0, and also traverse till
  till the last element. this case should be placed at first, or else invalid answers
  will be included.
- if (i >= s.length()), we go out of bound, means we completed that recursion tree, 
  hence, we return 0, and add previous recursion calls will add up with this 0, and
  finally the result will be returned.

*/

/*

1531. String Compression II

Run-length encoding is a string compression method that works by replacing 
consecutive identical characters (repeated 2 or more times) with the 
concatenation of the character and the number marking the count of the 
characters (length of the run). For example, to compress the string "aabccc" 
we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".

Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. You need to delete at most k characters 
from s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at most k characters.

Example 1:

Input: s = "aaabcccd", k = 2
Output: 4
Explanation: Compressing s without deleting anything will give us 
"a3bc3d" of length 6. Deleting any of the characters 'a' or 'c' 
would at most decrease the length of the compressed string to 5, 
for instance delete 2 'a' then we will have s = "abcccd" which 
compressed is abc3d. Therefore, the optimal way is to delete 'b' 
and 'd', then the compressed version of s will be "a3c3" of length 4.

Example 2:

Input: s = "aabbaa", k = 2
Output: 2
Explanation: If we delete both 'b' characters, the resulting 
compressed string would be "a4" of length 2.

Example 3:

Input: s = "aaaaaaaaaaa", k = 0
Output: 3
Explanation: Since k is zero, we cannot delete anything. 
The compressed string is "a11" of length 3.



*/