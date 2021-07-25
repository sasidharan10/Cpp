#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int findMedian1(int *a, int *b, int n)
{
    // Time : O(nlogn)
    // Space : O(2n)

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        v.push_back(b[i]);
    }
    sort(v.begin(), v.end());
    int median = (v[n] + v[n - 1]) / 2;
    return median;
}
int findMedian2(int *a, int *b, int n)
{
    // Time : O(n)
    // Space : O(1)

    int i = 0, j = 0;
    int m1 = -1;
    int m2 = -1;
    for (int k = 0; k <= n; k++)
    {
        while (i == n)
        {
            m1 = m2;
            m2 = b[0];
        }
        while (j == n)
        {
            m1 = m2;
            m2 = a[0];
        }
        if (a[i] <= b[j])
        {
            m1 = m2;
            m2 = a[i];
            i++;
        }
        else
        {
            m1 = m2;
            m2 = b[j];
            j++;
        }
    }
    return (m1 + m2) / 2;
}
int getMedian(int *a, int *b, int start_a, int end_a, int start_b, int end_b)
{
    if (end_a - start_a == 1 && end_b - start_b == 1)
    {
        return (max(a[start_a], b[start_b]) + min(a[end_a], b[end_b])) / 2;
    }
    int median_a = (start_a + end_a) / 2;
    int median_b = (start_b + end_b) / 2;

    int m1 = a[median_a];
    int m2 = b[median_b];

    if (m1 == m2)
        return m1;
    if (m1 < m2)
    {
        start_a = median_a;
        end_b = median_b;
    }
    else
    {
        start_b = median_b;
        end_a = median_a;
    }
    return getMedian(a, b, start_a, end_a, start_b, end_b);
}
int findMedian3(int *a, int *b, int n)
{
    return getMedian(a, b, 0, n - 1, 0, n - 1);
}
int main()
{
    int a[] = {1, 12, 15, 26, 38};
    int b[] = {2, 13, 17, 30, 45};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    cout << "Median is " << findMedian1(a, b, n1) << endl;
    cout << "Median is " << findMedian2(a, b, n1) << endl;
    cout << "Median is " << findMedian3(a, b, n1) << endl;
    return 0;
}