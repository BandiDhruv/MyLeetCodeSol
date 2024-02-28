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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        int k=height(root,ans);
        return ans;
    }
    int height(TreeNode* node,int &ans)
    {
        if(node==NULL)
            return 0;
        int left=height(node->left,ans);
        int right=height(node->right,ans);
        ans=max(ans,left+right);
        return max(left,right)+1;
    }

};