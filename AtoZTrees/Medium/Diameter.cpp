
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

// OPTIMAL

int fn(TreeNode *root, int &res)
{
    if (!root)
        return 0;
    int lh = fn(root->left, res);
    int rh = fn(root->right, res);
    res = max(res, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode *root)
{
    int res = 0;
    fn(root, res);
    return res;
}