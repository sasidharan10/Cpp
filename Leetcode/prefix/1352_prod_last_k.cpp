#include <bits/stdc++.h>
using namespace std;
// Brute force
class ProductOfNumbers2
{
public:
    // TC: O(n + k)
    // SC: O(n)

    vector<int> arr;
    int n;
    ProductOfNumbers2()
    {
        n = 0;
    }

    void add(int num)
    {
        // TC: O(n)

        arr.push_back(num);
        n++;
        cout << "List: ";
        for (int it : arr)
        {
            cout << it << ", ";
        }
        cout << endl;
    }

    int getProduct(int k)
    {
        // TC: O(k)

        int prod = 1;
        for (int i = n - 1; i >= n - k; i--)
        {
            prod *= arr[i];
        }
        return prod;
    }
};

// Optimal - using cumulative prod array
class ProductOfNumbers
{
public:
    // TC: O(1)
    // SC: O(n)

    vector<int> arr;
    int n;
    ProductOfNumbers()
    {
        n = 0;
    }

    void add(int num)
    {
        // TC: O(n)

        int lastElm = 1;
        if (n > 0)
            lastElm = arr[n - 1];
        if (num == 0)
        {
            arr.clear();
            n = 0;
        }
        else
        {
            arr.push_back(lastElm * num);
            n++;
        }
        cout << "List: ";
        for (int it : arr)
        {
            cout << it << ", ";
        }
        cout << endl;
    }

    int getProduct(int k)
    {
        // TC: O(1)
        if (k > n)
            return 0;
        if (n == k)
            return arr[n - 1];
        int lastElm = arr[n - 1];
        int prod = lastElm / arr[n - k - 1];
        return prod;
    }
};
int main()
{
    // Solution s;
    ProductOfNumbers p;
    // ProductOfNumbers2 p;
    p.add(3);                                               // [3]
    p.add(0);                                               // [3,0]
    p.add(2);                                               // [3,0,2]
    p.add(5);                                               // [3,0,2,5]
    p.add(4);                                               // [3,0,2,5,4]
    cout << "p.getProduct(2): " << p.getProduct(2) << endl; // return 20. The product of the last 2 numbers is 5 * 4 = 20
    cout << "p.getProduct(3): " << p.getProduct(3) << endl; // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
    cout << "p.getProduct(4): " << p.getProduct(4) << endl; // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
    p.add(8);                                               // [3,0,2,5,4,8]
    cout << "p.getProduct(2): " << p.getProduct(2) << endl; // return 32. The product of the last 2 numbers is 4 * 8 = 32
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/product-of-the-last-k-numbers

Youtube: https://www.youtube.com/watch?v=Jvu3hd8A2rg

Code Link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Product%20of%20the%20Last%20K%20Numbers.cpp

algorithm:

- Brute Force Approach:

- self explanatory

- Optimal Approach:

- using cumulative prod array.

*/

/*

1352. Product of the Last K Numbers

Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:

ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always
the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into
a single 32-bit integer without overflowing.

Example:

Input
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Output
[null,null,null,null,null,null,20,40,0,null,32]

Explanation
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32

Constraints:

0 <= num <= 100
1 <= k <= 4 * 104
At most 4 * 104 calls will be made to add and getProduct.
The product of the stream at any point in time will fit in a 32-bit integer.

Follow-up: Can you implement both GetProduct and Add to work in O(1) time complexity instead of O(k) time complexity?

*/

/*
************* Java Code **************



*/