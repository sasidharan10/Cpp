#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int mini = 5, maxi = 10;
    int range = maxi - mini + 1;

    // random_integer = lowest + rand() % range

    for (int i = 0; i < 10; i++)
    {
        int ran = rand() % range + mini;
        cout << ran << endl;
    }

    return 0;
}