// Given two sorted linked lists, merge them to produce a combined sorted linked list. Return the head of the final linked list created.

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

public:
    ListNode(int val1, ListNode *next1)
    {
        val = val1;
        next = next1;
    }
    ListNode(int val1)
    {
        val = val1;
        next = nullptr;
    }
};

ListNode *MakeList(vector<int> nums)
{
    int n = nums.size();
    ListNode *head = new ListNode(nums[0], nullptr);
    ListNode *curr = head;
    for (int i = 1; i < n; i++)
    {
        ListNode *temp = new ListNode(nums[i], nullptr);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void Traverse(ListNode *head)
{
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

// TC=O(n+m) SC=O(n+m)
// ListNode *MergeBrute(ListNode *head1, ListNode *head2){
//     ListNode *MergedHead = NULL;
//     ListNode *curr = NULL;
//     while (head1 != NULL && head2 != NULL){
//         ListNode *temp = new ListNode(-1);
//         if (head1->val <= head2->val){
//             temp->val = head1->val;
//             head1 = head1->next;
//         }
//         else{
//             temp->val = head2->val;
//             head2 = head2->next;
//         }
//         if (MergedHead == NULL){
//             MergedHead = temp;
//             curr = MergedHead;
//         }
//         else{
//             curr->next = temp;
//             curr = temp;
//         }
//     }
//     while (head1 != NULL){
//         ListNode *temp = new ListNode(head1->val, nullptr);
//         if (MergedHead == NULL){
//             MergedHead = temp;
//             curr = MergedHead;
//         }
//         else{
//             curr->next = temp;
//             curr = temp;
//         }
//         head1 = head1->next;
//     }
//     while (head2 != NULL){
//         ListNode *temp = new ListNode(head2->val, nullptr);
//         if (MergedHead == NULL){
//             MergedHead = temp;
//             curr = MergedHead;
//         }
//         else{
//             curr->next = temp;
//             curr = temp;
//         }
//         head2 = head2->next;
//     }
//     return MergedHead;
// }


// TC=O(n+m) SC=O(1)
ListNode *Merge(ListNode *head1, ListNode *head2){
    ListNode *MeregdHead = new ListNode(-1);
    ListNode *curr = MeregdHead;
    while (head1 != nullptr && head2 != nullptr){
        if (head1->val <= head2->val){
            curr->next = head1;
            head1 = head1->next;
        }
        else{
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    if (head1 != nullptr)
        curr->next = head1;
    else
        curr->next = head2;
    return MeregdHead->next;
}

int main()
{
    vector<int> nums = {1, 4, 6, 7};
    int n = nums.size();
    ListNode *head1 = MakeList(nums);
    Traverse(head1);
    vector<int> nums1 = {3, 8, 9};
    int n1 = nums1.size();
    ListNode *head2 = MakeList(nums1);
    Traverse(head2);
    ListNode *MergeHead = Merge(head1, head2);
    Traverse(MergeHead);
}