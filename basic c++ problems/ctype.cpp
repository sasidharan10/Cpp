#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main()
{
    char a[] = "\nThis\t. is,  (good)";
    int blank = 0, space = 0, cntrl = 0, punct = 0, i = 0, graph = 0;
    while (a[i] != '\0')
    {
        if (isblank(a[i]))
            blank++;
        if (isspace(a[i]))
            space++;
        if (iscntrl(a[i]))
            cntrl++;
        if (ispunct(a[i]))
            punct++;
        if (isgraph(a[i]))
            graph++;
        i++;
    }
    cout << "blank : " << blank << endl;
    cout << "space : " << space << endl;
    cout << "cntrl : " << cntrl << endl;
    cout << "punct : " << punct << endl;
    cout << "graph : " << graph << endl;
    // char b='P';
    // b=tolower(b);
    // cout<<"b: "<<b;
    return 0;
}

// note : <ctype>

// isalpha() = to check it is an alphabet
// isalnum() = to check it is alphanumeric
// isdigit() = to check it is a number
// isspace() = to check all spaces (' ',/t,/n,/v)
// isblank() = only checks for ' ' and /t
// iscntrl() = only check whitespace characters (\t,\n,\v,\r)
// ispunct() = to check it is a punctuation  (. , ( ))
// isgraph() = to check it is a graphical character (all except ' ' and '\n','\t' etc)
// isprint() = to check character is printablee (all except '\n','\t' '\0' etc)
// isupper()
// islower()
// toupper()
// tolower()