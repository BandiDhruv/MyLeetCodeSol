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
    int h(TreeNode*root){
        if(!root)return 0;
        int i=1;
        while(root->left)
            ++i,root=root->left;
        return i;
    }

    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int count=1;
        while(root){
            if(!root->left)break;
            if(h(root->left)==h(root->right))count<<=1,count+=1,root=root->right;
            else count<<=1,root=root->left;
        }
        return count;
    }
};