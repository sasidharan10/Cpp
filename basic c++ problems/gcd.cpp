#include <iostream>
using namespace std;
int gcd(int a,int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a>b)
        return gcd(a-b,b);
    else
        return gcd(a,b-a);
}
int main()
{
    // greatest common divisor or highest common factor
    int a=50,b=40;
    cout<<"GCD is : "<<gcd(a,b);
    return 0;
}