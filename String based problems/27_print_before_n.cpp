#include<iostream>
using namespace std;
int main()
{
    char a[]="this \tis \n(good)";
    int i=0;
    cout<<"string is : ";  // counts . , () [] etc
    while(a[i]!='\0')
    {
        if(a[i]!='\n')
            cout<<a[i];
        else
            break;
        i++;
    }
    return 0;
}

/*

Write a program in C to print only the string before new line character. Go to the editor

Note: isprint() will only print line one, because the newline character is not printable.

Expected Output :

The quick brown fox

*/