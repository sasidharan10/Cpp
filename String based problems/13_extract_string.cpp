#include <iostream>
using namespace std;
int main()
{
    char a[] = "floor gang aoooh";
    int x, len, i = 0;
    cout << "String is : " << a;
    int n = sizeof(a) / sizeof(a[0]);
    cout << "\nEnter the index : ";
    cin >> x;
    cout << "Enter the length : " << endl;
    cin >> len;
    cout << "String is : ";
    if (len + x > n - 1)
    {
        cout << "Not Possible!!!";
        return 0;
    }

    while (len--)
    {
        cout << a[x];
        x++;
    }
    return 0;
}

/*

Write a program in C to extract a substring from a given string.

Test Data :
Input the string : this is test string
Input the position to start extraction :9
Input the length of substring :4

Expected Output :

The substring retrieve from the string is : " test " 

*/