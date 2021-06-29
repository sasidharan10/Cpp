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
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t,a; 
    cin>>t;
    while(t--)
    {
        int fact=1;
        cin>>a;
        while(a>1)
        {
            fact=fact*a;
            a--;
        }
        cout<<fact<<endl;
    }
	return 0;
}