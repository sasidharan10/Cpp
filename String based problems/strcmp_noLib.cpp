#include <iostream>
using namespace std;
int test(char *s1, char *s2)
{
    int flag = 1;
    while (*s1 != '\0' || *s2 != '\0')
    {
        if (*s1 == *s2)
        {
            s1++;
            s2++;
        }
        else if ((*s1 == '\0' && *s2 != '\0') || (*s1 != '\0' && *s2 == '\0') || *s1 != *s2)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
bool compare(char *a, char *b)
{
    int i = 0, n1 = 0, n2 = 0;
    while (a[i] != '\0')
    {
        n1++;
        i++;
    }
    i = 0;
    while (b[i] != '\0')
    {
        n2++;
        i++;
    }
    if (n1 != n2)
        return false;
    for (int i = 0; i < n1; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
int main()
{
    char a[] = "aabbcc";
    char b[] = "aabbcc";
    if (test(a, b))
        cout << "They are equal";
    else
        cout << "They are NOT equal";
    return 0;
}