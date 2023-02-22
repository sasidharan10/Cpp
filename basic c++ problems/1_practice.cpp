#include<iostream>
using namespace std;
int main()
{
    int a=153,b=0;
    b=a;
    int sum=0,n=0;
    while(a>0)
    {
        n=a%10;
        a=a/10;
        sum=sum+n*n*n;
    }
    cout<<"Sum: "<<sum<<endl;
    if(sum==b)
    {
        cout<<"It is armstrong number!!!"<<endl;
    }
    else
        cout<<"NOT!!!"<<endl;
    return 0;
}