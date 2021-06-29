#include<iostream>
using namespace std;
int main()
{
    char a[]="floor gang";
    char b[]=" aooouuuh";
    char c[30];
    int l1 = sizeof(a) / sizeof(a[0]);
    int l2 = sizeof(b) / sizeof(b[0]);
    int i=0,j=0;
    while(a[i]!='\0')
    {
        c[i]=a[i];
        i++;
    }
    while(b[j]!='\0')
    {
        c[i]=b[j];
        j++;
        i++;
    }
    c[i]='\0';
    cout<<"String is : "<<c;
    return 0;    
}

// 19) Concatenate Two Strings Manually