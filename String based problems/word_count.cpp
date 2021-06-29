#include<iostream>
using namespace std;
int main()
{
    char a[]="this is awesome bro";
    int i=0,word=1;
    while(a[i]!='\0')
    {
        if(a[i]==' ' || a[i]=='\t' || a[i]=='\n')
            word++;
        i++;
    }
    cout<<"Word count : "<<word;
    return 0;
}