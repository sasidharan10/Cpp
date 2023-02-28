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
    int num, result;
    cout << "Enter a number : ";
    cin >> num;
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

// happy numbers : 7, 28, 100, 320