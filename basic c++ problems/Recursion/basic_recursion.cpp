#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void func1(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    func1(n - 1);
}
void func2(int n)
{
    if (n == 0)
        return;
    func2(n - 1);
    cout << n << " ";
}
int sumN1(int i, int sum)
{
    if (i < 1)
        return sum;
    return sumN1(i - 1, sum + i);
}
int sumN2(int n)
{
    if (n == 0)
        return n;
    return n + sumN2(n - 1);
}
void sumN3(int i, int &sum)
{
    if (i < 1)
        return;
    sum += i;
    sumN3(i - 1, sum);
}
void rev(int *a, int i, int n)
{
    if (i >= n / 2)
        return;
    swap(a[i], a[n - 1 - i]);
    rev(a, i + 1, n);
}
bool palindrome(string s1, int i)
{
    int n = s1.length();
    if (i >= n / 2)
        return true;
    if (s1[i] != s1[n - i - 1])
        return false;
    return palindrome(s1, i + 1);
}
int main()
{
    func1(5);
    cout << endl;
    func2(5);
    cout << endl;
    int sum = 0;
    cout << "Sum (parameterized): " << sumN1(5, sum) << endl;
    cout << "Sum (functional): " << sumN2(5) << endl;
    sumN3(5, sum);
    cout << "Sum (by reference): " << sum << endl;
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Reverse: ";
    rev(a, 0, n);
    for (auto i : a)
        cout << i << " ";
    string s1 = "racecar";
    cout << "\nIs \"" << s1 << "\" palindrome?: " << palindrome(s1, 0);
    return 0;
}