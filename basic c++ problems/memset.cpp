#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
int main()
{
    int arr[10];
    memset(arr,0,sizeof(arr));  // works only for 0,-1 .
    cout<<"Array  : ";
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"String : ";
    string str="abcdefghijk";     // good for initialising strings and char array
    memset(&str[0]+3,'0',5*sizeof(str[0]));
    cout<<str;
    return 0;
}