#include <iostream>
using namespace std;
int main()
{
    char a[] = "kosvjkisnvs";
    int arr[255] = {0};
    int i = 0;
    cout << "The repeating word is : ";
    while (a[i] != '\0')
    {
        if (arr[a[i]] == 0)
            arr[a[i]]++;
        else
        {
            cout << a[i];
            break;
        }
        i++;
    }
}

/*

Write a C programming to find the repeated character in a given string. Go to the editor
Test Data :
Input a string: w3resource
Expected Output:

Input a string: The first repetitive character in w3resource is: r 

*/