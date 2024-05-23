#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
    Node(int data1, Node *prev1, Node *next1){
        data = data1;
        prev = prev1;
        next = next1;
    }
};

Node *Insertionbeforehead(Node *head, int val){
    Node *newHead = new Node(val, nullptr, head);
    head->prev = newHead;
    return newHead;
}

Node *Insertionbeforetail(Node *head, int val){
    if (head->next == nullptr)
        return Insertionbeforehead(head, val);
    Node *curr = head;
    while (curr->next != nullptr){
        curr = curr->next;
    }
    Node *temp = new Node(val, curr->prev, curr);
    curr->prev->next = temp;
    curr->prev = temp;
    return head;
}

Node *Insertion(Node *head, int val, int idx){
    Node *curr = head;
    int c = 0;
    while (curr){
        c++;
        if (c == idx)
            break;
        curr = curr->next;
    }
    Node *temp = new Node(val, curr->prev, curr);
    curr->prev->next = temp;
    curr->prev = temp;
    return head;
}

Node *Deletion(Node *head, int idx){
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *curr = head;
    if (idx == 1){
        head = curr->next;
        curr->next->prev = nullptr;
        curr->next = nullptr;
        delete curr;
        return head;
    }
    int cnt = 0;
    while (curr){
        cnt++;
        if (cnt == idx){
            curr->prev->next = curr->next;
            if (curr->next != nullptr)
                curr->next->prev = curr->prev;
            delete curr;
            return head;
        }
        curr = curr->next;
    }
    return head;
}

Node *MakedLL(vector<int> nums){
    Node *curr = new Node(nums[0], nullptr, nullptr);
    Node *head = curr;
    for (int i = 1; i < nums.size(); i++){
        Node *temp = new Node(nums[i], curr, nullptr);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void Traverse(Node *head){
    Node *curr = head;
    while (curr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main(){
    vector<int> nums = {10, 20, 30, 40};
    Node *head = MakedLL(nums);
    Traverse(head);
    cout << "Enter index of Element for Deletion" << endl;
    int idx2;
    cin >> idx2;
    head = Deletion(head, idx2);
    Traverse(head);
    // head = Insertionbeforehead(head, 33);
    // Traverse(head);
    // head = Insertionbeforetail(head, 22);
    // Traverse(head);
    cout << "Enter value & index of Element for Insertion" << endl;
    int ival, idx1;
    cin >> ival >> idx1;
    head = Insertion(head, ival, idx1);
    Traverse(head);
}