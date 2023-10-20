#include <bits/stdc++.h>
using namespace std;
class NestedInteger
{
public:
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
public:
    vector<int> result;
    int current = 0;
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        for (auto &&it : nestedList)
        {
            helper(it);
        }
    }
    void helper(NestedInteger nl)
    {
        if (nl.isInteger())
        {
            result.push_back(nl.getInteger());
        }
        else
        {
            for (auto &&it : nl.getList())
            {
                helper(it);
            }
                }
    }
    int next()
    {
        return result[current++];
    }

    bool hasNext()
    {
        return current < result.size();
    }
};
int main()
{
    vector<int> nums{1, 2, 3, 4, 5};
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/flatten-nested-list-iterator

Youtube: https://www.youtube.com/watch?v=V-gPWPOyq8I

algorithm:

*/