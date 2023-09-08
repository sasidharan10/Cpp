#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseWords(string S)
    {
        // TC: O(n)
        // SC: O(n)

        string ans = "", temp = "";
        for (int i = S.length() - 1; i >= 0; i--)
        {
            if (S[i] == '.')
            {
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans.push_back('.');
                temp = "";
            }
            else
            {
                temp += S[i];
            }
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};
int main()
{
    Solution s;
    string str = "i.like.this.program.very.much";
    cout << "Reverse words: " << s.reverseWords(str) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

leetcode:

Youtube:

algorithm:

*/