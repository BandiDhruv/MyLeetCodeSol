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
        queue<TreeNode*>q;
        q.push(root);
        if(root==nullptr)return {};
        while(!q.empty()){
            int size=q.size();
            vector<int> temp(size);
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                temp.push_back(it->val);
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
            ans.push_back(temp.back());
        }
        return ans;
    }
};