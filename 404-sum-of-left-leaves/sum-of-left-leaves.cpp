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
    int solve(TreeNode*root){
        if(!root)return 0;
        int ans=0;
        if(root->left)ans+=(root->left->left==nullptr && root->left->right==nullptr)?root->left->val:0+solve(root->left);
        if(root->right)ans+= solve(root->right);
        return ans;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root);
    }
};