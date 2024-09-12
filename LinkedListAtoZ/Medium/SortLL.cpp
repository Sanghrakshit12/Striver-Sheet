#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        next = nullptr;
    }
};

void traverse(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << endl;
        curr = curr->next;
    }
}

ListNode *Build(vector<int> nums)
{
    ListNode *head = NULL;
    ListNode *curr;
    for (int i = 0; i < nums.size(); i++)
    {
        ListNode *temp = new ListNode(nums[i]);
        if (head == NULL)
        {
            head = temp;
            curr = head;
        }
        else
        {
            curr->next = temp;
            curr = temp;
        }
    }
    return head;
}

ListNode *Merge(ListNode *a, ListNode *b)
{
    ListNode *temp = new ListNode(-1);
    ListNode*dum=temp;
    while (a != NULL && b != NULL)
    {
        if (a->val <= b->val)
        {
            temp->next = a;
            a = a->next;
        }
        else
        {
            temp->next = b;
            b = b->next;
        }
        temp=temp->next;
    }
   while (a) {
        temp->next = a;
        a = a->next;
        temp = temp->next;
    }
    while (b) {
        temp->next = b;
        b = b->next;
        temp = temp->next;
    }
    return dum->next;
}

ListNode *Mid(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    if (head == NULL || head->next == NULL)
        return head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *SortLL(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *mid = Mid(head);
    ListNode *x = mid->next;
    mid->next = nullptr;
    ListNode *a = SortLL(head);
    ListNode *b = SortLL(x);
    return Merge(a, b);;
}

int main()
{
    ListNode *head;
    head = NULL;
    vector<int> nums = {1,5,8,2,0};
    head = Build(nums);
    ListNode*srt=SortLL(head);
    traverse(srt);
}