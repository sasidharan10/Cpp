#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int countHomogenous(string s)
    {
        // TC: O(n)
        // SC: O(1)
        
        long long len = 1;
        long long res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == s[i + 1])
            {
                len++;
                len = mod;
            }
            else
            {
                len = 1;
            }
            res = (res + len) % mod;
        }
        return res % mod;
    }
};
int main()
{
    Solution s;
    string str = "abbcccaa";
    cout << "No of Homogenous Substring: " << s.countHomogenous(str);
    return 0;
}

/*

link:
leetcode: https://leetcode.com/problems/count-number-of-homogenous-substrings

Youtube: https://www.youtube.com/watch?v=qEJR7ox0mNI

algorithm:

*/