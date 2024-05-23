#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node *MakeList(vector<int> nums){
    int n = nums.size();
    Node *head = new Node(nums[0], nullptr);
    Node *curr = head;
    for (int i = 1; i < n; i++){
        Node *temp = new Node(nums[i], nullptr);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void Traverse(Node *head){
    int length = 0;
    Node *k = head;
    while (k){
        cout << k->data << " ";
        k = k->next;
        length++;
    }
    cout << endl;
    cout << "length is " << length << endl;
}
Node *Reverse(Node *head){
    Node *prev = nullptr;
    Node *nxt = nullptr;
    Node *curr = head;
    while (curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();
    Node *head = MakeList(nums);
    Traverse(head);
    head = Reverse(head);
    Traverse(head);
}