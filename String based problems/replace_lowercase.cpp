#include<iostream>
#include<cctype>
using namespace std;
int main()
{
    char a[]="I am a GOOD35 Boy";
    // int n = sizeof(a) / sizeof(a[0]);
    int i=0;
    cout<<"\nThe string is : ";
    while(a[i]!='\0')
    {
        // easy method

        if(isupper(a[i]))
            a[i]=tolower(a[i]);
        else
            a[i]=toupper(a[i]);
        i++;
        
        // if(a[i]==' ')
        //     cout<<" ";
        // else if(a[i]>=65 && a[i]<=90)
        //     cout<<(char)(a[i]+32);
        // else if(a[i]>=97 && a[i]<=122)
        //     cout<<(char)(a[i]-32);
        // else
        //     cout<<a[i];
        // i++;

    }
    cout<<a;
    return 0;
}
