#include <bits/stdc++.h>
using namespace std;

void decToBinary(int n)
{
    int binaryNum[32];

    // Counter for binary array
    int i = 0;
    while (n > 0)
    {
        // Storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Printing binary array in reverse order
    cout << "Number to binary(Program): ";
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

int main()
{
    int n = 11;
    decToBinary(n);
    cout << "\nNumber to binary(in-built): " << bitset<4>(n) << endl;
    int b = 101;
    string s = to_string(b);
    cout << "Binary to Decimal(in-built): " << stoi(s, 0, 2) << endl;
    return 0;
}