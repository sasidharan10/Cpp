#include<iostream>
using namespace std;
bool isPrime(int x)
{
    if(x==0 || x==1)
        return false;
    for(int i=2;i<=x/2;i++)
    {
        if(x%i==0)
        return false;
    }
    return true;
}
int main()
{
    int x;
    cout<<"Enter the number : "<<endl;
    cin>>x;
    if(isPrime(x))
    {
        cout<<"The number "<<x<<" is a prime number."<<endl;
    }
    else
        cout<<"The number "<<x<<" is NOT a prime number."<<endl;
        return 0;
}
