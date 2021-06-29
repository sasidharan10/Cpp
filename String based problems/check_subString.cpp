#include<iostream>
using namespace std;
int main()
{
    char a[]="floor gang aooouuhh";
    char b[]="gang";
    int flag=0;
    cout<<""<<endl;
    int l1 = sizeof(a) / sizeof(a[0]);
    int l2 = sizeof(b) / sizeof(b[0]);
    for (int i = 0; i <= l1-l2; i++)   // l1-l2 because no need to go till end of the string.
    {
        for (int j = 0; j < l2; j++)
        {
            if(a[i+j]!=b[j])  // checking the substring in every index
                break;
            if(j==l2)
                flag=1;
        }   
    }
    if(flag==0)
        cout<<"Substing is present";
    else
        cout<<"Substing is NOT present!!!";
    return 0;
}

//  15) C Programming: Replace lowercase characters by uppercase and vice-versa