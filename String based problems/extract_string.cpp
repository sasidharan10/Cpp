#include<iostream>
using namespace std;
int main()
{
    char a[]="floor gang aoooh";
    int x,len,i=0;
    cout<<"String is : "<<a;
    int n = sizeof(a) / sizeof(a[0]);
    cout<<"\nEnter the index : ";
    cin>>x;
    cout<<"Enter the lenght : "<<endl;
    cin>>len;
    cout<<"String is : ";
    while(x<len)
    {
        cout<<a[x];
        x++;
    }
}