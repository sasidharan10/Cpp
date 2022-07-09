#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
template <typename t>
void print(t pq)
{
    while (!pq.empty()) // checks if empty
    {
        cout << pq.top() << " "; // returns top element
        pq.pop();                // deletes top element
    }
}
int main()
{
    int a[]{7, 5, 8, 9, 4, 2, 6, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    priority_queue<int> pq1, pq3;                       // Max-Heap (default)
    priority_queue<int, vector<int>, greater<int>> pq2; // min-Heap
    for (int i = 0; i < n; i++)
    {
        pq1.push(a[i]); // to push
    }
    // priority_queue<int> pq1(a,a+n);
    for (int i = 0; i < n; i++)
    {
        pq2.emplace(a[i]); // same but efficient for user data types
    }
    cout << "PQ 1 : ";
    print(pq1);
    cout << "\nPQ 2 : ";
    print(pq2);
    pq1.swap(pq3); // swap
    cout << "\nsize: " << pq3.size() << endl;
    cout << "Accessing elements:";
    while (!pq3.empty())
    {
        cout << pq3.top() << " ";
        pq3.pop();
    }
    cout << "\nIs empty?: " << pq3.empty() << endl;
    return 0;
}