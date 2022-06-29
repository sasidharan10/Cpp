#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string a;
    ifstream rd("read.txt"); // reading the file and storing in rd
    // rd>>a; // gets only one word
    getline(rd, a); // gets full line
    cout << "Content in read.txt : " << a << endl;

    // writing operation

    string b = "This is writing the content in a file using ofstream";
    ofstream wt("write.txt"); // writing the file and storing in rd
    wt << b;
    cout << "\nWritten successfully!!!(check write.txt)" << endl;
    return 0;
    
}