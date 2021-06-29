#include<iostream>
using namespace std;
int main()
{
    char a[]="this. is, (good)";
    int count=0,i=0;
    while(a[i]!='\0')
    {
        if(ispunct(a[i]))
            count++;
        i++;
    }
    cout<<"Count is : "<<count;  // counts . , () [] etc
    return 0;
}

// 26) Count the number of punctuation characters exists in a string