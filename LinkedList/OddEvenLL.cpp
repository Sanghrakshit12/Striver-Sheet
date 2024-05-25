// Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their ListNodes contains a single digit. Add the two numbers and return the sum as a linked list.

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

ListNode* oddEvenList(ListNode* head){
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;
        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }

int main(){
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();
    ListNode *head = MakeList(nums);
    Traverse(head);
    ListNode *Head = oddEvenList(head);
    Traverse(Head);
}