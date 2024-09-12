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
    for (int i = 0; i < nums.size(); i++){
        Node *temp = new Node(nums[i]);
        if (head == NULL){
            head = temp;
            curr = head;
        }
        else{
            curr->next = temp;
            curr = temp;
        }
    }
    return head;
}

Node *SortBrute(Node *head){
    Node *zro = new Node(-1);
    Node *zh = zro;
    Node *one = new Node(-1);
    Node *oh = one;
    Node *two = new Node(-1);
    Node *th = two;
    while (head){
        if (head->val == 0){
            zro->next = head;
            zro = head;
        }
        else if (head->val == 1){
            one->next = head;
            one = head;
        }
        else{
            two->next = head;
            two = head;
        }
        head = head->next;
    }
    two->next = nullptr;
    one->next = th->next;
    zro->next = oh->next;
    return zh->next;
}

int main()
{
    Node *head;
    head = NULL;
    vector<int> nums = {1, 2, 1, 0, 1, 2, 0, 1, 2, 2, 1, 0};
    head = Build(nums);
    Node *h = SortBrute(head);
    traverse(h);
}