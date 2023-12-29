#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> products{"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";
    sort(products.begin(), products.end());
    cout << searchWord.compare(0, 3, "mouse") << endl;
    int it = lower_bound(products.begin(), products.end(), "zou") - products.begin();
    cout << it << endl;
    return 0;
}