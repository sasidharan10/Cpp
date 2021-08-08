#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool validShuffle1(string a, string b)
{
    // Time : O(n)
    // Space : O(2n)

    vector<int> hash1(26, 0);
    vector<int> hash2(26, 0);
    int n = a.length();
    int m = b.length();
    if (n > m)
        return false;
    int left = 0;
    int right = 0;
    while (right < n)
    {
        hash1[a[right] - 'a']++;
        hash2[b[right] - 'a']++;
        right++;
    }
    right--;
    while (right < m)
    {
        if (hash1 == hash2)
            return true;
        right++;
        if (right != m)
            hash2[b[right] - 'a']++;
        hash2[b[left] - 'a']--;
        left++;
    }
    return false;
}
bool validShuffle2(string a, string b)
{
    // Time : O(n)
    // Space : O(2n)
    vector<int> hash1(255, 0);
    vector<int> hash2(255, 0);
    int n = a.length();
    int m = b.length();
    if (n > m)
        return false;
    int left = 0;
    int right = 0;
    while (right < n)
    {
        hash1[a[right]]++;
        hash2[b[right]]++;
        right++;
    }
    right--;
    while (right < m)
    {
        if (hash1 == hash2)
            return true;
        right++;
        if (right != m)
            hash2[b[right]]++;
        hash2[b[left]]--;
        left++;
    }
    return false;
}
int main()
{
    string str1 = "geekforgeeks";
    string str2 = "ekegorfkeegsgeek";
    cout << "Valid : " << validShuffle1(str1, str2) << endl;
    cout << "Valid : " << validShuffle2(str1, str2) << endl;
    return 0;
}