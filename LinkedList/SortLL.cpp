// Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their ListNodes contains a single digit. Add the two numbers and return the sum as a linked list.

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

public:
    ListNode(int val1, ListNode *next1)
    {
        val = val1;
        next = next1;
    }
    ListNode(int val1)
    {
        val = val1;
        next = nullptr;
    }
};

ListNode *MakeList(vector<int> nums)
{
    int n = nums.size();
    ListNode *head = new ListNode(nums[0], nullptr);
    ListNode *curr = head;
    for (int i = 1; i < n; i++)
    {
        ListNode *temp = new ListNode(nums[i], nullptr);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void Traverse(ListNode *head)
{
    int length = 0;
    ListNode *k = head;
    while (k)
    {
        cout << k->val << " ";
        k = k->next;
        length++;
    }
    cout << endl;
    cout << "length is " << length << endl;
}

ListNode *Reverse(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *next = NULL;
    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

ListNode *SortBrute(ListNode *head)
{
    if(head==NULL) return head;
    ListNode *res = head;
    while (head)
    {
        ListNode *temp = head->next;
        ListNode *x = head;
        int m = head->val;
        while (temp)
        {
            if (temp->val < m)
            {
                m = temp->val;
                x = temp;
            }
            temp = temp->next;
        }
        swap(head->val, x->val);
        head = head->next;
    }
    return res;
}

int main()
{
    vector<int> nums = {-1, 5, 3, 4, 0};
    int n = nums.size();
    ListNode *head = MakeList(nums);
    Traverse(head);
    ListNode *SortHead = SortBrute(head);
    Traverse(SortHead);
}