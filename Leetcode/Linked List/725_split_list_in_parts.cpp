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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> v;
        int s = 0;
        ListNode *temp = head;
        ListNode *prev;
        while (temp)
        {
            temp = temp->next;
            s++;
        }
        temp = head;
        int d = s / k;
        int extra = s % k;
        while (k--)
        {
            v.push_back(temp);
            for (int i = 0; i < d && temp != nullptr; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            if (extra)
            {
                prev = temp;
                temp = temp->next;
                extra--;
            }
            if(prev)
                prev->next = nullptr;
        }
        while (k>0)
        {
            v.push_back(nullptr);
            k--;
        }
        return v;
    }
};
int main()
{
    Solution s;
    ListNode *head = NULL;
    head = s.InsertEnd(head, 3);
    head = s.InsertEnd(head, 6);
    head = s.InsertEnd(head, 4);
    head = s.InsertEnd(head, 7);
    head = s.InsertEnd(head, 7);
    head = s.InsertEnd(head, 1);
    head = s.InsertEnd(head, 2);
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 5);
    head = s.InsertEnd(head, 5);
    s.printList(head);
    vector<ListNode *> v;
    v = s.splitListToParts(head, 3);
    cout << "Split parts: " << endl;
    for (auto i : v)
    {
        while (i)
        {
            cout << i->val << " ";
            i = i->next;
        }
        cout << endl;
    }
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/split-linked-list-in-parts/description/

*/