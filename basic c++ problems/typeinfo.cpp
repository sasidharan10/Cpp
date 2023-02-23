#include <iostream>
#include <typeinfo>
using namespace std;
int main()
{
    int a = 1;
    float b = 2.3;
    char c = 'z';
    double d = 126;
    long long int e = 126;
    cout<<typeid(a).name()<<endl;
    cout<<typeid(b).name()<<endl;
    cout<<typeid(c).name()<<endl;
    cout<<typeid(d).name()<<endl;
    cout<<typeid(e).name()<<endl;
    return 0;
}