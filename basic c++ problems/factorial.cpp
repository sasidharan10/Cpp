#include<iostream>
using namespace std;
int factorial(int x)
{
    if(x==0)
        return 1;
    else
        return x*factorial(x-1);
}
int main()
{
    int x;
    cout<<"Enter a number : "<<endl;
    cin>>x;
    cout<<factorial(x);
    return 0;
}