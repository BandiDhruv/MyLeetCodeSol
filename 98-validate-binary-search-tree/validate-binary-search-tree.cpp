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
    bool s(TreeNode*root ,long long lmin,long long rmax)
    {
        if(!root)return true;
        if((root->val<=lmin) || (root->val >= rmax))
            return false;
        return (s(root->left,lmin,1ll*root->val) and s(root->right,1ll*root->val,rmax));
    }
    bool isValidBST(TreeNode* root) {
        long long x=1ll*INT_MIN-1,y=1ll*INT_MAX+1;
        
        return s(root->left,x,root->val) and s(root->right,root->val,y);
    }
};