// Given the head of a linked list that may contain a cycle, return the starting point of that cycle. If there is no cycle in the linked list return null.

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
    curr->next=head->next->next;
    return head;
}

ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return 0;
        ListNode*fast=head;
        ListNode*slow=head;
        slow=slow->next;
        fast=fast->next->next;
        bool b=0;
        while(fast!=NULL && fast->next!=NULL){
            if(slow==fast){
                b=1;
                slow=head;
                break;
            }
        slow=slow->next;
        fast=fast->next->next;
        }
        if(b==0) return NULL;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
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

int main(){
    vector<int> nums1 = {1, 3, 1, 2, 4};
    ListNode *head = MakeList(nums1);
    ListNode*val= detectCycle(head);
    cout<<val->val;
}