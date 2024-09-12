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

Node *Build(vector<int> nums){
    Node *head = NULL;
    Node *curr;
    for (int i = 0; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i]);
        if (head == NULL){
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

Node*Brute(Node*head,int n){
int c=0;
    Node*curr=head;
      Node*curr1=head;
    while(curr){
        c++;
        curr=curr->next;
    }
    if(c==n) return head->next;
    int i=1;
    while(i<c-n){
        curr1=curr1->next;
        i++;
    } 
    curr1->next=curr1->next->next;
    return head;
}

Node*Optimal(Node*head,int n){
Node*fast=head;
Node*slow=head;
int i=0;
while(i<n) {fast=fast->next;i++;}
if(fast==NULL) return head->next;
while(fast->next){
    fast=fast->next;
    slow=slow->next;
}
slow->next=slow->next->next;
return head;
}

int main(){
    Node *head;
    head = NULL;
    vector<int> nums = {1, 2, 43, 4, 5,0};
    head = Build(nums);
    Node*h1=Optimal(head,3);
    traverse(h1);
}