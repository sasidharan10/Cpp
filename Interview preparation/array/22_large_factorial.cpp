#include <iostream>
#include <algorithm>
using namespace std;
int multiply(int x, int *res, int res_size)
{
    int carry = 0, prod = 1;
    for (int i = 0; i < res_size; i++)
    {
        prod = x * res[i] + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry)
    {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}
void factorial(int n)
{
    int res[500];
    res[0] = 1;
    int res_size = 1;
    for (int i = 2; i <= n; i++)
    {
        res_size = multiply(i, res, res_size);
    }
    cout << "Factorial of " << n << endl;
    for (int j = res_size - 1; j >= 0; j--)
    {
        cout << res[j];
    }
}
int main()
{
    int n = 100;
    factorial(n);
    return 0;
}

/*

- here we have to do normal real-life multiplication.
- we have to create an array to store all digits of the factorial.
- whenever we multiply a number with the result, we will keep updating the digits and 


*/