#include <iostream>
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
        ListNode *temp = new ListNode(n);
        // if(head==NULL)
        // {
        //     head=temp;
        //     return head;
        // }
        temp->next = head;
        head = temp;
        return head;
    }
    void printList(ListNode *head)
    {
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return head;
        ListNode *current = head, *prev = NULL, *temp;
        while (current != NULL)
        {
            if (current->val == val)
            {
                temp = current->next;
                if (current == head)
                {
                    head = current->next;
                    current->next = NULL;
                    delete current;
                }
                else
                {
                    prev->next = current->next;
                    current->next = NULL;
                    delete current;
                }
                current = temp;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
    ListNode *removeElements2(ListNode *head, int val)
    {
        // Simple sol
        if (head == NULL)
            return head;
        ListNode *temp = new ListNode();
        temp->next = head;
        ListNode *current = temp;
        while (current->next != NULL)
        {
            if (current->next->val == val)
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }
        return temp->next;
    }
    ListNode *removeElements3(ListNode *head, int val)
    {
        // recursive Solution
        if(head==NULL)
            return head;
        head->next=removeElements3(head->next,val);
        if(head->val==val)
            return head->next;
        else
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
    head = s.removeElements3(head, 6);
    s.printList(head);

    return 0;
}