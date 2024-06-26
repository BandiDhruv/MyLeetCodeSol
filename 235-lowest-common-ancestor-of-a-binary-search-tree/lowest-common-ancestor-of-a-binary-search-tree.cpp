/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return nullptr;
        if(root->val<=p->val && root->val >=q->val)return root;
        else if(root->val>p->val && root->val > q->val)return solve(root->left,p,q);
        else return solve(root->right,p,q);
    }   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val)
            return solve(root,p,q);
        else return solve(root,q,p);
    }
};