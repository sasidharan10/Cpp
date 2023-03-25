#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(j<=n-i)
                cout<<"  ";
            else
                cout<<j-n+i<<" ";
        }
        for (int k = n; k >= 2; k--)
        {
            if(k<=i)
                cout<<k -1<<" ";
        }
        
        cout<<endl;
    }
    
    return 0;
}