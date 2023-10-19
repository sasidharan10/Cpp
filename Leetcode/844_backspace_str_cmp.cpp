#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        string s1 = "", t1 = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#' && s1.empty())
            {
                continue;
            }
            else if (s[i] == '#')
            {
                s1.pop_back();
            }
            else
                s1 += s[i];
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == '#' && t1.empty())
            {
                continue;
            }
            else if (t[i] == '#')
            {
                t1.pop_back();
            }
            else
                t1 += t[i];
        }
        cout << s1 << " " << t1 << endl;
        return s1 == t1;
    }
};
int main()
{
    Solution s;
    string str = "ab#c", t = "ad#c";
    // string str = "ab##", t = "c#d#";
    cout << "String are same?: " << s.backspaceCompare(str, t);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/backspace-string-compare

Youtube:

algorithm:

*/