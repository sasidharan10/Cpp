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
    ListNode *InsertEnd(ListNode *head, int n)
    {
        ListNode *temp1 = new ListNode(n);
        if (head == NULL)
        {
            head = temp1;
            return head;
        }
        ListNode *temp2 = head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
        return head;
    }
    void printList(ListNode *head)
    {
        cout << "List: ";
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *delNode;
        ListNode *temp = head;
        if (head == nullptr)
            return head;
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        prev->next = head;
        while (temp != nullptr)
        {
            if (temp->next != nullptr && temp->val == temp->next->val)
            {
                while (temp->next != nullptr && temp->val == temp->next->val)
                {
                    delNode = temp->next;
                    temp->next = delNode->next;
                    delete delNode;
                }
                prev->next = temp->next;
            }
            else
            {
                prev = prev->next;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};
int main()
{
    Solution s;
    ListNode *head = NULL;
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 5);
    s.printList(head);
    head = s.deleteDuplicates(head);
    s.printList(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

*/