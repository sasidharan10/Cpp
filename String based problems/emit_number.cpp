#include<iostream>
using namespace std;
int main()
{
    char a[] = "fl42o!or g5a@ng42 ao45o#o0u9uhh";
    int n = sizeof(a) / sizeof(a[0]);
    int i=0,j=0;
    cout<<"The string is : ";
    // while(a[i]!='\0')
    // {
    //     if(a[i]>=48 && a[i]<=57)
    //     {
    //         i++;
    //         continue;
    //     }
    //     cout<<a[i];
    //     i++;
    // }
    for(i=0;a[i]!='\0';i++)
    {
        if(!(a[i]>='A' && a[i]<='Z' || a[i]>='a' && a[i]<='z'))
        {
            for(j=i;a[j]!='\0';j++)
            {
                a[j]=a[j+1];
            }
            --i;
            a[j]='\0';
        }
    }
    cout<<a;
    return 0;
}


// 17) a[i]!='\0'