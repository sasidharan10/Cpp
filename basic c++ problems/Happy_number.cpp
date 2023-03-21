#include <iostream>
#include <stdio.h>
using namespace std;

// isHappyNumber() will determine whether a number is happy or not
int isHappy(int result)
{
    // Calculates the sum of squares of digits
    int sum = 0, rem = 0;
    while (result > 0)
    {
        rem = result % 10;
        sum = sum + (rem * rem);
        result = result / 10;
    }
    return sum;
}
int main()
{
    int num = 19, result;
    result = num;

    while (result != 1 && result != 4)
        result = isHappy(result);

    // Happy number always ends with 1
    if (result == 1)
        cout << num << " is a Happy number";

    // Unhappy number ends in a cycle of repeating numbers which contains 4
    if (result == 4)
        cout << num << " is a Not Happy numer";
    return 0;
}

// happy numbers : 7, 19, 28, 100, 320

/*

- A number is called happy if it leads to 1 after a sequence of steps wherein each step number is replaced by the sum of squares of its digit that is if we start with Happy Number and keep replacing it with digits square sum, we reach 1.
- A number will not be a Happy Number when it makes a loop in its sequence that is it touches a number in sequence which already been touched.

Input: n = 19
Output: True
19 is Happy Number,
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
As we reached to 1, 19 is a Happy Number.

*/