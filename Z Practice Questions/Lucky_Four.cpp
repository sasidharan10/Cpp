#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        int count=0,rem;
        while(a>0)
        {
            rem=a%10;
            if(rem==4)
                count++;
            a=a/10;
        }
        cout<<count<<endl;
    }
	return 0;
}

// count the no of 4s in each given number