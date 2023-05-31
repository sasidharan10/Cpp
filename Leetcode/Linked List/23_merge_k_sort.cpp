#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <map>
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
class cmp
{
public:
    bool operator()(ListNode *a, ListNode *b) const
    {
        return a->val > b->val;
    }
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
        cout << "List: ";
        while (p != NULL)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        ListNode *dummy = new ListNode(0);
        ListNode *tail = nullptr;
        tail = dummy;
        int minimum = 0;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != nullptr)
                pq.push(lists[i]);
        }
        while (!pq.empty())
        {
            ListNode *temp = pq.top();
            pq.pop();
            tail->next = temp;
            tail = tail->next;
            if (temp->next)
                pq.push(temp->next);
        }
        return dummy->next;
    }
    ListNode *mergeKLists2(vector<ListNode *> &lists)
    {
        multimap<int, ListNode *> m;
        int minimum = 0;
        for (auto &&i : lists)
        {
            while (i)
            {
                m.insert({i->val, i});
                i = i->next;
            }
        }
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        for (auto &&i : m)
        {
            ans->next = i.second;
            ans = ans->next;
        }
        return temp->next;
    }
};
int main()
{
    Solution s;
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    ListNode *l3 = nullptr;
    l1 = s.InsertEnd(l1, 1);
    l1 = s.InsertEnd(l1, 4);
    l1 = s.InsertEnd(l1, 5);
    s.print(l1);
    l2 = s.InsertEnd(l2, 1);
    l2 = s.InsertEnd(l2, 3);
    l2 = s.InsertEnd(l2, 4);
    s.print(l2);
    l3 = s.InsertEnd(l3, 2);
    l3 = s.InsertEnd(l3, 6);
    s.print(l3);
    vector<ListNode *> v;
    v.push_back(l1);
    v.push_back(l2);
    v.push_back(l3);
    ListNode *ans = s.mergeKLists(v);
    s.print(ans);
    return 0;
}