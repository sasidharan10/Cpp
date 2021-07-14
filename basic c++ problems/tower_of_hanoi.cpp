#include <iostream>
#include <algorithm>
using namespace std;
void TowerOfHanoi(int start, int end, char source, char auxilary, char destination)
{
    if (start > end)
        return;
    // to move disc 1 to n-1 from A to B
    TowerOfHanoi(start, end - 1, source, destination, auxilary);
    // this will take care of last disc to move from A to C
    cout << "Move disk " << end << " from " << source << " to " << destination << endl;
    // to move disc 1 to n-1 from B to C
    TowerOfHanoi(start, end - 1, auxilary, source, destination);
}
int main()
{
    int start = 1;
    int end = 3;
    // cout<<"Enter no of disc in TOH : ";
    // cin>>end;
    cout << "\nAlgorithm is : \n"
         << endl;
    TowerOfHanoi(start, end, 'A', 'B', 'C');
    return 0;
}