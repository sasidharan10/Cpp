#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<int, bool> mem;
bool solve1(string s, int pos, unordered_set<string> dc)
{
    if (pos == s.size())
        return true;
    for (int i = pos; i < s.size(); i++)
    {
        if (dc.find(s.substr(pos, i - pos + 1)) != dc.end() && solve1(s, i + 1, dc))
            return true;
    }
    return false;
}
bool solve2(string s, int pos, unordered_set<string> dc)
{
    if (mem.count(pos))
        return mem[pos];
    for (int i = pos; i < s.size(); i++)
    {
        if (dc.find(s.substr(pos, i - pos + 1)) != dc.end() && solve1(s, i + 1, dc))
            return mem[pos] = true;
    }
    return mem[pos] = false;
}
bool solve3(string s, unordered_set<string> dc)
{
    int n = s.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    for (int length = 1; length <= n; length++)
    {
        int start = 1;
        int end = length;
        // Sliding window
        while (end <= n)
        {
            if (dc.find(s.substr(start - 1, length)) != dc.end())
                dp[start][end] = true;
            else
            {
                bool flag = false;
                for (int i = start; i < end; i++)
                {
                    if (dp[start][i] && dp[i + 1][end])
                    {
                        flag = true;
                        break;
                    }
                }
                dp[start][end] = flag;
            }
            start += 1;
            end += 1;
        }
    }
    cout << "\n DP : " << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return dp[1][n];
}
bool wordBreak(string s, vector<string> dict)
{
    unordered_set<string> dc;
    for (auto i : dict)
        dc.insert(i);
    // return solve1(s, 0, dc);
    // return solve2(s, 0, dc);
    return solve3(s, dc);
}
int main()
{
    // vector<string> dict{"my", "pen"};
    vector<string> dict{"i", "like", "sam", "sung", "samsung", "mobile", "ice",
                        "cream", "icecream", "man", "go", "mango"};
    // string s = "mypenmy";
    string s = "ilikesamsung";
    if (wordBreak(s, dict))
        cout << "Word can be Formed" << endl;
    else
        cout << "Word cannot be Formed" << endl;
    return 0;
}