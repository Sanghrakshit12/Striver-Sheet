
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
    curr->next=head->next;
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

bool hasCycle(ListNode *head){
    if (head == NULL || head->next == NULL)
        return 0;
    ListNode *slow = head;
    ListNode *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (fast != NULL && fast->next != NULL){
        if (slow == fast)
            return 1;
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();
    ListNode *head = MakeList(nums);
    cout << hasCycle(head);
}