#include<iostream>
#include<vector>
using namespace std;
vector<int> fibonacci(int x)
{
    vector<int> ans;
    int a=0,b=1,c=0;;
    for(int i=0;i<x;i++)
    {
        ans.push_back(a);
        c=a+b;
        a=b;
        b=c;
    }
    return ans;
}
int main()
{
    int x;
    cin>>x;
    vector<int> ans;
    ans=fibonacci(x);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}