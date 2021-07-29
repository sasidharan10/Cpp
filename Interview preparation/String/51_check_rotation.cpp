#include<iostream>
#include<algorithm>
#include<String>
using namespace std;
bool checkRotation(string s1,string s2)
{
    // Time : O(n)
    // Space : O(2n)

    if (s1.length()!=s2.length())
        return false;
    
    string temp=s1+s1;
    if(temp.find(s2)!=string::npos)
        return true;
    else
        return false;
    
}
int main()
{
    string s1="ABCD";
    string s2="CDAB";
    string s3="ACBD";
    cout<<"Rotated : "<<checkRotation(s1,s2)<<endl;
    cout<<"Rotated : "<<checkRotation(s1,s3)<<endl;
}   
