#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int longestPrefixSuffix(string str)
{
    int n = str.length();
    int len = 0;
    int i = 1;
    int *lps = new int[n];
    while (i < n)
    {
        if (str[len] == str[i])
        {
            lps[i] = len + 1;
            len++;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    int res = lps[n - 1];
    return len;
    // return len > n / 2 ? ceil((float)len / 2) : len;  // without overlapping
    delete[] lps;
}
int main()
{
    string str = "abckgjogabjfgjabc";
    // string str = "aaaa";
    cout << "Length of Longest Prefix Suffix : " << longestPrefixSuffix(str) << endl;
    return 0;
}