/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode*root){
        if(!root)return 0;
        int l=1+height(root->left);
        int r=1+height(root->right);
        return max(l,r);
    }
    bool solve(TreeNode*root){
        if(!root)return true;
        int lh=height(root->left);
        int rh=height(root->right);
        // if(abs(lh-rh)>1)return false;
        return (abs(lh-rh)<=1) && solve(root->left) && solve(root->right);
    }
    bool isBalanced(TreeNode* root) {
        return solve(root);
    }
};