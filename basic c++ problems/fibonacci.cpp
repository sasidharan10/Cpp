#include<iostream>
using namespace std;
int main()
{
    int x,a=0,b=1,c=0;;
    cout<<"Enter the length of the fibonacci series : "<<endl;
    cin>>x;
    cout<<"The fibonacci series is : "<<endl;
    for(int i=0;i<x;i++)
    {
        cout<<a<<" ";
        c=a+b;
        a=b;
        b=c;
    }
    // cout<<a;
}
