#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int *p = find(arr, arr + n, x);
    if(p==arr + n)
        cout<<"Not Found: "<<endl;
    else
        cout<<"Found: "<<endl;

}
