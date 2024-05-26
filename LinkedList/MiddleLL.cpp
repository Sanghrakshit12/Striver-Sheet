// Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

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

// ListNode *MiddleBrute(ListNode *head){
//     int c = 0;
//     ListNode *curr = head;
//     while (curr){
//         c++;
//         curr = curr->next;
//     }
//     curr = head;
//     int cnt = 0;
//     while (curr){
//         cnt++;
//         if (cnt == (c / 2) + 1)
//             return curr;
//         curr = curr->next;
//     }
//     return head;
// }

ListNode *Middle(ListNode *head){
    ListNode *hare = head;
    ListNode *tortoise = head;
    if (head == NULL || head->next == NULL)
        return head;
    while (hare != NULL && hare->next != NULL){
        hare = hare->next->next;
        tortoise = tortoise->next;
    }
    return tortoise;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int n = nums.size();
    ListNode *head = MakeList(nums);
    Traverse(head);
    ListNode *Mid = Middle(head);
    cout << Mid->val << " ";
}