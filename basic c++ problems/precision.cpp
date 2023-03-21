#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    // float x = 8.7435849;
    float x = 8.74;
    cout << setprecision(0) << x << endl;
    cout << setprecision(1) << x << endl;
    cout << setprecision(2) << x << endl;
    cout << setprecision(3) << x << endl;
    cout << setprecision(6) << x << endl;

    // use fixed to add trailing 0's, if there are no further decimal numbers

    cout << fixed << setprecision(0) << x << endl;
    cout << fixed << setprecision(1) << x << endl;
    cout << fixed << setprecision(2) << x << endl;
    cout << fixed << setprecision(3) << x << endl;
    cout << fixed << setprecision(6) << x << endl;

    printf("\n%.9f",x);   // old method
    return 0;
}