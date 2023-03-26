#include <iostream>
#include <vector>
using namespace std;
void printSubsequences(int index, vector<int> v, vector<int> &ans)
{
    // Time  : O(2^n) 1 traversal
    // Space : O(n)    depth of tree
    
    if (index == v.size())
    {
        if (ans.size() == 0)        // for empty subset
        {
            cout << "{}" << endl;
            return;
        }
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
        return;
    }
    // to take the current element in the subsequence
    ans.push_back(v[index]);
    printSubsequences(index + 1, v, ans);
    ans.pop_back();
    printSubsequences(index + 1, v, ans);
}
int main()
{
    vector<int> v{56, 97, 34};
    vector<int> ans;
    int index = 0;
    printSubsequences(index, v, ans);
    return 0;
}

// Q) Print all the subsets of the array