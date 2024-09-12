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

bool LoopBrute(Node *head)
{
    Node *curr = head;
    unordered_map<Node *, int> mpp;
    while (curr)
    {
        if (mpp.find(curr) != mpp.end())
            return 1;
        mpp[curr] = 1;
        curr = curr->next;
    }
    return 0;
}

bool Loop(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    bool b = 0;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    Node *head;
    head = NULL;
    vector<int> nums = {1, 2, 43, 4, 5, 0};
    head = Build(nums);
    // head->next->next->next=head;
    cout << Loop(head);
}