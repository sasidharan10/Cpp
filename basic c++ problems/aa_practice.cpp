#include<iostream>
#include<algorithm>
using namespace std;
void assemblyLine(int A[],int N)
{
    int result=-404;
    result=0;
    int b[N];
    for (int i = 0; i < N; i++)
    {
        b[i]=A[i];
    }
    int f=0;
    sort(b,b+N);
    for (int i = 0; i < N; i++)
    {
        if(A[i]!=b[i])
        {
            cout<<i<<" ";
            f=1;
        }
    }
    if(f==0)
    {
        cout<<result;
    }

}
int main()
{
    int N,i;
    cin>>N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin>>A[i];
    }
    assemblyLine(A,N);
    return 0;
}