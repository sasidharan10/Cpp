#include<iostream>
using namespace std;
void towerOfHanoi(int start, int end, char source, char auxilary, char destination)
{
    if(start>end)
        return;
    towerOfHanoi(start, end-1, source, destination, auxilary);
    cout<< "move disk "<< source<<" to "<<destination<<endl;
    towerOfHanoi(start, end-1, auxilary, source, destination);
}
int main()
{
    int start=1;
    int end=2;
    towerOfHanoi(start, end,'A','B','C');
    return 0;
}