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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
    ListNode *head = new ListNode(0);
    ListNode *curr = head;
    int c = 0;
    while (l1 != NULL || l2 != NULL || c != 0){
        int sum = 0;
        if (l1 != NULL){
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL){
            sum += l2->val;
            l2 = l2->next;
        }
        if (c != 0){
            sum += c;
            c = 0;
        }
        if (sum > 9){
            sum = sum % 10;
            c = 1;
        }
        ListNode *temp = new ListNode(sum);
        curr->next = temp;
        curr = temp;
    }
    return head->next;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();
    ListNode *head1 = MakeList(nums);
    Traverse(head1);
    vector<int> nums1 = {3, 2, 1, 4};
    int n1 = nums1.size();
    ListNode *head2 = MakeList(nums1);
    Traverse(head2);
    ListNode *addHead = addTwoNumbers(head1, head2);
    Traverse(addHead);
}