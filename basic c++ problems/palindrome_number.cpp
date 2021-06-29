#include<iostream>
using namespace std;
int main()
{
    int x,sum=0,rem=0;
    cout<<"Enter a number : "<<endl;
    cin>>x;
    while(x>0)
    {
        rem=x%10;
        
        sum=sum*10+rem;
        x=x/10;
    }
    cout<<"Palindrome is : "<<sum<<endl;
    return 0;
}