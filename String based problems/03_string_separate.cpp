#include<iostream>
#include<stdio.h>
using namespace std;
void separate(char *a)
{
    int i=0;
    while(a[i]!='\0')
    {
        cout<<a[i]<<" ";
        i++;
    }
}
int main()
{
    char a[50];
    cout<<"Enter a string : "<<endl;
    // int n = sizeof(a)/sizeof(a[0]);
    fgets(a,sizeof(a),stdin);
    separate(a);
}


/*

Write a program in C to separate the individual characters from a string.

Input the string : w3resource.com

Expected Output :

The characters of the string are : 
w  3  r  e  s  o  u  r  c  e  .  c  o  m 

*/