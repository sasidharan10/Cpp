#include <iostream>
using namespace std;
int main()
{
    char a[] = "floor a gang aaoouuhh";
    int n = sizeof(a) / sizeof(a[0]);
    int i = 0, st = 0, en = 0, cur_len = 0, min_index = 0, max_index = 0, max = 0, min = n;
    while (en < n)
    {
        if (en < n && a[en] != ' ' && a[en] != '\0')
            en++;
        else
        {
            cur_len = en - st;
            if (cur_len > max)
            {
                max = cur_len;
                max_index = st;
            }
            if (cur_len < min)
            {
                min = cur_len;
                min_index = st;
            }
            en++;
            st = en;
        }
    }
    cout << "max : ";
    for (int i = 0; i < max; i++)
    {
        cout << a[max_index];
        max_index++;
    }
    cout << "\nlength : " << max << endl;
    cout << "min : ";
    for (int i = 0; i < min; i++)
    {
        cout << a[min_index];
        min_index++;
    }
    cout << "\nlength : " << min << endl;
}

/*

Write a program in C to find the largest and smallest word in a string. Go to the editor

Test Data :
Input the string : It is a string with smallest and largest word.

Expected Output :

The largest word is 'smallest'
and the smallest word is 'a' 
in the string : 'It is a string with smallest and largest word.'.

*/