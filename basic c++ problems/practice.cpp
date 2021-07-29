#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s1="hello";
    string s2="hello";
    s2[0]=(char)'s';   // not possible  in java
    cout<<"s1 : "<<s1<<endl;
    cout<<"s2 : "<<s2<<endl;
    return 0;
}