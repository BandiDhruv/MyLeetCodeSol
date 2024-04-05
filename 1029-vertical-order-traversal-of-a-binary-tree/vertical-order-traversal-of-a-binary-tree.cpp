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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode*node=q.front().first;
            int horizontalDistance=q.front().second.first;
            int verticaLevel=q.front().second.second;
            q.pop();
            mp[horizontalDistance][verticaLevel].insert(node->val);
            if(node->left)q.push({node->left,{horizontalDistance-1,verticaLevel+1}});
            if(node->right)q.push({node->right,{horizontalDistance+1,verticaLevel+1}});
        }
        
        for(auto &it:mp){
            vector<int> temp;
            for(auto i:it.second)
            {
                for(auto k:i.second)temp.push_back(k);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};