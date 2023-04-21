#include <iostream>
using namespace std;
int main()
{
    char a[] = "floor gang aooouuhh";
    char b[] = "ooouh";
    int flag = 0;
    cout << "" << endl;
    int l1 = (sizeof(a) / sizeof(a[0])) - 1;
    int l2 = (sizeof(b) / sizeof(b[0])) - 1;
    for (int i = 0; i <= l1 - l2; i++) // l1-l2 because no need to go till end of the string.
    {
        int j = 0;
        for (j = 0; j < l2; j++)
        {
            if (a[i + j] != b[j]) // checking the substring in every index
                break;
        }
        if (j == l2)
            flag = 1;
    }
    if (flag == 1)
        cout << "Substring is present";
    else
        cout << "Substring is NOT present!!!";
    return 0;
}

/*

Write a C program to check whether a given substring is present in the given string.

Test Data :
Input the string : This is a test string.
Input the substring to be search : search

Expected Output :

The substring is not exists in the string.

*/