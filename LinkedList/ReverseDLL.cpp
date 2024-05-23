#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
    Node(int data1, Node *prev1, Node *next1)
    {
        data = data1;
        prev = prev1;
        next = next1;
    }
};

Node *MakedLL(vector<int> nums)
{
    Node *curr = new Node(nums[0], nullptr, nullptr);
    Node *head = curr;
    for (int i = 1; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i], curr, nullptr);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void Traverse(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* ReverseDLL(Node*head){
    Node*curr=head;
    Node*nxt=nullptr;
    Node*bck=nullptr;
    while(curr){
        nxt=curr->next;
        curr->next=bck;
        curr->prev=nxt;
        bck=curr;
        curr=nxt;
    }
    return bck;
}

int main()
{
    vector<int> nums = {10, 20, 30, 40};
    Node *head = MakedLL(nums);
    Traverse(head);
    head=ReverseDLL(head);
    Traverse(head);
}