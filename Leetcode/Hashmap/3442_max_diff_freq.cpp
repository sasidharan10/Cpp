#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDifference(string s)
    {
        int n = s.length();
        vector<int> mp(26, 0);
        for (int i = 0; i < n; i++)
        {
            mp[s[i] - 'a']++;
        }
        int maxOddFreq = 0;
        int minEvenFreq = INT_MAX;
        for (int it : mp)
        {
            if (it % 2 == 0 && it != 0)
            {
                if (it <= minEvenFreq)
                    minEvenFreq = it;
            }
            else
            {
                if (it >= maxOddFreq)
                    maxOddFreq = it;
            }
        }
        return maxOddFreq - minEvenFreq;
    }
};
int main()
{
    Solution s;
    string str = "aaaaabbc";
    cout << "Result: " << s.maxDifference(str) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i

Youtube: https://www.youtube.com/watch?v=cpoRrOk03ME

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Leetcode%20Easy/Maximum%20Difference%20Between%20Even%20and%20Odd%20Frequency%20I.cpp

algorithm:

- Optimal Approach:

- using map

*/

/*

3442. Maximum Difference Between Even and Odd Frequency I

You are given a string s consisting of lowercase English letters.
Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of
characters a1 and a2 in the string such that:

a1 has an odd frequency in the string.
a2 has an even frequency in the string.
Return this maximum difference.

Example 1:

Input: s = "aaaaabbc"
Output: 3

Explanation:

The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
The maximum difference is 5 - 2 = 3.

Example 2:

Input: s = "abcabcab"
Output: 1

Explanation:

The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
The maximum difference is 3 - 2 = 1.


Constraints:

3 <= s.length <= 100
s consists only of lowercase English letters.
s contains at least one character with an odd frequency and one with an even frequency.


*/

/*
************* Java Code **************

    public int maxDifference(String s) {
        int n = s.length();
        int[] mp = new int[26];
        for (int i = 0; i < n; i++) {
            int val = s.charAt(i) - 'a';
            mp[val]++;
        }
        int maxOddFreq = 0;
        int minEvenFreq = Integer.MAX_VALUE;
        for (int it : mp) {
            if (it % 2 == 0 && it != 0) {
                if (it <= minEvenFreq)
                    minEvenFreq = it;
            } else {
                if (it >= maxOddFreq)
                    maxOddFreq = it;
            }
        }
        return maxOddFreq - minEvenFreq;
    }

*/