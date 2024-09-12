#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        next = nullptr;
    }
};

void traverse(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << endl;
        curr = curr->next;
    }
}

Node *Build(vector<int> nums)
{
    Node *head = NULL;
    Node *curr;
    for (int i = 0; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i]);
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

Node *Segregate(Node *head)
{
    Node *odd = new Node(-1);
    Node *oh = odd;
    Node *even = new Node(-1);
    Node *eh = even;
    Node *curr = head;
    while (curr)
    {
        if (curr->val % 2 == 0)
        {
            even->next = curr;
            even = curr;
        }
        else
        {
            odd->next = curr;
            odd = curr;
        }
        curr = curr->next;
    }
    odd->next = nullptr;
    even->next=oh->next;
    return eh->next;
}

int main()
{
    Node *head;
    head = NULL;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    head = Build(nums);
    Node *head1 = Segregate(head);
    traverse(head1);
}