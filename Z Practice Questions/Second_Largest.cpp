#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,b,c,max=0;
    int a[3];
    cin>>t;
    while (t--)
    {
        for (int i = 0; i < 3; i++)
        {
            cin>>a[i];
        }
        sort(a,a+3);
        cout<<a[1]<<endl;        
    }
	return 0;
}
