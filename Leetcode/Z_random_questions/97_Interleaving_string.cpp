#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isInterleave(string s1, string s2, string s3) {
    if((s1.length()+s2.length())!=s3.length())
        return 0;
    for (int i = 0; i < s3.length(); i++)
    {
        // if(s3.find())
    }
    
}

int main()
{
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    // string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
    cout<<"Interleaving string?: "<<isInterleave(s1,s2,s3);
    return 0;
}