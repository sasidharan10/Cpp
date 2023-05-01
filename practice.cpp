#include <iostream>
#include <vector>

using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> vec{begin(arr), end(arr)};

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}