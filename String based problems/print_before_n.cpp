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

// 27) Print only the string before new line character