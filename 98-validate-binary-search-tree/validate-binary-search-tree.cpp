class Solution {
public:
    bool solve(TreeNode*root,long long mini,long long maxi){
        if(!root)return true;
        if(root->val<=mini || root->val>=maxi)return false;
        return solve(root->left,mini,root->val) && solve(root->right,root->val,maxi);
    }

    bool isValidBST(TreeNode* root) {
        long long mini=1ll*INT_MIN-1ll*1,maxi=1ll*INT_MAX+1*1ll;
        return solve(root,mini,maxi);
    }
};