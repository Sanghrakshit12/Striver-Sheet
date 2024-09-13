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

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
Node*curr=head;
while(curr->next!=NULL) curr=curr->next;
vector<pair<int, int>> res;
while(head!=curr && curr->next!=head){
    int sum=head->data+curr->data;
    if(sum>target){
        curr=curr->prev;
    }
    else if(sum<target){
        head=head->next;
    }
    else{
        res.push_back({head->data,curr->data});
        head=head->next;
        curr=curr->prev;
    }
}
return res;
}

int main()
{
    vector<int> nums = {1,2,3,4};
    Node *head = build(nums);
    vector<pair<int,int>>x = findPairsWithGivenSum(head, 5);
    for(auto i:x){
        cout<<i.first<<" "<<i.second<<" "<<endl;
    }
}