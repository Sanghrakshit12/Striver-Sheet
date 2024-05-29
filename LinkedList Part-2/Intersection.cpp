// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

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

// ListNode* IntesectionBrute(ListNode *head1, ListNode *head2){
// unordered_set<ListNode*>st;
// while(head1){
//     st.insert(head1);
//     head1=head1->next;
// }
// while(head2){
//     if(st.find(head2)!=st.end())
//         return head2;
//         head2=head2->next;
// }
// return NULL;
// }

ListNode *Intesection(ListNode *head1, ListNode *head2){
    ListNode *h1 = head1;
    ListNode *h2 = head2;
    while (h1 != h2){
        if (h2 == NULL)
            h2 = head1;
        else
            h2 = h2->next;
        if (h1 == NULL)
            h1 = head2;
        else
            h1 = h1->next;
    }
    return h1;
}

int main(){
    vector<int> nums1 = {1, 3, 1, 2, 4};
    ListNode *head1 = MakeList(nums1);
    Traverse(head1);
    vector<int> nums2 = {3, 2, 4};
    ListNode *head2 = MakeList(nums2);
    Traverse(head2);
    ListNode *Head = Intesection(head1, head2);
    cout << Head->val;
}