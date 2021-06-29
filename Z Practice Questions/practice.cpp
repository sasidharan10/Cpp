#include <iostream>
#include <math.h>
#include <cctype>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,a,b; 
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a>b)
            cout<<a<<" "<<a+b<<endl;
        else
            cout<<b<<" "<<a+b<<endl;
    }
	return 0;
}
