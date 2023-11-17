#include <bits/stdc++.h>
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
    ListNode *reverseList(ListNode *head, int n, int k)
    {
        if (n < k)
            return head;
        ListNode *temp = head;
        ListNode *prev, *cur, *nextNode;
        cur = head;
        prev = nullptr;
        for (int i = 0; i < k; i++)
        {
            nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        head->next = reverseList(cur, n - k, k);
        return prev;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        if (!head || !head->next || k == 1)
            return head;
        int n = 0;
        while (temp)
        {
            temp = temp->next;
            n++;
        }
        if (n < k)
            return head;
        head = reverseList(head, n, k);
        return head;
    }
};
int main()
{
    Solution s;
    ListNode *head = NULL;
    int k = 2;
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 5);
    // head = s.InsertEnd(head, 6);
    // head = s.InsertEnd(head, 7);
    // head = s.InsertEnd(head, 8);
    // head = s.InsertEnd(head, 9);
    s.printList(head);
    head = s.reverseKGroup(head, k);
    s.printList(head);
    return 0;
}
