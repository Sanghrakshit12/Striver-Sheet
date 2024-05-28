// Given a linked list and an integer N, the task is to delete the Nth node from the end of the linked list and print the updated linked list.

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

// ListNode *DeletenthBrute(ListNode *head, int n){
//             int cnt=0;
//     ListNode*curr=head;
//     while(curr){
//         cnt++;
//         curr=curr->next;
//     }
//     curr=head;
//     int i=0;
//     if(cnt==n){
//         return head->next;
//     }
//     while(curr){
//         i++;
//         if(i==cnt-n){
//             curr->next=curr->next->next;
//             return head;
//         }
//         curr=curr->next;
//     }
//      return head;
// }

ListNode *Deletenth(ListNode *head, int n){
    ListNode *slow = head;
    ListNode *fast = head;
    if (head == NULL)
        return head;
    while (n != 0){
        fast = fast->next;
        n--;
    }
    if (fast == NULL)
        return head->next;
    while (fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();
    ListNode *head = MakeList(nums);
    Traverse(head);
    ListNode *Head = Deletenth(head, 4);
    Traverse(Head);
}