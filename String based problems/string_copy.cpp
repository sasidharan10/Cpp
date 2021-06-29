#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main()
{
    
    char a[20]="sasi dharan";
    char b[20];
    int i=0;
    // strcpy(b,a);
    while(a[i]!='\0')
    {
        b[i]=a[i];
        i++;
    }
    cout<<"Copied character : "<<b;
    cout<<"\nNo of character : "<<i;

}

// for string : 

// string a,b;
// cout<<"Enter a string"<<endl;
// getline(cin,a);
// b=a;
// cout<<"\n b : "<<b;