#include <iostream>
using namespace std;
void print(int (*a)[3], int n)
{
    cout << "The array is : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << ", ";
        }
        cout << endl;
    }
}
int main()
{
    int a[][3] = {{1, 2, 3,},{4, 5, 6}};
    int(*p)[3] = a;

    cout << "a : " << a << endl;               // returns pointer of 1D array
    cout << "a[0] : " << a[0] << endl;         // pointer to first element
    cout << "*a : " << *a << endl;             // pointer to first element
    cout << "&a[0][0] : " << &a[0][0] << endl; // address of the element
    cout <<"-------------------------------------"<< endl;
    cout << "a+1 : " << a + 1 << endl;         // returns pointer of second row 1d array
    cout << "a[1] : " << a[1] << endl;         // points to the 1st element in second row
    cout << "*(a+1) : " << *(a + 1) << endl;   // points to the 1st element in second row
    cout << "&a[1] : " << &a[1] << endl;       // address of second row
    cout << "&a[1][0] : " << &a[1][0] << endl; // address of the 1st element in second row
    cout <<"-------------------------------------"<< endl;
    cout << "*(*a+1) : " << *(*a + 1) << endl;
    cout << "*(*(a+1)) : " << *(*(a + 1)) << endl;
    cout <<"-------------------------------------"<< endl;
    cout << "*(a[0]+1) : " << *(a[0] + 1) << endl;
    cout << "*(*(a+1)+1) : " << *(*(a + 1) + 1) << endl;
    cout <<"-------------------------------------"<< endl;
    cout << "a[1] : " << a[1] << endl;
    cout << "*a[1] : " << *a[1] << endl;
    cout << "**a : " << **a << endl;
    cout <<"-------------------------------------"<< endl;
    print(a, 2);
    return 0;
}

// note

// for 2d array atleast mention size for column during declaration
// if a 2D array statement has 2 '*' symbols, then its definetly a value as it is dereferenced twice.
// or if it has 1 '*' symbol and one a[0] then also it returns a value as it is also dereferenced twice.
// normal addition to the variable just pushes it to next element or next row