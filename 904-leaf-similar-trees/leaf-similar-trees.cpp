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
        vector<int > ans1,ans2;
        void dfs(TreeNode*root)
        {
            if(root==NULL)return ;
            if(root!=NULL && root->left==NULL && root->right==NULL)ans1.push_back(root->val);
            if(root->left)dfs(root->left);
            if(root->right)dfs(root->right);
        }
        void dfs1(TreeNode*root)
        {
            if(root==NULL)return ;
            if(root!=NULL && root->left==NULL && root->right==NULL)ans2.push_back(root->val);
            if(root->left)dfs1(root->left);
            if(root->right)dfs1(root->right);
        }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        dfs1(root2);
        if(ans1.size()!=ans2.size())return false;
        // cout<<"hihihih";
        // cout<<ans1.size()<<"=?"<<ans2.size();
        for(int i=0;i<ans1.size();i++){
            if(ans1[i]!=ans2[i])return false;
            // cout<<ans1[i]<<"  hi  "<<ans2[j]<<endl;
        }
        return true;
    }
};