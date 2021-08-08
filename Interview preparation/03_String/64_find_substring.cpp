#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
void Search1(string txt, string pat)
{
    // Time : O(n*m)
    // Space : O(1)

    int n = txt.size();
    int m = pat.size();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (txt[j + i] != pat[j])
                break;
        }
        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}
void Search2(string txt, string pat)
{
    // Time : O(n*m)
    // Space : O(2n)

    int n = txt.size();
    int m = pat.size();
    vector<int> a(255, 0);
    vector<int> b(255, 0);
    int left = 0;
    int right = 0;
    while (right < m)
    {
        a[txt[right]]++;
        b[pat[right]]++;
        right++;
    }
    right--;
    while (right < n)
    {
        if (a == b)
            cout << "Pattern found at index " << left << endl;
        right++;
        if (right != n)
            a[txt[right]]++;
        a[txt[left]]--;
        left++;
    }
}
void Search3(string txt, string pat)
{
    // Rolling Hash

    // Time : O(n*m)
    // Space : O(1)

    int t = 0;
    int p = 0;
    int n = txt.length();
    int m = pat.length();
    for (int i = 0; i < m; i++)
    {
        p = p + (txt[i] - 'A');
        t = t + (pat[i] - 'A');
    }
    int j;
    for (int i = 0; i < n - m; i++)
    {
        if (t == p)
        {
            for (j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }
        if (i < n - m)
        {
            t = t - (txt[i] - 'A');
            t = t + (txt[i + m] - 'A');
        }
    }
}
void Search4(string txt, string key)
{
    // Rabin-Karp Algorithm

    // Time : O(n*m) (faster than rolling hash)
    // Space : O(1)

    int n = txt.length();
    int m = key.length();
    int d = 256;          // character range
    int p = 5381;        // prime number
    int h = 1;           // pow(d,m-1) used for eliminating the first character from the hash
    long long int k = 0; // hash for ket string
    long long int t = 0; // hash window of txt string
    // the first character
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % p;
    }
    for (int i = 0; i < m; i++)
    {
        t = (t * d + txt[i]) % p;
        k = (k * d + key[i]) % p;
    }
    int j;
    for (int i = 0; i < n - m; i++)
    {
        if (t == k)
        {
            for (j = 0; j < m; j++)
            {
                if (txt[i + j] != key[j])
                    break;
            }
            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }
        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % p;
            if (t < 0)
                t = (t + p);
        }
    }
}
int main()
{
    // char txt[] = "GEEKS FOR GEEKS";
    // char pat[] = "GEEK";
    string txt = "GEEKSFORGEEKS";
    string pat = "GEEK";
    // Function Call
    // Search1(txt, pat);
    // Search2(txt, pat);
    Search3(txt, pat);
    Search4(txt, pat);
    return 0;
}
