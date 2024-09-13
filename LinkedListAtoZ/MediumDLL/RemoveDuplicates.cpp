#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev;
    int data;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

Node *build(vector<int> nums)
{
    Node *head = NULL;
    Node *curr = head;
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
            temp->prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

void traverse(Node *temp)
{
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *removeDuplicates(Node *head)
{
    if (!head) return nullptr;

    Node* curr = head;
    while (curr && curr->next)
    {
        if (curr->data == curr->next->data)
        {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            if (curr->next) curr->next->prev = curr;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}


int main()
{
    vector<int> nums = {3, 3, 4, 5, 6, 6};
    Node *head = build(nums);
    Node*x=removeDuplicates(head);
    traverse(x);
}