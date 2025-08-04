#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *insertNode(ListNode *head, int n)
    {
        ListNode *temp = new ListNode(n);
        temp->next = head;
        head = temp;
    }
    void print(ListNode *p)
    {
        cout << "List: ";
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
    }
    int getDecimalValue(ListNode *head)
    {
        int prevSum = 0;
        while (head)
        {
            prevSum = prevSum * 2 + (head->val);
            head = head->next;
        }
        return prevSum;
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.insertNode(head, 0);
    head = s.insertNode(head, 1);
    head = s.insertNode(head, 0);
    head = s.insertNode(head, 1);
    // s.print(head);
    cout << "Decimal: " << s.getDecimalValue(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/solutions/

*/