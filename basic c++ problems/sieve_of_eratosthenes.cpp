#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // brute force
    bool isPrime1(int num)
    {
        // TC: O(n)
        // SC: O(1)

        for (int i = 2; i <= num - 1; i++)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    // better
    bool isPrime2(int num)
    {
        // TC: O(n/2)
        // SC: O(1)

        for (int i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    // optimal
    bool isPrime3(int num)
    {
        // TC: O(sqrt(n))
        // SC: O(1)

        // for (int i = 2; i <= sqrt(num); i++)
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
                return false;
        }
        // (i <= sqrt(num)) can also be written as (i * i <= num)
        // use num = 100 as example, and find its factors.
        return true;
    }
    vector<int> findPrime(int n)
    {
        vector<int> primeNumbers;
        for (int i = 2; i <= n; i++)
        {
            // if (isPrime1(i))
            //     primeNumbers.push_back(i);
            // if (isPrime2(i))
            //     primeNumbers.push_back(i);
            if (isPrime3(i))
                primeNumbers.push_back(i);
        }
        return primeNumbers;
    }

    // Better
    vector<int> sieveOfEratosthenes1(int n)
    {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i <= n; i++)
        {
            if (isPrime[i] == true)
            {
                for (int j = 2; i * j <= n; j++)
                {
                    isPrime[i * j] = false;
                }
            }
        }
        vector<int> ans;
        for (int i = 2; i < n + 1; i++)
        {
            if (isPrime[i])
                ans.push_back(i);
        }
        return ans;
    }

    // Optimal
    vector<int> sieveOfEratosthenes2(int n)
    {
        // TC: O(n*log(log(n)))
        // SC: O(n)
        
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i <= n; i++)
        {
            if (isPrime[i] == true)
            {
                for (int j = 2; i * j <= n; j++)
                {
                    isPrime[i * j] = false;
                }
            }
        }
        vector<int> ans;
        for (int i = 2; i < n + 1; i++)
        {
            if (isPrime[i])
                ans.push_back(i);
        }
        return ans;
    }
};
int main()
{
    Solution s;
    int n = 30;
    vector<int> ans = s.findPrime(n);
    for (int it : ans)
    {
        cout << it << ", ";
    }
    cout << endl;
    // ans = s.sieveOfEratosthenes1(n);
    ans = s.sieveOfEratosthenes2(n);
    for (int it : ans)
    {
        cout << it << ", ";
    }
    cout << endl;
    return 0;
}

/*

notes: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/iPad%20PDF%20Notes/Maths%20Concepts%20-%20Primality%20Check%20%26%20Sieve%20Of%20Eratosthenes.pdf

leetcode:

Youtube: https://www.youtube.com/watch?v=61LWhWexFI4

Code Link: 

algorithm:

*/