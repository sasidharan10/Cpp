#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long n = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int temp = s[i] - '0';
            if (isdigit(s[i]))
            {
                n *= temp;
            }
            else
                n += 1;
        }
        string res = "";
        for (int i = s.length() - 1; i >= 0; i--)
        {
            int temp = s[i] - '0';
            k %= n;
            if (k == 0 && isalpha(s[i]))
                return res += s[i];
            if (isdigit(s[i]))
            {
                n /= temp;
            }
            else
                n--;
        }
        return res;
    }
    string decodeAtIndexBf(string s, int k)
    {
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            int n = s[i] - '0';
            if (isdigit(s[i]) && n > 1)
            {
                string temp = res;
                for (int j = 0; j < n - 1; j++)
                {
                    res += temp;
                }
            }
            else
            {
                res += s[i];
            }
        }
        cout << res << endl;
        string t = "";
        t += res[k - 1];
        return t;
    }
};
int main()
{
    Solution s;
    string str = "leet2code3";
    int k = 10;
    cout << "ith element: " << s.decodeAtIndex(str, k) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/decoded-string-at-index

Youtube: https://www.youtube.com/watch?v=vmgVNV0u3pE&t=526s

algorithm:

*/