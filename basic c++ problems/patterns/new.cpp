#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n=5;
    int count=1;
    for (int i = 0; i < n; i++) 
    {
        for (int j = n; j >= 1; j--)
        {
            if(j>n-i)
                cout<<"  ";
            else
                cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}