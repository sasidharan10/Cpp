#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<int> left_rotate(vector<int> a,int n,int d)
{
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        b[i]=a[(i-(n-d)+n)%n];
    }
    return b;
}
int main()
{
    int n,d;
    cin>>n;
    cin>>d;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    b=left_rotate(a,n,d);
    for(int i:b)
        cout<<i<<" ";
    return 0;
}