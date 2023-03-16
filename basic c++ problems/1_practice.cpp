#include <iostream>
#include <string>
using namespace std;
void reverse_string(int n, char *a)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(a[i++], a[j--]);
    }
}
int Factorial(int x)
{
    if(x==1)
        return x;
    return x*Factorial(x-1);
}
int main()
{
    int x=5;
    cout<<"Factorial: "<<Factorial(x)<<endl;
    return 0;
}