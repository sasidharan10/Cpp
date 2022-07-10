#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int romanToInt(string s)
{
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if ((i + 1 != s.length()) && (mp[s[i]] < mp[s[i + 1]]))
        {
            res -= mp[s[i]];
        }
        else
            res += mp[s[i]];
    }
    return res;
}
int main()
{
    string s = "MCMXCIV";
    cout << "Roman to Integer: " << romanToInt(s);
    return 0;
}