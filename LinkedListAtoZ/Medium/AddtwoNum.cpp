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
        cout << curr->val << " ";
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

ListNode *addTwoNumbers(ListNode *h1, ListNode *h2){
    ListNode *temp = new ListNode(-1);
    ListNode *dum = temp;
    int c = 0;
    while (h1 != NULL || h2 != NULL || c != 0)
    {
        int s = c;
        if (h1)
        {
            s += h1->val;
            h1 = h1->next;
        }
        if (h2)
        {
            s += h2->val;
            h2 = h2->next;
        }
        c = s / 10;
        s = s % 10;
        temp->next = new ListNode(s);
        temp = temp->next;
    }
    return dum->next;
}

int main()
{
    ListNode *head1;
    head1 = NULL;
    ListNode *head2;
    head2 = NULL;
    vector<int> nums = {9, 9};
    head1 = Build(nums);
    vector<int> nums2 = {1};
    head2 = Build(nums2);
    ListNode *x = addTwoNumbers(head1, head2);
    traverse(x);
}