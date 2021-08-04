#include <iostream>
#include <algorithm>
#include <string>
typedef unsigned long long int lli;
using namespace std;
lli hashing(string str)
{
    int p = 5381;
    lli hash = 0;
    int d = 256;
    for (int i = 0; i < str.length(); i++)
    {
        // hash = (d * hash + str[i]) % p;
        hash = p * hash + str[i];
    }
    return hash;
}
int main()
{
    string str1 = "abcd";
    string str2 = "acbd";
    string str3 = "adbc";
    string str6 = "acbd";
    string str4 = "dcba";
    string str5 = "udfi";
    cout << str1 << " : " << hashing(str1) << endl;
    cout << str2 << " : " << hashing(str2) << endl;
    cout << str3 << " : " << hashing(str3) << endl;
    cout << str6 << " : " << hashing(str6) << endl;
    cout << str4 << " : " << hashing(str4) << endl;
    cout << str5 << " : " << hashing(str5) << endl;
    return 0;
}