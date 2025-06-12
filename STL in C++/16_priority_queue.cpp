#include <bits/stdc++.h>
using namespace std;
class Pair
{
public:
    int first;
    int second;
    Pair(int first, int second)
    {
        this->first = first;
        this->second = second;
    }
};
struct comp
{
    bool operator()(const Pair p1, const Pair p2)
    {
        if (p1.first == p2.first)
            return p1.second > p2.second;
        else
            return p1.first < p2.first;
    }
};
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
    priority_queue<int> pq1, pq3;                    // Max-Heap (default)
    priority_queue<int, vector<int>, greater<>> pq2; // min-Heap
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

    cout << "********** Custom class **********" << endl;
    Pair p1(30, 1);
    Pair p2(20, 2);
    Pair p3(10, 3);
    priority_queue<Pair, vector<Pair>, comp> pq4;
    pq4.push(p1);
    pq4.push(p2);
    pq4.push(p3);
    cout << "\nCustom PQ 4 : " << endl;
    while (!pq4.empty())
    {
        cout << pq4.top().first << " : " << pq4.top().second << endl;
        pq4.pop();
    }

    return 0;
}

/*

- Provides constant time lookup of largest and smallest element.
- vector or array is used in priority queue.
- Cost of insertion and deletion is O(logn).

Think of the comparator as answering:

"Should p1 go below p2 in the heap?"

If yes, return true → p2 comes first.

If no, return false → p1 comes first.

*/