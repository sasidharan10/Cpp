#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int ind, int prev, int num, int n, int &res, vector<int> &mp, string pattern)
    {
        if (ind == n)
        {
            res = min(res, num);
            return;
        }
        if (pattern[ind] == 'I')
        {
            for (int i = prev + 1; i <= 9; i++)
            {
                if (mp[i] == 1)
                    continue;
                mp[i] = 1;
                int temp = num;
                temp = temp * 10 + i;
                solve(ind + 1, i, temp, n, res, mp, pattern);
                mp[i] = 0;
            }
        }
        else
        {
            for (int i = prev - 1; i >= 1; i--)
            {
                if (mp[i] == 1)
                    continue;
                mp[i] = 1;
                int temp = num;
                temp = temp * 10 + i;
                solve(ind + 1, i, temp, n, res, mp, pattern);
                mp[i] = 0;
            }
        }
    }
    // Brute - backtracking, finding all permutatinos
    string smallestNumber3(string pattern)
    {
        // TC: O(9!)
        // SC: O(n)

        int n = pattern.length();
        int res = INT_MAX;
        vector<int> mp(10, 0);
        for (int i = 1; i <= 9; i++)
        {
            mp[i] = 1;
            solve(0, i, i, n, res, mp, pattern);
            mp[i] = 0;
        }
        return to_string(res);
    }

    bool matchesPattern(string num, string pattern, int n)
    {
        for (int i = 1; i <= n; i++)
        {
            if ((pattern[i - 1] == 'I' && num[i - 1] > num[i]) || (pattern[i - 1] == 'D' && num[i - 1] < num[i]))
                return false;
        }
        return true;
    }
    // Brute force - finding all permutations
    string smallestNumber2(string pattern)
    {
        // TC: O(9!)
        // SC: O(n)

        int n = pattern.length();
        string num = "";
        for (int i = 1; i <= n + 1; i++)
        {
            num.push_back(i + '0');
        }
        while (!matchesPattern(num, pattern, n))
        {
            next_permutation(num.begin(), num.end());
        }
        return num;
    }

    // Optimal- Greedy - using stack
    string smallestNumber(string pattern)
    {
        // TC: O(n)
        // SC: O(n)

        int n = pattern.length();
        stack<char> st;
        int count = 1;
        string num = "";
        for (int i = 0; i <= n; i++)
        {
            st.push(count + '0');
            count++;
            if (i == n || pattern[i] == 'I')
            {
                while (!st.empty())
                {
                    num.push_back(st.top());
                    st.pop();
                }
            }
        }
        return num;
    }
};
int main()
{
    Solution s;
    string pattern = "IIIDIDDD";
    cout << "Result: " << s.smallestNumber(pattern) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/construct-smallest-number-from-di-string

Youtube: https://www.youtube.com/watch?v=rCjwDls-HPk

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/strings/Construct%20Smallest%20Number%20From%20DI%20String.cpp

algorithm:

- Brute Force Approach:

- backtracking

- Optimal Approach:

- refer video

*/

/*

2375. Construct Smallest Number From DI String

You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D'
meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.

Example 1:

Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.

Example 2:

Input: pattern = "DDD"
Output: "4321"
Explanation:
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.

Constraints:

1 <= pattern.length <= 8
pattern consists of only the letters 'I' and 'D'.

*/

/*
************* Java Code **************

    public static int res;
    public static void solve(int ind, int prev, int num, int n, int[] mp, String pattern)
    {
        if (ind == n)
        {
            res = Math.min(res, num);
            return;
        }
        if (pattern.charAt(ind) == 'I')
        {
            for (int i = prev + 1; i <= 9; i++)
            {
                if (mp[i] == 1)
                    continue;
                mp[i] = 1;
                int temp = num;
                temp = temp * 10 + i;
                solve(ind + 1, i, temp, n, mp, pattern);
                mp[i] = 0;
            }
        }
        else
        {
            for (int i = prev - 1; i >= 1; i--)
            {
                if (mp[i] == 1)
                    continue;
                mp[i] = 1;
                int temp = num;
                temp = temp * 10 + i;
                solve(ind + 1, i, temp, n, mp, pattern);
                mp[i] = 0;
            }
        }
    }

    // Brute - backtracking, finding all permutatinos
    public static String smallestNumber(String pattern)
    {
        // TC: O(9!)
        // SC: O(n)

        int n = pattern.length();
        res = Integer.MAX_VALUE;
        int[] mp = new int[10];
        for (int i = 1; i <= 9; i++)
        {
            mp[i] = 1;
            solve(0, i, i, n, mp, pattern);
            mp[i] = 0;
        }
        return Integer.toString(res);
    }

    // Optimal
    public static String smallestNumber(String pattern) {
        // TC: O(9!)
        // SC: O(n)

        int n = pattern.length();
        Stack<Character> st = new Stack<>();
        int count = 1;
        StringBuilder num = new StringBuilder();
        for (int i = 0; i <= n; i++) {
            st.push((char) (count + '0'));
            count++;
            if (i == n || pattern.charAt(i) == 'I') {
                while (!st.empty()) {
                    num.append(st.pop());
                }
            }
        }
        return num.toString();
    }

*/