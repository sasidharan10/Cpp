#include <iostream>
using namespace std;
int main()
{
    char a[] = "this. is, (good)";
    int count = 0, i = 0;
    while (a[i] != '\0')
    {
        if (ispunct(a[i]))
            count++;
        i++;
    }
    cout << "Count is : " << count; // counts . , () [] etc
    return 0;
}

/*

 Write a program in C to count the number of punctuation characters exists in a string.

Test Data :
Input a string : The quick brown fox, jumps over the, lazy dog.

Expected Output :

The punctuation characters exists in the string is : 3 

*/