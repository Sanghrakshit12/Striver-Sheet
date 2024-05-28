//  Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list instead, you will be given access to the node to be deleted directly. It is guaranteed that the node to be deleted is not a tail node in the list.

#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;

public:
    ListNode(int val1, ListNode *next1){
        val = val1;
        next = next1;
    }
    ListNode(int val1){
        val = val1;
        next = nullptr;
    }
};

ListNode *MakeList(vector<int> nums){
    int n = nums.size();
    ListNode *head = new ListNode(nums[0], nullptr);
    ListNode *curr = head;
    for (int i = 1; i < n; i++){
        ListNode *temp = new ListNode(nums[i], nullptr);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void Traverse(ListNode *head){
    int length = 0;
    ListNode *k = head;
    while (k){
        cout << k->val << " ";
        k = k->next;
        length++;
    }
    cout << endl;
    cout << "length is " << length << endl;
}

// void Delete(ListNode *Node){
//     ListNode *curr = NULL;
//     while (Node != NULL && Node->next != NULL){
//         Node->val = Node->next->val;
//         curr=Node;
//         Node = Node->next;
//     }
//     curr->next=nullptr;
// }

void deleteNode(ListNode *Node){
    Node->val = Node->next->val;
    Node->next = Node->next->next;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int n = nums.size();
    ListNode *head = MakeList(nums);
    Traverse(head);
    ListNode *Node = head->next->next;
    deleteNode(Node);
}