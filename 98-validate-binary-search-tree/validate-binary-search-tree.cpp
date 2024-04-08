class Solution {
public:
    void solve(TreeNode*root,vector<int>&ans){
        if(!root)return ;
        if(root->left)solve(root->left,ans);
        ans.push_back(root->val);
        if(root->right)solve(root->right,ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]>=ans[i+1])return false;
        }
        return true;
    }
};