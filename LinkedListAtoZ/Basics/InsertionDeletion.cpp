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

Node *Insert(Node *head, int val, int idx)
{
    Node *prev = NULL;
    if (head == NULL)
    {
        if (idx == 0)
        {
            Node *temp = new Node(val);
            return temp;
        }
        else
            return head;
    }
    else
    {
        if (idx == 0)
        {
            Node *temp = new Node(val);
            temp->next = head;
            return temp;
        }
        Node *curr = head;
        int id = 0;
        while (curr != NULL)
        {
            if (id == idx)
            {
                Node *temp = new Node(val);
                temp->next = prev->next;
                prev->next = temp;
                return head;
            }
            id++;
            prev = curr;
            curr = curr->next;
        }
    }
    Node *temp = new Node(val);
    prev->next = temp;
    return head;
}

Node* Delete(Node*head,int idx){
    if(head==NULL) return NULL;
    if(idx==0) return head->next;
    Node *curr = head;
    Node* prev=NULL;
        int id = 0;
        while (curr != NULL)
        {
            if (id == idx)
            {
                prev->next=curr->next;
                return head;
            }
            id++;
            prev = curr;
            curr = curr->next;
        }
        return head;
}

int length(Node*head){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;
    }
    return c;
}

bool Search(Node*head,int vale){
     while(head!=NULL){
        if(head->val==vale) return 1;
        head=head->next;
    }
    return 0;
}

int main()
{
    Node *head;
    head = NULL;
    vector<int> nums = {1, 2, 3, 4, 50};
    head = Build(nums);
    head=Delete(head,5);
    head=Insert(head, 400, 0);
    traverse(head);
    cout<<length(head)<<endl;
    cout<<Search(head,488);
}