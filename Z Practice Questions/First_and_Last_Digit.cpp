#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t,a; 
    cin>>t;
    while(t--)
    {
        cin>>a;
        int rem,sum=0;
        rem=a%10;
        while(a>=10)
            a/=10;
        sum=rem+a;
        cout<<sum<<endl;
    }
	return 0;
}