#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    // Constructor with val and next parameters
    Node(int val, Node *next)
    {
        this->val = val;   // Assign the parameter 'val' to the member 'val'
        this->next = next; // Assign the parameter 'next' to the member 'next'
    }

    // Constructor with only val, next is set to nullptr
    Node(int val)
    {
        this->val = val;      // Assign the parameter 'val' to the member 'val'
        this->next = nullptr; // Set 'next' to nullptr by default
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

Node* Reverse(Node*head){
    Node*curr=head;
    Node*nxt=nullptr;Node* prev=nullptr;
    while (curr!=nullptr)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}

int main()
{
    Node *head;
    head = NULL;
    vector<int> nums = {1, 2, 3, 4, 50};
    head = Build(nums);
    traverse(head);
    head=Reverse(head);
    traverse(head);
}