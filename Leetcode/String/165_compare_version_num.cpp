#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // using string streams
    vector<string> getTokens(string version)
    {
        stringstream v(version);
        string token_v = "";
        vector<string> version_tokens;
        while (getline(v, token_v, '.'))
        {
            version_tokens.push_back(token_v);
        }
        return version_tokens;
    }
    int compareVersion2(string version1, string version2)
    {

        vector<string> v1 = getTokens(version1);
        vector<string> v2 = getTokens(version2);

        int m = v1.size();
        int n = v2.size();

        int i = 0;
        while (i < m || i < n)
        {

            int a = i < m ? stoi(v1[i]) : 0;
            int b = i < n ? stoi(v2[i]) : 0;

            if (a > b)
                return 1;
            else if (b > a)
                return -1;
            else
                i++;
        }
        return 0;
    }
    int compareVersion(string version1, string version2)
    {
        // TC: O(n+m)
        // SC: O(1)

        int n = version1.length();
        int m = version2.length();
        int i = 0, j = 0;
        char ch;
        while (i < n || j < m)
        {
            int val1 = 0, val2 = 0;
            while (i < n && version1[i] != '.')
            {
                ch = version1[i];
                val1 = val1 * 10 + (ch - 48);
                i++;
            }
            while (j < m && version2[j] != '.')
            {
                ch = version2[j];
                val2 = val2 * 10 + (ch - 48);
                j++;
            }
            // cout << "val1: " << val1 << ", val2: " << val2 << endl;
            if (val1 > val2)
                return 1;
            else if (val2 > val1)
                return -1;
            else
            {
                i++;
                j++;
            }
        }
        return 0;
    }
};
int main()
{
    Solution s;
    // string version1 = "1.01", version2 = "1.001";
    // string version1 = "0.1", version2 = "1.1";
    string version1 = "1.1.1.2", version2 = "1.1.2";
    cout << "Result: " << s.compareVersion(version1, version2) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/compare-version-numbers/

Youtube: https://www.youtube.com/watch?v=Mmy9hdPXwRc

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/strings/Compare%20Version%20Numbers.cpp

algorithm:

- Approach
-

*/

/*

165. Compare Version Numbers

Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision
consists of digits and may contain leading zeros. Every revision contains at least
one character. Revisions are 0-indexed from left to right, with the leftmost revision
being revision 0, the next revision being revision 1, and so on. For example 2.5.33
and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions
are compared using their integer value ignoring any leading zeros. This means that
revisions 1 and 001 are considered equal. If a version number does not specify a
revision at an index, then treat the revision as 0. For example, version 1.0 is
less than version 1.1 because their revision 0s are the same, but their revision
1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.

Example 1:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

Example 2:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: version1 does not specify revision 2, which means it is treated as "0".

Example 3:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Explanation: version1's revision 0 is "0", while version2's revision 0 is "1".
0 < 1, so version1 < version2.

*/

/*
************* Java Code **************

public static int compareVersion(String version1, String version2) {
        int n = version1.length();
        int m = version2.length();
        int i = 0, j = 0;
        char ch;
        while (i < n || j < m) {
            int val1 = 0, val2 = 0;
            while (i < n && version1.charAt(i) != '.') {
                ch = version1.charAt(i);
                val1 = val1 * 10 + (ch - 48);
                i++;
            }
            while (j < m && version2.charAt(j) != '.') {
                ch = version2.charAt(j);
                val2 = val2 * 10 + (ch - 48);
                j++;
            }
            if (val1 > val2)
                return 1;
            else if (val2 > val1)
                return -1;
            else {
                i++;
                j++;
            }
        }
        return 0;
    }

*/