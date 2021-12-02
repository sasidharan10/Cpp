#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main()
{
    string input;
    cout<<"enter password : ";
    cin>>input;
    int len=input.length();
    int lw=0,up=0,sp=0,dg=0;
    for (int i = 0; i < len; i++)
    {
        if(input[i]>=65 && input[i]<=90)
            up=1;
        else if(input[i]>=97 && input[i]<=122)
            lw=1;
        else if(input[i]>=48 && input[i]<=57)
            dg=1;
        else
            sp=1;
    }
    if(lw && up && dg && sp && len>=8)
        cout<<"Password is Strong"<<endl;
    else
        cout<<"Password is Weak"<<endl;
    return 0;
}