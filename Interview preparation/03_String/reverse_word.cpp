#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string s="Have a nice day ";
    reverse(s.begin(),s.end());
    cout<<"String : "<<s<<endl;
    string ::iterator st,e;
    st=s.begin();
    for (auto i=s.begin(); i!=s.end(); i++)
    {
        if(*i==' ')
        {
            reverse(st,i);
            st=i+1;
        }
        if(i+1==s.end())
        {
            reverse(st,i+1);
            st=i+1;
        }
    }
    cout<<"String : "<<s<<endl;
}