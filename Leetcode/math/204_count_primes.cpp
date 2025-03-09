#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Brute force
    bool isPrime(int num)
    {
        for (int i = 2; i < num - 1; i++)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    int countPrimes2(int n)
    {
        // TC: O(n^2)
        // SC: O(1)

        if (n <= 2)
            return 0;
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrime(i))
            {
                count++;
            }
        }
        return count;
    }

    // Optimal - sieve of eratosthenes
    int countPrimes(int n)
    {
        // TC: O(n*log(logn))
        // SC: O(n)

        if (n <= 2)
            return 0;
        vector<int> primeNumbers(n, 1);
        primeNumbers[0] = 0;
        primeNumbers[1] = 0;
        int count = 0;
        for (int i = 2; i * i < n; i++)
        {
            if (primeNumbers[i] == 1)
            {
                for (int j = 2; i * j < n; j++)
                {
                    primeNumbers[i * j] = 0;
                }
            }
        }
        for (int i = 2; i < n; i++)
        {
            if (primeNumbers[i] == 1)
                count++;
        }
        return count;
    }
};
int main()
{
    Solution s;
    int n = 17;
    cout << "Count: " << s.countPrimes2(n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/count-primes/

Youtube:

Code Link:

algorithm:

- Brute Force Approach:

-

- Optimal Approach:

- sieve of eratosthenes

*/

/*

204. Count Primes

Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:

Input: n = 0
Output: 0

Example 3:

Input: n = 1
Output: 0

Constraints:

0 <= n <= 5 * 10^6

*/

/*
************* Java Code **************

    public static int countPrimes(int n) {
        if (n <= 2)
            return 0;
        int[] primeNumbers = new int[n];
        Arrays.fill(primeNumbers, 1);
        primeNumbers[0] = 0;
        primeNumbers[1] = 0;
        int count = 0;
        for (int i = 2; i * i < n; i++) {
            if (primeNumbers[i] == 1) {
                for (int j = 2; i * j < n; j++) {
                    primeNumbers[i * j] = 0;
                }
            }
        }
        for (int i = 2; i < n; i++) {
            if (primeNumbers[i] == 1)
                count++;
        }
        return count;
    }

*/