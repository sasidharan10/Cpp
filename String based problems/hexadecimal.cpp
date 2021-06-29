#include<iostream>
#include<cctype>
using namespace std;
int main()
{
    char a;
    cout<<"Enter a digit : ";
    cin>>a;
    if(isxdigit(a))
        cout<<"\nIt is hexadecimal";
    else
        cout<<"\nIt is NOT hexadecimal";
    return 0;
}

// 21) Check whether a character is Hexadecimal Digit or not