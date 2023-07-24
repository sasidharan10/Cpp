#include <iostream>
#include <ctime>
using namespace std;

void sleepForSeconds(int seconds)
{
    clock_t end_time = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end_time)
    {
    }
}

int main()
{
    cout << "This will be executed immediately." << endl;

    sleepForSeconds(3);
    cout << "This will be executed after the specified delay." << endl;

    return 0;
}
/*
c++ is synchronous in nature, but it can act as async, like in this example,
it actually WAITS for the function to get completed, and then proceeds to next line,
 without any, special functions like callback(), promises() in js.



*/