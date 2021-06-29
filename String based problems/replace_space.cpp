#include<iostream>
using namespace std;
int main()
{
    char a[]="floor gang aaoouuhh";
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        if(a[i]==' ')
            a[i]='*';
    }
    cout<<"The string is : "<<a;
    return 0;  
}

// 25) Replace the spaces of a string with a specific character