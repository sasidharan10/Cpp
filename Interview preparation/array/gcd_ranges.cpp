#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int findGcd(int *a,int l,int r)
{
    int result=a[0];
    for (int i = l; i <= r; i++)
    {
        result=gcd(a[i],result);
        if(result==1)
            return 1;
    }
    return result;
}
int main()
{
    int a[]{20,40,60,80,10,5};
    int n = sizeof(a) / sizeof(a[0]);
    int r=2;
    for (int i = 0; i < n; i++)
    {
        if(n>r)
        {
            cout<<"GCD from index "<<i<<" to "<<r<<" : "<<findGcd(a,i,r)<<endl;
            r++;
        }
    }
    return 0;
}

// GCDs of given index ranges in an array