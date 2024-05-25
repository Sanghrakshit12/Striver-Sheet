// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

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
    while (k)
    {
        cout << k->val << " ";
        k = k->next;
        length++;
    }
    cout << endl;
    cout << "length is " << length << endl;
}

// ListNode *SortColorsBrute(ListNode *head){
//     ListNode *curr = head;
//     int z = 0, o = 0, t = 0;
//     while (curr){
//         if (curr->val == 0)
//             z++;
//         else if (curr->val == 1)
//             o++;
//         else
//             t++;
//         curr = curr->next;
//     }
//     ListNode *temp = head;
//     while (temp){
//         if (z > 0){
//             temp->val = 0;
//             z--;
//         }
//         else if (o > 0){
//             temp->val = 1;
//             o--;
//         }
//         else{
//             temp->val = 2;
//             t--;
//         }
//         temp = temp->next;
//     }
//     return head;
// }

ListNode *SortColors(ListNode *head){
    ListNode *zero = new ListNode(-1);
    ListNode *zeroHead = zero;
    ListNode *one = new ListNode(-1);
    ListNode *oneHead = one;
    ListNode *two = new ListNode(-1);
    ListNode *twoHead = two;
    ListNode *curr = head;
    while (curr){
        if (curr->val == 0){
            zero->next = curr;
            zero = zero->next;
        }
        else if (curr->val == 1){
            one->next = curr;
            one = curr;
        }
        else{
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }
    (oneHead->next) ? zero->next = oneHead->next : zero->next = twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;
    delete oneHead;
    delete twoHead;
    return zeroHead->next;
}

int main(){
    vector<int> nums = {2, 2, 1, 2, 2};
    int n = nums.size();
    ListNode *head = MakeList(nums);
    Traverse(head);
    ListNode *Head = SortColors(head);
    Traverse(Head);
}