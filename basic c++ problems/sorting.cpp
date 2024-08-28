#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int rno;
    Student(string name, int rno)
    {
        this->name = name;
        this->rno = rno;
    }
};
struct comp // class also works
{
    bool operator()(const Student &s1, const Student &s2)
    {
        return s1.rno < s2.rno; // decending
        // return s1.rno > s2.rno;   // ascending
    }
};
int main()
{
    // Sorting Array

    cout << "Sorting array: ";
    int arr[]{1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    // sort(arr, arr + n, greater<>());  // decending order
    for (int it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    // Sorting Vector

    cout << "Sorting vector: ";
    vector<int> nums{1, 5, 3, 4, 2};
    // sort(nums.begin(), nums.end());
    sort(nums.begin(), nums.end(), greater<>()); // decending order
    for (int it : nums)
    {
        cout << it << " ";
    }
    cout << endl;

    // Sorting Vector of class

    cout << "Sorting Vector of custom class: " << endl;
    Student s1("suarez", 9), s2("xavi", 6), s3("messi", 10);
    Student s4("busquets", 5), s5("neymar", 11), s6("iniesta", 8), s7("naymar", 111);
    vector<Student> v1;
    v1.push_back(s1);
    v1.push_back(s2);
    v1.push_back(s3);
    v1.push_back(s4);
    v1.push_back(s5);
    v1.push_back(s6);
    v1.push_back(s7);
    auto sortStudent = [&](Student a, Student b)
    {
        return a.rno < b.rno; // ascending order
        // return a.name < b.name;     // sort by name
        // return a.rno > b.rno;       // decending order
    };
    sort(v1.begin(), v1.end(), sortStudent);
    for (auto &&it : v1)
    {
        cout << it.rno << " : " << it.name << endl;
    }
    cout << endl;

    // Sorting 2D vector :

    cout << "Sorting 2D vector : " << endl;
    vector<vector<int>> v2{{1, 3}, {6, 4}, {3, 2}, {2, 8}};
    sort(v2.begin(), v2.end()); // sorts based on row elements
    for (vector<int> vt : v2)
    {
        for (int it : vt)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
    // incase we want to sort it based on 2nd element of each row, then we can define
    // custom lamdba function as we did above.

    // Priority Queue using class

    cout << "Priority Queue using class(Lambda) : " << endl;
    auto cmp = [&](Student const &a, Student const &b)
    {
        return a.rno < b.rno; // decending
        // return a.rno > b.rno;    // ascending
    };

    // using lambda
    priority_queue<Student, vector<Student>, decltype(cmp)> pq(cmp);
    // explanation below.

    pq.push(s1);
    pq.push(s2);
    pq.push(s3);
    pq.push(s4);
    pq.push(s5);
    pq.push(s6);
    while (!pq.empty())
    {
        Student temp = pq.top();
        pq.pop();
        cout << temp.rno << " : " << temp.name << endl;
    }
    cout << endl;

    // using comparator
    cout << "Priority Queue using class(Comparator) : " << endl;
    priority_queue<Student, vector<Student>, comp> pq2;
    pq2.push(s1);
    pq2.push(s2);
    pq2.push(s3);
    pq2.push(s4);
    pq2.push(s5);
    pq2.push(s6);
    while (!pq2.empty())
    {
        Student temp = pq2.top();
        pq2.pop();
        cout << temp.rno << " : " << temp.name << endl;
    }
    cout << endl;

    // Using set

    cout << "Set using class(Comparator): " << endl;

    set<Student, comp> st; // works well for set DS also.
    st.insert(s1);
    st.insert(s2);
    st.insert(s3);
    st.insert(s4);
    st.insert(s5);
    st.insert(s6);

    for (auto &&it : st)
    {
        cout << it.rno << " : " << it.name << endl;
    }
    cout << endl;
    return 0;
}

/*

Breakdown:
priority_queue<Student, vector<Student>, decltype(cmp)>:

priority_queue<Student, ...>: This declares a priority queue that will store Student objects.

vector<Student>: This specifies the underlying container that the priority_queue will use to store
the elements. By default, priority_queue uses a vector to hold the elements internally.

decltype(cmp): decltype is a keyword in C++ that deduces the type of an expression at compile time.
Here, it deduces the type of the lambda function cmp. This is necessary because priority_queue
needs to know the type of the comparator, and since cmp is a lambda (which doesn’t have a standard
type like int or string), decltype is used to capture its type.

pq(cmp):
pq: This is the name of the priority queue object being declared.
(cmp): This passes the cmp lambda function as an argument to the constructor of the priority_queue.
The priority_queue needs the comparator function to know how to order the elements (in this case,
Student objects) internally. By passing cmp, you're telling the priority_queue to use this specific
comparator for ordering its elements.

*/

/*

    // just trying to use dynamic allocation, not related to this.
    Student *t1 = new Student("puyol", 5); // dynamically allocating space
    delete t1;

*/