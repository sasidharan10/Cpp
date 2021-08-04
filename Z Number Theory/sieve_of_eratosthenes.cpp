#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    // Time : O(nlog(logn))
    
    int prime[100];
    for (int i : prime)
        i=1;
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= 50; i++)
    {
        if (prime[i])
            for (int j = i * i; j <= 50; j += i)
            {
                prime[j] = 0;
            }
    }
    for (int i = 2; i < 50; i++)
    {
        if (prime[i])
            cout << i << " ";
    }
    return 0;
}