#include <iostream>
using namespace std;
typedef unsigned long long int lli;
lli hash1(string str)
{
    int p = 5381;
    lli hash = 0;
    for (int i = 0; i < str.length(); i++)
    {
        hash = p * hash + str[i];
    }
    return hash;
}
int main()
{
    string str = "ascias";
    cout << "Hash: " << hash1(str) << endl;
    return 0;
}