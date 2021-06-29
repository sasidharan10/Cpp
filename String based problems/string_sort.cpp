#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char a[][10]={"sasi","bishnoi","axar"};
    char temp[10];
    int flag=0;
    int n = sizeof(a) / sizeof(a[0]);
    cout<<n<<endl;
    // bubble sort
    for (int i = 0; i < n-1; i++)
    {
        flag=0;
        for (int j = 0; j < n-i-1; j++)
        {
            if(strcmp(a[j],a[j+1])>0)
            {
                strcpy(temp,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],temp);
                flag=1;
            }   
        }
        if(flag==0)
            break;
    }
    for (int i = 0; i < n; i++)
    {   
        cout<<a[i]<<endl;
    }
    
}