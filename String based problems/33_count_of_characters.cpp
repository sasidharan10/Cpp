#include <iostream>
using namespace std;
int main()
{
    // char a[] = "kos5vj49ki3scmpifhnvs4";
    char a[] = "abbacdaf";
    int arr[127] = {0};
    int i = 0;
    cout << "The count of each character is : " << endl;
    while (a[i] != '\0')
    {
        arr[a[i]]++;
        i++;
    }
    i = 0;
    while (a[i] != '\0')
    {
        if(arr[a[i]]>0)
        {
            cout << a[i] << " : " << arr[a[i]] << endl;
            arr[a[i]]=0;
        }
            i++;
    }
    return 0;
}

/*

Write a C programming to count of each character in a given string. Go to the editor
Test Data :
Input a string: w3resource
Expected Output:

Enter a str1ing: The count of each character in the string w3resource is 
w	1
3	1
r	2
e	2
s	1
o	1
u	1
c	1

*/