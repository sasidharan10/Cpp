#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int noOfCoins(int n)
{
    return (n*(n+1))/2;
}
int maxHeight(int n)
{
    if (n == 0)
        return 0;
    int i = 1;
    int count = 0;
    while (i <= n)
    {
        count++;
        n = n - i;
        i++;
    }
    return count;
}
int main()
{
    int n = 15;
    int c = 5;
    cout << "No of coins to make triangle :  " << noOfCoins(c) << endl;
    cout << "Max Height of Triangle :  " << maxHeight(n) << endl;
    return 0;
}