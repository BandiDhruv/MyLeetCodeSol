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
        int left=1+h(root->left),right=1+h(root->right);
        return max(left,right);
    }
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int ans=root->val;
        int he=h(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it=q.front();
                if(it.second==he){
                    return it.first->val;
                    
                }
                q.pop();
                if(it.first->left)q.push({it.first->left,it.second+1});
                if(it.first->right)q.push({it.first->right,it.second+1});
            }
        }
        return ans;
    }
};