#include <iostream>
using namespace std;
int main()
{
    char a[] = "the floor the gangthe  aoootheuuhh";
    char b[] = "the";
    int l1 = sizeof(a) / sizeof(a[0]);
    int l2 = sizeof(b) / sizeof(b[0]);
    int freq = 0, t = 0, h = 0, e = 0, sp1 = 0,sp2=0;
    for (int i = 0; i <= l1 - 3; i++)
    {
        sp1 = (a[i-1] == ' ' || a[i-1] == '\0');
        t = (a[i] == 't' || a[i] == 'T');
        h = (a[i+1] == 'h' || a[i+1] == 'H');
        e = (a[i+2] == 'e' || a[i+2] == 'E');
        sp2 = (a[i+3] == ' ' || a[i+3] == '\0');
        if (sp1 && t && h && e && sp2)
            freq++;
    }
    cout << "Count is : " << freq;
    return 0;
}

// 16) Find the number of times the word 'the' in any combination appears