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

Node *Brute(Node *headA, Node *headB)
{
    unordered_map<Node *, int> mpp;
    while (headA)
    {
        if (mpp.find(headA) != mpp.end())
            return headA;
        mpp[headA] = 1;
        headA = headA->next;
    }
    while (headB)
    {
        if (mpp.find(headB) != mpp.end())
            return headB;
        mpp[headB] = 1;
        headB = headB->next;
    }
    return NULL;
}

Node *getIntersectionNode(Node *headA, Node *headB)
{
    int l1 = 0, l2 = 0;
    Node *h1 = headA;
    Node *h2 = headB;
    while (h1)
    {
        l1++;
        h1 = h1->next;
    }
    while (h2)
    {
        l2++;
        h2 = h2->next;
    }
    int s = abs(l1 - l2);
    if (l1 > l2)
    {
        while (s > 0)
        {
            headA = headA->next;
            s--;
        }
    }
    else
    {
        while (s > 0)
        {
            headB = headB->next;
            s--;
        }
    }
    while (headA != NULL && headB != NULL)
    {
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

int main()
{
    Node *head;
    head = NULL;
    vector<int> nums = {1, 2, 43, 4, 5, 0};
    head = Build(nums);
}