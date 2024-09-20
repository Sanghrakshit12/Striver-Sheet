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
int fn(TreeNode *root, int &x)
{
    if (!root)
        return 0;
    int l = max(0, fn(root->left, x));
    int r = max(0, fn(root->right, x));
    x = max(x, root->val + l + r);
    return root->val + max(l, r);
}
int maxPathSum(TreeNode *root)
{
    int x = INT_MIN;
    fn(root, x);
    return x;
}