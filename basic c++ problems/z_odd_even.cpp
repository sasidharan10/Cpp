#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    int *b = new int[m];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int oc1 = 0;
    int oc2 = 0;
    int oi1 = 0;
    int oi2 = 0;
    int ei1 = 0;
    int ei2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            oc1++;
            oi1 = i;
        }
        else
        {
            ei1 = i;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (b[i] % 2 != 0)
        {
            oc2++;
            oi2 = i;
        }
        else
        {
            ei2 = i;
        }
    }
    int cnt = 0;
    if (oc1 % 2 != 0 && oc2 % 2 != 0)
    {
        swap(a[oi1], b[ei2]);
        cnt++;
    }
    else if (oc1 % 2 == 0 && oc2 % 2 == 0)
    {
        cnt = 0;
    }
    else
    {
        cnt = -1;
    }
    cout << "Minimum swap : " << cnt << endl;
    return 0;
}