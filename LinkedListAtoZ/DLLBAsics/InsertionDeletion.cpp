#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *back;
    Node(int val)
    {
        this->val = val;
        next = nullptr;
        back = nullptr;
    }
    Node(int val, Node *next, Node *back)
    {
        this->val = val;
        this->next = next;
        this->back = back;
    }
};

Node *Build(Node *head, vector<int> nums)
{
    Node *curr = NULL;
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
            curr->next = temp; // Link the previous node to the current one
            temp->back = curr; // Set the back pointer
            curr = temp;
        }
    }
    return head;
}

void Traverse(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

Node *Insert(Node *head, int val, int idx)
{
    if (head == NULL)
    {
        if (idx == 0)
        {
            Node *temp = new Node(val);
            return temp;
        }
        else
        {
            return head;
        }
    }
    if(idx==0){
        Node *temp = new Node(val);
        temp->next=head;
        head->back = temp;
        return temp;
    }
    Node *curr = head;
    Node *prev = NULL;
    int id = 0;
    while (curr != NULL)
    {
        if (id == idx)
        {
            Node *temp = new Node(val);
            temp->next = prev->next;
            temp->back = prev;
            prev->next = temp;
            curr->back = temp;
            return head;
        }
        id++;
        prev = curr;
        curr = curr->next;
    }
    if (id == idx)
    {
        Node *temp = new Node(val);
        prev->next = temp;
        temp->back = prev;
    }
    return head;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    Node *head = NULL;
    head = Build(head, nums);
    head = Insert(head, 3098, 5);
     Traverse(head);
}
