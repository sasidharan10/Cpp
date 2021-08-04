#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void kmpAlgo(string txt, string pat, int *lps)
{
    int n = txt.length();
    int m = pat.length();
    // int *lps = new int[m]{0};
    // int lps[m]{0};
    int len = 0;
    int i = 1;
    // computing lps
    while (i < m)
    {
        if (pat[len] == pat[i])
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
    // finding pattern in string
    i = 0;
    int j = 0;
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == m)
        {
            cout << "Pattern found at index : " << i - j << endl;
            j = lps[j - 1];
        }
    }
    // delete[] lps;
}
int main()
{
    string txt = "abcafhabcabgjdgabcab";
    string pat = "abcab";
    int lps[5]{0};
    kmpAlgo(txt, pat, lps);
    return 0;
}