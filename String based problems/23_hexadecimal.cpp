#include <iostream>
#include <cctype>
using namespace std;
int main()
{
    char a;
    cout << "Enter a digit : ";
    cin >> a;
    if (isxdigit(a))
        cout << "\nIt is hexadecimal";
    else
        cout << "\nIt is NOT hexadecimal";
    return 0;
}

/*

Write a program in C to check whether a character is Hexadecimal Digit or not. Go to the editor

Test Data :
Input a character : 7

Expected Output :

The entered character is a hexadecimal digit.

*/