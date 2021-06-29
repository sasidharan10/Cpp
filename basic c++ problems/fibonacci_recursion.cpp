#include<iostream>
using namespace std;
int fib(int x)
{
    if(x<=1)
        return x;
    else
        return fib(x-1)+fib(x-2);
}
int main()
{
    int x,n;
    cout<<"Enter the length of the fibonacci series : "<<endl;
    cin>>x;
    cout<<fib(x);
    return 0;
}