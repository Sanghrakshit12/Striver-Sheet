//

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
    for (int i = 1; i < n; i++)
    {
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

ListNode *Reverse2(ListNode *head, int l, int h){
    if (head == NULL || l == h)
        return head;

    ListNode *temp = new ListNode(-1);
    temp->next = head;

    ListNode *temp2 = temp;

    for (int i = 1; i < l; i++)
        temp2 = temp2->next;

    ListNode *curr = temp2->next;
    ListNode *help = curr;
    ListNode *prev = NULL;
    ListNode *nxt = NULL;
    for (int i = l; i <= h; i++){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    help->next = curr;
    temp2->next = prev;

    return temp->next;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();

    ListNode *head = MakeList(nums);
    Traverse(head);
    Traverse(Reverse2(head, 2, 4));
}