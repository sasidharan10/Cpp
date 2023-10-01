#include <bits/stdc++.h>
using namespace std;
int main()
{
    string x = "s343asdfghjk";
    int k = 97;
    // cout << x[0] - '0' << endl;
    // cout << isdigit(x[0]) << endl;
    reverse(x.begin() + 7, x.end());
    cout << x << endl;
    return 0;
}