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
    void reorderList(ListNode *head)
    {
        ListNode *l1 = head;
        ListNode *l2 = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        do
        {
            slow = slow->next;
            fast = fast->next->next;
        } while (fast && fast->next);
        l2 = slow->next;
        slow->next = nullptr;
        l2 = reverseList(l2);
        // printList(l1);
        // printList(l2);
        ListNode *temp1 = nullptr;
        ListNode *temp2 = nullptr;
        while (l2)
        {
            // take smaller list, to avoid "out of bound error"
            temp1 = l1->next;
            temp2 = l2->next;

            l1->next = l2;
            l2->next = temp1;
            l2 = temp2;
            l1 = temp1;
        }
    }
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *nextNode = nullptr;
        while (current)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
        return head;
    }
};
int main()
{
    Solution s;
    ListNode *head = NULL;
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 5);
    s.printList(head);
    s.reorderList(head);
    s.printList(head);
    return 0;
}

/*

link:

leetcode:

*/