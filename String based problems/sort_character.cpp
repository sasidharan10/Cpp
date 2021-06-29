#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    char a[] = "nfn8vds6ifjjw4e9kz8xmeck4";
    cout << "string before sorting : " << a << endl;
    // string b=(string)a;
    // sort(b.begin(),b.end());
    // cout<<"string after sorting : "<<b<<endl;
    int flag = 0;
    char temp;
    int n = sizeof(a) / sizeof(a[0]);
    // bubble sort
    for (int i = 0; i < n-1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 2; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
    cout << "string after sorting : " << a << endl;
    return 0;
}

// here we use n-2 because the last character is '\0' and we dont want the last character to be compared