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

Node *Rev(Node *head)
{
    Node *prv = NULL;
    Node *nxt = NULL;
    Node *curr = head;
    while (curr)
    {
        nxt = curr->next;
        curr->next = prv;
        prv = curr;
        curr = nxt;
    }
    return prv;
}

bool Palin(Node *head)
{
    if (head == NULL || head->next == NULL)
        return 1;
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *head1 = Rev(slow->next);
    slow->next = head1;
    while (head1)
    {
        if (head->val != head1->val)
            return 0;
        head1 = head1->next;
        head = head->next;
    }
    return 1;
}

int main()
{
    Node *head;
    head = NULL;
    vector<int> nums = {1, 2, 43, 29, 1};
    head = Build(nums);
    cout << Palin(head);
}