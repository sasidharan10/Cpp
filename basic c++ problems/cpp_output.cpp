#include<iostream>
#include<cstdio>    // for fgets()
#include<cstring>   // string.h in C lang
#include<string>    // to use string DS
using namespace std;
int main()
{
    int a;
    cout<<"Enter number: "<<endl;
    cin>>a;
    cout<<"Number: "<<a<<endl;
    // char b[30];
    cout<<"Enter string: "<<endl;
    string c;
    // cin>>b;                 // cin cannot take strings with spaces
	// gets(b);                // avoid it because it does not support buffer overflow()
	// fgets(b,sizeof(b),stdin);  // recommended
    // getline(cin,c);         // this fn is for string DS
    // printf("String b: %s",b);
    getline(cin,c);
    cout<<"String c: "<<c<<endl;
    return 0;
}

/*
- cerr in C++ is un-buffered so it is used when one needs to display the error message immediately.


*/