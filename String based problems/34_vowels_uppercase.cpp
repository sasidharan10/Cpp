#include <iostream>
using namespace std;
int main()
{
    char a[] = "floor gang aaoouuhh";
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] == 'a' || a[i] == 'A' || a[i] == 'e' || a[i] == 'E' || a[i] == 'i' || a[i] == 'I' || a[i] == 'o' || a[i] == 'O' || a[i] == 'u' || a[i] == 'U')
        {
            a[i] = toupper(a[i]);
        }
        i++;
    }
    cout << "The string is : " << a;
    return 0;
}

/*

Write a C programming to convert vowels into upper case character in a given string. Go to the editor
Test Data :
Input a string : w3resource
Expected Output:

Input a sentence: The original string:
w3resource
After converting vowels into upper case the sentence becomes:
w3rEsOUrcE

*/