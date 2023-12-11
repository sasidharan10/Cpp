#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int start, int end, string &word, int k)
    {
        // TC: O(n*26*n) ~ O(n^2)
        // SC: O(26)

        int len = end - start + 1;
        int res = 0;
        // case: 1
        for (int chars = 1; chars <= 26 && chars * k <= len; chars++)
        {
            vector<int> mp(26, 0);
            int goodChars = 0;
            int windowLength = chars * k;
            int i = start;
            // case: 2
            for (int j = start; j <= end; j++)
            {
                int ch = word[j] - 'a';
                mp[ch]++;
                // case: 3
                if (mp[ch] == k)
                {
                    goodChars++;
                }
                else if (mp[ch] == k + 1)
                {
                    goodChars--;
                }

                // checking if it exceeds window length
                // if yes, we slide the window to right by 1
                // case: 4
                if (j - i + 1 > windowLength)
                {
                    ch = word[i] - 'a';
                    if (mp[ch] == k)
                    {
                        goodChars--;
                    }
                    else if (mp[ch] == k + 1)
                    {
                        goodChars++;
                    }
                    mp[ch]--;
                    i++;
                }

                // case: 5
                if (goodChars == chars)
                {
                    res++;
                }
            }
        }
        return res;
    }
    int countCompleteSubstrings(string word, int k)
    {
        int n = word.length();
        int last = 0;
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == n || abs(word[i - 1] - word[i]) > 2)
            {
                res += solve(last, i - 1, word, k);
                last = i;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    string str = "igigee";
    int k = 2;
    cout << "Count Complete Substrings: " << s.countCompleteSubstrings(str, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-complete-substrings/description/

Youtube: https://www.youtube.com/watch?v=ygPMLjxaT2Y

algorithm:

- to satisfy 2nd condition, (i.e., The difference between two adjacent
  characters in a substring is at most 2), we can break the given strings into
substrings, that will satisfy the condition.
- Then we calculate the no of substrings that can be formed, and return the result.
- case 1: We check the substring of all lengths, from 1 to length of that substring
  and check if it satisfies the conditions, hence we have the first loop, and we also
  ensure. the length doesn't go beyond "len".
- case 2: we canculate the window length, and loop through that substring.
- case 3: For each char we visit, we increase its frequency, and check if its count = k.
  If yes, then we increase goodChars++. if it exceeds k, then we decrease goodChars--.
- case 4: we check if the current window exceeeds the window length, if yes, then we
  need to slide the window towards right, hence we decrease count of word[i]--
  also, update its "goodChars" value based on the change.
- case 5: Finally we check if goodChars count == chars, if yes, then its a substring
  hence we increase the count.
  
*/

/*

2953. Count Complete Substrings

You are given a string word and an integer k.

A substring s of word is complete if:

Each character in s occurs exactly k times.
The difference between two adjacent characters is at most 2. That is, for any two
adjacent characters c1 and c2 in s, the absolute difference in their positions
in the alphabet is at most 2.
Return the number of complete substrings of word.

A substring is a non-empty contiguous sequence of characters in a string.

Example 1:

Input: word = "igigee", k = 2
Output: 3
Explanation: The complete substrings where each character appears exactly
twice and the difference between adjacent characters is at most 2 are: igigee, igigee, igigee.
Example 2:

Input: word = "aaabbbccc", k = 3
Output: 6
Explanation: The complete substrings where each character appears exactly
three times and the difference between adjacent characters is
at most 2 are: aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc.

*/
