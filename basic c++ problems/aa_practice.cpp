#include<iostream>
#include<algorithm>
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
int assemblyline(int N,int A[])
{
    int result=-404;
    result=0;
    int *b=new int[N];
    for (int i = 0; i < N; i++)
    {
        b[i]=A[i];
    }
    int f=0;
    sort(b,b+N);
    for (int i = 0; i < N; i++)
    {
        if(A[i]==b[i])
        {
            result++;
            f=1;
        }
    }
    if(f==0)
        result=-404;
    return result;
    
}
int main()
{
    int n;
    cin>>n;
    vector<int> ans;
    ans=fibonacci(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}