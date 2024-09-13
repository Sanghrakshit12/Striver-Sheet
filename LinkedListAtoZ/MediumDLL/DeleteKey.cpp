#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *next;
    Node *back;
    int val;
    Node(int val)
    {
        this->val = val;
        next = nullptr;
        back = nullptr;
    }
};

Node*build(vector<int>nums){
    Node*head=NULL;
    Node*curr=head;
    for(int i=0;i<nums.size();i++){
        Node* temp=new Node(nums[i]);
        if(head==NULL){
            head=temp;
            curr=head;
        }
        else{
            curr->next=temp;
            temp->back=curr;
            curr=curr->next;
        }
    }
    return head;
}

void traverse(Node*temp){
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

Node*DeleteKey(Node*head,int k){
    if(head==NULL){
        return head;
    }
    while(head!=NULL && head->val==k){
        Node*temp=head;
        head=head->next;
        if(head!=nullptr) head->back=nullptr;
        delete temp;
    }
    Node* curr=head;
    while(curr){
        if(curr->val==k){
            Node*tmp=curr;
            if(curr->back!=nullptr) curr->back->next=curr->next;
            if(curr->next!=nullptr) curr->next->back=curr->back;
            curr=curr->next;
            delete tmp;
        }
        else{
            curr=curr->next;
        }
        
    }
    return head;
}

int main(){
    vector<int>nums={3,3,4,3,4,3};
    Node*head=build(nums);
    Node*x=DeleteKey(head,3);
    traverse(x);
}