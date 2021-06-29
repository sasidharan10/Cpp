#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int n=16789;
    while (n >= 10)
    {
                n /= 10;
    }
    cout<<n;
}