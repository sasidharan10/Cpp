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
    int c;
    float a;
    cin>>c>>a;
    if(a>0 && a<=2000 && c>=0 && c<=2000)
    {
       if(c%5==0 && a>=(c+0.50))
       {
           a=a-c-0.50;
           cout<<fixed<<setprecision(2)<<a;
       }
       else
           cout<<fixed<<setprecision(2)<<a; 
    }
    return 0;
}