#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ap{1, 4, 7, 10, 13, 16, 19};
    int n = 7;
    int first = 1;
    int d = 3;
    int last = 1 + (n - 1) * d;
    cout << "Last term: " << ap[n - 1] << endl;
    cout << "Last term using formula: " << last << endl;
    cout << "Sum of n terms: " << accumulate(ap.begin(), ap.end(), 0) << endl;
    cout << "Sum of n terms using formula: " << (n) * (first + last) / 2 << endl;
    return 0;
}

/*

- Arithmetic progression formula:

- Find a(n)th term = a + (n-1)*d;

- Sum of n terms, S(n) = {  n * (a + a(n))/2  } OR {  n * (2a + (n-1)*d)/2  }

*/