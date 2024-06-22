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
    int solve(TreeNode*root,int maxTillNow){
        if(!root)return 0;
        int ans=0;
        if(root->left){
            if(root->left->val>=maxTillNow){
                // maxTillNow=root->left->val;
                ans+= 1+solve(root->left,root->left->val);
            }
            else ans+= solve(root->left,maxTillNow);
        }
        if(root->right){
            if(root->right->val>=maxTillNow){
                // maxTillNow=root->right->val;
                ans+= 1+solve(root->right,root->right->val);
            }
            else ans+= solve(root->right,maxTillNow);
        }
        return ans;
        
    }
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        return 1+solve(root,root->val);
    }
};