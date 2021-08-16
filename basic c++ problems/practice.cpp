#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <cctype>
using namespace std;
void func(int a)
{
    if(a==0)
        return;
    cout<<a<<endl;
    func(a-1);
    cout<<a<<endl;
}
int main()
{
    int a=5;
    func(a);
    return 0;
}