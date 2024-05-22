#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

void Traverse(Node *head)
{
    int length = 0;
    Node *k = head;
    while (k)
    {
        cout << k->data << " ";
        k = k->next;
        length++;
    }
    cout << endl;
    cout << "length is " << length << endl;
}

Node *MakeList(vector<int> nums)
{
    int n = nums.size();
    Node *head = new Node(nums[0], nullptr);
    Node *curr = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(nums[i], nullptr);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

Node *Insertion(Node *head, int val, int idx)
{
    if (head == NULL){
        if (idx == 1)
            return new Node(val, nullptr);
        else
            return NULL;
    }
    if (idx == 1)
        return new Node(val, head);
    Node *temp = head;
    int cnt = 0;
    Node *prev = NULL;
    while (temp)
    {
        cnt++;
        if (cnt == idx)
        {
            Node *x = new Node(val, temp);
            prev->next = x;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    if (idx == cnt + 1)
    {
        Node *x = new Node(val, nullptr);
        prev->next = x;
    }
    return head;
}

Node *Deletion(Node *head, int idx)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    if (idx == 1)
    {
        head = head->next;
        delete temp;
        return head;
    }
    Node *prev = nullptr;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if (cnt == idx)
        {
            prev->next = prev->next->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();
    Node *head = MakeList(nums);
    cout << "Enter value & index of Element for Insertion" << endl;
    int ival, idx1;
    cin >> ival >> idx1;
    head = Insertion(head, ival, idx1);
    Traverse(head);
    cout << "Enter index of Element for Deletion" << endl;
    int idx2;
    cin >> idx2;
    head = Deletion(head, idx2);
    Traverse(head);
}