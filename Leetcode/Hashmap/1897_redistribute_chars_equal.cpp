#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int n = words.size();
        vector<int> mp(26, 0);
        for (int i = 0; i < n; i++)
        {
            for (char it : words[i])
            {
                mp[it - 'a']++;
            }
        }
        for (int it : mp)
        {
            if (it % n != 0)
                return false;
        }
        return true;
    }
};
int main()
{
    Solution s;
    vector<string> nums{"abc", "aabc", "bc"};
    // vector<string> nums{"ab","a"};
    cout << "Result: " << s.makeEqual(nums) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal

Youtube:

algorithm:

- Use a map, get count all chars occurences.
- Check if each chars (count % n == 0).
- If not, return "false", else return "true".
- Since every characters should be equally divided among the 'n' words in the array,
  to make every word equal.
*/

/*

1897. Redistribute Characters to Make All Strings Equal

You are given an array of strings words (0-indexed).

In one operation, pick two distinct indices i and j, where words[i] is a 
non-empty string, and move any character from words[i] to any position in words[j].

Return true if you can make every string in words equal using any number 
of operations, and false otherwise.

Example 1:

Input: words = ["abc","aabc","bc"]
Output: true
Explanation: Move the first 'a' in words[1] to the front of words[2],
to make words[1] = "abc" and words[2] = "abc".
All the strings are now equal to "abc", so return true.

Example 2:

Input: words = ["ab","a"]
Output: false
Explanation: It is impossible to make all the strings equal using the operation.

*/