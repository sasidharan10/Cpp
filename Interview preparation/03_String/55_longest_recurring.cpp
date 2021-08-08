#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;
string longestSubSeq(string str)
{
    unordered_map<char,int>m;
    int maxCount=0;
    string res="";
    for (int i = 0; i < str.length(); i++)
    {
        m[str[i]]++;
        maxCount=max(maxCount,m[str[i]]);
    }
    unordered_map<char,int>::iterator it;
    for (it=m.begin();it!=m.end();it++)
    {
        if(it->second==maxCount)
            res+=it->first;
    }
    return res;
}
int main()
{
    // string str = "aabb";
    string str = "aabebcdd";
    cout << "largest subsequence : "<< longestSubSeq(str);
    return 0;
}