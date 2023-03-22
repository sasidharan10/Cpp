#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
class student
{
public:
    int rno;
    string name;
};
int compareInt(const void *a, const void *b)
{
    const int *p1 = (int *)a;
    const int *p2 = (int *)b;
    return *p1 - *p2;
}
int compareStr(const void *a, const void *b)
{
    const char *p1 = (char *)a;
    const char *p2 = (char *)b;
    return strcmp(p1, p2);
}
int compareCls(const void *a, const void *b)
{
    student *p1 = (student *)a;
    student *p2 = (student *)b;
    // return p1->rno - p2->rno;
    return p1->rno - p2->rno;
}
int main()
{
    int arr[] = {3, 2, 6, 8, 4, 1, 7, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n, sizeof(int), compareInt);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nFor string: " << endl;
    char str[][20]{"messi", "iniesta", "xavi", "puyol"};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; str[i][j] != '\0'; j++)
        {
            cout << str[i][j];
        }
        cout << endl;
    }

    cout << "\nFor class: " << endl;
    student s1[]{{2, "iniesta"}, {3, "xavi"}, {1, "messi"}};
    int t = sizeof(s1) / sizeof(student);
    // cout<<t<<endl;
    qsort(s1, n, sizeof(student), compareCls);
    for (int i = 0; i < t; i++)
    {
        cout << s1[i].rno << " - " << s1[i].name << endl;
    }

    return 0;
}