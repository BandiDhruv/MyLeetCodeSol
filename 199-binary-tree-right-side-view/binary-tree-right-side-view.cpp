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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int temp=-1;
            while(size--){
                auto it=q.front();
                q.pop();
                temp=it->val;
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};