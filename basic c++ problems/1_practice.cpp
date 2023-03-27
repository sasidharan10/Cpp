#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    string s="RSDLU";
    string ans="";
    s.erase(s.end()-3, s.end());
    cout<<s<<endl;
    return 0;
}