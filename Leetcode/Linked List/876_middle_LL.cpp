#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
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

        cout << "\nList: ";
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
    }
    ListNode *middleNode(ListNode *head)
    {
        ListNode*slow,*fast;
        slow=fast=head;
        while (fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.insertNode(head, 6);
    head = s.insertNode(head, 5);
    head = s.insertNode(head, 4);
    head = s.insertNode(head, 3);
    head = s.insertNode(head, 2);
    head = s.insertNode(head, 1);
    s.print(head);
    cout<<"Value: "<<(s.middleNode(head))->val;
    return 0;
}


/*

link: 

leetcode: https://leetcode.com/problems/middle-of-the-linked-list/description/

*/