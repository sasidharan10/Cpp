#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    // storing graph in matrix
    unordered_map<int, int> mat;
    // n = nodes, m = edges
    int n = 5, m = 6;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        mat[a] = b;
        mat[b] = a;
    }

    // storing graph in list (more efficient)
    vector<vector<int>> v(2 * m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    return 0;
}

/*

1,2
1,3
2,4
3,4
5,3
5,4

1 -- 3
|    |  \
|    |   5
|    |  /
2 -- 4



*/