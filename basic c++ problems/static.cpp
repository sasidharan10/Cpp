#include <iostream>
#include <algorithm>
using namespace std;
void counter()
{
    static int c = 0;
    cout << c++ << " ";
}
int main()
{
    for (int i = 0; i < 3; i++)
    {
        counter();
    }
    return 0;
}

/*

- static variables can only be initialised once in a program.
  if multiple initialization occurs, they are skipped
- it is allocated in memory only once.(no multiple copies for static variables)


*/