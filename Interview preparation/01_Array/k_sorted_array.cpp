#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
void sortArray1(int *a, int n)
{
    // Time  : O(n*k)
    // Space : O(1)

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int index = i;
        while (index > 0 && a[index - 1] > key)
        {
            a[index] = a[index - 1];
            index--;
        }
        a[index] = key;
    }
}
void sortArray2(int *a, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq(a, a + k + 1);
    int index = 0;
    for (int i = k + 1; i < n; i++)
    {
        a[index++] = pq.top();
        pq.pop();
        pq.push(a[i]);
    }
    while (!pq.empty())
    {
        a[index++] = pq.top();
        pq.pop();
    }
}
int main()
{
    int a[]{10, 9, 8, 7, 4, 70, 60, 50};
    int k = 4;
    int n = sizeof(a) / sizeof(a[0]);
    // sortArray1(a,n);
    sortArray2(a, n, k);
    cout << "\nList : ";
    for (int i : a)
    {
        cout << i << " ";
    }
    return 0;
}