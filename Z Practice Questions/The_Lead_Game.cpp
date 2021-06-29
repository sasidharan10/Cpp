#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,a,b,w=0,max=0,temp=0;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a>b)
        {
            temp=a-b;
            if(temp>max)
            {
                max=temp;
                w=1;
            }
        }
        else
        {
           temp=b-a;
            if(temp>max)
            {
                max=temp;
                w=2;
            }
        }
    }
    if(w==1)
        cout<<w<<" "<<max<<endl;
    else
        cout<<w<<" "<<max<<endl;
	return 0;
}
