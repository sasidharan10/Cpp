#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseWords(string s, int k)
    {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k)
        {
            if (i + k <= n)
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else
            {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
    string reverseWords2(string s, int k)
    {
        int start = 0, n = s.length();
        int i = 0;
        while (i < n)
        {
            if (n - i > 2 * k)
            {
                reverse(s.begin() + start, s.begin() + start + k);
                i += 2 * k;
                start = i;
            }
            else if (n - i < 2 * k && n - i > k)
            {
                reverse(s.begin() + start, s.begin() + start + k);
                break;
            }
            else
            {
                reverse(s.begin() + start, s.end());
                break;
            }
        }
        return s;
    }
};
int main()
{
    Solution s;
    int k = 2;
    string str = "abcdefg";
    cout << "Reverse words in a string: " << s.reverseWords(str, k);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/reverse-string-ii/description/

Youtube:

algorithm:

*/