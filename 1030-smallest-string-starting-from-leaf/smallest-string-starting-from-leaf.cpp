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
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<string,TreeNode*>> q;
        q.push({string(1,char(root->val+97)),root});
        vector<string> ans;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it=q.front();
                auto node=it.second;
                auto str=it.first;
                q.pop();
                if(node->left){
                    q.push({string(1,char(node->left->val+97))+str,node->left});
                }
                if(node->right){
                    q.push({string(1,char(node->right->val+97))+str,node->right});
                }
                if(!(node->left) && !(node->right)){
                    ans.push_back(str);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};