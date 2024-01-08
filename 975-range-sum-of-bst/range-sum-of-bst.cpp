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
    int solve(TreeNode*root,int l,int h)
    {
        if(root==NULL) return 0;
        if(root->val>=l && root->val<=h) {
            return root->val + solve(root->right,l,h) + solve(root->left,l,h);
        }
        else if(root->val>l)
        {
            return solve(root->left,l,h);    
        }
        else return solve(root->right,l,h); 
         
        // return 0;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root,low,high);
    }
};