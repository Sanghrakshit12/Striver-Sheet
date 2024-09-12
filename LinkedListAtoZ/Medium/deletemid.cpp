#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        next = nullptr;
    }
};

void traverse(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << endl;
        curr = curr->next;
    }
}

Node *Build(vector<int> nums)
{
    Node *head = NULL;
    Node *curr;
    for (int i = 0; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i]);
        if (head == NULL)
        {
            head = temp;
            curr = head;
        }
        else
        {
            curr->next = temp;
            curr = temp;
        }
    }
    return head;
}

Node *MidBrute(Node *head){
    Node *curr = head;
    Node *cur = head;
    int c = 0;
    while (curr){
        c++;
        curr = curr->next;
    }
    int i = 1;
    while (i < c / 2){
        cur = cur->next;
        i++;
    }
    cur->next = cur->next->next;
    return head;
}

Node *Optimal(Node *head){
    if (head == NULL || head->next == NULL)
        return head;
    Node *slow = head;
    Node *fast = head->next->next;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
}

int main()
{
    Node *head;
    head = NULL;
    vector<int> nums = {1, 2, 3, 4, 5};
    head = Build(nums);
    Node *h1 = Optimal(head);
    traverse(h1);
}