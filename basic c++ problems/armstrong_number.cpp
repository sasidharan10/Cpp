#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int x,temp,sum=0,rem=0;
    cout<<"Enter a number : "<<endl;
    cin>>x;
    temp=x;
    while(temp>0)
    {
        rem=temp%10;
        sum=sum+(rem*rem*rem);
        // sum=sum+pow(rem,3);   // not working
        temp=temp/10;
    }
    if(x==sum)
        cout<<"It is an armstrong number"<<endl;
    else
        cout<<"It is NOT an armstrong number"<<endl;
    // cout<<pow(2,3);
    return 0;
}

