#include<iostream>
#include<cstdio>
using namespace std;
void rev_sep(char *a,int n)
{
    int i=n;
    for(int i=n-1;i>=0;i--)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    char a[50];
    int i=0,n=0;
    cout<<"Enter a string"<<endl;
    fgets(a,sizeof(a),stdin);
    while(a[i]!='\0')
    {
        n++;
        i++;
    }
    // n=strlen(a);
    rev_sep(a,n);
}