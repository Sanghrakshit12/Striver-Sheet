// A Binary Tree is balanced if, for all nodes in the tree, the difference between left and right subtree height is not more than 1.

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

// BRUTE O(N^2)
int height(TreeNode *root){
    if (!root)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return 1 + max(l, r);
}

bool BruteisBalanced(TreeNode *root){
    if (!root)
        return 1;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1 &&
        BruteisBalanced(root->left) && BruteisBalanced(root->right))
        return 1;
    return 0;
}

// OPTIMAL O(n)
int check(TreeNode *root){
    if (!root)
        return 0;
    int lh = check(root->left);
    if (lh == -1)
        return -1;
    int rh = check(root->right);
    if (rh == -1)
        return -1;
    if (abs(rh - lh) > 1)
        return -1;
    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode *root){
    if (check(root) == -1)
        return 0;
    return 1;
}