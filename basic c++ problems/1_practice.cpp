#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
    char a[20] = "skjvhevlb";
    int i = 0;
    while (a[i] != '\0')
    {
        i++;
    }
    cout << "Size: " << i << endl;
    string b = (string)a; // typecasting
    sort(b.begin(), b.end());
    cout << "String: " << b << endl;
    find(b.begin(), b.end(), 'z') != b.end() ? cout << "Found!!!" << endl : cout << "Not Found!!!" << endl; // using conditional operator
    cout << "Max Element: " << *max_element(b.begin(), b.end()) << endl;
    cout << "Min Element: " << *min_element(b.begin(), b.end()) << endl;
    cout << "Count: " << count(b.begin(), b.end(), 'a') << endl;
    int arr[] = {1, 2, 3, 4, 3, 2, 1, 4, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    cout << "Array: ";
    for (auto j : arr)
        cout << j << " ";
    cout << endl;
    cout << "Lower bound: " << *lower_bound(arr, arr + n, 3) << endl;
    cout << "Upper bound: " << *upper_bound(arr, arr + n, 3) << endl;
    cout << "Count of 3: " << upper_bound(arr, arr + n, 3) - lower_bound(arr, arr + n, 3) << endl;
    vector<int> v{1, 2, 3, 4, 3, 2, 1, 4, 5, 3};
    v.erase(unique(v.begin(), v.end()), v.end());
    int *p = unique(arr, arr + n);
    cout << "Vector: ";
    for (auto k = v.begin(); k != v.end(); k++)
    {
        cout << *k << " ";
    }
    n=sizeof(arr)-sizeof(p);
    cout << endl;
    cout << "Array: ";
    for (int l = 0; l < n; l++)
    {
        cout<<arr[l]<<" ";
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout<<"Sizeof: "<<sizeof(arr)<<endl;
    return 0;
    
}
