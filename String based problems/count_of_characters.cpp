#include<iostream>
using namespace std;
int main()
{
    char a[]="kos5vj49ki3scmpifhnvs4";
    int arr[127]={0};
    int i=0;
    cout<<"The count of each character is : "<<endl;
    while(a[i]!='\0')
    {
        arr[a[i]]++;
        i++;
    }
    i=0;
    while(a[i]!='\0')
    {
        cout<<a[i]<<" : "<<arr[a[i]]<<endl;
        i++;
    }
    return 0;
}

// 33) Count of each character in a given string