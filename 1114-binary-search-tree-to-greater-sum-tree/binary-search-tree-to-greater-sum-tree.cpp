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
    int sum;
    void getArr(TreeNode*root,vector<int> &ans){
        if(!root)return;
        ans.push_back(root->val);
        getArr(root->left,ans);
        getArr(root->right,ans);
        return ;
    }
    void solve(TreeNode*root,vector<int>&pre,unordered_map<int,int>&mp){
        if(!root)return;
        int idx=mp[root->val];
        root->val=sum-((idx>0)?pre[idx-1]:0);
        solve(root->left,pre,mp);
        solve(root->right,pre,mp);
        return;
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> ans;
        getArr(root,ans);
        sort(ans.begin(),ans.end());
        // for(auto it:ans)cout<<it<<" ";
        vector<int> pre(ans.begin(),ans.end());
        for(int i=1;i<ans.size();i++)pre[i]+=pre[i-1];
        // cout<<endl;
        sum=pre[pre.size()-1];
        // for(auto it:pre)cout<<it<<" ";
        unordered_map<int,int> mpidx;
        for(int i=0;i<ans.size();i++)mpidx[ans[i]]=i;
        solve(root,pre,mpidx);
        return root;
    }
};