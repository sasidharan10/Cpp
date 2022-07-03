#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int primeCount1(int n)
{
    vector<int> primeNumbers(n + 1, 1);
    primeNumbers[0] = primeNumbers[1] = 0;
    int count = 0;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (primeNumbers[i] == 1)
        {
            for (int j = 2 * i; j < n; j += i)
            {
                primeNumbers[j] = 0;
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        if (primeNumbers[i] == 1)
            count++;
    }
    return count;
}
int main()
{
    int n = 17;
    cout << "Count: " << primeCount1(n) << endl;
    return 0;
}