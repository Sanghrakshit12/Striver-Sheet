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

int Lengthh(Node *slow, Node *fast){
    int res=1;
    fast=fast->next;
    while(slow!=fast){
        res++;
        fast=fast->next;
    }
    return res;
}

int detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    bool b = 0;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
             return Lengthh(slow, fast);
    }
    return 0;
}

int main()
{
    Node *head;
    head = NULL;
    vector<int> nums = {1, 2, 43, 4, 5, 0};
    head = Build(nums);
    head->next->next = head;
    cout << detectCycle(head);
}