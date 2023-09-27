#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> lastIndex(26, 0);
        vector<bool> seen(26, false);
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            lastIndex[s[i] - 'a'] = i;
        }
        // st.push(s[0]);
        for (int i = 0; i < s.length(); i++)
        {
            int cur = s[i] - 'a';
            if (seen[cur])
                continue;
            if (!st.empty() && st.top() > s[i] && i < lastIndex[st.top() - 'a'])
            {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[cur] = true;
        }
        string res = "";
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main()
{
    Solution s;
    string str = "cbacdcbc";
    cout << "Resultant string: " << s.removeDuplicateLetters(str) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

*/