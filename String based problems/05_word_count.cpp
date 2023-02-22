#include <iostream>
using namespace std;
int main()
{
    char a[] = "this is awesome bro";
    int i = 0, word = 1;
    while (a[i] != '\0')
    {
        if (a[i] == ' ' || a[i] == '\t' || a[i] == '\n')
            word++;
        i++;
    }
    cout << "Word count : " << word;
    return 0;
}

/*
Write a program in C to count the total number of words in a string. Go to the editor

Test Data :
Input the string : This is w3resource.com

Expected Output :

Total number of words in the string is : 3

*/