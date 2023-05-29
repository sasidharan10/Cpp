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
    void print(ListNode *p)
    {

        cout << "\nList: ";
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
    }
    ListNode *ReverseList(ListNode *head)
    {
        ListNode *prev, *nextptr, *current;
        prev = NULL;
        current = head;
        if (head == NULL)
            return head;
        while (current != NULL)
        {
            nextptr = current->next;
            current->next = prev;
            prev = current;
            current = nextptr;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *low = head;
        ListNode *high = head->next;
        while (high != NULL && high->next != NULL)
        {
            low = low->next;
            high = high->next->next;
        }
        ListNode *first = head;
        ListNode *second = low->next;
        low->next = NULL;
        second = ReverseList(second);
        print(first);
        print(second);
        while (first && second)
        {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};
int main()
{
    Solution s;
    ListNode *head = nullptr;
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 3);
    s.print(head);
    cout << "Palindrome? : " << s.isPalindrome(head);
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/palindrome-linked-list/description/

*/