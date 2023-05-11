#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int convertDecimal(int b)
{
    int n = 1, sum = 0;
    while (b > 0)
    {
        int rem = b % 10;
        b = b / 10;
        sum += (rem * n);
        n = n * 2;
    }
    return sum;
}
int main()
{
    int b = 1010;
    cout << "Decimal: " << convertDecimal(b) << endl;
    return 0;
}