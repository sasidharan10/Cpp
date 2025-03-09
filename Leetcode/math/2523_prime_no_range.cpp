#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPrime(int num)
    {
        if (num <= 1)
            return false;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    vector<int> closestPrimes2(int left, int right)
    {
        //T.C : O((R-L) * sqrt(R))
        //S.C : O(R-L)

        vector<int> primeNumbers;
        for (int i = left; i <= right; i++)
        {
            if (isPrime(i))
            {
                if (!primeNumbers.empty() && i - primeNumbers.back() <= 2)
                    return {primeNumbers.back(), i};
                primeNumbers.push_back(i);
            }
        }
        int n = primeNumbers.size();
        int mini = INT_MAX;
        vector<int> res(2, -1);
        for (int i = 0; i < n - 1; i++)
        {
            int diff = primeNumbers[i + 1] - primeNumbers[i];
            if (diff < mini)
            {
                res[0] = primeNumbers[i];
                res[1] = primeNumbers[i + 1];
                mini = diff;
            }
        }
        return res;
    }
    vector<bool> sieveHelper(int right)
    {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i <= right; i++)
        {
            if (isPrime[i])
            {
                for (int j = 2; i * j <= right; j++)
                {
                    isPrime[i * j] = false;
                }
            }
        }
        return isPrime;
    }
    vector<int> closestPrimes(int left, int right)
    {
        //T.C : O(Rlog(log(R)) + (R-L))
        //S.C : O(R)

        vector<bool> isPrime = sieveHelper(right);
        vector<int> primeNumbers;
        for (int i = left; i <= right; i++)
        {
            if (isPrime[i])
                primeNumbers.push_back(i);
        }
        int n = primeNumbers.size();
        int mini = INT_MAX;
        vector<int> res(2, -1);
        for (int i = 0; i < n - 1; i++)
        {
            int diff = primeNumbers[i + 1] - primeNumbers[i];
            if (diff < mini)
            {
                res[0] = primeNumbers[i];
                res[1] = primeNumbers[i + 1];
                mini = diff;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    int left = 10, right = 19;
    vector<int> ans = s.closestPrimes2(left, right);
    cout << "Result: ";
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/closest-prime-numbers-in-range/

Youtube: https://www.youtube.com/watch?v=fwKTSOUvzaE

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Mathematical/Closest%20Prime%20Numbers%20in%20Range.cpp

algorithm: 

- Optimal Approach:

- both methods are sieve fof eratosthenes

*/

/*

2523. Closest Prime Numbers in Range

Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these
conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

Example 1:

Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.

Example 2:

Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.

Constraints:

1 <= left <= right <= 10^6


*/

/*
************* Java Code **************

    public static boolean[] sieveHelper(int right) {
        boolean[] isPrime = new boolean[right + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = 2; i * j <= right; j++) {
                    isPrime[i * j] = false;
                }
            }
        }
        return isPrime;
    }

    public static int[] closestPrimes(int left, int right) {
        boolean[] isPrime = sieveHelper(right);
        List<Integer> primeNumbers = new ArrayList<>();
        for (int i = left; i <= right; i++) {
            if (isPrime[i])
                primeNumbers.add(i);
        }
        int n = primeNumbers.size();
        int mini = Integer.MAX_VALUE;
        int[] res = new int[2];
        Arrays.fill(res, -1);
        for (int i = 0; i < n - 1; i++) {
            int diff = primeNumbers.get(i + 1) - primeNumbers.get(i);
            if (diff < mini) {
                res[0] = primeNumbers.get(i);
                res[1] = primeNumbers.get(i + 1);
                mini = diff;
            }
        }
        return res;
    }

*/