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
    Node *prev = NULL;
    Node *nxt = NULL;
    while (head)
    {
        nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

Node *addOne(Node *head)
{
    Node *curr = Rev(head);
    Node*cur=curr;
    int c=1;
    while(curr){
        int s=curr->val+c;
        if(s<10){
            curr->val=s;
            c=0;
            break;
        }
        else{
            c=1;
            curr->val=0;
        }
        curr=curr->next;
    }
    if(c==1){
        Node* temp=new Node(1);
        temp->next=cur;
        return temp;
    }
    return Rev(cur);
}

int main()
{
    Node *head;
    head = NULL;
    vector<int> nums = {9,8};
    head = Build(nums);
    Node*s=addOne(head);
    traverse(s);
}