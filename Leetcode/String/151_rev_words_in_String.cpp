#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> arr;
        int st = 0, end = 0;
        string temp = "", ans = "";
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ' ')
            {
                temp = "";
                st = i;
                while (s[st] != ' ' && st < n)
                {
                    temp += s[st];
                    st++;
                }
                arr.push_back(temp);
                cout << temp << endl;
                i = st - 1;
            }
        }
        while (arr.size() > 1)
        {
            ans += arr.back();
            ans += ' ';
            arr.pop_back();
        }
        ans += arr.back();
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "a good   example";
    cout << "Reverse words in a string: " << s.reverseWords(str);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/reverse-words-in-a-string/

Youtube:

algorithm:

*/