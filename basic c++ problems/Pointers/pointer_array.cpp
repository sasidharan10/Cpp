#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int *p = a;
    cout << "a : " << a << endl; // base address
    cout << "&a[0] : " << &a[0] << endl;
    cout << "&a[2] : " << &a[2] << endl;
    cout << "a+2 : " << a + 2 << endl;
    cout << "*(a+2) : " << *(a + 2) << endl;
    cout << "a[2] : " << a[2] << endl;
    return 0;
}

// &a[2] and (a+2) are is_same(gives address)

// *(a+2) and a[2] are same(gives the value)
