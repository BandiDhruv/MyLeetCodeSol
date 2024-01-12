class Solution {
public:
    int maxi=INT_MIN,mini=INT_MAX;
    void findMaxUtil(TreeNode*root,TreeNode*child)
    {
        if(child==NULL || root==NULL)return;
        maxi=max(maxi,abs(root->val-child->val));
        if(child->left)findMaxUtil(root,child->left);
        if(child->right)findMaxUtil(root,child->right);
    }
    void dfs(TreeNode* root)
    {
        if(root == NULL) return;
        
            findMaxUtil(root,root->left);
            findMaxUtil(root,root->right);
        // if(root->right)
        // {
            dfs(root->left);
            dfs(root->right);
        // }
        // if(root->left)
        // {
        // }
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return maxi;
    }
};