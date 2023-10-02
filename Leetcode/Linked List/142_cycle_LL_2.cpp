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
        cout << "\nList: ";
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow != NULL and fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            if (slow == fast)
                break;
        }
        if (!slow || !fast)
            return NULL;
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
int main()
{
    Solution s;
    ListNode *head = NULL;
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 0);
    head = s.InsertEnd(head, -4);
    s.printList(head);
    head->next->next->next = head->next;
    ListNode *temp = s.detectCycle(head);
    if (!temp)
        cout << "No cycle" << endl;
    else
        cout << "Cycle beg at: " << temp->val << endl;
    return 0;
}