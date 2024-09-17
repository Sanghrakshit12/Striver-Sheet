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

void fn(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    fn(root->left, res);
    fn(root->right, res);
    res.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    fn(root, res);
    return res;
}