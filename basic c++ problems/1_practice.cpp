#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string x = "sasasafs";
    int k=97;
    cout << "x: " << x << endl;
    
    x+=to_string(k)+"->";
    cout << "x: " << x << endl;
    x.pop_back();
    cout << "x: " << x << endl;
    x.erase(x.end()-3, x.end());
    cout << "x: " << x << endl;
    return 0;
}