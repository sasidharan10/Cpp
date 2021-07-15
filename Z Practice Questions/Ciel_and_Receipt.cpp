#include <iostream>
#include <algorithm>
using namespace std;
void solve()
{
    int limit = 2048;
    int n, count = 0;
    cin >> n;
    while (n > 0)
    {
        count = count + n / limit;
        n = n % limit;
        limit = limit / 2;
    }
    cout << count << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}