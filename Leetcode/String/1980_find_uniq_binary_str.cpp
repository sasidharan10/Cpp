#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Better
    string findDifferentBinaryString2(vector<string> &nums)
    {
        unordered_set<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int temp = stoi(nums[i], 0, 2);
            st.insert(temp);
        }
        string res = "";
        for (int number = 0; number <= n; number++)
        {
            if (st.find(number) == st.end())
            {
                res = bitset<16>(number).to_string();
                return res.substr(16 - n, n);
            }
        }
        return "";
    }
    // Optimal using Cantor's diagonal argument
    string findDifferentBinaryString(vector<string> &nums)
    {
        string res = "";
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            char ch = nums[i][i];
            res += ch == '0' ? '1' : '0';
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<string> nums = {"111", "011", "001"};
    cout << "Unique Binary String: " << s.findDifferentBinaryString(nums) << endl;
    return 0;
}

/*

link:

leetcode:

Youtube:

algorithm:

- we go through every bit number, and add inverted number to the result, so that,
  the result is different from every number in the array
*/