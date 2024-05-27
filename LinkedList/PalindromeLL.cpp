// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

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

// bool PalindromeBrute(ListNode*head){
// vector<int>nums;
// while(head){
//     nums.push_back(head->val);
//     head=head->next;
// }
// int n=nums.size();
// int l=0,h=n-1;
// while(l<h){
//     if(nums[l]!=nums[h]){
//         return 0;
//     }
//     h--;l++;
// }
// return 1;
// }

ListNode *Reverse(ListNode *head){
    ListNode *prev = NULL;
    ListNode *next = NULL;
    while (head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool PalindromeLL(ListNode *head){
    ListNode *temp = head;
    if (head->next == NULL)
        return 1;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *revHead = NULL;
    if (fast == NULL)
        revHead = Reverse(slow);
    else
        revHead = Reverse(slow->next);
    while (temp != slow && revHead != NULL){
        if (temp->val != revHead->val)
            return 0;
        temp = temp->next;
        revHead = revHead->next;
    }
    return 1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 3, 2, 1};
    int n = nums.size();
    ListNode *head = MakeList(nums);
    Traverse(head);
    cout << PalindromeLL(head);
}