#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
void calc(int i,int n,int k,int x,int y,unordered_set<int> &s)
{
    int t=abs(k-i);
    int res=(t*x-(n-t)*y) + (i*x-(n-i)*y);
    if(s.find(res)==s.end())
        s.insert(res);
    return;
}
int main()
{
    int n=3,x=1,y=1,z=3;
    int count=0;
    int j=0;
    unordered_set<int> s;
    for (int i = 1,j=i+1; i <= n && j<=n; i++)
    {
        int k=n-i+j;
        calc(i,n,k,x,y,s);
        calc(n-i,n,k,x,y,s);
    }
    for (auto i : s)
        cout<<i<<" ";
    cout<<endl;
    cout<<s.size();
    return 0;
}
