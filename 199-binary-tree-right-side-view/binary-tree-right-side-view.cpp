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
        if(!root)return {};
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int a=-1;
            while(size--){
                auto it=q.front();
                a=it->val;
                q.pop();
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
            ans.push_back(a);
        }
    return ans;
    }
};