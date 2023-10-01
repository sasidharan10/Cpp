#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]==' ')
            {
                reverse(s.begin() + start, s.begin() + (i));
                start = i+1;
            }
        }
        reverse(s.begin() + start, s.end());
        return s;
    }
};
int main()
{
    Solution s;
    string str = "Let's take LeetCode contest";
    cout << "Reverse words in a string: " << s.reverseWords(str);
    return 0;
}

/*

link: 

leetcode: https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

Youtube: 

algorithm: 

*/