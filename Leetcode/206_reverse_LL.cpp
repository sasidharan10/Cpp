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
    ListNode *InsertBeg(ListNode *head, int n)
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = head;
        ListNode *nextNode = NULL;
        ListNode *prev = NULL;
        while (current != NULL)
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
    head = s.InsertBeg(head, 6);
    head = s.InsertBeg(head, 5);
    head = s.InsertBeg(head, 4);
    head = s.InsertBeg(head, 3);
    head = s.InsertBeg(head, 6);
    head = s.InsertBeg(head, 2);
    head = s.InsertBeg(head, 1);
    s.printList(head);
    head = s.reverseList(head);
    s.printList(head);
    return 0;
}