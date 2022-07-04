#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n=5;
    int count=1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if(j>n-i+1)
                cout<<"  ";
            else
                cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}