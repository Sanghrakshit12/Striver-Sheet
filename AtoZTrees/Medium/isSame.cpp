
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
bool isSameTree(TreeNode* node1, TreeNode* node2) {
        if(node1 == NULL && node2 == NULL){
            return true;
        }
        if( node1== NULL || node2==NULL){
            return false;
        }
        return ((node1->val == node2->val)
            && isSameTree(node1->left, node2->left)
                && isSameTree(node1->right, node2->right));
    }