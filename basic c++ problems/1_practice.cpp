#include <iostream>
#include <string>
using namespace std;
int main()
{
    int r1 = 2, c1 = 3;
    int r2 = 3, c2 = 2;
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int b[3][2] = {{2, 2}, {2, 2}, {2, 2}};

    if (c1 == r2)
        cout << "Yes : " << endl;
    else
    {
        cout << "No : " << endl;
        return 0;
    }
    int prod[2][2];
    int sum = 0;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < r2; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            prod[i][j] = sum;
            sum = 0;
        }
    }
    cout << "Multiplication is : " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << prod[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}