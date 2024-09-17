#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (!root)
        return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> fr;
        for (int i = 0; i < n; i++)
        {
            TreeNode *x = q.front();
            q.pop();
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
            fr.push_back(x->val);
        }
        res.push_back(fr);
    }
    return res;
}