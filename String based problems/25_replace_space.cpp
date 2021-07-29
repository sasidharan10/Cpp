#include <iostream>
using namespace std;
int main()
{
    char a[] = "floor gang aaoouuhh";
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ' ')
            a[i] = '*';
    }
    cout << "The string is : " << a;
    return 0;
}

/*

Write a program in C to replace the spaces of a string with a specific character. Go to the editor

Test Data :
Input a string : Be glad to see the back of Input replace character : *

Expected Output :

After replacing the space with  * the new string is :                 
Be*glad*to*see*the*back*of*

*/